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

#include <iostream>
#include <vector>
#include "MyList.h"

using namespace std;

int main()
{
	MyList list1("zachary");
	MyList list2("za");
	cout << list1.find(list2) << endl;
	
	//list1.print();
	
}
