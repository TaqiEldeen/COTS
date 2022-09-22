/*
 * BTN_cfg.h
 *
 *  Created on: 19 Aug 2022
 *      Author: 20109
 */

#ifndef HAL_BTN_BTN_CFG_H_
#define HAL_BTN_BTN_CFG_H_

/*buttons of the IMTschool AVR kit*/

#define BTN0_PORT PORTB_ID
#define BTN0_PIN  PIN0_ID

#define BTN1_PORT PORTB_ID
#define BTN1_PIN  PIN1_ID

#define BTN2_PORT PORTB_ID
#define BTN2_PIN  PIN2_ID

#define BTN3_PORT PORTB_ID
#define BTN3_PIN  PIN3_ID

#define BTN4_PORT PORTB_ID
#define BTN4_PIN  PIN4_ID

#define BTN5_PORT PORTB_ID
#define BTN5_PIN  PIN5_ID

#define BTN6_PORT PORTB_ID
#define BTN6_PIN  PIN6_ID

#define BTN7_PORT PORTB_ID
#define BTN7_PIN  PIN7_ID

/*
 * you can choose from INTERNAL_PULLUP or EXTERNAL_PULLUP
 *
 * */
#define BTN_PULLING INTERNAL_PULLUP


#endif /* HAL_BTN_BTN_CFG_H_ */
