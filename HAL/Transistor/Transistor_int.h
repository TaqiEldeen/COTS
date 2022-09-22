/*
 * Transistor_int.h
 *
 *  Created on: 25 Aug 2022
 *      Author: 20109
 */

#ifndef HAL_TRANSISTOR_TRANSISTOR_INT_H_
#define HAL_TRANSISTOR_TRANSISTOR_INT_H_

typedef enum {
	TR0_ID,
	TR1_ID,
	TR2_ID,
	TR3_ID
};

void Transistor_vInit(u8 A_u8TrId);
void Transistor_vTurnOn(u8 A_u8TrId);
void Transistor_vTurnOff(u8 A_u8TrId);


#endif /* HAL_TRANSISTOR_TRANSISTOR_INT_H_ */
