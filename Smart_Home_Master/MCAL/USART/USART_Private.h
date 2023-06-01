/**
 * @file USART_Private.h
 * @author Khaled Abdulaziz 
 * @brief 
 * @version 0.1
 * @date 2023-04-11
 * 
 * 
 */

#ifndef MCAL_USART_USART_PRIVATE_H_
#define MCAL_USART_USART_PRIVATE_H_

#define USART_UCSRA     (*(volatile u8*)0x2B)
#define USART_UCSRB		(*(volatile u8*)0x2A)
#define USART_UCSRC		(*(volatile u8*)0x40)
#define USART_UBRRH		(*(volatile u8*)0x40)
#define USART_UBRRL		(*(volatile u8*)0x29)
#define USART_UDR       (*(volatile u8*)0x2C)

/*UCSRA*/
#define UCSRA_RXC        7
#define UCSRA_TXC        6
#define UCSRA_UDRE       5
#define UCSRA_FE         4
#define UCSRA_DOR        3
#define UCSRA_PE         2
#define UCSRA_U2X        1
#define UCSRA_MPCM       0

/*UCSRB*/
#define UCSRB_RXCIE      7
#define UCSRB_TXCIE      6
#define UCSRB_UDRIE      5
#define UCSRB_RXEN       4
#define UCSRB_TXEN       3
#define UCSRB_UCSZ2      2
#define UCSRB_RXB8       1
#define UCSRB_TXB8       0

/*UCSRC->0x40*/
#define UCSRC_URSEL      7
#define UCSRC_UMSEL      6
#define UCSRC_UPM1       5
#define UCSRC_UPM0       4
#define UCSRC_USBS       3
#define UCSRC_UCSZ1      2
#define UCSRC_UCSZ0      1
#define UCSRC_UCPOL      0

#endif /* MCAL_USART_USART_PRIVATE_H_ */
