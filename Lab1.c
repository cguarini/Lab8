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

int Lab1main(void){
	//Initialize any supporting variables
	 
	
	// Initialize buttons and LEDs
	LED_Init();
	Button_Init();
	
	int btnCount = 0;
	
	for(;;){
		//Turn on an LED configuration when button is held
		if(!(GPIOC_PDIR & (1 << 6))){ //Button press!
			if(btnCount == 0){//red then green then blue
				GPIOB_PCOR |= (1 << 22);// turn on red
				wait();
				turnOffAll();
				GPIOE_PCOR |= (1 << 26); //turn on green
				wait();
				turnOffAll();
				GPIOB_PCOR |= (1 << 21);//Turn on blue
				wait();
				turnOffAll();
			}
			else if(btnCount == 1){//cyan then magenta then yellow
				GPIOE_PCOR |= (1 << 26); //turn on green
				GPIOB_PCOR |= (1 << 21);//Turn on blue
				wait();
				turnOffAll();
				GPIOB_PCOR |= (1 << 22);// turn on red
				GPIOB_PCOR |= (1 << 21);//Turn on blue
				wait();
				turnOffAll();
				GPIOB_PCOR |= (1 << 22);// turn on red
				GPIOE_PCOR |= (1 << 26); //turn on green
				GPIOB_PSOR |= (1 << 21);//Turn off blue
				wait();
				turnOffAll();
			}
			else if(btnCount == 2){//white
				GPIOE_PCOR |= (1 << 26); //turn on green
				GPIOB_PCOR |= (1 << 21);//Turn on blue
				GPIOB_PCOR |= (1 << 22);// turn on red
				wait();
				turnOffAll();
				btnCount = -1;
			}
				btnCount++;
		}
		// Turn off LEDs on release of button
		else{
			turnOffAll();
		}
	}
}
