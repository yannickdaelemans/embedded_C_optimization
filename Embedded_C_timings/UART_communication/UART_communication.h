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

int init_communication(void);
void send_data(uint16_t data);


#endif /* UART_COMMUNICATION_UART_COMMUNICATION_H_ */
