/*	Partner 1 Name & E-mail: Zachary Sells zsell001@ucr.edu
 *	Partner 2 Name & E-mail: Sam Sepasi ssepa001@ucr.edu
 *	Lab Section: 023
 *	Assignment: Lab 1  Exercise 4
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
	//inputs
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0x00; PORTB = 0xFF;
	DDRD = 0x00; PORTD = 0xFF;
	
	//outputs
	DDRC = 0xFF; PORTC = 0x00;
	unsigned char tempC = 0x00;
	unsigned short tot_weight = 0x0000;
    while(1)
    {
        tot_weight = PINA + PINB + PIND;
		if(tot_weight > 140) 
			PORTC = 0x01;
		if(PINA - PIND > 80 || PIND - PINA > 80)
			PORTC = PINC | 0x02;
		
		
		
		
		tot_weight = tot_weight >> 2;
		tot_weight = tot_weight & 0x00fc;
		PORTC = PINC | tot_weight;
		//PORTD = tot_weight;
    }
}
