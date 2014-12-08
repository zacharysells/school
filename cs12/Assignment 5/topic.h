// Course: CS 12 <quarter & year>
//
// First Name: Zachary 
// Last Name: Sells
// Course username: zsell001
// email address: zsell001@ucr.edu
//
// Lecture Section: 001
// Lab Section: 025
// TA: Mirebrahim, Seyed Hamid
//
// Assignment: assn5
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//
// =================================================================

#ifndef TOPIC_H
#define TOPIC_H
#include "message.h"

using namespace std;

  class Topic: public Message
  {                            // no new member variables
    public:

      //default constructor
      Topic();

      //Constructor with parameters
      Topic(const string &athr, const string &sbjct, const string &bdy, unsigned iid);

      //print the reply in the given format. See output specs. 
      //Similar to previous assignment, but you now have to include the id in the output.
      virtual void print() const;

      virtual bool is_reply() const;
  };

#endif
