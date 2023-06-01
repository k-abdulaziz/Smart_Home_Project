/**
 * @file LED_Program.c
 * @author Khaled Abdulaziz 
 * @brief 
 * @version 0.1
 * @date 2023-04-03
 * 
 * 
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_Interface.h"
#include "BUZ_Config.h"
#include "BUZ_Interface.h"

#include "BUZ_Private.h"

void BUZ_voidInit(void)
{
    DIO_voidSetPinDirection(BUZZER_PORT, BUZZER_PIN, DIO_OUTPUT);
}

void BUZ_voidTurnON(void)
{
	DIO_voidSetPinValue(BUZZER_PORT, BUZZER_PIN, DIO_HIGH);
}

void BUZ_voidTurnOFF(void)
{
	DIO_voidSetPinValue(BUZZER_PORT, BUZZER_PIN, DIO_LOW);
}
