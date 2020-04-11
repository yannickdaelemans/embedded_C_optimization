/*
 * UART_communication.c
 *
 *  Created on: 8 Apr 2020
 *      Author: Yannick
 */

#include "UART_communication.h"

int init_communication(void)
{
  //WDTCTL = WDTPW | WDTHOLD;                 // Stop Watchdog

    // Configure GPIO
      P3SEL0 |= BIT4 + BIT5;                    // eUSCI_A1 UART
      P3SEL1 &= ~(BIT4 + BIT5);                 // eUSCI_A1 UART
      PJSEL0 |= BIT4 | BIT5;                    // Configure XT1 pins for ACLK

      // Disable the GPIO power-on default high-impedance mode to activate
      // previously configured port settings
      PM5CTL0 &= ~LOCKLPM5;

      // XT1 Setup
      CSCTL0_H = CSKEY >> 8; // Unlock CS registers
      CSCTL2 = SELA__LFXTCLK | SELS__DCOCLK | SELM__DCOCLK;
      CSCTL3 = DIVA__1 | DIVS__1 | DIVM__1; // Set all dividers
      CSCTL4 &= ~LFXTOFF;
      do
      {
      CSCTL5 &= ~LFXTOFFG; // Clear XT1 fault flag
      SFRIFG1 &= ~OFIFG;
      }while (SFRIFG1&OFIFG); // Test oscillator fault flag
      CSCTL0_H = 0; // Lock CS registers

      // Configure USCI_A1 for UART mode
      UCA1CTLW0 = UCSWRST; // Put eUSCI in reset
      UCA1CTLW0 |= UCSSEL__ACLK; // CLK = ACLK
      UCA1BR0 = 3; // 9600 baud
      UCA1MCTLW |= 0x5300; // 32768/9600 - INT(32768/9600)=0.41
      // UCBRSx value = 0x53 (See UG)
      UCA1BR1 = 0;
      UCA1CTL1 &= ~UCSWRST; // Initialize eUSCI
      UCA1IE |= UCRXIE; // Enable USCI_A0 RX interrupt

      __bis_SR_register(LPM3_bits | GIE); // Enter LPM3, interrupts enabled
      __no_operation();

      while (1){
          while(!(UCA1IFG&UCTXIFG)){
                UCA1TXBUF = 0x55;
                __no_operation();
          }
      }

}

void send_data(uint16_t data){
    int i = 0;
    while (i != 1){
        while(!(UCA1IFG&UCTXIFG)){
              UCA1TXBUF = 0x55;         // can only send through a single byte
              i = 1;
        }
    }
}

#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)            // 04/07/2020
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
      /*while(!(UCA1IFG&UCTXIFG));
      UCA1TXBUF = 0x55;
      __no_operation();*/
      break;
    case USCI_UART_UCTXIFG: break;
    case USCI_UART_UCSTTIFG: break;
    case USCI_UART_UCTXCPTIFG: break;
  }
}
