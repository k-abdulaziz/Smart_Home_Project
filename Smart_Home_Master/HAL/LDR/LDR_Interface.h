/*
 * LM35_Interface.h
 *
 *  Created on: May 28, 2023
 *      Author: khale
 */

#ifndef HAL_LDR_LDR_INTERFACE_H_
#define HAL_LDR_LDR_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"

void LDR_voidInit(void);
u16 LDR_u16ReadValue(void);

#endif /* HAL_LDR_LDR_INTERFACE_H_ */
