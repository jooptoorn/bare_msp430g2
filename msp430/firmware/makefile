NAME        = firmware
TARGET 		= msp430g2553
DIR			= $(shell pwd)
CSOURCES    = $(shell find -L . -type f -name '*.c')
CPPSOURCES  = $(shell find -L . -type f -name '*.cpp')
ASOURCES    = $(shell find -L . -type f -name '*.S')
INCLUDES    = $(shell find -L . -type f -name '*.h')
DEPENDS     = $(CSOURCES:%.c=%.dep)
COBJS       = $(CSOURCES:%.c=%.o)
CPPOBJS     = $(CPPSOURCES:%.cpp=%.o)
AOBJS       = $(ASOURCES:%.S=%.o) 

AS          = msp430-efl-as
CC          = msp430-elf-gcc
CPP         = msp430-elf-c++
LD          = msp430-elf-ld
OC          = msp430-elf-objcopy
CCFLAGS     = '-mmcu=$(TARGET)'
CPPFLAGS    = '-mmcu=$(TARGET)'
LDFLAGS     = '-T$(TARGET).ld' #-nostartfiles -nostdlib -nodefaultlibs
OCFLAGS     = -Oelf32-msp430 --strip-unneeded

DEBUGGER = mspdebug rf2500

# all generates our target bin
all: $(NAME).elf

#generate elf from object files
$(NAME).elf: $(NAME).obj
	$(OC) $(OCFLAGS) $(NAME).obj $(NAME).elf 

# generate obj by linking all .o files
$(NAME).obj: $(COBJS) $(CPPOBJS) $(AOBJS) 
	$(LD) $(LDFLAGS) -o $(NAME).obj $(COBJS) $(CPPOBJS) $(AOBJS)

# compile .c to .o files. Generate .dep files on the fly.
%.o: %.c
	$(CC) $(CCFLAGS) -MD -o $@ -c $<
	@cp $*.d $*.dep; \
	sed -e 's/#.*//' -e 's/^[^:]*: *//' -e 's/ *\\$$//' \
		-e '/^$$/ d' -e 's/$$/ :/' < $*.d >> $*.dep; \
	rm -f $*.d

# compile assembler files
%.o: %.S
	$(AS) $(ASFLAGS) -o $@ -c $<

# include depencies are defined in .dep files. Include them as rules here.
-include $(DEPENDS)

## Program device using MSP debugger
flash: $(NAME).elf
	$(DEBUGGER) "erase" "load $(DIR)/$(NAME).elf" 

binary: $(NAME).elf
	$(OC) -O binary $(NAME).elf $(NAME).bin

# clean all generated files
.PHONY: clean
clean:
	-rm -f $(NAME).elf $(NAME).obj $(NAME).bin $(COBJS) $(AOBJS) $(DEPENDS)
