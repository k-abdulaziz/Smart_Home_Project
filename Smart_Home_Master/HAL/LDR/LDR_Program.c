/*
 * LM35_Program.c
 *
 *  Created on: May 28, 2023
 *      Author: khale
 */


#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/ADC/ADC_Interface.h"
#include "LDR_Config.h"
#include "LDR_Interface.h"

void LDR_voidInit(void)
{
	DIO_voidSetPinDirection(DIO_PORT_A, DIO_PIN0, DIO_INPUT);
    //ADC_voidInit();
}

u16 LDR_u16ReadValue(void)
{
    return ADC_u16StartConversionPolling(LDR_ADC_CHANNEL);
}
