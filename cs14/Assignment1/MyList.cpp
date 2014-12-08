/**
 * Course: CS 14 Fall 2012
 *
 * First Name: Zachary
 * Last Name: Sells
 * Username: zsell001
 * email address: zsell001@ucr.edu
 *
 *
 * Assignment: assignment 1
 * Filename : MyList.cpp
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 

#include "MyList.h"
#include <cstdlib>

using namespace std;
MyList::MyList()
:head(NULL)
{}

/**
 * Copy Constructor, deep copy
 */
MyList::MyList(const MyList& str)
{	
	this->head = NULL;
	for(Node * it = str.head; it != NULL ; it = it->next)
	{
		this->push_back(it->value);
	}
}

/**
 * Overloaded constructor, builds list from string& str
 */
MyList::MyList(const string& str)
{
	Node * tmp = new Node(str[0],NULL);
	head = tmp;
	for(unsigned i = 1; i < str.size(); i++)
	{
		this->push_back(str.at(i));
	}
}

/**
 * Overloaded constructor, builds list from string literal str
 */
MyList::MyList(const char* str)
{
	if(str == "")
	{
		head = NULL;
		return;
	}

	Node * tmp = new Node(str[0],NULL);
	head = tmp;
	for(unsigned i = 1; str[i] != '\0'; i++)
	{
		this->push_back(str[i]);
	}
}

/**
 * Overloaded assignment operator, deep copy
 */
MyList& MyList::operator=(const MyList& str)
{
	this->head = NULL;
	for(Node * it = str.head; it != NULL ; it = it->next)
	{
		this->push_back(it->value);
	}
}

/**
 * Destructor
 */
MyList::~MyList()
{
	Node * current = head;
	while(current != NULL)
	{
		Node * next = current->next;
		delete current;
		current = next;
	}
	head = NULL;
}

/**
 * Inserts char value at the front of the list
 */
void MyList::push_front (char value)
{
	if(head == NULL)
	{ 
		this->push_back(value);
		return;
	}
	Node * tmp = new Node(value, head);
	head = tmp;
}

/**
 * Inserts char value at the back of the list
 */
void MyList::push_back(char value)
{
	Node * tmp = new Node(value,NULL);
	if(head == NULL)
	{
		head = tmp;
		return;	
	}
	for(Node * it = head; ;it=it->next)
	{
		if(it->next == NULL)
		{
			it->next = tmp;
			break;
		}
	}
}

/**
 * Removes the first node from MyList
 */
void MyList::pop_front()
{
	if(head == NULL) return;
	Node * tmp = new Node();
	tmp = head->next;
	delete head;
	head = tmp;
}

/**
 *  Removes the last node from the MyList
 */
void MyList::pop_back()
{
	Node * it = head;
	if(head == NULL) return;
	for(; it->next->next != NULL; it = it->next)
	{
		//Iterate through list.
	}
	delete it->next;
	it->next = NULL;
}

/**
 *  This function switches the VALUES of the nodes at index i and j.
 *  NOTE: If i or j is out of bounds this function should just return(void).
 *  NOTE: To simplify your code check to make sure that i is less than j,
 *  and if not, swap the values.
 */
void MyList::swap(int i, int j)
{
	if(j < i)
	{
		int tmp = i;
		i = j;
		j = tmp;
	}
	Node * current_i = new Node;
	Node * current_j = new Node;
	char tmp;
	current_i = head;
	current_j = head;
	for(unsigned e = 0; e < i; e++)
	{
		if(current_i->next == NULL)
		{
			cout << "Error: Out of Bounds" << endl;
			return;
		}
		current_i = current_i->next;
	}
	for(unsigned e = 0; e < j; e++)
	{
		if(current_j->next == NULL)
		{
			cout << "Error: Out of Bounds" << endl;
			return;	
		}
		current_j = current_j->next;
	}
	tmp = current_i->value;
	current_i->value = current_j->value;
	current_j->value = tmp;

	
}

/**
 * Inserts a node with value at position i
 */
void MyList::insert_at_pos(int i, char value)
{
	if(i == 0)
	{
		push_front(value);
		return;
	}
	Node * tmp = new Node(value,NULL);
	Node * it = head;
	
	for(unsigned e = 1; e < i; e++)
	{
		if(it == NULL) return;
		it = it->next;
	}
	tmp->next = it->next;
	it->next = tmp;
}

/**
 *  This function rearranges the list in reverse order.
 */
void MyList::reverse(){
  if(head == NULL)
    return;
  else{
    int loc_size = size();
    for(int i = 0; i < loc_size/2; i++)
      swap(i, loc_size -(i+1));
  }
}

/**
 * Counts the number of nodes in MyList
 */
int MyList::size()const
{
	int count = 0;
	for(Node * it = head; it != NULL; it=it->next)
	{
		count++;
	}
	return count;
}

/**
 * Prints the contents of MyList
 */
void MyList::print()const
{
	for(Node * it = head; it != NULL; it = it->next)
	{
		cout << it->value;
	}
	cout << endl;
}

/**
 *  Finds the the first occurrence of the character c in this list.
 *  Returns -1 if the character is not found.
 */
int MyList::find(char c)const
{
	int count = 0;
	for(Node * it = head; it != NULL; count ++, it = it->next)
	{
		if(it->value == c) return count;
	}
	return -1;
}
	

/**
 * Finds the the first occurrence of the MyList query_str MyList
 * Returns -1 if the character is not found.
 */
int MyList::find(MyList& query_str)const
{	
	int count = 0;
	Node * it_str = query_str.head;//Iterator for passed in parameter.
	for(Node * it_this = head; it_this != NULL; it_this = it_this->next)//Iterate through implicit parameter.
	{
		if(it_this->value == it_str->value)//If a match.
		{
			if(it_str->next == NULL || it_this->next == NULL)
			{
				if(it_this->next == NULL && it_str->next != NULL) return -1;//If one list has reached the end while the other hasnt, return -1;
				if(it_this->next != NULL && it_str->next == NULL) return -1;	
				return count;
			}
			it_str = it_str->next;//Move string paramter iterator.
			continue;
		}
		else if(it_this->next == NULL) return -1;//End of strint parameter and no match is found.
		else count++;
	}
	return count;
}

/**
 * Removes all instances of the '0' char.
 * Used to test, not part of assn1 specs
 */
void MyList::remove_zeroes() 
{
}

/**
 * Function concatenates str to this
 */
MyList MyList::operator+(const MyList& str)
{
	Node * it = head;
	for(; it->next != NULL; it = it->next)
	{}
	for(Node * it2 = str.head; it2 != NULL; it2 = it2->next)
	{
		this->push_back(it2->value);
	}
	return *this;
}

char& MyList::operator[](const int i)
{
	Node * it = head;
	for(int e = 0; e < i; e++)
	{

		it = it->next;
	}
	return it->value;
}
