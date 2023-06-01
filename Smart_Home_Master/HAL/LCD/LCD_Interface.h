/**
 * @file LCD_Interface.h
 * @author Khaled Abdulaziz
 * @brief
 * @version 0.1
 * @date 2023-03-29
 *
 *
 */

#ifndef HAL_LCD_LCD_INTERFACE_H_
#define HAL_LCD_LCD_INTERFACE_H_

#define LCD_COLUMNS_NUMBER 16
#define LCD_ROWS_NUMBER 2

#define LCD_ROW0 0
#define LCD_ROW1 1

#define LCD_COLUMN0 0
#define LCD_COLUMN1 1
#define LCD_COLUMN2 2
#define LCD_COLUMN3 3
#define LCD_COLUMN4 4
#define LCD_COLUMN5 5
#define LCD_COLUMN6 6
#define LCD_COLUMN7 7
#define LCD_COLUMN8 8
#define LCD_COLUMN9 9
#define LCD_COLUMN10 10
#define LCD_COLUMN11 11
#define LCD_COLUMN12 12
#define LCD_COLUMN13 13
#define LCD_COLUMN14 14
#define LCD_COLUMN15 15

void LCD_voidInit(void);

void LCD_voidSendCommand(u8 Copy_u8Command);

void LCD_voidSendData(const s8 Copy_s8Data);

void LCD_voidSendString(const s8 *Copy_ps8Char);

void LCD_voidSendNumber(u32 Copy_u32Num);

void LCD_voidGotoXY(u8 Copy_u8Row, u8 Copy_u8Column);

void LCD_voidDisplayShiftLeft(void);

void LCD_voidDisplayShiftRightt(void);

void LCD_voidClearDisplay(void);

void LCD_voidDisplaySpecialPattern(u8* Copy_u8PatternArray, u8 Copy_u8PatternNum, u8 Copy_u8Row, u8 Copy_u8Column);

#endif /* HAL_LCD_LCD_INTERFACE_H_ */
