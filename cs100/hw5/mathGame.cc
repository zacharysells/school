#include "game.h"
#include <cstdlib>
#include <unistd.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

using namespace std;

mathGame::mathGame(double rate)
:game(rate)
{}

void mathGame::play() const
{
	
	int pid = fork();
	
	if(pid < 0)
	{
		cout << "Something went wrong...exiting" << endl;
		exit(1);
	}
	else if(pid == 0)
	{
		srand(time(NULL));
		int operand1, operand2;
		int user_ans;
		int difficultyScale = 25;
		int score = 0;
		int parentID = getpid();
		cout << "---------------------------------------------------------" << endl;
		cout << "This is a timed math game! See how many you can get right" << endl;
		cout << "You'll only have a few seconds for each questions." << endl;
		cout << "Oh, and they'll get progressively harder :) " << endl;
		cout << "GO!!!" << endl;
		cout << "---------------------------------------------------------" << endl;
		sleep(3);
		do
		{
			pid = fork();
			
			if(pid < 0) 
			{
				cout << "Something went wrong...exiting" << endl;
				exit(1);
			}
			if(pid == 0)
			{
				sleep(4);
				cout << "\nClose but no cigar! Your final score is: " << score << endl;
				cout << "Good job, you did better than average!...almost" << endl;
				kill(parentID, SIGTERM);
				exit(0);
			}
			else
			{
				operand1 = rand() % difficultyScale + 1;
				operand2 = rand() % difficultyScale + 1;
				cout << operand1 << " + " << operand2 << " = ";
				cin >> user_ans;

				if(user_ans == operand1 + operand2)
				{
					cout << "CORRECT! +1 point" << endl;
					score++;
					difficultyScale = difficultyScale * 2;
				}
				kill(pid, SIGTERM);
			}
		}while(user_ans == operand1 + operand2);
		cout << "\nClose but no cigar! Your final score is: " << score << endl;
		cout << "Good job, you did better than average!...almost" << endl;
		exit(0);
	}
	
	else
	{
		wait(NULL);
		return;
	}
}
