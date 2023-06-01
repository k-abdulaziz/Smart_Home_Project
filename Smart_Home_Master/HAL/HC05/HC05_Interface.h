/**
 * @file USART_Interface.h
 * @author Khaled Abdulaziz 
 * @brief 
 * @version 0.1
 * @date 2023-04-11
 * 
 * 
 */

#ifndef MCAL_USART_HC05_INTERFACE_H_
#define MCAL_USART_HC05_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"

void HC05_voidTx_Char(u8 Copy_u8Data);
u8 HC05_u8Rx_Char(void);
void HC05_voidTx_String(s8 *Copy_pu8String);
s8* HC05_pu8Rx_String(s8 *Copy_pu8Received_String, u8 Copy_u8Terminating_Char);

#endif /* MCAL_USART_HC05_INTERFACE_H_ */
