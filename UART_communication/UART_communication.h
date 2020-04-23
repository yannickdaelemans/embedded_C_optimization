/*
 * UART_communication.h
 *
 *  Created on: 8 Apr 2020
 *      Author: Yannick
 */

#include <msp430.h>
#include <stdio.h>
#include <stdint.h>

#ifndef UART_COMMUNICATION_UART_COMMUNICATION_H_
#define UART_COMMUNICATION_UART_COMMUNICATION_H_

//methods
void send_data(unsigned int data);
void send_data_pointer(unsigned char *data_pointer, unsigned char data_bytes_length);


#endif /* UART_COMMUNICATION_UART_COMMUNICATION_H_ */
