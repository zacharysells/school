#include <iostream>
#include <vector>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <climits>
#include <cstdlib>
#include <fstream>
#include <sstream>

using namespace std;

int exec_cmd(vector<string> &cmd_ls)
{	
	//Construct arg list. Set to null if no args are present.
	const char * argv = cmd_ls[1].c_str();
	if(*argv == ' ') argv = NULL;
	
	cout << "ARGV: " << argv << endl;
	
	//Check for input or output redirect
	if(cmd_ls[2] == "<")
	{
		int infile = open(cmd_ls[3].c_str(), O_RDONLY);
		if(infile < 0) return -1;
		if(dup2(infile, 0) < 0) return -1;
	}
	else if(cmd_ls[4] == "<")
	{
		int infile = open(cmd_ls[5].c_str(), O_RDONLY);
		if(infile < 0) return -1;
		if(dup2(infile, 0) < 0) return -1;
	}
	if(cmd_ls[2] == ">")
	{
		int outfile = open(cmd_ls[3].c_str(), O_WRONLY | O_CREAT | O_TRUNC,  S_IREAD | S_IWRITE );
		if(outfile < 0) return -1;
		if(dup2(outfile, 1) < 0) return -1;
	}
	else if(cmd_ls[4] == ">")
	{
		int outfile = open(cmd_ls[5].c_str(), O_WRONLY | O_CREAT | O_TRUNC,  S_IREAD | S_IWRITE );
		if(outfile < 0) return -1;
		if(dup2(outfile, 1) < 0) return -1;
	}
	
	//Execute command then exit child process.
	execlp(cmd_ls[0].c_str(),cmd_ls[0].c_str(), argv, (char*)NULL);
	exit(0);
	
	return 0;
}

//This function takes the command and breaks it up into 
//components that can be read by the exec_cmd() function.
int eval_cmd(const string &command)
{
	if(command == "quit") return 0;
	
	int pid = fork();
	switch(pid)
	{
		case -1: return -1;
		
		case 0:
		{
			vector<string> cmd_ls;
			stringstream ss;
			ss << command;
			string cmd;
			ss >> cmd;
			cmd_ls.push_back(cmd);
			while(ss >> cmd)
			{	
				if(cmd != "<" && cmd != ">")
				{
					if(cmd_ls.size() == 1) cmd_ls.push_back(cmd);
						
					else cmd_ls[1] = cmd_ls[1] + " " + cmd;
				}
				else
				{
					do 
					{
						cmd_ls.push_back(cmd);
					}while(ss >> cmd);
				}
			}
			//Check for bad input
			if(cmd_ls.size() > 1 && (cmd_ls[1] == "<" || cmd_ls[1] == ">"))
			{
				cmd_ls.insert(cmd_ls.begin() + 1," ");
			}
			if(cmd_ls.size() < 6)
			{
				for(int i = 0; i < 6; i++) cmd_ls.push_back(".");
			}
			
			if(exec_cmd(cmd_ls) < 0) return -1;
			
			break;
		}
		
		default: wait(NULL);
	}
	
	return 0;
	
}

int main(int argc, char * argv[])
{
	string command;
	
	while(command != "quit")
	{
		cout << "% ";
		getline(cin, command);
		eval_cmd(command);
	}
	kill(getpid(),9);
}
