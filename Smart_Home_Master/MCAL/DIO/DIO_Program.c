/**
 * @file DIO_Program.c
 * @author Khaled Abdulaziz
 * @brief This is the implementation file for the DIO module which is responsible for controlling
 *        the input/output directions and values of the microcontroller's pins and ports.
 * @version 0.1
 * @date 2023-03-29
 *
 *
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "DIO_Interface.h"
#include "DIO_Private.h"
#include "DIO_Config.h"

void DIO_voidSetPinDirection(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8Direction)
{
    if ((Copy_u8PortId <= DIO_PORT_D) && (Copy_u8PortId >= DIO_PORT_A))
    {
        if ((Copy_u8PinId <= DIO_PIN7) && (Copy_u8PinId >= DIO_PIN0))
        {
            switch (Copy_u8Direction)
            {
            case DIO_OUTPUT:
            {
                switch (Copy_u8PortId)
                {
                case DIO_PORT_A:
                    SET_BIT(DIO_DDRA, Copy_u8PinId);
                    break;
                case DIO_PORT_B:
                    SET_BIT(DIO_DDRB, Copy_u8PinId);
                    break;
                case DIO_PORT_C:
                    SET_BIT(DIO_DDRC, Copy_u8PinId);
                    break;
                case DIO_PORT_D:
                    SET_BIT(DIO_DDRD, Copy_u8PinId);
                    break;
                default:
                    /* Error handling */
                    break;
                }
                break;
            }
            case DIO_INPUT:
            {
                switch (Copy_u8PortId)
                {
                case DIO_PORT_A:
                    CLEAR_BIT(DIO_DDRA, Copy_u8PinId);
                    break;
                case DIO_PORT_B:
                    CLEAR_BIT(DIO_DDRB, Copy_u8PinId);
                    break;
                case DIO_PORT_C:
                    CLEAR_BIT(DIO_DDRC, Copy_u8PinId);
                    break;
                case DIO_PORT_D:
                    CLEAR_BIT(DIO_DDRD, Copy_u8PinId);
                    break;
                default:
                    /* Error handling */
                    break;
                }
                break;
            }
            default:
            {
                /* Error Handling  */
                break;
            }
            }
        }
        else
        {
            /* Error Handling */
        }
    }
    else
    {
        /* Error Handling */
    }
}

void DIO_voidSetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8Value)
{
    if ((Copy_u8PortId <= DIO_PORT_D) && (Copy_u8PortId >= DIO_PORT_A))
	{
		if ((Copy_u8PinId <= DIO_PIN7) && (Copy_u8PinId >= DIO_PIN0))
        {
            switch (Copy_u8Value)
            {
            case DIO_HIGH:
            {
                switch (Copy_u8PortId)
                {
                case DIO_PORT_A:
                    SET_BIT(DIO_PORTA, Copy_u8PinId);
                    break;
                case DIO_PORT_B:
                    SET_BIT(DIO_PORTB, Copy_u8PinId);
                    break;
                case DIO_PORT_C:
                    SET_BIT(DIO_PORTC, Copy_u8PinId);
                    break;
                case DIO_PORT_D:
                    SET_BIT(DIO_PORTD, Copy_u8PinId);
                    break;
                default:
                    /* Error handling */
                    break;
                }
                break;
            }
            case DIO_LOW:
            {
                switch (Copy_u8PortId)
                {
                case DIO_PORT_A:
                    CLEAR_BIT(DIO_PORTA, Copy_u8PinId);
                    break;
                case DIO_PORT_B:
                    CLEAR_BIT(DIO_PORTB, Copy_u8PinId);
                    break;
                case DIO_PORT_C:
                    CLEAR_BIT(DIO_PORTC, Copy_u8PinId);
                    break;
                case DIO_PORT_D:
                    CLEAR_BIT(DIO_PORTD, Copy_u8PinId);
                    break;
                default:
                    /* Error handling */
                    break;
                }
                break;
            }
            default:
            {
                /* Error Handling  */
                break;
            }
            }
        }
        else
        {
            /* Error Handling */
        }
    }
    else
    {
        /* Error Handling */
    }
}

u8   DIO_u8GetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId)
{
    u8 Local_u8Variable = DIO_LOW;
    if ((Copy_u8PortId <= DIO_PORT_D) && (Copy_u8PortId >= DIO_PORT_A))
    {
        if ((Copy_u8PinId <= DIO_PIN7) && (Copy_u8PinId >= DIO_PIN0))
        {
            switch (Copy_u8PortId)
            {
            case DIO_PORT_A:
                Local_u8Variable = GET_BIT(DIO_PINA, Copy_u8PinId);
                break;
            case DIO_PORT_B:
                Local_u8Variable = GET_BIT(DIO_PINB, Copy_u8PinId);
                break;
            case DIO_PORT_C:
                Local_u8Variable = GET_BIT(DIO_PINC, Copy_u8PinId);
                break;
            case DIO_PORT_D:
                Local_u8Variable = GET_BIT(DIO_PIND, Copy_u8PinId);
                break;
            default:
                /* do nothing */
                break;
            }
        }
        else
        {
            /* Error Handling */
        }
    }
    else
    {
        /* Error Handling */
    }
    return Local_u8Variable;
}

void DIO_voidSetPortDirection(u8 Copy_u8PortId, u8 Copy_u8Direction)
{
    if ((Copy_u8PortId <= DIO_PORT_D) && (Copy_u8PortId >= DIO_PORT_A))
    {
        switch (Copy_u8Direction)
        {
        case DIO_OUTPUT:
        {
            switch (Copy_u8PortId)
            {
            case DIO_PORT_A:
                SET_REG(DIO_DDRA);
                break;
            case DIO_PORT_B:
                SET_REG(DIO_DDRB);
                break;
            case DIO_PORT_C:
                SET_REG(DIO_DDRC);
                break;
            case DIO_PORT_D:
                SET_REG(DIO_DDRD);
                break;
            default:
                /* Error handling */
                break;
            }
            break;
        }
        case DIO_INPUT:
        {
            switch (Copy_u8PortId)
            {
            case DIO_PORT_A:
                CLEAR_REG(DIO_DDRA);
                break;
            case DIO_PORT_B:
                CLEAR_REG(DIO_DDRB);
                break;
            case DIO_PORT_C:
                CLEAR_REG(DIO_DDRC);
                break;
            case DIO_PORT_D:
                CLEAR_REG(DIO_DDRD);
                break;
            default:
                /* Error handling */
                break;
            }
            break;
        }
        default:
        {
            /* Error Handling  */
            break;
        }
        }
    }
    else
    {
        /*Error Handling*/
    }
}

void DIO_voidSetPortValue(u8 Copy_u8PortId, u8 Copy_u8Value)
{
    if ((Copy_u8PortId <= DIO_PORT_D) && (Copy_u8PortId >= DIO_PORT_A))
    {
        if ((Copy_u8Value <= DIO_PORT_HIGH) && (Copy_u8Value >= DIO_PORT_LOW))
        {
        switch (Copy_u8PortId)
            {
            case DIO_PORT_A:
                DIO_PORTA = Copy_u8Value;
                break;
            case DIO_PORT_B:
                DIO_PORTB = Copy_u8Value;
                break;
            case DIO_PORT_C:
                DIO_PORTC = Copy_u8Value;
                break;
            case DIO_PORT_D:
                DIO_PORTD = Copy_u8Value;
                break;
            default:
                /* Error handling */
                break;
            }
        }
        else
        {
            /* Error Handling */
        }
    }
    else
    {
        /*Error Handling*/
    }
}

u8   DIO_u8GetPortValue(u8 Copy_u8PortId)
{
    u8 Local_u8Variable = DIO_PORT_LOW;

    if ((Copy_u8PortId <= DIO_PORT_D) && (Copy_u8PortId >= DIO_PORT_A))
    {
        switch (Copy_u8PortId)
        {
        case DIO_PORT_A:
            Local_u8Variable = GET_REG(DIO_PINA);
            break;
        case DIO_PORT_B:
            Local_u8Variable = GET_REG(DIO_PINB);
            break;
        case DIO_PORT_C:
            Local_u8Variable = GET_REG(DIO_PINC);
            break;
        case DIO_PORT_D:
            Local_u8Variable = GET_REG(DIO_PIND);
            break;
        default:
            /* do nothing */
            break;
        }
    }
    else
    {
        /*Error Handling*/
    }
    return Local_u8Variable;
}

void DIO_voidTogglePinValue(u8 Copy_u8PortId, u8 Copy_u8PinId)
{
    if ((Copy_u8PortId <= DIO_PORT_D) && (Copy_u8PortId >= DIO_PORT_A))
    {
        if ((Copy_u8PinId <= DIO_PIN7) && (Copy_u8PinId >= DIO_PIN0))
        {
            switch(Copy_u8PortId)
            {
                case DIO_PORT_A:
                    TOGGLE_BIT(DIO_PORTA, Copy_u8PinId); // set pin value to low
                    break;

                case DIO_PORT_B:
                    TOGGLE_BIT(DIO_PORTB, Copy_u8PinId); // set pin value to low
                    break;

                case DIO_PORT_C:
                    TOGGLE_BIT(DIO_PORTC, Copy_u8PinId); // set pin value to low
                    break;

                case DIO_PORT_D:
                    TOGGLE_BIT(DIO_PORTD, Copy_u8PinId); // set pin value to low
                    break;

                default:
                    // Do nothing, invalid port
                    break;
            }
        }
    }
}

void DIO_voidTogglePortValue(u8 Copy_u8PortId)
{
    if ((Copy_u8PortId <= DIO_PORT_D) && (Copy_u8PortId >= DIO_PORT_A))
    {
        switch (Copy_u8PortId)
        {
        case DIO_PORT_A:
            TOGGLE_REG(DIO_PORTA);
            break;

        case DIO_PORT_B:
            TOGGLE_REG(DIO_PORTB);
            break;

        case DIO_PORT_C:
            TOGGLE_REG(DIO_PORTC);
            break;

        case DIO_PORT_D:
            TOGGLE_REG(DIO_PORTD);
            break;

        default:
            // Do nothing, invalid port
            break;
        }
    }
}
