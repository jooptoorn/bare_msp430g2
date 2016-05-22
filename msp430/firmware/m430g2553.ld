/* Simple linker script for M430G2553 */

/* MEMORY describes the device's memory blocks and their addresses */

MEMORY { 
  codeflash (rx)  : ORIGIN = 0xc000, LENGTH = 16K
  vectflash (rx)  : ORIGIN = 0xffc0, LENGTH = 64
  ram   	(rwx) : ORIGIN = 0x0200, LENGTH = 512
}

_LD_STACK_TOP = 0x3ff; /* Stack should start here */

/* SECTIONS lists where various parts data and code should go.
   Since they all just relate to the addressed defined above,
   porting code to other MCUs usually does not require changes. */

SECTIONS {

    /* vector table must be located in a dedicated part of flash
	 * memory. It contains interrupt handler pointers as explained
	 * in http://www.ti.com/lit/ds/slas735j/slas735j.pdf page 11. Each
	 * entry refers to the flash address of handler functions code in text*/
    vectors : {
        *(.vectors)
    } >vectflash
 
    /* .text section contains code and readonly (const) globals */
    text : {   
        *(.text)
        *(.rodata)
	   _LD_END_OF_TEXT = .;     /* Remember position (=start of RAM mirror in FLASH) */
    } >codeflash
  
    /* data section contains read-write (non-const) globals and static variables
     * initialized to a value other than zero. The addresses are mapped to RAM
     * (the code needs to write to it), but initial values put to a mirror region
     * in FLASH (because we need to have the values at startup). Bootstrap code
     * will copy the values from FLASH to RAM. Note that bootstrap code wants this
     * section to follow the text section directly. */
    data : {
        _LD_START_OF_DATA = .;   /* Remember position (=start of initialized RAM) */
        *(.data);
        _LD_END_OF_DATA = .;     /* Remember position (=end of initialized RAM) */
    } >ram AT >flash

    /* bss section contains globals and static variables either initialized to zero
     * or not initialized at all. These are not mirrored in FLASH. Their memory
     * needs to be zeroed at startup. We'll clear it in the bootstrap code. Note that
     * bootstrap code wants this section to follow the data section directly. */
    bss : {
        _LD_START_OF_BSS = .;   /* Remember position (=start of uninitialized RAM) */
        *(.bss)
        _LD_END_OF_BSS = .;     /* Remember position (=end of uninitialized RAM) */
    } > ram
}
