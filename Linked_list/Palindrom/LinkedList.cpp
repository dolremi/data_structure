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
  ListNode *appendOne = rhs.head;
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

    cout << "0" << endl;
}

ListNode * LinkedList::curHead(){
  return head;
}

int LinkedList::currSize(){
  return size;
}


// Iterative version to determine if it is palindrome
// use runner technique with two pointers
// use stack to push half of the linked list 
// compare them with the second half 
bool LinkedList::isPalin(){
  ListNode *slow = head;
  ListNode *fast = head;

  stack <int> mystack;
  mystack.push(head->val);

  while(fast != 0 && fast -> Next != 0){
    slow = slow -> Next;
    mystack.push(slow -> val);
    fast = fast -> Next -> Next;
  }

  while( slow != 0){
    slow = slow -> Next;
    if(mystack.top() != slow -> val)
      return false;

    mystack.pop();
  }

  if(mystack.empty())
    return true;

  return false;

}
