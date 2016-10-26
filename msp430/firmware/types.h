#ifndef _TYPES_
#define _TYPES_

typedef unsigned char uint8_t;
typedef unsigned int uint16_t;
typedef unsigned int size_t;
typedef unsigned long uint32_t;
typedef unsigned long long uint64_t;

typedef char int8_t;
typedef int int16_t;
typedef long int32_t;
typedef long long int64_t;

#ifndef __cplusplus
typedef unsigned char bool;
#define false 0
#define true (!false)
#endif

#ifndef NULL 
#define NULL ((void*)0)
#endif


/* Some definitions for registers memory mapping. All just resolve to volatile. This way, allowed usage can be seen in the typedefs. HW_WO: Write only, HW_RO: Read only, HW_RW: Read/Write, HW_RS: Reserved (do not access), HW_UU: Unused (padding etc.) */

typedef volatile uint8_t HW_WO;
typedef volatile uint8_t HW_RO;
typedef volatile uint8_t HW_RW;
typedef volatile uint8_t HW_RS;
typedef volatile uint8_t HW_UU;


#endif
