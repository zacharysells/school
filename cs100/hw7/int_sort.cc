#include <iostream>
#include <iterator>
#include <algorithm>
#include <fstream>
#include <set>

using namespace std;

bool is_odd(int i)
{
	return i%2 == 1;
}

bool is_even(int i)
{
	return !is_odd(i);
}

int main()
{
	ifstream numbers;
	ofstream evens, odds;
	evens.open("evens.txt");
	odds.open("odds.txt");
	numbers.open("numbers.txt");
	multiset<int> sorted_set;
	copy(istream_iterator<int>(numbers),
		istream_iterator<int>(),
		inserter(sorted_set, sorted_set.end()));
	
	remove_copy_if(sorted_set.begin(), sorted_set.end(), ostream_iterator<int>(evens, " "), is_odd);
	remove_copy_if(sorted_set.begin(), sorted_set.end(), ostream_iterator<int>(odds, " "), is_even);

	
	cout << "Even numbers file is: evens.txt" << endl;
	cout << "Odd numbers file is: odds.txt" << endl;
	cout << "Sorted list of ints is below: " << endl;
	cout << "---------------------------------------" << endl;
	
	
	for(set<int>::iterator it = sorted_set.begin(); it != sorted_set.end(); ++it)
		cout << *it << " ";
}
