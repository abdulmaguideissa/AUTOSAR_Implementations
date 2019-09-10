/************************************************************
* Module:      Adc SWS.
* File Name:   Adc.h
* Description: Header file of the MCAL Adc module 
               based on the AUTOSAR Compiler SWS.
* Author:      Abdulmaguid Eissa.
*************************************************************/

#ifndef ADC_H
#define ADC_H

/* ADC SWS Vendor Id */
#define ADC_VENDOR_ID                    (2020U)

/* ADC SWS Module Id */
#define ADC_MODULE_ID                    (123U)

/* ADC Instance Id */
#define ADC_INSTANCE_ID                  (0U)

/*
* SW Module Version is 1.0.0
*/
#define ADC_SW_MAJOR_VERSION             (1U)
#define ADC_SW_MINOR_VERSION             (0U)
#define ADC_SW_PATCH_VERSION             (0U)

/*
* AUTOSAR Version is 4.3.1 compatible
*/
#define ADC_AR_RELEASE_MAJOR_VERSION     (4U) 
#define ADC_AR_RELEASE_MINOR_VERSION     (3U)
#define ADC_AR_RELEASE_PATCH_VERSION     (1U)

/* Adc Initialization checking Macros */
#define ADC_INITIALIZED                 (1U)
#define ADC_NOT_INITIALIZED             (0U)

#include "Std_Types.h"
/* For release version compatibility checking */
#if ((ADC_AR_RELEASE_MAJOR_VERSION != STD_TYPES_AR_RELEASE_MAJOR_VERSION)\
  || (ADC_AR_RELEASE_MINOR_VERSION != STD_TYPES_AR_RELEASE_MINOR_VERSION)\
  || (ADC_AR_RELEASE_PATCH_VERSION != STD_TYPES_AR_RELEASE_PATCH_VERSION))
	#error "The AR release of Adc does not match the expected Std_Types release"
#endif 

#include "Adc_Cfg.h"
/* For release version compatibility checking */
#if ((ADC_AR_RELEASE_MAJOR_VERSION != ADC_CFG_AR_RELEASE_MAJOR_VERSION)\
  || (ADC_AR_RELEASE_MINOR_VERSION != ADC_CFG_AR_RELEASE_MINOR_VERSION)\
  || (ADC_AR_RELEASE_PATCH_VERSION != ADC_CFG_AR_RELEASE_PATCH_VERSION))
#error "The AR release of Adc does not match the expected Adc cfg release"
#endif 
/* For SW version compatibility checking */
#if ((ADC_CFG_SW_MAJOR_VERSION != ADC_SW_MAJOR_VERSION)\
  || (ADC_CFG_SW_MINOR_VERSION != ADC_SW_MINOR_VERSION)\
  || (ADC_CFG_SW_PATCH_VERSION != ADC_SW_PATCH_VERSION))
#error "The SW of Adc does not match the expected Adc Cfg release"
#endif 

/***************************************************************
*                     ADC APIs service Ids                     *
***************************************************************/
/* Service Id for Adc initialization */
#define ADC_INIT_SID                     (0x00)

/* Service Id for Adc uninitializing the Adc hardware */
#define ADC_DEINIT_SID                   (0x01)

/* Service Id for Adc module version information */
#define ADC_GET_VERSION_INFO_SID         (0x0A)

/***************************************************************
*                       DET Error Codes                       *
***************************************************************/
/* Development Error Code 
   Relatd to Adc_Init */
#define ADC_E_UNINIT                     (0x0A)

/* Runtime Error Code
   Related to Adc_StartGroupConversion */
#define ADC_E_BUSY                       (0x0B)

/* Runtime Error Code 
   Relatd to Adc_StopGroupConversion */
#define ADC_E_IDLE                       (0x0C)

/* Development Error Code 
   Related to Adc_Init */
#define ADC_E_ALREADY_INITIALIZED        (0x0D)

/* Development Error Code 
   Related to Adc_Init, NULL_PTR passed */
#define ADC_E_PARAM_CONFIG               (0x0E)

/* Development Error Code
   Related to Adc_SetupResultBuffer, NULL_PTR passed */
#define ADC_E_PARAM_POINTER              (0x14)

/* Development Error Code 
   Invalid group Id request */
#define ADC_E_PARAM_GROUP                (0x15)

/* Development Error Code 
   HW trigger call with continuous conversion mode */
#define ADC_E_WRONG_CONV_MODE            (0x16)

/* Development Error Code 
   Adc_StartGroupConversion or Adc_StopGroupConversion called 
   on a group with trigger source configured as hardware */
#define ADC_E_WRONG_TRIGG_SRC            (0x17)

/* Development Error Code 
   Enable/disable notification function for a group whose 
   configuration set has no notification available */
#define ADC_E_NOTIF_CAPABILITY           (0x18)

/* Development Error Code
   Conversion started and result buffer pointer is not initialized */
#define ADC_E_BUFFER_UNINIT              (0x19) 

/* Runtime Error Code 
   One or more ADC group/channel not in IDLE state */
#define ADC_E_NOT_DISENGAGED             (0x1A)

/***************************************************************
*                      Type Definitions                        *
***************************************************************/
#if (ADC_TRIGGER_SOURCE_MODE == STD_ON)
/* Adc trigger source type */
typedef uint8 Adc_TriggerSourceType;
#define	ADC_TRIGG_SRC_SW                 ((Adc_TriggerSourceType)0U)
#define	ADC_TRIGG_SRC_HW                 ((Adc_TriggerSourceType)1U)
#endif /* (TRIGGER_SOURCE_MODE == STD_ON) */

/* Adc Channel Configuration Type */
typedef struct
{
	uint8  Adc_PortId;           // TO BE ADDED IN THE PORT SWS IMPLEMENTATION
	uint8  Adc_ChannelId;
	uint8  Adc_ChannelResolution;
	uint32 Adc_SampleRate;
	Adc_TriggerSourceType Adc_TriggerSource;
}Adc_ConfigChannel;

/* Adc Configuration Type */
typedef struct
{
	Adc_ConfigChannel Adc_Channels[ADC_CONFIGURED_CHANNELS];
}Adc_ConfigType;

/* Adc Ch Type */
typedef uint8 Adc_ChannelType;

/* Adc group Type */
typedef uint8 Adc_GroupType;

/* Adc value group type to read converted values */
typedef sint32 Adc_ValueGroupType;

/* Adc clock prescaler type */
typedef uint8 Adc_PrescaleType;

/* Adc conversion time type */
typedef uint16 Adc_ConversionTimeType;

/* Adc sampling time type */
typedef uint16 Adc_SamplingTimeType;

/* Adc resolution type */
typedef uint8 Adc_ResolutionType;

/* Adc status type */
typedef uint8 Adc_StatusType;
#define	ADC_IDLE                            ((Adc_StatusType)0U)
#define	ADC_BUSY                            ((Adc_StatusType)1U)
#define	ADC_COMPLETED						((Adc_StatusType)2U)
#define	ADC_STREAM_COMPLETED				((Adc_StatusType)3U)

#if (ADC_GROUP_CONV_MODE == STD_ON)
/* Adc group conversion mode type */
typedef uint8 Adc_GroupConvModeType;
#define	ADC_CONV_MODE_ONESHOT               ((Adc_GroupConvModeType)0U)
#define	ADC_CONV_MODE_CONTINUOUS            ((Adc_GroupConvModeType)1U)
#endif /* (GROUP_CONV_MODE == STD_ON) */


/* Adc group priority type */
typedef uint8 Adc_GroupPriorityType;

#if (ADC_STREAM_SAMPLE_BUFFER_MODE == STD_ON)
/* Adc stream sample buffer mode type */
typedef uint8 Adc_StreamSampleBufferModeType;
#define	ADC_STREAM_BUFFER_LINEAR          ((Adc_StreamSampleBufferModeType)0U)
#define	ADC_STREAM_BUFFER_CIRCULAR        ((Adc_StreamSampleBufferModeType)1U)
#endif /* (STREAM_SAMPLE_BUFFER_MODE == STD_ON) */

#if (ADC_GROUP_ACCESS_MODE == STD_ON)
/* Adc group access mode type */
typedef uint8 Adc_GroupAccessModeType;
#define	ADC_ACCESS_MODE_SINGLE            ((Adc_GroupAccessModeType)0U)
#define	ADC_ACCESS_MODE_STREAMING         ((Adc_GroupAccessModeType)1U)
#endif /* (ADC_GROUP_ACCESS_MODE == STD_ON) */

#if (ADC_HW_TRIGGER_SIG_MODE == STD_ON)
/* Adc HW trigger signal type */
typedef uint8 Adc_HwTriggerSignalType;
#define	ADC_HW_TRIG_RISING_EDGE           ((Adc_HwTriggerSignalType)0U)
#define	ADC_HW_TRIG_FALLING_EDGE          ((Adc_HwTriggerSignalType)1U)
#define	ADC_HW_TRIG_BOTH_EDGES            ((Adc_HwTriggerSignalType)3U)
#endif /* (ADC_HW_TRIGGER_SIG_MODE == STD_ON) */

#if (ADC_PRIORITY_IMPLEMENTATION_MODE == STD_ON)
/* Adc priority implementation type */
typedef uint8 Adc_PriorityImplementationType;
#define	ADC_PRIORITY_NONE                 ((Adc_PriorityImplementationType)0U)
#define	ADC_PRIORITY_HW                   ((Adc_PriorityImplementationType)1U)
#define	ADC_PRIORITY_HW_SW                ((Adc_PriorityImplementationType)2U)
#endif /* (ADC_PRIORITY_IMPLEMENTATION_MODE == STD_ON) */


/***************************************************************
*                    Functions Prototypes                      *
****************************************************************/

/***************************************************************
* Service Name:       Adc_Init
* Service ID[hex]:    0x00
* Sync/Async:         Synchronous
* Reentrancy:         Non reentrant
* Parameters (in):    ConfigPtr - Pointer to configuration set in variant PB.
* Parameters (inout): None
* Parameters (out):   None
* Return value:       None
* Description:        Initializes the ADC hardware units and driver.
****************************************************************/
void Adc_Init(const Adc_ConfigType * ConfigPtr);

#if (SETUP_RESULT_BUFFER_API == STD_ON)
/***************************************************************
* Service Name:       Adc_SetupResultBuffer
* Service ID[hex]:    0x0C
* Sync/Async:         Synchronous
* Reentrancy:         Reentrant
* Parameters (in):    Group  Numeric ID of requested ADC channel group.
					  DataBufferPtr  pointer to result data buffer
* Parameters (inout): None
* Parameters (out):   None
* Return value:       Std_ReturnType  E_OK: result buffer pointer initialized correctly
									  E_NOT_OK: operation failed or development error
												occured
* Description:        Initializes ADC driver with the group specific
					  result buffer start address where the conversion
					  results will be stored. The application has to
					  ensure that the application buffer, where DataBufferPtr
					  points to, can hold all the conversion results of the
					  specified group. The initialization with Adc_SetupResultBuffer
					  is required after reset, before a group conversion
					  can be started.
****************************************************************/
Std_ReturnType Adc_SetupResultBuffer(Adc_GroupType Group,
	const Adc_ValueGroupType * DataBufferPtr);
#endif /* (SETUP_RESULT_BUFFER_API == STD_ON) */

#if (ADC_DEINT_API == STD_ON)
/***************************************************************
* Service Name:       Adc_DeInit
* Service ID[hex]:    0x01
* Sync/Async:         Synchronous
* Reentrancy:         Non reentrant
* Parameters (in):    None
* Parameters (inout): None
* Parameters (out):   None
* Return value:       None
* Description:        Returns all ADC HW Units to a state comparable to their 
				      power on reset state.
****************************************************************/
void Adc_DeInit(void);
#endif /* (ADC_DEINT_API == STD_ON) */

#if (ENALBLE_HW_TRIGGER_API == STD_ON)
/***************************************************************
* Service Name:       Adc_EnableHardwareTrigger
* Service ID[hex]:    0x05
* Sync/Async:         Synchronous
* Reentrancy:         Reentrant
* Parameters (in):    Group  Numeric ID of requested ADC Channel group.
* Parameters (inout): None
* Parameters (out):   None
* Return value:       None
* Description:        Enables the hardware trigger for the requested ADC Channel group.
****************************************************************/
void Adc_EnableHardwareTrigger(Adc_GroupType Group);
#endif /* (ENALBLE_HW_TRIGGER_API == STD_ON) */

#if (DISALBLE_HW_TRIGGER_API == STD_ON)
/***************************************************************
* Service Name:       Adc_DisableHardwareTrigger
* Service ID[hex]:    0x06
* Sync/Async:         Synchronous
* Reentrancy:         Reentrant
* Parameters (in):    Group  Numeric ID of requested ADC Channel group.
* Parameters (inout): None
* Parameters (out):   None
* Return value:       None
* Description:        Disables the hardware trigger for the requested ADC Channel group.
****************************************************************/
void Adc_DisableHardwareTrigger(Adc_GroupType Group);
#endif /* (DISALBLE_HW_TRIGGER_API == STD_ON) */

#if (GET_GROUP_STATUS_API == STD_ON)
/***************************************************************
* Service Name:       Adc_GetGroupStatus
* Service ID[hex]:    0x09
* Sync/Async:         Synchronous
* Reentrancy:         Reentrant
* Parameters (in):    Group  Numeric ID of requested ADC Channel group.
* Parameters (inout): None
* Parameters (out):   None
* Return value:       Adc_StatusType  Conversion status for the requested group. 
* Description:        Returns the conversion status of the requested ADC Channel group. 
****************************************************************/
Adc_StatusType Adc_GetGroupStatus(Adc_GroupType Group);
#endif /* (GET_GROUP_STATUS_API == STD_ON) */

#if (ADC_VERSION_INFO_API == STD_ON)
/***************************************************************
* Service Name:       Adc_GetVersionInfo
* Service ID[hex]:    0x0a
* Sync/Async:         Synchronous
* Reentrancy:         Reentrant
* Parameters (in):    None
* Parameters (inout): None
* Parameters (out):   versioninfo  Pointer to where to store the version information of this module. 
* Return value:       None
* Description:        Returns the version information of this module.
****************************************************************/
void Adc_GetVersionInfo(Std_VersionInfoType * versioninfo);
#endif /* ADC_VERSION_INFO_API == STD_ON */

/* Extern PB configurtion structure to be used by the Adc.c */
extern const Adc_ConfigType Adc_Configuration;

#endif /* !ADC_H */
