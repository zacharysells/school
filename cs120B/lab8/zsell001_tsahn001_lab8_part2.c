/*	Partner 1 Name & E-mail: Zachary Sells zsell001@ucr.edu
 *	Partner 2 Name & E-mail: tsahn001@ucr.edu
 *	Lab Section: 23
 *	Assignment: Lab #8  Exercise #2
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

enum toggle_States {wait, wait_low, do_toggle} tog_state;
unsigned char toggle = 0x01;
unsigned char A2 = 0x00;
void toggle_tick()
{
	A2 = GetBit(~PINA, 2);
	
	switch(tog_state)
	{
		case -1:
			toggle = 0x01;
			tog_state = wait;
			break;
		case wait:
			if(A2)
			{
				tog_state = do_toggle;
			}
			else
			{
				tog_state = wait;
			}
			break;
		case do_toggle:
			tog_state = wait_low;
			break;
		case wait_low:
			if(A2)
			{
				tog_state = wait_low;
			}
			else
			{
				tog_state = wait;
			}
			break;
		default:
			tog_state = -1;
			break;
	}
	
	switch(tog_state)
	{
		case wait:
			break;
		case do_toggle:
			toggle = ((~toggle) & (0x01));
			break;
		case wait_low:
			break;
		default:
			break;
	}
	
}

enum freq_States {wait_inc_dec, wait_low_inc, inc, wait_low_dec, dec} freq_state;
unsigned char A0 = 0x00;
unsigned char A1 = 0x00;
unsigned char increment = 0x00;
unsigned char decrement = 0x00;
void freq_tick()
{
	A0 = GetBit(~PINA, 0);
	A1 = GetBit(~PINA, 1);
	switch(freq_state)
	{
		case -1:
			freq_state = wait_inc_dec;
			break;
		
		case wait_inc_dec:
			if(A0 && !A1)
			{
				freq_state = wait_low_inc;
			}
			else if(!A0 && A1)
			{
				freq_state = wait_low_dec;
			}
			else
			{
				freq_state = wait_inc_dec;
			}
			break;
			
		case wait_low_inc:
			if(!A0 && !A1)
			{
				freq_state = wait_low_inc;
			}
			else
			{
				freq_state = inc;
			}
			break;
		
		case inc:
			freq_state = wait_inc_dec;
			break;
		
		case wait_low_dec:
			if(!A0 && !A1)
			{
				freq_state = wait_low_dec;
			}
			else
			{
				freq_state = dec;
			}
			break;
			
		case dec:
			freq_state = wait_inc_dec;
			break;
		
		default:
			freq_state = -1;
			break;
	}
	
	switch(freq_state)
	{
		case wait_inc_dec:
			break;
		case wait_low_dec:
			break;
		case wait_low_inc:
			break;
		
		case inc:
			increment = 0x01;
			break;
		
		case dec:
			decrement = 0x01;
			break;
	}
}

enum comb_States {wait_for_req, comb_inc, comb_dec, off} comb_state;
double notes[8] = {261.63, 293.66, 329.63, 349.23, 392.00, 440.00, 493.88, 523.25};
unsigned char index = 0;
void comb_tick()
{
	switch(comb_state)
	{
		case -1:
			comb_state = wait_for_req;
			index = 3;
			break;
		case wait_for_req:
			if(toggle &&  !decrement && increment)
			{
				comb_state = comb_inc;
			}
			else if(toggle && decrement && !increment)
			{
				comb_state = comb_dec;
			}
			else if(!toggle)
			{
				comb_state = off;
			}
			else
			{
				comb_state = wait_for_req;
			}
			break;
			
		case comb_inc:
			comb_state = wait_for_req;
			break;
			
		case comb_dec:
			comb_state = wait_for_req;
			break;
			
		case off:
			if(!toggle)
			{
				comb_state = off;
			}
			else if(toggle)
			{
				comb_state = wait_for_req;
			}
			break;
			
		default:
			comb_state = -1;
			break;
	}
	
	switch(comb_state)
	{
		case wait_for_req:
			set_PWM(notes[index]);
			break;
		case comb_inc:
			if(index < 7)
			{
				++index;
			}
			increment = 0x00;
			break;
		case comb_dec:
			if(index > 0)
			{
				--index;
			}
			decrement = 0x00;
			break;
		case off:
			set_PWM(0);
			break;
	}
	PORTB = toggle;
}

int main(void)
{
	DDRB = 0xFF; PORTB = 0x00;
	DDRA = 0x00; PORTA = 0xFF;
	
	TimerSet(100);
	TimerOn();
	tog_state = -1;
	freq_state = -1;
	comb_state = -1;
	PWM_on();
    while(1)
    {
		toggle_tick();
		freq_tick();
		comb_tick();
		while(!TimerFlag);
		TimerFlag = 0;
    }
}
