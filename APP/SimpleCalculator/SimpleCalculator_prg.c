/*
 * SimpleCalculator_prg.c
 *
 *  Created on: 24 Aug 2022
 *      Author: TaqiEldeen
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../HAL/LCD/LCD_int.h"
#include "../../HAL/KeyPad/KeyPad_int.h"
#include "SimpleCalculator_pri.h"
#include "SimpleCalculator_int.h"
#include <avr/delay.h>

void SimpleCalulator_vInit(){
	LCD_vInit();
	KeyPad_vInit();
	LCD_vSetPosition(ROW0_ID, COL4_ID);
	LCD_vDispStr("Welcome!");
	_delay_ms(1000);
	LCD_vClrDisp();
}

void SimpleCalulator_vUpdate(){
	/*The array size is the number of available Columns in the LCD*/
	static u8 L_u8Calculator[16] = {}; /*Used to save the whole process of the calculation*/
	static u8 L_u8Iterator = 0; /*Used to iterate throw the array*/

	u8 L_u8GetVal = KeyPad_u8GetPressedKey(); /*Get the pressed value*/

	if(L_u8GetVal != NO_PRESSED_KEY){ /*If the user pressed a key*/
		if(L_u8GetVal == '='){ /*If the user wants to calculate*/
			SimpleCalculator_vHandleCalculate(L_u8Calculator, L_u8Iterator);
			for(u8 i=0; i<L_u8Iterator; i++) L_u8Calculator[i] = 0;
			L_u8Iterator = 0;
		} else if (L_u8GetVal == 'c'){ /*If the user want to clear*/
			LCD_vClrDisp();
			for(u8 i=0; i<L_u8Iterator; i++) L_u8Calculator[i] = 0;
			L_u8Iterator = 0;
		} else {/*Entering the values*/
			L_u8Calculator[L_u8Iterator] = L_u8GetVal; /*save the value in the array*/
			LCD_vDispChar(L_u8GetVal);
			L_u8Iterator++;
		}
	}

}

static void SimpleCalculator_vSetTheResultPos(){ /*Used to set the Result position*/
	LCD_vSetPosition(ROW1_ID, COL0_ID);
	LCD_vDispStr("Res =");
}

static s32 SimpleCalculator_u8Calculate(u8 *A_u8LeftOperand, u8 *A_u8RightOperand, u8 A_u8Operation){
	s32 L_s32Result;
	s32 L_s32LeftVal, L_s32RightVal;

	L_s32LeftVal = SimpleCalculator_s32StrToInt(A_u8LeftOperand);
	L_s32RightVal = SimpleCalculator_s32StrToInt(A_u8RightOperand);

	switch(A_u8Operation){
		case '+': L_s32Result = L_s32LeftVal + L_s32RightVal; break;
		case '-': L_s32Result = L_s32LeftVal - L_s32RightVal; break;
		case '/': L_s32Result = L_s32LeftVal / L_s32RightVal; break;
		case '*': L_s32Result = L_s32LeftVal * L_s32RightVal; break;
	}

	return L_s32Result;
}

void SimpleCalculator_vHandleCalculate(u8 * A_u8Str, u8 A_u8Len){/*Handle calculation*/
	u8 L_u8OpLength = 0;
	u8 L_u8LeftOperand[9] = {};
	u8 L_u8RightOperand[9] = {};
	u8 L_u8Operation;
	s32 L_s32Result;

	L_u8OpLength = A_u8Len;
	SimpleCalculator_vSetTheResultPos();

	if(L_u8OpLength <3){
		LCD_vDispStr("INVALID");
	} else {
		for(u8 i=0; ; i++){ /*Get the left operand*/
			if(GET_LEFT_OPERAND_CONDITION){/*got the left operand*/
				L_u8LeftOperand[i] = '\0'; /*Apply NILL*/
				L_u8Operation = A_u8Str[i];/*Get the operation*/
				u8 k;
				for(k=i+1; k<L_u8OpLength; k++){ /*Get the Right operand*/
					L_u8RightOperand[k - (i+1)] = A_u8Str[k];
				}
				L_u8RightOperand[k] = '\0'; /*Apply Nill*/
				break; /*Break from the loop*/
			}
			L_u8LeftOperand[i] = A_u8Str[i];
		}
		/*Get the result and display it*/
		L_s32Result = SimpleCalculator_u8Calculate(L_u8LeftOperand, L_u8RightOperand, L_u8Operation);
		LCD_vDispNum(L_s32Result);
	}
	/*Delay to clear after the result*/
	_delay_ms(2000);
	LCD_vClrDisp();
}


static s32 SimpleCalculator_s32StrToInt(u8 *A_u8Str){
	s32 L_u32Num = 0;

	for(u8 i=0; A_u8Str[i] != '\0'; i++){
		L_u32Num = L_u32Num*10 + (A_u8Str[i] - 0x30);
	}
	return L_u32Num;
}
