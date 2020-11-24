#include<stdio.h>
#include<stdint.h>

//int glob = 0;
//int func( const int nr);

/*
 * Example code of the use of chars and uint8_t
 * this code gives examples of sign extensions for
 * using 8 bit variables in stead of 16 bit examples
 */

 /*
unsigned int uintfun (unsigned int a, unsigned int b){
    return(a+b)<<1;
}

int intfun (int a, int b ){
    return(a+b)<<1;
}

unsigned char uscfun (unsigned char a, unsigned char b){
    return(a+b)<<1;
}

signed char scfun (signed char a,
  signed char b){
    return(a+b)<<1;
}

signed char cfun (char a, char b){
    return(a+b)<<1;
}

int8_t sint8fun (int8_t a, int8_t b){
    return(a+b)<<1;
}

uint8_t usint8fun (uint8_t a, uint8_t b){
    return(a+b)<<1;
}
*/

/*
 * Example code for the use of consts and
 * constant pointers
 * this has two sections, each gives titled
 * by a comment
 */

// Section constant values
/*
int ex = 100;

int func(int ex);

int examplefunction(){
    int new = func(ex);
    if(ex < 100){
        return new;
    }
    return ex;
}

const int ex_const = 100;

int examplefunctionconst(){
    int new = func(ex_const);
    if(ex_const < 100){
        return new;
    }
    return ex_const;
}


// Section Constant pointers
/*
const int examp = 10;

int funcp( const int * ptr);

int examplefunction(){
    int new = func(&examp);
    if( examp < 100){
        return new;
    }
    return examp;
}

const int* ex = &examp;

int examplefunctionpointer(){
    int new = funcp(ex);
    if( *ex < 100){
        return 12;
    }
    return *ex;
}

/*
 * Example code of the struct and struct-
 * packing/padding benefits
 */
 /*
struct{
    char id1;
    char id2;
    char percentage;
    int name;
    char c;
} struct_char;

struct{
    int name;
    char id1;
    char id2;
    char percentage;
    char c;
} struct_int;


void example() {
    struct_char.id1 = 0;
    struct_char.name = 0;
    struct_char.percentage = 0;
    struct_char.id2 = 0xF2;

    struct_int.id1 = 0;
    struct_int.name = 0;
    struct_int.percentage = 0;
    struct_int.id2 = 0xF2;
}


/*
 * Example code of the Byte to Word
 * conversion using either a union
 * or bitshifting
 */
 /*

 typedef struct {
    uint8_t LSB;
    uint8_t MSB;
} structure_word;

union{
    structure_word word_struct;
    uint16_t word;
} byte_to_word;

int conversion_union(uint8_t MSB,
uint8_t LSB){
    byte_to_word.word_struct.MSB =
      MSB;
    byte_to_word.word_struct.LSB =
      LSB;
    return byte_to_word.word;
}
int conversion_shift(uint8_t MSB,
uint8_t LSB){
    int new = (MSB << 8) | LSB;
    return new;
}

/*
 * Example code of the if-tester for
 * testing the placement of variables
 * in either ANd or OR logic
 */

/*
 int if_tester_AND(char a, int b,
  int c, int d){
    int x;
    if(a<12 && c <55 && b < 3){
        x = 5;
    } else{
        x = 17;
    }
    return x;
}

int if_tester_OR(char a,
   int b, int c, int d){
    int x;
    if(a < 12 || c < 55 || b < 3 ){
        x =5;
    } else{
        x = 17;
    }
    return x;
}

/*
 * Example code for the loops
 */

/*

int func( const int nr);

int while_function(int num,
          int num2, int num3){
    while (num != num3){
        num = func(num2);
    }
    return num;
}
int while_function_0(int num,
  int num2, int num3){
    while (num != 0){
        num = func(num2);
    }
    return num;
}

int while_function_const
  (int num){
    int num_cmp = 6;
    while (num_cmp != 20){
        num_cmp = func(num);
    }
    return num_cmp;
}

void for_function(int num, int num2){
    for(int i = 0; i != num; i++){
        func(num2);
    }
}

void for_function_0(int num, int num2){
    for(int i = num; i != 0; --i){
        func(num2);
    }
}

int for_function_const(int num){

    for (int num_cmp = 0; num_cmp != 20; num_cmp ++){
        num = func(num);
    }
    return num;
}


/*
 * Example code for the inlining of functions
 */
/*
int inline_func(int num){
    if(num < 100){
        return num + 50;
    } else {
        return num - 40 ;
    }
}

int inline_tester(int num){
    int new = inline_func(num);
    return new;
}

/*
 * Example code for the use of registers
 */
/*
int arguments(int num1, int num2, int num3, int num4, int num5){
    return num1+num2-num3+num4-num5;
}
*/
