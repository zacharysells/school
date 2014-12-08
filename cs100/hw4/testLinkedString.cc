#include "String.h"
using namespace std;

int main()
{
	
	const char * c = "Hello World!";
	const char * c2 = "\0";
	const  char * c3 = "_Zachary";
	
	cout << "Testing constructors..." << endl;
	String s(c);
	String s2(c2);
	String s3(c3);
	String s4(s3);
	cout << "Strings s, s2, s3, s4 have been constructed with s2 being the empty string" << endl << endl;
	
	cout << "s3 = " << s3 << endl;
	cout << "Setting s4 = s3" << endl;
	cout << "s4 = " << s4 << endl << endl;
	
	cout << "Editing s3 and setting s2[0] = 'z'" << endl;
	s3[4] = 'k';
	s3[7] = 'i';
	s2[0] = 'z';
	cout << "s = " << s << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s3 = " << s3 << endl;
	cout << "s4 = " << s4 << endl << endl;
	
	cout << "Size of s3: " << s3.length() << endl;
	cout << "Size of s2: " << s2.length() << endl << endl;
	
	cout << "Index of char 'Z' on s3: " << s3.indexOf('Z') << endl;
	cout << "Index of char 'i' on s2: " << s2.indexOf('i') << endl;
	cout << "Index of char 'l' on s3: " << s3.indexOf('l') << endl << endl;
	
	cout << "Is s3 == s4? ";
	if(s3 == s4) cout << "Yes" << endl;
	
	else cout << "No" << endl << endl;
	
	cout << "Setting s3 = s4" << endl;
	s3 = s4;
	
	cout << "Is s3 == s4? ";
	if(s3 == s4) cout << "Yes" << endl << endl;
	
	else cout << "No" << endl << endl;

	
	cout << "Concatenating s2 to s..." << endl;
	cout << "s + s2 = " << s + s2 << endl << endl;
	
	cout << "s = " << s << endl; 
	
	cout << "Concatenating s3 to s2 using += operator..." << endl;
	s2 += s3;
	cout << "(s + s2) + s3 = " << s2 << endl << endl;
	
	cout << "Enter a single-word string and I will tell you it's size" << endl;
	cin >> s;
	cout << "Size: " << s.length() << endl << endl;
	
	cout << "This concludes testing..." << endl;
	
	
	cout << "--------------------------------------------" << endl;
	cout << "Assignment efficiency:" << endl;
	
	
	cout << "Operator += is more efficient." << endl;
	cout << "It only requires 2 + 2n copies, where n is the size of the right operand" << endl;
	cout << "It also only creates n new node objects" << endl << endl;
	
	cout << "Operator + is less efficient." << endl;
	cout << "It requires twice as many copies and new nodes as the += operator" << endl
	<<"because it needs to create an entirely new String object that is the combined size of the two operands" << endl;
	
	
	
}

