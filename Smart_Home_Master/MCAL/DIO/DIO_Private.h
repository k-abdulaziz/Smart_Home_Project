/**
 * @file DIO_Private.h
 * @author Khaled Abdulaziz
 * @brief This is the private header file for the DIO module which contains the memory-mapped
 *        hardware registers of the microcontroller's input/output ports and pins.
 * @version 0.1
 * @date 2023-03-29
 *
 *
 */

#ifndef MCAL_DIO_DIO_PRIVATE_H_
#define MCAL_DIO_DIO_PRIVATE_H_

/* PORT A REGISTERS */
#define DIO_PORTA (*(volatile u8 *)0x3B)
#define DIO_DDRA  (*(volatile u8 *)0x3A)
#define DIO_PINA  (*(volatile u8 *)0x39)

/* PORT B REGISTERS */
#define DIO_PORTB (*(volatile u8 *)0x38)
#define DIO_DDRB  (*(volatile u8 *)0x37)
#define DIO_PINB  (*(volatile u8 *)0x36)

/* PORT C REGISTERS */
#define DIO_PORTC (*(volatile u8 *)0x35)
#define DIO_DDRC  (*(volatile u8 *)0x34)
#define DIO_PINC  (*(volatile u8 *)0x33)

/* PORT D REGISTERS */
#define DIO_PORTD (*(volatile u8 *)0x32)
#define DIO_DDRD  (*(volatile u8 *)0x31)
#define DIO_PIND  (*(volatile u8 *)0x30)

#define DIO_SFIOR (*(volatile u8 *)0x50)

#endif /* MCAL_DIO_DIO_PRIVATE_H_ */
