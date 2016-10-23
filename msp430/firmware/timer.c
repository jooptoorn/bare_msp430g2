#include "timer.h"

//void wdt_init(uint8_t ps, bool aux_clk, bool mode, bool nmi, bool edge){
void wdt_init(uint16_t testvar){
//	uint8_t setting = 0;
	//disable wdog, clear counter
//	*WDT_CTL = (WDT_PW | WDTHOLD | WDTCNTCL);
	//set bits
	//setting = (ps & WDTISx_MSK) | (aux_clk & WDTSSEL) | (mode & WDTTMSEL) | (nmi & WDTNMI) | (edge & WDTNMIES);
	//write wdog setting
	//*WDT_CTL = (WDT_PW << 8) | WDTHOLD | setting;
	//enable wdog
	//*WDT_CTL = (WDT_PW << 8) | setting;
}
