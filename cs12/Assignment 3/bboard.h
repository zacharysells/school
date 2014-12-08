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
#ifndef _BBOARD_H_
#define _BBOARD_H_

#include <vector>
#include <string>
#include "message.h"
#include "user.h"

class Bboard
{
	private: 
	string title;
	vector<User> user_list;
	User current_user;
	vector<Message> message_list;
	
	
	void add_user(const string &name, const string & pass);
	
	bool user_exists(const string &name, const string &pass);
	
	//User get_user(const string &name) const;
	
	void display() const;
	
	void add_message();
	
	
	public:
	Bboard();
	
	Bboard(const string & titl);
	
	void setup();
	
	void login();
	
	void run();
	
};

#endif
	
