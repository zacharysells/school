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
#include "user.h"
#include <string>

using namespace std;

User::User()
:username(""),password("")
{}

User::User(const string& uname, const string& pass)
:username(uname),password(pass)
{}

string User::get_username() const
{
    return username;
}

string User::get_password() const
{
	return password;
}

bool User::check(const string& uname, const string& pass) const
{
    if(username == "")
        return false;
        
    else if(username == uname && password == pass)
        return true;
        
    return false;
}

void User::set_password(const string& newpass)
{
    password = newpass;
}
