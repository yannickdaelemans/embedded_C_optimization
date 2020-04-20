/*
 * init.h
 *
 *  Created on: 20 Apr 2020
 *      Author: Yannick
 */

#include <msp430.h>
#include <stdio.h>
#include <stdint.h>

#ifndef INIT_INIT_H_
#define INIT_INIT_H_

//initialisations
void init_GPIO(void);
void init_clocks(void);
void init_communication(void);
void init_timer(void);

#endif /* INIT_INIT_H_ */
