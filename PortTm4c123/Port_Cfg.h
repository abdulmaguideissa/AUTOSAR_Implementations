/*****************************************************************
* Module:      Port_Cfg
* File Name:   Port_Cfg.h
* Description: Header file for Port Module, 
*			   implementation is based on AUTOSAR specfications.
*              Contains symbolic names definitions.
* Author:      Abdulmaguid Eissa
* Date:        Sept 12, 2019   
*******************************************************************/

#ifndef PORT_CFG_H
#define PORT_CFG_H

/*
* SW Module Version is 1.0.0
*/
#define PORT_CFG_SW_MAJOR_VERSION             (1U)
#define PORT_CFG_SW_MINOR_VERSION             (0U)
#define PORT_CFG_SW_PATCH_VERSION             (0U)

/*
* AUTOSAR Version is 4.3.1 compatible
*/
#define PORT_CFG_AR_RELEASE_MAJOR_VERSION     (4U) 
#define PORT_CFG_AR_RELEASE_MINOR_VERSION     (3U)
#define PORT_CFG_AR_RELEASE_PATCH_VERSION     (1U)
											  

/* Number of configured Port Pins */
#define PORT_CONFIG_PORT_PINS                 (2U)

/* Number of configured Ports */
#define PORT_CONFIG_PORT_NUM                  (6U)

/* Number of configured port modes */
#define PORT_CONFIG_MODE_NUM                  (4U)

/* Precompile option for Development Error Detect */
#define PORT_DEV_ERROR_DETECT                 (STD_ON)
											  
/* Precompile option for setting Pin direction API */
#define PORT_SET_PIN_DIRECTION_API            (STD_ON)
											  
/* Precompile option for version info API */  
#define PORT_VERSION_INFO_API                 (STD_ON)

/* Precompile option to set pin mode API */
#define PORT_SET_PIN_MODE_API                 (STD_ON)

/* Precompile and Post Build option for setting the Pin direction,
   according to its mode E.g. a pin used for an ADC must be configured
   to be an in port. */
#define PORT_PIN_DIRECTION                    (STD_ON)

/* Precompile and Post Build option for changing a Pin 
   direction during runtime */
#define PORT_PIN_DIRECTION_CHANGEABLE         (STD_ON)

/* Precompile and Post Build option for setting initial Pin mode 
   to be ADC, DIO, LIN, .. */
#define PORT_PIN_INITIAL_MODE                 (STD_ON)

/* Precompile and Post Build option for setting 
   Port Pin Level value from Port pin list. */
#define PORT_PIN_LEVEL_VALUE                  (STD_OFF)

/* Precompile and Post Build option for setting Pin mode
to be ADC, DIO, LIN, .. */
#define PORT_PIN_MODE                         (STD_ON)

/* Precompile and Post Build option for Port pin mode changeability */
#define PORT_PIN_MODE_CHANGEABLE              (STD_ON)

/* Port Pin Level value from Port pin list */
#if (PORT_PIN_LEVEL_VALUE == STD_ON)
#define PORT_PIN_LEVEL_HIGH                   (STD_HIGH)
#define PORT_PIN_LEVEL_HIGH                   (STD_LOW)
#endif /* (PORT_PIN_LEVEL_VALUE == STD_ON) */

/* Pin index in PortConfig structure in Port_PBcfg.c file */
#define PortConf_PWM_STRL_PIN_ID_INDEX        ((uint8)0x00)              /* steering left motor */
#define PortConf_PWM_STRR_PIN_ID_INDEX        ((uint8)0x01)              /* Steering right motor */
											  
/* Configured Port IDs */					

#define PortConf_PWM_STRL_PORT_REG            ((Port_PinType)1)
#define PortConf_PWM_STRR_PORT_REG            ((Port_PinType)1)
											  
/* Configured Port Pin numbers */			 
#define PortConf_PWM_STRL_PIN_NUM             ((Port_PinType)4)
#define PortConf_PWM_STRR_PIN_NUM		      ((Port_PinType)5)
											  
/* Configured Port Pin direction */			  
#define PortConf_PWM_STRL_PIN_DIRECTION       ((Port_PinDirectionType)PORT_PIN_OUT) /* TO BE EDITTED */
#define PortConf_PWM_STRR_PIN_DIRECTION       ((Port_PinDirectionType)PORT_PIN_OUT)

#endif /* PORT_CFG_H */
