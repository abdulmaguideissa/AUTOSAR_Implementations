/************************************************************
* Module:      Common - Standard Types
* File Name:   Std_Types.h
* Description: General types definitions
* Author:      Abdulmaguid Eissa
*************************************************************/

#ifndef STD_TYPES_H
#define STD_TYPES_H

/* Id for the company in the AUTOSAR */
#define STD_TYPES_VENDOR_ID                                  (2020U)

/* Module Id */
#define STD_TYPES_MODULE_ID                                  (197U)

/* Module Version 1.0.0 */
#define STD_TYPES_SW_MAJOR_VERSION                           (1U)
#define STD_TYPES_SW_MINOR_VERSION                           (0U)
#define STD_TYPES_SW_PATCH_VERSION                           (0U)

/* AUTOSAR Version 4.3.1 */
#define STD_TYPES_AR_RELEASE_MAJOR_VERSION                   (4U)
#define STD_TYPES_AR_RELEASE_MINOR_VERSION                   (3U)
#define STD_TYPES_AR_RELEASE_PATCH_VERSION                   (1U)


#include "Platform_Types.h"
#if ((STD_TYPES_AR_RELEASE_MAJOR_VERSION != PLATFORM_AR_RELEASE_MAJOR_VERSION)\
  || (STD_TYPES_AR_RELEASE_MINOR_VERSION != PLATFORM_AR_RELEASE_MINOR_VERSION)\
  || (STD_TYPES_AR_RELEASE_PATCH_VERSION != PLATFORM_AR_RELEASE_PATCH_VERSION))
	#error "The AR release of Std_Types does not match the expected Platform_Types release"
#endif /* (STD_TYPES_AR_RELEASE_MAJOR_VERSION != PLATFORM_AR_RELEASE_MAJOR_VERSION) */

#include "Compiler.h"
#if ((STD_TYPES_AR_RELEASE_MAJOR_VERSION != COMPILER_AR_RELEASE_MAJOR_VERSION)\
  || (STD_TYPES_AR_RELEASE_MINOR_VERSION != COMPILER_AR_RELEASE_MINOR_VERSION)\
  || (STD_TYPES_AR_RELEASE_PATCH_VERSION != COMPILER_AR_RELEASE_PATCH_VERSION))
	#error "The AR release of Std_Types does not match the expected Compiler release"
#endif /* (STD_TYPES_AR_RELEASE_MAJOR_VERSION != COMPILER_AR_RELEASE_MAJOR_VERSION) */

/*
*  Describes the standard Return Type Definitions used in the project
*/
typedef uint8 Std_ReturnType;

/*
* Structure for the Version of the module.
* This is requested by calling <Module name>_GetVersionInfo()
*/
typedef struct
{
	uint16  vendorID;
	uint16  moduleID;
	uint8 sw_major_version;
	uint8 sw_minor_version;
	uint8 sw_patch_version;
} Std_VersionInfoType;

/* Symbol definition. 
   Because E_OK is already defined within OSEK, the symbol E_OK has to be 
   shared */
#ifndef STATUSTYPEDEFINED  
#define STATUSTYPEDEFINED  
#define E_OK            (0x00U) 

typedef unsigned char StatusType; /* OSEK compliance */
#endif 

#define E_NOT_OK        (0x01U) 

#define STD_HIGH        (0x01U)       /* Physical state 5V or 3.3V */ 
#define STD_LOW         (0x00U)       /* Physical state 0 */ 

#define STD_ACTIVE      (0x01U)       /* Logical state active */
#define STD_IDLE        (0x00U)       /* Logical state idle */

#define STD_ON          (0x01U)       /* Standard ON */
#define STD_OFF         (0x00U)       /* Standard OFF */


#endif /* STD_TYPES_H */
