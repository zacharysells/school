#include <iostream>
#include <vector>
using namespace std;

int main()
{
	string s;
	getline(cin,s);
	s = s + '\n';
	cout << s.find('\n');
}
