/*
 * blink.c
 *
 *  Created on: Oct 22, 2016
 *      Author: Joop aan den Toorn
 */

#include "firmware/firmware.h"

__attribute__((__interrupt__))
void  wdog_handler(void){
	static uint16_t cnt = 0;
	if(!(cnt++ %16))
	{
		if(GPIO_PORT1->OUT & 0x40)
			GPIO_PORT1->OUT &=  ~0x40;
		else
			GPIO_PORT1->OUT |=  0x40;
	}
}

void main(void){
	//enable interrupts
	INTERRUPTS_EN;
	//test code to see if rest framework works
	GPIO_PORT1->DIR |= 0x41;					// Set P1.0 to output direction
	//clear leds
	GPIO_PORT1->OUT = 0;

	//enable watchdog
	wdt_config(WDT_CLK_DIV_32768 | WDT_MODE_ITVL);

	//enable interrupt
	*IE1 |= WDTIE;
	while(1);
}

