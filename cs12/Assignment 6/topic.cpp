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
#include "topic.h"
#include "message.h"
#include <iostream>
#include <sstream>
#include "reply.h"

Topic::Topic()
:Message()
{}

Topic::Topic(const string& athr, const string& sbjct, const string& bdy, unsigned iid)
:Message(athr,sbjct,bdy,iid)
{}

//Print a topic and all of its children
void Topic::print() const
{
	cout << "-----------------------------------------------" << endl;
	cout << "Message #" << id << ": " << subject << endl;
	cout << "from " << author << ": " << body;
	
	for(unsigned i = 0; i < child_list.size();i++)
	{
		dynamic_cast<Reply *>(child_list.at(i))->print_subtree(1);
	}
}

bool Topic::is_reply() const
{
	return (subject.substr(0,3) == "Re:");
}

string Topic::to_formatted_string() const
{
    string s;
    stringstream final;
    final << "<begin_topic>" << endl;
    final << ":id: " << id << endl;
    final << ":subject: " << subject << endl;
    final << ":from: " << author << endl;
    if(child_list.size() != 0)
    {
        final << ":children: ";
        for(unsigned i = 0; i < child_list.size();i++)
        {
            final <<child_list.at(i)->get_id() << " ";
        }
        final << endl;
    }
    final << ":body: " << body;
    final << "<end>" << endl;
    return final.str();
}
	
