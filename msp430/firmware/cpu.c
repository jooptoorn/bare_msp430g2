#include "cpu.h"

inline void enable_interrupts(bool en){
	if(en){
		asm("NOP");
		asm("EINT");
	}
	else
		asm("DINT");
	asm("NOP");
}
