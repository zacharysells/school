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
	const User * current_user;
	vector<Message*> message_list;
	
	
	void add_user(const string &name, const string & pass);
	
	
	const User * get_user(const string &name, const string &pw)const;
	
	void display() const;
	
	void add_topic();
	
	void add_reply();
	
	
	public:
	Bboard();
	
	Bboard(const string & titl);
	
	~Bboard();
	
	//Setup user list file
	bool load_users(const string &userfile);
	
	//Setup message list vector
	bool load_messages(const string &datafile);
	
	//Save changes to data file
	bool save_messages(const string& datafile);
	
	void login();
	
	void run();
	
};

#endif
	
