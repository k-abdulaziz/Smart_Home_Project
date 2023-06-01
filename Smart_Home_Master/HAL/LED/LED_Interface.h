/**
 * @file LED_Interface.h
 * @author Khaled Abdulaziz 
 * @brief 
 * @version 0.1
 * @date 2023-04-03
 * 
 * 
 */

#ifndef HAL_LED_LED_INTERFACE_H_
#define HAL_LED_LED_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"

#define LEDS_NUM 8

#define RED_INDICATOR_LED    DIO_PIN6
#define GREEN_INDICATOR_LED  DIO_PIN7
#define LIGHT_LED1  DIO_PIN3
#define LIGHT_LED2  DIO_PIN4
#define LIGHT_LED3  DIO_PIN6


#define INDICATORS_PORT  DIO_PORT_C
#define LIGHT_PORT  	 DIO_PORT_D

void LED_voidInit(void);
void LED_voidTurnON(u8 Copy_u8LED_Port, u8 Copy_u8LED_No);
void LED_voidTurnOFF(u8 Copy_u8LED_Port, u8 Copy_u8LED_No);

#endif /* HAL_LED_LED_INTERFACE_H_ */
