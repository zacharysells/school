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
#include <vector>
#include "bboard.h"
#include "message.h"
#include "user.h"
using namespace std;

int main()
{
	Bboard myboard("Zack's Amazing Bulletin Board");
	cout << endl << endl << endl;
	myboard.setup();
	myboard.login();
	myboard.run();
}
