// Template List class definition
#ifndef LIST_H
#define LIST_H

#include <iostream>
#include"ListNode.h" // ListNode class definition
using namespace std;

template <typename Nodetype>
class List{
public:
  List(); // constructor
  ~List(); // destructor
  void insertAtFront(const Nodetype &);
  void insertAtBack(const Nodetype &);
  bool removeFromFront(Nodetype &);
  bool removeFromBack(Nodetype &);
  bool isEmpty() const; 
  void print() const;
private:
  ListNode<Nodetype> *firstPtr; // pointer to first node
  ListNode<Nodetype> *lastPtr; // pointer to last node

  // utility funciton to allocate new node
  ListNode<Nodetype> *getNewNode(const Nodetype &);
}; // end class List

// default constructor
template<typename Nodetype>
List<Nodetype>::List()
  : firstPtr(0), lastPtr(0){} // end List constructor

// destructor
template<typename Nodetype>
List<Nodetype>::~List(){
  if( !isEmpty()){ // List is not empty
    cout << "Destroying nodes ... \n";
    
    ListNode<Nodetype> *currentPtr = firstPtr;
    ListNode<Nodetype> *tempPtr; 

    while( currentPtr){ // delete remaining 
      tempPtr = currentPtr;
      cout << tempPtr -> data << "\n";
      currentPtr = currentPtr->nextPtr;
      delete tempPtr;
    } // end while
  } // end if
  
  cout << "All nodes destroyed \n\n";
} // end List destructor

// insert node at front of list
template< typename Nodetype>
void List<Nodetype>::insertAtFront(const Nodetype & value){
  ListNode<Nodetype> *newPtr = new Nodetype( value );
  
  if( isEmpty() ) // List is empty
    firstPtr = lastPtr = newPtr;  // new list has only one node
  else{ // List is not empty
    newPtr->nextPtr = firstPtr; // point new node to previous 1st node
    firstPtr = newPtr;  // aim firstPtr to newPtr
  } // end else
} // end function

// insert node at back of list
template<typename Nodetype>
void List<Nodetype>::insertAtBack(const Nodetype &value){
  ListNode<Nodetype> *newPtr = new Nodetype( value );
  
  if( isEmpty() ) // List is empty
    firstPtr = lastPtr = newPtr; // new list has only one node
  else{ // List is not empty
    lastPtr->nextPtr = newPtr; // point lastPtr to new node
    lastPtr = newPtr; // new last node
  }  // end else
}  // end function


// delete node from front of list
template<typename Nodetype>
bool List<Nodetype>::removeFromFront(Nodetype &value){
 
  if( isEmpty() ) // List is empty
    return false; // delete unsuccessful
  else{
    ListNode<Nodetype> *tempPtr = firstPtr;
    
    if( firstPtr == lastPtr)
      firstPtr = lastPtr = 0; // no nodes remain after removal
    else
      firstPtr = firstPtr->nextPtr; // point to previous 2nd node

    value = tempPtr->data; // return data being removed
    delete tempPtr;  // reclaim previous front node
    return true;  // delete successful
  } // end else
} // end function removeFromFront

// delete node from back of list
template<typename Nodetype>
bool List<Nodetype>::removeFromBack(Nodetype &value){
  if( isEmpty()) // List is empty
    return false;
  else{
    ListNode<Nodetype> *tempPtr = lastPtr; // hold tempPtr to delete

    if( firstPtr == lastPtr) // List has one element
      firstPtr = lastPtr = 0; // no nodes remain after removal 
    else{
      ListNode<Nodetype> *currentPtr = firstPtr;
      
      // locate second-to-last element
      while( currentPtr->nextPtr != lastPtr)
	currentPtr = currentPtr->nextPtr; // move to next node

      lastPtr = currentPtr; // remove last node
      currentPtr->nextPtr = 0; // this is now the last node
    } // end else
    value = tempPtr->data; // return value from old last node
    delete tempPtr; // reclaim former last node
    return true;   // delete successful
  } // end else
} // end function removeFromBack

// is List empty?
template<typename Nodetype>
bool List<Nodetype>::isEmpty() const{
  return firstPtr == 0;
} // end function isEmpty

// return pointer to newly allocated node
template<typename Nodetype>
ListNode<Nodetype> *List<Nodetype>::getNewNode(const Nodetype &value){
  return new ListNode<Nodetype> (value);
}  // end function getNewNode

// dieplay contents of List
template <typename Nodetype>
void List<Nodetype>::print() const{
  if( isEmpty() ){ // List is empty
    cout << "The list is empty\n\n";
    return;
  } // end if
  
  ListNode<Nodetype> *currentPtr = firstPtr;

  cout << "The list is: ";
  
  while( currentPtr){ // get element data
    cout << currentPtr->data << ' ';
    currentPtr = currentPtr->nextPtr;
  }  // end while

  cout << "\n\n";
} // end function print

#endif
