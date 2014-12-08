/*	Partner 1 Name & E-mail: Zachary Sells zsell001@ucr.edu
 *	Partner 2 Name & E-mail: Sam Sepasi ssepa001@ucr.edu
 *	Lab Section: 023
 *	Assignment: Lab 1  Exercise 3
 *	Exercise Description: [optional - include for your own benefit]
 *	
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */

#include <avr/io.h>

int main(void)
{
	DDRA = 0x00; PORTA = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;
	unsigned char numb_avail = 0x04;
    while(1)
    {
		numb_avail = 0x04;
        if(PINA & 0x01)
			--numb_avail;
		if(PINA & 0x02)
			--numb_avail;
		if(PINA & 0x04)
			--numb_avail;
		if(PINA & 0x08)
			--numb_avail;
			
		if(numb_avail == 0x00)
			PORTC = 0x80 | numb_avail;
		else
			PORTC = numb_avail;
    }
}
