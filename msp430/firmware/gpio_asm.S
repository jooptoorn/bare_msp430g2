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
	.global led_green_toggle
	.global led_red_on
	.global led_red_off
	.global led_red_toggle

led_green_on:
	bis.b #40h, &P1OUT
	ret

led_green_off:
	bic.b #40h, &P1OUT
	ret

led_green_toggle:
	xor.b #40h, &P1OUT
	ret

led_red_on:
	bis.b #01h, &P1OUT
	ret

led_red_off:
	bic.b #01h, &P1OUT
	ret

led_red_toggle:
	xor.b #01h, &P1OUT
	ret


	.end
