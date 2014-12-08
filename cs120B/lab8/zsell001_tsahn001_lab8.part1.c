/*	Partner 1 Name & E-mail: Zachary Sells zsell001@ucr.edu
 *	Partner 2 Name & E-mail: tsahn001@ucr.edu
 *	Lab Section: 23
 *	Assignment: Lab #8  Exercise #1
 *	Exercise Description: [optional - include for your own benefit]
 *	
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */


#include <avr/io.h>
#include "timer.h"

// 0.954 hz is lowest frequency possible with this function,
// based on settings in PWM_on()
// Passing in 0 as the frequency will stop the speaker from generating sound
void set_PWM(double frequency) {
	
if (!frequency) { TCCR3B &= 0x08; } //stops timer/counter
	else { TCCR3B |= 0x03; } // resumes/continues timer/counter				
		
	// prevents OCR3A from overflowing, using prescaler 64
	// 0.954 is smallest frequency that will not result in overflow
	if (frequency < 0.954) { OCR3A = 0xFFFF; }
	
	// prevents OCR3A from underflowing, using prescaler 64					// 31250 is largest frequency that will not result in underflow	
	else if (frequency > 31250) { OCR3A = 0x0000; }
	
	// set OCR3A based on desired frequency			
	else { OCR3A = (short)(8000000 / (128 * frequency)) - 1; }

	TCNT3 = 0; // resets counter
}

void PWM_on() {
	TCCR3A = (1 << COM3A0);
		// COM3A0: Toggle PB6 on compare match between counter and OCR3A
	TCCR3B = (1 << WGM32) | (1 << CS31) | (1 << CS30);	
		// WGM32: When counter (TCNT3) matches OCR3A, reset counter
		// CS31 & CS30: Set a prescaler of 64
	set_PWM(0);
}

void PWM_off() {
	TCCR3A = 0x00;
	TCCR3B = 0x00;
}

// Bit-access function
unsigned char SetBit(unsigned char x, unsigned char k, unsigned char b) {
	return (b ? x | (0x01 << k) : x & ~(0x01 << k));
}
unsigned char GetBit(unsigned char x, unsigned char k) {
	return ((x & (0x01 << k)) != 0);
}

enum note_States {silent, note_C4, note_D4, note_E4} note_state;
unsigned char A0 = 0x00;
unsigned char A1 = 0x00;
unsigned char A2 = 0x00;
void note_tick()
{
	A0 = GetBit(~PINA, 0);
	A1 = GetBit(~PINA, 1);
	A2 = GetBit(~PINA, 2);
	switch(note_state)
	{
		case -1:
			note_state = silent;
			break;
		
		case silent:
			if(A0 && !A1 && !A2)
			{
				note_state = note_C4;
			}
			else if(!A0 && A1 && !A2)
			{
				note_state = note_D4;
			}
			else if(!A0 && !A1 && A2)
			{
				note_state = note_E4;
			}
			else
			{
				note_state = silent;
			}
			break;
		
		case note_C4:
			if(A0 && !A1 && !A2)
			{
				note_state = note_C4;
			}
			else if(!A0 && A1 && !A2)
			{
				note_state = note_D4;
			}
			else if(!A0 && !A1 && A2)
			{
				note_state = note_E4;
			}
			else
			{
				note_state = silent;
			}
			break;
		case note_D4:
			if(A0 && !A1 && !A2)
			{
				note_state = note_C4;
			}
			else if(!A0 && A1 && !A2)
			{
				note_state = note_D4;
			}
			else if(!A0 && !A1 && A2)
			{
				note_state = note_E4;
			}
			else
			{
				note_state = silent;
			}
			break;
		case note_E4:
			if(A0 && !A1 && !A2)
			{
				note_state = note_C4;
			}
			else if(!A0 && A1 && !A2)
			{
				note_state = note_D4;
			}
			else if(!A0 && !A1 && A2)
			{
				note_state = note_E4;
			}
			else
			{
				note_state = silent;
			}
			break;
		default:
			note_state = -1;
			break;
		
	}
	
	switch(note_state)
	{
		case silent:
		{
			set_PWM(0);
			break;
		}		
		case note_C4:
		{
			set_PWM(261.63);
			break;
		}
		case note_D4:
		{
			set_PWM(293.66);
			break;
		}
		case note_E4:
		{
			set_PWM(329.63);
			break;
		}
		default:
			break;
	}
}

int main(void)
{
	DDRB = 0xFF; PORTB = 0x00;
	DDRA = 0x00; PORTA = 0xFF;
	
	TimerSet(100);
	TimerOn();
	note_state = -1;
	PWM_on();
    while(1)
    {
		note_tick();
		while(!TimerFlag);
		TimerFlag = 0;
    }
}
