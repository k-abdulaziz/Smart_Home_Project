/**
 * @file KPD_Config.h
 * @author Khaled Abdulaziz
 * @brief
 * @version 0.1
 * @date 2023-03-29
 *
 *
 */

#ifndef HAL_KPD_KPD_CONFIG_H_
#define HAL_KPD_KPD_CONFIG_H_

#include "../../MCAL/DIO/DIO_Interface.h"

#define KPD_PORT        DIO_PORT_B
#define KPD_ROW0        DIO_PIN0
#define KPD_ROW1        DIO_PIN1
#define KPD_ROW2        DIO_PIN2
#define KPD_ROW3        DIO_PIN3
#define KPD_COLUMN0     DIO_PIN4
#define KPD_COLUMN1     DIO_PIN5
#define KPD_COLUMN2     DIO_PIN6
#define KPD_COLUMN3     DIO_PIN7

#define KPD_ROWS_NUM    4
#define KPD_COLUMNS_NUM 4

#define KPD_NO_KEY_PRESSED 0xFF

static const u8 Kpd_au8Values_LCD[KPD_ROWS_NUM][KPD_COLUMNS_NUM] = {{'7','8','9','/'},
					 	 	 	 	 	 	 	 	 	 	 {'4','5','6','*'},
															 {'1','2','3','-'},
															 {'C','0','=','+'}};

static const u8 Kpd_au8Values_SS[KPD_ROWS_NUM][KPD_COLUMNS_NUM] = {{7,8,9,0},
					 	 	 	 	 	 	 	 	 	 	{4,5,6,0},
															{1,2,3,0},
															{0,0,0,0}};

#endif /* HAL_KPD_KPD_CONFIG_H_ */
