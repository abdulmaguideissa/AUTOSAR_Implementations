/*****************************************************************
* Module:      Adc
* File Name:   Adc_PBcfg.c
* Description: Source file for Adc post build Module configuration definition,
*			   implementation is based on AUTOSAR specfications.
*              Contains symbolic names definitions.
* Author:      Abdulmaguid Eissa
*******************************************************************/


/*
* SW Module Version is 1.0.0
*/
#define ADC_PBCFG_SW_MAJOR_VERSION             (1U)
#define ADC_PBCFG_SW_MINOR_VERSION             (0U)
#define ADC_PBCFG_SW_PATCH_VERSION             (0U)

/*
* AUTOSAR Version is 4.3.1 compatible
*/
#define ADC_PBCFG_AR_RELEASE_MAJOR_VERSION     (4U) 
#define ADC_PBCFG_AR_RELEASE_MINOR_VERSION     (3U)
#define ADC_PBCFG_AR_RELEASE_PATCH_VERSION     (1U)

#include "Adc.h"
/* For release version compatibility checking */
#if ((ADC_AR_RELEASE_MAJOR_VERSION != ADC_PBCFG_AR_RELEASE_MAJOR_VERSION)\
  || (ADC_AR_RELEASE_MINOR_VERSION != ADC_PBCFG_AR_RELEASE_MINOR_VERSION)\
  || (ADC_AR_RELEASE_PATCH_VERSION != ADC_PBCFG_AR_RELEASE_PATCH_VERSION))
#error "The AR release of Adc does not match the expected Adc PBcfg release"
#endif 

/* For SW version compatibility checking */
#if ((ADC_PBCFG_SW_MAJOR_VERSION != ADC_SW_MAJOR_VERSION)\
  || (ADC_PBCFG_SW_MINOR_VERSION != ADC_SW_MINOR_VERSION)\
  || (ADC_PBCFG_SW_PATCH_VERSION != ADC_SW_PATCH_VERSION))
#error "The SW of Adc does not match the expected Adc PBcfg release"
#endif 

/* PB configuration structure definition */
const Adc_ConfigType Adc_Configuration =
{
		AdcConf_PORT_ID, AdcConf_CHANNEL_ID, 
		AdcConf_RESOLUTION, AdcConf_SAMPLE_RATE, ADC_TRIGG_SRC_SW
};












