/**
 * @file KPD_Program.c
 * @author Khaled Abdulaziz
 * @brief
 * @version 0.1
 * @date 2023-03-29
 *
 *
 */
#include <util/delay.h>
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_Interface.h"

#include "KPD_Interface.h"
#include "KPD_Private.h"
#include "KPD_Config.h"

const u8 KPD_au8ROWSPINS[4] ={KPD_ROW0, KPD_ROW1, KPD_ROW2, KPD_ROW3};
const u8 KPD_au8COLUMNSPINS[4] ={KPD_COLUMN0, KPD_COLUMN1, KPD_COLUMN2, KPD_COLUMN3};

void KPD_voidInit(void)
{
	//set 4 consecutive pins as output (rows)
	DIO_voidSetPinDirection(KPD_PORT, KPD_ROW0, DIO_OUTPUT);
	DIO_voidSetPinDirection(KPD_PORT, KPD_ROW1, DIO_OUTPUT);
	DIO_voidSetPinDirection(KPD_PORT, KPD_ROW2, DIO_OUTPUT);
	DIO_voidSetPinDirection(KPD_PORT, KPD_ROW3, DIO_OUTPUT);

	//set 4 consecutive pins as input (columns)
	DIO_voidSetPinDirection(KPD_PORT, KPD_COLUMN0, DIO_INPUT);
	DIO_voidSetPinDirection(KPD_PORT, KPD_COLUMN1, DIO_INPUT);
	DIO_voidSetPinDirection(KPD_PORT, KPD_COLUMN2, DIO_INPUT);
	DIO_voidSetPinDirection(KPD_PORT, KPD_COLUMN3, DIO_INPUT);

	//write high to all pins
	DIO_voidSetPortValue(KPD_PORT, DIO_PORT_HIGH);
}

u8  KPD_u8GetKey(void)
{
	u8 Local_u8Column , Local_u8Row; /* declaration of local variables */
	u8 Local_u8Key = KPD_NO_KEY_PRESSED; /* initialization of key */

	/* check rows */
	for (Local_u8Row = 0; Local_u8Row < KPD_ROWS_NUM; Local_u8Row++)
	{
		/* put low on current row */
		DIO_voidSetPinValue(KPD_PORT, KPD_au8ROWSPINS[Local_u8Row], DIO_LOW);
		/* check columns */
		for( Local_u8Column = 0;  Local_u8Column < KPD_COLUMNS_NUM;  Local_u8Column++)
		{
			/* check if key pressed (low value of PIN) */
	        if(!DIO_u8GetPinValue(KPD_PORT, KPD_au8COLUMNSPINS[Local_u8Column]))
	        {
	        	/* until released */
	            while(!DIO_u8GetPinValue(KPD_PORT, KPD_au8COLUMNSPINS[Local_u8Column]));
	            _delay_ms(5); /* bouncing */
	            Local_u8Key = Kpd_au8Values_LCD[Local_u8Row][Local_u8Column]; /* the pressed key of keypad */
	        }
		}

		/* put high on current row */
		DIO_voidSetPinValue(KPD_PORT, KPD_au8ROWSPINS[Local_u8Row], DIO_HIGH);
	}
	return Local_u8Key;
}
