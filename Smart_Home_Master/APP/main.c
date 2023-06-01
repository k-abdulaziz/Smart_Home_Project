#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <util/delay.h>

#include "../MCAL/DIO/DIO_Interface.h"
#include "../MCAL/EXTI/EXTI_Interface.h"
#include "../MCAL/GIE/GIE_Interface.h"
#include "../HAL/EEPROM/EEPROM_Interface.h"
#include "../HAL/LCD/LCD_Interface.h"
#include "../HAL/KPD/KPD_Interface.h"
#include "../HAL/Servo_Motor/Servo_Motor_Interface.h"
#include "../HAL/BUZ/BUZ_Interface.h"
#include "../HAL/LED/LED_Interface.h"
#include "../HAL/LM35/LM35_Interface.h"
#include "../HAL/LDR/LDR_Interface.h"

void APP_voidWelcomeScreen();
void APP_voidUserScreen(s8 Copy_as8EnteredUser[]);
void APP_voidPasswordScreen(char Copy_as8Message[], char Copy_as8EnteredPassword[]);
void APP_voidAccessGrantedScreen();
void APP_voidAccessDeniedScreen();
void APP_voidInvalidOptionScreen();
void APP_voidTheftAlarm();
void APP_voidMainMenu();
void APP_voidDoorMenu();
void APP_voidInvalidOptionScreen();
void APP_voidReset(void);
void APP_voidAC(void);
void APP_voidLights(void);

u16 Local_u16Password_Loc = 0x00;
s16 EEPROM_u16Byte = 0;
static u8 StGlobal_u8Temperature;
static u16 StGlobal_u16LightValue;

int main(void)
{
	u8 init_flag, reset_flag;
	LCD_voidInit();
	ADC_voidInit();
	DC_MOTOR_voidInit();
    KPD_voidInit();
	EXTI_voidInit();
	GIE_VoidEnable();
    LED_voidInit();
    BUZ_voidInit();
	TWI_voidMasterInit(0x00);
    Servo_Motor_voidInit();
    EEPROM_voidReadDataByte(EEPROM_INIT_FLAG_ADDRESS, &init_flag);
    //EEPROM_voidReadDataByte(EEPROM_INIT_FLAG_ADDRESS, &reset_flag);

	BUZ_voidTurnOFF();

    if(init_flag == 0xFF)
    {
        EEPROM_voidInit();
    }

    EXTI_voidSetCallBackINT0(&APP_voidReset);

	u8 Local_u8Data = 0x00;
	u16 Local_u16Data = 0x00;
	//static u16 Local_u16Password_Loc = 0x00;

    u16 tries = 0;
    static s8 Local_as8EnteredUser[4];
    static s8 Local_as8EnteredPassword[6];

    APP_voidWelcomeScreen();

	while (1) {
		APP_voidUserScreen(Local_as8EnteredUser);
		APP_voidPasswordScreen("ENTER PASSWORD:", Local_as8EnteredPassword);
		u8 User_Flag = 0, Password_Flag = 0;
		u8 Local_u8UserNum = atoi(Local_as8EnteredUser);
		u16 Local_u16PasswordNum = atoi(Local_as8EnteredPassword);
		for(s16 EEPROM_u16Byte = 0; EEPROM_u16Byte < 10; EEPROM_u16Byte++)
		{
			Local_u16Password_Loc = EEPROM_PASSWORDS_START_ADDRESS + (EEPROM_u16Byte * 2);
			EEPROM_voidReadDataByte(EEPROM_u16Byte, &Local_u8Data);
			if(Local_u8UserNum == Local_u8Data)
			{
				User_Flag = 1;
				EEPROM_voidReadDataWord(Local_u16Password_Loc, &Local_u16Data);
				if(Local_u16PasswordNum == Local_u16Data)
				{
					Password_Flag = 1;
				}
				else
				{
					break;
				}
			}
		}
		if (User_Flag == 1 && Password_Flag == 1) {
			APP_voidAccessGrantedScreen();
			APP_voidMainMenu();
		} else {
			tries++;
			if (tries == 3) {
				APP_voidTheftAlarm();
				tries = 0;
			} else {
				APP_voidAccessDeniedScreen();
			}
		}
	}

	return 0;
}

void APP_voidWelcomeScreen()
{
    s8 message[] = "WELCOME TO SMART HOME!";
    int i;

    LCD_voidClearDisplay();
    LCD_voidGotoXY(0, 15);
    LCD_voidSendString(message);

    for (i = 0; i < (strlen(message) + LCD_COLUMNS_NUMBER - 1); i++) {
        LCD_voidDisplayShiftLeft();
        _delay_ms(100);
    }
}

void APP_voidUserScreen(s8 Copy_as8EnteredUser[])
{
    s8 message[] = "ENTER USER:";
    int i, j;
    char key;

    LCD_voidClearDisplay();
    LCD_voidSendString(message);

    for (i = 0, j = 0; i < 3; ) {
        key = KPD_u8GetKey();

        if (key != 0xFF) {
        	Copy_as8EnteredUser[i] = key;
            LCD_voidGotoXY(1, j);
            LCD_voidSendData(key);
            _delay_ms(100);
            i++;
            j++;
        }
    }

    Copy_as8EnteredUser[3] = '\0';
}


void APP_voidPasswordScreen(char Copy_as8Message[], char Copy_as8EnteredPassword[])
{
    //s8 message[] = "ENTER PASSWORD:";
    int i, j;
    char key;

    LCD_voidClearDisplay();
    LCD_voidSendString(Copy_as8Message);

    for (i = 0, j = 0; i < 5; ) {
        key = KPD_u8GetKey();

        if (key != 0xFF) {
        	Copy_as8EnteredPassword[i] = key;
            LCD_voidGotoXY(1, j);
            LCD_voidSendData(key);
            _delay_ms(100);
            LCD_voidGotoXY(1, j);
            LCD_voidSendData('*');
            i++;
            j++;
        }
    }

    Copy_as8EnteredPassword[5] = '\0';
}

void APP_voidChangePassword() {
    //s8 message[] = "ENTER OLD PASSWORD:";
    s16 i, j;
    s8 key;
	u16 Local_u16Data = 0x00;
    s8 Copy_as8OldPassword[6], Copy_as8NewPassword1[6], Copy_as8NewPassword2[6];
    u16 old_password, new_password1, new_password2;
    //u16 password_loc;

    APP_voidPasswordScreen("NTR OLD PASSWORD:", Copy_as8OldPassword);

    // Check if old password is correct
    Local_u16Password_Loc = EEPROM_PASSWORDS_START_ADDRESS + (EEPROM_u16Byte * 2);
    EEPROM_voidReadDataWord(Local_u16Password_Loc, &Local_u16Data);
    u16 Local_u16PasswordNum = atoi(Copy_as8OldPassword);
    if (Local_u16PasswordNum != Local_u16Data) {
        // Old password is incorrect
        LCD_voidClearDisplay();
        LCD_voidSendString("WRONG PASSWORD!");
        _delay_ms(2000);
        return;
    }

    // Get new password from user
    APP_voidPasswordScreen("NTR NEW PASSWORD:", Copy_as8NewPassword1);

    // Get new password again to confirm
    APP_voidPasswordScreen("CNFRM NEW PASSWORD:", Copy_as8NewPassword2);

    // Check if new passwords match
    if (strcmp(Copy_as8NewPassword1, Copy_as8NewPassword2)) {
        // New passwords don't match
        LCD_voidClearDisplay();
        LCD_voidSendString("NOT MATCHING!");
        _delay_ms(2000);
        return;
    }

    // Write new password to EEPROM
    EEPROM_voidWriteDataWord(Local_u16Password_Loc, atoi(Copy_as8NewPassword1));
    //Users_Data[EEPROM_u16Byte].Local_au16Passwords = new_Password1;

    // Success message
    LCD_voidClearDisplay();
    LCD_voidSendString("PASSWORD CHANGED!");
    _delay_ms(1000);

    //APP_voidMainMenu();
}


void APP_voidAccessGrantedScreen() {
	LCD_voidClearDisplay();
	LCD_voidSendString((s8*) "WELCOME HOME!");
    LED_voidTurnON(INDICATORS_PORT, GREEN_INDICATOR_LED);
	_delay_ms(1000);
}

void APP_voidAccessDeniedScreen() {
	LCD_voidClearDisplay();
	LCD_voidSendString((s8*) "WRONG USER/PASS!");
	_delay_ms(1000);
	LCD_voidClearDisplay();
}

void APP_voidTheftAlarm()
{
	s32 i;
	for (i = 0; i < 10; i++) {
		LCD_voidClearDisplay();
		_delay_ms(200);
		LCD_voidSendString((s8*) "THEFT ALARM!");
		BUZ_voidTurnON();
		LED_voidTurnON(INDICATORS_PORT, RED_INDICATOR_LED);
	    _delay_ms(1000);
		BUZ_voidTurnOFF();
		LED_voidTurnOFF(INDICATORS_PORT, RED_INDICATOR_LED);
	    _delay_ms(1000);
	}
}

void APP_voidMainMenu() {
	u8 Local_u8Key;
	LCD_voidClearDisplay();
	LCD_voidGotoXY(0, 0);
	LCD_voidSendString((s8*) "1.DOOR  2.LIGHT");
	LCD_voidGotoXY(1, 0);
	LCD_voidSendString((s8*) "3.C/P 4.RESTART");
	while (1) {
		Local_u8Key = KPD_u8GetKey();
		if (Local_u8Key != 0xFF) {
			if (Local_u8Key == '1') {
				APP_voidDoorMenu();
			} else if (Local_u8Key == '2') {
				APP_voidLightMenu();
			} else if (Local_u8Key == '3') {
				APP_voidChangePassword();
				APP_voidMainMenu();
			} else if (Local_u8Key == '4') {
				main();
			} else {
				APP_voidInvalidOptionScreen();
				APP_voidMainMenu();
			}
		}

		APP_voidAC();
		APP_voidLights();
	}
}

void APP_voidDoorMenu() {
	u8 Local_u8Key;
	LCD_voidClearDisplay();
	LCD_voidGotoXY(0, 0);
	LCD_voidSendString((s8*) "1.Open 2.Close");
	LCD_voidGotoXY(1, 0);
	LCD_voidSendString((s8*) "3.Back");
	while (1) {
		Local_u8Key = KPD_u8GetKey();
		if (Local_u8Key != 0xFF) {
			if (Local_u8Key == '1') {
				Servo_Motor_voidMove(90);
			} else if (Local_u8Key == '2') {
				Servo_Motor_voidMove(0);
			} else if (Local_u8Key == '3') {
				APP_voidMainMenu();
			} else {
				APP_voidInvalidOptionScreen();
				APP_voidDoorMenu();
			}
		}

		APP_voidAC();
		APP_voidLights();

	}
}

void APP_voidLightMenu() {
	u8 Local_u8Key;
	LCD_voidClearDisplay();
	LCD_voidGotoXY(0, 0);
	LCD_voidSendString((s8*) "1.T-ON 2.T-OFF");
	LCD_voidGotoXY(1, 0);
	LCD_voidSendString((s8*) "3.Back");
	while (1) {
		Local_u8Key = KPD_u8GetKey();
		if (Local_u8Key != 0xFF) {
			if (Local_u8Key == '1') {
				LED_voidTurnON(LIGHT_PORT, LIGHT_LED1);
				LED_voidTurnON(LIGHT_PORT, LIGHT_LED2);
				LED_voidTurnON(LIGHT_PORT, LIGHT_LED3);
			} else if (Local_u8Key == '2') {
				LED_voidTurnOFF(LIGHT_PORT, LIGHT_LED1);
				LED_voidTurnOFF(LIGHT_PORT, LIGHT_LED2);
				LED_voidTurnOFF(LIGHT_PORT, LIGHT_LED3);
			} else if (Local_u8Key == '3') {
				APP_voidMainMenu();
			} else {
				APP_voidInvalidOptionScreen();
				APP_voidDoorMenu();
			}
		}

		APP_voidAC();
		//APP_voidLights();
	}
}

void APP_voidInvalidOptionScreen() {
	LCD_voidClearDisplay();
	LCD_voidSendString((s8*) "INVALID OPTION!");
	_delay_ms(1000);
	LCD_voidClearDisplay();
}


void APP_voidReset(void)
{
    _delay_ms(5000); // wait for 5 seconds to confirm button press
    EEPROM_voidWriteDataByte(EEPROM_RESET_FLAG_ADDRESS, 0x00);
    if (DIO_u8GetPinValue(DIO_PORT_D, DIO_PIN2) == DIO_LOW) { // check if the button is still pressed
        //cli(); // disable interrupts to prevent unwanted behavior during reset
    	EEPROM_voidInit();
        __asm__ __volatile__ ("jmp 0"); // jump to address 0 to reset the program
    }
}

void APP_voidAC(void)
{
	StGlobal_u8Temperature = LM35_u8ReadTemperature();

	if(StGlobal_u8Temperature <= 20)
	{
		DC_MOTOR_voidRunClockwise();
	}

	else if(StGlobal_u8Temperature >= 30)
	{
		DC_MOTOR_voidRunAntiClockwise();
	}

	else
	{
		DC_MOTOR_voidStop();
	}
}

void APP_voidLights(void)
{
	StGlobal_u16LightValue = LDR_u16ReadValue();

	if(StGlobal_u16LightValue <= 500)
	{
		LED_voidTurnON(LIGHT_PORT, LIGHT_LED1);
		LED_voidTurnON(LIGHT_PORT, LIGHT_LED2);
		LED_voidTurnON(LIGHT_PORT, LIGHT_LED3);
	}
	else
	{
		LED_voidTurnOFF(LIGHT_PORT, LIGHT_LED1);
		LED_voidTurnOFF(LIGHT_PORT, LIGHT_LED2);
		LED_voidTurnOFF(LIGHT_PORT, LIGHT_LED3);
	}
}
