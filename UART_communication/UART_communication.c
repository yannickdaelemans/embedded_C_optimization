/*
 * UART_communication.c
 *
 *  Created on: 8 Apr 2020
 *      Author: Yannick
 */

#include "UART_communication.h"

void send_data(char data, unsigned int nr_of_bytes){
    /*while (nr_of_bytes){
        while(!(UCA1IFG&UCTXIFG)){
            int trash = UCA1RXBUF;
              UCA1TXBUF = data;                 // can only send through a single byte
              nr_of_bytes--;
        }
    }*/
    UCA1TXBUF = data;
}

void send_data_pointer(unsigned char *data_pointer, unsigned char data_bytes_length){
    while (data_bytes_length){
        while(!(UCA1IFG&UCTXIFG)){
              int trash = UCA1RXBUF;
              UCA1TXBUF = *data_pointer;                 // can only send through a single byte
              data_bytes_length--;
              data_pointer++;
        }
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
      UCA1TXBUF = 0x55; // for debugging reasons
      __no_operation();
      break;
    case USCI_UART_UCTXIFG: break;
    case USCI_UART_UCSTTIFG: break;
    case USCI_UART_UCTXCPTIFG: break;
  }
  UCA1IFG &= ~UCRXIFG;
}
