// ********************************************************
// Header file TreeException.h for the ADT Binary Search Tree.
// ********************************************************
#include <string>
using namespace std;

#ifndef TREEEXCEPTION_H_
#define TREEEXCEPTION_H_

class TreeException : public exception
{
   string msg;
public:
   TreeException(const string & message =""): msg(message) { }

   const char* what() { return msg.c_str(); }
   ~TreeException() throw() {}

}; // end TreeException

#endif /* TREEEXCEPTION_H_ */
