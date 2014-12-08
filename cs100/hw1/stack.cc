#include "stack.h"
#include <iostream>

using namespace std;

Stack::Stack()
:data(),current(0)
{}

void Stack::push(char c)
{
	data[current] = c;
	current++;
}

char Stack::pop()
{
	current--;
	return data[current];
}

char Stack::top()
{
	return data[current - 1];
}

bool Stack::isEmpty()
{
	if (current == 0) return true;
	
	return false;
}

Stack::~Stack()
{
	//No dynamically allocated data in Stack class
}

int main()
{
	cout << "-------------------------------------------------" 
	<< "-------" << endl;
	cout << "To invoke testing subroutine, enter 'quit' and then"
	<<"\nenter 'hello' as a test word. To quit program, enter ^d" << endl;
	cout << "-------------------------------------------------" 
	<< "-------" << endl;

	bool run_tests = false;
	
	Stack charStack;
	while(!cin.eof())
	{

		int iterator = 0;
		
		cout << "Enter word: ";
		string str;
		getline(cin, str);
		if(str == "quit") 
		{
			run_tests = true;
			break;
		}
		
		while(str[iterator] != '\0')
		{
			charStack.push(str[iterator]);
			++iterator;
		}

		while(!charStack.isEmpty())
		{
			cout << charStack.pop();
		}
		cout << endl;
	}
	if(run_tests)
	{
		cout << "-------------------------------------------------" << endl;
		int iterator = 0;
		cout << "Enter test word: ";
		string str;
		cin >> str;
			
		while(str[iterator] != '\0')
		{
			charStack.push(str[iterator]);
			++iterator;
		}
		
		
		cout << "Testing stack.pop()" << endl;
		cout << "Expected popped element: o | Actual popped element: " 
		<< charStack.pop() << endl;
		cout << "-------------------------------------------------" << endl;
		cout << "Printing top of stack using stack.top()..." << endl;
		cout << "Expected output: l | Actual ouput: " 
		<< charStack.top() << endl;
		cout << "-------------------------------------------------" << endl;
		cout << "Popping elements until stack is empty. This will test "
		<< "both pop() and isEmpty()" << endl;
		while(!charStack.isEmpty())
		{
			cout << "Popped off element: " << charStack.pop() << endl;
		}
		cout << "Stack is empty" << endl;
		cout << "-------------------------------------------------" << endl;
	}
	
	return 0;
}
