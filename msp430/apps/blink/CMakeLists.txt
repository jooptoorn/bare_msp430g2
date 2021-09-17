# Template for a MSP430 project

cmake_minimum_required(VERSION 3.11)

set(CMAKE_TOOLCHAIN_FILE "${CMAKE_SOURCE_DIR}/generic-msp430-gcc.cmake")

# Name your project
project(blink)

#device dependent config, here for launchpad
set(MSP430_MCU msp430g2553)
set(MSP430_MCU_FREQ 1000000UL)
set(MSP430_LD ${CMAKE_SOURCE_DIR}/firmware/${MSP430_MCU}.ld)

# Find source files
add_subdirectory(firmware)
file(GLOB FIRMWARE_SRC ${CMAKE_SOURCE_DIR}/firmware/*.c)
message(STATUS "${FIRMWARE_SRC}")
set(SOURCES ${PROJECT_NAME}.c ${FIRMWARE_SRC})

msp430_add_executable(blink ${SOURCES})
