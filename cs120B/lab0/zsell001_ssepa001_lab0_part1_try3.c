

/*	Partner 1 Name & E-mail: Zachary Sells zsell001@ucr.edu
 *	Partner 2 Name & E-mail: sam Sepasi ssepa001@ucr.edu
 *	Lab Section: 23
 *	Assignment: Lab 0  Part 1, Try 3 
 *	Exercise Description: [optional - include for your own benefit]
 *	
 *	I acknowledge all content contained herein, excluding
 *  template or example
 *	code, is my own original work.
 */
#include "rims.h"

unsigned long result;
unsigned char i;

void main()
{
    while(1)
    {
      result = 0;
      i = 1;
      while( i <= A)
      {
          result = result + i;
          puts("Iteration: ");
          puti(i);
          puts("\r\n");
          i = i + 1;
      }
      puts("Result: ");
      puti(result);
      puts("\r\n");
      B = result;
    }
}