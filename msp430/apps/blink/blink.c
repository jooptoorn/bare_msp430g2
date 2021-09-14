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
	//multiples of 16 amount to ~2Hz
	if(!(cnt++ %16))
	{	//do stuff
		//toggle both LEDs
		led_green_toggle();
		led_red_toggle();

	}
}

__attribute__((__interrupt__))
void io1_handler(void){
	//determine source of interrupt
	uint8_t src = GPIO_PORT1->IFG;
	//clear register
	GPIO_PORT1->IFG = 0;
	//do stuff
	if(src & GPIO_PIN3){
		//check current status and invert
		// gpio_toggle_pin(GPIO_PORT1, GPIO_PIN6);
	}
}

void main(void){
	//enable interrupts
	INTERRUPTS_EN;
	//set direction of LEDs to output
	gpio_set_dir_pin(GPIO_PORT1, GPIO_PIN0 | GPIO_PIN6, GPIO_OUTPUT);
	//set leds
	led_green_on();
	led_red_off();
	//set direction of switches to input
	gpio_set_dir_pin(GPIO_PORT1, GPIO_PIN3, GPIO_INPUT);
	//enable pullup switch
	gpio_set_pullup(GPIO_PORT1, GPIO_PIN3, true);
	//set watchdog to interval mode
	wdt_config(WDT_CLK_DIV_32768 | WDT_MODE_ITVL);
	//enable interrupts
	*IE1 |= WDTIE;
	gpio_set_interrupt(GPIO_PORT1, GPIO_PIN3, true, GPIO_EDGE_HIGHTOLOW);

	while(1){
		//wdt_feed();
	}
}

