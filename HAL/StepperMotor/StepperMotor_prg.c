/*
 * StepperMotor_prg.c
 *
 *  Created on: 25 Aug 2022
 *      Author: 20109
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "StepperMotor_pri.h"
#include "StepperMotor_cfg.h"
#include "StepperMotor_int.h"
#include <avr/delay.h>

void StepperMotor_vInit(){
	DIO_vSetPinDir(COILS_PORT, BLUE_COIL_PIN, DIR_OUTPUT);
	DIO_vSetPinDir(COILS_PORT, PINK_COIL_PIN, DIR_OUTPUT);
	DIO_vSetPinDir(COILS_PORT, YELLOW_COIL_PIN, DIR_OUTPUT);
	DIO_vSetPinDir(COILS_PORT, ORANGE_COIL_PIN, DIR_OUTPUT);
}

/* the function should handle turning on the motor in a specific direction
 *
 *
 * */
void StepperMotor_vTurnOn(u8 A_u8Dir){
#if (STEPS_MODE == FULL_STEP_MODE)
	const u8 L_u8FullStepSequence[4][4] = {
			/*PINK, YELLOW, BLUE, ORANGE*/
			{0, 0, 1, 0},
			{1, 0, 0, 0},
			{0, 1, 0, 0},
			{0, 0, 0, 1}
	};

	switch(A_u8Dir){
		case STEPPER_ANTI_CLK_WISE:
		{
			for(u8 step=0; step<4; step++){
				DIO_vSetPinVal(COILS_PORT, PINK_COIL_PIN,   L_u8FullStepSequence[step][0]);
				DIO_vSetPinVal(COILS_PORT, YELLOW_COIL_PIN, L_u8FullStepSequence[step][1]);
				DIO_vSetPinVal(COILS_PORT, BLUE_COIL_PIN,   L_u8FullStepSequence[step][2]);
				DIO_vSetPinVal(COILS_PORT, ORANGE_COIL_PIN, L_u8FullStepSequence[step][3]);
				_delay_ms(2);
			}
			break;
		}
		case STEPPER_CLK_WISE:
		{
			for(s8 step=3; step>=0; step--){
				DIO_vSetPinVal(COILS_PORT, PINK_COIL_PIN,   L_u8FullStepSequence[step][0]);
				DIO_vSetPinVal(COILS_PORT, YELLOW_COIL_PIN, L_u8FullStepSequence[step][1]);
				DIO_vSetPinVal(COILS_PORT, BLUE_COIL_PIN,   L_u8FullStepSequence[step][2]);
				DIO_vSetPinVal(COILS_PORT, ORANGE_COIL_PIN, L_u8FullStepSequence[step][3]);
				_delay_ms(2);
			}
			break;
		}
	}
#else
	const u8 L_u8HalfStepSequence[8][4] = {
			/*PINK, YELLOW, BLUE, ORANGE*/
			{0, 0, 1, 1},
			{0, 0, 1, 0},
			{1, 0, 1, 0},
			{1, 0, 0, 0},
			{1, 1, 0, 0},
			{0, 1, 0, 0},
			{0, 1, 0, 1},
			{0, 0, 0, 1}
	};
	static s8 L_u8Step = 0;

	switch(A_u8Dir){
		case STEPPER_ANTI_CLK_WISE:
		{
			DIO_vSetPinVal(COILS_PORT, PINK_COIL_PIN,   L_u8HalfStepSequence[L_u8Step][0]);
			DIO_vSetPinVal(COILS_PORT, YELLOW_COIL_PIN, L_u8HalfStepSequence[L_u8Step][1]);
			DIO_vSetPinVal(COILS_PORT, BLUE_COIL_PIN,   L_u8HalfStepSequence[L_u8Step][2]);
			DIO_vSetPinVal(COILS_PORT, ORANGE_COIL_PIN, L_u8HalfStepSequence[L_u8Step][3]);
			_delay_ms(2);

			L_u8Step++;
			if(L_u8Step > 7)
				L_u8Step = 0;

			break;
		}
		case STEPPER_CLK_WISE:
		{
			DIO_vSetPinVal(COILS_PORT, PINK_COIL_PIN,   L_u8HalfStepSequence[L_u8Step][0]);
			DIO_vSetPinVal(COILS_PORT, YELLOW_COIL_PIN, L_u8HalfStepSequence[L_u8Step][1]);
			DIO_vSetPinVal(COILS_PORT, BLUE_COIL_PIN,   L_u8HalfStepSequence[L_u8Step][2]);
			DIO_vSetPinVal(COILS_PORT, ORANGE_COIL_PIN, L_u8HalfStepSequence[L_u8Step][3]);
			_delay_ms(2);

			L_u8Step--;
			if(L_u8Step < 0)
				L_u8Step = 0;

			break;
		}
	}
#endif

}

void StepperMotor_vSetRPM(u8 A_u8RPM){
	/*set delay using: delay in ms = (15/(512*RPM))*/
}

/*used to move the stepper a specific angle in a specific direction*/
void StepperMotor_vSetAngle(u8 A_u8Angle,u8 A_u8Dir){
#if (STEPS_MODE == FULL_STEP_MODE)
	const u8 L_u8FullStepSequence[4][4] = {
			/*PINK, YELLOW, BLUE, ORANGE*/
			{0, 0, 1, 0},
			{1, 0, 0, 0},
			{0, 1, 0, 0},
			{0, 0, 0, 1}
	};

	switch(A_u8Dir){
		case STEPPER_ANTI_CLK_WISE:
		{
			for(u8 step=0; step<4; step++){
				DIO_vSetPinVal(COILS_PORT, PINK_COIL_PIN,   L_u8FullStepSequence[step][0]);
				DIO_vSetPinVal(COILS_PORT, YELLOW_COIL_PIN, L_u8FullStepSequence[step][1]);
				DIO_vSetPinVal(COILS_PORT, BLUE_COIL_PIN,   L_u8FullStepSequence[step][2]);
				DIO_vSetPinVal(COILS_PORT, ORANGE_COIL_PIN, L_u8FullStepSequence[step][3]);
				_delay_ms(2);
			}
			break;
		}
		case STEPPER_CLK_WISE:
		{
			for(s8 step=3; step>=0; step--){
				DIO_vSetPinVal(COILS_PORT, PINK_COIL_PIN,   L_u8FullStepSequence[step][0]);
				DIO_vSetPinVal(COILS_PORT, YELLOW_COIL_PIN, L_u8FullStepSequence[step][1]);
				DIO_vSetPinVal(COILS_PORT, BLUE_COIL_PIN,   L_u8FullStepSequence[step][2]);
				DIO_vSetPinVal(COILS_PORT, ORANGE_COIL_PIN, L_u8FullStepSequence[step][3]);
				_delay_ms(2);
			}
			break;
		}
	}
#else
	const u8 L_u8HalfStepSequence[8][4] = {
			/*PINK, YELLOW, BLUE, ORANGE*/
			{0, 0, 1, 1},
			{0, 0, 1, 0},
			{1, 0, 1, 0},
			{1, 0, 0, 0},
			{1, 1, 0, 0},
			{0, 1, 0, 0},
			{0, 1, 0, 1},
			{0, 0, 0, 1}
	};
	s8 L_u8Steps =  A_u8Angle/0.17578125;
	s8 L_u8Iterator = 0;
	switch(A_u8Dir){
		case STEPPER_ANTI_CLK_WISE:
		{
			L_u8Iterator = 0;
			for(u32 i=0; i<(L_u8Steps/7); i++){
				DIO_vSetPinVal(COILS_PORT, PINK_COIL_PIN,   L_u8HalfStepSequence[L_u8Iterator][0]);
				DIO_vSetPinVal(COILS_PORT, YELLOW_COIL_PIN, L_u8HalfStepSequence[L_u8Iterator][1]);
				DIO_vSetPinVal(COILS_PORT, BLUE_COIL_PIN,   L_u8HalfStepSequence[L_u8Iterator][2]);
				DIO_vSetPinVal(COILS_PORT, ORANGE_COIL_PIN, L_u8HalfStepSequence[L_u8Iterator][3]);
				_delay_ms(2);
			}

			L_u8Iterator++;
			if(L_u8Iterator>7) /*After completing the sequence reset the iterator*/
				L_u8Iterator = 0;

			break;
		}
		case STEPPER_CLK_WISE:
		{
			L_u8Iterator = 7; /*the sequence is reversed*/
			for(u32 i=0; i<(L_u8Steps/7); i++){
				DIO_vSetPinVal(COILS_PORT, PINK_COIL_PIN,   L_u8HalfStepSequence[L_u8Iterator][0]);
				DIO_vSetPinVal(COILS_PORT, YELLOW_COIL_PIN, L_u8HalfStepSequence[L_u8Iterator][1]);
				DIO_vSetPinVal(COILS_PORT, BLUE_COIL_PIN,   L_u8HalfStepSequence[L_u8Iterator][2]);
				DIO_vSetPinVal(COILS_PORT, ORANGE_COIL_PIN, L_u8HalfStepSequence[L_u8Iterator][3]);
				_delay_ms(2);
			}

			L_u8Iterator--;
			if(L_u8Iterator<0) /*After completing the sequence reset the iterator*/
				L_u8Iterator = 7;

			break;
		}
	}
#endif
}

void StepperMotor_vTurnOff(){
	DIO_vSetPinVal(COILS_PORT, PINK_COIL_PIN,   VAL_LOW);
	DIO_vSetPinVal(COILS_PORT, YELLOW_COIL_PIN, VAL_LOW);
	DIO_vSetPinVal(COILS_PORT, BLUE_COIL_PIN,   VAL_LOW);
	DIO_vSetPinVal(COILS_PORT, ORANGE_COIL_PIN, VAL_LOW);
}

