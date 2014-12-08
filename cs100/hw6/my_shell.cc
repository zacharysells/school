#include <iostream>
#include <vector>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <cstring>

using namespace std;

void sigint_handler(int x)
{
	return;
}

string full_path(const string &cmd)
{
	struct stat buffer;
	const char * path = getenv("PATH");
	int infile, outfile;
	string cmd_path;
	int e = 0;
	for(int i = 0; path[i]; ++i)
	{
		if(path[i] == ':')
		{
			for(; e < i; e++)
			{
				cmd_path.push_back(path[e]);
			}
			++e;
			
			if(stat((cmd_path + "/" + cmd).c_str(), &buffer) == 0)
				return cmd_path + "/" + cmd;
			cmd_path.clear();
		}
	}
	return "NULL";
}

void open_infile(const char * file)
{
	int infile = open(file, O_RDONLY);
	if(infile < 0)
	{
		cerr << "ERROR: cannot open infile" << endl;
		exit(1);
	}
	if(dup2(infile, 0) < 0)
	{
		cerr << "ERROR: dup2 failed!" << endl;
		exit(1);
	}
}

void open_outfile(const char * file)
{
	int outfile = open(file, O_WRONLY | O_CREAT | O_TRUNC, S_IREAD | S_IWRITE );
	if(outfile < 0)
	{
		cerr << "ERROR: cannot open outfile" << endl;
		exit(1);
	}
	if(dup2(outfile, 1) < 0)
	{
		cerr << "ERROR: dup2 failed!" << endl;
		exit(1);
	}
}

const char ** vec_to_char(vector<string> &argv, const string &cmd)
{
	const char **args = new const char* [argv.size()+2];
	args [0] = cmd.c_str();
	for (int j = 0;  j < argv.size();  ++j)
		args [j+1] = argv[j].c_str();

	args [argv.size()+1] = NULL;
	return args;
}

int exec_cmd(const string &command);

void handle_pipe(const string &cmd, const string &cmdPostPipe, vector<string> argv)
{
	int pipeArray[2];
	
	if(pipe(pipeArray) == -1)
	{
		cerr << "ERROR: Pipe failed..exiting" <<endl;
		exit(1);
	}	
	int pid = fork();	
	switch(pid)
	{	
		case -1: cerr << "ERROR: Fork failed...exiting" << endl; break;

		case 0:
		{
			//Child
			close(pipeArray[1]);
			dup2(pipeArray[0],0);
			close(pipeArray[0]);
			exec_cmd(cmdPostPipe);
		}
				
		default:
		{
			//Parent
			close(pipeArray[0]);
			dup2(pipeArray[1], 1);
			close(pipeArray[1]);
			execv(cmd.c_str(), (char**)vec_to_char(argv, cmd));
		}
	}
}

void handle_daemon()
{
	int pid = fork();
			
	switch(pid)
	{
		case -1: cout << "Fork failed...exiting"; exit(1);
		
		case 0: 
		{
			if(setsid() < 0)
			{
				cout << "setsid() failed...exiting" << endl;
				exit(0);
			}
			close(STDOUT_FILENO);
			close(STDERR_FILENO);
			return;
		}
		
		default: exit(0);
	}
}

int exec_cmd(const string &command)
{	
	if(command.at(command.length() - 1) == '&')	handle_daemon();
	stringstream ss(command);
	string cmd;
	vector<string> argv;
	ss >> cmd; //First parameter is executable
	cmd = full_path(cmd);
	if(cmd == "NULL")
	{
		cout << "Error, no such executable found in PATH" << endl;
		return -1;
	}
	
	string temp;
	while(ss >> temp)
	{
		if(temp == "<")//Infile is specified. Open it.
		{
			ss >> temp;
			open_infile(temp.c_str());
		}
		
		else if(temp == ">")//Outfile is specified. Open it.
		{
			ss >> temp;
			open_outfile(temp.c_str());
		}
		
		else if(temp == "&")//Exec command in background
		{
			continue;	
		}
		
		else if(temp == "|")//Pipe has been specified
		{
			string cmdPostPipe;
			ss >> cmdPostPipe;
			string buf;
			while(ss >> buf)
			{
				cmdPostPipe = cmdPostPipe + " " + buf;
			}
			handle_pipe(cmd, cmdPostPipe, argv);
		}
		
		else
		{
			argv.push_back(temp);
		}	
	}
	execv(cmd.c_str(), (char**)vec_to_char(argv, cmd));
}

int eval_cmd(const string &command)
{
	if(command == "quit") return 0;
	if(command == "") return 0;
	
	int pid = fork();
	switch(pid)
	{
		case -1: cout << "Fork failed...exiting"; return -1;
		
		case 0: exec_cmd(command);
		
		default: wait(NULL);
	}
	
	return 0;
	
}

int main(int argc, char * argv[])
{
	string command;
	if(signal(SIGINT,sigint_handler) == SIG_ERR)
	{
		cout << "Could not handle SIGINT" << endl;
	}
	while(command != "quit")
	{
		cout << "% ";
		getline(cin, command);
		eval_cmd(command);
	}
	kill(getpid(),9);
}
