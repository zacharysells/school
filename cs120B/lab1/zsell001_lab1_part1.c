/*	Partner 1 Name & E-mail: Zachary Sells zsell001@ucr.edu
 *	Partner 2 Name & E-mail: Sam Sepasi ssepa001@ucr.edu
 *	Lab Section: 023
 *	Assignment: Lab 1  Exercise 1
 *	Exercise Description: [optional - include for your own benefit]
 *	
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */


#include <avr/io.h>

int main(void)
{
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	unsigned char tempB = 0x00;
    while(1)
    {
        //TODO:: Please write your application code
		tempB = (PINA & 0x01) && !(PINA & 0x02);
		PORTB = tempB;
    }
}
