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
   LinkedList():size(0),input(0){};
  LinkedList(LinkedList &rhs);

  ~LinkedList();

  const LinkeList & operator=(const LinkedList &rhs);
  int deleteNode(int val);
  void insert(int pos, int val);
  void append(int val);
  void display();
  ListNode *curHead();
  int currSize();

  bool isPalin();
  bool isPalinR(ListNode *head, int length, ListNode*& next);  
 private:
  ListNode *head;
  int size;
  void clearList();
};

#endif
