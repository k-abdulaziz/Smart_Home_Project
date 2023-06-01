/*
 * LM35_Program.c
 *
 *  Created on: May 28, 2023
 *      Author: khale
 */


#include "LM35_Interface.h"
#include "LM35_Config.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/ADC/ADC_Interface.h"

void LM35_voidInit(void)
{
	DIO_voidSetPinDirection(DIO_PORT_A, DIO_PIN0, DIO_INPUT);
    //ADC_voidInit();
}

u8 LM35_u8ReadTemperature(void)
{
    u16 Local_u16DigitalValue = ADC_u16StartConversionPolling(LM35_ADC_CHANNEL);
    u16 Local_u16AnalogValue = (Local_u16DigitalValue * 5000UL) / 1024 ;
    u8 Local_u8Temperature = Local_u16AnalogValue / 10;
    return Local_u8Temperature;
}
