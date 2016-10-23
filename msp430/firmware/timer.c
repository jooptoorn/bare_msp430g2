#include "timer.h"

void wdt_config(uint16_t cfg){
	//mask cfg to lower byte
	cfg &= 0xff;
	//disable wdog, clear counter
	*WDT_CTL = (WDT_PW | WDTHOLD | WDTCNTCL);
	//write wdog setting
	*WDT_CTL = (WDT_PW | WDTHOLD | cfg);
	//enable wdog
	*WDT_CTL = (WDT_PW | cfg);
}
