/*
 * SimpleCalculator_pri.h
 *
 *  Created on: 24 Aug 2022
 *      Author: TaqiEldeen
 */

#ifndef APP_SIMPLECALCULATOR_SIMPLECALCULATOR_PRI_H_
#define APP_SIMPLECALCULATOR_SIMPLECALCULATOR_PRI_H_

#define GET_LEFT_OPERAND_CONDITION (A_u8Str[i] =='-' || A_u8Str[i] =='+' || A_u8Str[i] == '/' || A_u8Str[i] == '*')


static s32 SimpleCalculator_u8Calculate(u8 *A_u8LeftOperand, u8 *A_u8RightOperand, u8 A_u8Operation);
static void SimpleCalculator_vHandleCalculate(u8 * A_u8Str, u8 A_u8Len);
static void SimpleCalculator_vSetTheResultPos();
static s32 SimpleCalculator_s32StrToInt(u8 *A_u8Str);

#endif /* APP_SIMPLECALCULATOR_SIMPLECALCULATOR_PRI_H_ */
