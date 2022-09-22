/*
 * LCD_animation1_prg.c
 *
 *  Created on: 23 Aug 2022
 *      Author: 20109
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "../../HAL/LCD/LCD_int.h"
#include "LCD_animation1_int.h"
#include <avr/delay.h>

void LCD_Animation1_vInit(){
	LCD_vInit();
}
void LCD_Animation1_vUpdate(){
	const u8 L_u8Word[] = "Taqi ELdeen";
	static u8 L_u8WordLength = 10;
	static u8 L_u8IsFirstRow = 1;

	static u8 L_u8Iterator = 0, L_u8ColPos = 0;

	if(L_u8IsFirstRow){
		LCD_vSetPosition(ROW0_ID, L_u8ColPos);
		L_u8IsFirstRow = 0;
	} else {
		LCD_vSetPosition(ROW1_ID, L_u8ColPos);
		L_u8IsFirstRow = 1;
	}

	LCD_vDispChar(L_u8Word[L_u8Iterator]);
	L_u8Iterator++;
	if(L_u8Iterator > L_u8WordLength){
		L_u8Iterator = 0;
	}
	L_u8ColPos++;
	if(L_u8ColPos > 15){
		_delay_ms(300);
		L_u8ColPos = 0;
	}
	_delay_ms(300);
}
