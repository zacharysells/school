#include <iostream>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include "BST.h"

using namespace std;

void READ_FROM_FILE(BinarySearchTree& tree)
{
    int value;
	ifstream filename;
    filename.open ("txtfile.txt");
    while (!filename.eof())
    {
        filename >> value;
        tree.searchTreeInsert(value);
    }
}
// display the item key
void display(TreeItemType& anItem)
{
	cout << anItem.getKey() << endl;
}

// read from console the tree values
void storeTreeNodes(BinarySearchTree& tree)
{
	int value; // node value
	cout << "Enter a positive value (negative value to stop): " ;
	cin >> value;
	while (value > -1)
	{
		tree.searchTreeInsert(value);

		cout << "Enter a positive value (negative value to stop): " ;
		cin >> value;
	}
}

void show_root(const BinarySearchTree& tree)
{
   TreeItemType item = tree.rootData();
   cout << item.getKey();
}//end show_root()

//-------------------------------------------------------------------

int count(const BinarySearchTree& tree)
{
    if(tree.isEmpty()) return 0;
    
    return 1 + count(tree.leftSubtree()) + count(tree.rightSubtree());
    
}//end count()

//--------------------------------------------------------------------

int sum(const BinarySearchTree& tree)
{
    if(tree.isEmpty()) return 0;
    return (tree.rootData()).getKey() + sum(tree.leftSubtree()) + sum(tree.rightSubtree());
    
}//end sum()
    
//---------------------------------------------------------------------
int height(const BinarySearchTree& tree)
{
    if(tree.isEmpty()) return 0;
    int left_height = height(tree.leftSubtree());
    int right_height = height(tree.rightSubtree());
    if(right_height > left_height) return right_height + 1;
    else return left_height + 1;

}//end height()

//--------------------------------------------------------------------------

void search_range(const BinarySearchTree &tree,int a, int b)
{
    if(tree.isEmpty()) return;
  
    search_range(tree.leftSubtree(),a,b);
    if(tree.rootData().getKey() >= a && tree.rootData().getKey() <= b) cout << tree.rootData().getKey() << endl;
    search_range(tree.rightSubtree(),a,b);
}
    
    
//end search_range()
int main()
{
	BinarySearchTree aTree;
    
	storeTreeNodes(aTree);
	int low, high;
    low = 13;
	cout << endl << "-------------------------------------------------" << endl;
	cout << "IN ORDER TRAVERSE: "<< endl;
	aTree.inorderTraverse(display);

    cout << "a.) Root: ";
    show_root(aTree);
    cout << "\nb.) Count: ";
    cout << count(aTree) << endl;
    cout << "c.) Sum: " << sum(aTree) << endl;
    cout << "e.) Height: " << height(aTree) << endl;
    cout << "d.) Search and count for value: " << low << endl << endl;
    cout << "f.)Number of comparisons = " << aTree.searchCount(low) << endl;
    
    cout << "Search Range between 5 and 12: " << endl;
    search_range(aTree,5,12);
    
    cout << "\nh.) In order traversal 2(Iterative): " << endl;
    aTree.inorderTraverse2();
    
    
    cout << "g.)Print structured tree:" << endl;
    aTree.printTree();
    
    cout << "Saving tree to file, 'BST_tree.txt'" << endl;
    aTree.saveTree();
    
    cout << "Restoring tree..." << endl;
    //BinarySearchTree t = aTree.restoreTree("BST_tree.txt");
    //t.printTree();
	return 0;
}
