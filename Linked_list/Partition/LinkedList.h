#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

// General class for linked list data structure 
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

  bool insert(int pos, int val);
  void append(int val);
  bool deleteNode(int input);
  ListNode *curHead();
  int currSize();
  void display();
  void partition(int k);  
};

#endif
