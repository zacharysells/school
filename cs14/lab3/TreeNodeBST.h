// *********************************************************
// Header file TreeNodeBST.h for the ADT Binary Search Tree.
// *********************************************************
#include "KeyedItem.h"


#ifndef TREENODEBST_H_
#define TREENODEBST_H_

typedef KeyedItem TreeItemType;

class TreeNode // a node in the tree
{
private:
   TreeNode() { }
   TreeNode(const TreeItemType& nodeItem,
            TreeNode *left = NULL, TreeNode *right = NULL)
           : item(nodeItem), leftChildPtr(left),
             rightChildPtr(right) { }
   TreeItemType item; // a data item in the tree
   // pointers to children
   TreeNode *leftChildPtr, *rightChildPtr;

   // friend class - can access private parts
   friend class BinarySearchTree;
}; // end class

#endif /* TREENODEBST_H_ */
