/*
 * SSD_TDM_prg.c
 *
 *  Created on: 17 Aug 2022
 *      Author: 20109
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../HAL/SSD/SSD_int.h"
#include "SSD_TDM_pri.h"
#include <avr/delay.h>

void SSD_TDM_vInit(){
	SSD_vInit(SSDL_ID);/*init left seven seg*/
	SSD_vInit(SSDR_ID);/*init right seven seg*/
}
void SSD_TDM_vKeepSameNum(u8 A_u8LeftVal, u8 A_u8RightVal){
	SSD_vTurnOn(SSDL_ID);
	SSD_vTurnOff(SSDR_ID);
	SSD_vDispNum(SSDL_ID, A_u8RightVal);
	_delay_ms(5);
	SSD_vTurnOff(SSDL_ID);
	SSD_vTurnOn(SSDR_ID);
	SSD_vDispNum(SSDR_ID, A_u8LeftVal);
	_delay_ms(5);
}
void SSD_TDM_vUpdate(){

	static u8 counter = 0;
	if(counter == 100)
		counter = 0;
	for(u8 i=0; i < COUNTER_DELAY_MS/10; i++){
		SSD_vTurnOn(SSDL_ID);
		SSD_vTurnOff(SSDR_ID);
		SSD_vDispNum(SSDL_ID, counter%10);
		_delay_ms(5);
		SSD_vTurnOff(SSDL_ID);
		SSD_vTurnOn(SSDR_ID);
		SSD_vDispNum(SSDR_ID, counter/10);
		_delay_ms(5);
	}
	counter++;
}
