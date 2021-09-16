#ifdef GEN_ASS_HDR
									; include the C headers, note only macro's will be extracted.
	#include "firmware.h"
#else
									; automatically created header file
	#include "gpio_asm.h"
#endif

	.text
	.global led_green_on_asm
	.global led_green_off_asm
	.global led_green_toggle_asm
	.global led_red_on_asm
	.global led_red_off_asm
	.global led_red_toggle_asm

led_green_on_asm:
	bis.b #40h, &P1OUT
	ret

led_green_off_asm:
	bic.b #40h, &P1OUT
	ret

led_green_toggle_asm:
	xor.b #40h, &P1OUT
	ret

led_red_on_asm:
	bis.b #01h, &P1OUT
	ret

led_red_off_asm:
	bic.b #01h, &P1OUT
	ret

led_red_toggle_asm:
	xor.b #01h, &P1OUT
	ret


	.end
