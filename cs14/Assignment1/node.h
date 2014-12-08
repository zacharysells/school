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

#ifndef __NODE_H_
#define __NODE_H_

class Node {
  friend class MyList;
private:
  Node* next;
  char value;
  
 public:
  //Constructor
  Node();
  Node(char val, Node * nexxt);
};

#endif /* NODE_H_ */

