/**
 * @file ADC_Private.h
 * @author Khaled Abdulaziz 
 * @brief 
 * @version 0.1
 * @date 2023-04-04
 * 
 * 
 */

#ifndef MCAL_ADC_ADC_PRIVATE_H_
#define MCAL_ADC_ADC_PRIVATE_H_

/* PORT A REGISTERS */
#define ADC_ADMUX   (*(volatile u8 *)0x27)
#define ADC_ADCSRA  (*(volatile u8 *)0x26)
#define ADC_ADCH    (*(volatile u8 *)0x25)
#define ADC_ADCL    (*(volatile u8 *)0x24)
#define ADC_DATA    (*(volatile u16*)0x24)
#define ADC_SFIOR   (*(volatile u8 *)0x50)

/*ADMUX REG*/
#define ADMUX_MUX0  0
#define ADMUX_MUX1  1
#define ADMUX_MUX2  2
#define ADMUX_MUX3  3
#define ADMUX_MUX4  4
#define ADMUX_ADLAR 5
#define ADMUX_REFS0 6
#define ADMUX_REFS1 7

/*ADCSRA REG*/
#define ADCSRA_ADPS0  0
#define ADCSRA_ADPS1  1
#define ADCSRA_ADPS2  2
#define ADCSRA_ADIE   3
#define ADCSRA_ADIF   4
#define ADCSRA_ADATE  5
#define ADCSRA_ADSC   6
#define ADCSRA_ADEN   7

#define SFIOR_ADTS0 5
#define SFIOR_ADTS1 6
#define SFIOR_ADTS2 7

#define ADMUX_MASK 0b11100000

#endif /* MCAL_ADC_ADC_PRIVATE_H_ */
