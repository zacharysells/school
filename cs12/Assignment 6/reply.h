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

#ifndef REPLY_H
#define REPLY_H
#include <string>
#include "message.h"

using namespace std;

class Reply: public Message
{	

    public:
    //default constructor
    Reply();
    
    /*  Constructor with parameters.
        similar to Message's constructor except:
        The subject should be initialized to "Re: <sbjct>" not <sbjct>.
        The parent_id should be initialized.
    */
    Reply(const string& athr, const string& sbjct, const string& body, unsigned id);

    /* print the reply to screen in the given format - see output specs for details
    * Then it invokes print_subtree(n) on each of the messages in child_list 
    * (we leave it to you to figure out what n is!)
    */
    virtual void print() const;

    virtual bool is_reply() const;
      
    /* This function is responsible for printing the selected Reply and all of its subtree recursively
     * After printing the Reply with the given indentation and format (see output details).
     * it calls the print_subtree function of all of the Replies in its child_list(see message)
     * with incremented indentation value. 
     *
     * Note: Each indentation value represent 2 spaces. e.g. if indentation=1 the reply should be indented
     * 2 spaces, if it's 2, indent by 4 spaces. 
     */       
    virtual void print_subtree(unsigned indentation) const;
    
    /* this writes the contents of the Reply to a string in the following format:
       <begin_reply>
       :id: 4
       :subject: single line
       :from: author
       :children: 5 6 [this line should not be printed if there are no children.]
       :body: multiple lines
       2nd line
       <end>
    * the line starting with :children: has the list of id's of all children (See file specs. for details)
    */
    virtual string to_formatted_string() const;
    
    
    private:
    //Helper function to help print body with correct format
	void format(unsigned indentation) const;
	
	//Helper function for printing body
	unsigned numb_chars_inbody(char c) const;
    
};
#endif
