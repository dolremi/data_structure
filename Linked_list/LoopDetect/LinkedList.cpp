#include "LinkedList.h"
#include <iostream>

using namespace std;

LinkedList::LinkedList(LinkedList &rhs){
  operator=(rhs);
}

const LinkedList & LinkedList::operator=(const LinkedList &rhs){
  // check self-assignment
  if(this != &rhs){
    clearList();
    ListNode *copy = rhs.curHead();
    
    while(copy){
      append(copy->val);
      copy = copy->Next;
    }
    size = rhs.currSize();
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
     delete tmp;
   }

   size = 0;
   head = 0;
 }

void LinkedList::insert(int pos, int val){
  ListNode * insertOne = head;
  if(pos < size & pos >0){
    for(int i = 0; i < pos -1; i++){
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
    head = head-> Next;
    delete temp;
    --size;
    return input;
  }
  
  ListNode *p1 = head;

  while(p1->Next){
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

  while(fast && fast->Next){
    slow = slow->Next;
    fast = fast->Next->Next;

    if(slow == fast)
      break;
  }

  // No loop case
  if(!fast || !fast->Next){
    return 0;
  }
  slow = head;
  while(slow != fast){
    slow = slow ->Next;
    fast = fast->Next;
  }
  return slow;
}

