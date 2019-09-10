/**************************************************************
* Non Autosar file.
* File name:  Tivac_Hw.h
* Decription: File that contains all the required APIs to initialize the
              hardware of the uC.
* Author:     Abdulmaguid Eissa.
***************************************************************/

#ifndef TIVAC_HW_H
#define TIVAC_HW_H

/* Fixed header files */
#include "Platform_Types.h"
#include "Bit_Manipulation.h"
#include "Adc.h"

#define OPERATION_INIT                        (TRUE)            /* Initialization operation */
#define OPERATION_DEINIT                      (FALSE)           /* UnInitialization operation */
#define SYSTEM_VOLTAGE                        (3.3F)

/***************************************************************
* Name:        ADC_InitChannel
* Inputs:      ch_num number of ADC channels
               struct_parameters structure pointer to the ADC parameters
* Outputs:     None
* Description: Initializing one Adc channel HW
****************************************************************/
void ADC_InitChannel(uint8 ch_num, Adc_ConfigChannel * adc_parameters);

/***************************************************************
* Name:        ADC_DeInitChannel
* Inputs:      ch_num number of ADC channels
			   struct_parameters structure pointer to the ADC parameters
* Outputs:     None
* Description: Resetting one Adc channel HW
****************************************************************/
void ADC_DeInitChannel(uint8 ch_num, Adc_ConfigChannel * adc_parameters);

/***************************************************************
* Name:        ADC_GetSamples
* Inputs:      None
* Outputs:     Adc digital samples
* Description: Retrieving the digital samples of the Adc.s
****************************************************************/
uint32 ADC_GetSamples(void);

/***************************************************************
* Name:        ADC_Convert
* Inputs:      adc_sampling digital samples from ADC 
               adc_resolution in bits
* Outputs:     result of conversion
* Description: Adc sampling conversion into meaningful data such as temperature,
			   distance, light intensity, ...
			   The conversion technique is highly dependent on the application, thus
			   we need to draw a graph for the adc readings and the actual desired 
			   physical quantity to figure out a conversion equation.

			   12-bit digital value
			   |
			   |
			   |   some graph to deduce a conversion function from.
			   |
			   |_________________ the analog value
****************************************************************/
float32 ADC_Convert(uint32 adc_sampling, uint32 adc_resolution);

#endif // !
