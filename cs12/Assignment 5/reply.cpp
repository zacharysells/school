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
#include "reply.h"
#include "message.h"
#include <iostream>

using namespace std;

Reply::Reply()
:Message(),parent_id(0)
{}

Reply::Reply(const string& athr,const string& sbjct, const string & bdy, unsigned iid, unsigned parnt_id)
:Message(athr,sbjct,bdy,iid),parent_id(parnt_id)
{}

void Reply::print() const
{
	cout << "\n\tMessage #" << id << ": " << subject << endl;
	cout << "\tfrom " << author << ": " << body << endl;
}

bool Reply::is_reply() const
{
	return (subject.substr(0,3) == "Re:");
}

unsigned Reply::get_parent_id() const
{
	return parent_id;
}
