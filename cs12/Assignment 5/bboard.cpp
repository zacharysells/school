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
#include <cstdlib>
#include <vector>
#include "bboard.h"
#include "user.h"
#include "topic.h"
#include "reply.h"

using namespace std;

Bboard::Bboard()//Default constructor
:title(""),user_list(),current_user(NULL),message_list()
{}

Bboard::Bboard(const string &titl)//Paramaterized Constructor
:title(titl),user_list(),current_user(NULL),message_list()
{}

Bboard::~Bboard()//Destructor
{
	for(unsigned i = 0; i < message_list.size(); i++)
	{
		delete message_list[i];
	}
}

void Bboard::setup()//Read in the usernames and passwords
{
	vector<string> name_list;
	vector<string> pass_list;
	string user;
	string pass;
	while(cin >> user)
	{
		if(user == "end")
		{
			break;
		}
		name_list.push_back(user);
		
		cin >> pass;
		pass_list.push_back(pass);
	}
	
	for(unsigned i = 0; i < name_list.size(); i++)//store users into vector user_list
	{
		add_user(name_list.at(i),pass_list.at(i));
	}
}

void Bboard::login()//Login user
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
	
		current_user = get_user(input_name,input_pass);
		if(current_user != NULL)
		{
			cout << "\nWelome back " << input_name << "!" << endl << endl;
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
	cout << "Menu" << endl;
	cout << "  -  Display Messages ('D' or 'd')" << endl;
	cout << "  -  Add New Topic ('N' or 'n')" << endl;
	cout << "  -  Add Reply to a Topic ('R' or 'r')" << endl;
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
		add_topic();
		goto run;//return to menu screen
	}
	
	else if (run_decision == "R" || run_decision == "r")
	{
		add_reply();
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

//If user is found, sets that user to current_user. Otherwise, sets current user to NULL
const User* Bboard::get_user(const string &name, const string &pw) const 
{
	for(unsigned i = 0; i < user_list.size(); i++)
	{
		if(user_list.at(i).get_username() == name && 
		user_list.at(i).get_password() == pw)
			return &user_list[i];
		
	}
	return NULL;
}
		

void Bboard::add_topic()
{
	string message_subj;
	string message_body;
	cout << endl;
	cin.ignore();//clear cin buffer.
	//Get subject/body of topic, and creat new dynamic pointer to Topic object.
	cout << "Enter Subject: ";
	getline(cin, message_subj);
	cout << "Enter Body: ";
	getline(cin, message_body);
	Topic* t = new Topic((current_user->get_username()),(message_subj),(message_body),(message_list.size() + 1));
	message_list.push_back(t);//add message to message_list vector
	cout << "Message Recorded!" << endl << endl;
}

void Bboard::add_reply()
{
	string message_subj;
	string message_body;
	int decision = 0;
	cin.ignore();//clear cin buffer.
	//Get subject/body of reply and create a pointer to a new dynamic Topic object.
	cout << "\nEnter Topic ID (-1 for Menu): ";
	cin >> decision;
	if(decision == -1)
	{
		cout << endl;
		return;
	}
	//If invalid Topic Id is chosen, program will enter loop until a valid ID is chosen.
	while(decision > static_cast<int>(message_list.size()) || decision == 0 || message_list[decision-1]->is_reply())
	{
		cout << "Invalid Topic ID!!" << endl;
		cout << "\nEnter Topic ID (-1 for Menu): ";
		cin >> decision;
		if(decision == -1)
		{
			cout << endl;
			return;
		}
	}
	message_subj = "Re: " + message_list[decision-1]->get_subject();
	cin.ignore();
	cout << "Enter Body: ";
	getline(cin, message_body);
	Reply* r = new Reply((current_user->get_username()),(message_subj),(message_body),(message_list.size() + 1),decision);
	message_list.push_back(r);
	cout << "Message Recorded!" << endl << endl;
}

void Bboard::display() const
{
	if(message_list.size() == 0)
	{
		cout << "\nNothing to Display." << endl << endl;
		return;
	}
	cout << endl;
	//go through message_list vector and output all messages.
	for(unsigned i = 0; i < message_list.size(); i++)
	{
		if(!(message_list[i]->is_reply()))
		{
			message_list[i]->print();
			for(unsigned e = 0; e < message_list.size(); e++)
			{
				if(message_list[e]->is_reply())
				{
					if((dynamic_cast<Reply *>(message_list[e]))->get_parent_id() == i+1)
						message_list[e]->print();
				}
			}
		}
	}
	
	//display separator at bottom to match given output.
	cout << "-----------------------------------------------" << endl << endl;
	

}
