/*
 * DCmotor_int.h
 *
 *  Created on: 25 Aug 2022
 *      Author: 20109
 */

#ifndef HAL_DCMOTOR_DCMOTOR_INT_H_
#define HAL_DCMOTOR_DCMOTOR_INT_H_
/*Must be connected to H-bridge*/


#define ANTI_CLK_WISE 1
#define CLK_WISE      0

void DCmotor_vInit();
void DCmotor_vTurnOn();
void DCmotor_vTurnOff();
void DCmotor_vSetDirection(u8 A_u8Dir);

#endif /* HAL_DCMOTOR_DCMOTOR_INT_H_ */
