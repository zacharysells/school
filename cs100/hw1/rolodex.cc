#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

string filename = "temp.txt";

ofstream rolodex_write;
ifstream rolodex_read;
ofstream rolodex_temp; //Used for delete function

void insert_new()
{
	rolodex_write.open(filename.c_str(), fstream::app);
	string info_var;	//variable used to collect info about contact
	
	cin.ignore(1000, '\n'); //clear buffer
	system("clear");
	
	cout << "Enter a name for new contact(last then first): ";
	getline(cin, info_var);
	rolodex_write << info_var;
	rolodex_write << " | ";
	
	cout << "Enter an address for the new contact: ";
	getline(cin, info_var);
	rolodex_write << info_var;
	rolodex_write << " | ";
	
	cout << "Enter a phone number for the new contact: ";
	getline(cin, info_var);
	rolodex_write << info_var;
	rolodex_write << " ;" << endl;
	
	rolodex_write.close();
}

bool find(const string &info_var) //Returns true if contact is in rolodex;
{
	bool found = false;
	rolodex_read.open(filename.c_str());
	string dumby_var;
	
	while(rolodex_read >> dumby_var)
	{
		if(dumby_var == info_var)
		{
			found = true;
			
			cout << "Name: ";
		while(dumby_var != "|")
		{
			cout << dumby_var << " ";
			rolodex_read >> dumby_var;
		}
		cout << endl;
		
		cout << "Address: ";
		rolodex_read >> dumby_var;
		while(dumby_var != "|")
		{
			cout << dumby_var << " ";
			rolodex_read >> dumby_var;
		}
		cout << endl;
		
		cout << "Phone Number: ";
		rolodex_read >> dumby_var;
		while(dumby_var != ";")
		{
			cout << dumby_var << " ";
			rolodex_read >> dumby_var;
		}
		cout << endl << "----------------------------------------------"
		<< endl;
		}
		while(dumby_var != ";")
		{
			rolodex_read >> dumby_var;
		}
	}
	rolodex_read.close();
	return found;
}

void delete_contact(const string &info_var)
{
	string dumby_var;
	string test;
	rolodex_read.open(filename.c_str());
	rolodex_temp.open("temp2.txt");
	
	while(rolodex_read >> dumby_var)
	{
		if(dumby_var == info_var)
		{
			while(dumby_var != ";")
			{
				rolodex_read >> dumby_var;
			}
		}
		
		else 
		{
			rolodex_temp << dumby_var;
			getline(rolodex_read, dumby_var);
			rolodex_temp << dumby_var << endl;
		}
	}
	
	cout << "Contact deleted." << endl;
	
	remove(filename.c_str());
	rename("temp2.txt",filename.c_str());
	rolodex_temp.close();
	rolodex_read.close();
	return;
}

void print_rolodex()
{
	rolodex_read.open(filename.c_str());
	string dumby_var;
	system("clear");
	while(rolodex_read >> dumby_var)
	{
		cout << "Name: ";
		while(dumby_var != "|")
		{
			cout << dumby_var << " ";
			rolodex_read >> dumby_var;
		}
		cout << endl;
		
		cout << "Address: ";
		rolodex_read >> dumby_var;
		while(dumby_var != "|")
		{
			cout << dumby_var << " ";
			rolodex_read >> dumby_var;
		}
		cout << endl;
		
		cout << "Phone Number: ";
		rolodex_read >> dumby_var;
		while(dumby_var != ";")
		{
			cout << dumby_var << " ";
			rolodex_read >> dumby_var;
		}
		cout << endl << "----------------------------------------------"
		<< endl;
	}
	rolodex_read.close();
}

int main()
{
	int save_flag = 0;
	char save_curr;
	system("clear");
	char command;
	string info_var;
	
	cout << "Welcome to Rolodex!, press 'i' to start entering\n"
	<< "contacts. To load an already saved rolodex, press 'l'"
	<< endl;
	
	while(command != 'q')
	{
		cout << "Command: ";
		cin >> command;
		switch(command)
		{
			case 'i':
			{
				insert_new();
				break;
			}
			
			case 'f': 
			{
				system("clear");
				cout << "Enter last name of contact: ";
				cin >> info_var;
				if(!find(info_var))
				{
					cout << "Contact does not exist in rolodex." << endl;

				}
				break;
			}
			case 'd':
			{
				system("clear");
				cout << "Enter last name of contact to delete: ";
				cin >> info_var;
				if(!find(info_var))
				{
					cout << "Contact does not exist in rolodex." << endl;
				}
				else delete_contact(info_var);
				break;
			}
			
			case 'p':
			{
				print_rolodex();
				break;
			}
			
			case 'l':
			{
				string temp_filename;
				if(save_flag == 0)
				{
					cout << "Save current rolodex(y or n)? ";
					cin >> save_curr;
					
					if(save_curr == 'y')
					{
						cout << "Enter a name for the rolodex: ";
						cin >> temp_filename;
						rename(filename.c_str(), temp_filename.c_str());
					}
					
					else if(save_curr == 'n')
					{
						remove(filename.c_str());
					}
				}
				
				cout << "Enter rolodex to load: ";
				cin >> filename;
				cout << "Rolodex loaded." << endl;
				break;
			}
			
			case 's':
			{
				save_flag++;
				cout << "Enter a name for the rolodex: ";
				string temp_filename;
				cin >> temp_filename;
				rename(filename.c_str(), temp_filename.c_str());
				filename = temp_filename;
				break;
			}
			
			case 'q':
			{
				
				
				if(save_flag > 0)
				{
					cout << "Exiting Rolodex. Saved rolodex as '" 
					<< filename << "'..." << endl;
				}
				else
				{
					cout << "Enter a name for the rolodex: ";
					string temp_filename;
					cin >> temp_filename;
					rename(filename.c_str(), temp_filename.c_str());
					filename = temp_filename;
				}
			
				break;
			}
		
		}
	}	
		
	return 0;
	
}
