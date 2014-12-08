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

#ifndef MESSAGE_H
#define MESSAGE_H
#include <string>

using namespace std;

  class Message  // abstract base class
  {
    protected:  // allow access to these members by objects of derived classes
      string author;
      string subject;
      string body;
      unsigned id;

    public:

      //default constructor
      Message();

      //Constructor with parameters
      Message(const string &athr, const string &sbjct, const string &body, unsigned id);

      //print the Topic in the required format - see output specs (different from previos assignment!!)
      virtual void print() const = 0; // NOTE NAME CHANGE from previous assignment!

      // returns true if the object is reply.
      virtual bool is_reply() const = 0;
      
      //returns the subject string.
      string get_subject() const;

      virtual ~Message();

  };
#endif
