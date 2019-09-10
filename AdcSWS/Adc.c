/************************************************************
* Module:      Adc SWS.
* File Name:   Adc.c
* Description: Source file of the MCAL Adc module
	           based on the AUTOSAR Compiler SWS.
* Author:      Abdulmaguid Eissa.
*************************************************************/

#include "Adc.h"

#if (ADC_DEV_ERROR_DETECT == STD_ON) /* Reference the Det.h only if DET is switched on */
#include "Det.h"
/* AUTOSAR Version checking between Det and Dio Modules */
#if ((DET_AR_MAJOR_VERSION != ADC_AR_RELEASE_MAJOR_VERSION)\
 ||  (DET_AR_MINOR_VERSION != ADC_AR_RELEASE_MINOR_VERSION)\
 ||  (DET_AR_PATCH_VERSION != ADC_AR_RELEASE_PATCH_VERSION))
#error "The AR version of Det.h does not match the expected version"
#endif /* (DET_AR_MAJOR_VERSION != ADC_AR_RELEASE_MAJOR_VERSION) */

/* AUTOSAR Version checking between Det and Dio Modules */
#if ((DET_SW_MAJOR_VERSION != ADC_SW_MAJOR_VERSION)\
 ||  (DET_SW_MINOR_VERSION != ADC_SW_MINOR_VERSION)\
 ||  (DET_SW_PATCH_VERSION != ADC_SW_PATCH_VERSION))
#error "The SW version of Det.h does not match the expected version"
#endif /* (DET_SW_MAJOR_VERSION != ADC_SW_MAJOR_VERSION) */

#endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */

/* Non AUTOSAR files inclusion */
#include "Tivac_Hw.h"

/* Global definitions, File specdific definitons */
STATIC Adc_ConfigChannel * Adc_Channel = NULL_PTR;         /* Pointer to the first element of the strcture of array */
STATIC uint8            Adc_InitStatus = ADC_NOT_INITIALIZED;
STATIC Adc_StatusType   Adc_ConvStatus = ADC_IDLE;         /* Conversion status */

/***************************************************************
*                    Functions Definitions                     *
****************************************************************/

/***************************************************************/
/*              Adc_Init Service definition                   */
void Adc_Init(const Adc_ConfigType * ConfigPtr)
{
	boolean error = FALSE;

#if (ADC_DEV_ERROR_DETECT == STD_ON)
	if (NULL_PTR == ConfigPtr)
	{
		Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
			ADC_INIT_SID, ADC_E_PARAM_CONFIG);
		error = TRUE;
	}
	else
	{
		/* No action required */
	}
	if (ADC_INITIALIZED == Adc_InitStatus)
	{
		Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
			ADC_INIT_SID, ADC_E_ALREADY_INITIALIZED);
		error = TRUE;
	}
	else
	{
		/* No action required */
	}
#endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */
	if (FALSE == error)
	{

		Adc_Channel = ConfigPtr->Adc_Channels;
		ADC_InitChannel(ADC_CONFIGURED_CHANNELS, Adc_Channel);
		Adc_InitStatus = ADC_INITIALIZED;    /* Done initializing Adc unit */
	}
	else
	{
		/* No action required */
	}
}

/***************************************************************/
/*              Adc_DeInit Service definition                 */
void Adc_DeInit(void)
{
	boolean error = FALSE;

#if (ADC_DEV_ERROR_DETECT == STD_ON)
	if (ADC_NOT_INITIALIZED == Adc_InitStatus)
	{
		Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
			ADC_DEINIT_SID, ADC_E_UNINIT);  
		error = TRUE;
	}
	else
	{
		/* No action required */
	}
	if (ADC_BUSY == Adc_ConvStatus)
	{
		Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
			ADC_DEINIT_SID, ADC_E_BUSY);
		error = TRUE;
	}
	else
	{
		/* No action required */
	}
#endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */
	if (FALSE == error)
	{
		ADC_DeInitChannel(ADC_CONFIGURED_CHANNELS, Adc_Channel);
		Adc_InitStatus = ADC_NOT_INITIALIZED;
	}
	else
	{
		/* No action required */
	}
}

/**************************************************************/
/*        Adc_GetVersionInfo Service definition               */
#if (ADC_VERSION_INFO_API == STD_ON)
void Adc_GetVersionInfo(Std_VersionInfoType* versioninfo)
{
	boolean error = FALSE;

#if (ADC_DEV_ERROR_DETECT == STD_ON) /* Report Error */
	if (ADC_NOT_INITIALIZED == Adc_InitStatus)
	{
		Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
			ADC_GET_VERSION_INFO_SID, ADC_E_UNINIT);
		error = TRUE;
	}
	else
	{
		/* No action required */
	}
	if (NULL_PTR == versioninfo)
	{
		Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,
			ADC_GET_VERSION_INFO_SID, ADC_E_PARAM_POINTER);
		error = TRUE;
	}
	else
	{
		/* No Action Required */
	}
#endif /* (ADC_DEV_ERROR_DETECTION == STD_ON) */
	if (FALSE == error)
	{
		versioninfo->vendorID = ADC_VENDOR_ID;
		versioninfo->moduleID = ADC_MODULE_ID;
		versioninfo->sw_major_version = (uint8)ADC_SW_MAJOR_VERSION;
		versioninfo->sw_minor_version = (uint8)ADC_SW_MINOR_VERSION;
		versioninfo->sw_patch_version = (uint8)ADC_SW_PATCH_VERSION;
	}
	else
	{
		/* No Action Required */
	}
}
#endif /* (ADC_VERSION_INFO_API == STD_ON) */

