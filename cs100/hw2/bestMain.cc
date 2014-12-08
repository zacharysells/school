#include "Coins.h"
#include <cstdlib>
using namespace std;

int main()
{
	char command;
	Coins satchel(0,0,0,0);
	cout << system("clear");
	while (command != 'q')
	{
		
		cout << "Welcome to your Coin purse!(it's a satchel!)" << endl;
		cout << "Enter 'd' to deposit coins." << endl;
		cout << "Enter 'e' to withdraw or extract coins." << endl;
		cout << "Enter 'p' to print your coins and balance." << endl;
		cout << "Enter 'q' to exit the program" << endl << endl;
		cout << "~";
		
		cin >> command;
	
		switch(command)
		{
		
			case 'd':
			{
				int q = 0;
				int d = 0;
				int n = 0;
				int p = 0;
				cout << "How many quarters? ";
				cin >> q;
				cout << "How many dimes? ";
				cin >> d;
				cout << "How many nickels? ";
				cin >> n;
				cout << "How many pennies? ";
				cin >> p;
				cout << endl;
				
				satchel.depositChange(Coins(q,d,n,p));
				break;
			}
			
			case 'e':
			{
				system("clear");
				int amount;
				cout << "How much would you like to withdraw(in cents)? ";
				cin >> amount;
				satchel = satchel.extractChange(amount);
				break;
			}
		
		
			case 'p':
			{
				system("clear");
				cout << satchel;
				break;
			}
			
		}
	}
}
