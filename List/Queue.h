// Template Queue class definition derived from class List
#ifndef QUEUE_H
#define QUEUE_H

#include "List.h" // List class definition

template<typename Queuetype>
class Queue: private List<Queuetype>{
 public:
  // enqueue calls List member function insertAtBack
  void enqueue( const Queuetype &data){
    insertAtBack( data );
  } // end function enqueue

  // dequeue calls List member function removeFromFront
  bool dequeue(Queuetype &data){
    return removeFromFront(data);
  } // end function dequeue

  // isQueueEmpty calls List member function isEmpty
  bool isQueueEmpty() const{
    return this->isEmpty();
  }

  // printQueue calls List member function print
  void printQueue() const{
    this->print();
  } // end function printQueue
};  // end class Queue

#endif
