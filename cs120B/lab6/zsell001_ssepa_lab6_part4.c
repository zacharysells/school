/*	Partner 1 Name & E-mail: Zachary Sells zsell001@ucr.edu
 *	Partner 2 Name & E-mail: Sam Sepasi ssepa001@ucr.edu
 *	Lab Section: 23
 *	Assignment: Lab #6  Exercise #4
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
enum SPEAK_sm {speak_on, speak_off} speakstates;
enum COMB_sm {comb_1} combstates;
enum FREQ_sm {freq_wait, freq_up, freq_upw, freq_down, freq_downw} freqstates;
unsigned char threeLEDs = 0x00;
unsigned char shift = 0;
unsigned int first = 1;
unsigned int first1 = 1;
unsigned char tmpB = 0x00;
unsigned char blinkingLED = 0x00;
unsigned char speaker = 0x00;
unsigned char freq = 0;

Frequency_SM (){
	unsigned char A0 = GetBit(~PINA, 0);
	unsigned char A1 =GetBit(~PINA, 1);
	switch(freqstates)
	{
		case -1:
			freqstates = freq_wait;
			freq = 1;
			break;
		case freq_wait:
			if(A0){
				freqstates = freq_up;
			}
			else if(A1){
				freqstates = freq_down;
			}
			break;
		case freq_up :
			if (A0){
				freqstates = freq_upw;
			}	
			else if (!A0){
				freqstates = freq_wait;
			}
			break;
		case freq_down :
			if(A1)
			{
				freqstates = freq_downw;
			}
			else if(!A1)
			{
				freqstates = freq_wait;
			}				
			break;
		case freq_upw:
			if(A0)
			{
				freqstates = freq_upw;
			}
			else if(!A0)
			{
				freqstates = freq_wait;
			}							
			break;
		case freq_downw:
			if(A1)
			{
				freqstates = freq_downw;	
			}			
			else if(!A1)
			{
				freqstates = freq_wait;	
			}			
			break;
		default:
			break;
	}
	
	switch(freqstates)
	{
		case freq_wait:
			break;
		case freq_up:
			if(freq < 30)
			{
				++freq;
			}
			break;
		case freq_down:
			if(freq > 0)
			{
				--freq;
			}
			break;
		default:
			break;
	}						
		
		
	
	
	
}

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
	switch (blkstates){
		case -1:
			blkstates = bl1;
			blinkingLED = 0x00;
		case bl1 :
			break;
		default:
			break;
	}
	switch(blkstates){
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

Speaker_sm()
{
	unsigned char A2 = GetBit(~PINA, 2);
	switch(speakstates)
	{
		case -1:
			speakstates = speak_off;
			break;
		case speak_off:
			if(A2)
			{
				speakstates = speak_on;
			}
			else
			{
				speakstates = speak_off;
			}
			break;
		case speak_on:
			if(A2)
			{
				speakstates = speak_off;
			}
			else
			{
				speakstates = speak_on;
			}
			break;
		default:
			break;
	}
	
	switch(speakstates)
	{
		case speak_off:
			speaker = 0x00;
			break;
		case speak_on:
			speaker = 0x10;
			break;
		default:
			break;
	}		
}

Combine_sm (){
	
	switch(combstates)
	{
		case -1:
			combstates = comb_1;
			break;
		case comb_1:
			break;
		default:
			break;
	}
	
	switch(combstates)
	{
		case comb_1:
			tmpB = blinkingLED | threeLEDs | speaker;
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
	 speakstates = -1;
	 freqstates = -1;
	 
	 unsigned long led_ElapsedTime = 0;
	 unsigned long blk_ElapsedTime = 0;
	 unsigned long speak_ElapsedTime = 0;
	 //unsigned long freq_ElapsedTime = 0;
	 DDRA = 0x00; PORTA = 0xFF;
     DDRB = 0xFF; PORTB = 0x00; // LCD data lines
     TimerSet(1);
     TimerOn();
     
     while(1) {
		 
		 Frequency_SM();
		 if(led_ElapsedTime >= 300)
		 {
			ThreeLed_SM();
			led_ElapsedTime = 0;
		 }
		 if(blk_ElapsedTime >= 1000)
		 {
			Blinks_sm();
			blk_ElapsedTime = 0;
		 }
		 if(speak_ElapsedTime >= freq)
		 {
			 Speaker_sm();
			 speak_ElapsedTime = 0;
		 }
		 
		 Combine_sm();
	     while(!TimerFlag);
	     TimerFlag = 0;
		 
		 led_ElapsedTime += 1;
		 blk_ElapsedTime += 1;
		 speak_ElapsedTime += 1;
	     
     }
}
