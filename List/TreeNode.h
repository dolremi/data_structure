#ifndef TREENODE_H
#define TREENODE_H

// forward declaration of class Tree
template<typename Nodetype> class Tree;

// TreeNode class-template definition
template<typename Nodetype> 
class TreeNode{
  friend class Tree<Nodetype>;
 public:
  // constructor
 TreeNode(const Nodetype &d): leftPtr(0), // pointer to left tree
                              data(d),    // tree node data
                              rightPtr(0) // pointer to right subtree
				{} // end TreeNode constructor

  Nodetype getData() const{
    return data;
  }

 private:
  TreeNode<Nodetype> *leftPtr;
  Nodetype data;
  TreeNode<Nodetype> *rightPtr;
}; // end class TreeNode

#endif
