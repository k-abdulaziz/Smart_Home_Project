/**
 * @file BUZ_Interface.h
 * @author Khaled Abdulaziz 
 * @brief 
 * @version 0.1
 * @date 2023-04-03
 * 
 * 
 */

#ifndef HAL_BUZ_BUZ_INTERFACE_H_
#define HAL_BUZ_BUZ_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"

#define BUZZER_PIN   DIO_PIN5

#define BUZZER_PORT  DIO_PORT_C

void BUZ_voidInit(void);
void BUZ_voidTurnON(void);
void BUZ_voidTurnOFF(void);

#endif /* HAL_BUZ_BUZ_INTERFACE_H_ */
