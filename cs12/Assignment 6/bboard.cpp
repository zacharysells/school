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
#include <cstdlib>
#include <vector>
#include "bboard.h"
#include "user.h"
#include "topic.h"
#include "reply.h"
#include <sstream>
#include <fstream>

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

bool Bboard::load_users(const string &userfile)//Read in the usernames and passwords
{
	ifstream data_in(userfile.c_str());
	if(!data_in)
		return false;
	vector<string> name_list;
	vector<string> pass_list;
	string user;
	string pass;
	while(data_in >> user)//Pass in name/passwords one by one
	{
		if(user == "end")
		{
			break;
		}
		name_list.push_back(user);
		
		data_in >> pass;
		pass_list.push_back(pass);
	}
	
	for(unsigned i = 0; i < name_list.size(); i++)//store users into vector user_list
	{
		add_user(name_list.at(i),pass_list.at(i));
	}
	return true;
}

bool Bboard::load_messages(const string &datafile)
{
	//Variables needed for loading messages.
    string s;
    int id;
    unsigned number;
    string type;
    string subject;
    string author;
    stringstream childs;
    string child;
    vector<unsigned> children;
    vector<vector<unsigned> > child_list;
    vector<unsigned> ids;
    string body;
    string bodies;
    unsigned count = 0;
    fstream data_in(datafile.c_str());
    if(!data_in) return false;
    
    data_in >> s;
    data_in >> type;
    
    //Take in one word at a time, analyze it and store information accordingly
    while(data_in >> s)
    {
		bodies = "";
        if(s == ":id:")
            data_in >> id;
            
        else if(s == ":subject:")
        {
            data_in.get();
            getline(data_in,subject);
        }
        else if(s == ":from:")
            data_in >> author;
        
        else if(s == ":children:")
        {
            data_in.get();
            getline(data_in,child);
            childs << child;
            while(childs >> number)
            {
                children.push_back(number);
            }
            child_list.push_back(children);
            ids.push_back(id);
        }
        else if(s == ":body:")
        {
			data_in.get();
			getline(data_in,body);
            while(body != "<end>")
            {
                bodies = bodies + body + "\n";
                getline(data_in,body);
            }
            
            if(type == "<begin_topic>")//If its a topic, push_back as a Dynamic pointer to Topic
			{
				Topic * t = new Topic(author,subject,bodies,id);
				message_list.push_back(t);
			}
		
			else if(type == "<begin_reply>")//If its a reply, push_back as a Dynamic pointer to Reply
			{
				Reply * t = new Reply(author,subject,bodies,id);
				message_list.push_back(t);
			}
			data_in >> type;
		}
		childs.clear();
		children.resize(0);
		count++;
    }
    for(unsigned i = 0; i < ids.size();i++)
    {
		for(unsigned e = 0; e < child_list.at(i).size(); e++)
		{
			message_list[ids[i]-1]->add_child(message_list[child_list[i][e] - 1]);
		}
	}
	return true;
}

//Save changes to data file
bool Bboard::save_messages(const string &datafile)
{
	ofstream data_out(datafile.c_str());
	if(!data_out) return false;
	
	data_out << message_list.size() << endl;
	for(unsigned i = 0; i < message_list.size(); i++)
	{
		data_out << message_list.at(i)->to_formatted_string();
	}
	return true;
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
			//Only accept valid username and password
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
		return;
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
	string body;
	cout << endl;
	cin.ignore();//clear cin buffer.
	//Get subject/body of topic, and creat new dynamic pointer to Topic object.
	cout << "Enter Subject: ";
	getline(cin, message_subj);
	cout << "Enter Body: ";
	getline(cin, body);
	while(!body.empty())
    {
        message_body = message_body + body + "\n";
        body = "";
        getline(cin,body);
    }
	Topic* t = new Topic((current_user->get_username()),(message_subj),(message_body),(message_list.size() + 1));
	message_list.push_back(t);//add message to message_list vector
	cout << "Message Recorded!" << endl << endl;
}

void Bboard::add_reply()
{
	string message_subj;
	string message_body;
	string body;
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
	while(decision > static_cast<int>(message_list.size()) || decision == 0)
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
	message_subj = "Re: " + message_list[decision-1]->get_subject();//Create reply subject
	cout << "Enter Body: ";
	cin.ignore();
	getline(cin, body);
	while(!body.empty())//Accept multiple lines of body.
    {
        message_body = message_body + body + "\n";
        getline(cin,body);
    }
	Reply* r = new Reply((current_user->get_username()),(message_subj),(message_body),(message_list.size() + 1));
	message_list.at(decision-1)->add_child(r);
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
	for(unsigned i = 0; i < message_list.size();i++)
	{
		if(!message_list[i]->is_reply())
			message_list[i]->print();
	}
	//display separator at bottom to match given output.
	cout << "-----------------------------------------------" << endl << endl;
	

}
