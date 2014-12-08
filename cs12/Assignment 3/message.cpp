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
// Assignment: assn3
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//
// =================================================================
#include <iostream>
#include "user.h"
#include "message.h"

using namespace std;


Message::Message()
:author(""),subject(""),body("")
{}

Message::Message(const string& athr, const string& sbjct, const string& bdy)
:author(athr),subject(sbjct),body(bdy)
{}

void Message::display() const
{	
	
    cout << subject << endl;
    cout << "from " << author << ": " << body << endl;
    cout << "-----------------------------------------------" << endl;
}
