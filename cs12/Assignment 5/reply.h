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

#ifndef REPLY_H
#define REPLY_H
#include <string>
#include "message.h"

using namespace std;

class Reply: public Message
{	
    private:
    unsigned parent_id;

    public:
    //default constructor
    Reply();
    
    /*  Constructor with parameters.
        similar to Message's constructor except:
        The subject should be initialized to "Re: <sbjct>" not <sbjct>.
        The parent_id should be initialized.
    */

    Reply(const string& athr, const string& sbjct, const string& body, unsigned id, unsigned parent_id);

    //print the reply in the given format - see output specs for details
    virtual void print() const;

    virtual bool is_reply() const;
      
    //accessor for the topic's id     
    unsigned get_parent_id() const;
};
#endif
