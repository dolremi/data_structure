#ifndef LISTNODE_H
#define LISTNODE_H

template <typename Nodetype> class List;
class ListNode{
  friend class List<Nodetype>; // make List a friend

public:
  ListNode(const Nodetype &); // constructor
  Nodetype getData() const; // return data in node
private:
  Nodetype data; // data
  ListNode<Nodetype> *nextPtr; // next node in list
}; // end class ListNode

// constructor
template <typename Nodetype>
ListNode<Nodetype>::ListNode(const Nodetype &info)
  : data(info), nextPtr(0){} // end ListNode constructor

// return copy of data in node
template <typename Nodetype>
Nodetype ListNode<Nodetype>::getData() const{
  return data;
} // end function getData

#endif

