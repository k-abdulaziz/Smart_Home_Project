/**
 * @file GIE_Program.c
 * @author Khaled Abdulaziz 
 * @brief 
 * @version 0.1
 * @date 2023-04-02
 * 
 * 
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "GIE_Interface.h"
#include "GIE_Private.h"
#include "GIE_Config.h"

void GIE_VoidEnable(void)
{
	__asm__ __volatile__ ("sei" ::);
    //SET_BIT(GIE_SREG, SREG_I);
}

void GIE_VoidDisable(void)
{
    CLEAR_BIT(GIE_SREG, SREG_I);
}
