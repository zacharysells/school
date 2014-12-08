#include <iostream>
#include <iomanip>
#include <iterator>
#include <fstream>
#include <set>
#include <map>

using namespace std;

int main()
{
	ifstream wordFile, exWordFile;
	wordFile.open("words.txt");
	exWordFile.open("excludedWords.txt");
	map<string, int> words;
	string input_str;
	
	//Set up exclusion set
	set<string> exclusion_set;
	copy(istream_iterator<string>(exWordFile), 
		istream_iterator<string>(),
		inserter(exclusion_set, exclusion_set.begin()));
		
	
	pair< map<string,int>::iterator , bool > ret;
	while(wordFile >> input_str)
	{
		//Don't include word if it's in the inclusion set.
		if(exclusion_set.find(input_str) == exclusion_set.end())
		{
			ret = words.insert(pair<string,int>(input_str,1));
			
			//Increment Word if it's already in set
			if(ret.second ==  false)
				ret.first->second++;
		}
	}
	
	cout << "Word list is: words.txt" << endl;
	cout << "Exclusion set is: excludedWords.txt" << endl;
	cout << "Word counts are below: " << endl;
	cout << "---------------------------------------" << endl;
	
	
	map<string,int>::iterator map_it = words.begin();
	for(; map_it != words.end(); ++map_it)
		cout << setw(20) << left << map_it->first << "\t" << map_it->second << endl;
	
}
