#ifndef _TIMER_
#define _TIMER_

#include "firmware.h"

/*
 *
 * Watchdog+ defs
 *
 * */
typedef enum {
	WDTHOLD		= 0x80,
	WDTNMIES	= 0x40,
	WDTNMI		= 0x20,
	WDTTMSEL	= 0x10,
	WDTCNTCL	= 0x08,
	WDTSSEL		= 0x04,
	WDTISx_MSK	= 0x03
} WDT_CTL_ENUM;

//always write to watchdog with password in upper bits
#define WDT_PW		(0x5a << 8)

//void wdt_init(uint8_t ps, bool aux_clk, bool mode, bool nmi, bool edge);
void wdt_init(uint16_t testvar);

#endif
