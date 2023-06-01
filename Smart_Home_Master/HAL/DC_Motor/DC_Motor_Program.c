/**
 * @file DC_MOTOR_Program.c
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

#include "DC_MOTOR_Interface.h"
#include "DC_MOTOR_Private.h"
#include "DC_MOTOR_Config.h"

void DC_MOTOR_voidInit(void) {
    // Initialize the direction pins as output
    DIO_voidSetPinDirection(DC_MOTOR_PORT, DC_MOTOR_PIN1, DIO_OUTPUT);
    DIO_voidSetPinDirection(DC_MOTOR_PORT, DC_MOTOR_PIN2, DIO_OUTPUT);

    // Stop the motor initially
    DC_MOTOR_voidStop();
}

void DC_MOTOR_voidRunClockwise(void) {
    // Set the direction pins to run the motor clockwise
    DIO_voidSetPinValue(DC_MOTOR_PORT, DC_MOTOR_PIN1, DIO_HIGH);
    DIO_voidSetPinValue(DC_MOTOR_PORT, DC_MOTOR_PIN2, DIO_LOW);
}

void DC_MOTOR_voidRunAntiClockwise(void) {
    // Set the direction pins to run the motor anticlockwise
    DIO_voidSetPinValue(DC_MOTOR_PORT, DC_MOTOR_PIN1, DIO_LOW);
    DIO_voidSetPinValue(DC_MOTOR_PORT, DC_MOTOR_PIN2, DIO_HIGH);
}

void DC_MOTOR_voidStop(void) {
    // Set both direction pins to low to stop the motor
    DIO_voidSetPinValue(DC_MOTOR_PORT, DC_MOTOR_PIN1, DIO_LOW);
    DIO_voidSetPinValue(DC_MOTOR_PORT, DC_MOTOR_PIN2, DIO_LOW);
}
