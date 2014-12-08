/**
 * Course: CS 14 Fall 2012
 *
 * First Name: Zachary
 * Last Name: Sells
 * Username: zsell001
 * email address: zsell001@ucr.edu
 *
 *
 * Assignment: Assignment 4
 * Filename : main.cpp
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 

#include "mymap.h"

using namespace std;

int main() {
map<int> romanNumerals;
romanNumerals["I"] = 1;
romanNumerals["V"] = 5;
romanNumerals["X"] = 10;
romanNumerals["L"] = 50;
romanNumerals["C"] = 100;
romanNumerals["D"] = 500;
romanNumerals["M"] = 1000;

cout << "\nTesting assignment operator";

map <int> RN;
RN = romanNumerals;

cout << "\n Testing if RN contains C ";
if(RN.find("C") != NULL)
cout <<"\n C is in the map" << endl;
else
cout << "\n oops! something is wrong" << endl;

// Add more testing here
return 0;
}
