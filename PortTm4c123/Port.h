/***************************************************************
* Module:      Port
* File Name:   Port.h
* Description: Header file for Port Module, 
*              implementation is based on AUTOSAR specfications.
* Author:      Abdulmaguid Eissa
* Date:        Sept 12, 2019
****************************************************************/

#ifndef PORT_H
#define PORT_H


/* Port Vendor ID in AUTOSAR */
#define PORT_VENDOR_ID                    (2020U)

/* Port Module ID in AUTOSAR */
#define	PORT_MODULE_ID					  (124U)

/* Port Instance ID */
#define PORT_INSTANCE_ID                  (0U)

/* Sytem clock configuration */
#define PORT_SYSTEM_CLOCK                 (1000000UL)

/* 
 * SW Module Version is 1.0.0 
 */
#define PORT_SW_MAJOR_VERSION             (1U)
#define PORT_SW_MINOR_VERSION             (0U)
#define PORT_SW_PATCH_VERSION             (0U)

/* 
 * AUTOSAR Version is 4.0.3 compatible 
 */
#define PORT_AR_RELEASE_MAJOR_VERSION    (4U) 
#define PORT_AR_RELEASE_MINOR_VERSION    (3U)
#define PORT_AR_RELEASE_PATCH_VERSION    (1U)

/* Port Initialization checking Macros */
#define PORT_INITIALIZED                 (1U)
#define PORT_NOT_INITIALIZED             (0U)

/* Standard AUTOSAR types */
#include "Std_Types.h"

/* Check compatibility of Port.h AUTOSAR version with 
 * Std_Types AUTOSAR version.
 */
#if ((STD_TYPES_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Std_Types.h does not match the expected version"
#endif

/**************************************************************
 *                     Non AUTOSAR files                      *
 **************************************************************/
/*
 * Microcontroller specific configurations 
 */
#include "tm4c123gh6pm.h"

/* Macros for hardware initializations */
#include "Bit_Manipulation.h"

/***************************************************************
 *                    API Service ID Macros                    *
****************************************************************/
/* Service ID for initializing Port device */
#define PORT_INIT_SID                    ((uint8)0x00)

/* Service ID for setting a Pin direction to be input/output */
#define PORT_SET_PIN_DIRECTION_SID       ((uint8)0x01)

/* Service ID for refreshing the config Ports to the config direction */
#define PORT_REFRESH_PORT_DIRECTION_SID  ((uint8)0x02)

/* Service ID to return the version info of Port module */
#define PORT_GET_VERSION_INFO_SID        ((uint8)0x03)

/* Service ID for setting the Port pin mode of the referenced pin */
#define PORT_SET_PIN_MODE_SID            ((uint8)0x04)

/***************************************************************
 *                       DET Error Codes                       * 
 ***************************************************************/
/* Invalid Port ID request */
#define PORT_E_PARAM_PIN                 ((uint8)0x0A)

/* Port Pin not configured as changeable */
#define PORT_E_DIRECTION_UNCHANGEABLE    ((uint8)0x0B)

/* API Port_Init service called with wrong parameters */
#define PORT_E_PARAM_CONFIG              ((uint8)0x0C)

/* API Port_SetPinMode service called with invalid mode */
#define PORT_E_PARAM_INVALID_MODE        ((uint8)0x0D)

/* API Port_SetPinMode service called, when mode is unchangeable */
#define PORT_E_MODE_UNCHANGEABLE         ((uint8)0x0E)

/* API sevice called without module initialization */
#define PORT_E_UNINIT                    ((uint8)0x0F)

/* APIs called with a NULL Pointer, Error shall be reported */
#define PORT_E_PARAM_POINTER             ((uint8)0x10)

/***************************************************************
*                Port Names and Pins Modes                     *
****************************************************************/
/* Each value of the following definitions is a Port specific
   value, meaning that you need to change this value if you switch
   to use another Port module according to the uC datasheet
   Demo for UART0 of Tivac uC:
   #define PORT_PIN_CONFIG_MODE_UART_SET   (0x00000011)
   #define PORT_PIN_CONFIG_MODE_UART_CLEAR (0x000000FF) */

/* Port A */
#define PORTA     (0)
/* Port B */
#define PORTB     (1)
/* Port C */
#define PORTC     (2)
/* Port D */
#define PORTD     (3)
/* Port E */
#define PORTE     (4)
/* Port F */
#define PORTF     (5)

/* Adc set value */
#define PORT_PIN_CONFIG_MODE_ADC_SET         (0x0053)  /* Place holder number */
/* Adc clear value */
#define PORT_PIN_CONFIG_MODE_ADC_CLEAR       (0x0000)
/* Dio set value */
#define PORT_PIN_CONFIG_MODE_DIO_SET         (0x0053)
/* Dio clear value */
#define PORT_PIN_CONFIG_MODE_DIO_CLEAR       (0x0053)
/* Icu set value */
#define PORT_PIN_CONFIG_MODE_ICU_SET         (0x0053)
/* Icu clear value */
#define PORT_PIN_CONFIG_MODE_ICU_CLEAR       (0x0053)
/* Pwm set value */
#define PORT_PIN_CONFIG_MODE_PWM_SET         (0x0053)
/* Pwm clear value */
#define PORT_PIN_CONFIG_MODE_PWM_CLEAR       (0x0053)


/***************************************************************
*                        Module Data Types                     *
****************************************************************/
/* Port pin type, pins number is MCU specific. */
typedef uint8 Port_PinType;

/* Port pin direction type, pin direction is MCU specific.
Values of this enumeration are based on the MCU architecture that is being used */
typedef uint8 Port_PinDirectionType;
#define	PORT_PIN_IN                   ((Port_PinDirectionType)0)
#define	PORT_PIN_OUT				  ((Port_PinDirectionType)1)

/* Port device driver configurations */
#include "Port_Cfg.h"

/* Check compatibility of Port.h AUTOSAR version with
* Port_Cfg.h AUTOSAR version.
*/
#if ((PORT_CFG_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (PORT_CFG_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (PORT_CFG_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
#error "The AR version of Port_Cfg.h does not match the expected version"
#endif

/* Check compatibility of Port.h SW version with
* Port_Cfg.h SW version.
*/
#if ((PORT_CFG_SW_MAJOR_VERSION != PORT_SW_MAJOR_VERSION)\
 ||  (PORT_CFG_SW_MINOR_VERSION != PORT_SW_MINOR_VERSION)\
 ||  (PORT_CFG_SW_PATCH_VERSION != PORT_SW_PATCH_VERSION))
#error "The AR version of Port_Cfg.h does not match the expected version"
#endif

/* Port pin mode type, enumeration for pins number, it is MCU specific. */
#if ((PORT_PIN_MODE == STD_ON) || (PORT_PIN_INITIAL_MODE == STD_ON))
typedef uint8 Port_PinModeType;
#define	PORT_PIN_MODE_ADC             ((Port_PinModeType)0)
#define	PORT_PIN_MODE_DIO             ((Port_PinModeType)1)
#define	PORT_PIN_MODE_ICU             ((Port_PinModeType)2)
#define	PORT_PIN_MODE_PWM             ((Port_PinModeType)3)
#endif /* (PORT_PIN_MODE == STD_ON) */

/* Port configuration.
Highly dependent on the used MCU.
*/
typedef struct
{
	uint8        Port_RegNumber;
	Port_PinType Port_PinNumber;
	Port_PinType Port_PinDirection;
#if (PORT_PIN_INITIAL_MODE == STD_ON)
	Port_PinModeType Port_PinInitMode;
#endif /* (PORT_PIN_INITIAL_MODE == STD_ON) */
#if (PORT_PIN_LEVEL_VALUE == STD_ON)
	uint8 Port_LevelInitValue;
#endif /* (PORT_PIN_LEVEL_VALUE == STD_ON) */
#if (PORT_PIN_DIRECTION_CHANGEABLE == STD_ON)
	uint8 Port_PinDirChange;
#endif /* (PORT_PIN_DIRECTION_CHANGEABLE == STD_ON) */
}Port_ConfigPin;

/* Port configuration type,
structure of array of Port_ConfigPin structure */
typedef struct
{
	Port_ConfigPin Pins[PORT_CONFIG_PORT_PINS];
}Port_ConfigType;

/***************************************************************
*                    Functions Prototypes                      *
****************************************************************/

/***************************************************************
* Service Name:       Port_Init
* Service ID[hex]:    0x00
* Sync/Async:         Synchronous
* Reentrancy:         Non reentrant
* Parameters (in):    ConfigPtr - Pointer to configuration set.
* Parameters (inout): None
* Parameters (out):   None
* Return value:       None
* Description:        Initializes the Port Driver module.
****************************************************************/
void Port_Init(const Port_ConfigType* ConfigPtr);

/***************************************************************
* Service Name:       Port_SetPinDirection
* Service ID[hex]:    0x01
* Sync/Async:         Synchronous
* Reentrancy:         Reentrant
* Parameters (in):    Pin - Port Pin ID number,
                      Direction - Port Pin Direction.
* Parameters (inout): None
* Parameters (out):   None
* Return value:       None
* Description:        Sets the port pin direction.
****************************************************************/
#if (PORT_SET_PIN_DIRECTION_API == STD_ON)
	void Port_SetPinDirection(
		Port_PinType Pin,
		Port_PinDirectionType Direction);
#endif /* (PORT_SET_PIN_DIRECTION_API == STD_ON) */

/***************************************************************
* Service Name:       Port_RefreshPortDirection
* Service ID[hex]:    0x02
* Sync/Async:         Synchronous
* Reentrancy:         Non reentrant
* Parameters (in):    None
* Parameters (inout): None
* Parameters (out):   None
* Return value:       None
* Description:        Refreshes port direction.
****************************************************************/
void Port_RefreshPortDirection(void);

/***************************************************************
* Service Name:       Port_GetVersionInfo
* Service ID[hex]:    0x03
* Sync/Async:         Synchronous
* Reentrancy:         Non reentrant
* Parameters (in):    None
* Parameters (inout): None
* Parameters (out):   versioninfo - Pointer to where to store the version information of this module.
* Return value:       None
* Description:        Returns the version information of this module.
****************************************************************/
#if (PORT_VERSION_INFO_API == STD_ON)
	void Port_GetVersionInfo(Std_VersionInfoType* versioninfo);
#endif /* (PORT_VERSION_INFO_API == STD_ON) */

/***************************************************************
* Service Name:       Port_SetPinMode 
* Service ID[hex]:    0x04
* Sync/Async:         Synchronous
* Reentrancy:         Reentrant
* Parameters (in):    Pin - Port Pin ID number,
                      Mode - New Port Pin mode to be set on port pin. 
* Parameters (inout): None
* Parameters (out):   None.
* Return value:       None
* Description:        Sets the port pin mode.
****************************************************************/
#if (PORT_SET_PIN_MODE_API == STD_ON)
	void Port_SetPinMode(
		Port_PinType Pin,
		Port_PinModeType Mode);
#endif /* (PORT_SET_PIN_MODE_API == STD_ON) */

/* External Post Build Structure to be linked to PBcfg.c when used by other modules */
extern const Port_ConfigType Port_CanConfig;

#endif /* PORT_H */
