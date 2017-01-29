#include "gpio.h"

void gpio_set_dir_port(GPIO_HW_STRUCT * const port, bool dir){
	port->DIR = dir;
}

void gpio_set_dir_pin(GPIO_HW_STRUCT * const port, const GPIO_PIN pin, bool dir){
	if(dir)
		port->DIR |= pin;
	else
		port->DIR &= ~pin;
}

void gpio_write_port(GPIO_HW_STRUCT * const port, bool val){
	if(val)
	{
		port->OUT = GPIO_PORT_HIGH;
	}
	else
	{
		port->OUT = GPIO_PORT_LOW;
	}
}

void gpio_write_pin(GPIO_HW_STRUCT * const port, const GPIO_PIN pin, bool val){
	if(val)
	{
		port->OUT |= pin;
	}
	else
	{
		port->OUT &= ~pin;
	}
}

uint8_t gpio_read_port(GPIO_HW_STRUCT * const port){
	return port->IN;
}

bool gpio_read_pin(GPIO_HW_STRUCT * const port, const GPIO_PIN pin){
	return (port->IN & pin);
}

void gpio_set_pullup(GPIO_HW_STRUCT * const port, const GPIO_PIN pin, bool en){
	if(en){ //enable pullup, first set direction of OUT to HIGH
		port->OUT |= pin;
		port->REN |= pin;
	}
	else
		port->REN &= ~pin;
}

void gpio_set_pulldown(GPIO_HW_STRUCT * const port, const GPIO_PIN pin, bool en){
	if(en){ //enable pulldown, first set direction of OUT to LOW
		port->OUT &= ~pin;
		port->REN |= pin;
	}
	else
		port->REN &= ~pin;
}

void gpio_set_interrupt(GPIO_HW_STRUCT * const port, const GPIO_PIN pin, bool en, bool dir){
	if(en){ //enable the interrupt
		//disable interrupt to prevent accidental trigger
		port->IE &= ~pin;
		//first set edge
		if(dir) //interrupt on low-to-high
			port->IES |= pin;
		else	//interrupt on high-to-low
			port->IES &= ~pin;
		//then enable interrupt
		port->IE |= pin;
	} else { //disable the interrupt
		port->IE &= ~pin;
	}
}
