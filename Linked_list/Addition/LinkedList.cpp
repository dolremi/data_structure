#include "LinkedList.h"
#include <iostream>
#include <math.h>

using namespace std;

LinkedList::LinkedList(LinkedList &rhs){
  operator=(rhs);
}

const LinkedList & LinkedList::operator=(const LinkedList &rhs){
  // check the self-assignment
  if(this != &rhs){
    clearList();
    ListNode *copy = rhs.curHead();
    
    while(copy){
      append(copy->val);
      copy = copy -> Next;
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
    ListNode temp = p1;
    p1 = p1->Next;
    delete p1;
  }
}

void LinkedList::insert(int pos, int val){
  ListNode * insertOne = head;
  if(pos < size && pos > 0){
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
  

// add two linked list to one, for instance
//  input: 7 -> 1 -> 6 + 5 -> 9 -> 2 That is 617 + 295
//  output: 2 -> 1 -> 9 That is 912
//  The idea is at first convert each linked list
//  to a number, then add them together. At last convert
//  back to the linked list. 

void LinkedList::addReverse(LinkedList &lhs, LinkedList &rhs){
  int result = RlistToNumber(lhs.head) + RlistToNumber(rhs.head);
  cout << "The result is " << result << endl;
  NumberToRList(result);
}

void LinkedList::NumberToRList(int result){
  int i = 0;
  ListNode *p1 = head;
  
  while(result){
    int value = result % 10;    
    result /= 10;
    append(value);
  }
}

// convert reverse order list to a number
int LinkedList::RlistToNumber(ListNode *input){
  int result = 0;
  int tenth = 1;
  ListNode *p1 = input;
 
  while(p1){
    result += p1->val * tenth;
    tenth *= 10;
    p1 = p1-> Next;
  }

  return result;
}
  
// Now the forward order list needs to use recursive version
void LinkedList::addForward(LinkedList &lhs, LinkedList &rhs){
  int k = 1, j = 1;
  int result = FlistToNumber(lhs.head, k) + FlistToNumber(rhs.head, j);

  cout << "Now the result is " << result << endl;
  NumberToFList(result);

}

int LinkedList::FlistToNumber(ListNode *input, int &i){
  if(input -> Next == NULL){
    return input->val * i;
  }

  int result = FlistToNumber(input->Next, i);
  i *= 10;
  result += i * input->val;
  return result;
}

void LinkedList::NumberToFList(int result){
  if(result < 10){
    append(result);
    return;
  }
  NumberToFList(result /10);
  append(result%10);
}
  
// Add two linked list in place like the Book solution
void LinkedList::addRInPlace(LinkedList &lhs, LinkedList &rhs){
  ListNode *lp1 = lhs.head;
  ListNode *rp1 = rhs.head;

  if(lp1 == NULL && rp1 == NULL)
    return ;
  
  int total = lp1->val + rp1->val;
  int carry = total/10;
  head  = new ListNode(total%10);
  ListNode *p1 = head; 
  size = 1;
  
  lp1 = lp1->Next;
  rp1 = rp1->Next;
  
  while(lp1 && rp1){
    total = lp1->val + rp1->val + carry;
    carry = total/10;
  
    cout << "Now the carry is " << carry;
    ListNode *newNode = new ListNode(total%10);

    p1->Next = newNode;
    p1 = p1->Next;

    lp1 = lp1->Next;
    rp1 = rp1->Next;
    ++size;
  }

  if(lp1){
    while(lp1){
      total = lp1->val + carry;
      carry = total/10;
      ListNode *newNode = new ListNode(total%10);
      p1->Next = newNode;
      p1 = p1->Next;
      lp1 = lp1 -> Next;     
    }
  }else{
    while(rp1){
      total = rp1->val + carry;
      carry = total/10;
      ListNode *newNode =new ListNode(total%10);
      p1->Next = newNode;
      p1 = p1->Next;
      rp1 = rp1->Next;
    }
  }
}
    
  
