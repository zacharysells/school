#include "Coins.h"
using namespace std;

const int CENTS_FOR_CHIPS = 68;

int main()
{
	Coins pocket(5,3,6,8);
	Coins piggyBank(50,50,50,50);
	
	cout << "My pocket" << pocket << endl;
	cout << "My piggy bank" << piggyBank << endl;
	
	pocket = pocket.extractChange(CENTS_FOR_CHIPS);
	cout << "This is what's left after buying a candy bar for " 
	<< CENTS_FOR_CHIPS << "cents. " << endl;
	cout << pocket;
	
	cout << "Taking 30 quarters, 25 dimes, 13 nickels, and 22 pennies from piggy bank moving it to pocket." << endl;
	for(int i = 0; i < 30; ++i)
	{
		piggyBank = piggyBank.extractChange(25);
		pocket.depositChange(Coins(1,0,0,0));
	}
	for(int i = 0; i < 25; ++i)
	{
		piggyBank = piggyBank.extractChange(10);
		pocket.depositChange(Coins(0,1,0,0));
	}
	for(int i = 0; i < 13; ++i)
	{
		piggyBank = piggyBank.extractChange(5);
		pocket.depositChange(Coins(0,0,1,0));
	}
	for(int i = 0; i < 22; ++i)
	{
		piggyBank = piggyBank.extractChange(1);
		pocket.depositChange(Coins(0,0,0,1));
	}
	cout << "My pocket" << pocket << endl;
	cout << "My piggy bank" << piggyBank << endl;
	cout << "Found 5 nickels and 7 pennies while vaccuming. Putting"
	<< " them in my piggy bank." << endl;
	piggyBank.depositChange(Coins(0,0,5,7));
	cout << piggyBank;
}
