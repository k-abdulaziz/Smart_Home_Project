/**
 * @file LCD_Private.h
 * @author Khaled Abdulaziz
 * @brief
 * @version 0.1
 * @date 2023-03-30
 *
 *
 */

#ifndef HAL_LCD_LCD_PRIVATE_H_
#define HAL_LCD_LCD_PRIVATE_H_

#define LCD_DISPLAY_CLEAR 0x01     // clear display
#define LCD_RETURN_HOME 0x02     // return home

#define LCD_8_BIT_MODE 0
#define LCD_4_BIT_MODE 1

#define LCD_FUNCTION_8BIT_SET0 0x3C // 8-bit data, 2-lines, 5 x 10 dots
#define LCD_FUNCTION_8BIT_SET1 0x38 // 8-bit data, 2-lines, 5 x 7 dots
#define LCD_FUNCTION_8BIT_SET2 0x34 // 8-bit data, 1-line, 5 x 10 dots
#define LCD_FUNCTION_8BIT_SET3 0x30 // 8-bit data, 1-line,  5 x 7 dots
#define LCD_FUNCTION_4BIT_SET0 0xC0 // 4-bit data, 2-lines, 5 x 10 dots
#define LCD_FUNCTION_4BIT_SET1 0x80 // 4-bit data, 2-lines, 5 x 7 dots
#define LCD_FUNCTION_4BIT_SET2 0x40 // 4-bit data, 1-line, 5 x 10 dots
#define LCD_FUNCTION_4BIT_SET3 0x00 // 4-bit data, 1-lines, 5 x 7 dots

#define LCD_8BIT_ENTRY_MODE_SET0 0x06    // increasing address, shift off
#define LCD_8BIT_ENTRY_MODE_SET1 0x04    // decreasing address, shift off
#define LCD_8BIT_ENTRY_MODE_SET2 0x07    // increasing address, shift left
#define LCD_8BIT_ENTRY_MODE_SET3 0x05    // decreasing address, shift right
#define LCD_4BIT_ENTRY_MODE_SET0 0x60    // increasing address, shift off
#define LCD_4BIT_ENTRY_MODE_SET1 0x40    // decreasing address, shift off
#define LCD_4BIT_ENTRY_MODE_SET2 0x70    // increasing address, shift left
#define LCD_4BIT_ENTRY_MODE_SET3 0x50    // decreasing address, shift right

#define LCD_8BIT_DISPLAY_MODE0 0x0F        // on display, cursor and blink
#define LCD_8BIT_DISPLAY_MODE1 0x0E        // on display, cursor, blink off
#define LCD_8BIT_DISPLAY_MODE2 0x0C        // on display, off cursor and blink
#define LCD_8BIT_DISPLAY_MODE3 0x08        // off display, off cursor and blink

#define LCD_4BIT_DISPLAY_MODE0 0xF0        // on display, cursor and blink
#define LCD_4BIT_DISPLAY_MODE1 0xE0        // on display, cursor, blink off
#define LCD_4BIT_DISPLAY_MODE2 0xC0        // on display, off cursor and blink
#define LCD_4BIT_DISPLAY_MODE3 0x80        // off display, off cursor and blink

#define LCD_CURSOR_SHIFT_LEFT 0x10
#define LCD_CURSOR_SHIFT_RIGHT 0x14
#define LCD_DISPLAY_SHIFT_LEFT 0x18
#define LCD_DISPLAY_SHIFT_RIGHT 0x1C

#define LCD_CGRAM_BASE_ADDRESS 0x40
#define LCD_DDRAM_BASE_ADDRESS 0x80

#define LCD_NUM_SPECIAL_PATTERNS 8
#define LCD_SPECIAL_PATTERN_SIZE 8
#define LCD_CGRAM_BIT_6 6
#define LCD_CGRAM_BIT_7 7

s8* Private_u8NumtoStr(s32 num);

#define LCD_PATTERN_ADDRESS(Pattern_Num) (LCD_CGRAM_BASE_ADDRESS + ((Pattern_Num) * LCD_SPECIAL_PATTERN_SIZE))

#endif /* HAL_LCD_LCD_PRIVATE_H_ */
