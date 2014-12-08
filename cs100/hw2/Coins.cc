#include <iostream>
#include <iomanip>
#include "Coins.h"

using namespace std;

Coins::Coins(int q = 0, int d = 0, int n = 0, int p = 0)
:quarters(q),dimes(d),nickels(n),pennies(p)
{}

void Coins::depositChange(Coins c)
{
	quarters = quarters + c.quarters;	//Deposit quarters
	dimes = dimes + c.dimes;			//Deposit dimes
	nickels = nickels + c.nickels;		//Deposit dimes
	pennies = pennies + c.pennies;		//Deposit pennies
}

bool Coins::hasSufficientAmount(int amount)
{
	Coins c = *this;
	
	while(amount >= 25 && c.quarters != 0)
	{
		amount = amount - CENTS_PER_QUARTER;
		c.quarters--;
	}
	
	while(amount >= 10 && c.dimes != 0)
	{
		amount = amount - CENTS_PER_DIME;
		c.dimes--;
	}
	
	while(amount >= 5 && c.nickels != 0)
	{
		amount = amount - CENTS_PER_NICKEL;
		c.nickels--;
	}
	
	while(amount >= 1 && c.pennies != 0)
	{
		amount = amount - CENTS_PER_PENNY;
		c.pennies--;
	}
	
	if(amount > 0) 
	{
		return false;
	}
	else 
	{
		return true;
	}
}

Coins Coins::extractChange(int amount)
{
	Coins c = *this;
	Coins real_this = *this;
	
	while(amount >= 25 && c.quarters != 0)
	{
		amount = amount - CENTS_PER_QUARTER;
		c.quarters--;
	}
	
	while(amount >= 10 && c.dimes != 0)
	{
		amount = amount - CENTS_PER_DIME;
		c.dimes--;
	}
	
	while(amount >= 5 && c.nickels != 0)
	{
		amount = amount - CENTS_PER_NICKEL;
		c.nickels--;
	}
	
	while(amount >= 1 && c.pennies != 0)
	{
		amount = amount - CENTS_PER_PENNY;
		c.pennies--;
	}
	
	if(amount > 0) 
	{
		cout << "Not enough coins or not exact change" << endl << endl;
		return *this;
	}
	else 
	{
		real_this = c;
		return real_this;
	}
}

void Coins::print(ostream & out)
{
	float total = (quarters * 25 + dimes
	* 10 + nickels * 5 + pennies) / 100.0;
	
	cout << "\n-----------------------------------" << endl;
	cout << "Quarters(25c): " << quarters << endl;
	cout << "Dimes(10c):    " << dimes << endl;
	cout << "Nickels(5c):   " << nickels << endl;
	cout << "Pennies(1c):   " << pennies << endl;
	cout << "-----------------------------------" << endl;
	
	cout.setf(ios::fixed, ios::floatfield);
	cout.precision(2);
	cout << "Total: $" << total << " dollars" << endl;
	cout << "-----------------------------------" << endl;
}

ostream& operator<< (ostream & out, Coins & c)
{
	c.print(out);
	return out;
}



