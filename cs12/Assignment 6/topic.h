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

	 /* this function will print the Topic as in the previous assignment.
     * Then it invokes print_subtree(1) on each of the messages in child_list 
     * (which are all "first-level" Reply objects).
     */
	virtual void print() const;
	
	/* this writes the contents of the Topic to a string in the following format:
        <begin_topic>
        :id: 4
        :subject: single line
        :from: author
        :children: 5 6 [this line should not be printed if there are no children.]
        :body: multiple lines - line 1
        line 2
        line 3
        <end>
     * line starting with :children: has the id's of all children (See file specs. for details)
     */
    virtual string to_formatted_string() const;

    virtual bool is_reply() const;
};

#endif
