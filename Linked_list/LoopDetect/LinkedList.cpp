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
  if(LoopHead() == NULL){
    while(head){
      ListNode *temp = head;
      head = head-> Next;
      delete temp;
    }
  }else{
    ListNode *end = LoopHead();
    while(head != end){
      ListNode *temp = head;
      head = head -> Next;
      delete temp;
    }
    
    head = head -> Next;  
    while(head != end){
      ListNode *temp = head;
      head = head->Next;
      delete temp;
    }
    delete end;
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
  
  
void LinkedList::makeLoop(int index){
  if(index > 0 && index < size){
    ListNode *p1 = head;
    ListNode *end = head;
    for(int i = 0; i < index; i++){
      p1 = p1->Next;
      end = end->Next;
    }

    while(end->Next){
      end = end->Next;
    }
    end->Next = p1;
  }else{
    cout << "please insert a index value between 0 and size" << endl;
  }
}


// Runner techniques are used
//   There will be three phases to find the head of the loop
//   1. Two pointers both start from the head of the linked list, the slow one  will move one node each time, while the fast one will move two nodes each 
//         time. At the end, the slow one will meet the fast one. Otherwise one of the pointer will reach the end of the list
//   2. When two pointers collide, the fast runner is LOOP_SIZE - k steps behind the slower runner asssume the slow runner is k steps intothe loop.Therefore
//         both CollisionSpot and LinkedListHead are k nodes from the start of the loop. 
//   3. So put two pointers at LinkedListHead and CollisionSpot respectively, then move one node each time, in the end the spot the two pointers meet is the
//         the start of the loop. 
ListNode * LinkedList::LoopHead(){
  ListNode *slow = head;
  ListNode *fast = head;

  while(fast != NULL && fast->Next != NULL){
    slow = slow->Next;
    fast = fast->Next->Next;

    if(slow == fast)
      break;
  }

  // No loop case
  if(fast == NULL || fast->Next== NULL){
    return NULL;
  }
  slow = head;
  while(slow != fast){
    slow = slow ->Next;
    fast = fast->Next;
  }
  return slow;
}

