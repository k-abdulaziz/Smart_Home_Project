/**
 * @file DC_MOTOR_Interface.h
 * @author Khaled Abdulaziz 
 * @brief 
 * @version 0.1
 * @date 2023-04-03
 * 
 * 
 */

#ifndef HAL_SERVO_MOTOR_SERVO_MOTOR_INTERFACE_H_
#define HAL_SERVO_MOTOR_SERVO_MOTOR_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"

void Servo_Motor_voidInit(void);
u16 Servo_Motor_u16CalculateAngle(u8 Local_Angle);
void Servo_Motor_voidMove(u8 Local_Angle);

#endif /* HAL_SERVO_MOTOR_SERVO_MOTOR_INTERFACE_H_ */
