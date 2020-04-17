#include <msp430.h> 
#include "UART_communication/UART_communication.h"


/**
 * main.c
 */
int main(void)
{
    volatile unsigned int timer;
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
	init_GPIO();
	init_clocks();
	init_communication();
	init_timer();

	// For debugging purposes
	char num = 0x54;
	unsigned char *ptr = &num;
	while(1){
	    send_data(num, 2);
	    timer = TA0R;
	    num++;
	    while(num < 0x21 || num > 0x7D){
	        num = 0x22;
	    }
	}

	return 0;
}
