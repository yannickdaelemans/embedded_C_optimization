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


