/**************************************************************
* Non Autosar file.
* File name:  Tivac_Hw.c
* Decription: File that contains all the required APIs implementation
              to initialize the hardware of the uC.
* Author:     Abdulmaguid Eissa.
***************************************************************/

#include "Tivac_Hw.h"
#include "Adc_Registers.h"

/* Private functions declarations */
STATIC void   ADC_ConfigGpioRegs(boolean operation);
STATIC void   ADC_SetAdc0Regs(boolean trigger_source, uint32 sample_rate);

/* Private globals definitions */
STATIC volatile uint32 delay;

/* ADC_InitChannel 
   Applying switch case to each one of the configured parameters.
*/
void ADC_InitChannel(uint8 ch_num, Adc_ConfigChannel * adc_parameters)
{
	uint8 i;

	for ( i = 0; i < ch_num; i++)
	{
		switch (adc_parameters[i].Adc_PortId)
		{
			case 0:       /* Port A To Be Implemented */
			case 1:       /* Port B To Be Implemented */
			case 2:       /* Port C To Be Implemented */
			case 3:       /* Port D To Be Implemented */
				break;
			case 4:       /* Port E */
				ADC_ConfigGpioRegs(OPERATION_INIT);
				switch (adc_parameters[i].Adc_ChannelId)
				{
					case 0:
						ADC_SetAdc0Regs(adc_parameters[i].Adc_TriggerSource, adc_parameters[i].Adc_SampleRate);
						break;
					default:
						break;
				}
			default:
				break;
		}
	}
}

/* ADC_DeInitChannel */
void ADC_DeInitChannel(uint8 ch_num, Adc_ConfigChannel * adc_parameters)
{
	for (uint8 i = 0; i < ch_num; i++)
	{
		switch (adc_parameters[i].Adc_ChannelId)
		{
			case 0:       /* ADC0 */
				ADC_ConfigGpioRegs(OPERATION_DEINIT);  /* Return channel registers to its normal state */
				break;
			default:
				break;
		}
	}
}

/* ADC_GetSamples */
uint32 ADC_GetSamples(void)
{
	uint32 samples = 0;

	SET_VAL(ADC0_PSSI_R, ADC0_ACTSS);              /* initiate sampling in sampler sequencer 3 */

	while (BIT_IS_CLEAR(ADC0_RIS_R, ADC0_RIS)) {}; /* busy wait on RIS to be done */
	samples = READ_REG_VAL(ADC0_SSFIFO3_R, ADC0_FIFO_RANGE);
	SET_VAL(ADC0_ISC_R, ADC0_ACTSS);               /* Acknowledge completion */
	return (samples);
}

/* ADC_Convert 
*/
float32 ADC_Convert(uint32 adc_sampling, uint32 adc_resolution)
{
	return ((float32)(SYSTEM_VOLTAGE * (float32)(adc_sampling >> adc_resolution)));
}

/* Private functions definitions */
/* ADC_SetGpioRegs */
STATIC void ADC_ConfigGpioRegs(boolean operation)
{
	if ( OPERATION_INIT == operation )
	{
		SET_BIT(SYSCTL_RCGC2_R, PORTE_CLOCK);
		delay = SYSCTL_RCGC2_R;
		CLEAR_BIT(GPIO_PORTE_DIR_R, PIN2);
		CLEAR_BIT(GPIO_PORTE_DEN_R, PIN2);
		SET_BIT(GPIO_PORTE_AFSEL_R, PIN2);
		SET_BIT(GPIO_PORTE_AMSEL_R, PIN2);
	}
	else if (OPERATION_DEINIT == operation)
	{
		CLEAR_BIT(SYSCTL_RCGC2_R, PORTE_CLOCK);
		delay = SYSCTL_RCGC2_R;
		SET_BIT(GPIO_PORTE_DIR_R, PIN2);
		SET_BIT(GPIO_PORTE_DEN_R, PIN2);
		CLEAR_BIT(GPIO_PORTE_AFSEL_R, PIN2);
		CLEAR_BIT(GPIO_PORTE_AMSEL_R, PIN2);
	}
	else
	{
		/* No action required */
	}
}

/* ADC_SetAdc0Regs */
STATIC void ADC_SetAdc0Regs(boolean trigger_source, uint32 sample_rate)
{
	SET_BIT(SYSCTL_RCGC0_R, ADC0_EN);         /* Enable ADC0 */
	delay = SYSCTL_RCGC0_R;
	CLEAR_VAL(SYSCTL_RCGC0_R, sample_rate);   /* 125K sample/sec */
	SET_VAL(ADC0_SSPRI_R, ADC0_SSPRI);        /* sequencer 3 is the highest priority */
	CLEAR_VAL(ADC0_ACTSS_R, ADC0_ACTSS);      /* Disable sequencer 3 */

	if (ADC_TRIGG_SRC_SW == trigger_source)
	{
		CLEAR_VAL(ADC0_EMUX_R, ADC0_EMUX);    /* Configure for software trigger */
	}
	else
	{
		/* No action required */
	}
	CLEAR_BIT(ADC0_SSMUX3_R, ADC0_SSMUX3);    /* clear SS3 */
	ADD_VAL(ADC0_SSMUX3_R, ADC0_CH_AIN1);     /* set channel 1, PE2 */
	SET_VAL(ADC0_SSCTL3_R, ADC0_SSCTL3);      /* configure END0 and IE0 */
	SET_VAL(ADC0_ACTSS_R, ADC0_ACTSS);        /* Enable sequencer 3 */
}

