/**************************************************************
 * Non Autosar file.
 * File name:  Adc_Registers.h
 * Decription: File that contains all the required registers to initialize 
               the ADC hardware of the Tivac launchpad.
 * Author:     Abdulmaguid Eissa.
***************************************************************/

#ifndef ADC_REGISTERS_H
#define ADC_REGISTERS_H

/***************************************************************
                        GPIO PORTE
****************************************************************/
#define SYSCTL_RCGC2_R          (*((volatile unsigned long *)0x400FE108))
#define GPIO_PORTE_DATA_R       (*((volatile unsigned long *)0x400243FC))
#define GPIO_PORTE_DIR_R        (*((volatile unsigned long *)0x40024400))
#define GPIO_PORTE_IS_R         (*((volatile unsigned long *)0x40024404))
#define GPIO_PORTE_IBE_R        (*((volatile unsigned long *)0x40024408))
#define GPIO_PORTE_IEV_R        (*((volatile unsigned long *)0x4002440C))
#define GPIO_PORTE_IM_R         (*((volatile unsigned long *)0x40024410))
#define GPIO_PORTE_RIS_R        (*((volatile unsigned long *)0x40024414))
#define GPIO_PORTE_MIS_R        (*((volatile unsigned long *)0x40024418))
#define GPIO_PORTE_ICR_R        (*((volatile unsigned long *)0x4002441C))
#define GPIO_PORTE_AFSEL_R      (*((volatile unsigned long *)0x40024420))
#define GPIO_PORTE_DEN_R        (*((volatile unsigned long *)0x4002451C))
#define GPIO_PORTE_AMSEL_R      (*((volatile unsigned long *)0x40024528))
#define GPIO_PORTE_PCTL_R       (*((volatile unsigned long *)0x4002452C))
#define SYSCTL_RCGC0_R          (*((volatile unsigned long *)0x400FE100))

/****************************************************************
				     ADC registers (ADC0)
*****************************************************************/
#define ADC0_ACTSS_R            (*((volatile unsigned long *)0x40038000))
#define ADC0_RIS_R              (*((volatile unsigned long *)0x40038004))
#define ADC0_IM_R               (*((volatile unsigned long *)0x40038008))
#define ADC0_ISC_R              (*((volatile unsigned long *)0x4003800C))
#define ADC0_EMUX_R             (*((volatile unsigned long *)0x40038014))
#define ADC0_USTAT_R            (*((volatile unsigned long *)0x40038018))
#define ADC0_TSSEL_R            (*((volatile unsigned long *)0x4003801C))
#define ADC0_SSPRI_R            (*((volatile unsigned long *)0x40038020))
#define ADC0_PSSI_R             (*((volatile unsigned long *)0x40038028))
#define ADC0_CTL_R              (*((volatile unsigned long *)0x40038038))
#define ADC0_SSMUX3_R           (*((volatile unsigned long *)0x400380A0))
#define ADC0_SSCTL3_R           (*((volatile unsigned long *)0x400380A4))
#define ADC0_SSFIFO3_R          (*((volatile unsigned long *)0x400380A8))
#define ADC0_SSFSTAT3_R         (*((volatile unsigned long *)0x400380AC))
#define ADC0_PSSI_R             (*((volatile unsigned long *)0x40038028))

/* Registers values */
#define PIN2                    (2U)
#define PORTE_CLOCK             (4U)
#define ADC0_EN                 (16U)
#define ADC0_SSPRI              (0x0123)
#define ADC0_ACTSS              (0x0008)
#define ADC0_EMUX               (0xF000)
#define ADC0_SSMUX3             (0x000F)
#define ADC0_SSCTL3             (0x0006)
#define ADC0_CH_AIN1            (1)
#define ADC0_RESET              (0xFFFFFFFF)
#define ADC0_RIS                (3U)
#define ADC0_FIFO_RANGE         (0xFFF)

#endif /* !ADC_REGIRERS_H */
