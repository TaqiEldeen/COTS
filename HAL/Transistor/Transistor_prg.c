/*
 * Transistor_prg.c
 *
 *  Created on: 25 Aug 2022
 *      Author: 20109
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "Transistor_cfg.h"
#include "Transistor_int.h"

void Transistor_vInit(u8 A_u8TrId){
	switch(A_u8TrId){
		case TR0_ID: DIO_vSetPinDir(TR0_PORT, TR0_PIN, DIR_OUTPUT); break;
		case TR1_ID: DIO_vSetPinDir(TR1_PORT, TR1_PIN, DIR_OUTPUT); break;
		case TR2_ID: DIO_vSetPinDir(TR2_PORT, TR2_PIN, DIR_OUTPUT); break;
		case TR3_ID: DIO_vSetPinDir(TR3_PORT, TR3_PIN, DIR_OUTPUT); break;
	}
}
void Transistor_vTurnOn(u8 A_u8TrId){
	switch(A_u8TrId){
		case TR0_ID: DIO_vSetPinVal(TR0_PORT, TR0_PIN, VAL_HIGH); break;
		case TR1_ID: DIO_vSetPinVal(TR1_PORT, TR1_PIN, VAL_HIGH); break;
		case TR2_ID: DIO_vSetPinVal(TR2_PORT, TR2_PIN, VAL_HIGH); break;
		case TR3_ID: DIO_vSetPinVal(TR3_PORT, TR3_PIN, VAL_HIGH); break;
	}
}
void Transistor_vTurnOff(u8 A_u8TrId){
	switch(A_u8TrId){
		case TR0_ID: DIO_vSetPinVal(TR0_PORT, TR0_PIN, VAL_LOW); break;
		case TR1_ID: DIO_vSetPinVal(TR1_PORT, TR1_PIN, VAL_LOW); break;
		case TR2_ID: DIO_vSetPinVal(TR2_PORT, TR2_PIN, VAL_LOW); break;
		case TR3_ID: DIO_vSetPinVal(TR3_PORT, TR3_PIN, VAL_LOW); break;
	}
}

