/**
 * @file USART_Interface.h
 * @author Khaled Abdulaziz 
 * @brief 
 * @version 0.1
 * @date 2023-04-11
 * 
 * 
 */

#ifndef MCAL_USART_USART_INTERFACE_H_
#define MCAL_USART_USART_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"

#define USART_ASYNCH_NORMAL_MODE              1
#define USART_ASYNCH_DOUBLE_SPEED_MODE        2
#define USART_SYNCH_MASTER_MODE               3

#define USART_OPERATION_MODE     USART_ASYNCH_NORMAL_MODE

#define USART_DISABLED_PARITY         1
#define USART_EVEN_PARITY             2
#define USART_ODD_PARITY              3

#define USART_PARITY_MODE     USART_DISABLED_PARITY

#define USART_1_STOP_BIT         1
#define USART_2_STOP_BITS        2

#define USART_STOP_BIT_SELECT USART_1_STOP_BIT

#define USART_5_BITS        1
#define USART_6_BITS        2
#define USART_7_BITS        3
#define USART_8_BITS        4
#define USART_9_BITS        5

#define USART_CHARACTER_SIZE USART_8_BITS

#define USART_FALLING_XCK_EDGE       1
#define USART_RISING_XCK_EDGE        2

#define USART_CLOCK_POLARITY USART_FALLING_XCK_EDGE

void USART_voidInit(void);
void USART_voidTx_Char(u8 Copy_u8Data);
u8 USART_u8Rx_Char(void);
void USART_voidTx_String(s8 *Copy_pu8String);
s8* USART_pu8Rx_String(s8 *Copy_pu8Received_String, u8 Copy_u8Terminating_Char);

#endif /* MCAL_USART_USART_INTERFACE_H_ */
