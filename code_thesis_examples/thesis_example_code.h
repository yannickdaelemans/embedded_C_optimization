/*
 * thesis_example_code.h
 *
 *  Created on: 24 Nov 2020
 *      Author: Yannick
 */

#include "extra_function.h"
#include "../UART_communication/UART_communication.h"

/*
 * Example code of the use of chars and uint8_t
 * this code gives examples of sign extensions for
 * using 8 bit variables in stead of 16 bit examples
 */

unsigned int uintfun (unsigned int a, unsigned int b);

int intfun (int a, int b );

unsigned char uscfun (unsigned char a, unsigned char b);

signed char scfun (signed char a, signed char b);

signed char cfun (char a, char b);

int8_t sint8fun (int8_t a, int8_t b);

uint8_t usint8fun (uint8_t a, uint8_t b);

/*
 * Example code for the use of consts and
 * constant pointers
 * this has two sections, each gives titled
 * by a comment
 */

// Section constant values

int function_no_constants();

int function_constants();

int add(int num);

int addconst(int num);

// Section Constant pointers

int examplefunction();

int function_ptr_constants();

/*
 * Example code of the struct and struct-
 * packing/padding benefits
 */

void struct_example();


/*
 * Example code of the Byte to Word
 * conversion using either a union
 * or bitshifting
 */
int conversion_union(uint8_t MSB, uint8_t LSB);
int conversion_shift(uint8_t MSB, uint8_t LSB);

/*
 * Example code of the if-tester for
 * testing the placement of variables
 * in either ANd or OR logic
 */


 int if_tester_AND(char a, int b, int c, int d);

int if_tester_OR(char a, int b, int c, int d);

/*
 * example code compare 0
 */

int compare_to_zero(int num, int num2);

int compare_to_reg(int num, int num2);

int compare_to_num(int num, int num2);

int not_compare_to_zero(int num, int num2);

int bigger_to_zero(int num, int num2);

int smaller_to_zero(int num, int num2);

/*
 * Example code for the loops
 */



int while_function(int num, int num2, int num3);
int while_function_0(int num, int num2, int num3);
int while_function_const (int num, int num2);

void for_function(int num, int num2);

void for_function_0(int num, int num2);

int for_function_const(int num);

/*
 * Example code for the inlining of functions
 */

int inline_func(int num);

int inline_tester(int num);
/*
 * Example code for the use of registers
 */

int arguments_function(int num1, int num2, int num3, int num4, int num5);
