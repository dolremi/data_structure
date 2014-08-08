#include "LinkedList.h"
#include <iostream>

using namespace std;

LinkedList::LinkedList(LinkedList &rhs){
  operator=(rhs);
}

LinkedList::~LinkedList(){
  clearList();
}

void LinkedList::clearList(){
  ListNode *p1 = head;
  
  while(p1){
    ListNode *tmp = p1;
    p1 = p1->Next;
    delete tmp;
  }
  size = 0;
  head = 0;
}


const LinkedList & LinkedList::operator=(const LinkedList & rhs){
  // Check the self-assignment
  if(this != &rhs){
    clearList();
    ListNode *copy = rhs.head;

    while(copy){
      append(copy->val);
      copy = copy->Next;
    }

    size = rhs.currSize();
  }

  return *this;
}

void LinkedList::insert(int pos, int val){
  
  ListNode * insertOne = head;
  if(pos < size && pos > 0){
    for(int i = 0; i < pos - 1; i++){
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
    return -99999999;

  if(head->val == input){
    ListNode *temp = head;
    head = head->Next;
    delete temp;
    --size;
    return input;
  }
  
  ListNode *p1 = head;

  while(!p1->Next){
    if(p1->Next->val == input){
      ListNode *temp = p1->Next;
      p1->Next = p1->Next->Next;
      delete temp;
      --size;
      return input;
    }
    p1 = p1->Next;
  }
  
  return -99999999;
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
  
