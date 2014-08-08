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
  LinkedList():size(0), head(0);
  ~LinkedList();

  ListNode *getHead(){ return head;}
  size getSize(){return size;}
  const LinkedList & operator=(const LinkedList &);
  void insert(int pos, int val);
  void append(int val);
  ListNode * middle();
  int deleteNode(int val);
  void display();
  void removeMiddle(ListNode *midOne);
 private:
  ListNode *head;
  int size;
  void clearList();
};

#endif
