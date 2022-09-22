/*
 * SSD_SNAKE_prg.c
 *
 *  Created on: 18 Aug 2022
 *      Author: 20109
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../HAL/SSD/SSD_int.h"
#include "../../HAL/BTN/BTN_int.h"
#include "SSD_SNAKE_int.h"
#include <avr/delay.h>
static u8 G_u8IsClkWise = 0;

void SSD_SNAKE_vInit(){
	SSD_vInit(SSDL_ID);
	SSD_vInit(SSDR_ID);

	SSD_vTurnOn(SSDL_ID);
	SSD_vTurnOn(SSDR_ID);

	BTN_vInit(BTN0_ID);
	BTN_vInit(BTN1_ID);
}

void SSD_SNAKE_vAnimate(){
	static s8 G_u8Counter = 0;
	/*Handling directions*/
	if(G_u8IsClkWise){
		G_u8Counter++;
		if(G_u8Counter > 7){ /*reset counter*/
			G_u8Counter = 0;
		}
	} else {
		G_u8Counter--;
		if(G_u8Counter < 0){ /*reset counter*/
			G_u8Counter = 7;
		}
	}

	/*Handle the 7seg*/
	if(G_u8Counter <4 ){/*right 7seg*/
		SSD_vTurnOff(SSDL_ID);
		SSD_vTurnOn(SSDR_ID);
	} else { /*left 7seg*/
		SSD_vTurnOff(SSDR_ID);
		SSD_vTurnOn(SSDL_ID);
	}

	/*display animation*/
	switch(G_u8Counter){
		case 0: SSD_vSegmentOn(SSDL_ID, SSD_A_ID); break;
		case 1: SSD_vSegmentOn(SSDL_ID, SSD_B_ID); break;
		case 2: SSD_vSegmentOn(SSDL_ID, SSD_C_ID); break;
		case 3: SSD_vSegmentOn(SSDL_ID, SSD_D_ID); break;
		case 4: SSD_vSegmentOn(SSDR_ID, SSD_D_ID); break;
		case 5: SSD_vSegmentOn(SSDR_ID, SSD_E_ID); break;
		case 6: SSD_vSegmentOn(SSDR_ID, SSD_F_ID); break;
		case 7: SSD_vSegmentOn(SSDR_ID, SSD_A_ID); break;
	}
	/*Delay of the animation*/
	_delay_ms(500);
}

void SSD_SNAKE_vUpdate(){
	if(BTN_u8GetState(BTN0_ID) == BTN_ON && BTN_u8GetState(BTN1_ID) == BTN_OFF){
		G_u8IsClkWise = 1;
	} else if(BTN_u8GetState(BTN0_ID) == BTN_OFF && BTN_u8GetState(BTN1_ID) == BTN_ON){
		G_u8IsClkWise = 0;
	} else {
		/*DO nothing*/
	}
	SSD_SNAKE_vAnimate();
}
