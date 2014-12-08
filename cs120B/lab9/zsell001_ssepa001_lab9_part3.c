/*	Partner 1 Name & E-mail: Zachary Sells zsell001@ucr.edu
 *	Partner 2 Name & E-mail: Sam Sepasi ssepa001@ucr.edu
 *	Lab Section: 23
 *	Assignment: Lab #9  Exercise #3
 *	Exercise Description: [optional - include for your own benefit]
 *	
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */

#include <avr/io.h>
#include <bit.h>
#include <io.c>
#include <timer.h>
#include <stdio.h>


//--------Find GCD function --------------------------------------------------
unsigned long int findGCD(unsigned long int a, unsigned long int b)
{
	unsigned long int c;
	while(1){
		c = a%b;
		if(c==0){return b;}
		a = b;
b = c;
	}
	return 0;
}
//--------End find GCD function ----------------------------------------------

//--------Task scheduler data structure---------------------------------------
// Struct for Tasks represent a running process in our simple real-time operating system.
typedef struct _task {
	/*Tasks should have members that include: state, period,
		a measurement of elapsed time, and a function pointer.*/
	signed char state; //Task's current state
	unsigned long int period; //Task period
	unsigned long int elapsedTime; //Time elapsed since last task tick
	int (*TickFct)(int); //Task tick function
} task;

//--------End Task scheduler data structure-----------------------------------


//--------Shared Variables----------------------------------------------------
unsigned char SM2_output = 0x00;
unsigned char SM3_output = 0x00;
unsigned char pause = 0;

//--------End Shared Variables------------------------------------------------
unsigned char out = 0x00;
unsigned char i = 0;
unsigned char fin = 0x00;
enum key_State {one,onew, two,twow, three,threew, four,fourw, tim} keystate;	
unsigned char message[] = "Congradulations!"; //16;
void tick_KeypadKey() {

	switch (keystate){
		case -1:
			keystate = one;
			i = 0;
			out = ' ';
			break;
		case one:
			keystate = onew;
			PORTC = 0xEF;
			break;
		case onew:
			keystate = two;
			break;
		case two:
			keystate = twow;
			PORTC = 0xDF;
			break;
		case twow:
			
			keystate = three;
			break;
		case three:
			keystate = threew;
			PORTC = 0xBF;
			break;
		case threew:
			
			keystate = four;
			break;
		case four:
			PORTC = 0x7F;
			keystate = fourw;
			break;
		case fourw:
			keystate = tim;
			break;
		case tim:
			keystate = one;
			break;
		default:
			keystate = one;
			break;
	}			
		asm("nop");
		
		unsigned char b0 = GetBit(~PINC,0);
		unsigned char b1 = GetBit(~PINC,1);
		unsigned char b2 = GetBit(~PINC,2);
		unsigned char b3 = GetBit(~PINC,3);
		switch(keystate){
			case onew:
				++i;
				if(b0){
					out = '1';
				}					
				else if (b1){
					out = '4';
				}					
				else if (b2){
					out = '7';
				}					
				else if (b3){
					out = '*';
				}
			
				break;
			case twow:
				++i;
				if(b0){
					out = '2';
				}
				else if (b1){
					out = '5';
				}
				else if (b2){
					out = '8';
				}
				else if (b3){
					out = '0';
				}
				
				break;	
			case threew:
				++i;
				if(b0){
					out = '3';
				}
				else if (b1){
					out = '6';
				}
				else if (b2){
					out = '9';
				}
				else if (b3){
					out = '#';
				}
				
				
				break;
			case fourw:
				if(b0){
					out = 'A';
				}
				else if (b1){
					out = 'B';
				}
				else if (b2){
					out = 'C';
				}
				else if (b3){
					out = 'D';
				}
			
				break;
			case tim:
				LCD_Cursor(1);
				LCD_WriteData(out);
				break;
				
			default:
				break;
		}
}		


int main(void)
{
	DDRB = 0xFF; PORTB = 0x00; // PORTB set to output, outputs init 0s
	DDRC = 0xF0; PORTC = 0x0F; // PC7..4 outputs init 0s, PC3..0 inputs init 1s
	DDRA = 0xFF; PORTA = 0x00;
	DDRD = 0xFF; PORTD = 0x00;
	LCD_init();
	unsigned long int SMTick1_calc = 10;
	unsigned long int tmpGCD = 1;
	unsigned long int GCD = tmpGCD;
	unsigned long int SMTick1_period = SMTick1_calc/GCD;
	static task task1;
	task *tasks[] = { &task1};
	const unsigned short numTasks = sizeof(tasks)/sizeof(task*);
	// Task 1
	task1.state = -1;//Task initial state.
	task1.period = SMTick1_period;//Task Period.
	task1.elapsedTime = SMTick1_period;//Task current elapsed time.
	task1.TickFct = &tick_KeypadKey;//Function pointer for the tick.
	
	// Set the timer and turn it on
	TimerSet(GCD);
	TimerOn();

	unsigned short i; // Scheduler for-loop iterator
	while(1) {
		// Scheduler code
		for ( i = 0; i < numTasks; i++ ) {
			// Task is ready to tick
			if ( tasks[i]->elapsedTime == tasks[i]->period ) {
				// Setting next state for task
				tasks[i]->state = tasks[i]->TickFct(tasks[i]->state);
				// Reset the elapsed time for next tick.
				tasks[i]->elapsedTime = 0;
			}
			tasks[i]->elapsedTime += 1;
		}
		while(!TimerFlag);
		TimerFlag = 0;
	}

	// Error: Program should not exit!
	return 0;
}

	