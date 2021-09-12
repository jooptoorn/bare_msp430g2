#ifdef GEN_ASS_HDR
									; include the C headers, note only macro's will be extracted.
	#include "firmware.h"
#else
									; automatically created header file
	#include "gpio_asm.h"
#endif

	.text
	.global led_green_on
	.global led_green_off

led_green_on:
	bis.b #40h, &P1OUT
	ret

led_green_off:
	bic.b #40h, &P1OUT
	ret
	.end
