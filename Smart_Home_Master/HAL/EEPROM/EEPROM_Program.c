/**
 * @file EEPROM_Program.c
 * @author Khaled Abdulaziz 
 * @brief 
 * @version 0.1
 * @date 2023-04-17
 * 
 * 
 */

#include <util/delay.h>

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/TWI/TWI_Interface.h"

#include "EEPROM_Interface.h"
#include "EEPROM_Private.h"
#include "EEPROM_Config.h"

void EEPROM_voidInit(void) {

	int i = 0, j = 0;
	u8 init_flag, reset_flag;
	Users_Data Local_Users[10] = {
		{101, 12345},
		{102, 63454},
		{103, 2000},
		{104, 35478},
		{105, 4000},
		{106, 510},
		{107, 6300},
		{108, 7000},
		{109, 8000},
		{110, 900}
	};

	// Write users data to EEPROM
	for (i = EEPROM_USERS_START_ADDRESS; i < NUM_USERS; i++) {
		EEPROM_voidWriteDataByte(i, Local_Users[i].Local_au8Users);
	}

	// Write users passwords to EEPROM
	for (i = EEPROM_PASSWORDS_START_ADDRESS, j = 0; j < NUM_USERS;
			i += 2, j++) {
		EEPROM_voidWriteDataWord(i, Local_Users[j].Local_au16Passwords);
	}

    // set init flag
    init_flag = 0x00;
    EEPROM_voidWriteDataByte(EEPROM_INIT_FLAG_ADDRESS, init_flag);
    reset_flag = 0xFF;
    EEPROM_voidWriteDataByte(EEPROM_RESET_FLAG_ADDRESS, reset_flag);
}

// Function to write a byte of data to an EEPROM at a given address
void EEPROM_voidWriteDataByte(u16 Copy_u16Address, u8 Copy_u8Data)
{
    u8 Local_u8Address;

    // Calculate the local address of the EEPROM using the pre-defined values
    Local_u8Address = (EEPROM_ADDRESS_ID | (EEPROM_A2_VALUE << 2) | ((u8)(Copy_u16Address >> 8)));

    // Send start condition to begin TWI communication
    TWI_voidSendStartCondition();

    // Send the slave address of the EEPROM with write permission
    TWI_voidSendSlaveAddressWithWriteACK(Local_u8Address);

    // Send the high byte of the memory address to write to
    TWI_voidMasterWriteDataACK((u8)Copy_u16Address);

    // Send the data byte to be written to the EEPROM
    TWI_voidMasterWriteDataACK(Copy_u8Data);

    // Send stop condition to end TWI communication
    TWI_voidSendStopCondition();

    // Wait for 10ms for the write operation to complete
    _delay_ms(10);
}

// Function to write a byte of data to an EEPROM at a given address
void EEPROM_voidWriteDataWord(u16 Copy_u16Address, u16 Copy_u16Data)
{
	union {
		uint16_t word;
		struct {
			uint8_t lo;
			uint8_t hi;
		} byte;
	} x;
	x.word = Copy_u16Data;
	EEPROM_voidWriteDataByte((uint8_t *)Copy_u16Address,     x.byte.lo);
	EEPROM_voidWriteDataByte((uint8_t *)Copy_u16Address + 1, x.byte.hi);
}

// Function to read a byte of data from an EEPROM at a given address
void EEPROM_voidReadDataByte(u16 Copy_u16Address, u8 *Copy_u8Data)
{
    u8 Local_u8Address, Copy_u8ReceivedData;

    // Calculate the local address of the EEPROM using the pre-defined values
    Local_u8Address = (EEPROM_ADDRESS_ID | (EEPROM_A2_VALUE << 2) | ((u8)(Copy_u16Address >> 8)));

    // Send start condition to begin TWI communication
    TWI_voidSendStartCondition();

    // Send the slave address of the EEPROM with write permission
    TWI_voidSendSlaveAddressWithWriteACK(Local_u8Address);

    // Send the high byte of the memory address to read from
    TWI_voidMasterWriteDataACK((u8)Copy_u16Address);

    // Send repeated start condition to switch to read mode
    TWI_voidSendRepeated_StartCondition();

    // Send the slave address of the EEPROM with read permission
    TWI_voidSendSlaveAddressWithReadACK(Local_u8Address);

    // Read the data byte from the EEPROM
    TWI_voidMasterReadDataNACK(&Copy_u8ReceivedData);

    // Store the received data byte in the output parameter
    *Copy_u8Data = Copy_u8ReceivedData;

    // Send stop condition to end TWI communication
    TWI_voidSendStopCondition();
}

// Function to read a byte of data from an EEPROM at a given address
void EEPROM_voidReadDataWord(u16 Copy_u16Address, u16 *Copy_u16Data)
{
	union {
		uint16_t word;
		struct {
			uint8_t lo;
			uint8_t hi;
		} byte;
	} x;
	EEPROM_voidReadDataByte((const uint8_t *) Copy_u16Address, &x.byte.lo);
	EEPROM_voidReadDataByte((const uint8_t *) Copy_u16Address + 1, &x.byte.hi);
	*Copy_u16Data = x.word;
}

void EEPROM_voidReset(void)
{
    for (uint16_t i = 0; i < 1024; i++)
    {
    	EEPROM_voidWriteDataByte((uint8_t*) i, 0xFF);
    }
}
