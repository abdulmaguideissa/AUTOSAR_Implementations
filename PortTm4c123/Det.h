/************************************************************
* Module:      Default Error Tracer.
* File Name:   Det.h
* Description: Definitions and APIs for reporting DET based on
	           the AUTOSAR SWS.
* Author:      Abdulmaguid Eissa.
*************************************************************/

#ifndef DET_H
#define DET_H

/* Id for the company in the AUTOSAR */
#define DET_VENDOR_ID                 (2020U)

/* Det Module Id */
#define DET_MODULE_ID                 (15U)

/* Instance Id */
#define DET_INSTANCE_ID               (0U)

/*
* Det Software Module Version 1.0.0
*/
#define DET_SW_MAJOR_VERSION          (1U)
#define DET_SW_MINOR_VERSION          (0U)
#define DET_SW_PATCH_VERSION          (0U)

/*
* AUTOSAR Version 4.0.3
*/
#define DET_AR_MAJOR_VERSION          (4U)
#define DET_AR_MINOR_VERSION          (3U)
#define DET_AR_PATCH_VERSION          (1U)

/* Standard AUTOSAR types */
#include "Std_Types.h"

/* AUTOSAR checking between Std Types and Det Modules */
#if ((DET_AR_MAJOR_VERSION != STD_TYPES_AR_RELEASE_MAJOR_VERSION)\
 ||  (DET_AR_MINOR_VERSION != STD_TYPES_AR_RELEASE_MINOR_VERSION)\
 ||  (DET_AR_PATCH_VERSION != STD_TYPES_AR_RELEASE_PATCH_VERSION))
	#error "The AR version of Std_Types.h does not match the expected version"
#endif

/* Type definitions */
/* Det Configuration Type */
typedef struct
{
	boolean Det_DevelopmentError;
}Det_ConfigType;

/****************************************************************
*                      Function Prototypes                       *
*****************************************************************/

/***************************************************************
* Service Name:       Det_Init
* Service ID[hex]:    0x00
* Sync/Async:         Synchronous
* Reentrancy:         Non Reentrant
* Parameters (in):    ConfigPtr  Pointer to the selected configuration set
* Parameters (inout): None
* Parameters (out):   None
* Return value:       None
* Description:        Service to initialize the Default Error Tracer. 
****************************************************************/
void Det_Init(const Det_ConfigType * ConfigPtr);

/***************************************************************
* Service Name:       Det_ReportError
* Service ID[hex]:    0x01
* Sync/Async:         Not Applicable: The function never returns 
* Reentrancy:         Reentrant
* Parameters (in):    ModuleId  Module ID of calling module. 
                      InstanceId  The identifier of the index based 
					  instance of a module, starting 
                      from 0, If the module is a single instance module 
					  it shall pass 0 as the InstanceId. 
                      ApiId  ID of API service in which error is detected 
                      ErrorId  ID of detected development error 
* Parameters (inout): None
* Parameters (out):   None
* Return value:       Std_ReturnType never returns a value, but has
                      a return type for compatibility with services and hooks 
* Description:        Service to report development errors.
****************************************************************/
Std_ReturnType Det_ReportError(uint16 ModuleId,
	uint8 InstanceId,
	uint8 ApiId,
	uint8 ErrorId);

#endif /* DET_H */
