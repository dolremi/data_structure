#include "LinkedList.h"
#include <iostream>
#include <map>

using namespace std;

LinkedList::LinkedList(){
  size = 0;
  head = NULL;
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
  if(head == NULL){
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
  
  if(head == NULL)
    return false;

  if(head->val == input){
    ListNode *temp = head;
    head = NULL;
    delete temp;
    size = 0;
    return true;
  }
  
  ListNode *p1 = head;
  while(p1->Next != NULL){
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

  ListNode *p1 = head;
  
  while(p1){
    cout << p1 -> val << " -> ";
    p1 = p1 -> Next;
  }
  cout << " NULL" << endl;
}

// Iteration version use the "runnner" technique with  O(n) of running time and O(1) of space 
ListNode * LinkedList::kthlastIter(int k){
  ListNode *p1 = head;
  ListNode *p2 = head;
     
  //Fast runner p2 is k nodes ahead of p1
  for(int i = 0; i < k-1; i++){
    if(p2 == 0) return NULL; // Error check for k is out of the range    
    p2 = p2->Next;
  }
  if(p2 == 0) return NULL;  // Error checking if p2 is NULL

  // When the fast runner reached the end, the slow runner reached the kth to the last element
  while(p2->Next){
    p2 = p2->Next;
    p1 = p1->Next;
  }
  return p1;
}

ListNode * LinkedList::currentHead(){
  return head;
}

int LinkedList::currentSize(){
  return size;
}

// A recursive version of kth to last, k is a reference to the value which will
// record the position relative the the last element, nth to last : k = n, this number
// will change across the function calls, the space is O(n) 
ListNode * LinkedList::kthlastRecur(ListNode *input, int &k, int m){
 
  // Base case or head is NULL
  if(input == NULL)
    return NULL;

  ListNode *result = kthlastRecur(input->Next, k, m);
  k = k + 1;
  
  if(k == m){
    return input;
  }
    return result;
}
