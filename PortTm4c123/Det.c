/***********************************************************
* Module:      Det
* File Name:   Det.c
* Description: Det stores the development, runtime and transient 
			   errors reported by other modules.
* Author:      Abdulmaguid Eissa
************************************************************/

#include "Det.h"

/* Det_Init, initializing the Default Error Tracing */
void Det_Init(const Det_ConfigType * ConfigPtr)
{
}

/* Det_ReportError, see Det.h for the APT documentation */
Std_ReturnType Det_ReportError(uint16 ModuleId,
	uint8 InstanceId,
	uint8 ApiId,
	uint8 ErrorId)
{
	while (1)
	{

	}
}