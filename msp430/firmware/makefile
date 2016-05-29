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

AS          = msp430-as
CC          = msp430-gcc
CPP         = msp430-gcc
LD          = msp430-ld
OC          = msp430-objcopy
CCFLAGS     = '-mmcu=$(TARGET)'
CPPFLAGS    = '-mmcu=$(TARGET)'
LDFLAGS     = '-T$(TARGET).ld' #-nostartfiles -nostdlib -nodefaultlibs
OCFLAGS     = -Obinary --strip-unneeded

DEBUGGER = mspdebug rf2500

# all generates our target bin
all: $(NAME).bin

# generate out from obj by objcopying from linked obj file
$(NAME).bin: $(NAME).obj
	$(OC) $(OCFLAGS) $(NAME).obj $(NAME).bin

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
flash: $(NAME)
	$(DEBUGGER) "load $(DIR)/$(NAME)"

# clean all generated files
.PHONY: clean
clean:
	-rm $(NAME).bin $(NAME).obj $(COBJS) $(AOBJS) $(DEPENDS)
