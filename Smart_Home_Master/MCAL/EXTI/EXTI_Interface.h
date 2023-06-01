/**
 * @file EXTI_Interface.h
 * @author Khaled Abdulaziz 
 * @brief 
 * @version 0.1
 * @date 2023-04-02
 * 
 * 
 */

#ifndef MCAL_EXTI_EXTI_INTERFACE_H_
#define MCAL_EXTI_EXTI_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"

#define EXTI_INT0 0
#define EXTI_INT1 1
#define EXTI_INT2 2

#define EXTI_REQUEST_EN  EXTI_INT0

#define INT_SC_LOW_LEVEL    0
#define INT_SC_ANY_CHANGE   1
#define INT_SC_FALLING_EDGE 2
#define INT_SC_RISING_EDGE  3

#define INT_SENSE_CONTROL_MODE INT_SC_FALLING_EDGE

void EXTI_voidInit(void);
void EXTI_voidEnable(u8 Copy_u8IntNo, u8 Copy_u8SenseControl);
void EXTI_voidDisable(u8 Copy_u8IntNo);
void EXTI_voidSetCallBackINT0(void (*pf0) (void));
void EXTI_voidSetCallBackINT1(void (*pf1) (void));
void EXTI_voidSetCallBackINT2(void (*pf2) (void));

#endif /* MCAL_EXTI_EXTI_INTERFACE_H_ */
