#include<stdio.h>
#include "MK64F12.h"
#include "uart.h"

#define MAX_LENGTH (40)

//Initialize UART0 and UART3
void initializeUarts(void){
	uart0_init();
	uart3_init();
}

void carriageReturn0(){
	uart0_putchar('\n');
	uart0_putchar('\r');
}

void carriageReturn3(){
	uart3_putchar('\n');
	uart3_putchar('\r');
}

void getPhoneChat(void){
	
	int i = 0;
	char str[MAX_LENGTH];
	
	char c = 0;
	
	uart3_put("Enter message: ");
	
	while(1){
		c = uart3_getchar();
		if(c == 0x0D){//carriage return
			i = 0;
			carriageReturn3();
			uart0_put("Them: ");
			uart0_put(str + 0);
			carriageReturn3();
			uart3_put("You: ");
			uart3_put(str + 0);
			carriageReturn0();
		}
		else if(i < MAX_LENGTH){
			uart3_putchar(c);
			i++;
		}
		break;
	}
}

void getComputerChat(void){
	
	int i = 0;
	char str[MAX_LENGTH];
	
	char c = 0;
	
	uart3_put("Enter message: ");
	
	while(1){
		c = uart0_getchar();
		if(c == 0x0D){//carriage return
			i = 0;
			carriageReturn3();
			uart3_put("Them: ");
			uart3_put(str + 0);
			carriageReturn3();
			uart0_put("Message Sent!");
			carriageReturn0();
		}
		else if(i < MAX_LENGTH){
			uart0_putchar(c);
			i++;
		}
		break;
	}
}

//Run the chat room
int chat_main(){
	
	initializeUarts();
	
	uart0_put("Welcome to IDE Chat! 40 character limit, the phone sends the message first.");
	uart3_put("Welcome to IDE Chat! 40 character limit, the phone sends the message first.");
	
	//Program loop
	while(1){
		uart3_put("This is Chris'");
		//for(int i = 0; i < 2000000; i++);
		//getPhoneChat();
		//getComputerChat();
	}
	
}