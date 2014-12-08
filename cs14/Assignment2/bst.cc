// -*- bst.cc -*-
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
#include <vector>
using namespace std;
//this macro (max) makes the computing of height() easier
#define max (a, b) ((a > b) ? (a):(b))
#define nil 0

// #define Value int // restore for testing.
template < typename Value >

class Tree {
	class Node { // binary tree node
		public:
			Node* left;
			Node* right;
			Value value;
			int level; // for Andersson trees
			Node( const Value v = Value(), int lev = 1 )
				: value(v), level(lev), left(nil), right(nil)
			{}
			Value& content() { return value; }
			bool isExternal() { return left == nil && right == nil; }
			bool isInternal() { return ! isExternal(); }
			int height() 
			{
				if(this == nil) return -1;
				int left_height = this->left->height();
				int right_height = this->right->height();
				if(right_height > left_height) return right_height + 1;
				else return left_height + 1;
			}
			int size() 
			{
				if(this == nil) return 0;
				else 
				{
					return(1 + this->left->size() + this->right->size());
				}
			}
	}; // Node


	// const Node* nil; // later nil will point to a sentinel node.
	Node* root;
	int count;

	public:
	
	Node * get_root()
	{
		return root;
	}
	
	
	int size() {
		this->root->size();
	}

	bool empty() { return size() == 0; }

		void print_node( const Node* n ) {
			cout << n->value << endl;
		}

		bool search ( Node* N, Value x )
		{
			vector<Node *> stack;
			stack.push_back(N);
			while(stack.size() != 0)
			{
				Node * current = stack.at(stack.size() - 1);
				if(stack.at(stack.size() - 1)->value == x) return true;
				stack.pop_back();
				
				if(current->right != NULL) stack.push_back(current->right);
				
				if(current->left != NULL) stack.push_back(current->left);
			}
			return false;
			
		}//end search()

//--------------------------------------------------------------------------------------------------------------------------------


		void preorder(Node* N)const 
		{
			vector<Node *> stack;
			stack.push_back(N);
			while(stack.size() != 0)
			{
				Node * current = stack.at(stack.size() - 1);
				cout << stack.at(stack.size() - 1)->value << endl;
				stack.pop_back();
				
				if(current->right != NULL) stack.push_back(current->right);
				
				if(current->left != NULL) stack.push_back(current->left);
			}
			
		}//end preorder traversal
		
//------------------------------------------------------------------------------------
		
		void postorder(Node* N)const 
		{
			if( root == NULL) return;
			vector<Node *> stack;
			stack.push_back(N);
			Node * prev = NULL;
			while(stack.size() != 0)
			{
				Node * current = stack.at(stack.size() - 1);
				if(prev == NULL || prev->left == current || prev->right == current)
				{
					if(current->left != NULL) stack.push_back(current->left);
					else if(current->right != NULL) stack.push_back(current->right);
				}
				else if(current->left == prev)
				{
					if(current->right != NULL) stack.push_back(current->right);
				}
				else
				{
					cout << current->value << endl;
					stack.pop_back();
				}
					prev = current;
			}
						
		}//end postorder traversal
		
//------------------------------------------------------------------------------------------
		
		void inorder(Node* N)const 
		{
			vector<Node *> stack;
			Node * current = N;
			while(true)
			{
				if(current != NULL)
				{
					stack.push_back(current);
					current = current->left;
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
						cout << current->value << endl;
						current = current->right;
					}	
				}
			
			}
		}//end inorder()
		
//---------------------------------------------------------------------------


		Value& operator[] (int n)
		{
			vector<Node *> stack;
			vector<Node *> final;
			Node * current = this->root;
			while(true)
			{
				if(current != NULL)
				{
					stack.push_back(current);
					current = current->left;
				}
				else
				{
					if(stack.size() == 0)
					{
						return final.at(n)->value;
					}
				else
					{
						current = stack.at(stack.size() -1);
						stack.pop_back();
						final.push_back(current);
						current = current->right;
					}	
				}
			
			}

		}//end operator[]()
		
		Tree() : count(0), root(nil) {}
		void insert( Value X ) { root = insert( X, root ); }
		Node* insert( Value X, Node* T ) {
			// The normal binary-tree insertion procedure ...
			if ( T == nil ) {
				T = new Node( X ); // the only place that T gets updated.
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
		void remove( Value X ) { root = remove( X, root ); }
		Node* remove( Value X, Node* T ) {
			// The normal binary-tree removal procedure ...
			// Weiss's code is faster but way more intricate.
			if ( T != nil ) {
				if ( X > T->value ) {
					T->right = remove( X, T->right );
				} else if ( X < T->value ) {
					T->left = remove( X, T->left );
				} else { // X == T->value
					if ( T->right != nil ) {
						Node* x = T->right;
						while ( x != nil && x->left != nil ) x = x->left;
						T->value = x->value; // successor's value
						T->right = remove( T->value, T->right );
					} else if ( T->right != nil ) {
						Node* x = T->left;
						while ( x != nil && x->right != nil ) x = x->right;
						T->value = x->value; // predecessor's value
						T->left = remove( T->value, T->left );
					} else { // *T is external
						delete T;
						T = nil; // the only updating of T
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
		int n = 5;
		for(int i = 0; i < 5; i++) {
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
		
		cout << "\n Tree size: "<< t.get_root()->size();
		cout << "\n Tree height: "<< t.get_root()->height();
		
		cout << "\n Searching for 73: "<< endl;

		if (t.search(t.get_root(), 73))
			cout << "\n Value found";
		else
			cout << "\n Value not found";

		//print inorder traversal of the tree
		cout << "\n Tree inorder Traversal: \n";
		t.inorder(t.get_root());
		cout << endl;
		
		//print preorder traversal of the tree
		cout << "\n Tree preorder Traversal: \n";
		t.preorder(t.get_root());

		// print postorder traversal of the tree
		cout << "\n Tree postorder Traversal: \n";
		t.postorder(t.get_root());

		//Finally, inorder array style printing of the tree
		cout << "\n Print array style inorder Traversal of the tree: \n";
		for(int i = 0; i < 5; i++)
			cout << t[i] << " ";
		
		return 0;

	} // main
#endif
#endif
