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
