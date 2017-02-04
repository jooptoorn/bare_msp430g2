#define __DBL_MIN_EXP__ (-1021)
#define __UINT_LEAST16_MAX__ 0xffffU
#define __ATOMIC_ACQUIRE 2
#define __FLT_MIN__ 1.1754943508222875e-38F
#define __GCC_IEC_559_COMPLEX 0
#define INTERRUPTS_DIS { asm("NOP"); asm("DINT"); asm("NOP"); }
#define __UINT_LEAST8_TYPE__ unsigned char
#define _GPIO_ 
#define __INTMAX_C(c) c ## LL
#define __CHAR_BIT__ 8
#define GPIO_PORT_HIGH (0xff)
#define WDT_NMI_RISE_EDGE (0 << 6)
#define __UINT8_MAX__ 0xff
#define __WINT_MAX__ 0xffffU
#define NO_TRAMPOLINES 1
#define __ORDER_LITTLE_ENDIAN__ 1234
#define __SIZE_MAX__ 0xffffU
#define __WCHAR_MAX__ 0x7fffffffL
#define __DBL_DENORM_MIN__ ((double)4.9406564584124654e-324L)
#define __GCC_ATOMIC_CHAR_LOCK_FREE 1
#define __GCC_IEC_559 0
#define __FLT_EVAL_METHOD__ 0
#define gpio_write_pin(port,pin,val) (val ? gpio_write_pin_high(port,pin) : gpio_write_pin_low(port,pin))
#define __GCC_ATOMIC_CHAR32_T_LOCK_FREE 1
#define GPIO_PORT_LOW (0 )
#define __UINT_FAST64_MAX__ 0xffffffffffffffffULL
#define __SIG_ATOMIC_TYPE__ int
#define __DBL_MIN_10_EXP__ (-307)
#define __FINITE_MATH_ONLY__ 0
#define __GNUC_PATCHLEVEL__ 0
#define __UINT_FAST8_MAX__ 0xffffU
#define __has_include(STR) __has_include__(STR)
#define __DEC64_MAX_EXP__ 385
#define __INT8_C(c) c
#define __UINT_LEAST64_MAX__ 0xffffffffffffffffULL
#define __SHRT_MAX__ 0x7fff
#define __LDBL_MAX__ 1.7976931348623157e+308L
#define P1OUT (0x021)
#define __UINT_LEAST8_MAX__ 0xff
#define __GCC_ATOMIC_BOOL_LOCK_FREE 1
#define __UINTMAX_TYPE__ long long unsigned int
#define __DEC32_EPSILON__ 1E-6DF
#define __MSP430XGENERIC__ 1
#define __CHAR_UNSIGNED__ 1
#define __UINT32_MAX__ 0xffffffffUL
#define GPIO_OUTPUT (1)
#define __LDBL_MAX_EXP__ 1024
#define gpio_write_port_high(port) (port->OUT = 0xff)
#define __WINT_MIN__ 0U
#define _TYPES_ 
#define __SCHAR_MAX__ 0x7f
#define __WCHAR_MIN__ (-__WCHAR_MAX__ - 1)
#define __INT64_C(c) c ## LL
#define __DBL_DIG__ 15
#define __GCC_ATOMIC_POINTER_LOCK_FREE 1
#define __SIZEOF_INT__ 2
#define __SIZEOF_POINTER__ 2
#define __USER_LABEL_PREFIX__ 
#define gpio_toggle_pin(port,pin) (port->OUT ^=pin)
#define __STDC_HOSTED__ 1
#define __LDBL_HAS_INFINITY__ 1
#define _FIRMWARE_ 
#define WDT_CLK_SM (0 << 2)
#define __FLT_EPSILON__ 1.1920928955078125e-7F
#define __MSP430__ 1
#define __LDBL_MIN__ 2.2250738585072014e-308L
#define __STDC_UTF_16__ 1
#define __DEC32_MAX__ 9.999999E96DF
#define __INT32_MAX__ 0x7fffffffL
#define __SIZEOF_LONG__ 4
#define __UINT16_C(c) c ## U
#define _TIMER_ 
#define __DECIMAL_DIG__ 17
#define WDT_CLK_EXT (1 << 2)
#define __has_include_next(STR) __has_include_next__(STR)
#define __LDBL_HAS_QUIET_NAN__ 1
#define gpio_set_dir_pin_output(port,pin) (port->DIR |= pin)
#define GPIO_SEL2 ((GPIO_SEL2_HW_STRUCT*) 0x040)
#define __GNUC__ 5
#define __FLT_HAS_DENORM__ 1
#define __SIZEOF_LONG_DOUBLE__ 8
#define __BIGGEST_ALIGNMENT__ 2
#define GPIO_PIN0 (1 << 0)
#define GPIO_PIN1 (1 << 1)
#define GPIO_PIN2 (1 << 2)
#define GPIO_PIN3 (1 << 3)
#define GPIO_PIN4 (1 << 4)
#define GPIO_PIN5 (1 << 5)
#define GPIO_PIN6 (1 << 6)
#define GPIO_PIN7 (1 << 7)
#define __DBL_MAX__ ((double)1.7976931348623157e+308L)
#define WDT_CLK_DIV_8192 (1)
#define __INT_FAST32_MAX__ 0x7fffffffL
#define __DBL_HAS_INFINITY__ 1
#define __DEC32_MIN_EXP__ (-94)
#define __INT_FAST16_TYPE__ int
#define WDT_PW (0x5a << 8)
#define __LDBL_HAS_DENORM__ 1
#define __DEC128_MAX__ 9.999999999999999999999999999999999E6144DL
#define __INT_LEAST32_MAX__ 0x7fffffffL
#define __DEC32_MIN__ 1E-95DF
#define true (!false)
#define WDT_PIN_MODE_NMI (1 << 5)
#define gpio_write_pin_high(port,pin) (port->OUT |= pin)
#define __DBL_MAX_EXP__ 1024
#define __DEC128_EPSILON__ 1E-33DL
#define gpio_read_pin(port,pin) (port->IN & pin)
#define __PTRDIFF_MAX__ 0x7fff
#define __LONG_LONG_MAX__ 0x7fffffffffffffffLL
#define __SIZEOF_SIZE_T__ 2
#define __SIZEOF_WINT_T__ 2
#define __GXX_ABI_VERSION 1009
#define __FLT_MIN_EXP__ (-125)
#define gpio_write_pin_low(port,pin) (port->OUT &= ~pin)
#define WDT_MODE_WDOG (0 << 4)
#define __INT_FAST64_TYPE__ long long int
#define __DBL_MIN__ ((double)2.2250738585072014e-308L)
#define GPIO_INPUT (0)
#define __DEC128_MIN__ 1E-6143DL
#define __REGISTER_PREFIX__ 
#define __UINT16_MAX__ 0xffffU
#define __DBL_HAS_DENORM__ 1
#define __UINT8_TYPE__ unsigned char
#define __NO_INLINE__ 1
#define __FLT_MANT_DIG__ 24
#define WDT_CLK_DIV_64 (3)
#define __VERSION__ "5.3.0"
#define __UINT64_C(c) c ## ULL
#define __GCC_ATOMIC_INT_LOCK_FREE 1
#define __FLOAT_WORD_ORDER__ __ORDER_LITTLE_ENDIAN__
#define __MSP430X__ 1
#define gpio_read_port(port) (port->IN)
#define gpio_set_dir_port(port,dir) (port->DIR = dir)
#define __INT32_C(c) c ## L
#define __DEC64_EPSILON__ 1E-15DD
#define __ORDER_PDP_ENDIAN__ 3412
#define __DEC128_MIN_EXP__ (-6142)
#define __INT_FAST32_TYPE__ long int
#define gpio_set_dir_pin(port,pin,dir) (dir ? gpio_set_dir_pin_output(port,pin) : gpio_set_dir_pin_input(port,pin))
#define __UINT_LEAST16_TYPE__ short unsigned int
#define __INT16_MAX__ 0x7fff
#define __SIZE_TYPE__ unsigned int
#define __UINT64_MAX__ 0xffffffffffffffffULL
#define __INT8_TYPE__ signed char
#define __ELF__ 1
#define __FLT_RADIX__ 2
#define __INT_LEAST16_TYPE__ short int
#define __LDBL_EPSILON__ 2.2204460492503131e-16L
#define __UINTMAX_C(c) c ## ULL
#define __SIG_ATOMIC_MAX__ 0x7fff
#define gpio_write_port(port,val) (val ? gpio_write_port_high(port) : gpio_write_port_low(port))
#define __GCC_ATOMIC_WCHAR_T_LOCK_FREE 1
#define __SIZEOF_PTRDIFF_T__ 2
#define __DEC32_SUBNORMAL_MIN__ 0.000001E-95DF
#define __INT_FAST16_MAX__ 0x7fff
#define __UINT_FAST32_MAX__ 0xffffffffUL
#define __UINT_LEAST64_TYPE__ long long unsigned int
#define __FLT_HAS_QUIET_NAN__ 1
#define __FLT_MAX_10_EXP__ 38
#define __LONG_MAX__ 0x7fffffffL
#define __DEC128_SUBNORMAL_MIN__ 0.000000000000000000000000000000001E-6143DL
#define __FLT_HAS_INFINITY__ 1
#define __UINT_FAST16_TYPE__ unsigned int
#define __DEC64_MAX__ 9.999999999999999E384DD
#define NULL ((void*)0)
#define __CHAR16_TYPE__ short unsigned int
#define __PRAGMA_REDEFINE_EXTNAME 1
#define __INT_LEAST16_MAX__ 0x7fff
#define __DEC64_MANT_DIG__ 16
#define __INT64_MAX__ 0x7fffffffffffffffLL
#define __UINT_LEAST32_MAX__ 0xffffffffUL
#define __GCC_ATOMIC_LONG_LOCK_FREE 1
#define __INT_LEAST64_TYPE__ long long int
#define __INT16_TYPE__ short int
#define __INT_LEAST8_TYPE__ signed char
#define __STDC_VERSION__ 201112L
#define __DEC32_MAX_EXP__ 97
#define __INT_FAST8_MAX__ 0x7fff
#define __INTPTR_MAX__ 0x7fff
#define WDT_PIN_MODE_RST (0 << 5)
#define __LDBL_MANT_DIG__ 53
#define __DBL_HAS_QUIET_NAN__ 1
#define false 0
#define __SIG_ATOMIC_MIN__ (-__SIG_ATOMIC_MAX__ - 1)
#define _CPU_ 
#define INTERRUPTS_EN { asm("NOP"); asm("EINT"); asm("NOP"); }
#define __INTPTR_TYPE__ int
#define __UINT16_TYPE__ short unsigned int
#define __WCHAR_TYPE__ long int
#define __SIZEOF_FLOAT__ 4
#define __UINTPTR_MAX__ 0xffffU
#define __DEC64_MIN_EXP__ (-382)
#define __INT_FAST64_MAX__ 0x7fffffffffffffffLL
#define __GCC_ATOMIC_TEST_AND_SET_TRUEVAL 1
#define __FLT_DIG__ 6
#define IFG1 ((uint16_t*) 0x0002)
#define __UINT_FAST64_TYPE__ long long unsigned int
#define __INT_MAX__ 0x7fff
#define __INT64_TYPE__ long long int
#define __FLT_MAX_EXP__ 128
#define __DBL_MANT_DIG__ 53
#define __INT_LEAST64_MAX__ 0x7fffffffffffffffLL
#define __GCC_ATOMIC_CHAR16_T_LOCK_FREE 1
#define __DEC64_MIN__ 1E-383DD
#define __WINT_TYPE__ unsigned int
#define __UINT_LEAST32_TYPE__ long unsigned int
#define __SIZEOF_SHORT__ 2
#define __LDBL_MIN_EXP__ (-1021)
#define gpio_write_port_low(port) (port->OUT = 0x0)
#define _MEMORYMAP_ 
#define WDT_CLK_DIV_32768 (0)
#define __INT_LEAST8_MAX__ 0x7f
#define __LDBL_MAX_10_EXP__ 308
#define __ATOMIC_RELAXED 0
#define __DBL_EPSILON__ ((double)2.2204460492503131e-16L)
#define __SIZEOF_INT20__ 4
#define WDT_NMI_FALL_EDGE (1 << 6)
#define __UINT8_C(c) c
#define __INT_LEAST32_TYPE__ long int
#define __SIZEOF_WCHAR_T__ 4
#define __UINT64_TYPE__ long long unsigned int
#define GPIO_PORT1 ((GPIO_HW_STRUCT*) 0x020)
#define GPIO_PORT2 ((GPIO_HW_STRUCT*) 0x028)
#define __INT_FAST8_TYPE__ int
#define WDT_MODE_ITVL (1 << 4)
#define __GNUC_STDC_INLINE__ 1
#define WDT_CLK_DIV_512 (2)
#define IE1 ((uint16_t*) 0x0000)
#define __DBL_DECIMAL_DIG__ 17
#define __STDC_UTF_32__ 1
#define __DEC_EVAL_METHOD__ 2
#define GPIO_EDGE_LOWTOHIGH (0)
#define WDT_CTL ((uint16_t*) 0x0120)
#define __ORDER_BIG_ENDIAN__ 4321
#define wdt_feed() (*WDT_CTL = (WDT_PW | WDTCNTCL))
#define __UINT32_C(c) c ## UL
#define __INTMAX_MAX__ 0x7fffffffffffffffLL
#define __BYTE_ORDER__ __ORDER_LITTLE_ENDIAN__
#define __FLT_DENORM_MIN__ 1.4012984643248171e-45F
#define __INT8_MAX__ 0x7f
#define __UINT_FAST32_TYPE__ long unsigned int
#define __CHAR32_TYPE__ long unsigned int
#define __FLT_MAX__ 3.4028234663852886e+38F
#define __INT32_TYPE__ long int
#define __SIZEOF_DOUBLE__ 8
#define __FLT_MIN_10_EXP__ (-37)
#define __INTMAX_TYPE__ long long int
#define __DEC128_MAX_EXP__ 6145
#define __ATOMIC_CONSUME 1
#define __GNUC_MINOR__ 3
#define __UINTMAX_MAX__ 0xffffffffffffffffULL
#define __DEC32_MANT_DIG__ 7
#define __DBL_MAX_10_EXP__ 308
#define __LDBL_DENORM_MIN__ 4.9406564584124654e-324L
#define __INT16_C(c) c
#define __STDC__ 1
#define gpio_set_dir_pin_input(port,pin) (port->DIR &= ~pin)
#define __PTRDIFF_TYPE__ int
#define __ATOMIC_SEQ_CST 5
#define __UINT32_TYPE__ long unsigned int
#define __UINTPTR_TYPE__ unsigned int
#define __DEC64_SUBNORMAL_MIN__ 0.000000000000001E-383DD
#define __DEC128_MANT_DIG__ 34
#define __LDBL_MIN_10_EXP__ (-307)
#define __SIZEOF_LONG_LONG__ 8
#define __GCC_ATOMIC_LLONG_LOCK_FREE 1
#define __LDBL_DIG__ 15
#define __FLT_DECIMAL_DIG__ 9
#define __UINT_FAST16_MAX__ 0xffffU
#define __GCC_ATOMIC_SHORT_LOCK_FREE 1
#define GPIO_EDGE_HIGHTOLOW (1)
#define __UINT_FAST8_TYPE__ unsigned int
#define __ATOMIC_ACQ_REL 4
#define __ATOMIC_RELEASE 3
