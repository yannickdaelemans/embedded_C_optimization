/*
 * UART_communication.c
 *
 *  Created on: 8 Apr 2020
 *      Author: Yannick
 */

#include "UART_communication.h"

void send_data(unsigned int data){
    /*while (nr_of_bytes){
        while(!(UCA1IFG&UCTXIFG)){
            int trash = UCA1RXBUF;
              UCA1TXBUF = data;                 // can only send through a single byte
              nr_of_bytes--;
        }
    }*/
    char c1 = data >> 8;
    char c2 = data & 0x00ff;
    while(!(UCA1IFG & UCTXIFG));
    UCA1TXBUF = c2;
    __no_operation();
    while(!(UCA1IFG & UCTXIFG));
    UCA1TXBUF = c1;
    while(UCA1STATW & UCBUSY);
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


