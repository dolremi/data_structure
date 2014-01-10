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
  cout << " NULL";
}
  
// Remove duplicated item with hash table    
void LinkedList::removedDuplicated1(){
  map<int, int> mymap;
  ListNode *p1 = head;
  if(p1 == NULL){
    cout << "There is no linked list here! " << endl;
  }else{
    while(p1->Next){
      int temp = p1->Next->val;
      if(mymap.find(temp) == mymap.end()){
	mymap[temp] = 1;
      }
      else{

	// remove the duplicated one
	ListNode *temp = p1->Next;
	p1->Next= p1-> Next -> Next;
	delete temp;
	--size;
      }
      p1 = p1->Next;
    }
  }
}

void LinkedList::removedDuplicated2(){
  ListNode *p1 = head;
  if(p1 == NULL){
    cout << "There is nothing in the linked list" << endl;
  }else{
    while(p1){
      ListNode *p2 = p1 -> Next;
      ListNode *p3 = p1;
      while(p2){
	if(p2->val == p1 -> val){
	  ListNode *moved = p2;
	  p3 ->Next = p2-> Next;
	  delete moved;
	  --size;
	}
	p3 = p3->Next;
	p2 = p2->Next;
      }
      p1 = p1 -> Next;
    }
  }
}

//Iteration version use "runnner" technique
ListNode * LinkedList::kthlastIter(int k){
  ListNode *p1 = head;
  ListNode *p2 = p1;

  if( k >= size)
    return 0;
    
  //p2 is k nodes ahead of p1
  for(int i = 0; i < k; i++){
    p2 = p2->Next;
  }
  
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

// a recursive version of kth to last

ListNode * LinkedList::kthlastRecur(ListNode *input, int &k, int m){
  if(input-> Next == NULL)
    return NULL;

  ListNode *result = kthlastRecur(input->Next, k, m);
  k = k + 1;
  
  if(k == m)
    return input;
  else 
    return result;
}
