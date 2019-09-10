/*****************************************************************
* Module:      Adc
* File Name:   Adc_Cfg.h
* Description: Header file for Adc Module precompile configuration,
*			   implementation is based on AUTOSAR specfications.
*              Contains symbolic names definitions.
* Author:      Abdulmaguid Eissa
*******************************************************************/

#ifndef ADC_CFG_H
#define ADC_CFG_H

/*
* SW Module Version is 1.0.0
*/
#define ADC_CFG_SW_MAJOR_VERSION             (1U)
#define ADC_CFG_SW_MINOR_VERSION             (0U)
#define ADC_CFG_SW_PATCH_VERSION             (0U)

/*
* AUTOSAR Version is 4.3.1 compatible
*/
#define ADC_CFG_AR_RELEASE_MAJOR_VERSION     (4U) 
#define ADC_CFG_AR_RELEASE_MINOR_VERSION     (3U)
#define ADC_CFG_AR_RELEASE_PATCH_VERSION     (1U)

/* AUTOSAR configuration of the Adc module */
/* Adc DeInit Api */
#define ADC_DEINT_API                        (TRUE)

/* Adc read group Api */
#define ADC_READ_GROUP_API                   (TRUE)

/* Adc version info Api */
#define ADC_VERSION_INFO_API                 (TRUE)

/* Adc enable start, stop group Api */
#define ADC_ENABLE_START_STOP_GROUP_API      (STD_OFF)

/* Adc hw trigger Api */
#define ADC_HW_TRIGGER_API                   (STD_OFF)

/* Enable HW trigger Api */
#define ENALBLE_HW_TRIGGER_API               (STD_OFF)

/* Disable HW trigger Api */
#define DISALBLE_HW_TRIGGER_API              (STD_OFF)

/* Get group status Api */
#define GET_GROUP_STATUS_API                 (STD_OFF)     

/* Setup result buffer Api */
#define SETUP_RESULT_BUFFER_API              (STD_OFF)

/* Adc development error detection */
#define ADC_DEV_ERROR_DETECT                 (TRUE)

/* Adc enable limit check */
#define ADC_ENABLE_LIMIT_CHECK               (STD_OFF)

/* Adc enable queuing */
#define  ADC_ENABLE_QUEUING                  (STD_OFF)

/* Adc group notify capability */
#define ADC_GROUP_NOTIF_CAPABILITY           (STD_OFF)

/* Adc trigger source mode */
#define ADC_TRIGGER_SOURCE_MODE              (TRUE)

/* Adc group conversion mode */
#define ADC_GROUP_CONV_MODE                  (STD_OFF)

/* Adc sream sample buffer mode */
#define ADC_STREAM_SAMPLE_BUFFER_MODE        (STD_OFF)

/* Adc group access mode */
#define ADC_GROUP_ACCESS_MODE                (STD_OFF)

/* Adc hw trigger signal mode */
#define ADC_HW_TRIGGER_SIG_MODE              (STD_OFF)

/* Adc priority implementation mode */
#define ADC_PRIORITY_IMPLEMENTATION_MODE     (STD_OFF)

/* Adc priority specification */
#define ADC_PRIORITY_IMPLEMENTATION          (ADC_PRIORITY_NONE)

/* Adc group access mode type */
#define ADC_GROUP_ACCCESS_MODE               (ADC_ACCESS_MODE_SINGLE)

/* Adc group conversion mode */
#define ADC_GROUP_CONVERSION_MODE            (ADC_CONV_MODE_CONTINUOUS)

/* Adc group Id */
#define ADC_GROUP_ID                         ((Adc_GroupType)0U)

/* Number of configured Adc channels */
#define ADC_CONFIGURED_CHANNELS              (1U)

/* Adc configured ports Id */
/* PORTE */
#define AdcConf_PORT_ID                      ((uint8)4) 

/* Adc configured channel */
/* Pin 2 */
#define AdcConf_CHANNEL_ID                   ((Adc_ChannelType)0) 

/* Adc resolution number */
/* for 12-bit conversion */
#define AdcConf_RESOLUTION                   ((Adc_ResolutionType)12U)    

/* Adc sample rate, 125K sample/sec
   The number is uC specific */
#define AdcConf_SAMPLE_RATE                  ((uint32)0x00000300U)




#endif /* ADC_CFG_H */
