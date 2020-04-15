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
	uint8_t num = 0x54;
	unsigned char *ptr = &num;
	while(1){
	    send_data(num, 2);
	    num++;
	}

	return 0;
}
