#include "LinkedList.h"
#include <iostream>

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
  
//   Partition the linked list with the value of inputValue
//   It will use "Runner" technique, one pointer point to the current position 
//   of the node less than inputValue, the other point to the current position of the node greater or equal to inputValue. The process is finished when the second pointer reach to the end of the list
//   This method is better than the solution of Book, since it is in-place swap

void LinkedList::partition(int inputValue){
  if(head){
  ListNode *p1 = head;

  // Test the current node value put the smaller values in front
  while(p1 && p1->val < inputValue ){
    p1 = p1->Next;
  }
  
  // Start from the firt node which is larger than the inputValue, swap the values of two nodes of which one is larger than inputValue put ahead of the smaller one
  ListNode *p2 = p1;
  while(p2){
    if(p2->val < inputValue && p1 != p2){
      int temp = p2-> val;
      p2-> val = p1 -> val;
      p1-> val = temp;
      p1 = p1 -> Next;
    }
    p2 = p2 -> Next;
  }
  }else{
    cout << "There is nothing in the list" << endl;
  }
}
  
