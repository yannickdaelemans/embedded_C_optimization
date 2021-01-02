/*
 * extra_function.c
 *
 *  Created on: 26 Nov 2020
 *      Author: Yannick
 */

#include "extra_function.h"

int glob_nr = 0;

int func_consts(int ex){
    return glob_nr + ex;
}

int func_consts_ptr( const int * ptr){
    return glob_nr + *ptr;
}

int func_while_const( const int nr){
    return nr + 2;
}

void for_func(const int nr){
    glob_nr += nr;
}
