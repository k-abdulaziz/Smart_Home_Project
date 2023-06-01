/*
 * LM35_Interface.h
 *
 *  Created on: May 28, 2023
 *      Author: khale
 */

#ifndef HAL_LM35_LM35_INTERFACE_H_
#define HAL_LM35_LM35_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"

void LM35_voidInit(void);
u8 LM35_u8ReadTemperature(void);

#endif /* HAL_LM35_LM35_INTERFACE_H_ */
