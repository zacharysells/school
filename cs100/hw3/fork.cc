#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <cstdio>
using namespace std;

int main()
{
	int pid1, pid2, pid3, pid4;
	int NUMB_OUTS = 10000;
	
    pid1 = fork();
    switch(pid1)
	{
		case -1: perror("Fork failed, exiting"), exit(1);
		
		case 0: 
		{
			cout << "PID of child 1: " << getpid() << endl;
			for(int i = 0; i < NUMB_OUTS; ++i)
			{
				cout << "A" << flush;
			}
			if(kill(getpid(),9) < 0) cout << "Error killing child" << endl;
		}
		 
		default: break;
	}
	
	pid2 = fork();
    switch(pid2)
	{
		case -1: perror("Fork failed, exiting"), exit(1);
		
		case 0: 
		{
			cout << "PID of child 2: " << getpid() << endl;
			for(int i = 0; i < NUMB_OUTS; ++i)
				cout << "B" << flush;
			if(kill(getpid(),9) < 0) cout << "Error killing child" << endl;
		}
		 
		default: break;
	}
	
	pid3 = fork();
    switch(pid3)
	{
		case -1: perror("Fork failed, exiting"), exit(1);
		
		case 0: 
		{
			cout << "PID of child 3: " << getpid() << endl;
			for(int i = 0; i < NUMB_OUTS; ++i)
				cout << "C" << flush;
			if(kill(getpid(),9) < 0) cout << "Error killing child" << endl;
		}
		 
		default: break;
	}
	
	pid4 = fork();
    switch(pid4)
	{
		case -1: perror("Fork failed, exiting"), exit(1);
		
		case 0: 
		{
			cout << "PID of child 4: " << getpid() << endl;
			for(int i = 0; i < NUMB_OUTS; ++i)
				cout << "D" << flush;
			if(kill(getpid(),9) < 0) cout << "Error killing child" << endl;
		}
		 
		default: break;
	}
	
	wait(NULL);
	wait(NULL);
	wait(NULL);
	wait(NULL);
}
