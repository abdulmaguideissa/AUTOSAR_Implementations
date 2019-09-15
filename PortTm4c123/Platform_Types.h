/************************************************************
* Module:      Common - Platform Abstraction
* File Name:   Platform_Types.h
* Description: Platform types for ARM Cortex M4, Tivac
* Author:      Abdulmaguid Eissa
*************************************************************/

#ifndef PLATFORM_TYPES_H
#define PLATFORM_TYPES_H

/* Id for the company in the AUTOSAR */
#define PLATFORM_VENDOR_ID                          (2020U)

/* Module Id */
#define PLATFORM_TYPES_MODULE_ID                    (199U)

/* Module Version 1.0.0 */
#define PLATFORM_SW_MAJOR_VERSION                   (1U)
#define PLATFORM_SW_MINOR_VERSION                   (0U)
#define PLATFORM_SW_PATCH_VERSION                   (0U)

/* AUTOSAR Version 4.3.1 */
#define PLATFORM_AR_RELEASE_MAJOR_VERSION           (4U)
#define PLATFORM_AR_RELEASE_MINOR_VERSION           (3U)
#define PLATFORM_AR_RELEASE_PATCH_VERSION           (1U)

/*
* CPU register type width
*/
#define CPU_TYPE_8                  (8U)
#define CPU_TYPE_16                 (16U)
#define CPU_TYPE_32                 (32U)

/*
* Bit order definition
*/
#define MSB_FIRST                   (0U)        /* Big endian bit ordering        */
#define LSB_FIRST                   (1U)        /* Little endian bit ordering     */

/*
* Byte order definition
*/
#define HIGH_BYTE_FIRST             (0U)        /* Big endian byte ordering       */
#define LOW_BYTE_FIRST              (1U)        /* Little endian byte ordering    */

/* Platform type and endianess definitions, specific for TM4C123
 NOTE: ARM Cortex M4 architectures supports both little and big endianess */
#define CPU_TYPE                    (CPU_TYPE_32)
							
#define CPU_BIT_ORDER               (LSB_FIRST)
#define CPU_BYTE_ORDER              (LOW_BYTE_FIRST)

/* Boolean Values */
#ifndef FALSE
#define FALSE                       (0U)
#endif
#ifndef TRUE
#define TRUE                        (1U)
#endif

typedef unsigned char      boolean;		   
typedef unsigned char      uint8;          
typedef signed char        sint8;          
typedef unsigned short     uint16;         
typedef signed short       sint16;         
typedef unsigned long      uint32;         
typedef signed long        sint32;         
typedef unsigned long long uint64;         
typedef signed long long   sint64;
typedef float              float32;
typedef double             float64;

#endif /* PLATFORM_TYPES_H */
