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
#include <iostream>
#include <vector>
#include "bboard.h"
#include "message.h"
#include "user.h"
using namespace std;


int main(int argc, char** argv)
  {
    // check commandline arguments (see Chapter 9, section 9.5 of the text for explanations and examples)   
    if(argc != 3){
        cout << "ERROR: Invalid program call."<< endl
        << "Usage: <program_name> userfile datafile"<< endl;
        return -1;
    }
    string userfile(argv[1]);
    string datafile(argv[2]);
   
    Bboard bb("CS12 Bulletin Board");
   
    // load users from file
    if( !bb.load_users(userfile) )
    {
     cout << "ERROR: Cannot load users from "<<userfile<< endl;
     return -1;
    }
   
    // load messages   
    if( !bb.load_messages(datafile) )
    {
     cout << "ERROR: Cannot load messages from "<< datafile<< endl;
     return -1;
    }
   
    bb.login();
    bb.run();

    // save messages
    if( !bb.save_messages(datafile) )
    {
     cout << "ERROR: Cannot save messages to "<<datafile<< endl;
     return -1;
    }
    return 0;
  } 

