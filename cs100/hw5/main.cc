#include "game.h"
#include <vector>
#include <iostream>
using namespace std;

void game_library(game * Games[])
{
	int selection = 0;
	while(selection >= 0)
	{
		cout << "----------------------------------------------------------" << endl;
		cout << "----------------------------------------------------------" << endl;
		cout << "Welcome to my game library! Choose from one of the following games: " << endl;
		cout << "----------------------------------------------------------" << endl;
		cout << "----------------------------------------------------------" << endl;
		cout << "1.)Guessing Game, " << "Rating: " << Games[0]->rating() << endl;
		cout << "2.)Hangman, " << "Rating: " << Games[1]->rating() << endl;
		cout << "3.)Math Game, " << "Rating: " << Games[2]->rating() << endl;
		cout << "Your selection('-1' to quit)";
		cin >> selection;
	
	
		switch(selection)
		{
			case 1: Games[0]->play(); break;
			
			case 2: Games[1]->play(); break;
			
			case 3: Games[2]->play(); break;
			
			default: break;
		}
	}
	
}

int main()
{
	guessingGame guess(6.0);
	hangman hang(7.0);
	mathGame math(10.0);
	
	game* Games[3];
	Games[0] = &guess;
	Games[1] = &hang;
	Games[2] = &math;
	game_library(Games);
}
