#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

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
  LinkedList(LinkedList &rhs);
  LinkedList();
  ~LinkedList();

  bool deleteNode(int val);
  bool insert(int pos, int val);
  void append(int val);
  void display();
  ListNode *curHead();
  int currSize();

  bool isPalin();
  bool isPalinR(ListNode *head, int length, ListNode *&next);  
};

#endif
