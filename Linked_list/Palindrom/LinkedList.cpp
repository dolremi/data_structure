#include "LinkedList.h"
#include <iostream>
#include <stack>
using namespace std;

LinkedList::LinkedList(){
  size = 0;
  head = 0;
}

LinkedList::LinkedList(int input, int val){
  size = input;
  head = new ListNode(val);
  ListNode *insertOne = head;  

  for(int i = 0; i < input - 1; i++){
    ListNode *newNode = new ListNode(val);
    insertOne->Next = newNode;
    insertOne = insertOne -> Next;
  }
}

LinkedList::LinkedList(LinkedList &rhs){
  size = rhs.size;
  head = new ListNode(rhs.head->val);
  ListNode *appendOne = rhs.head->Next;
  ListNode *insertOne = head;

  while(appendOne){
    ListNode *newNode = new ListNode(appendOne->val);
    insertOne -> Next = newNode;
    insertOne = insertOne -> Next;
    appendOne = appendOne -> Next; 
 }
}

LinkedList::~LinkedList(){
  while(head){
    ListNode *temp = head;
    head = head-> Next;
    delete temp;
  }
  size = 0;
}

bool LinkedList::insert(int pos, int val){
  ListNode * insertOne = head;
  if(pos > size)
    return false;
  for(int i = 0; i < pos; i++){
    insertOne = insertOne -> Next;
  }
  ListNode *newNode = new ListNode(val);
  newNode -> Next = insertOne -> Next;
  insertOne ->Next = newNode;
  size = size + 1;
  return true;
}

void LinkedList::append(int val){
  if(head == 0){
    head = new ListNode(val);
  }
  else{
    ListNode *lastNode = head;
    while(lastNode->Next)
      lastNode = lastNode->Next;
    ListNode *temp = new ListNode(val);
    lastNode->Next = temp;
  }
  size = size + 1;
}

bool LinkedList::deleteNode(int input){
  if(head == 0)
    return false;
  if(head->val == input){
    ListNode *temp = head;
    head = 0;
    delete temp;
    size = 0;
    return true;
  }
  ListNode *p1 = head;
  while(p1->Next != 0){
    if(p1->Next->val == input){
      ListNode *temp = p1->Next;
      p1->Next = p1->Next->Next;
      delete temp;
      --size;
      return true;
    }
    p1 = p1->Next;
  }
  return false;
}

void LinkedList::display(){
  cout << "Now the list is as following" << endl;
  ListNode *p1 = head;
  while(p1){ 
    cout << p1->val << " -> ";
    p1 = p1->Next;
  }
  cout << "NULL" << endl;
}

ListNode * LinkedList::curHead(){
  return head;
}

int LinkedList::currSize(){
  return size;
}
// There are several ways to check the palindrome 
//   1. Reverse the linked list and compare the first half
//   2. Use a stack to push the first half of the linked list, then compare them with the second half
//   3. Recursive approach

// Iterative version to determine if it is palindrome
// use runner technique with two pointers fast/slow runner, slow runner run each node at one time, the fast runner runs two nodes at one time
// Be cautioun for the loop terminatino condition 
bool LinkedList::isPalin(){
  ListNode *slow = head;
  ListNode *fast = head;
  int iter = 1;
  stack <int> mystack;
 
  // The condition to terminate the loop is to check if fast-> Next and fast is empty
  while(fast != 0 && fast -> Next != 0){
    mystack.push(slow -> val);
    slow = slow -> Next;
    fast = fast -> Next -> Next;   
  }   

  // Has odd number of elements, so skip the middle element
  if(fast){
    slow = slow -> Next;
  }
 
  // Always check if the pointer is NULL before accessing the value of it
  while(slow != 0 ){
    if(mystack.top() != slow -> val)
      return false;
    slow = slow -> Next;
    mystack.pop();
  }
  return true;
}

// Each call compares its head to the 'next' ListNode, then go to next node of 'next' ListNode up the stack
bool LinkedList::isPalinR(ListNode *head, int length, ListNode*& next){
  // Base case when it reaches to the middle element
  if(head == NULL || length == 0){
    return true;
  }else if (length == 1){
    next = next->Next;
    return true;
  }

  // Return the compared result from the next ListNode
  // For each call the next node needs to update to next one
  next = next -> Next;
  bool res = isPalinR(head->Next, length -2, next);
  
  if(res){
    res = head->val == next->val;
    next = next->Next;
  }
  return res;
}

