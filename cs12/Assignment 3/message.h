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
// Assignment: assn3
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//
// =================================================================
#ifndef _MESSAGE_H_
#define _MESSAGE_H_

#include <iostream>

using namespace std;

  class Message
  {
    private:

      string author;
      string subject;
      string body;

    public:

      //default constructor
      Message();

      //Constructor with parameters
      Message(const string& athr, const string& sbjct, const string& body);


      //displays the message in the given format. See output specs.
      void display() const;
  };


#endif
  //end inc guards
