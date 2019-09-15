/******************************************************************************
* Module:      Port
* File Name:   Port.c
* Description: Source file for Port device driver APIs implementation,
*              implementation is based on AUTOSAR specfications.
* Author:      Abdulmaguid Eissa
* Date:        Sep 12, 2019
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
* Service Name: Port_InitDevErrorCheck
* Return value: TRUE, if initialized
                FALSE, if not initialized.
* Description:  Check port initialization status and report error.
****************************************************************/
boolean STATIC Port_InitDevErrorCheck(uint8 Service_Id);

/****************************************************************
* Service Name: PortDirection_Init
* Param value:  register value
				direction: in/out
				pin number
* Description:  locally initialize port pins direction
****************************************************************/
void STATIC PortDirection_Init(uint32 reg, Port_PinType pin, Port_PinDirectionType dir);

/* File specific varaibles declarations */
STATIC Port_ConfigPin * Port_Pins = NULL_PTR;             /* Pointer to config Pin struct first element */
STATIC uint8 Port_Status          = PORT_NOT_INITIALIZED;
STATIC volatile uint32 delay = 0;

/***************************************************************
*                    Functions Definitions                     *
****************************************************************
/*              Port_Init Service definition                   */
/* If the register can affect several hardware modules and if it
   is an I/O register it shall be initialised by this PORT driver.  
   If the register can affect several hardware modules and if it 
   is not an I/O register, it shall be initialised by the MCU driver. 
*/
void Port_Init(const Port_ConfigType* ConfigPtr)
{
	boolean error   = FALSE;
	uint8 pin_index = 0;
#if (PORT_PIN_INITIAL_MODE == STD_ON)
	uint32 * ModeRegister_Ptr = NULL_PTR;
#endif // (PORT_PIN_INITIAL_MODE == STD_ON)
	uint32 * DigRegister_Ptr   = NULL_PTR;
	uint32 * AltFnRegister_Ptr = NULL_PTR;
	uint32 * AngFnRegister_Ptr = NULL_PTR;
	uint32 * Direction_Ptr     = NULL_PTR;

#if (PORT_DEV_ERROR_DETECT == STD_ON) /* Report Errors */
	if (NULL_PTR == ConfigPtr)
	{
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, 
			PORT_INIT_SID, PORT_E_PARAM_CONFIG);
		error = TRUE;
	}
	else
	{
		/* No Action Required */
	}
#endif /* (PORT_DEV_ERROR_DETECT == STD_ON) */
	Port_Pins = ConfigPtr->Pins;   /* Address of the first Pin */

	if (FALSE == error)
	{
		/* Initiate the I/O registers */
		for (pin_index = 0; pin_index < PORT_CONFIG_PORT_PINS; pin_index++)
		{
			SET_BIT(SYSCTL_RCGC2_R, Port_Pins[pin_index].Port_RegNumber);             /* GPIO clock source enable */
			delay = SYSCTL_RCGC2_R;
			switch (Port_Pins[pin_index].Port_RegNumber)
			{
				case PORTA:            /* Port A */
#if (PORT_PIN_INITIAL_MODE == STD_ON)
					ModeRegister_Ptr = &GPIO_PORTA_PCTL_R;          /* This register is changeable */
#endif // (PORT_PIN_INITIAL_MODE == STD_ON)
					DigRegister_Ptr = &GPIO_PORTA_DEN_R;
					Direction_Ptr = &GPIO_PORTA_DIR_R;
					AltFnRegister_Ptr = &GPIO_PORTA_AFSEL_R;
					AngFnRegister_Ptr = &GPIO_PORTA_AMSEL_R;
					break;
				case PORTB:             /* Port B */
#if (PORT_PIN_INITIAL_MODE == STD_ON)
					ModeRegister_Ptr = &GPIO_PORTB_PCTL_R;          /* This register is changeable */
#endif // (PORT_PIN_INITIAL_MODE == STD_ON)				
					DigRegister_Ptr = &GPIO_PORTB_DEN_R;
					Direction_Ptr = &GPIO_PORTB_DIR_R;
					AltFnRegister_Ptr = &GPIO_PORTB_AFSEL_R;
					AngFnRegister_Ptr = &GPIO_PORTB_AMSEL_R;
					break;
				case PORTC:              /* Port C */
#if (PORT_PIN_INITIAL_MODE == STD_ON)
					ModeRegister_Ptr = &GPIO_PORTC_PCTL_R;          /* This register is changeable */
#endif // (PORT_PIN_INITIAL_MODE == STD_ON)				
					DigRegister_Ptr = &GPIO_PORTC_DEN_R;
					Direction_Ptr = &GPIO_PORTC_DIR_R;
					AltFnRegister_Ptr = &GPIO_PORTC_AFSEL_R;
					AngFnRegister_Ptr = &GPIO_PORTC_AMSEL_R;
					break;
				case PORTD:             /* Port D */
#if (PORT_PIN_INITIAL_MODE == STD_ON)
					ModeRegister_Ptr = &GPIO_PORTD_PCTL_R;          /* This register is changeable */
#endif // (PORT_PIN_INITIAL_MODE == STD_ON)
					DigRegister_Ptr = &GPIO_PORTD_DEN_R;
					Direction_Ptr = &GPIO_PORTD_DIR_R;
					AltFnRegister_Ptr = &GPIO_PORTD_AFSEL_R;
					AngFnRegister_Ptr = &GPIO_PORTD_AMSEL_R;
					break;
				case PORTE:              /* Port E */
#if (PORT_PIN_INITIAL_MODE == STD_ON)
					ModeRegister_Ptr = &GPIO_PORTE_PCTL_R;          /* This register is changeable */
#endif // (PORT_PIN_INITIAL_MODE == STD_ON)
					DigRegister_Ptr = &GPIO_PORTE_DEN_R;
					Direction_Ptr = &GPIO_PORTE_DIR_R;
					AltFnRegister_Ptr = &GPIO_PORTE_AFSEL_R;
					AngFnRegister_Ptr = &GPIO_PORTE_AMSEL_R;
					break;
				case PORTF:              /* Port F */
#if (PORT_PIN_INITIAL_MODE == STD_ON)
					ModeRegister_Ptr = &GPIO_PORTF_PCTL_R;          /* This register is changeable */
#endif // (PORT_PIN_INITIAL_MODE == STD_ON)
					DigRegister_Ptr = &GPIO_PORTF_DEN_R;
					Direction_Ptr = &GPIO_PORTF_DIR_R;
					AltFnRegister_Ptr = &GPIO_PORTF_AFSEL_R;
					AngFnRegister_Ptr = &GPIO_PORTF_AMSEL_R;
					break;
				default:
					break;
			}

			PortDirection_Init(*Direction_Ptr, Port_Pins[pin_index].Port_PinNumber,      /* Initiate pin direction */
				Port_Pins[pin_index].Port_PinDirection);	

			/* Default settings, set registers as Dio */
#if (PORT_PIN_INITIAL_MODE == STD_OFF)
			CLEAR_VAL(*ModeRegister_Ptr, PORT_PIN_CONFIG_MODE_DIO_CLEAR);                /* Clear configured pins */
			SET_VAL(*ModeRegister_Ptr, PORT_PIN_CONFIG_MODE_DIO_SET);                    /* Set configured pins as DIO */																			     
#elif (PORT_PIN_INITIAL_MODE == STD_ON)												     
			SET_BIT(*AltFnRegister_Ptr, Port_Pins[pin_index].Port_PinNumber);            /* Enable alternate function */
			switch (Port_Pins[pin_index].Port_PinInitMode)
			{
				case PORT_PIN_MODE_ADC:          /* ADC Mode */
					ModeRegister_Ptr = &SYSCTL_RCGC0_R;
					CLEAR_BIT(*DigRegister_Ptr, Port_Pins[pin_index].Port_PinNumber);        /* Disable digital */
					delay = SYSCTL_RCGC0_R;
					SET_BIT(*AngFnRegister_Ptr, Port_Pins[pin_index].Port_PinNumber);        /* Enable analog function */
					SET_VAL(*ModeRegister_Ptr, PORT_PIN_CONFIG_MODE_ADC_SET);                /* Set configured pins as ADC */
					break;
				case PORT_PIN_MODE_DIO:          /* DIO Mode */
					SET_BIT(*DigRegister_Ptr, Port_Pins[pin_index].Port_PinNumber);          /* Enable Digital */
					CLEAR_BIT(*AngFnRegister_Ptr, Port_Pins[pin_index].Port_PinNumber);      /* Disable analog function */
					CLEAR_VAL(*ModeRegister_Ptr, PORT_PIN_CONFIG_MODE_DIO_CLEAR);            /* Clear configured pins */
					SET_VAL(*ModeRegister_Ptr, PORT_PIN_CONFIG_MODE_DIO_SET);                /* Set configured pins as DIO */
					break;
				case PORT_PIN_MODE_ICU:          /* ICU Mode */
					SET_BIT(*DigRegister_Ptr, Port_Pins[pin_index].Port_PinNumber);          /* Enable Digital */
					CLEAR_BIT(*AngFnRegister_Ptr, Port_Pins[pin_index].Port_PinNumber);      /* Disable analog function */
					CLEAR_VAL(*ModeRegister_Ptr, PORT_PIN_CONFIG_MODE_ICU_CLEAR);            /* Clear configured pins as ICU */
					SET_VAL(*ModeRegister_Ptr, PORT_PIN_CONFIG_MODE_ICU_SET);                /* Set configured pins as ICU */
					break;
				case PORT_PIN_MODE_PWM:         /* PWM Mode */
					SET_BIT(*DigRegister_Ptr, Port_Pins[pin_index].Port_PinNumber);          /* Enable Digital */
					CLEAR_BIT(*AngFnRegister_Ptr, Port_Pins[pin_index].Port_PinNumber);      /* Disable analog function */
					CLEAR_VAL(*ModeRegister_Ptr, PORT_PIN_CONFIG_MODE_PWM_CLEAR);            /* Clear configured pins as PWM */
					SET_VAL(*ModeRegister_Ptr, PORT_PIN_CONFIG_MODE_PWM_SET);                /* Set configured pins as PWM */
					break;
				default:
					break;
			}
#endif // (PORT_PIN_INITIAL_MODE == STD_ON)
		}
	}
	Port_Status = PORT_INITIALIZED;
}

/**************************************************************/
/*        Port_SetPinDirection Service definition             */
/* Run time function */
#if (PORT_PIN_DIRECTION_CHANGEABLE == STD_ON)
void Port_SetPinDirection(Port_PinType Pin, Port_PinDirectionType Direction)
{
	uint32 * Direction_Ptr = NULL_PTR;
	boolean error = FALSE;

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
			case PORTA:
				Direction_Ptr = &GPIO_PORTA_DIR_R;
				break;
			case PORTB:
				Direction_Ptr = &GPIO_PORTB_DIR_R;
				break;
			case PORTC:
				Direction_Ptr = &GPIO_PORTC_DIR_R;
				break;
			case PORTD:
				Direction_Ptr = &GPIO_PORTD_DIR_R;
				break;
			case PORTE:
				Direction_Ptr = &GPIO_PORTE_DIR_R;
				break;
			case PORTF:
				Direction_Ptr = &GPIO_PORTE_DIR_R;
				break;
			default:
				break;
		}

		PortDirection_Init(*Direction_Ptr, Port_Pins[Pin].Port_PinNumber,
			Port_Pins[Pin].Port_PinDirChange);
	} /* (FALSE == error) */
	else
	{
		/* No Action Required */
	}
}
#endif 
/* (PORT_PIN_DIRECTION == STD_ON) */


/**************************************************************/
/*       Port_RefreshPortDirection Service definition         */
/* Run time function */
void Port_RefreshPortDirection(void)
{
	boolean error                    = FALSE;
	uint32 * DirectionRegister_Ptr   = NULL_PTR;
	Port_PinType pin_index = 0;
	
#if (PORT_DEV_ERROR_DETECT == STD_ON) /* Report Errors */
	error = Port_InitDevErrorCheck(PORT_REFRESH_PORT_DIRECTION_SID);
#endif /* (PORT_DEV_ERROR_DETECT == STD_ON) */

	if (FALSE == error)
	{
		for (pin_index = 0; PORT_CONFIG_PORT_PINS > pin_index; pin_index++)
		{
			switch (Port_Pins[pin_index].Port_RegNumber)
			{
				case PORTA:
					DirectionRegister_Ptr = &GPIO_PORTA_DIR_R;
					break;
				case PORTB:
					DirectionRegister_Ptr = &GPIO_PORTB_DIR_R;
					break;
				case PORTC:
					DirectionRegister_Ptr = &GPIO_PORTC_DIR_R;
					break;
				case PORTD:
					DirectionRegister_Ptr = &GPIO_PORTD_DIR_R;
					break;
				case PORTE:
					DirectionRegister_Ptr = &GPIO_PORTE_DIR_R;
					break;
				case PORTF:
					DirectionRegister_Ptr = &GPIO_PORTE_DIR_R;
					break;
				default:
					break;
			}

			PortDirection_Init(*DirectionRegister_Ptr, Port_Pins[pin_index].Port_RegNumber,
				Port_Pins[pin_index].Port_PinDirection);
		} /* while (PORT_CONFIG_PORT_PINS > Configured_Pins_Index) */
	}
}

/**************************************************************/
/*        Port_GetVersionInfo Service definition              */
#if (PORT_VERSION_INFO_API == STD_ON)
void Port_GetVersionInfo(Std_VersionInfoType* versioninfo)
{
	boolean error = FALSE;
/* Report Error */
#if (PORT_DEV_ERROR_DETECT == STD_ON) 
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
/* Run time function 
   Only I/O function shall be initialized using Port device driver
   and the other functions shall be initialized using the MCU driver */
#if (PORT_SET_PIN_MODE_API == STD_ON)
void Port_SetPinMode(Port_PinType Pin, Port_PinModeType Mode)
{
	boolean error              = FALSE;
	uint32 * ModeRegister_Ptr  = NULL_PTR;
	
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

	/* Return immediately if the pin mode is not changeable */
	if (PORT_PIN_MODE_CHANGEABLE == STD_OFF)         
	{
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
			PORT_SET_PIN_MODE_SID, PORT_E_MODE_UNCHANGEABLE);
		return;
	}
#endif /* (PORT_DEV_ERROR_DETECT == STD_ON) */

	if (FALSE == error)
	{
		switch (Port_Pins[Pin].Port_RegNumber) /* Register assignment */
		{
			case PORTA:            /* Port A */
				ModeRegister_Ptr = &GPIO_PORTA_PCTL_R;          /* This register is changeable */
				break;
			case PORTB:             /* Port B */
				ModeRegister_Ptr = &GPIO_PORTB_PCTL_R;
				break;
			case PORTC:              /* Port C */
				ModeRegister_Ptr = &GPIO_PORTC_PCTL_R;
				break;
			case PORTD:             /* Port D */
				ModeRegister_Ptr = &GPIO_PORTD_PCTL_R;
				break;
			case PORTE:              /* Port E */
				ModeRegister_Ptr = &GPIO_PORTE_PCTL_R;
				break;
			case PORTF:              /* Port F */
				ModeRegister_Ptr = &GPIO_PORTF_PCTL_R;
				break;
			default:
				break;
		}
		switch (Mode)  
		{
			case PORT_PIN_MODE_ADC:          /* ADC Mode */
				ModeRegister_Ptr = &SYSCTL_RCGC0_R;
				SET_VAL(*ModeRegister_Ptr, PORT_PIN_CONFIG_MODE_ADC_SET);           /* Set configured pins as ADC */
				delay = SYSCTL_RCGC0_R;
				break;       
			case PORT_PIN_MODE_DIO:          /* DIO Mode */
				CLEAR_VAL(*ModeRegister_Ptr, PORT_PIN_CONFIG_MODE_DIO_CLEAR);      /* Clear configured pins */
				SET_VAL(*ModeRegister_Ptr, PORT_PIN_CONFIG_MODE_DIO_SET);          /* Set configured pins as DIO */
				break;
			case PORT_PIN_MODE_ICU:          /* ICU Mode */
				CLEAR_VAL(*ModeRegister_Ptr, PORT_PIN_CONFIG_MODE_ICU_CLEAR);      /* Clear configured pins */
				SET_VAL(*ModeRegister_Ptr, PORT_PIN_CONFIG_MODE_ICU_SET);          /* Set configured pins as ICU */
				break;
			case PORT_PIN_MODE_PWM:         /* PWM Mode */
				CLEAR_VAL(*ModeRegister_Ptr, PORT_PIN_CONFIG_MODE_PWM_CLEAR);      /* Clear configured pins */
				SET_VAL(*ModeRegister_Ptr, PORT_PIN_CONFIG_MODE_PWM_SET);          /* Set configured pins as PWM */
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

/**************************************************************/
/*                   PortDirection_Init                       */
void STATIC PortDirection_Init(uint32 reg, Port_PinType pin, 
	Port_PinDirectionType dir)
{
	if (PORT_PIN_OUT == dir)
	{
		SET_BIT(reg, pin);
	}
	else if (PORT_PIN_IN == dir)
	{
		CLEAR_BIT(reg, pin);
	}
	else
	{
		/* No action required */
	}
}