/**
 * @file Servo_Motor_Program.c
 * @author Khaled Abdulaziz 
 * @brief 
 * @version 0.1
 * @date 2023-04-08
 * 
 * 
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/TIMERS/TIMERS_Interface.h"

#include "Servo_Motor_Interface.h"
#include "Servo_Motor_Private.h"
#include "Servo_Motor_Config.h"

void Servo_Motor_voidInit(void)
{
    DIO_voidSetPinDirection(DIO_PORT_D, DIO_PIN5, DIO_OUTPUT);
    TIMER1_voidInit();
    TIMER1_voidSetInputCaptutreValue(SERVO_MAX);
}

u16 Servo_Motor_u16CalculateAngle(u8 Local_Angle)
{
    u16 Local_Time = 0;
    Local_Time = ((f32) Local_Angle / 0.18) + 999;
    return Local_Time;
}

void Servo_Motor_voidMove(u8 Local_Angle)
{
    u16 local_return = Servo_Motor_u16CalculateAngle(Local_Angle);
    TIMER1_voidSetCompareMatchValue(local_return);
}
