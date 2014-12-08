/*	Partner 1 Name & E-mail: Zachary Sells zsell001@ucr.edu
 *	Partner 2 Name & E-mail: Sam Sepasi ssepa001@ucr.edu
 *	Lab Section: 023
 *	Assignment: Lab 2  Exercise 2
 *	Exercise Description: [optional - include for your own benefit]
 *	
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */


#include <avr/io.h>

// Bit-access function
unsigned char SetBit(unsigned char x, unsigned char k, unsigned char b) {
	return (b ? x | (0x01 << k) : x & ~(0x01 << k));
}
unsigned char GetBit(unsigned char x, unsigned char k) {
	return ((x & (0x01 << k)) != 0);
}

int main(void)
{
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	DDRC = 0xFF; PORTC = 0x00; 
	
	unsigned char tmpA = 0x00;
	unsigned char tmpC = 0x00;
    while(1)
    {
         tmpA = PINA;
		 tmpC = 0x00;
		 
		 if(tmpA == 1 || tmpA == 2)
		 {
			SetBit(tmpC, 5, 1);
			tmpC = SetBit(tmpC, 6, 1);
		 }			
		
		 else if(tmpA == 3 || tmpA == 4)
		 {
			tmpC = SetBit(tmpC, 5, 1);
			tmpC = SetBit(tmpC, 4, 1);
			tmpC = SetBit(tmpC, 6, 1);
		 }
		 
		 else if(tmpA == 5 || tmpA == 6)
		 {
			 tmpC = SetBit(tmpC, 3, 1);
			 tmpC = SetBit(tmpC, 4, 1);
			 tmpC = SetBit(tmpC, 5, 1);
		 }
		 
		 else if(tmpA == 7 || tmpA == 8 || tmpA == 9)
		 {
			tmpC = SetBit(tmpC, 2, 1);
		 	tmpC = SetBit(tmpC, 3, 1);
		 	tmpC = SetBit(tmpC, 4, 1);
		 	tmpC = SetBit(tmpC, 5, 1);
		 }		 
		 else if(tmpA == 10 || tmpA == 11 || tmpA == 12)
		 {
			 tmpC = SetBit(tmpC, 1, 1);
			 tmpC = SetBit(tmpC, 2, 1);
			 tmpC = SetBit(tmpC, 3, 1);
			 tmpC = SetBit(tmpC, 4, 1);
			 tmpC = SetBit(tmpC, 5, 1);
		 }
		 
		 else if(tmpA == 13 || tmpA == 14 || tmpA == 15)
		 {
			 tmpC = SetBit(tmpC, 0, 1);
			 tmpC = SetBit(tmpC, 1, 1);
			 tmpC = SetBit(tmpC, 2, 1);
			 tmpC = SetBit(tmpC, 3, 1);
			 tmpC = SetBit(tmpC, 4, 1);
			 tmpC = SetBit(tmpC, 5, 1);
		 }
		 
		 PORTC = tmpC;		 
			 					 			 			 			
    }
}
