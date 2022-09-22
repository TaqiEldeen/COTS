/*
 * StepperMotor_pri.h
 *
 *  Created on: 26 Aug 2022
 *      Author: 20109
 */

#ifndef HAL_STEPPERMOTOR_STEPPERMOTOR_PRI_H_
#define HAL_STEPPERMOTOR_STEPPERMOTOR_PRI_H_

#define FULL_STEP_MODE 1
#define HALF_STEP_MODE 0

/**
 * you can get the required delay between steps given the RPM
 *
 * Max RPM = 15
 * Min RPM = 1 (for this equation and you can just stop the motor if you want)
 */
#define DELAY_EQN   ( 15 / (512*RPM) )

/*
 * You can get the required steps given the degree
 * */

#define STEPS_EQN  ( DEGREE / (0.17578125))

#endif /* HAL_STEPPERMOTOR_STEPPERMOTOR_PRI_H_ */
