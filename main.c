#include <msp430.h> 
#include "init/init.h"
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
	init_timer();


	return 0;
}

void testing(){
    unsigned int timer_begin;
    unsigned int timer_end;
    unsigned int time;
    int amount = 0;
    // For debugging purposes
    char num = 0x54;
    //unsigned char *ptr = &num;
    while(amount < 8){
        send_data(num, 2);
        timer_begin = TA0R;
        num++;
        for(int i = 0; i < 60; i ++){
            for(int i = 0; i < 20000; i ++){
                __no_operation();
            }
        }
        while(num < 0x21 || num > 0x7D){
            num = 0x22;
        }
        timer_end = TA0R;
        time = timer_end - timer_begin;
        amount++;
    }


}

#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
#pragma vector=USCI_A1_VECTOR
__interrupt void USCI_A1_ISR(void)
#elif defined(__GNUC__)
void __attribute__ ((interrupt(USCI_A1_VECTOR))) USCI_A1_ISR (void)
#else
#error Compiler not supported!
#endif
{
  switch(__even_in_range(UCA1IV, USCI_UART_UCTXCPTIFG))
  {
    case USCI_NONE: break;
    case USCI_UART_UCRXIFG:
      while(!(UCA1IFG&UCTXIFG));
      UCA1IFG &= ~UCRXIFG;
      char read_buf = UCA1RXBUF;
      if(read_buf == '1'){
          testing();
      }
      __no_operation();
      break;
    case USCI_UART_UCTXIFG: break;
    case USCI_UART_UCSTTIFG: break;
    case USCI_UART_UCTXCPTIFG: break;
  }
}
