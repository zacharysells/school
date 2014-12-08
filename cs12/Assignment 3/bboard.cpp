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
#include <cstdlib>
#include <vector>
#include "bboard.h"
#include "user.h"

using namespace std;

Bboard::Bboard()//Default constructor
:title(""),user_list(),current_user(User()),message_list()
{}

Bboard::Bboard(const string &titl)//Paramaterized Constructor
:title(titl),user_list(),current_user(User()),message_list()
{}

void Bboard::setup()
{
	vector<string> name_list;
	vector<string> pass_list;
	string user;
	string pass;
	while(cin >> user)//Read in the usernames and passwords
	{
		if(user == "end")
		{
			break;
		}
		name_list.push_back(user);
		
		cin >> pass;
		pass_list.push_back(pass);
	}
	
	for(int i = 0; i < name_list.size(); i++)//store users into vector user_list
	{
		add_user(name_list.at(i),pass_list.at(i));
	}
}

void Bboard::login()
{
	string input_name;
	string input_pass;
	cout << "Welcome to " << title << endl;//Login screen.
	cout << "Enter your username (\"Q\" or \"q\" to quit): ";
	cin >> input_name;
	while (input_name != "Q" && input_name != "q")
	{
		cout << "Enter your password: ";
		cin >> input_pass;
	
		if(user_exists(input_name,input_pass))//Verify login credentials
		{
			User x(input_name,input_pass);
			current_user = x;//Set current user.
			cout << "Welome back " << input_name << "!" << endl << endl;
			return;
		}
		else
		{
			cout << "Invalid username or Password!" << endl << endl;
			cout << "Enter your username (\"Q\" or \"q\" to quit): ";
			cin >> input_name;
		}
	}
	cout << "Bye!";//Exit program if user enters 'q' or 'Q'.
	exit(0);
}
	
void Bboard::run()
{
	string run_decision;
	
	run://Menu screen
	cout << "\nMenu" << endl;
	cout << "  -  Display Messages ('D' or 'd')" << endl;
	cout << "  -  Add New Message ('N' or 'n')" << endl;
	cout << "  -  Quit ('Q' or 'q')" << endl;
	cout << "Choose an action: ";
	cin >> run_decision;
	
	if (run_decision == "D" || run_decision == "d")
	{
		display();
		goto run;//return to menu screen
	}
	
	else if (run_decision == "N" || run_decision == "n")
	{
		add_message();
		goto run;//return to menu screen
	}
	
	else if (run_decision == "Q" || run_decision == "q")
	{
		cout << "Bye!";//only exit the program when user enters 'q' or 'Q'
		exit(0);
	}
	
	else
	{
		goto run;//Repeat menu screen if user enters invalid input.
	}
	
	
}

//adds user to user_list vector.
void Bboard::add_user(const string &name, const string &pass)
{
	User x(name,pass);
	user_list.push_back(x);
}

//return true if user exists, else false.
bool Bboard::user_exists(const string &name, const string &pass)
{
	for(int i = 0; i < user_list.size(); i++)
	{
		if(user_list.at(i).get_username() == name && 
		user_list.at(i).get_password() == pass)
		{
			return true;
		}
	}
	return false;
}

void Bboard::add_message()
{
	string message_subj;
	string message_body;
	cout << endl;
	cin.ignore();//clear cin buffer.
	cout << "Enter Subject: ";
	getline(cin, message_subj);
	cout << "Enter Body: ";
	getline(cin, message_body);
	Message x(current_user.get_username(),message_subj,message_body);
	message_list.push_back(x);//add message to message_list vector
	cout << "Message Recorded!" << endl;
}

void Bboard::display() const
{
	if(message_list.size() == 0)
	{
		cout << "Nothing to Display." << endl;
		return;
	}

	//display separator at top to match given output.
	cout << "\n-----------------------------------------------" << endl;
	
	//go through message_list vector and output all messages.
	int numb_messages = 1;
	for(int i = 0; i < message_list.size(); i ++)
	{
		cout << "Message #" << numb_messages << ": ";
		message_list.at(i).display();
		numb_messages++;
	}
}
