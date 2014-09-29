#ifndef TREE_H
#define TREE_H

#include <iostream>
#include "TreeNode.h"
using namespace std;

template<typename Nodetye> 
class Tree{
 public:
  Tree(); // constructor
  void insertNode(const Nodetype &);
  void preOrderTraversal() const;
  void inOrderTraversal() const;
  void postOrderTraversal() const;
 private:
  TreeNode<Nodetype> *rootPtr;
  
  // utility functions
  void insertNodeHelper( TreeNode<Nodetype> **, const Nodetype &);
  void preOrderHelper(TreeNode<Nodetype> * ) const;
  void inOrderHelper(TreeNode<Nodetype> *) const;
  void postOrderHelper(TreeNode<Nodetype> *) const;
}; // end class Tree

// constructor
template<typename Nodetype>
Tree<Nodetype>::Tree(){
  rootPtr = 0; // indicate tree is initially empty
} // end Tree constructor

// insert node in Tree
template<typename Nodetype>
void Tree<Nodetype>::insertNode(const Nodetype &value){
  insertNodeHelper( &rootPtr, value);
} // end function insertNode

// utility function called by insertNode
template<typename Nodetype>
void Tree<Nodetype>::insertNodeHelper(TreeNode<Nodetype> **ptr, const Nodetype &value){
  // subtree is empty; create new TreeNode containing value
  if( *ptr == 0)
    *ptr = new TreeNode<Nodetype> (value);
  else{ // subtree is not empty
    if( value < (*ptr)->data)
      insertNodeHelper( & ( ( *ptr)->leftPtr), value);
    else{
      if( value > (*ptr) -> data)
	insertNodeHelper( & ( (*ptr)->rightPtr), value);
      else
	cout << value << "dup" << endl;
    }
  }
}

// begin preorder traversal of Tree
template<typename Nodetype>
void Tree<Nodetype>::preOrderTraversal() const{
  preOrderHelper( rootPtr);
} // end function preOrderTraversal

// utility funtion to perform preOrder traversal
template<typename Nodetype>
void Tree<Nodetype>::preOrderHelper( TreeNode<Nodetype> *ptr){
  if( ptr){
    cout << ptr->data << ' ';
    preOrderHelper(ptr->leftPtr);
    preOrderHelper(ptr->rightPtr);
  }
}
