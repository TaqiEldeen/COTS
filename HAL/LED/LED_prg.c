/*
 * LED_prg.c
 *
 *  Created on: 19 Aug 2022
 *      Author: 20109
 */
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "LED_cfg.h"
#include "LED_int.h"

void LED_vInit (u8 A_u8LedId){
	switch(A_u8LedId){
		case LED0_ID: DIO_vSetPinDir(LED0_PORT, LED0_PIN, DIR_OUTPUT);  break;
		case LED1_ID: DIO_vSetPinDir(LED1_PORT, LED1_PIN, DIR_OUTPUT);  break;
		case LED2_ID: DIO_vSetPinDir(LED2_PORT, LED2_PIN, DIR_OUTPUT);  break;
		case LED3_ID: DIO_vSetPinDir(LED3_PORT, LED3_PIN, DIR_OUTPUT);  break;
		case LED4_ID: DIO_vSetPinDir(LED4_PORT, LED4_PIN, DIR_OUTPUT);  break;
		case LED5_ID: DIO_vSetPinDir(LED5_PORT, LED5_PIN, DIR_OUTPUT);  break;
		case LED6_ID: DIO_vSetPinDir(LED6_PORT, LED6_PIN, DIR_OUTPUT);  break;
		case LED7_ID: DIO_vSetPinDir(LED7_PORT, LED7_PIN, DIR_OUTPUT);  break;
	}
}

void LED_vInitAll (){
	DIO_vSetPinDir(LED0_PORT, LED0_PIN, DIR_OUTPUT);
	DIO_vSetPinDir(LED1_PORT, LED1_PIN, DIR_OUTPUT);
	DIO_vSetPinDir(LED2_PORT, LED2_PIN, DIR_OUTPUT);
	DIO_vSetPinDir(LED3_PORT, LED3_PIN, DIR_OUTPUT);
	DIO_vSetPinDir(LED4_PORT, LED4_PIN, DIR_OUTPUT);
	DIO_vSetPinDir(LED5_PORT, LED5_PIN, DIR_OUTPUT);
	DIO_vSetPinDir(LED6_PORT, LED6_PIN, DIR_OUTPUT);
	DIO_vSetPinDir(LED7_PORT, LED7_PIN, DIR_OUTPUT);
}

void LED_vTurnOn  (u8 A_u8LedId){
	switch(A_u8LedId){
		case LED0_ID: DIO_vSetPinVal(LED0_PORT, LED0_PIN, VAL_HIGH);  break;
		case LED1_ID: DIO_vSetPinVal(LED1_PORT, LED1_PIN, VAL_HIGH);  break;
		case LED2_ID: DIO_vSetPinVal(LED2_PORT, LED2_PIN, VAL_HIGH);  break;
		case LED3_ID: DIO_vSetPinVal(LED3_PORT, LED3_PIN, VAL_HIGH);  break;
		case LED4_ID: DIO_vSetPinVal(LED4_PORT, LED4_PIN, VAL_HIGH);  break;
		case LED5_ID: DIO_vSetPinVal(LED5_PORT, LED5_PIN, VAL_HIGH);  break;
		case LED6_ID: DIO_vSetPinVal(LED6_PORT, LED6_PIN, VAL_HIGH);  break;
		case LED7_ID: DIO_vSetPinVal(LED7_PORT, LED7_PIN, VAL_HIGH);  break;
	}
}

void LED_vTurnOff (u8 A_u8LedId){
	switch(A_u8LedId){
		case LED0_ID: DIO_vSetPinVal(LED0_PORT, LED0_PIN, VAL_LOW);  break;
		case LED1_ID: DIO_vSetPinVal(LED1_PORT, LED1_PIN, VAL_LOW);  break;
		case LED2_ID: DIO_vSetPinVal(LED2_PORT, LED2_PIN, VAL_LOW);  break;
		case LED3_ID: DIO_vSetPinVal(LED3_PORT, LED3_PIN, VAL_LOW);  break;
		case LED4_ID: DIO_vSetPinVal(LED4_PORT, LED4_PIN, VAL_LOW);  break;
		case LED5_ID: DIO_vSetPinVal(LED5_PORT, LED5_PIN, VAL_LOW);  break;
		case LED6_ID: DIO_vSetPinVal(LED6_PORT, LED6_PIN, VAL_LOW);  break;
		case LED7_ID: DIO_vSetPinVal(LED7_PORT, LED7_PIN, VAL_LOW);  break;
	}
}


