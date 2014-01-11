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

  // always start from the node before the deleted one
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
  
// Remove duplicated item with hash table to remove the duplicated node
// The main algorithm is as following: simply iterate through the whole linked list, push each element into the hash table, if a duplicated one is found, remove it. The running time of the algorithm is O(n).
void LinkedList::removedDuplicated1(){
  map<int, int> mymap;
  ListNode *p1 = head;
  if(p1 == NULL){
    cout << "There is no linked list here! " << endl;
  }else{
    while(p1->Next){
      int temp = p1->Next->val;
      
      // In STL map, the find() method will return map::end() if no element is found
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

// Use a "runner" pointer to record the node before the removed one
// The space is O(1), but the running time is O(n^2)
void LinkedList::removedDuplicated2(){
  ListNode *p1 = head;
  if(p1 == NULL){
    cout << "There is nothing in the linked list" << endl;
  }else{
    while(p1){
     
      // Only two pointers are needed for 'runner' technique
      ListNode *runner = p1;
      while(runner->Next){
	if(runner->Next->val == p1 -> val){
	  ListNode *moved = runner->Next;
	  runner ->Next = runner-> Next->Next;
	  delete moved;
	  --size;
	}

	runner = runner->Next;
      }
      p1 = p1 -> Next;
    }
  }
}
