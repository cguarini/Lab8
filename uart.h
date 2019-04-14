//CONSTANTS
#define BAUD_RATE 9600      //default baud rate 
#define SYS_CLOCK 20485760 //default system clock (see DEFAULT_SYSTEM_CLOCK  in system_MK64F12.c)

//UART 0 FUNCTIONS
void uart0_put(char *ptr_str);
void uart0_init(void);
uint8_t uart0_getchar(void);
void uart0_putchar(char ch);

//UART 3 FUNCTIONS
void uart3_put(char *ptr_str);
void uart3_init(void);
uint8_t uart3_getchar(void);
void uart3_putchar(char ch);
