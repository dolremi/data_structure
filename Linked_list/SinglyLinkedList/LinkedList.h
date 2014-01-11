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

  // Private members in LinkedList
  ListNode *head;
  int size;
 public:

  // Constructors and destructors for the linked list
  LinkedList(int size, int val);
  LinkedList(LinkedList &rhs);
  LinkedList();
  ~LinkedList();

  // Getter functions in the class
  ListNode *curHead();
  int currSize();

  // Setter functions in the class 
  bool insert(int pos, int val);
  void append(int val);
  bool deleteNode(int val);

  // Print the list of the nodes
  void display();
  
};

#endif
