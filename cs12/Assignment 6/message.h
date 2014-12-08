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
// Assignment: assn6
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//
// =================================================================

#ifndef MESSAGE_H
#define MESSAGE_H
#include <string>
#include <vector>

using namespace std;

  class Message  // abstract base class
  {
    protected:  // allow access to these members by objects of derived classes
      string author;
      string subject;
      string body;
      unsigned id;
      vector<Message*> child_list;

    public:

      //default constructor
      Message();

      //Constructor with parameters
      Message(const string &athr, const string &sbjct, const string &body, unsigned id);

      //print the Topic in the required format
      virtual void print() const = 0; // 

      // returns true if the object is reply.
      virtual bool is_reply() const = 0;
      
      //returns the subject string.
      string get_subject() const;
      
      //return id of message object.
      unsigned get_id() const;
      
      //Convert message to a string with correct formatting
      virtual string to_formatted_string() const = 0;
      
      // Adds a pointer to the child to child_list. 
      void add_child(Message* child);

      virtual ~Message();

  };
#endif
