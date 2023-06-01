/**
 * @file TWI_Program.c
 * @author Khaled Abdulaziz 
 * @brief 
 * @version 0.1
 * @date 2023-04-14
 * 
 * 
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../DIO/DIO_Interface.h"

#include "TWI_Interface.h"
#include "TWI_Private.h"
#include "TWI_Config.h"

void TWI_voidMasterInit(u8 Copy_u8Address)
{
	// Set the prescaler value
	TWI_TWSR &= 0b11111100;
	TWI_TWSR |= TWI_PRESCALER;

	// Set the bit rate value
	TWI_TWBR = ((F_CPU / TWI_SCL_FREQUENCY) - 16) / (2 * Power(4, TWI_PRESCALER));

	// Set the address of the master
	TWI_TWAR = Copy_u8Address;

	//SET_BIT(TWI_TWCR, TWCR_TWEN);
}

TWI_EN_Error_t TWI_voidSendStartCondition(void)
{
	TWI_EN_Error_t Local_u8ErrorState = No_Error;

	// Send the start condition
	TWI_TWCR = (1 << TWCR_TWINT) | (1 << TWCR_TWSTA) | (1 << TWCR_TWEN);

	// Wait for the flag to be set
	while (!GET_BIT(TWI_TWCR, TWCR_TWINT));

	// Check if the start condition was successfully transmitted
	if ((TWI_TWSR & TWI_STATUS_MASK) != TWI_MTX__START)
	{
		// Return an error if the start condition failed
		Local_u8ErrorState = Error_StartCondition;
	}

	return Local_u8ErrorState;
}

TWI_EN_Error_t TWI_voidSendRepeated_StartCondition(void)
{
	TWI_EN_Error_t Local_u8ErrorState = No_Error;

	// Send the repeated start condition
	TWI_TWCR = (1 << TWCR_TWINT) | (1 << TWCR_TWSTA) | (1 << TWCR_TWEN);

	// Wait for the flag to be set
	while (!GET_BIT(TWI_TWCR, TWCR_TWINT));

	// Check if the repeated start condition was successfully transmitted
	if ((TWI_TWSR & TWI_STATUS_MASK) != TWI_MTX__REPEATED_START)
	{
		// Return an error if the repeated start condition failed
		Local_u8ErrorState = Error_ReStartCondition;
	}

	return Local_u8ErrorState;
}

/*Send the SlaveAddress Write*/
/*this Slave Address You want Connect it */
TWI_EN_Error_t TWI_voidSendSlaveAddressWithWriteACK(u8 Local_SlaveAddress)
{
	TWI_EN_Error_t Local_u8ErrorState = No_Error;

	// Send the slave address
	TWI_TWDR = ((Local_SlaveAddress << 1));

	// Select the write mode
	CLEAR_BIT(TWI_TWDR, 0);

	// Clear the flag and enable ACK
	TWI_TWCR = (1 << TWCR_TWEN) | (1 << TWCR_TWINT) | (1 << TWCR_TWEA);

	// Wait for the flag to be set
	while (!GET_BIT(TWI_TWCR, TWCR_TWINT));

	// Check if the slave address with write ACK was successfully transmitted
	if ((TWI_TWSR & TWI_STATUS_MASK) != TWI_MTX__SLA_W_ACK)
	{
		// Return an error if the slave address with write ACK failed
		Local_u8ErrorState = Error_SLAWACK;
	}

	return Local_u8ErrorState;
}

TWI_EN_Error_t TWI_voidSendSlaveAddressWithWriteNACK(u8 Local_SlaveAddress)
{
	TWI_EN_Error_t Local_u8ErrorState = No_Error;

	/*Send the Slave Address */
	TWI_TWDR = (Local_SlaveAddress << 1);

	/*Select the Write Mode*/
	CLEAR_BIT(TWI_TWDR, 0);

	/*Clear Flag*/
	TWI_TWCR = (1 << TWCR_TWEN) | (1 << TWCR_TWINT);

	/*wait the flag*/
	while (GET_BIT(TWI_TWCR, TWCR_TWINT) == 0);

	/*Check ACK*/
	if ((TWI_TWSR & TWI_STATUS_MASK) != TWI_MTX__SLA_W_NOT_ACK)
	{
		Local_u8ErrorState = Error_SLAWNotACK;
	}

	return Local_u8ErrorState;
}

/*Send the SlaveAdd Read*/
TWI_EN_Error_t TWI_voidSendSlaveAddressWithReadACK(u8 Local_SlaveAddress)
{
	TWI_EN_Error_t Local_u8ErrorState = No_Error;

	TWI_TWDR = (Local_SlaveAddress << 1);

	/*Read */
	SET_BIT(TWI_TWDR, 0);

	/**/
	TWI_TWCR = (1 << TWCR_TWEN) | (1 << TWCR_TWINT)  | (1 << TWCR_TWEA);

	/**/
	while (GET_BIT(TWI_TWCR, TWCR_TWINT) == 0);

	/**/
	if ((TWI_TWSR & TWI_STATUS_MASK) != TWI_MRX__SLA_R_ACK)
	{
		Local_u8ErrorState = Error_SLARACK;
	}

	return Local_u8ErrorState;
}

TWI_EN_Error_t TWI_voidSendSlaveAddressWithReadNACK(u8 Local_SlaveAddress)
{
	TWI_EN_Error_t Local_u8ErrorState = No_Error;

	TWI_TWDR = (Local_SlaveAddress << 1);

	/*Read */
	SET_BIT(TWI_TWDR, 0);

	/**/
	TWI_TWCR = (1 << TWCR_TWEN) | (1 << TWCR_TWINT);

	/**/
	while (GET_BIT(TWI_TWCR, TWCR_TWINT) == 0);

	/**/
	if ((TWI_TWSR & TWI_STATUS_MASK) != TWI_MRX__SLA_R_NOT_ACK)
	{
		Local_u8ErrorState = Error_SLArNotACK;
	}

	return Local_u8ErrorState;
}

/* Master Send the Data*/
TWI_EN_Error_t TWI_voidMasterWriteDataACK(u8 Local_Data)
{
	TWI_EN_Error_t Local_u8ErrorState = No_Error;

	/*Write Data*/
	TWI_TWDR = Local_Data;

	/*Clear Flag*/
	TWI_TWCR = (1 << TWCR_TWEN) | (1 << TWCR_TWINT) | (1 << TWCR_TWEA);

	/*wait flag*/
	while (!GET_BIT(TWI_TWCR, TWCR_TWINT));

	/*Check Ack => */
	if ((TWI_TWSR & TWI_STATUS_MASK) != TWI_MRX__DATA_ACK)
	{
		Local_u8ErrorState = Error_WriteDataWithAck;
	}

	return Local_u8ErrorState;
}

TWI_EN_Error_t TWI_voidMasterWriteDataNACK(u8 Local_Data)
{
	TWI_EN_Error_t Local_u8ErrorState = No_Error;

	/*Write Data*/
	TWI_TWDR = Local_Data;

	/*Clear Flag*/
	TWI_TWCR = (1 << TWCR_TWEN) | (1 << TWCR_TWINT);

	/*wait flag*/
	while (!GET_BIT(TWI_TWCR, TWCR_TWINT));

	/*Check Ack => */
	if ((TWI_TWSR & TWI_STATUS_MASK) != TWI_MRX__DATA_NOT_ACK)
	{
		Local_u8ErrorState = Error_WriteDataWithNotAck;
	}

	return Local_u8ErrorState;
}

/*Master Rx the Data*/
TWI_EN_Error_t TWI_voidMasterReadDataACK(u8 *Recive_Data)
{
	/*Local_u8ErrorState var*/
	TWI_EN_Error_t Local_u8ErrorState = No_Error;

	/*clear flag*/
	TWI_TWCR = (1 << TWCR_TWEN) | (1 << TWCR_TWINT) | (1 << TWCR_TWEA);

	/*wait flag*/
	while (GET_BIT(TWI_TWCR, TWCR_TWINT) == 0);

	/*check ack*/
	if ((TWI_TWSR & TWI_STATUS_MASK) != TWI_MRX__DATA_ACK)
	{
		Local_u8ErrorState = Error_ReadDataWithAck;
	}

	*Recive_Data = TWI_TWDR;

	return Local_u8ErrorState;
}

TWI_EN_Error_t TWI_voidMasterReadDataNACK(u8 *Recive_Data)
{
	/*Local_u8ErrorState var*/
	TWI_EN_Error_t Local_u8ErrorState = No_Error;

	/*clear flag*/
	TWI_TWCR = (1 << TWCR_TWEN) | (1 << TWCR_TWINT);

	/*wait flag*/
	while (GET_BIT(TWI_TWCR, TWCR_TWINT) == 0);

	/*check ack*/
	if ((TWI_TWSR & TWI_STATUS_MASK) != TWI_MRX__DATA_NOT_ACK)
	{
		Local_u8ErrorState = Error_ReadDataWithNotAck;
	}

	*Recive_Data = TWI_TWDR;

	return Local_u8ErrorState;
}

/*Stop*/
void TWI_voidSendStopCondition(void)
{
	TWI_TWCR = (1 << TWCR_TWSTO) | (1 << TWCR_TWINT) | (1 << TWCR_TWEN);

}

/*Slave*/
void TWI_voidSlaveInit(u8 Local_SlaveAddress)
{
	/*Set Slave Address iN TWAR*/
	TWI_TWAR = (Local_SlaveAddress << 1);

	/*Enable ACK*/
	SET_BIT(TWI_TWCR, TWCR_TWEA);

	/*Enable TWI*/
	SET_BIT(TWI_TWCR, TWCR_TWEN);
}

u32 Power(u32 base, u32 exponent)
{
    u32 result = 1;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}
