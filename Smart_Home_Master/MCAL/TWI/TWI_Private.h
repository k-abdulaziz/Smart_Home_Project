/**
 * @file TWI_Private.h
 * @author Khaled Abdulaziz 
 * @brief 
 * @version 0.1
 * @date 2023-04-14
 * 
 * 
 */

#ifndef MCAL_TWI_TWI_PRIVATE_H_
#define MCAL_TWI_TWI_PRIVATE_H_

#include "../DIO/DIO_Interface.h"

/* TWI Master Transmit Check */
#define TWI_MTX__START                         0x08
#define TWI_MTX__REPEATED_START                0x10
#define TWI_MTX__SLA_W_ACK                     0x18
#define TWI_MTX__SLA_W_NOT_ACK                 0x20
#define TWI_MTX__DATA_ACK                      0x28
#define TWI_MTX__DATA_NOT_ACK                  0x30
#define TWI_MTX__ARBITRATION_LOST              0x38

/* TWI Master Receive Check */
#define TWI_MRX__START                         0x08
#define TWI_MRX__REPEATED_START                0x10
#define TWI_MRX__ARBITRATION_LOST              0x38
#define TWI_MRX__SLA_R_ACK                     0x40
#define TWI_MRX__SLA_R_NOT_ACK                 0x48
#define TWI_MRX__DATA_ACK                      0x50
#define TWI_MRX__DATA_NOT_ACK                  0x58

/* TWI Slave Transmit Check */
#define TWI_STX__SLA_R_RECEIVED_ACK            0xA8
#define TWI_STX__ARBITRATION_LOST              0xB0
#define TWI_STX__DATA_ACK                      0xB8
#define TWI_STX__DATA_NOT_ACK                  0xC0
#define TWI_STX__LAST_DATA_RECEIVED_ACK        0xC8

/* TWI Slave Receive Check */
#define TWI_SRX__SLA_W_RECEIVED_ACK            0x60
#define TWI_SRX__ARB_LOST_SLA_R_W_SLA_W_ACK    0x68
#define TWI_SRX__GENERAL_CALL_ACK              0x70
#define TWI_SRX__ARB_LOST_GENERAL_CALL_ACK     0x78
#define TWI_SRX__SLA_W_ACK                     0x80
#define TWI_SRX__SLA_W_NOT_ACK                 0x88
#define TWI_SRX__SLA_W_GEN_CALL_DATA_ACK       0x90
#define TWI_SRX__SLA_W_GEN_CALL_DATA_NOT_ACK   0x98
#define TWI_SRX__STOP_REPEATED_START           0xA0

#define TWI_STATUS_MASK 0xF8

#define TWI_TWCR     (*(volatile u8*)0x56)
#define TWI_TWDR     (*(volatile u8*)0x23)
#define TWI_TWAR	 (*(volatile u8*)0x22)
#define TWI_TWSR	 (*(volatile u8*)0x21)
#define TWI_TWBR	 (*(volatile u8*)0x20)

#define TWCR_TWIE 0
#define TWCR_TWEN 2
#define TWCR_TWWC 3
#define TWCR_TWSTO 4
#define TWCR_TWSTA 5
#define TWCR_TWEA 6
#define TWCR_TWINT 7

#define TWSR_TWPS0 0
#define TWSR_TWPS1 1
#define TWSR_TWS3 3
#define TWSR_TWS4 4
#define TWSR_TWS5 5
#define TWSR_TWS6 6
#define TWSR_TWS7 7

#define TWAR_TWGCE 0

u32 Power(u32 base, u32 exponent);

#endif /* MCAL_TWI_TWI_PRIVATE_H_ */
