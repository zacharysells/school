// bst.cc

#ifndef BST_H
#define BST_H
#define TEST

#include <cassert>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <map>
#include <list>
#include <math.h>

using namespace std;

#define nil 0

// #define Value int // restore for testing.

template < typename Value >
class Tree {

	class Node {
	public:
		Node (const Value v = Value(), int lev = 1)
				: value(v), level(lev), left(nil), right(nil)
				{}
		Node* left;
		Node* right;
		Value value;
		int count;
		int level; // for AA trees

		Value& content() { return value;}
		bool empty() { return size() == 0;}
		bool isExternal() { return left == nil && right == nil;}
		bool isInternal() { return !isExternal();}

		int size() {
			// returns the size of the subtree rooted at this node
			// FILL IN

		}

		int height() {
			// returns the height of the subtree rooted at this node
			// FILL IN
		}

	}; // Node

	// const Node* nil;
	Node* root;
	int count;


public:

	void print_node( const Node* n) {
		// Prints the node value.
		// FILL IN
	}

	bool search (Value x) {
		// search for a value in the BST and returns true if it was found.
		// FILL IN
	}

	void preorder() const {
		// Traverse and print the tree one Value per line in preorder.
		// FILL IN
	}

	void postorder()const {
		// Traverse and print the tree one Value per line in postorder.
		// FILL IN
	}

	void inorder()const {
		// Traverse and print the tree one Value per line in inorder.
		// FILL IN
		}

	Value& operator[] (int n){
		// returns reference to the value field of the n-th Node.
		// FILL IN
	}


	Tree() : count(0), root(nil) {}

	void insert (Value X) { root = insert( X, root); }

	Node* insert( Value X, Node* T) {
		// The normal binary tree insertion procedure ...
		if ( T == nil) {
			T = new Node (X);  // The only place that T gets updated.
		} else if ( X < T->value ) {
			T->left = insert( X, T->left );
		} else if ( X > T->value ) {
			T->right = insert( X, T->right );
		} else {
			T->value = X;
		}

		// later, rebalancing code will be installed here

		return T;
	}

	void remove( Value X ) { root = remove( X, root); }
	Node* remove( Value X, Node* T ) {
		// The normal binary-tree removal procedure ...
		// Weiss's code is faster but way more intricate.

		if (T != nil) {
			if ( X > T->value ) {
				T->right = remove( X, T->right );
			} else if ( X < T->value ) {
				T->left = remove( X, T->left );
			} else {
				if ( T->right != nil ) {
					Node* x = T->right;
					while ( x != nil && x->left != nil ) x = x->left;
					T->value = x->value;             // successor's value
					T->right = remove( T->value, T->right );
				} else if ( T->right != nil ) {
					Node* x = T->left;
					while ( x != nil && x->right != nil ) x = x->right;
					T->value = x->value;             // predecessor's value
					T->left = remove( T->value, T->left );
				} else {
					delete T;
					T = nil;
				}
			}
		}
		// later, rebalancing code will be installed here
		return T;
	}
	void display() { display( root ); }
	void display( Node* n ) {
		// in-order traversal with indented display.
		static int depth = 0;
		++ depth;
		if ( n == nil ) return;
		if ( n->right != nil ) display(n->right);
		for( int i = 0; i != depth; ++i ) cout << " ";
		cout << n->value << "-" << n->level << endl;
		if ( n->left != nil ) display(n->left);
		--depth;
	}
	void okay( ) { okay( root ); }

	void okay( Node* T ) {
		// diagnostic code can be installed here
		return;
	}
	}; // Tree
	// ============== below is for testing ===============================
	#ifdef TEST
	int myrand() { // a simple random number generator
	static unsigned long next = 3;
	next = next * 1103515245 + 12345;
	unsigned x = (unsigned) (next/65536) % 32768 ;
	return x % 100;
	}
	int main() {
	// This is a test routine to exercise the list.
		Tree<int> t;
		int n = 0;
		for(;;) {
			int j = myrand();
			cerr << "inserting: " << j << endl;
			t.insert( j );
			cerr<< "Traversing: " << ++n << "\n";
			t.display();
			cerr << "done\n";
			t.okay();
			int k = myrand();
			cerr << "removing: " << k << endl;
			t.remove( k );
			cerr<< "Traversing: " << ++n << "\n";
			t.display();
			cerr << "Done\n";
			t.okay();
		}
	} // main
	#endif
	#endif

