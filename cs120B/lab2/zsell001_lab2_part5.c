/*	Partner 1 Name & E-mail: Zachary Sells zsell001@ucr.edu
 *	Partner 2 Name & E-mail: Sam Sepasi ssepa001@ucr.edu
 *	Lab Section: 023
 *	Assignment: Lab 2  Exercise 5
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
	DDRD = 0x00; PORTD = 0xFF;
	DDRB = 0xFE; PORTB = 0x01; // Configure port A's 8 pins as inputs, initialize to 1s
	//DDRB = 0xFF; PORTB = 0x00; // Configure port B's 8 pins as outputs, initialize to 0s
	unsigned short weight = 0;
	unsigned char tmpD = 0x00;
	unsigned char tmpB = 0x00;
    while(1)
    {
		tmpB = PORTB;
		weight = tmpD;
		weight = weight << 1;
		weight = SetBit(weight, 0, GetBit(tmpB, 0));
		
		
        //TODO:: Please write your application code 
    }
}
