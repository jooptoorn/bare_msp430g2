#include "timer.h"

inline void wdt_config(uint8_t cfg){
	//disable wdog, clear counter
	*WDT_CTL = (WDT_PW | WDTHOLD | WDTCNTCL);
	//write wdog configuration
	*WDT_CTL = (WDT_PW | WDTHOLD | cfg);
	//enable wdog
	*WDT_CTL = (WDT_PW | cfg);
}
