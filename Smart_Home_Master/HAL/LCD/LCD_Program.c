/**
 * @file LCD_Program.c
 * @author Khaled Abdulaziz
 * @brief
 * @version 0.1
 * @date 2023-03-29
 *
 *
 */
#include <util/delay.h>
#include <stdlib.h>
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_Interface.h"

#include "LCD_Interface.h"
#include "LCD_Private.h"
#include "LCD_Config.h"

// Helper functions for 4-bit mode
void LCD_voidSendHigherNibble(u8 Copy_u8Value)
{
    DIO_voidSetPortValue(LCD_DATA_PORT, (Copy_u8Value & 0xF0) | (DIO_u8GetPortValue(LCD_DATA_PORT) & 0x0F));

    DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_CONTROL_E_PIN, DIO_HIGH);
    _delay_ms(1);
    DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_CONTROL_E_PIN, DIO_LOW);
}

void LCD_voidSendLowerNibble(u8 Copy_u8Value)
{
    DIO_voidSetPortValue(LCD_DATA_PORT, ((Copy_u8Value << 4) & 0xF0) | (DIO_u8GetPortValue(LCD_DATA_PORT) & 0x0F));

    DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_CONTROL_E_PIN, DIO_HIGH);
    _delay_ms(1);
    DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_CONTROL_E_PIN, DIO_LOW);
}

void LCD_voidInit(void)
{
    /* POWER ON */

    /* Set direction for data port */
    DIO_voidSetPinDirection(LCD_DATA_PORT, LCD_DATA_PIN1, DIO_OUTPUT);
    DIO_voidSetPinDirection(LCD_DATA_PORT, LCD_DATA_PIN2, DIO_OUTPUT);
    DIO_voidSetPinDirection(LCD_DATA_PORT, LCD_DATA_PIN3, DIO_OUTPUT);
    DIO_voidSetPinDirection(LCD_DATA_PORT, LCD_DATA_PIN4, DIO_OUTPUT);

    /* Set direction for control pins */
    DIO_voidSetPinDirection(LCD_CONTROL_PORT, LCD_CONTROL_RS_PIN, DIO_OUTPUT);
    DIO_voidSetPinDirection(LCD_CONTROL_PORT, LCD_CONTROL_RW_PIN, DIO_OUTPUT);
    DIO_voidSetPinDirection(LCD_CONTROL_PORT, LCD_CONTROL_E_PIN, DIO_OUTPUT);

#if LCD_BIT_MODE == LCD_8_BIT_MODE

    /* Set direction for data port */
    DIO_voidSetPortDirection(LCD_DATA_PORT, DIO_OUTPUT);

    /* Make sure power is on */
    /* Wait more than 30ms */
    _delay_us(40);

    /* Function Set */
    LCD_voidSendCommand(LCD_8BIT_FUNCTION_SET_MODE);

    _delay_ms(1);

    /* Display on/off control */
    LCD_voidSendCommand(LCD_8BIT_DISPLAY_MODE);

    _delay_ms(1);

    LCD_voidSendCommand(LCD_DISPLAY_CLEAR);

    _delay_ms(2);

    /* Entry mode set */

    LCD_voidSendCommand(LCD_8BIT_ENTRY_MODE);

#elif LCD_BIT_MODE == LCD_4_BIT_MODE

    /* Make sure power is on */
    /* Wait more than 30ms */
    _delay_us(50);
	LCD_voidSendCommand(0x33);
	LCD_voidSendCommand(0x32);
	LCD_voidSendCommand(0x28);
	LCD_voidSendCommand(0x0c);
	LCD_voidSendCommand(0x06);

	LCD_voidSendCommand(1);
	_delay_ms(2);
//    // Initialize LCD in 4-bit mode
//    LCD_voidSendCommand(0x20);
//    LCD_voidSendCommand(0x20);
//    LCD_voidSendCommand(LCD_4BIT_FUNCTION_SET_MODE);
//
//    _delay_ms(1);
//
//    /* Display on/off control */
//    LCD_voidSendCommand(0x00);
//    LCD_voidSendCommand(LCD_4BIT_DISPLAY_MODE);
//
//    _delay_ms(1);
//
//    LCD_voidSendCommand(0x00);
//    LCD_voidSendCommand(LCD_DISPLAY_CLEAR);
//
//    _delay_ms(2);
//
//    /* Entry mode set */
//    LCD_voidSendCommand(0x00);
//    LCD_voidSendCommand(LCD_4BIT_ENTRY_MODE);

#endif

}

void LCD_voidSendCommand(u8 Copy_u8Command)
{
    /* select IR setting RS to (LOW) */
    DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_CONTROL_RS_PIN, DIO_LOW);

    /* set R/W to wrie (LOW) */
    DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_CONTROL_RW_PIN, DIO_LOW);

#if LCD_BIT_MODE == LCD_8_BIT_MODE

    /* set data port to command */
    DIO_voidSetPortValue(LCD_DATA_PORT, Copy_u8Command);

    /* falling edge */
    DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_CONTROL_E_PIN, DIO_HIGH);

    _delay_ms(5);

    DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_CONTROL_E_PIN, DIO_LOW);

#elif LCD_BIT_MODE == LCD_4_BIT_MODE

    /* send higher nibble */
    LCD_voidSendHigherNibble(Copy_u8Command);

    /* send lower nibble */
    LCD_voidSendLowerNibble(Copy_u8Command);

#endif

}

void LCD_voidSendData(const s8 Copy_s8Data)
{
    /* select IR setting RS to (HIGH) */
    DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_CONTROL_RS_PIN, DIO_HIGH);

    /* set R/W to wrie (LOW) */
    DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_CONTROL_RW_PIN, DIO_LOW);

#if LCD_BIT_MODE == LCD_8_BIT_MODE

    /* set data port to command */
    DIO_voidSetPortValue(LCD_DATA_PORT, Copy_s8Data);

    /* falling edge */
    DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_CONTROL_E_PIN, DIO_HIGH);

    _delay_ms(5);

    DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_CONTROL_E_PIN, DIO_LOW);

#elif LCD_BIT_MODE == LCD_4_BIT_MODE

    /* send higher nibble */
    LCD_voidSendHigherNibble(Copy_s8Data);

    /* send lower nibble */
    LCD_voidSendLowerNibble(Copy_s8Data);

#endif
}

void LCD_voidSendString(const s8 *Copy_ps8Char)
{
    // Loop until the end of the string is reached
    while(*Copy_ps8Char != '\0')
    {
        // Send the current character to the LCD display
        LCD_voidSendData( *Copy_ps8Char);

        // Increment the pointer to point to the next character
        Copy_ps8Char++;
    }
}

void LCD_voidSendNumber(u32 Copy_u32Num)
{
    s8 *Local_ps8String = Private_u8NumtoStr(Copy_u32Num);
    LCD_voidSendString(Local_ps8String);
}

void LCD_voidGotoXY(u8 Copy_u8Row, u8 Copy_u8Column)
{
    if (Copy_u8Column >= 0 && Copy_u8Column < LCD_COLUMNS_NUMBER)
    {
        switch (Copy_u8Row)
        {
        case LCD_ROW0:
           LCD_voidSendCommand(LCD_DDRAM_BASE_ADDRESS + Copy_u8Column);
            break;
        case LCD_ROW1:
            LCD_voidSendCommand(LCD_CGRAM_BASE_ADDRESS + LCD_DDRAM_BASE_ADDRESS + Copy_u8Column);
            break;
        default:
            /* Error Handling */
            break;
        }
    }
    else
    {
        /* Error Handling */
    }
}

void LCD_voidDisplayShiftLeft(void)
{
    LCD_voidSendCommand(LCD_DISPLAY_SHIFT_LEFT);
}

void LCD_voidDisplayShiftRightt(void)
{
    LCD_voidSendCommand(LCD_DISPLAY_SHIFT_RIGHT);
}

void LCD_voidClearDisplay(void)
{
    LCD_voidSendCommand(LCD_DISPLAY_CLEAR);
}

s8* Private_u8NumtoStr(s32 num)
{
    s8* string = malloc(20); // allocate memory for the string
    if (string == NULL) { // check if allocation succeeded
        return NULL;
    }
    s32 rem, i = 0;
    do {
        rem = num % 10;
        num /= 10;
        *(string + i++) = rem + '0';
    } while (num > 0); // loop until all digits are processed
    *(string + i) = '\0'; // terminate the string
    // reverse the string
    for (s32 j = 0; j < i / 2; j++) {
        u8 temp = *(string + j);
        *(string + j) = *(string + i - j - 1);
        *(string + i - j - 1) = temp;
    }
    return string;
}


// Displays a custom pattern on the LCD screen at the given row and column.
// Copy_u8PatternArray: an array containing the custom pattern data
// Copy_u8PatternNum: the index of the pattern to be displayed
// Copy_u8Row: the row where the pattern should be displayed
// Copy_u8Column: the column where the pattern should be displayed
void LCD_voidDisplaySpecialPattern(u8* Copy_u8PatternArray, u8 Copy_u8PatternNum, u8 Copy_u8Row, u8 Copy_u8Column)
{
    // Set the cursor position to the specified row and column
    LCD_voidGotoXY(Copy_u8Row, Copy_u8Column);

    // Display the pattern number
    LCD_voidSendData(Copy_u8PatternNum);

    // Calculate the address of the custom pattern in the LCD's memory
    u8 Local_u8Address = 0;
    if (Copy_u8PatternNum < LCD_NUM_SPECIAL_PATTERNS) {
        Local_u8Address = Copy_u8PatternNum * LCD_SPECIAL_PATTERN_SIZE;

        // Set the two high-order bits of the address to indicate that we are writing to CGRAM
        SET_BIT(Local_u8Address, LCD_CGRAM_BIT_6);
        CLEAR_BIT(Local_u8Address, LCD_CGRAM_BIT_7);

        // Send the address command to the LCD
        LCD_voidSendCommand(Local_u8Address);

        // Send the pattern data to the LCD
        for (u8 index = 0; index < LCD_SPECIAL_PATTERN_SIZE; index++) {
            LCD_voidSendData(Copy_u8PatternArray[index]);
        }
    }
}
