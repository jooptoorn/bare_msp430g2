#include "firmware.h"

/* These variables are used to pass memory locations from the linker script to startup.c code. */
extern uint8_t _LD_STACK_TOP;
extern uint8_t _LD_END_OF_TEXT;
extern uint8_t _LD_START_OF_DATA;
extern uint8_t _LD_END_OF_DATA;
extern uint8_t _LD_END_OF_BSS;

//forward declarations of infinite loop and reset handler
void deadend(void);
void reset_handler(void);
/*weak defines for interrupt handlers. User defined functions
will override these*/
#define DEFAULTS_TO(func) __attribute__ ((weak, alias (#func)))

void main(void) DEFAULTS_TO(deadend);
void io1_handler(void) DEFAULTS_TO(deadend);
void io2_handler(void) DEFAULTS_TO(deadend);
void adc_handler(void) DEFAULTS_TO(deadend);
void serial1_handler(void) DEFAULTS_TO(deadend);
void serial2_handler(void) DEFAULTS_TO(deadend);
void timer0_1_handler(void) DEFAULTS_TO(deadend);
void timer0_2_handler(void) DEFAULTS_TO(deadend);
void wdog_handler(void) DEFAULTS_TO(deadend);
void comp_aplus_handler(void) DEFAULTS_TO(deadend);
void timer1_1_handler(void) DEFAULTS_TO(deadend);
void timer1_2_handler(void) DEFAULTS_TO(deadend);
void hardfault_handler(void) DEFAULTS_TO(reset_handler);

/* Declare the interrupt table. Format and details are specified in memorymap.h.
 * Write table to dedicated parts of flash (refer to msp430xxxx.ld)*/

__attribute__ ((section(".vectors")))
const VECTOR_TABLE vtable = {
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0,
	io1_handler,
	io2_handler,
	0,
	adc_handler,
	serial1_handler,
	serial2_handler,
	timer0_1_handler,
	timer0_2_handler,
	wdog_handler,
	comp_aplus_handler,
	timer1_1_handler,
	timer1_2_handler,
	hardfault_handler,
	reset_handler
};

/*
 * Default Handler
 *
 * loop forever until next reset occurs
 */
void deadend(void) {
	while(1);
}

/*
 * Reset Handler
 *
 * This code is executed immediately upon a reset.
 * From Programming Embedded Systems (http://stepsmail.com/download/Career-In-Embedded-System.PDF)
 * Startup code for C programs usually consists of the
 * following series of actions:
 * 1. Disable all interrupts.
 * 2. Copy any initialized data from ROM to RAM.
 * 3. Zero the uninitialized data area.
 * 4. Allocate space for and initialize the stack.
 * 5. Initialize the processor's stack pointer.
 * 6. Call main
 *
 * On the MSP430, the start-up module is responsible for the following tasks:
 * (http://mspgcc.sourceforge.net/manual/x1127.html)
 *  1. Providing a default vector table.
 *  2. Providing default interrupt handlers.
 *  3. Initializing the watchdog timer.
 *  4. Initializing the .data segment.
 *  5. Zeroing the .bss segment.
 *  6. Initializing the stack pointer
 *  7. Jumping to main(). (A jump is used, rather than a call, to save space on the stack. main() is not expected to return.)
 */

void reset_handler(void) {
	//disable watchdog
	*WDT_CTL = (WDT_PW | WDTHOLD);

	//- Copy any initialized data from ROM to RAM.
	uint8_t* mirror = &_LD_END_OF_TEXT; //copy from here
	uint8_t* ram = &_LD_START_OF_DATA;	//copy to here
	while (ram < (&_LD_END_OF_DATA)) *(ram++) = *(mirror++);

	//- Zero the uninitialized data area.
	while (ram < (&_LD_END_OF_BSS)) *(ram++) = 0;

	//- Initializing the stack pointer
	asm("mov.w   #_LD_STACK_TOP,r1");

	//- Jump to main(), don't use call to save space on stack
	asm("JMP main");
}
