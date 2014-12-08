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
#include "topic.h"
#include "message.h"
#include <iostream>

Topic::Topic()
:Message()
{}

Topic::Topic(const string& athr, const string& sbjct, const string& bdy, unsigned iid)
:Message(athr,sbjct,bdy,iid)
{}

void Topic::print() const
{
	cout << "-----------------------------------------------" << endl;
	cout << "Message #" << id << ": " << subject << endl;
	cout << "from " << author << ": " << body << endl;
}

bool Topic::is_reply() const
{
	return (subject.substr(0,3) == "Re:");
}
	
