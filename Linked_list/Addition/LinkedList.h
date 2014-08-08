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
  LinkedList():size(0), head(0);
  LinkedList(int size, int val);
  LinkedList(LinkedList &rhs);

  ~LinkedList();

  const LinkedList& operator=(const LinkedList &);
  ListNode *curHead();
  int currSize();
   
  int deleteNode(int val);
  void insert(int pos, int val);
  void append(int val);
  void display();
  
  void addReverse(LinkedList &lhs, LinkedList &rhs);
  int RlistToNumber(ListNode *input);
  void NumberToRList(int result);
  void addForward(LinkedList &lhs, LinkedList &rhs);
  int FlistToNumber(ListNode *input, int &i);
  void NumberToFList(int result);

  void addRInPlace(LinkedList &lhs, LinkedList &rhs);
 private:
  ListNode *head;
  int size;
  void clearList();
};

#endif
