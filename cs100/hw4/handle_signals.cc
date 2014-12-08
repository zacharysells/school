#include <csignal>
#include <cstdlib>
#include <stdio.h>
#include <unistd.h>
#include <iostream>
using namespace std;

int times_quit = 0;
int times_interupt = 0;
int times_stopped = 0;

void sigint_handler(int x)
{
	cout <<"I"<< endl;
	times_interupt++;
}

void sigquit_handler(int x)
{
	cout << "Q" << endl;
	times_quit++;
}

void sigstop_handler(int x)
{
	cout << "S" << endl;
	times_stopped++;
	if(times_stopped == 3)
	{
		cout << "Times Interrupted: " << times_interupt << endl;
		cout << "Times Stopped: " << times_stopped << endl;
		cout << "Times Quit: " << times_quit << endl;
		exit(1);
	}
	kill(getpid(),SIGSTOP);
	
}
int main() 
{
	// Turn off output buffering here if you like
	if(signal(SIGINT,sigint_handler) == SIG_ERR)
	{
		cout << "Could not handle SIGINT" << endl;
	}
	if(signal(SIGQUIT, sigquit_handler) == SIG_ERR)
	{
		cout << "Could not handle SIGQUIT" << endl;
	}
	
	if(signal(SIGTSTP, sigstop_handler) == SIG_ERR)
	{
		cout << "Could not handle SIGTSTP" << endl;
	}
	while (true)
	{
		cout << "X" << flush;
	}
}

