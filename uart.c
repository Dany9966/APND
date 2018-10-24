/*
 * uart.c
 *
 * Created: 10/23/2018 2:03:03 PM
 *  Author: dspuser
 */ 
#include <avr/io.h>
#define DIVISOR 7

void init() {
	// set directions
	DDRD = DDRD | 2;
	DDRD = DDRD & ~1;
	
	// set baud rate
	// UCSRC = UCSRC & 0x00;
	UBRRH = (DIVISOR >> 8) & 0xFF;
	UBRRL = DIVISOR & 0xFF;
	
	// enable receiver & transmitter
	// UCSRA = UCSRA & 0xFC;
	UCSRB |=  (1<<RXEN)|(1<<TXEN);
	// UCSRC =(1 << URSEL);
	UCSRC |= (1<<URSEL);
	UCSRC |= (1<<URSEL)|(3<<UCSZ0);

}

void transmit(unsigned char data) {
	while(!(UCSRA | (1 << UDRE))){
		;
	}
	
	UDR = data;
}