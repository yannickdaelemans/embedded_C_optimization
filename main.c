#include <msp430.h> 
#include "UART_communication/UART_communication.h"


/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
	init_GPIO();
	init_clocks();
	init_communication();

	// For debugging purposes
	while(1){
	    send_data(0x00FF);
	}

	return 0;
}
