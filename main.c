/*
 * APND.c
 *
 * Created: 10/23/2018 2:02:16 PM
 * Author : dspuser
 */ 


#define F_CPU 14745600UL

#include <avr/io.h>
#include <util/delay.h> 
#include "uart.h"



int main(void)
{
	init();
	
    /* Replace with your application code */
    while (1) 
    {
		_delay_ms(1000);
		transmit('a');
		_delay_ms(500);
    }
}

