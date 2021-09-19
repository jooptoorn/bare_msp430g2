#toolchain cmake file for msp430-gcc/avrdude toolchain

# needs the following variables:
# MSP430_MCU : mcu type 
# MSP430_MCU_FREQ : clock frequency (defines F_CPU)

INCLUDE(CMakeForceCompiler)

#find toolchain programs
find_program(MSP430-GCC msp430-elf-gcc)
find_program(MSP430-GXX msp430-elf-g++)
find_program(MSP430-LD msp430-elf-ld)
find_program(MSP430-OBJCOPY msp430-elf-objcopy)
find_program(MSP430-SIZE msp430-elf-size)
find_program(MSP430-OBJDUMP msp430-elf-objdump)
find_program(MSPDEBUG mspdebug)

#generic flags
set(MSP430_CFLAGS "-g3 -ggdb -gdwarf-2 -ffunction-sections -fdata-sections -nostartfiles -mcpu=msp430" CACHE STRING "MSP430 compilation flags")
set(MSP430_LFLAGS "-g3 -ggdb -gdwarf-2 -ffunction-sections -fdata-sections -nostartfiles -mcpu=msp430 -Wl,--entry=reset_handler,--unresolved-symbols=ignore-in-shared-libs" CACHE STRING "MSP430 linker flags")

#define toolchain
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_C_COMPILER ${MSP430-GCC})
set(CMAKE_CXX_COMPILER ${MSP430-GXX})

#Release by default
if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build." FORCE)
endif(NOT CMAKE_BUILD_TYPE)


function(msp430_add_executable_compilation EXECUTABLE)
	set(EXECUTABLE_ELF "${EXECUTABLE}.elf")

	# main target for the executable depends of elf
	add_custom_target(${EXECUTABLE} ALL DEPENDS ${EXECUTABLE_ELF})

	# compile and link elf file
	add_executable(${EXECUTABLE_ELF} ${ARGN})
	message(STATUS "ARGN= ${ARGN}")
	set_target_properties(${EXECUTABLE_ELF} PROPERTIES 
		COMPILE_FLAGS "-mmcu=${MSP430_MCU} -DF_CPU=${MSP430_MCU_FREQ} ${MSP430_CFLAGS}"
		LINK_FLAGS "-Wl,-T${MSP430_LD} ${MSP430_LFLAGS} -Xlinker -Map=${EXECUTABLE}.map")

	# display size info after compilation
	add_custom_command(TARGET ${EXECUTABLE} POST_BUILD
		COMMAND ${MSP430-SIZE} ${EXECUTABLE_ELF})
	
	# generate debug info
	add_custom_command(TARGET ${EXECUTABLE} POST_BUILD
		COMMAND ${MSP430-OBJDUMP} -S ${EXECUTABLE_ELF} > ${EXECUTABLE}.dbg)
endfunction(msp430_add_executable_compilation)

function(msp430_add_executable_upload ${EXECUTABLE})
	add_custom_target(upload_${EXECUTABLE} 
		COMMAND ${MSPDEBUG} tilib "erase" "load ${EXECUTABLE}.elf"
		DEPENDS ${EXECUTABLE})
endfunction(msp430_add_executable_upload)

function(msp430_add_executable EXECUTABLE)
	if(NOT MSP430_MCU)
		message(FATAL_ERROR "MSP430_MCU not defined")
	endif(NOT MSP430_MCU)
	msp430_add_executable_compilation(${EXECUTABLE} ${ARGN})
	msp430_add_executable_upload(${EXECUTABLE})
endfunction(msp430_add_executable)
