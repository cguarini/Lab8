/* 
Title:   Lab1 - GPIO
Purpose:   Lab1
Name:   Chris Guarini - cdg6285
Date:   1/16/19
*/
#include "MK64F12.h"                    // Device header
void LED_Init(void){
	// Enable clocks on Ports B and E for LED timing
	SIM_SCGC5 |= SIM_SCGC5_PORTB_MASK; //Enable Port B Clock
	SIM_SCGC5 |= SIM_SCGC5_PORTE_MASK; //Enable Port E Clock
	
	 
	// Configure the Signal Multiplexer for GPIO
	//Assign LEDs
	PORTB_PCR22 = PORT_PCR_MUX(1);//Red
	PORTE_PCR26 = PORT_PCR_MUX(1);//Green
	PORTB_PCR21 = PORT_PCR_MUX(1);//Blue
	
	// Switch the GPIO pins to output mode
	GPIOB_PDDR = (1 << 22) | (1 << 21); //set Red and Blue
	GPIOE_PDDR = (1 << 26); //Set Green
	
	 
	// Turn off the LEDs
  GPIOB_PSOR = (1 << 22) | (1 << 21);// turn off red and blue
	GPIOE_PSOR = (1 << 26); //turn off green
}


void Button_Init(void){
	// Enable clock for Port C PTC6 button
	 	SIM_SCGC5 |= SIM_SCGC5_PORTC_MASK; //Enable Port C Clock
	
	// Configure the Mux for the button
	 PORTC_PCR6 = PORT_PCR_MUX(1);
	// Set the push button as an input
	GPIOC_PDDR = (0 << 6); //Set switch
	 
}

void turnOffAll(void){
	GPIOB_PSOR = (1UL << 21) | (1UL << 22);
	GPIOE_PSOR = 1UL << 26;
}

void wait(void){
	for(int i = 0; i < 2000000; i++);
}

void redOn(void){
	GPIOB_PCOR |= (1 << 22);// turn on red
}
void greenOn(void){
	GPIOE_PCOR |= (1 << 26); //turn on green
}

void blueOn(void) {
	GPIOB_PCOR |= (1 << 21);//Turn on blue
}


