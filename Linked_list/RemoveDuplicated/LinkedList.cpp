#include "LinkedList.h"
#include <iostream>
#include <map>

using namespace std;


LinkedList::LinkedList(const LinkedList &rhs){
  operator=(rhs);
}

LinkedList::~LinkedList(){
  emptyList();
}

const LinkedList & operator=(const LinkedList &rhs){
  // check if current list is the same as rhs
  if(this != &rhs){
    emptyList();
    
    ListNode *copy = rhs.getHead();
    for(int i = 0; i < size; ++i){
      append(copy->val);
      copy = copy->Next;
    }
  }
    return *this;
}

void LinkedList::emptyList(){
  ListNode *searchNode = head;  
  while(searchNode){
    ListNode *temp = head;
    searchNode = searchNode-> Next;
    delete temp;
  }
  size = 0;
  head = 0;
}  

void LinkedList::insert(int pos, int val){
  
  ListNode * insertOne = head;
  if(pos < size && pos > 0){
    int i = 0;
    while(i < pos){
      insertOne = insertOne -> Next;
      ++i;
    }
    
    ListNode *newNode = new ListNode(val);
    newNode -> Next = insertOne -> Next;
    insertOne ->Next = newNode;
    size = size + 1;
  }else{
    cout << "Error! The position needs to be between 0 and " << size << endl;
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

  // move the head
  if(head->val == input){
    ListNode *temp = head;
    head = head->Next;
    delete temp;
    --size;
    return input;
  }
  
  ListNode *p1 = head;

  // always start from the node before the deleted one
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


bool LinkedList::isEmpty(){
  return (size == 0);
}
  
// Remove duplicated item with hash table to remove the duplicated node
// The main algorithm is as following: simply iterate through the whole linked list, push each element into the hash table, if a duplicated one is found, remove it. The running time of the algorithm is O(n).
void LinkedList::removedDuplicated1(){
  map<int, int> mymap;
  ListNode *p1 = head;
  if(!p1){
    cout << "There is no linked list here! " << endl;
  }else{
    // remember to store the head value
    mymap[p1->val] = 1;
    
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
  if(!p1){
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
