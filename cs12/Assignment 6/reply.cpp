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
#include "reply.h"
#include "message.h"
#include <iostream>
#include <sstream>

using namespace std;

Reply::Reply()
:Message()
{}

Reply::Reply(const string& athr,const string& sbjct, const string & bdy, unsigned iid)
:Message(athr,sbjct,bdy,iid)
{}

void Reply::print() const
{
	cout << "\n  Message #" << id << ": " << subject << endl;
	cout << "  from " << author << ": " << body << endl;
	dynamic_cast<Reply *>(child_list.at(0))->print_subtree(1);
}

//Print all of the children within a topic/reply using recursion
void Reply::print_subtree(unsigned indentation) const
{
	cout << endl;
	for(unsigned i = 0; i < indentation; i++)
		cout << "  ";
	cout << "Message #" << id << ": " << subject << endl;
	for(unsigned i = 0; i < indentation; i++)
		cout << "  ";
	cout << "from " << author << ": ";
	this->format(indentation);//Format body to match output specs
	indentation++;
	if(child_list.size() == 0) return;
	dynamic_cast<Reply *>(child_list.at(child_list.size()-1))->print_subtree(indentation);
	
}
//Return true if implicit parameter is a reply
bool Reply::is_reply() const
{
	return (subject.substr(0,3) == "Re:");
}

//Correctly format a message to a string
string Reply::to_formatted_string() const
{
    string s;
    stringstream final;
    final << "<begin_reply>" << endl;
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

//Helper function to print body in correct format
void Reply::format(unsigned indentation) const
{
	string s = body;
	cout << body.substr(0,s.find('\n')) << endl;
	s = s.substr(s.find('\n')+1);
	for(unsigned i = 0; i < this->numb_chars_inbody('\n')-1;i++)
	{
		for(unsigned i = 0; i < indentation; i ++)
			cout << "  ";
		cout << s.substr(0,s.find('\n')+1);//Stop at newline characters
		s = s.substr(s.find('\n')+1);
	}
}

//Helper function used in 'format' function.
unsigned Reply::numb_chars_inbody(char c) const
{
	unsigned count = 0;
	for(unsigned i = 0; i < body.size(); i++)
	{
		if(body.at(i) == c) count ++;
	}
	return count;
}
