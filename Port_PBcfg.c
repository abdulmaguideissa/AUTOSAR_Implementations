/******************************************************************************
*
* Module: Port_PBcfg
*
* File Name: Port_PBcfg.c
*
* Description: Source file for post build time configurable parameters,
*              implementation is based on AUTOSAR specfications.
*
* Author: Abdulmaguid Eissa
* 
* Date:  May 26, 2019
******************************************************************************/

#include "Port.h"

/*
* SW Module Version is 1.0.0
*/
#define PORT_PBCFG_SW_MAJOR_VERSION             (1U)
#define PORT_PBCFG_SW_MINOR_VERSION             (0U)
#define PORT_PBCFG_SW_PATCH_VERSION             (0U)

/*
* AUTOSAR Version is 4.0.3 compatible
*/
#define PORT_PBCFG_AR_RELEASE_MAJOR_VERSION     (4U) 
#define PORT_PBCFG_AR_RELEASE_MINOR_VERSION     (0U)
#define PORT_PBCFG_AR_RELEASE_PATCH_VERSION     (3U)

/* Check compatibility of Port.h AUTOSAR version with
* Port_PBcfg.c AUTOSAR version.
*/
#if ((PORT_PBCFG_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (PORT_PBCFG_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (PORT_PBCFG_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
	#error "The AR version of Port.h does not match the expected version"
#endif

/* Check compatibility of Port.h SW version with
* Port_PBcfg.c SW version.
*/
#if ((PORT_PBCFG_SW_MAJOR_VERSION != PORT_SW_MAJOR_VERSION)\
 ||  (PORT_PBCFG_SW_MINOR_VERSION != PORT_SW_MINOR_VERSION)\
 ||  (PORT_PBCFG_SW_PATCH_VERSION != PORT_SW_PATCH_VERSION))
	#error "The AR version of Port.h does not match the expected version"
#endif

/* PB structure used with Port_Init API */
const Port_ConfigType Port_Configuration =
{
	PortConf_LED_PORT_REG, PortConf_LED_PIN_NUM, PortConf_LED_PIN_DIRECTION,
	PortConf_BUTTON_PORT_REG, PortConf_BUTTON_PIN_NUM, PortConf_BUTTON_PIN_DIRECTION
};



