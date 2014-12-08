#include "game.h"
#include <cstdlib>
#include <iostream>

using namespace std;

guessingGame::guessingGame(double rate)
:game(rate)
{}

void guessingGame::play() const
{
	srand(time(NULL));
	int number_to_guess = rand() % 100 + 1;
	int number_of_guesses = 7;
	int guess = 0;
	cout << "Playing the guessing game! Your goal is to guess the number " << endl;
	cout << "that is between 1 and 100 in " << number_of_guesses << " guesses...GO!" << endl;
	
	while(number_of_guesses != 0)
	{
		cout << "Guesses left: "<< number_of_guesses << endl << "Guess? ";
		cin >> guess;
		if(guess > number_to_guess) 
		{
			cout << "Too big" << endl; 
			cout << "--------------------" << endl;
			--number_of_guesses;
			continue;
		}
		
		if(guess < number_to_guess)
		{
			cout << "Too small" << endl;
			cout << "--------------------" << endl;
			--number_of_guesses;
			continue;
		}
		
		cout << "You got it! And people said you'd never accomplish anything..." << endl;
		return;
	}
	cout << "You're out of guesses. The number was " << number_to_guess << endl;
	cout << "And you were just about to guess that weren't you?" << endl;
}

