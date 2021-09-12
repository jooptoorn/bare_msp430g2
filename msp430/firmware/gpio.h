#ifndef _GPIO_
#define _GPIO_

#include "firmware.h"

typedef uint8_t GPIO_PIN;

#define GPIO_PIN0 (1 << 0)
#define GPIO_PIN1 (1 << 1)
#define GPIO_PIN2 (1 << 2)
#define GPIO_PIN3 (1 << 3)
#define GPIO_PIN4 (1 << 4)
#define GPIO_PIN5 (1 << 5)
#define GPIO_PIN6 (1 << 6)
#define GPIO_PIN7 (1 << 7)

#define GPIO_PORT_LOW 	(0   )
#define GPIO_PORT_HIGH	(0xff)

#define GPIO_INPUT		(0)
#define GPIO_OUTPUT		(1)

#define GPIO_EDGE_LOWTOHIGH (0)
#define GPIO_EDGE_HIGHTOLOW (1)

/**
 * sets the direction of an entire i/o port to in- or output
 * @param port the gpio port
 * @param dir false for input, true for output
 */
#define gpio_set_dir_port(port, dir) (port->DIR = dir)

#define gpio_set_dir_pin_input(port, pin) (port->DIR &= ~pin)
#define gpio_set_dir_pin_output(port, pin) (port->DIR |= pin)
/**
 * sets the direction of an i/o pin
 * @param port the gpio port the pin belongs to
 * @param pin the pin that is configured
 * @param dir false for input, true for otput
 */
#define gpio_set_dir_pin(port, pin,dir) (dir ? gpio_set_dir_pin_output(port,pin) : gpio_set_dir_pin_input(port,pin))

#define gpio_write_port_high(port) (port->OUT = 0xff)
#define gpio_write_port_low(port) (port->OUT = 0x0)
/**
 * write port high or low. Note that this changes pull up or down cfg when pin is input
 * @param port the GPIO port to write
 * @param val true for high, false for low
 */
#define gpio_write_port(port, val) (val ? gpio_write_port_high(port) : gpio_write_port_low(port))

#define gpio_write_pin_high(port, pin) (port->OUT |= pin)
#define gpio_write_pin_low(port, pin) (port->OUT &= ~pin)
/**
 * write value to pin
 * @param port port the pin belongs to
 * @param pin the gpio pin
 * @param val false for LOW, true for HIGH. Note that this changes pull up or down
 * behavior of pins that are configured as input.
 */
#define gpio_write_pin(port, pin, val) (val ? gpio_write_pin_high(port,pin) : gpio_write_pin_low(port,pin))

/**
 * toggle an IO pin. Note this changes pullup or -down cfg for input pins
 * @param port gpio port the pin belongs to
 * @param pin the pin to goggle
 */
#define gpio_toggle_pin(port, pin) (port->OUT ^=pin)

/**
 * reads an entire gpio port
 * @param port the port to read
 * @return content of the port per pin
 */
#define gpio_read_port(port) (port->IN)

/**
 * read a gpio pin.
 * @param port the gpio port
 * @param pin the gpio pin to read
 * @return true on HIGH, false on LOW
 */
#define gpio_read_pin(port, pin) (port->IN & pin)


/**
 * enable/disable gpio pullup
 * @param port the gpio port
 * @param pin the gpio pin
 * @param en true for enable, false for disable
 */
void gpio_set_pullup(GPIO_HW_STRUCT * const port, const GPIO_PIN pin, bool en);

/**
 * enable/disable gpio pulldown
 * @param port the gpio port
 * @param pin the gpio pin
 * @param en true for enable, false for disable
 */
void gpio_set_pulldown(GPIO_HW_STRUCT * const port, const GPIO_PIN pin, bool en);

void gpio_set_interrupt(GPIO_HW_STRUCT * const port, const GPIO_PIN pin, bool en, bool dir);

//implemented in assembly
void led_green_on(void);
void led_green_off(void);
void led_green_toggle(void);
void led_red_on(void);
void led_red_off(void);
void led_red_toggle(void);

#endif
