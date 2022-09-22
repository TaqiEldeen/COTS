/*
 * StepperMotor_int.h
 *
 *  Created on: 25 Aug 2022
 *      Author: 20109
 */

#ifndef HAL_STEPPERMOTOR_STEPPERMOTOR_INT_H_
#define HAL_STEPPERMOTOR_STEPPERMOTOR_INT_H_

/* The stepper angle is 11.25/64 (64 reduction gear box) so it is 0.758 per step
 * requiring 360/0.758= 2048 step for full cycle in a full step mode and 4096 steps for half step mode
 * the max speed is 500 HZ (2ms delay between each step)
 * */

typedef struct{
	u8 dir, speed, degree;
}st_stepper_motor;

#define STEPPER_ANTI_CLK_WISE 1
#define STEPPER_CLK_WISE      0

void StepperMotor_vInit();
void StepperMotor_vTurnOn(u8 A_u8Dir);
void StepperMotor_vSetRPM(u8 A_u8RPM);
void StepperMotor_vSetAngle(u8 A_u8Speed, u8 A_u8Dir);
void StepperMotor_vSetDir(u8 A_u8Dir);
void StepperMotor_vTurnOff();

#endif /* HAL_STEPPERMOTOR_STEPPERMOTOR_INT_H_ */
