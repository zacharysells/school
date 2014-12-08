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
#include <iostream>
#include "user.h"
#include "message.h"

using namespace std;

//Constructors
Message::Message()
:author(""),subject(""),body(""),id(0)
{}

Message::Message(const string& athr, const string& sbjct, const string& bdy,unsigned iid)
:author(athr),subject(sbjct),body(bdy),id(iid)
{}

//Member Functions
void Message::print() const
{	
}

bool Message::is_reply() const
{
	return (subject.substr(0,3) == "Re:");
}

string Message::get_subject() const
{
	return subject;
}

Message::~Message()
{}
