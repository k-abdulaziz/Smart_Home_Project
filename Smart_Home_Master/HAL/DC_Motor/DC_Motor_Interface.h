/**
 * @file DC_MOTOR_Interface.h
 * @author Khaled Abdulaziz 
 * @brief 
 * @version 0.1
 * @date 2023-04-03
 * 
 * 
 */

#ifndef HAL_DC_MOTOR_DC_MOTOR_INTERFACE_H_
#define HAL_DC_MOTOR_DC_MOTOR_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"

void DC_MOTOR_voidInit(void);
void DC_MOTOR_voidRunClockwise(void);
void DC_MOTOR_voidRunAntiClockwise(void);
void DC_MOTOR_voidStop(void);

#endif /* HAL_DC_MOTOR_DC_MOTOR_INTERFACE_H_ */
