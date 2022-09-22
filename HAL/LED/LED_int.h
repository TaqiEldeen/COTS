/*
 * LED_int.h
 *
 *  Created on: 19 Aug 2022
 *      Author: 20109
 */

#ifndef HAL_LED_LED_INT_H_
#define HAL_LED_LED_INT_H_

typedef enum {
	LED0_ID,
	LED1_ID,
	LED2_ID,
	LED3_ID,
	LED4_ID,
	LED5_ID,
	LED6_ID,
	LED7_ID
};

#define LED_ON  1
#define LED_OFF 0

void LED_vInit    (u8 A_u8LedId);
void LED_vInitAll ();
void LED_vTurnOn  (u8 A_u8LedId);
void LED_vTurnOff (u8 A_u8LedId);


#endif /* HAL_LED_LED_INT_H_ */
