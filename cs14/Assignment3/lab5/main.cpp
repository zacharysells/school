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
#include <iostream>

using namespace std;

int main() {
map<string, int> romanNumerals;
romanNumerals["I"] = 1;
romanNumerals["V"] = 5;
romanNumerals["X"] = 10;
romanNumerals["L"] = 50;
romanNumerals["C"] = 100;
romanNumerals["D"] = 500;
romanNumerals["M"] = 1000;

//cout << "\nTesting assignment operator";


cout << romanNumerals["X"] << endl;
map<string, int> map2(romanNumerals);
romanNumerals["X"] = 15;

map<string, int> map3;
map3 = romanNumerals;
romanNumerals["X"] = 9999;
cout << map3["X"] << endl;

map <string, int> RN;
RN = romanNumerals;

cout << "\n Testing if RN contains C ";
if(RN.find("C") != RN.end())
cout <<"\n C is in the map" << endl;
else
cout << "\n oops! something is wrong" << endl;

// Add more testing here
return 0;
}
