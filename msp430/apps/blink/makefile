NAME        = firmware
TARGET 		= msp430g2553
DIR			= $(shell pwd)
ASOURCES    = $(shell find -L . -type f -name '*.S')
CSOURCES    = $(shell find -L . -type f -name '*.c')
CPPSOURCES  = $(shell find -L . -type f -name '*.cpp')
INCLUDES    = $(shell find -L . -type f -name '*.h')
LDSOURCE	= $(shell find -L . -type f -name '$(TARGET).ld')

AOBJS       = $(ASOURCES:%.S=%.o)
DEPENDS     = $(CSOURCES:%.c=%.dep)
COBJS       = $(CSOURCES:%.c=%.o)
CPPOBJS     = $(CPPSOURCES:%.cpp=%.o)

PREP		= msp430-elf-cpp
AS          = msp430-elf-as
CC          = msp430-elf-gcc
CPP         = msp430-elf-c++
LD          = msp430-elf-ld
OC          = msp430-elf-objcopy
OD			= msp430-elf-objdump
ASFLAGS	    = -mmcu=$(TARGET) -g
CCFLAGS     = -mmcu=$(TARGET) -g
CPPFLAGS    = -mmcu=$(TARGET)
LDFLAGS     = -T$(LDSOURCE) #-nostartfiles -nostdlib -nodefaultlibs
#OCFLAGS     = -Oelf32-msp430 --strip-unneeded
OCFLAGS     = -Oelf32-msp430
ODFLAGS		= -d -S

DEBUGGER = mspdebug tilib

# all generates our target bin
all: $(NAME).elf $(NAME).out

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
# generate special header for macro's throughout project, then include in assembly file
# abuse the normal preprocessor, because msp430-elf-as won't treat .S files like it should..
#step 1: extract macros from headers included in assembly .S file and store in auto created header
#step 2: preprocess file again with header created in 1, create .Spp file
#step 3: compile .Spp file

%.o: %.S
	$(PREP) -P -dM -DGEN_ASS_HDR $< -o $ $(<:%.S=%.h)
	$(PREP) -P -w $< -o $ $(<:%.S=%.Spp)
	$(AS) $(ASFLAGS) $(<:%.S=%.Spp) -o $@

# include depencies are defined in .dep files. Include them as rules here.
-include $(DEPENDS)

## Program device using MSP debugger
flash: $(NAME).elf
	$(DEBUGGER) "erase" "load $(NAME).elf" 

binary: $(NAME).elf
	$(OC) -O binary $(NAME).elf $(NAME).bin

# clean all generated files
.PHONY: clean
clean:
	-rm -f $(NAME).elf $(NAME).obj $(COBJS) $(AOBJS) $(AOBJS:%.o=%.Spp) $(DEPENDS)
	
debug: $(NAME).out

$(NAME).out: $(NAME).elf
	$(OD) $(ODFLAGS) $(NAME).elf > $(NAME).out
