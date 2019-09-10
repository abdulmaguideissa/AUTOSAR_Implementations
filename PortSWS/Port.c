/******************************************************************************
*
* Module: Port
*
* File Name: Port.c
*
* Description: Source file for Port device driver APIs implementation,
*              implementation is based on AUTOSAR specfications.
*
* Author: Abdulmaguid Eissa
*
* Date:  May 26, 2019
******************************************************************************/

#include "Port.h"

#if (PORT_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
	/* AUTOSAR version checking */
	#if ((DET_AR_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
	 ||  (DET_AR_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
	 ||  (DET_AR_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
		#error "The AR version of Det.h does not match the expected version"
	#endif /* AUTOSAR version checking */

	/* SW module version checking */
	#if ((DET_SW_MAJOR_VERSION != PORT_SW_MAJOR_VERSION)\
	 ||  (DET_SW_MINOR_VERSION != PORT_SW_MINOR_VERSION)\
	 ||  (DET_SW_PATCH_VERSION != PORT_SW_PATCH_VERSION))
		#error "The AR version of Det.h does not match the expected version"
	#endif /* SW module version checking */
#endif /* (DET_DEV_ERROR_DETECT == STD_ON) */

/***************************************************************/
/*           Private Functions Declarations                    */
/****************************************************************
* Service Name:       Port_InitDevErrorCheck
* Sync/Async:         Synchronous
* Parameters (in):    Service Id
* Parameters (inout): None
* Parameters (out):   None
* Return value:       TRUE, if initialized
                      FALSE, if not initialized.
* Description:        Check port initialization status and report error.
****************************************************************/
boolean STATIC Port_InitDevErrorCheck(uint8 Service_Id);

/* File specific varaibles declarations */
STATIC Port_ConfigPin * Port_Pins = NULL_PTR;             /* Pointer to config Pin struct first element */
STATIC uint8 Port_Status          = PORT_NOT_INITIALIZED;



/***************************************************************
*                    Functions Definitions                     *
****************************************************************/

/***************************************************************/
/*              Port_Init Service definition                   */
void Port_Init(const Port_ConfigType* ConfigPtr)
{
#if (PORT_DEV_ERROR_DETECT == STD_ON) /* Report Errors */
	if (NULL_PTR == ConfigPtr)
	{
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, 
			PORT_INIT_SID, PORT_E_PARAM_CONFIG);
	}
	else
	{
		/* No Action Required */
	}
#endif /* (PORT_DEV_ERROR_DETECT == STD_ON) */
	Port_Pins   = ConfigPtr->Pins;                /* Address of the first Pin */
	Port_Status = PORT_INITIALIZED;
}

/**************************************************************/
/*        Port_SetPinDirection Service definition             */
void Port_SetPinDirection(Port_PinType Pin, Port_PinDirectionType Direction)
{
	uint8 * Direction_Ptr = NULL_PTR;
	boolean error         = FALSE;

#if (PORT_DEV_ERROR_DETECT == STD_ON)    /* Report Errors */
	error = Port_InitDevErrorCheck(PORT_SET_PIN_DIRECTION_SID);
	
	if (PORT_CONFIG_PORT_PINS <= Pin)
	{
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
			PORT_SET_PIN_DIRECTION_SID, PORT_E_PARAM_PIN);
		error = TRUE;
	}
	else
	{
		/* No Action Required */
	}
#endif /* (PORT_DEV_ERROR_DETECT == STD_ON) */
	if (FALSE == error)
	{
		switch (Port_Pins[Pin].Port_RegNumber)
		{
			case 0:
				Direction_Ptr = &DDRA;
				break;
			case 1:
				Direction_Ptr = &DDRB;
				break;
			case 2:
				Direction_Ptr = &DDRC;
				break;
			case 3:
				Direction_Ptr = &DDRD;
				break;
			default:
				break;
		}

		if (PORT_PIN_OUT == Direction)
		{
			SET_BIT(*Direction_Ptr, Port_Pins[Pin].Port_PinNumber);
		}
		else if(PORT_PIN_IN == Direction)
		{
			CLEAR_BIT(*Direction_Ptr, Port_Pins[Pin].Port_PinNumber);
		}
		else
		{
			/* No Action Required */
		}
	} /* (FALSE == error) */
	else
	{
		/* No Action Required */
	}
}

/**************************************************************/
/*       Port_RefreshPortDirection Service definition         */
void Port_RefreshPortDirection(void)
{
	boolean error                 = FALSE;
	uint8 * DirectionRegister_Ptr = NULL_PTR;
	uint8 ConfiguredPinsIndex   = 0;
	
#if (PORT_DEV_ERROR_DETECT == STD_ON) /* Report Errors */
	error = Port_InitDevErrorCheck(PORT_REFRESH_PORT_DIRECTION_SID);
#endif /* (PORT_DEV_ERROR_DETECT == STD_ON) */

	if (FALSE == error)
	{
		while (PORT_CONFIG_PORT_PINS > ConfiguredPinsIndex)
		{
			switch (Port_Pins[ConfiguredPinsIndex].Port_RegNumber)
			{
				case 0:
					DirectionRegister_Ptr = &DDRA;
					break;
				case 1:
					DirectionRegister_Ptr = &DDRB;
					break;
				case 2:
					DirectionRegister_Ptr = &DDRC;
					break;
				case 3:
					DirectionRegister_Ptr = &DDRD;
					break;
				default:
					break;
			}

			if (PORT_PIN_OUT == Port_Pins[ConfiguredPinsIndex].Port_PinDirection)
			{
				SET_BIT(*DirectionRegister_Ptr, Port_Pins[ConfiguredPinsIndex].Port_PinNumber);
			}
			else if (PORT_PIN_IN == Port_Pins[ConfiguredPinsIndex].Port_PinDirection)
			{
				CLEAR_BIT(*DirectionRegister_Ptr, Port_Pins[ConfiguredPinsIndex].Port_PinNumber);
			}
			else
			{
				/* No Action Required */
			}
			ConfiguredPinsIndex++;
		} /* while (PORT_CONFIG_PORT_PINS > Configured_Pins_Index) */
	}
}

/**************************************************************/
/*        Port_GetVersionInfo Service definition              */
#if (PORT_VERSION_INFO_API == STD_ON)
void Port_GetVersionInfo(Std_VersionInfoType* versioninfo)
{
	boolean error = FALSE;

#if (PORT_DEV_ERROR_DETECT == STD_ON) /* Report Error */
	error = Port_InitDevErrorCheck(PORT_GET_VERSION_INFO_SID);

	if (NULL_PTR == versioninfo)
	{
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
			PORT_GET_VERSION_INFO_SID, PORT_E_PARAM_POINTER);
		error = TRUE;
	}
	else
	{
		/* No Action Required */
	}
#endif /* (PORT_DEV_ERROR_DETECTION == STD_ON) */
	if (FALSE == error)
	{
		versioninfo->vendorID = PORT_VENDOR_ID;
		versioninfo->moduleID = PORT_MODULE_ID;
		versioninfo->sw_major_version = (uint8)PORT_SW_MAJOR_VERSION;
		versioninfo->sw_minor_version = (uint8)PORT_SW_MINOR_VERSION;
		versioninfo->sw_patch_version = (uint8)PORT_SW_PATCH_VERSION;
	}
	else
	{
		/* No Action Required */
	}
}
#endif /* (PORT_VERSION_INFO_API == STD_ON) */

/**************************************************************/
/*           Port_SetPinMode Service definition               */
/* NOTE: TO BE COMPLETED.. */
#if (PORT_SET_PIN_MODE_API == STD_ON)
void Port_SetPinMode(Port_PinType Pin, Port_PinModeType Mode)
{
	boolean error             = FALSE;
	uint8 * ModeRegister_Ptr  = NULL_PTR;
	Port_PinModeType Pin_Mode = PORT_PIN_CONFIG_MODE_DIO;

#if (PORT_DEV_ERROR_DETECT == STD_ON)    /* Report Errors */
	error = Port_InitDevErrorCheck(PORT_SET_PIN_MODE_SID);

	if (PORT_CONFIG_PORT_PINS <= Pin)
	{
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
			PORT_SET_PIN_MODE_SID, PORT_E_PARAM_PIN);
		error = TRUE;
	}
	else
	{
		/* No Action Required */
	}
	if (PORT_CONFIG_MODE_NUM <= Mode)
	{
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
			PORT_SET_PIN_MODE_SID, PORT_E_PARAM_INVALID_MODE);
		error = TRUE;
	}
#endif /* (PORT_DEV_ERROR_DETECT == STD_ON) */

	if (FALSE == error)
	{
		switch (Port_Pins[Pin].Port_RegNumber) /* Register assignment */
		{
			case 0:
				ModeRegister_Ptr = &GPIO_PORTA_CTL_R;
				break;
			case 1:
				ModeRegister_Ptr = &GPIO_PORTB_CTL_R;
				break;
			case 2:
				ModeRegister_Ptr = &GPIO_PORTC_CTL_R;
				break;
			case 3:
				ModeRegister_Ptr = &GPIO_PORTD_CTL_R;
				break;
			default:
				break;
		}
		switch (Port_Pins[Pin].Port_PinInitMode)  /* NOTE: TO BE COMPLETED.. */
		{
			case 2:          /* ADC Mode */
				break;       
			case 3:          /* CAN Mode */
				break;
			case 4:          /* DIO Mode */
				break;
			case 5:          /* DIO GPT Mode */
				break;
			case 6:          /* DIO WDG Mode */
				break;
			case 7:          /* FlexRay Mode */
				break;
			case 8:          /* ICU Mode */
				break;
			case 9:          /* LIN Mode */
				break;
			case 10:         /* MEM Mode */
				break;
			case 11:         /* PWM Mode */
				break;
			case 12:         /* SPI Mode */
				break;
			default:
				break;
		}
	}
}
#endif /* (PORT_SET_PIN_MODE_API == STD_ON) */



/**************************************************************/
/*           Private Functions Definitions                    */
/*               Port_InitDevErrorCheck                       */
boolean STATIC Port_InitDevErrorCheck(uint8 Service_Id)
{
	if (PORT_NOT_INITIALIZED == Port_Status)
	{
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
			Service_Id, PORT_E_UNINIT);
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}