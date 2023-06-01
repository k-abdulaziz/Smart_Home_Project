/**
 * @file EXTI_Program.c
 * @author Khaled Abdulaziz 
 * @brief 
 * @version 0.1
 * @date 2023-04-02
 * 
 * 
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include <util/delay.h>

#include "../DIO/DIO_Interface.h"

#include "EXTI_Interface.h"
#include "EXTI_Private.h"
#include "EXTI_Config.h"

void (*ptrFun0) (void) = NULL;
void (*ptrFun1) (void) = NULL;
void (*ptrFun2) (void) = NULL;

void EXTI_voidSetCallBackINT0(void (*pf0) (void))
{
	ptrFun0 = pf0;
}

void EXTI_voidSetCallBackINT1(void (*pf1) (void))
{
	ptrFun1 = pf1;
}

void EXTI_voidSetCallBackINT2(void (*pf2) (void))
{
	ptrFun2 = pf2;
}

void EXTI_voidInit(void)
{
    #if EXTI_REQUEST_EN == EXTI_INT0
        SET_BIT(EXTI_GICR, GICR_INT0);
    	DIO_voidSetPinDirection(DIO_PORT_D, DIO_PIN2, DIO_INPUT);
    	DIO_voidSetPinValue(DIO_PORT_D, DIO_PIN2, DIO_HIGH);
        #if INT_SENSE_CONTROL_MODE == INT_SC_LOW_LEVEL
        CLEAR_BIT(EXTI_MCUCR, MCUCR_ISC00);
        CLEAR_BIT(EXTI_MCUCR, MCUCR_ISC01);
        #elif INT_SENSE_CONTROL_MODE == INT_SC_ANY_CHANGE
        SET_BIT(EXTI_MCUCR, MCUCR_ISC00);
        CLEAR_BIT(EXTI_MCUCR, MCUCR_ISC01);
        #elif INT_SENSE_CONTROL_MODE == INT_SC_FALLING_EDGE
        CLEAR_BIT(EXTI_MCUCR, MCUCR_ISC00);
        SET_BIT(EXTI_MCUCR, MCUCR_ISC01);
        #elif INT_SENSE_CONTROL_MODE == INT_SC_RISING_EDGE
        SET_BIT(EXTI_MCUCR, MCUCR_ISC00);
        SET_BIT(EXTI_MCUCR, MCUCR_ISC01);
        #else
        // No valid sense control mode defined for INT0
        #endif

    #elif EXTI_REQUEST_EN == EXTI_INT1
        SET_BIT(EXTI_GICR, GICR_INT1);
    	DIO_voidSetPinDirection(DIO_PORT_D, DIO_PIN3, DIO_INPUT);
    	DIO_voidSetPinValue(DIO_PORT_D, DIO_PIN3, DIO_HIGH);

        #if INT_SENSE_CONTROL_MODE == INT_SC_LOW_LEVEL
        CLEAR_BIT(EXTI_MCUCR, MCUCR_ISC10);
        CLEAR_BIT(EXTI_MCUCR, MCUCR_ISC11);
        #elif INT_SENSE_CONTROL_MODE == INT_SC_ANY_CHANGE
        SET_BIT(EXTI_MCUCR, MCUCR_ISC10);
        CLEAR_BIT(EXTI_MCUCR, MCUCR_ISC11);
        #elif INT_SENSE_CONTROL_MODE == INT_SC_FALLING_EDGE
        CLEAR_BIT(EXTI_MCUCR, MCUCR_ISC10);
        SET_BIT(EXTI_MCUCR, MCUCR_ISC11);
        #elif INT_SENSE_CONTROL_MODE == INT_SC_RISING_EDGE
        SET_BIT(EXTI_MCUCR, MCUCR_ISC10);
        SET_BIT(EXTI_MCUCR, MCUCR_ISC11);
        #else
        // No valid sense control mode defined for INT1
        #endif

    #elif EXTI_REQUEST_EN == EXTI_INT2
        SET_BIT(EXTI_GICR, GICR_INT2);
    	DIO_voidSetPinDirection(DIO_PORT_B, DIO_PIN2, DIO_INPUT);
    	DIO_voidSetPinValue(DIO_PORT_B, DIO_PIN2, DIO_HIGH);

        #if INT_SENSE_CONTROL_MODE == INT_SC_FALLING_EDGE
        CLEAR_BIT(EXTI_MCUCSR, MCUCSR_ISC2);
        #elif INT_SENSE_CONTROL_MODE == INT_SC_RISING_EDGE
        SET_BIT(EXTI_MCUCSR, MCUCSR_ISC2);
        #else
        // No valid sense control mode defined for INT2
        #endif

    #else
        // No valid EXTI request enabled
    #endif
}

void EXTI_voidEnable(u8 Copy_u8IntNo, u8 Copy_u8SenseControl)
{
    switch (Copy_u8IntNo)
    {
        case EXTI_INT0:
            SET_BIT(EXTI_GICR, GICR_INT0);
        	DIO_voidSetPinDirection(DIO_PORT_D, DIO_PIN2, DIO_INPUT);
        	DIO_voidSetPinValue(DIO_PORT_D, DIO_PIN2, DIO_HIGH);
            switch (Copy_u8SenseControl)
            {
                case INT_SC_LOW_LEVEL:
                    CLEAR_BIT(EXTI_MCUCR, MCUCR_ISC00);
                    CLEAR_BIT(EXTI_MCUCR, MCUCR_ISC01);
                    break;
                case INT_SC_ANY_CHANGE:
                    SET_BIT(EXTI_MCUCR, MCUCR_ISC00);
                    CLEAR_BIT(EXTI_MCUCR, MCUCR_ISC01);
                    break;
                case INT_SC_FALLING_EDGE:
                    CLEAR_BIT(EXTI_MCUCR, MCUCR_ISC00);
                    SET_BIT(EXTI_MCUCR, MCUCR_ISC01);
                    break;
                case INT_SC_RISING_EDGE:
                    SET_BIT(EXTI_MCUCR, MCUCR_ISC00);
                    SET_BIT(EXTI_MCUCR, MCUCR_ISC01);
                    break;
                default:
                    // No valid sense control mode defined for INT0
                    break;
            }
            break;

        case EXTI_INT1:
            SET_BIT(EXTI_GICR, GICR_INT1);
        	DIO_voidSetPinDirection(DIO_PORT_D, DIO_PIN3, DIO_INPUT);
        	DIO_voidSetPinValue(DIO_PORT_D, DIO_PIN3, DIO_HIGH);
            switch (Copy_u8SenseControl)
            {
                case INT_SC_LOW_LEVEL:
                    CLEAR_BIT(EXTI_MCUCR, MCUCR_ISC10);
                    CLEAR_BIT(EXTI_MCUCR, MCUCR_ISC11);
                    break;
                case INT_SC_ANY_CHANGE:
                    SET_BIT(EXTI_MCUCR, MCUCR_ISC10);
                    CLEAR_BIT(EXTI_MCUCR, MCUCR_ISC11);
                    break;
                case INT_SC_FALLING_EDGE:
                    CLEAR_BIT(EXTI_MCUCR, MCUCR_ISC10);
                    SET_BIT(EXTI_MCUCR, MCUCR_ISC11);
                    break;
                case INT_SC_RISING_EDGE:
                    SET_BIT(EXTI_MCUCR, MCUCR_ISC10);
                    SET_BIT(EXTI_MCUCR, MCUCR_ISC11);
                    break;
                default:
                    // No valid sense control mode defined for INT1
                    break;
            }
            break;

        case EXTI_INT2:
            SET_BIT(EXTI_GICR, GICR_INT2);
        	DIO_voidSetPinDirection(DIO_PORT_B, DIO_PIN2, DIO_INPUT);
        	DIO_voidSetPinValue(DIO_PORT_B, DIO_PIN2, DIO_HIGH);
            switch (Copy_u8SenseControl)
            {
                case INT_SC_FALLING_EDGE:
                    CLEAR_BIT(EXTI_MCUCSR, MCUCSR_ISC2);
                    break;
                case INT_SC_RISING_EDGE:
                    SET_BIT(EXTI_MCUCSR, MCUCSR_ISC2);
                    break;
                default:
                    // No valid sense control mode defined for INT2
                    break;
            }
            break;

        default:
            // No valid EXTI request enabled
            break;
    }
}

void EXTI_voidDisable(u8 Copy_u8IntNo)
{
    switch (Copy_u8IntNo)
    {
        case EXTI_INT0:
            CLEAR_BIT(EXTI_GICR, GICR_INT0);
            break;

        case EXTI_INT1:
            CLEAR_BIT(EXTI_GICR, GICR_INT1);
            break;

        case EXTI_INT2:
            CLEAR_BIT(EXTI_GICR, GICR_INT2);
            break;

        default:
            // No valid EXTI request enabled
            break;
    }
}

/*ISR*/
void __vector_1(void)    __attribute__((signal));
void __vector_1(void)
{
	if(ptrFun0 != NULL)
	{
		ptrFun0();
	}
}

/*ISR*/
void __vector_2(void)    __attribute__((signal));
void __vector_2(void)
{
	if(ptrFun1 != NULL)
	{
		ptrFun1();
	}
}
/*ISR*/
void __vector_3(void)    __attribute__((signal));
void __vector_3(void)
{
	if(ptrFun2 != NULL)
	{
		ptrFun2();
	}
}
