/*
 * LCD_animation2_prg.c
 *
 *  Created on: 23 Aug 2022
 *      Author: 20109
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "../../HAL/LCD/LCD_int.h"
#include "LCD_animation2_int.h"
#include <avr/delay.h>
static u8 LCD_animation2_u8CalcWordLength(u8* A_u8Word);
static u8 L_u8WordLength ;
static const u8 L_u8Word [] = "TAQI ELDEEN";

void LCD_animation2_vInit(){
	LCD_vInit();
	L_u8WordLength = LCD_animation2_u8CalcWordLength(L_u8Word);
	LCD_vDispStr(L_u8Word);
}

static u8 LCD_animation2_u8CalcWordLength(u8* A_u8Word){
	u8 L_u8Iterator = 0;

	while(A_u8Word[L_u8Iterator] != 0){
		L_u8Iterator++;
	}
	return L_u8Iterator;
}

void LCD_animation2_vUpdate(){
	for(u8 i=0; i<= 15 - L_u8WordLength; i++){
		LCD_vShiftDisp(SHIFT_RIGHT);
		_delay_ms(500);
	}
	for(s8 i=15 - L_u8WordLength; i>=0; i--){
		LCD_vShiftDisp(SHIFT_LEFT);
		_delay_ms(500);
	}

}
