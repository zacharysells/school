#include "game.h"
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;


hangman::hangman(double rate)
:game(rate)
{}



int numb_guesses = 7;
//First param is character to look for. Second param is string to look in
//Returns a vector of the matching indeces.
vector<int> char_matches(char c, const char * word)
{
	vector<int> matches;
	for(int i = 0; word[i] != '\0'; ++i)
		if(word[i] == c) matches.push_back(i);
	
	return matches;
}

void update_hidden(const char * actual_word, char * hidden_word, vector<int> indeces)
{
	for(int i = 0; i < indeces.size(); ++i)
	{
		hidden_word[indeces[i]] = actual_word[indeces[i]];
	}
}

void display_screen(const char * actual_word, char * hidden_word)
{
	char guess;
	cout << "Your word: " << hidden_word << endl;
	while(strcmp(actual_word, hidden_word) != 0 && numb_guesses != 0)
	{
		cout << "Take a guess! ";
		cin >> guess;
		update_hidden(actual_word, hidden_word, char_matches(guess, actual_word));
		cout << "Your word: " << hidden_word << endl;
		numb_guesses--;
	}
	if(strcmp(actual_word, hidden_word) == 0)
	{
		cout << "Good job you guessed it! Don't get TOO excited...That was an easy one" << endl;
		return;
	}
	
	cout << "Out of guesses! Don't worry I wasn't expecting you to guess it anyways..." << endl;
	cout << "The word was: " << actual_word << endl;
}

void hangman::play() const
{
	cout << "Let's play hangman! You'll have " << numb_guesses << " tries to guess the word...GO!" << endl;
	cout << "----------------------------------------------------------------" << endl << endl;
	
	const char * words[] = {"earthlings", "facelifted", "cactus", "ice", "cantalope", "apple", "math", "jacket", "alligator", "bee", "easy"};
	srand(time(NULL));
	
	const char * actual_word = words[rand() % 11];
	char hidden_word[strlen(actual_word)];
	
	int i = 0;
	for(; actual_word[i] != '\0'; ++i)
		hidden_word[i] = '-';
	hidden_word[i] = '\0';

	display_screen(actual_word, hidden_word);
	
	
}


