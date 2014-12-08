/*	Partner 1 Name & E-mail: Zachary Sells zsell001@ucr.edu
 *	Partner 2 Name & E-mail: Sam Sepasi ssepa001@ucr.edu
 *	Lab Section: 23
 *	Assignment: Lab #9  Exercise #2
 *	Exercise Description: [optional - include for your own benefit]
 *	
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */

#include <avr/io.h>
#include <bit.h>
#include <timer.h>
#include <stdio.h>
#include <string.h>
#include <io.c>


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

enum key_State {wait, one, two, three, four} keystate;	
enum LCD_State {next, shift} lcdstate;
int start_index = 0;
int end_index = 1;
int cursor = 16;
unsigned char message[] = "CS120B is Legend... wait for it DARY!";
unsigned char sub_message[100];

//16 chars on LCD
	
tick_LCD (){
	
	switch(lcdstate){
		case -1 :
			start_index = 1;
			end_index = 1;
			cursor = 16;
			lcdstate = next;
			break;
		case next:
			if(cursor < 1)
			{
				lcdstate = shift;
			}
			break;
		case shift:
			if(start_index > 36)
			{
				start_index = 1;
				end_index = 1;
				cursor = 16;
				lcdstate = next;
			}
			break;
		default:
			break;
	}
	switch(lcdstate){
		case next:
			strncpy(sub_message, message, end_index);
			LCD_DisplayString(cursor, sub_message);
			++end_index;
			--cursor;
			break;
		case shift:
			strncpy(sub_message, message + start_index, end_index);
			LCD_DisplayString(cursor, sub_message);
			++start_index;
			//++end_index;
			break;
		default:
			break;
	}
	//LCD_ClearScreen();
	
}


int main(void)
{
	DDRA = 0xFF; PORTA = 0x00;
	DDRD = 0xFF; PORTD = 0x00;
	LCD_init();
	
	unsigned long int SMTick1_calc = 150;
	
	unsigned long int tmpGCD = 1;
	//tmpGCD = findGCD(SMTick1_calc, SMTick2_calc);
	unsigned long int GCD = tmpGCD;
	unsigned long int SMTick1_period = SMTick1_calc/GCD;
	//unsigned long int SMTick2_period = SMTick2_calc/GCD;

	static task task1;
	task *tasks[] = { &task1};
	const unsigned short numTasks = sizeof(tasks)/sizeof(task*);
	// Task 1
	task1.state = -1;//Task initial state.
	task1.period = SMTick1_period;//Task Period.
	task1.elapsedTime = SMTick1_period;//Task current elapsed time.
	task1.TickFct = &tick_LCD;//Function pointer for the tick.
	//task2.state = -1;//Task initial state.
	//task2.period = SMTick2_period;//Task Period.
	//task2.elapsedTime = SMTick2_period;//Task current elapsed time.
	//task2.TickFct = &tick_LCD;//Function pointer for the tick.
	
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
