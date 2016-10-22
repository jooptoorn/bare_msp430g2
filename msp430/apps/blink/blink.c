/*
 * blink.c
 *
 *  Created on: Oct 22, 2016
 *      Author: Joop aan den Toorn
 */

#include "firmware/firmware.h"

void main(void){
	//test code to see if rest framework works
	GPIO_PORT1->DIR |= 0x41;					// Set P1.0 to output direction
	GPIO_PORT1->OUT =  0x01;					// Turn LED on

	while(true);
}


