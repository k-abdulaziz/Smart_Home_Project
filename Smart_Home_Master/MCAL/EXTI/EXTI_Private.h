/**
 * @file EXTI_Private.h
 * @author Khaled Abdulaziz 
 * @brief 
 * @version 0.1
 * @date 2023-04-02
 * 
 * 
 */

#ifndef MCAL_EXTI_EXTI_PRIVATE_H_
#define MCAL_EXTI_EXTI_PRIVATE_H_

/* PORT A REGISTERS */
#define EXTI_MCUCR  (*(volatile u8 *)0x55)
#define EXTI_MCUCSR (*(volatile u8 *)0x54)
#define EXTI_GIFR   (*(volatile u8 *)0x5A)
#define EXTI_GICR   (*(volatile u8 *)0x5B)

/* PORT D REGISTERS */
#define MCUCR_ISC00 0
#define MCUCR_ISC01 1
#define MCUCR_ISC10 2
#define MCUCR_ISC11 3

#define MCUCSR_ISC2 6

#define GICR_INT2 5
#define GICR_INT0 6
#define GICR_INT1 7

#define GIFR_INTF2 5
#define GIFR_INTF0 6
#define GIFR_INTF1 7

#endif /* MCAL_EXTI_EXTI_PRIVATE_H_ */
