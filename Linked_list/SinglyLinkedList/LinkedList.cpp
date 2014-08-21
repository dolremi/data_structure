#include "LinkedList.h"
#include <iostream>

using namespace std;

LinkedList::LinkedList(const LinkedList &rhs){
  operator=(rhs);
}

LinkedList::~LinkedList(){
  clearList();
}

void LinkedList::clearList(){
  Node *run = head;
  while(run){
    Node *tmp = run;
    run = run->Next;
    delete tmp;
  }
  head = 0;
  size = 0;
}

const LinkedList & LinkedList::operator=(const LinkedList &right){
  
  // check if self assignment
  if(this != &right){
    clearList();
   
    Node *rightHead = right.getHead();

    for(int i = 0; i < right.size; ++i){
      append(rightHead->val);
      rightHead = rightHead->Next;
    }
  }

  return *this;
}

void LinkedList::insert(int pos, int val){
  
  Node * insertOne = head;
  
  if( pos <= size && pos >= 0){    
    int i = 0;
    
    // Now the new node can be inserted after the head 
    while(i < size){
      insertOne = insertOne -> Next;
      ++i;
    }
    
    Node *newNode = new Node(val);

    // find the node next to the inserted position
    newNode -> Next = insertOne -> Next;
    insertOne ->Next = newNode;
    size = size + 1;
  }else{
    cout << "Error! The position needs to be between 0 and " << size << endl;
  }
}

void LinkedList::append(int val){
  if(!head){
    head = new Node(val);
  }else{
    Node *lastNode = head;

    // stop at the last node in the list    
    while(lastNode->Next)
      lastNode = lastNode->Next;

    Node *temp = new Node(val);
    lastNode->Next = temp;
  }
  size = size + 1;

}

int LinkedList::deleteNode(int input){
  
  if(!head)
    return -9999999;

  Node *p1 = head;

  // check if the head node needs to be deleted
  if(p1->val == input){
    Node *temp = head;
    head = head->Next;
    delete temp;
    --size;
    return input;
  }
  
  // For the deletion, always check with the node before the to-be-deleted node
  while(p1->Next){
    if(p1->Next->val == input){
     Node *temp = p1->Next;
      p1->Next = p1->Next->Next;
      delete temp;
      --size;
      return input;
    }
    p1 = p1->Next;
  }
  return -9999999;
}

void LinkedList::display(){
  if(isEmpty()){
    cout << "The list is empty." << endl;
  }else{
    cout << "Now the list is as following:" << endl;
    Node *p1 = head;
    while(p1){ 
      cout << p1->val << " -> ";
      p1 = p1->Next;
    }
    cout << "NULL" << endl;
  }
}

Node * LinkedList::getHead(){
  return head;
}

int LinkedList::getSize(){
  return size;
}
  
bool LinkedList::isEmpty(){
  return (size == 0);
}
