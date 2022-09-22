/*
 * main.c
 *
 *  Created on: 16 Aug 2022
 *      Author: 20109
 */

#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"
#include "../HAL/LED/LED_int.h"
#include "../MCAL/GIE/GIE_int.h"
#include "../MCAL/DIO/DIO_int.h"
#include "../MCAL/TIMER/TIMER_int.h"
#include "../MCAL/WDT/WDT_int.h"
#include <avr/delay.h>

/*Little endian: Least byte + Least address*/
/*Floating number representation in memory*/
/*float 1.1, 1.5, 1.75
 * if(x == 1.1)
 * else if(x == 1.5)
 * else if(x == 1.75)
 * */

void APP_LED(){
	DIO_vSetPinVal(PORTA_ID, PIN7_ID, VAL_HIGH);
	_delay_ms(1500);
	DIO_vSetPinVal(PORTA_ID, PIN7_ID, VAL_LOW);
	_delay_ms(2000);
}

int main(void){
	DIO_vSetPinDir(PORTA_ID, PIN7_ID, DIR_OUTPUT);
	WDT_vEnable();
	WDT_vSetSleep(WDT_SLEEP_1_0S);
	APP_LED();
	WDT_vDisable();

	while(1) {

	}
}

void toggleLed(){
	static u32 L_u8Counter = 0;
	switch(L_u8Counter) {
		case 4000:
			LED_vTurnOn(LED0_ID);
			LED_vTurnOff(LED1_ID);
			LED_vTurnOff(LED2_ID);
			break;
		case 8000:
			LED_vTurnOn(LED1_ID);
			LED_vTurnOff(LED0_ID);
			LED_vTurnOff(LED2_ID);
			break;
		case 12000:
			LED_vTurnOn(LED2_ID);
			LED_vTurnOff(LED1_ID);
			LED_vTurnOff(LED0_ID);
			break;
	}

	L_u8Counter++;
	if(L_u8Counter == 12001) L_u8Counter = 0;
	return;
}
