#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

/* Remove the duplicated item using two different methods */

using namespace std;

// structure for one node of the singly linked list

struct ListNode{
  int val;
  struct ListNode *Next;
  ListNode(int x): val(x), Next(0){}
};
 

class LinkedList{

  ListNode *head;
  int size;
 public:

// The default constructor is to allocate a linked list with size n and values of val
  LinkedList(int size, int val);
  LinkedList();
  LinkedList(LinkedList &rhs);

  ~LinkedList();

  bool insert(int pos, int val);

  ListNode *currentHead();
  int currentSize();
  void append(int val);
  bool deleteNode(int val);
  void display();

  // With hash table version
  void removedDuplicated1();

  // Without hash table version
  void removedDuplicated2();

  // Iterative version of kth to last 
  ListNode* kthlastIter(int k);

  // Recursive version of kth to last
  ListNode* kthlastRecur(ListNode *head, int& k, int m);
};

#endif
