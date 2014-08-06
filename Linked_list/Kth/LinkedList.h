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
  LinkedList():size(0), head(0){};
  LinkedList(LinkedList &rhs);
  ~LinkedList();

  ListNode *currentHead();
  int currentSize();

  const LinkedList & operator=(const LinkedList &rhs);
  bool insert(int pos, int val);
  void append(int val);
  int deleteNode(int val);
  void display();
 
  // Iterative version of kth to last 
  ListNode* kthlastIter(int k);

  // Recursive version of kth to last
  ListNode* kthlastRecur(ListNode *head, int& k, int m);
 private:
  void clearList();
  ListNode *head;
  int size;
 };

#endif
