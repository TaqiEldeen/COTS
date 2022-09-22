/*
 * BUZZER_prg.c
 *
 *  Created on: 19 Aug 2022
 *      Author: 20109
 */
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "BUZZER_cfg.h"
#include "BUZZER_int.h"

void BUZZER_vInit (){
	DIO_vSetPinDir(BUZZER_PORT, BUZZER_PIN, DIR_OUTPUT);
}
void Buzzer_vTurnOn  (){
	DIO_vSetPinVal(BUZZER_PORT, BUZZER_PIN, VAL_HIGH);
}
void Buzzer_vTurnOff (){
	DIO_vSetPinVal(BUZZER_PORT, BUZZER_PIN, VAL_LOW);
}
