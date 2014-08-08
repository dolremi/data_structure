#include "LinkedList.h"
#include <iostream>

using namespace std;

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
  operator=(rhs);
}

const LinkedList & LinkedList::operator(const LinkedList &rhs){
  if(this != &rhs){
    clearList();
    
    ListNode *copy = rhs.getHead();
    
    while(copy){
      append(copy->val);
      copy = copy->Next;
    }
    size = rhs.getSize();
  }
  return *this;
}

LinkedList::~LinkedList(){
  clearList();
}

void LinkedList::clearList(){
  ListNode *p1 = head;
  while(p1){
    ListNode *tmp = p1;
    p1 = p1->Next;
    delete p1;
  }
  size = 0;
  head = 0;
}

void  LinkedList::insert(int pos, int val){

  if(pos < size && pos >0){
    for(int i = 0; i < pos; i++){
      insertOne = insertOne -> Next;
    }

    ListNode *newNode = new ListNode(val);
    newNode -> Next = insertOne -> Next;
    insertOne ->Next = newNode;
    size = size + 1;
  }else{
    cout << "Error! The position should be between 0 and " << size << endl;
  }
}

void LinkedList::append(int val){
  if(!head){
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

int LinkedList::deleteNode(int input){
  
  if(!head)
    return -9999999;

  if(head->val == input){
    ListNode *temp = head;
    head = head->Next;
    delete temp;
    --size;
    return input;
  }
  
  ListNode *p1 = head;

  while(p1->Next != NULL){
    if(p1->Next->val == input){
      ListNode *temp = p1->Next;
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
  ListNode *p1 = head;
  while(p1){
    cout << p1->val << " -> ";
    p1 = p1 -> Next;
  }
   cout << "NULL" << endl;
}

ListNode* LinkedList::middle(){
  ListNode *p1 = head;
  for(int i = 0; i < (size-1)/2; i++){
    p1 = p1->Next;
  }
  return p1;
}
    
// Since we are not given the access to the previous node to the middle element, we can't delete the node directly
// However we can copy the value of the next node to the current one, then delete the next node 
// Note this method cannot delete the last node of the linked list
void LinkedList::removeMiddle(ListNode *mid){
  ListNode *p1 = mid->Next;
  if(mid -> Next && mid){
    ListNode *temp = mid->Next;
    mid->val = mid->Next->val;
    mid->Next = mid->Next->Next;
    delete temp;
    --size;
  }else{
    cout << "It cannot delete it" << endl;
  }
}  
