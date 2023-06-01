/**
 * @file EEPROM_Interface.h
 * @author Khaled Abdulaziz 
 * @brief 
 * @version 0.1
 * @date 2023-04-17
 * 
 * 
 */

#ifndef HAL_EEPROM_EEPROM_INTERFACE_H_
#define HAL_EEPROM_EEPROM_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"

#define NUM_USERS 10
#define NUM_PASSWORDS 10
#define EEPROM_INIT_FLAG_ADDRESS 0x50
#define EEPROM_RESET_FLAG_ADDRESS 0x51
#define EEPROM_USERS_START_ADDRESS 0x00
#define EEPROM_PASSWORDS_START_ADDRESS 0x0A
#define EEPROM_OFFSET 0xA

typedef struct {
	u8 Local_au8Users;
	u16 Local_au16Passwords;
} Users_Data;

void EEPROM_voidInit(void);
void EEPROM_voidWriteDataByte(u16 Copy_u16Address, u8 Copy_u8Data);
void EEPROM_voidWriteDataWord(u16 Copy_u16Address, u16 Copy_u16Data);
void EEPROM_voidReadDataByte(u16 Copy_u16Address, u8 *Copy_u8Data);
void EEPROM_voidReadDataWord(u16 Copy_u16Address, u16 *Copy_u16Data);
void EEPROM_voidReset(void);

#endif /* HAL_EEPROM_EEPROM_INTERFACE_H_ */
