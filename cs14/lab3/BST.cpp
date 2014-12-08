// *********************************************************
// Implementation file BST.cpp.
// *********************************************************
#include "BST.h" // header file
#include <cstddef> // definition of NULL
#include <iostream> //Need for printTree() function
#include <vector> //Need for inorderTraverse2() function
#include <fstream> //Need for file io

BinarySearchTree::BinarySearchTree() : root(NULL)
{
} // end default constructor

BinarySearchTree::BinarySearchTree(
                               const BinarySearchTree& tree)
{
   copyTree(tree.root, root);
} // end copy constructor

BinarySearchTree::BinarySearchTree(TreeNode *nodePtr) : root(nodePtr)
{
} // end protected constructor

BinarySearchTree::~BinarySearchTree()
{
   destroyTree(root);
} // end destructor

bool BinarySearchTree::isEmpty() const
{
   return (root == NULL);
} // end searchTreeIsEmpty

TreeItemType BinarySearchTree::rootData() const
{
   if (isEmpty())
      throw TreeException("TreeException: Empty tree");
   return root->item;
} // end rootData


void BinarySearchTree::searchTreeInsert(
                               const TreeItemType& newItem)
{
   insertItem(root, newItem);
} // end searchTreeInsert

void BinarySearchTree::searchTreeDelete(KeyType searchKey)
{
   deleteItem(root, searchKey);
} // end searchTreeDelete

void BinarySearchTree::searchTreeRetrieve(KeyType searchKey,
                                          TreeItemType& treeItem) const
{
   // if retrieveItem throws a TreeException, it is
   // ignored here and passed on to the point in the code
   // where searchTreeRetrieve was called
   retrieveItem(root, searchKey, treeItem);
} // end searchTreeRetrieve

void BinarySearchTree::preorderTraverse(FunctionType visit)
{
   preorder(root, visit);
} // end preorderTraverse

void BinarySearchTree::inorderTraverse(FunctionType visit)
{
   inorder(root, visit);
} // end inorderTraverse

void BinarySearchTree::postorderTraverse(FunctionType visit)
{
   postorder(root, visit);
} // end postorderTraverse

void BinarySearchTree::insertItem(TreeNode *& treePtr,
                                  const TreeItemType& newItem)
{
   if (treePtr == NULL)
   {  // position of insertion found; insert after leaf

      // create a new node
      treePtr = new TreeNode(newItem, NULL, NULL);

      // was allocation successful?
      if (treePtr == NULL)
         throw TreeException("TreeException: insert failed");
   }

   // else search for the insertion position
   else if (newItem.getKey() < treePtr->item.getKey())
      // search the left subtree
      insertItem(treePtr->leftChildPtr, newItem);

   else // search the right subtree
      insertItem(treePtr->rightChildPtr, newItem);
} // end insertItem

void BinarySearchTree::deleteItem(TreeNode * &treePtr, KeyType searchKey)
// Calls: deleteNodeItem.
{
   if (treePtr == NULL)
      throw TreeException(
         "TreeException: delete failed"); // empty tree

   else if (searchKey == treePtr->item.getKey())
      // item is in the root of some subtree
      deleteNodeItem(treePtr); // delete the item

   // else search for the item
   else if (searchKey < treePtr->item.getKey())
      // search the left subtree
      deleteItem(treePtr->leftChildPtr, searchKey);

   else // search the right subtree
      deleteItem(treePtr->rightChildPtr, searchKey);
} // end deleteItem

void BinarySearchTree::deleteNodeItem(TreeNode * &nodePtr)
// Algorithm note: There are four cases to consider:
// 1. The root is a leaf.
// 2. The root has no left child.
// 3. The root has no right child.
// 4. The root has two children.
// Calls: processLeftmost.
{
   TreeNode *delPtr;
   TreeItemType replacementItem;

   // test for a leaf
   if ( (nodePtr->leftChildPtr == NULL) &&
        (nodePtr->rightChildPtr == NULL) )
   {  delete nodePtr;
      nodePtr = NULL;
   } // end if leaf

   // test for no left child
   else if (nodePtr->leftChildPtr == NULL)
   {  delPtr = nodePtr;
      nodePtr = nodePtr->rightChildPtr;
      delPtr->rightChildPtr = NULL;
      delete delPtr;
   } // end if no left child

   // test for no right child
   else if (nodePtr->rightChildPtr == NULL)
   {  delPtr = nodePtr;
      nodePtr = nodePtr->leftChildPtr;
      delPtr->leftChildPtr = NULL;
      delete delPtr;
   } // end if no right child

   // there are two children:
   // retrieve and delete the inorder successor
   else
   {  processLeftmost(nodePtr->rightChildPtr,
                      replacementItem);
      nodePtr->item = replacementItem;
   } // end if two children
} // end deleteNodeItem

void BinarySearchTree::processLeftmost(TreeNode *&nodePtr,
                                       TreeItemType& treeItem)
{
   if (nodePtr->leftChildPtr == NULL)
   {  treeItem = nodePtr->item;
      TreeNode *delPtr = nodePtr;
      nodePtr = nodePtr->rightChildPtr;
      delPtr->rightChildPtr = NULL; // defense
      delete delPtr;
   }

   else
      processLeftmost(nodePtr->leftChildPtr, treeItem);
} // end processLeftmost

void BinarySearchTree::retrieveItem(TreeNode *treePtr,
                                    KeyType searchKey,
                                    TreeItemType& treeItem) const
{
   if (treePtr == NULL)
      throw TreeException(
         "TreeException: searchKey not found");

   else if (searchKey == treePtr->item.getKey())
      // item is in the root of some subtree
      treeItem = treePtr->item;

   else if (searchKey < treePtr->item.getKey())
      // search the left subtree
      retrieveItem(treePtr->leftChildPtr,
                   searchKey, treeItem);

   else // search the right subtree
      retrieveItem(treePtr->rightChildPtr,
                   searchKey, treeItem);
} // end retrieveItem


BinarySearchTree& BinarySearchTree::operator=(const BinarySearchTree& bst)
{
   if (this != &bst)
   {  destroyTree(root); // deallocate left-hand side
      copyTree(bst.root, root); // copy right-hand side
   } // end if
   return *this;
} // end operator=



void BinarySearchTree::copyTree(TreeNode *treePtr,
                          TreeNode *& newTreePtr) const
{
   // preorder traversal
   if (treePtr != NULL)
   {  // copy node
      newTreePtr = new TreeNode(treePtr->item, NULL, NULL);
      if (newTreePtr == NULL)
         throw TreeException(
            "TreeException: Cannot allocate memory");

      copyTree(treePtr->leftChildPtr, newTreePtr->leftChildPtr);
      copyTree(treePtr->rightChildPtr, newTreePtr->rightChildPtr);
   }
   else
      newTreePtr = NULL; // copy empty tree
} // end copyTree

void BinarySearchTree::destroyTree(TreeNode *& treePtr)
{
   // postorder traversal
   if (treePtr != NULL)
   {  destroyTree(treePtr->leftChildPtr);
      destroyTree(treePtr->rightChildPtr);
      delete treePtr;
      treePtr = NULL;
   } // end if
} // end destroyTree

TreeNode *BinarySearchTree::rootPtr() const
{
  return root;
} // end rootPtr

void BinarySearchTree::setRootPtr(TreeNode *newRoot)
{
   root = newRoot;
} // end setRoot

void BinarySearchTree::getChildPtrs(TreeNode *nodePtr,
                              TreeNode *& leftPtr,
                              TreeNode *& rightPtr) const
{
   leftPtr = nodePtr->leftChildPtr;
   rightPtr = nodePtr->rightChildPtr;
} // end getChildPtrs

void BinarySearchTree::setChildPtrs(TreeNode *nodePtr,
                              TreeNode *leftPtr,
                              TreeNode *rightPtr)
{
   nodePtr->leftChildPtr = leftPtr;
   nodePtr->rightChildPtr = rightPtr;
} // end setChildPtrs

void BinarySearchTree::preorder(TreeNode *treePtr,
                          FunctionType visit)
{
   if (treePtr != NULL)
   {  visit(treePtr->item);
      preorder(treePtr->leftChildPtr, visit);
      preorder(treePtr->rightChildPtr, visit);
   } // end if
} // end preorder

void BinarySearchTree::inorder(TreeNode *treePtr,
                         FunctionType visit)
{
   if (treePtr != NULL)
   {  inorder(treePtr->leftChildPtr, visit);
      visit(treePtr->item);
      inorder(treePtr->rightChildPtr, visit);
   } // end if
} // end inorder

void BinarySearchTree::postorder(TreeNode *treePtr,
                           FunctionType visit)
{
   if (treePtr != NULL)
   {  postorder(treePtr->leftChildPtr, visit);
      postorder(treePtr->rightChildPtr, visit);
      visit(treePtr->item);
   } // end if
} // end postorder

BinarySearchTree BinarySearchTree::leftSubtree() const
{
   TreeNode *subTreePtr;
   if (isEmpty())
      return BinarySearchTree();
   else
   {  copyTree(root->leftChildPtr, subTreePtr);
      return BinarySearchTree(subTreePtr);
   } // end if
} // end leftSubtree

BinarySearchTree BinarySearchTree::rightSubtree() const
{
   TreeNode *subTreePtr;
   if (isEmpty())
      return BinarySearchTree();
   else
   {  copyTree(root->rightChildPtr, subTreePtr);
      return BinarySearchTree(subTreePtr);
   } // end if
} // end rightSubtree

//-------------------------------------------------------------------------

int BinarySearchTree::searchCount(int value)
{
	static int depth = 0;
    if(this->rootData().getKey() == value)
    {
		return 1;
	}
    if(this->rightSubtree().isEmpty() || this->leftSubtree().isEmpty()) return depth;
    if(value < this->rootData().getKey())
    {
		depth--;
		return 1 + (this->leftSubtree()).searchCount(value);
	}
		
    else
    { 
		depth--;
		return 1 + this->rightSubtree().searchCount(value);
	}
    
}//end searchCount()

//----------------------------------------------------------------------------

void BinarySearchTree::printTree()
{
	
	static int depth = 0;
    if(this->isEmpty()) return; 

    for(int i = 0; i < depth; i++) cout << " ";
	cout << this->rootData().getKey() << endl;
	depth++;
	
    if (!this->leftSubtree().isEmpty() ) this->leftSubtree().printTree();
    if(!this->rightSubtree().isEmpty()) this->rightSubtree().printTree();
 
	depth--;
    
}//end printTree();

void BinarySearchTree::inorderTraverse2()
{
	vector<TreeNode *> stack;
	TreeNode * current = root;
	while(true)
	{
		if(current != NULL)
		{
			stack.push_back(current);
			current = current->leftChildPtr;
		}
		else
		{
			if(stack.size() == 0)
			{
				return;
			}
			else
			{
				current = stack.at(stack.size() -1);
				stack.pop_back();
				cout << current->item.getKey() << endl;
				current = current->rightChildPtr;
			}
		}
				
	}
}//end inorderTraverse2()

//----------------------------------------------------------------------

//void BinarySearchTree::insertItem2(TreeNode * &node_ptr,const TreeItemType &newItem)
//{//Iterative version of insert item.
	
	//TreeNode * current = this->rootPtr();
	//while(current != NULL)
	//{
		//if(current->rootData().getKey() < newItem.item.getKey()) current = current->rightSubtree();
		//else current = current->leftSubtree()
	//}
	
	
//}//end insertItem2()

//----------------------------------------------------------------------

void BinarySearchTree::saveTree_helper(ofstream & file)
{
	static int depth = 0;
    if(this->isEmpty()) return; 

    for(int i = 0; i < depth; i++) file << " ";
	file << this->rootData().getKey() << endl;
	depth++;
	
    if (!this->leftSubtree().isEmpty() ) this->leftSubtree().saveTree_helper(file);
    if(!this->rightSubtree().isEmpty()) this->rightSubtree().saveTree_helper(file);
 
	depth--; 
	
}//end saveTree_helper()

void BinarySearchTree::saveTree()
{
	ofstream file;
	file.open("BST_tree.txt");
	this->saveTree_helper(file);
	
}//end saveTree()

//----------------------------------------------------------------------

//BinarySearchTree BinarySearchTree::restoreTree(const string& s)
//{
	//int x = 0;
	//ifstream file;
	//BinarySearchTree t;
	//file.open(s.c_str());
	//while(file.get() != '\0')
	//{
		//file.unget();
		//x = file.get();
		//if(x > 0)
		//{
			//KeyedItem key = x;
			//t.insertItem(t.rootPtr(),key);
		//}
	//}
	
//}//end restoreTree()

