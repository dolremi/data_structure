#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

// General class for linked list data structure 

using namespace std;

// structure for one node of the singly linked list
// no hidden member data in C struct
struct Node{
  int val;
  struct Node *Next;
  Node(int x): val(x), Next(0){}
};
 
class LinkedList{

 public:
  LinkedList():head(0),size(0){};
  
  // copy constructors and destructors
  LinkedList(const LinkedList &rhs);
  ~LinkedList();

  // Assignment operator overloading for "big three"
  const LinkedList & operator=(const LinkedList &right);

  void insert(int pos, int val);
  void append(int val);
  int deleteNode(int val);

  // Print the list of the nodes
  void display();
  
  // Getter functions in the class
  Node *getHead();
  int getSize();
  bool isEmpty();
 private:
 // Private members in LinkedList
  Node *head;
  int size;

  // Utility functions
  void clearList(); 
};

#endif
