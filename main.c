#include <msp430.h> 
#include "init/init.h"
#include "UART_communication/UART_communication.h"
#include "code_thesis_examples/thesis_example_code.h"

/*
 * Created by:  Yannick Daelemans
 *
 * This will test all the methods as discussed in the thesis.
 * It will time all the methods and will send this through to a PC over UART.
 */

/*
 * main.c
 */

char global_variable = 0b01010101;
unsigned int timer_begin;
unsigned int timer_end;


int main(void)
{

	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
	init_GPIO();
	init_clocks();
	init_communication();
	init_timer();


	return 0;
}

void __attribute__ ((noinline)) sending(unsigned int ID, unsigned int timer_begin, unsigned int timer_end){
    unsigned int time;
    time = timer_end - timer_begin;
    send_data(0xFFFF);
    send_data(ID);
    send_data(timer_begin);
    send_data(timer_end);
    send_data(time);
    send_data(0xFFFF);
}



/*
 * Tester of all timings that need to be timed
 */

void __attribute__ ((optimize("-O0"))) SXT_AND_tester(int amount){
    unsigned int ans;
    int anss;
    unsigned char chans;
    signed char schans;
    uint8_t bans;
    int8_t sbans;
    for(int i = 0; i < amount; i++){
        timer_begin = TA0R;
        ans = uintfun(15, 25);
        timer_end = TA0R;
        sending(1, timer_begin, timer_end);

        timer_begin = TA0R;
        anss = intfun(15, 25);
        timer_end = TA0R;
        sending(2, timer_begin, timer_end);

        timer_begin = TA0R;
        chans = uscfun('1', 'b');
        timer_end = TA0R;
        sending(3, timer_begin, timer_end);

        timer_begin = TA0R;
        schans = scfun(-12, 'b');
        timer_end = TA0R;
        sending(4, timer_begin, timer_end);

        timer_begin = TA0R;
        schans = cfun(12, 'b');
        timer_end = TA0R;
        sending(5, timer_begin, timer_end);

        timer_begin = TA0R;
        sbans = sint8fun(-12, 15);
        timer_end = TA0R;
        sending(6, timer_begin, timer_end);

        timer_begin = TA0R;
        bans = usint8fun(12, 15);
        timer_end = TA0R;
        sending(7, timer_begin, timer_end);

        for(int i = 0; i < 30; i++){
                    __no_operation();
                }
    }
}

void __attribute__ ((optimize("-O0"))) constants(int amount){
    unsigned int ans;
    int anss;
    unsigned char chans;
    signed char schans;
    uint8_t bans;
    int8_t sbans;
    for(int i = 0; i < amount; i++){
        timer_begin = TA0R;
        anss = function_no_constants();
        timer_end = TA0R;
        sending(8, timer_begin, timer_end);

        timer_begin = TA0R;
        anss = function_constants();
        timer_end = TA0R;
        sending(9, timer_begin, timer_end);

        timer_begin = TA0R;
        anss = add(10);
        timer_end = TA0R;
        sending(17, timer_begin, timer_end);

        timer_begin = TA0R;
        anss = addconst(10);
        timer_end = TA0R;
        sending(18, timer_begin, timer_end);

        timer_begin = TA0R;
        anss = examplefunction();
        timer_end = TA0R;
        sending(10, timer_begin, timer_end);

        timer_begin = TA0R;
        anss = examplefunctionpointer();
        timer_end = TA0R;
        sending(11, timer_begin, timer_end);

        for(int i = 0; i < 30; i++){
                    __no_operation();
                }
    }
}

void __attribute__ ((optimize("-O0"))) unions(int amount){
    unsigned int ans;
    int anss;
    unsigned char chans;
    signed char schans;
    uint8_t bans;
    int8_t sbans;
    for(int i = 0; i < amount; i++){
        timer_begin = TA0R;
        anss = conversion_union(12, 25);
        timer_end = TA0R;
        sending(12, timer_begin, timer_end);

        timer_begin = TA0R;
        anss = conversion_shift(22, 15);
        timer_end = TA0R;
        sending(13, timer_begin, timer_end);

        for(int i = 0; i < 30; i++){
                    __no_operation();
                }
    }
}

void __attribute__ ((optimize("-O0"))) compare_to(int amount){
    int anss;
    for(int i = 0; i < amount; i++){
        timer_begin = TA0R;
        anss = compare_to_zero(25, 22);
        timer_end = TA0R;
        sending(19, timer_begin, timer_end);

        timer_begin = TA0R;
        anss = compare_to_reg(25, 22);
        timer_end = TA0R;
        sending(20, timer_begin, timer_end);

        timer_begin = TA0R;
        anss = compare_to_num(25, 22);
        timer_end = TA0R;
        sending(21, timer_begin, timer_end);

        timer_begin = TA0R;
        anss = not_compare_to_zero(25, 22);
        timer_end = TA0R;
        sending(22, timer_begin, timer_end);

        timer_begin = TA0R;
        anss = bigger_to_zero(25, 22);
        timer_end = TA0R;
        sending(23, timer_begin, timer_end);

        timer_begin = TA0R;
        anss = smaller_to_zero(-25, -22);
        timer_end = TA0R;
        sending(24, timer_begin, timer_end);

        for(int i = 0; i < 30; i++){
                    __no_operation();
                }
    }
}

void __attribute__ ((optimize("-O0"))) loops(int amount){
    unsigned int ans;
    int anss;
    unsigned char chans;
    signed char schans;
    uint8_t bans;
    int8_t sbans;
    for(int i = 0; i < amount; i++){
        timer_begin = TA0R;
        anss = while_function(12, 20, 22);
        timer_end = TA0R;
        sending(14, timer_begin, timer_end);

        timer_begin = TA0R;
        anss = while_function_0(22, -2,  15);
        timer_end = TA0R;
        sending(15, timer_begin, timer_end);

        timer_begin = TA0R;
        anss = while_function_const(18, 6);
        timer_end = TA0R;
        sending(16, timer_begin, timer_end);

        for(int i = 0; i < 30; i++){
                    __no_operation();
                }
    }
}


void total_tester(int amount){
    SXT_AND_tester(amount);
    constants(amount);
    unions(amount);
    loops(amount);
    compare_to(amount);
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
      UCA1IFG &= ~UCRXIFG;
      char read_buf = UCA1RXBUF;
      if(read_buf == '1'){
          //testing_clock();
      }
      if(read_buf == 'S'){
          SXT_AND_tester(100);
      }
      __no_operation();
      if(read_buf == 'C'){
          constants(100);
      }
      __no_operation();
      if(read_buf == 'U'){
          unions(100);
      }
      __no_operation();
      if(read_buf == 'W'){
          loops(100);
      }
      __no_operation();
      if(read_buf == '0'){
          compare_to(100);
      }
      __no_operation();
      if(read_buf == 'T'){
          total_tester(100);
      }
      __no_operation();
      break;
    case USCI_UART_UCTXIFG: break;
    case USCI_UART_UCSTTIFG: break;
    case USCI_UART_UCTXCPTIFG: break;
  }
}
