/**
 * @file LCD_Config.h
 * @author Khaled Abdulaziz
 * @brief
 * @version 0.1
 * @date 2023-03-29
 *
 *
 */

#ifndef HAL_LCD_LCD_CONFIG_H_
#define HAL_LCD_LCD_CONFIG_H_

#define LCD_BIT_MODE LCD_4_BIT_MODE

/*  LCD_FUNCTION_SET0 // 8-bit data, 2-lines, 5 x 10 dots
    LCD_FUNCTION_SET1 // 8-bit data, 2-lines, 5 x 7 dots
    LCD_FUNCTION_SET1 // 8-bit data, 1-line, 5 x 10 dots
    LCD_FUNCTION_SET2 // 8-bit data, 1-line,  5 x 7 dots
    LCD_FUNCTION_SET3 // 4-bit data, 2-lines, 5 x 10 dots
    LCD_FUNCTION_SET4 // 4-bit data, 2-lines, 5 x 7 dots
    LCD_FUNCTION_SET5 // 4-bit data, 1-line, 5 x 10 dots
    LCD_FUNCTION_SET6 // 4-bit data, 1-lines, 5 x 7 dots */

/*  LCD_DISPLAY_MODE0   // on display, cursor and blink
    LCD_DISPLAY_MODE1   // on display, cursor, blink off
    LCD_DISPLAY_MODE2   // on display, off cursor and blink
    LCD_DISPLAY_MODE3   // off display, off cursor and blink */

/*  LCD_ENTRY_MODE_SET0 // increasing address, shift off
    LCD_ENTRY_MODE_SET1 // decreasing address, shift off
    LCD_ENTRY_MODE_SET2 // increasing address, shift left
    LCD_ENTRY_MODE_SET3 // decreasing address, shift right */

#define LCD_8BIT_FUNCTION_SET_MODE   LCD_FUNCTION_8BIT_SET1
#define LCD_4BIT_FUNCTION_SET_MODE   LCD_FUNCTION_4BIT_SET1
#define LCD_8BIT_DISPLAY_MODE        LCD_8BIT_DISPLAY_MODE2
#define LCD_4BIT_DISPLAY_MODE        LCD_4BIT_DISPLAY_MODE2
#define LCD_8BIT_ENTRY_MODE          LCD_8BIT_ENTRY_MODE_SET0
#define LCD_4BIT_ENTRY_MODE          LCD_8BIT_ENTRY_MODE_SET0

#define LCD_CONTROL_PORT   DIO_PORT_C
#define LCD_CONTROL_RS_PIN DIO_PIN2
#define LCD_CONTROL_RW_PIN DIO_PIN3
#define LCD_CONTROL_E_PIN  DIO_PIN4

#define LCD_DATA_PORT   DIO_PORT_A
#define LCD_DATA_PIN1 	DIO_PIN4
#define LCD_DATA_PIN2 	DIO_PIN5
#define LCD_DATA_PIN3 	DIO_PIN6
#define LCD_DATA_PIN4 	DIO_PIN7


#endif /* HAL_LCD_LCD_CONFIG_H_ */
