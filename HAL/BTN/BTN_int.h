/*
 * BTN_int.h
 *
 *  Created on: 19 Aug 2022
 *      Author: 20109
 */

#ifndef HAL_BTN_BTN_INT_H_
#define HAL_BTN_BTN_INT_H_

/*the buttons ID*/
typedef enum {
	BTN0_ID,
	BTN1_ID,
	BTN2_ID,
	BTN3_ID,
	BTN4_ID,
	BTN5_ID,
	BTN6_ID,
	BTN7_ID
};

/*the states of the buttons*/
#define BTN_ON  1
#define BTN_OFF 0

void BTN_vInit    (u8 A_u8BtnId);
void BTN_vInitAll ();

u8 BTN_u8GetState   (u8 A_u8BtnId);
u8 BTN_u8GetAllVal  ();

#endif /* HAL_BTN_BTN_INT_H_ */
