/*
 * init.c
 *
 *  Created on: 20 Apr 2020
 *      Author: Yannick
 */

#include "init.h"

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
    // Clock System Setup
    CSCTL0_H = CSKEY >> 8;                    // Unlock CS registers
    CSCTL1 = DCOFSEL_6;                       // Set DCO to 8MHz
    CSCTL2 = SELA__LFXTCLK | SELS__DCOCLK | SELM__DCOCLK;  // Set SMCLK = MCLK = DCO
                                                // ACLK = VLOCLK
    CSCTL3 = DIVA__1 | DIVS__1 | DIVM__1;     // Set all dividers to 1

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
   UCA1IE |= UCRXIE;                         // Enable USCI_A1 RX interrupt

   __bis_SR_register(GIE);       // Enter LPM3, interrupts enabled --> writing to status register
   __no_operation();
}

void init_timer(void){
    TA0CTL = TASSEL__SMCLK | MC__CONTINOUS;   // SMCLK, continuous mode
}
