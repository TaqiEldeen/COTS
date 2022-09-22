/*
 * DCmotor_prg.c
 *
 *  Created on: 25 Aug 2022
 *      Author: 20109
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "../Transistor/Transistor_int.h"
#include "DCmotor_cfg.h"
#include "DCmotor_int.h"

void DCmotor_vInit(){
	Transistor_vInit(TR0_ID);
}
void DCmotor_vTurnOn(){
	Transistor_vTurnOn(TR0_ID);
}
void DCmotor_vTurnOff(){
	Transistor_vTurnOff(TR0_ID);
}
