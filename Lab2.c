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
#define BAUD_RATE 9600      //default baud rate 
#define SYS_CLOCK 20485760 //default system clock (see DEFAULT_SYSTEM_CLOCK  in system_MK64F12.c)
#define CHAR_COUNT 10      //change this to modify the max. permissible length of a sentence
#define MAX_LENGTH 8			//Max character length

void put(char *ptr_str);
void uart_init(void);
uint8_t uart_getchar(void);
void uart_putchar(char ch);

void printPrompt(){
	put("Write sentence here: ");
}

int main()
{
	
	uart_init();
	
	int i = 0;
	
	printPrompt();
	
	while(1){
		char c = uart_getchar();
		if(c == 0x0D){//carriage return
			i = 0;
			uart_putchar('\n');
			uart_putchar('\r');
			printPrompt();
		}
		else if(i < MAX_LENGTH){
			uart_putchar(c);
			i++;
		}
		
	}

		
}  

void part1(){
	
		put("IDE: LAB 2 Demonstration by Chris Guarini (cdg6285)");    /*Transmit this through UART*/
	
}

void put(char *ptr_str)
{
	while(*ptr_str)
		uart_putchar(*ptr_str++);
}