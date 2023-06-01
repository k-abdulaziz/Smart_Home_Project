/**
 * @file USART_Program.c
 * @author Khaled Abdulaziz 
 * @brief 
 * @version 0.1
 * @date 2023-04-11
 * 
 * 
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/USART/USART_Interface.h"

void HC05_voidTx_Char(u8 Copy_u8Data)
{
	USART_voidTx_Char(Copy_u8Data);
}

u8 HC05_u8Rx_Char(void)
{
	return USART_u8Rx_Char();
}

void HC05_voidTx_String(s8 *Copy_pu8String)
{
	USART_voidTx_String(Copy_pu8String);
}

s8* HC05_pu8Rx_String(s8 *Copy_pu8Received_String, u8 Copy_u8Terminating_Char)
{
	return USART_pu8Rx_String(Copy_pu8Received_String, Copy_u8Terminating_Char);
}

