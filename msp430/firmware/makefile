NAME        = blink.out
DIR			= $(shell pwd)
CSOURCES    = $(shell find -L . -type f -name '*.c')
CPPSOURCES  = $(shell find -L . -type f -name '*.cpp')
ASOURCES    = $(shell find -L . -type f -name '*.S')
INCLUDES    = $(shell find -L . -type f -name '*.h')
DEPENDS     = $(CSOURCES:%.c=%.dep)
COBJS       = $(CSOURCES:%.c=%.o)
CPPOBJS     = $(CPPSOURCES:%.cpp=%.o)
AOBJS       = $(ASOURCES:%.S=%.o) 

DEBUGGER = mspdebug rf2500

# all generates our target bin
all: $(NAME)

## Program device using MSP debugger
flash: $(NAME)
	$(DEBUGGER) "load $(DIR)/$(NAME)"

# clean all generated files
.PHONY: clean
clean:
	-rm $(NAME) $(NAME).obj $(COBJS) $(AOBJS) $(DEPENDS)
