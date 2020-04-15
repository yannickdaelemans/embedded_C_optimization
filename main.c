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
	int num = 0x5500;
	unsigned char *ptr = &num;
	while(1){
	    send_data_pointer(ptr, 2);
	}

	return 0;
}
