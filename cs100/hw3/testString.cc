#include "String.h"
#include <iostream>

using namespace std;

int main()
{
	const char * c = "Hello World!";
	const char * c2 = "_My name is";
	const  char * c3 = "_Zachary";
	
	cout << "Testing constructors..." << endl;
	String s(c);
	String s2(c2);
	String s3(c3);
	String s4(s3);
	cout << "Strings s, s2, s3, s4 have been constructed" << endl << endl;
	
	cout << "s3 = " << s3 << endl;
	cout << "Setting s4 = s3" << endl;
	cout << "s4 = " << s4 << endl << endl;
	
	cout << "Editing s3..." << endl;
	s3[4] = 'k';
	s3[7] = 'i';
	cout << "s = " << s << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s3 = " << s3 << endl;
	cout << "s4 = " << s4 << endl << endl;
	
	cout << "Size of s3: " << s3.size() << endl;
	cout << "Size of s2: " << s2.size() << endl << endl;
	
	cout << "Reverse of s3 is: " << s3.reverse() << endl << endl;
	
	cout << "Index of char 'Z' on s3: " << s3.indexOf('Z') << endl;
	cout << "Index of char 'i' on s3: " << s3.indexOf('i') << endl;
	cout << "Index of char 'l' on s3: " << s3.indexOf('l') << endl << endl;
	
	cout << "Index of pattern, 'World', in s: " << s.indexOf(String("World")) << endl << endl;
	
	cout << "Is s3 != s4? ";
	if(s3 != s4) cout << "Yes" << endl;
	
	else cout << "No" << endl << endl;
	
	cout << "Setting s3 = s4" << endl;
	s3 = s4;
	
	cout << "Is s3 == s4? ";
	if(s3 == s4) cout << "Yes" << endl << endl;
	
	else cout << "No" << endl << endl;

	cout << "Is s2 > s? ";
	if(s2 > s) cout << "Yes" << endl << endl;
	else if(s2 < s) cout << "No, it's less than" << endl << endl;
	else if(s2 == s) cout << "No. they are equal" << endl << endl;
	
	cout << "Is s3 >= s4? " << endl;
	if(s3 >= s4) cout << "Yes" << endl << endl;
	else cout << "No, s3 < s4" << endl << endl;
	
	cout << "Concatenating s2 to s..." << endl;
	cout << "s + s2 = " << s + s2 << endl << endl;
	
	cout << "Concatenating s3 to s2 using += operator..." << endl;
	s2 += s3;
	cout << "(s + s2) + s3 = " << s2 << endl << endl;
	
	cout << "Enter a single-word string and I will tell you it's size" << endl;
	cin >> s;
	cout << "Size: " << s.size() << endl << endl;
	
	cout << "This concludes testing..." << endl;

}
