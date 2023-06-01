/**
 * @file TWI_Interface.h
 * @author Khaled Abdulaziz 
 * @brief 
 * @version 0.1
 * @date 2023-04-14
 * 
 * 
 */

#ifndef MCAL_TWI_TWI_INTERFACE_H_
#define MCAL_TWI_TWI_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"

#define TWI_PRESCALER_1  	0x00
#define TWI_PRESCALER_4  	0x01
#define TWI_PRESCALER_16  	0x02
#define TWI_PRESCALER_64  	0x03

#define TWI_PRESCALER TWI_PRESCALER_1

typedef enum
{
    No_Error,
    Error_StartCondition,
    Error_ReStartCondition,
    Error_SLAWACK, /*Wrong when Send the Slave Address And Write*/
    Error_SLAWNotACK,
    Error_SLARACK,
    Error_SLArNotACK,
    Error_WriteDataWithAck,
    Error_WriteDataWithNotAck,
    Error_ReadDataWithAck,
    Error_ReadDataWithNotAck
} TWI_EN_Error_t;

//master
void TWI_voidMasterInit(u8 Copy_u8Address);

TWI_EN_Error_t TWI_voidSendStartCondition(void);
TWI_EN_Error_t TWI_voidSendRepeated_StartCondition(void);
TWI_EN_Error_t TWI_voidSendSlaveAddressWithWriteACK(u8 Local_SlaveAdress);
TWI_EN_Error_t TWI_voidSendSlaveAddressWithWriteNACK(u8 Local_SlaveAdress);
TWI_EN_Error_t TWI_voidSendSlaveAddressWithReadACK(u8 Local_SlaveAdress);
TWI_EN_Error_t TWI_voidSendSlaveAddressWithReadNACK(u8 Local_SlaveAdress);
TWI_EN_Error_t TWI_voidMasterWriteDataACK(u8 Local_Data);
TWI_EN_Error_t TWI_voidMasterWriteDataNACK(u8 Local_Data);

TWI_EN_Error_t TWI_voidMasterReadDataACK(u8 *Recive_Data);
TWI_EN_Error_t TWI_voidMasterReadDataNACK(u8 *Recive_Data);

void TWI_voidSendStopCondition(void);

/* slave */
void TWI_voidSlaveInit(u8 Local_SlaveAdress);
void TWI_voidSlaveSendData (u8 Local_Data);
u8   TWI_u8SlaveReceiveData();

#endif /* MCAL_TWI_TWI_INTERFACE_H_ */
