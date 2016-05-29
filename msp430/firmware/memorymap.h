/*defs for booting the device*/

#ifndef _MEMORYMAP_
#define _MEMORYMAP_

/*
 * The Vector Table
 * 
 * This table contains pointers to handler functions in memory
 * whenever an interrupt is triggered. Refer to User Guide page 37
 * http://www.ti.com/lit/ug/slau144j/slau144j.pdf. For the
 * msp430g2553, the 0-14 entries of the vector table are unused and
 * may be used for code memory. Reserving the memory here to
 * have maximum compatibility with other msp430 devices. Entry 15:
 * 
 * This location is used as bootstrap loader security key (BSLSKEY).
 * A 0xAA55 at this location disables the BSL completely. A zero (0h)
 * disables the erasure of the flash if an invalid password is supplied.
 * */

typedef struct {
	//interrupt priority 0-7: 0xffc0 - 0xffce
	void* RESERVED0[8];
	//interrupt priority 8-15: 0xffd0 - 0xffde
	void* RESERVED1[7];
	void* BSL_KEY;
	//interrupt priority 16-23: 0xffe0 - 0xffee
	void* RESERVED2[2];
	void* IO1_HANDLER;								//IO Port P1IFG.0 to P1IFG.7
	void* IO2_HANDLER;								//IO Port P2IFG.0 to P2IFG.7
	void* RESERVED3;
	void* ADC10_HANDLER;							//ADC10 handler
	void* USCI1_HANDLER;							//USCI_A0/USCI_B0 transmit (UART, SPI), USCI_B0	(I2C receive/transmit)
	void* USCI2_HANDLER;							//USCI_A0/USCI_B0 receive  (UART, SPI), USCI_B0	(I2C status)
	//interrupt priority 24-31: 0xfff0 - 0xfffe
	void* TIMER0_1;									//Timer0 TA0CCR0
	void* TIMER0_2;									//Timer0 TA0CCR(1/2), TAIFG
	void* WDOG_HANDLER;								//Watchdog
	void* COMP_APLUS_HANDLER;						//Comparator A+
	void* TIMER1_1;									//Timer1 TA1CCR0
	void* TIMER1_2;									//Timer1 TA1CCR(1/2), TAIFG
	void* NMI_HANDLER;								//Non-Maskable int. handler, triggered on NMIFLAG, Oscillator fault, flash mem access violation 
	void* RESET_HANDLER;							//Reset handler, triggered on Power-On and External reset, wachtdog time-out, flash key violation, PC out of range
} VECTOR_TABLE;

#endif
