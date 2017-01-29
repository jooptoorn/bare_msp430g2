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

#define WDT_CLK_DIV_32768 	0
#define WDT_CLK_DIV_8192	1
#define WDT_CLK_DIV_512		2
#define WDT_CLK_DIV_64		3

#define WDT_CLK_SM			0 << 2
#define WDT_CLK_EXT			1 << 2

#define WDT_MODE_WDOG		0 << 4
#define WDT_MODE_ITVL		1 << 4

#define WDT_PIN_MODE_RST	0 << 5
#define WDT_PIN_MODE_NMI	1 << 5

#define WDT_NMI_RISE_EDGE	0 << 6
#define WDT_NMI_FALL_EDGE	1 << 6

//always write to watchdog with password in upper bits
#define WDT_PW		(0x5a << 8)

/**
 * set the watchdog configuration in the control register
 * @param cfg bits to write in control reg
 */
void wdt_config(uint8_t cfg);

/**
 * clears the watchdog timer counter
 */
void wdt_feed(void);

#endif
