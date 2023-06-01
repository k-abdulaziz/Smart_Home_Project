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

#include "../DIO/DIO_Interface.h"

#include "USART_Interface.h"
#include "USART_Private.h"
#include "USART_Config.h"

void USART_voidInit(void)
{
    u16 UBRR = 0;

    /*Select the PD0 as INPUT */
    DIO_voidSetPinDirection(DIO_PORT_D, DIO_PIN0, DIO_INPUT);

    /*Select the PD1 as OUPUT*/
    DIO_voidSetPinDirection(DIO_PORT_D, DIO_PIN1, DIO_OUTPUT);

    CLEAR_BIT(USART_UCSRA, UCSRA_MPCM);

    #if USART_OPERATION_MODE == USART_ASYNCH_NORMAL_MODE
    UBRR = ((F_CPU / (USART_BAUDRATE * 16UL)) - 1);
    CLEAR_BIT(USART_UCSRA, UCSRA_U2X);
    USART_UCSRC = (1<<UCSRC_URSEL) | (0<<UCSRC_UMSEL);
    //CLEAR_BIT(USART_UCSRC, UCSRC_UMSEL);
    #elif USART_OPERATION_MODE == USART_ASYNCH_DOUBLE_SPEED_MODE
    UBRR = ((F_CPU / (USART_BAUDRATE * 8UL)) - 1);
    SET_BIT(USART_UCSRA, UCSRA_U2X);
    USART_UCSRC = (1<<UCSRC_URSEL) | (0<<UCSRC_UMSEL);
    //CLEAR_BIT(USART_UCSRC, UCSRC_UMSEL);
    #elif USART_OPERATION_MODE == USART_SYNCH_MASTER_MODE
    UBRR = ((F_CPU / (USART_BAUDRATE * 2UL)) - 1);
    CLEAR_BIT(USART_UCSRA, UCSRA_U2X);
    USART_UCSRC = (1<<UCSRC_URSEL) | (1<<UCSRC_UMSEL);
    //SET_BIT(USART_UCSRC, UCSRC_UMSEL);
        #if USART_CLOCK_POLARITY == USART_FALLING_XCK_EDGE
    	USART_UCSRC = (1<<UCSRC_URSEL) | (0<<UCSRC_UMPOL);
        //CLEAR_BIT(USART_UCSRC, UCSRC_UCPOL);
        #elif USART_CLOCK_POLARITY == USART_RISING_XCK_EDGE
    	USART_UCSRC = (1<<UCSRC_URSEL) | (1<<UCSRC_UMPOL);
        //SET_BIT(USART_UCSRC, UCSRC_UCPOL);
        #endif
    #endif

	USART_UBRRL = UBRR;
    USART_UBRRH = (UBRR >> 8);

	#if USART_PARITY_MODE == USART_DISABLED_PARITY
    USART_UCSRC = (1<<UCSRC_URSEL) | (0<<UCSRC_UPM0) | (0<<UCSRC_UPM1);
    //CLEAR_BIT(USART_UCSRC, UCSRC_UPM0);
    //CLEAR_BIT(USART_UCSRC, UCSRC_UPM1);
	#elif USART_PARITY_MODE == USART_EVEN_PARITY
    USART_UCSRC = (1<<UCSRC_URSEL) | (0<<UCSRC_UPM0) | (1<<UCSRC_UPM1);
    //CLEAR_BIT(USART_UCSRC, UCSRC_UPM0);
    //SET_BIT(USART_UCSRC, UCSRC_UPM1);
	#elif USART_PARITY_MODE == USART_ODD_PARITY
    USART_UCSRC = (1<<UCSRC_URSEL) | (1<<UCSRC_UPM0) | (1<<UCSRC_UPM1);
    //SET_BIT(USART_UCSRC, UCSRC_UPM0);
    //SET_BIT(USART_UCSRC, UCSRC_UPM1);
	#endif

 	#if USART_STOP_BIT_SELECT == USART_1_STOP_BIT
    USART_UCSRC = (1<<UCSRC_URSEL) | (0<<UCSRC_USBS);
    //CLEAR_BIT(USART_UCSRC, UCSRC_USBS);
	#elif USART_STOP_BIT_SELECT == USART_2_STOP_BITS
    USART_UCSRC = (1<<UCSRC_URSEL) | (1<<UCSRC_USBS);
    //SET_BIT(USART_UCSRC, UCSRC_USBS);
	#endif

	#if USART_CHARACTER_SIZE == USART_5_BITS
    USART_UCSRC = (1<<UCSRC_URSEL) | (0<<UCSRC_UCSZ0) | (0<<UCSRC_UCSZ1);
    CLEAR_BIT(USART_UCSRB, UCSRB_UCSZ2);
	#elif USART_CHARACTER_SIZE == USART_6_BITS
    USART_UCSRC = (1<<UCSRC_URSEL) | (1<<UCSRC_UCSZ0) | (0<<USRC_UCSZ1);
    CLEAR_BIT(USART_UCSRB, UCSRB_UCSZ2);
	#elif USART_CHARACTER_SIZE == USART_7_BITS
    USART_UCSRC = (1<<UCSRC_URSEL) | (0<<UCSRC_UCSZ0) | (1<<UCSRC_UCSZ1);
    CLEAR_BIT(USART_UCSRB, UCSRB_UCSZ2);
    #elif USART_CHARACTER_SIZE == USART_8_BITS
    USART_UCSRC = (1<<UCSRC_URSEL) | (1<<UCSRC_UCSZ0) | (1<<UCSRC_UCSZ1);
    CLEAR_BIT(USART_UCSRB, UCSRB_UCSZ2);
	#elif USART_CHARACTER_SIZE == USART_9_BITS
    USART_UCSRC = (1<<UCSRC_URSEL) | (1<<UCSRC_UCSZ0) | (1<<UCSRC_UCSZ1);
    SET_BIT(USART_UCSRB, UCSRB_UCSZ2);
	#endif

    /* ENABLE TX and RX */
    USART_UCSRB = (1<<UCSRB_RXEN) | (1<<UCSRB_TXEN);

}

void USART_voidTx_Char(u8 Copy_u8Data)
{
    /*Polling*/
	/*Wait Until the Tx Buffer Must be Empty*/
	while(!GET_BIT(USART_UCSRA, UCSRA_UDRE));
	USART_UDR = Copy_u8Data;
}

void USART_voidTx_String(s8 *Copy_pu8String)
{
	while(*Copy_pu8String)
	{
		USART_voidTx_Char(*Copy_pu8String++);
	}
}

u8 USART_u8Rx_Char(void)
{
    /*Wait until the Rx flag == 1*/
	while(!GET_BIT(USART_UCSRA ,UCSRA_RXC));
	return USART_UDR;
}

s8* USART_pu8Rx_String(s8 *Copy_pu8Received_String, u8 Copy_u8Terminating_Char)
{
    //static u8 string[256]; // buffer to store the received string, assuming a maximum length of 255 characters
    u8 temp = 0; // counter for the number of characters received
    u8 i = 0; // index of the current character being received
    for(i = 0 ;; i++)
    {
        *(Copy_pu8Received_String + i) = USART_u8Rx_Char(); // receive a character from USART and store it in the buffer
        if (*(Copy_pu8Received_String + i) == Copy_u8Terminating_Char) // check if the terminating character has been received
        {
            break; // exit the loop
        }
        else temp++; // increment the counter
    }
    *(Copy_pu8Received_String + temp) = '\0'; // terminate the string with a null character
    return Copy_pu8Received_String; // return the received string
}

