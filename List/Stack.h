// Template Stack class definition derived from class List
#idndef STACK_H
#define STACK_H

#include "List.h" // List class definition

template<typename Stacktype>
class Stack: private List< Stacktype>{
 public:
  // push calls the List function insertAtFront
  void push( const Stacktype &data){
    insertAtFront( data );
  } // end function push

  // pop calls the List function removeFromFront
  bool pop( Stacktype &data){
    return removeFromFront( data );
  } // end function pop

  // isStackEmpty calls the List function isEmpty
  bool isStackEmpty() const{
    return this->isEmpty();
  } // end function isStackEmpty

  // printStack calls the List function print
  void printStack() const{
    this->print();
  } // end function print
}; // end class Stack

# endif
