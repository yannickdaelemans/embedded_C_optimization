#include <msp430.h> 
#include "init/init.h"
#include "UART_communication/UART_communication.h"


/**
 * main.c
 */

char global_variable = 0b01010101;

int main(void)
{

	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
	init_GPIO();
	init_clocks();
	init_communication();
	init_timer();


	return 0;
}

void sending(unsigned int ID, unsigned int timer_begin, unsigned int timer_end){
    unsigned int time;
    time = timer_end - timer_begin;
    send_data(ID);
    send_data(timer_begin);
    send_data(timer_end);
    send_data(time);
    send_data(0x0000);
}

int testing_clock_call_function(int* pi, int* pi2){
    char bits = 0b11110000;
    bits ^= bits >> 3;
    bits = bits ^ global_variable;

    int var = *pi + *pi2;
    return var+bits;
}

void testing_clock(){
    unsigned int ID = 0x0000;
    unsigned int timer_begin = TA0R;
    unsigned int timer_end;
    // start with addressing some pins
    //declare all the pins
    //Control Ports
    P3DIR |= 0b00000000; // make port read only

    // make some pins write
    P1DIR |= 0b11111000;
    P8DIR |= 0b11110000;
    P9DIR |= 0b01111111;
    P2DIR |= 0xFF;

    char num = 0x80;
    P2OUT |= num;

    int number = 10;
    int* pi = &number;
    int number2 = 20;
    int* pi2 = &number2;

    int result = testing_clock_call_function(pi, pi2);
    for( int i = 0; i < 3; i++){
        if (result > 100){
            do{
                result = result - 1;
            } while(result > 100);
        }else{
            for(int i = 0; i < 5; ++i){
                result = result + i;
            }
        }
    }
    timer_end = TA0R;
    sending(ID, timer_begin, timer_end);
}


void testing(){
    unsigned int ID = 0x0000;
    unsigned int timer_begin;
    unsigned int timer_end;
    unsigned int time;
    int amount = 0;
    // For debugging purposes
    timer_begin = TA0R;
    for(int i = 0; i <10; i++){
        for(int i = 0; i < 20000; i ++){
            __no_operation();
        }
    }

    timer_end = TA0R;
    time = timer_end - timer_begin;
    send_data(ID);
    send_data(timer_begin);
    send_data(timer_end);
    send_data(time);
    send_data(0x0000);
    amount++;
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
          testing_clock();
      }
      __no_operation();
      break;
    case USCI_UART_UCTXIFG: break;
    case USCI_UART_UCSTTIFG: break;
    case USCI_UART_UCTXCPTIFG: break;
  }
}
