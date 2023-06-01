/**
 * @file TIMERS_Private.h
 * @author Khaled Abdulaziz 
 * @brief 
 * @version 0.1
 * @date 2023-04-05
 * 
 * 
 */

#ifndef MCAL_TIMERS_TIMERS_PRIVATE_H_
#define MCAL_TIMERS_TIMERS_PRIVATE_H_

#include "../../LIB/STD_TYPES.h"

//#define NULL 		0

#define TIMER0_OVF_CALLBACK_INDEX				0
#define TIMER1_OVF_CALLBACK_INDEX				1
#define TIMER2_OVF_CALLBACK_INDEX				2

#define TIMER0_CTC_CALLBACK_INDEX				3
#define TIMER1_CTC_CHANNEL_A_CALLBACK_INDEX		4
#define TIMER1_CTC_CHANNEL_B_CALLBACK_INDEX		5
#define TIMER2_CTC_CALLBACK_INDEX				6

#define TIMER1_INPUT_CAPTURE_CALLBACK_INDEX		7

void (*TIMER_CallBack[8])(void) = {NULL};


#define TIMERS_TIMSK   (* (volatile u8 *) (0x59))
#define TIMERS_TIFR    (* (volatile u8 *) (0x58))

/*					TIMER 0 REGISTERS						*/
#define TIMER0_TCCR0   (* (volatile u8 *) (0x53))
#define TIMER0_TCNT0   (* (volatile u8 *) (0x52))
#define TIMER0_OCR0    (* (volatile u8 *) (0x5C))

#define TCCR0_CS00	    0
#define TCCR0_CS01	    1
#define TCCR0_CS02	    2
#define TCCR0_WGM01	    3
#define TCCR0_COM00	    4
#define TCCR0_COM01	    5
#define TCCR0_WGM00	    6
#define TCCR0_FOC0	    7

#define TIMSK_TOIE0	    0
#define TIMSK_OCIE0	    1

#define TIFR_TOV0	    0
#define TIFR_OCF0	    1

void TIMER0_voidSetOVFCallBack(void (*Local_pvoidCallBack) (void));
void TIMER0_voidSetCTCCallBack(void (*Local_pvoidCallBack) (void));

void (*Local_pvoidCallBackOVF) (void) = NULL;
void (*Local_pvoidCallBackCTC) (void) = NULL;

void __vector_11(void) __attribute__((signal));
void __vector_10(void) __attribute__((signal));



/*					TIMER 1 REGISTERS						*/

#define TIMER1_TCCR1A   (* (volatile u8 *) (0x4F))
#define TIMER1_TCCR1B   (* (volatile u8 *) (0x4E))
#define TIMER1_TCNT1H   (* (volatile u8 *) (0x4D))
#define TIMER1_TCNT1L   (* (volatile u8 *) (0x4C))
#define TIMER1_TCNT1    (* (volatile u16 *) (0x4C))
#define TIMER1_OCR1AH   (* (volatile u8 *) (0x4B))
#define TIMER1_OCR1AL   (* (volatile u8 *) (0x4A))
#define TIMER1_OCR1A    (* (volatile u16 *) (0x4A))
#define TIMER1_OCR1BH   (* (volatile u8 *) (0x49))
#define TIMER1_OCR1BL   (* (volatile u8 *) (0x48))
#define TIMER1_OCR1B    (* (volatile u16 *) (0x48))
#define TIMER1_ICR1H    (* (volatile u8 *) (0x47))
#define TIMER1_ICR1L    (* (volatile u8 *) (0x46))
#define TIMER1_ICR1     (* (volatile u16 *) (0x46))

#define TCCR1A_COM1A1	7
#define TCCR1A_COM1A0	6
#define TCCR1A_COM1B1	5
#define TCCR1A_COM1B0	4
#define TCCR1A_FOC1A	3
#define TCCR1A_FOC1B	2
#define TCCR1A_WGM11	1
#define TCCR1A_WGM10	0

#define TCCR1B_ICNC1	7
#define TCCR1B_ICES1	6
#define TCCR1B_WGM13	4
#define TCCR1B_WGM12	3

#define	TCCR1B_CS12	2
#define TCCR1B_CS11	1
#define TCCR1B_CS10	0

#define TIMSK_TICIE1	5
#define	TIMSK_OCIE1A	4
#define TIMSK_OCIE1B	3
#define TIMSK_TOIE1	2

#define TIFR_ICF1	5
#define TIFR_OCF1A	4
#define TIFR_OCF1B	3
#define TIFR_TOV1	2

void __vector_6(void) __attribute__((signal));
void __vector_7(void) __attribute__((signal));
void __vector_8(void) __attribute__((signal));
void __vector_9(void) __attribute__((signal));


/*					TIMER 2 REGISTERS						*/

#define TIMER2_TCCR2   (* (volatile u8 *) (0x45))
#define TIMER2_TCNT2   (* (volatile u8 *) (0x44))
#define TIMER2_OCR2    (* (volatile u8 *) (0x43))


#define	TCCR2_FOC2	7
#define TCCR2_WGM20	6
#define TCCR2_COM21	5
#define TCCR2_COM20	4
#define TCCR2_WGM21	3
#define	TCCR2_CS22	2
#define	TCCR2_CS21	1
#define	TCCR2_CS20	0


#define TIMSK_TOIE2	6
#define TIMSK_OCIE2	7

#define TIFR_TOV2	6
#define TIFR_OCF2	7

void __vector_4(void) __attribute__((signal));
void __vector_5(void) __attribute__((signal));

#endif /* MCAL_TIMERS_TIMERS_PRIVATE_H_ */
