

/*	Partner 1 Name & E-mail: Zachary Sells zsell001@ucr.edu
 *	Partner 2 Name & E-mail: sam Sepasi ssepa001@ucr.edu
 *	Lab Section: 23
 *	Assignment: Lab 0  Part 1, Try 4
 *	Exercise Description: [optional - include for your own benefit]
 *	
 *	I acknowledge all content contained herein, excluding
 *  template or example
 *	code, is my own original work.
 */
#include "rims.h"



void main()
{
   const unsigned char numVoltages = 5;
   unsigned char voltages[5] = { 0, 24, 17, 12, 6};
   unsigned char highest;
   unsigned char i;
   while(1)
   {
       highest = voltages[0];
       for(i = 0; i < numVoltages; ++i)
       {
           puti(voltages[i]);
           puts(" ");

           if(voltages[i] > highest)
           {
               highest = voltages[i];
           }
       }
       puts("\r\n");
       B = highest;
   }
   
}