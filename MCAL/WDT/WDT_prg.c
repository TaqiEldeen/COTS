/*
 * WDT_prg.c
 *
 *  Created on: 20 Sep 2022
 *      Author: 20109
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "WDT_reg.h"
#include "WDT_int.h"


void WDT_vEnable(void){
	SET_BIT(WDTCR, WDE);
}
void WDT_vDisable(void){
	WDTCR = 0b00011000;
	WDTCR = 0x00;
}
void WDT_vSetSleep(u8 A_u8SleepTime){
	WDTCR &= 0b11111000;
	WDTCR |= (A_u8SleepTime << WDP0);
}
