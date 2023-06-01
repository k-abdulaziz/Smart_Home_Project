/**
 * @file ADC_Interface.h
 * @author Khaled Abdulaziz 
 * @brief 
 * @version 0.1
 * @date 2023-04-04
 * 
 * 
 */

#ifndef MCAL_ADC_ADC_INTERFACE_H_
#define MCAL_ADC_ADC_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"

/*  Reference Selection */
#define ADC_VREF_AREF_EXTERNAL  0
#define ADC_VREF_AVCC  1
#define ADC_VREF_INTERNAL 2

#define ADC_RIGHT_ADJUST 0
#define ADC_LEFT_ADJUST  1

#define ADC_SCM_ADC0 0
#define ADC_SCM_ADC1 1
#define ADC_SCM_ADC2 2
#define ADC_SCM_ADC3 3
#define ADC_SCM_ADC4 4
#define ADC_SCM_ADC5 5
#define ADC_SCM_ADC6 6
#define ADC_SCM_ADC7 7

#define ADC_PRESCALER_2 0
#define ADC_PRESCALER_4 1
#define ADC_PRESCALER_16 2
#define ADC_PRESCALER_32 3
#define ADC_PRESCALER_64 4
#define ADC_PRESCALER_128 5

#define ADC_INTERRUPT_DISABLE 0
#define ADC_INTERRUPT_ENABLE  1

#define ADC_SINGLE_CONVERSION_MODE 0
#define ADC_FREE_RUNNING_INTERRUPT_MODE  1

//#define ADC_AUTO_TRIGGER_DISABLE 0
//#define ADC_AUTO_TRIGGER_ENABLE 1

#define ADC_FREE_RUNNING_MODE   0
#define ADC_ANALOG_COMPARATOR   1
#define ADC_EXTERNAL_INTERRUPT  2
#define ADC_TIMER0_CTC          3
#define ADC_TIMER0_OVF          4
#define ADC_TIMER1_CTC          5
#define ADC_TIMER1_OVF          6
#define ADC_TIMER1_CE           7

void ADC_voidInit(void);
u16  ADC_u16StartConversionPolling(u8 Copy_u8ChannelId);
u16  ADC_u16StartConversionInterrupt(u8 Copy_u8ChannelId);
void ADC_voidSetADCCallBack(void (*Global_pvoidCallBack) (void));


#endif /* MCAL_ADC_ADC_INTERFACE_H_ */
