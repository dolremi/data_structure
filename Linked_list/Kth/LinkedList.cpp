#include "LinkedList.h"
#include <iostream>
#include <map>

using namespace std;

LinkedList::LinkedList(LinkedList &rhs){
  operator=(rhs);
}

LinkedList::~LinkedList(){
  clearList();
}

void LinkedList::clearList(){
  
  ListNode *runner = head;
  while(runner){
    ListNode *temp = runner;
    runner = runner->Next;
    delete temp;
  }
  size = 0;
  head = 0;
}

const LinkedList & LinkedList::operator=(const LinkedList &rhs){

  // check for self-assignment
  if(this != &rhs){
    clearList();
    
    ListNode *copy = rhs.head;

    while(copy){
      append(copy->val);
      copy = copy->Next;
    }
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
  
  if(!head )
    return -9999999;

  if(head->val == input){
    ListNode *temp = head;
    head = 0;
    delete temp;
    --size ;
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
    cout << p1 -> val << " -> ";
    p1 = p1 -> Next;
  }
  cout << " NULL" << endl;
}

// Iteration version use the "runnner" technique with  O(n) of running time and O(1) of space 
ListNode * LinkedList::kthlastIter(int k){
  ListNode *p1 = head;
  ListNode *p2 = head;
     
  // if k is out of bound 0 is returned
  if(k >= size) return 0;

  //Fast runner p2 is k nodes ahead of p1
  for(int i = 0; i < k-1; i++){
     p2 = p2->Next;
  }
 
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
ListNode * LinkedList::kthlastRecur(ListNode *input, int &j, int k){
 
  // Base case or head is NULL
  if(!input)
    return 0;

  ListNode *result = kthlastRecur(input->Next, j, k);
  j = j + 1;
  
  if(j == k){
    return input;
  }
    return result;
}
