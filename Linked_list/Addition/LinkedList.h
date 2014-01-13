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

  ListNode *curHead();
  int currSize();
   
  bool deleteNode(int val);
  bool insert(int pos, int val);
  void append(int val);
  void display();
  
  void addReverse(LinkedList &lhs, LinkedList &rhs);
  int RlistToNumber(ListNode *input);
  void NumberToRList(int result);
  void addForward(LinkedList &lhs, LinkedList &rhs);
  int FlistToNumber(ListNode *input, int &i);
  void NumberToFList(int result);

  void addRInPlace(LinkedList &lhs, LinkedList &rhs);
};

#endif
