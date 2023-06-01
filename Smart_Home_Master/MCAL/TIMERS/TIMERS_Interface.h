/**
 * @file TIMERS_Interface.h
 * @author Khaled Abdulaziz 
 * @brief 
 * @version 0.1
 * @date 2023-04-05
 * 
 * 
 */

#ifndef MCAL_TIMERS_TIMERS_INTERFACE_H_
#define MCAL_TIMERS_TIMERS_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"

/*				TIMER0					*/

/* Wave Generation Mode */
#define TIMER0_NORMAL				0
#define TIMER0_PWM_PHASE_CORRECT	1
#define TIMER0_CTC					2
#define TIMER0_FAST_PWM				3

/* COMPARE MATCH OUTPUT MODE NO-PWM */
#define TIMER0_NORMAL_OC0_DISCONNECTED	0
#define TIMER0_TOGGLE_OC0			1
#define TIMER0_CLEAR_OC0			2
#define TIMER0_SET_OC0			3

/* FAST PWM MODE */
#define TIMER0_NORMAL_OC0_DISCONNECTED	0
#define TIMER0_CLEAR_OC0 			2
#define TIMER0_SET_OC0			3

/* PHASE CORRECT PWM MODE */
#define TIMER0_NORMAL_OC0_DISCONNECTED	0
#define TIMER0_CLEAR_OC0			2
#define TIMER0_SET_OC0			3

/* Prescaler */
#define	TIMER0_STOP					0
#define	TIMER0_CLK_DIV_BY_1				1
#define TIMER0_CLK_DIV_BY_8				2
#define TIMER0_CLK_DIV_BY_64		    3
#define TIMER0_CLK_DIV_BY_256			4
#define TIMER0_CLK_DIV_BY_1024			5
#define TIMER0_EXT_CLK_T0_FALLING			6
#define TIMER0_EXT_CLK_T0_RISISNG			7


#define	TIMER0_DISABLE_INTERRUPT		0
#define	TIMER0_ENABLE_INTERRUPT		1


/*				TIMER1					*/
#define TIMER1_NORMAL								0
#define TIMER1_PWM_PHASE_CORRECT_8BIT				1
#define TIMER1_PWM_PHASE_CORRECT_9BIT				2
#define TIMER1_PWM_PHASE_CORRECT_10BIT				3
#define TIMER1_CTC_OCR1A								4
#define TIMER1_FAST_PWM_8BIT							5
#define TIMER1_FAST_PWM_9BIT							6
#define TIMER1_FAST_PWM_10BIT						7
#define TIMER1_PWM_PHASE_FREQUANCY_CORRECT_ICR1		8
#define TIMER1_PWM_PHASE_FREQUANCY_CORRECT_OCR1A		9
#define TIMER1_PWM_PHASE_CORRECT_ICR1				10
#define TIMER1_PWM_PHASE_CORRECT_OCR1A				11
#define TIMER1_CTC_ICR1								12
#define TIMER1_FAST_PWM_ICR1							13
#define TIMER1_FAST_PWM_OCR1A						14

#define TIMER1_OC1_DISCONNECTED			0
#define TIMER1_OC1_TOGGLE				1
#define TIMER1_OC1_CLEAR					2
#define TIMER1_OC1_SET					3

#define	TIMER1_STOP						0
#define	TIMER1__CLK_DIV_BY_1					1
#define TIMER1__CLK_DIV_BY_8					2
#define TIMER1__CLK_DIV_BY_64					3
#define TIMER1__CLK_DIV_BY_256				4
#define TIMER1__CLK_DIV_BY_1024				5
#define TIMER1_EXT_CLK_T0_FALLING			6
#define TIMER1_EXT_CLK_T0_RISISNG			7

#define	TIMER1_FALLING_INPUT_CAPTURE		0
#define	TIMER1_RISING_INPUT_CAPTURE		1

/*				TIMER2					*/
#define TIMER2_NORMAL				0
#define TIMER2_PWM_PHASE_CORRECT		1
#define TIMER2_CTC					2
#define TIMER2_FAST_PWM				3


#define TIMER2_OC2_DISCONNECTED		0
#define TIMER2_OC2_TOGGLE			1
#define TIMER2_OC2_CLEAR				2
#define TIMER2_OC2_SET				3


#define	TIMER2_STOP					0
#define	TIMER2_DIV_BY_1				1
#define TIMER2_DIV_BY_8				2
#define TIMER2_DIV_BY_32				3
#define TIMER2_DIV_BY_64				4
#define TIMER2_DIV_BY_128			5
#define TIMER2_DIV_BY_256			6
#define TIMER2_DIV_BY_1024			7


#define	TIMER2_DISABLE_INTERRUPT		0
#define	TIMER2_ENABLE_INTERRUPT		1



/*            	TIMER FUNCTIONS	PART				*/

typedef enum
{
	Timer_Normal_Mode,
	Timer_CTC_Mode
}Timer_Modes;

typedef enum
{
	Timer_Interrupt_Enable,
	Timer_Interrupt_Disable
}Timer_Interrupt;


typedef enum
{
	NO_CLK_SRC,
	NO_PRESCALAR,
	PRESCALAR_CLK8,
	PRESCALAR_CLK64,
	PRESCALAR_CLK256,
	PRESCALAR_CLK1024,
	EXT_CLK_FALLING=6,
	EXT_CLK_RISING
}Timer_PRESCALAR;

typedef	struct
{
	u8 Timer;
	Timer_Modes 	Timer_Mode;
	Timer_PRESCALAR	Timer_Prescaller;
	Timer_Interrupt Timer_OVF_INT;
	Timer_Interrupt Timer_CTC_INT;

}Timer_Configration;


//void TIMER_voidInit(void);
//void TIMER_voidPostInit(const Timer_Configration *  Cpy_Configuration);

/*										TIMER0											*/

void TIMER0_voidInit();
void TIMER0_voidSetPreloadValue(u8 Copy_u8PreloadValue);
void TIMER0_voidSetCompareMatchValue(u8 Copy_u8CompareMatchValue);
void TIMER0_voidSetOVFCallBack(void (*Local_pvoidCallBack) (void));
void TIMER0_voidSetCTCCallBack(void (*Local_pvoidCallBack) (void));


/*										TIMER1											*/
void TIMER1_voidInit(void);
void TIMER1_voidSetPreloadValue(u16 Copy_u8PreloadValue);
void TIMER1_voidSetCompareMatchValue(u16 Copy_u8CompareMatchValue);
void TIMER1_voidSetInputCaptutreValue(u16 Copy_u16InputCaptureValue);
void TIMER1_voidSetOVFCallBack(void (*Local_pvoidCallBack) (void));
void TIMER1_voidSetCTCCallBack_ChannelA(void (*Copy_pvoidCallBack) (void));
void TIMER1_voidSetCTCCallBack_ChannelB(void (*Copy_pvoidCallBack) (void));
void TIMER1_voidSetInputCaptureCallBack(void (*Copy_pvoidCallBack) (void));



/*										TIMER2											*/

void TIMER2_voidInit();
void TIMER2_voidSetPreloadValue(u8 Copy_u8PreloadValue);
void TIMER2_voidSetCompareMatchValue(u8 Copy_u8CompareMatchValue);
void TIMER2_voidSetOVFCallBack(void (*Local_pvoidCallBack) (void));
void TIMER2_voidSetCTCCallBack(void (*Local_pvoidCallBack) (void));

#endif /* MCAL_TIMERS_TIMERS_INTERFACE_H_ */
