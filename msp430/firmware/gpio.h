#ifndef _GPIO_
#define _GPIO_

#include "firmware.h"

typedef uint8_t GPIO_PIN;

#define GPIO_PIN0 1 << 0
#define GPIO_PIN1 1 << 1
#define GPIO_PIN2 1 << 2
#define GPIO_PIN3 1 << 3
#define GPIO_PIN4 1 << 4
#define GPIO_PIN5 1 << 5
#define GPIO_PIN6 1 << 6
#define GPIO_PIN7 1 << 7

#define GPIO_PORT_LOW 	0
#define GPIO_PORT_HIGH	0xff

#define GPIO_INPUT		0
#define GPIO_OUTPUT		1

#define GPIO_EDGE_LOWTOHIGH 0
#define GPIO_EDGE_HIGHTOLOW 1

/**
 * sets the direction of an entire i/o port to in- or output
 * @param port the gpio port
 * @param dir false for input, true for output
 */
void gpio_set_dir_port(GPIO_HW_STRUCT * const port, bool dir);

/**
 * sets the direction of an i/o pin
 * @param port the gpio port the pin belongs to
 * @param pin the pin that is configured
 * @param dir false for input, true for otput
 */
void gpio_set_dir_pin(GPIO_HW_STRUCT * const port, const GPIO_PIN pin, bool dir);

/**
 * write value to entire i/o port
 * @param port the gpio port
 * @param val true for HIGH, false for LOW for output pins. Note that this changes
 * pull up or down behavior of pins that are configured as inputs.
 */
void gpio_write_port(GPIO_HW_STRUCT * const port, bool val);

/**
 * write value to pin
 * @param port port the pin belongs to
 * @param pin the gpio pin
 * @param val false for LOW, true for HIGH. Note that this changes pull up or down
 * behavior of pins that are configured as input.
 */
void gpio_write_pin(GPIO_HW_STRUCT * const port, const GPIO_PIN pin, bool val);
/**
 * reads an entire gpio port
 * @param port the port to read
 * @return content of the port per pin
 */
uint8_t gpio_read_port(GPIO_HW_STRUCT * const port);

/**
 * read a gpio pin.
 * @param port the gpio port
 * @param pin the gpio pin to read
 * @return true on HIGH, false on LOW
 */
bool gpio_read_pin(GPIO_HW_STRUCT * const port, const GPIO_PIN pin);

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

#endif
