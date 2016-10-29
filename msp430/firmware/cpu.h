#ifndef _CPU_
#define _CPU_

#include "firmware.h"
/*set/clear general interrupt enable (GIE) bit in status register
 * more info: http://mspgcc.sourceforge.net/manual/x223.html
 * Insert NOP before command to ensure it is properly executed.
 * Because MCU is pipelined, EINT and DINT take two cycles. Always insert
 * NOP after too, to prevent interrupt routine instruction from being fetched
 * when disabling interrupts and vice versa. */


/* Use defines to avoid function call overhead.
 * Enable: */
#define INTERRUPTS_EN 	\
{						\
	__asm__("NOP");		\
	__asm__("EINT");	\
	__asm__("NOP");		\
}
/* Disable: */
#define INTERRUPTS_DIS 	\
{						\
	__asm__("NOP");		\
	__asm__("DINT");	\
	__asm__("NOP");		\
}

/* Set/clear GIE bit
 * @param en value to write to GIE bit*/
void enable_interrupts(bool en);

#endif
