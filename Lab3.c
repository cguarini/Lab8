/*
Title: UART DRIVER
Description: Uses the functions in UART.c to do basic terminal io
Authors: Chris Guarini cdg6285@rit.edu
Date: 1/23/2019

Some of the contents are obtained by the courtesy of the material provided by Freescale Semiconductor, Inc.
Copyright (c) 2014, Freescale Semiconductor, Inc.
All rights reserved.
*/

#include<stdio.h>
#include "MK64F12.h"
#include "uart.h"

//CONSTANTS
#define BAUD_RATE 9600      //default baud rate 
#define SYS_CLOCK 20485760 //default system clock (see DEFAULT_SYSTEM_CLOCK  in system_MK64F12.c)
#define CHAR_COUNT 10      //change this to modify the max. permissible length of a sentence
#define MAX_LENGTH 1			//Max character length


//Local functions
void put(char *ptr_str);

//LED.c functions
void LED_Init(void);
void turnOffAll(void);
void redOn(void);
void greenOn(void);
void blueOn(void);

void printPrompt(){
	put("Write Code Here: ");
}

void carriageReturn(){
	uart0_putchar('\n');
	uart0_putchar('\r');
}

void printUsage(){
	put(" 0 -> OFF; 1 -> RED; 2 -> BLUE; 3 -> GREEN");
	carriageReturn();
}


int main()
{
	
	uart3_init();
	LED_Init();
	
	int i = 0;
	
	printPrompt();
	
	char prev;
	
	while(1){
		char c = uart3_getchar();
		if(c == 0x0D){//carriage return
			i = 0;
			carriageReturn();
			if(prev == '0'){
				turnOffAll();
				put("ALL LEDS DEACTIVATED");
				carriageReturn();
			}
			else if(prev == '1'){
				redOn();
				put("RED LED ACTIVATED");
				carriageReturn();
			}
			else if(prev == '2'){
				blueOn();
				put("BLUE ACTIVATED");
				carriageReturn();
			}
			else if(prev == '3'){
				greenOn();
				put("GREEN ACTIVATED");
				carriageReturn();
			}
			else{
				printUsage();
			}
			
			printPrompt();
		}
		else if(i < MAX_LENGTH){
			uart3_putchar(c);
			i++;
		}
		prev = c;
		
	}

		
}  

void part1(){
	
		put("IDE: LAB 2 Demonstration by Chris Guarini (cdg6285)");    /*Transmit this through UART*/
	
}

void put(char *ptr_str)
{
	while(*ptr_str)
		uart3_putchar(*ptr_str++);
}