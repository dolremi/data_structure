#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

// Remove the duplicated item using two different methods 
using namespace std;

// C Structure for one node of the singly linked list
struct ListNode{
  int val;
  struct ListNode *Next;
  ListNode(int x): val(x), Next(0){}
};
 

class LinkedList{

  
 public:
  LinkedList():head(0), size(0){};
  LinkedList(const LinkedList &rhs);
  ~LinkedList();

  const LinkedList & operator=(const LinkedList &rhs);
  int getSize(){return size;};
  ListNode * getHead(){return head;};
  
  void insert(int pos, int val);
  void append(int val);
  int deleteNode(int val);
  void display();
  bool isEmpty();
  // With hash table version
  void removedDuplicated1();

  // Without hash table version
  void removedDuplicated2();
 private:
  ListNode *head;
  int size;
  void emptyList();
};

#endif
