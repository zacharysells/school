#include <iostream>
#include "hashmap.h"
#include <string>
#include <cassert>

using namespace std;

int symbol_to_int(char c)
{
	if(c == 'I') return 1;
	if(c == 'V') return 5;
	if(c == 'X') return 10;
	if(c == 'L') return 50;
	if(c == 'C') return 100;
	if(c == 'D') return 500;
	if(c == 'M') return 1000;
}


static int translate_Roman_to_Arabic(string s) 
{
	vector<int> num_list;
	int sum = 0;
	for(unsigned i = 0; i < s.size(); i++)
		num_list.push_back(symbol_to_int(s.at(i)));
	
	sum = sum + num_list[0];
	for(unsigned i = 1; i < num_list.size(); i++)
	{
		if(num_list[i+1] > num_list[i]) 
			sum = sum - num_list[i];
		
		else sum = sum + num_list[i];
	}
	return sum;
}


static void stringTest() {
    HashMap<string, int> shm;
    shm["Eleven"] = 11;
    assert(shm.containsKey("Eleven") && shm.get("Eleven") == 11 && shm["Eleven"] == 11);
    shm["Two"] = 2;
    assert(!shm.containsKey("one") && shm.get("Five") == 0 && shm["Five"] == 0 && shm.containsKey("Five"));
    }


int main() {
	HashMap<string, int> romanNumerals;
		romanNumerals.put("I", 1);
		romanNumerals.put("V", 5);
		romanNumerals.put("X", 10);
		romanNumerals.put("L", 50);
		romanNumerals.put("C", 100);
		romanNumerals.put("D", 500);
		romanNumerals.put("M", 1000);

		cout << "\n Size: "<< romanNumerals.size();
		cout << "\n V in decimal is: "<< romanNumerals.get("V");
		cout << "\n Removing V: ";
		romanNumerals.remove("V");
		cout << "\n New size: "<< romanNumerals.size();
		cout << "\n Testing if Map contains C ";
		if(romanNumerals.containsKey("C"))
			cerr <<"\n C is in the map";
		cout << "\n The numeric value of 'X' = " << romanNumerals["X"] << endl;
        
		//romanNumerals.print();
		//stringTest();
		assert(translate_Roman_to_Arabic("MCMLXIX") == 1969);

	return 0;
}

