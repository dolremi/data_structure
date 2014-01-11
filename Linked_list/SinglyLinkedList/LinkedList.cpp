#include "LinkedList.h"
#include <iostream>

using namespace std;

// The constructor for empty linked list
LinkedList::LinkedList(){
  size = 0;
  head = NULL;
}

// This constructor of the linked list will create a linked list of value "val" and size of "input"
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

// Copy constructer note that it didn't check self copy! And assume the original linked list is empty
LinkedList::LinkedList(LinkedList &rhs){
  size = rhs.size;
  head = new ListNode(rhs.head->val);
  ListNode *appendOne = rhs.head -> Next;
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

  // find the node next to the inserted position
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

    // stop at the last node in the list    
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

  // check if the head node needs to be deleted
  if(head->val == input){
    ListNode *temp = head;
    head = NULL;
    delete temp;
    size = 0;
    return true;
  }
  
  ListNode *p1 = head;

  // For the deletion, always check with the node before the to-be-deleted node
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
  
  
