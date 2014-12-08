/*	Partner 1 Name & E-mail: Zachary Sells zsell001@ucr.edu
 *	Partner 2 Name & E-mail: Sam Sepasi ssepa001@ucr.edu
 *	Lab Section: 23
 *	Assignment: Lab #6  Exercise #1
 *	Exercise Description: [optional - include for your own benefit]
 *	
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */

#include <avr/io.h>
#include "timer.h"


// Bit-access function
unsigned char SetBit(unsigned char x, unsigned char k, unsigned char b) {
	return (b ? x | (0x01 << k) : x & ~(0x01 << k));
}
unsigned char GetBit(unsigned char x, unsigned char k) {
	return ((x & (0x01 << k)) != 0);
}

enum LED_sm {state1} ledstates;
enum BLINK_sm {bl1} blkstates;
enum COMB_sm {comb_1} combstates;
unsigned char threeLEDs = 0x00;
unsigned char shift = 0;
unsigned int first = 1;
unsigned int first1 = 1;
unsigned char tmpB = 0x00;
unsigned char blinkingLED = 0x00;
ThreeLed_SM (){
	switch(ledstates){
		case -1:
			ledstates = state1;
			shift = 0;
			break;
		case state1:
			break;
		default:
			break;
	}
	switch  (ledstates){
		case state1:
			if (first == 1){
				threeLEDs = 0x01;
				first = 0;
			}
			else{
				threeLEDs = threeLEDs << 1;
				++shift;
				if (shift >=3){
					shift = 0;
					threeLEDs = 0x01;
				}
			}				
			break;
		default:
			break;				
	}	
				
}

Blinks_sm(){
	switch (bl1){
		case -1:
			blkstates = bl1;
			blinkingLED = 0x00;
		case bl1 :
			break;
		default:
			break;
	}
	switch(bl1){
		case bl1:
			if (first1){
				first1 = 0;
				blinkingLED = 0x08;
			}
			else{
				if (blinkingLED == 0x08){
					blinkingLED = 0x00;
				}
				else{
					blinkingLED = 0x08;
				}
			}				
		default:
			break;
	}			
}

Combine_sm (){
	
	switch(comb_1)
	{
		case -1:
			combstates = comb_1;
			break;
		case comb_1:
			break;
		default:
			break;
	}
	
	switch(comb_1)
	{
		case comb_1:
			tmpB = blinkingLED | threeLEDs;
			break;
		default:
			break;
	}
	
	PORTB = tmpB;
}			




int main(void)
{
     ledstates = -1;
	 blkstates = -1;
     DDRB = 0xFF; PORTB = 0x00; // LCD data lines
     TimerSet(1000);
     TimerOn();
     
     while(1) {
	     ThreeLed_SM();
		 Blinks_sm();
		 Combine_sm();
	     while(!TimerFlag);
	     TimerFlag = 0;
	     
     }
}
