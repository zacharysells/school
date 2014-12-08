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

#include "node.h"
#include <iostream>

using namespace std;

#ifndef MYLIST_H_
#define MYLIST_H_

class MyList{
 private:
  Node* head;
 public:
  MyList();
  MyList(const MyList& str);
  MyList(const string& str);
  MyList(const char* str);
  ~MyList();
  
  /* Mutators */
  void push_front(char value);
  void push_back(char value);
  void pop_front();
  void pop_back();
  void swap(int i, int j);
  void insert_at_pos(int i, char value);
  void reverse();
  void remove_zeroes();
  
  /* Accessors */
  int  size()const;
  void print()const;
  int  find(char value)const;
  int  find(MyList& query_str)const;
  
  /* Operator overloaders */
  MyList& operator=(const MyList& str);
  char& operator[](const int i);
  MyList operator+(const MyList& str);
};

#endif /* MYLIST_H_ */

