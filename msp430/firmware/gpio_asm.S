#ifdef GEN_ASS_HDR
									; include the C headers, note only macro's will be extracted.
	#include "firmware.h"
#else
									; automatically created header file
	#include "gpio_asm.h"
#endif

	.text
	.global led_green_write

led_green_write:
	bis.b #40h, &P1OUT
	ret

	.end
