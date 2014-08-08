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
 public:
  LinkedList(LinkedList &rhs);
  LinkedList():size(0), head(0){};
  ~LinkedList();

  const LinkedList & operator=(const LinkedList &rhs);
  void insert(int pos, int val);
  void append(int val);
  int deleteNode(int input);
  ListNode *curHead();
  int currSize();
  void display();
  void partition(int k);

 private:
  ListNode *head;
  int size;
  void clearList();
};

#endif
