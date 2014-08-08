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
 public:
  LinkedList(LinkedList &rhs);
  LinkedList():size(0), head(0){};
  ~LinkedList();

  const LinkedList & operator=(const LinkedList &rhs); 
  int deleteNode(int val);
  void display();
  void insert(int pos, int val);
  void append(int val);
  ListNode *curHead();
  int currSize();
  void clearList();
  void makeLoop(int index);
  ListNode * LoopHead();
 private:
  ListNode *head;
  int size;

};

#endif
