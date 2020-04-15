/*
 * UART_communication.c
 *
 *  Created on: 8 Apr 2020
 *      Author: Yannick
 */

#include "UART_communication.h"

void init_GPIO(void){
    //WDTCTL = WDTPW | WDTHOLD;                 // Stop Watchdog

    // Configure GPIO
    P3SEL0 |= BIT4 + BIT5;                    // eUSCI_A1 UART
    P3SEL1 &= ~(BIT4 + BIT5);                 // eUSCI_A1 UART
    PJSEL0 |= BIT4 | BIT5;                    // Configure XT1 pins for ACLK

    // Disable the GPIO power-on default high-impedance mode to activate
    // previously configured port settings
    PM5CTL0 &= ~LOCKLPM5;
}

void init_clocks (void){

    // Configure one FRAM waitstate as required by the device datasheet for MCLK
    // operation beyond 8MHz _before_ configuring the clock system.
    FRCTL0 = FRCTLPW | NWAITS_1;

    // Clock System Setup
    CSCTL0_H = CSKEY_H;                     // Unlock CS registers
    CSCTL1 = DCOFSEL_0;                     // Set DCO to 1MHz
    // Set SMCLK = MCLK = DCO, ACLK = LFXTCLK (VLOCLK if unavailable)
    CSCTL2 = SELA__LFXTCLK | SELS__DCOCLK | SELM__DCOCLK;
    // Per Device Errata set divider to 4 before changing frequency to
    // prevent out of spec operation from overshoot transient
    CSCTL3 = DIVA__4 | DIVS__4 | DIVM__4;   // Set all corresponding clk sources to divide by 4 for errata
    CSCTL1 = DCOFSEL_4 | DCORSEL;           // Set DCO to 16MHz
    // Delay by ~10us to let DCO settle. 60 cycles = 20 cycles buffer + (10us / (1/4MHz))
    __delay_cycles(60);
    CSCTL3 = DIVA__1 | DIVS__1 | DIVM__1;   // Set all dividers to 1 for 16MHz operation

    CSCTL4 &= ~LFXTOFF;
    do
    {
    CSCTL5 &= ~LFXTOFFG;                      // Clear XT1 fault flag
    SFRIFG1 &= ~OFIFG;
    }while (SFRIFG1&OFIFG);                   // Test oscillator fault flag

    CSCTL0_H = 0;                             // Lock CS registerss
}

void init_communication(void)
{
   // Configure USCI_A1 for UART mode
   UCA1CTLW0 = UCSWRST;                      // Put eUSCI in reset
   UCA1CTLW0 |= UCSSEL__ACLK;                // CLK = ACLK
   UCA1BR0 = 3;                              // 9600 baud
   UCA1MCTLW |= 0x5300;                      // 32768/9600 - INT(32768/9600)=0.41
   // UCBRSx value = 0x53 (See UG)
   UCA1BR1 = 0;
   UCA1CTL1 &= ~UCSWRST;                     // Initialize eUSCI
   UCA1IE |= UCRXIE;                         // Enable USCI_A0 RX interrupt

   __bis_SR_register(LPM3_bits | GIE);       // Enter LPM3, interrupts enabled --> writing to status register
   __no_operation();
}

void send_data(uint16_t data, unsigned int nr_of_bytes){
    while (nr_of_bytes){
        while(!(UCA1IFG&UCTXIFG)){
              UCA1TXBUF = 0x55;                 // can only send through a single byte
              nr_of_bytes--;
        }
    }
}

void send_data_pointer(unsigned char *data_pointer, unsigned char data_bytes_length){
    while (data_bytes_length){
        while(!(UCA1IFG&UCTXIFG)){
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
}
