/*********************************************************/
/***********		Author: TaqiEldeen	 	**************/
/***********		Layer: MCAL			 	**************/
/***********		Component: TIMER		**************/
/***********		Version: 1.02		 	**************/
/***********		Date: 13 Sep 2022	 	**************/
/***********		Updated: 17 Sep 2022	**************/
/*********************************************************/

#ifndef MCAL_TIMER_TIMER_CFG_H_
#define MCAL_TIMER_TIMER_CFG_H_

/**************   TIMER0_config   **************/

/* WaveForm generation Mode
 *
 * Options:
 * 1- TIMER0_WGM_NORMAL_MODE
 * 2- TIMER0_WGM_PWM_PHASE_CORRECT_MODE
 * 3- TIMER0_WGM_CTC_MODE
 * 4- TIMER0_WGM_FAST_PWM_MODE
 * */
#define TIMER0_WGM_MODE TIMER0_WGM_FAST_PWM_MODE

/* Compare Match Output Mode (OC0 Pin)  CTC
 *
 * Options:
 * 1- TIMER0_OC0_DISCONNECT
 * 2- TIMER0_TOG_OC0
 * 3- TIMER0_CLR_OC0
 * 4- TIMER0_SET_OC0
 * */
#define TIMER0_OC0_MODE TIMER0_OC0_DISCONNECT

/* Clock select
 *
 * Options:
 * 1- TIMER0_PRESCALER_NO_CLK
 * 2- TIMER0_PRESCALER_NO_PRESCALE
 * 3- TIMER0_PRESCALER_8
 * 4- TIMER0_PRESCALER_64
 * 5- TIMER0_PRESCALER_256
 * 6- TIMER0_PRESCALER_1024
 * 7- TIMER0_EXT_CLK_FALLING_EDGE
 * 8- TIMER0_EXT_CLK_RISING_EDGE
 * */
#define TIMER0_CLK_SELECT TIMER0_PRESCALER_8


/* Timers state
 *
 * Options:
 * 1- TIMER_ENABLE
 * 2- TIMER_DISABLE
 * */
#define TIMER0_STATE TIMER_ENABLE

/* interrupt state
 *
 * Options:
 * 1- INT_ENABLE
 * 2- INT_DISABLE
 * */
#define TIMER0_OVF_INT_STATE	INT_DISABLE
#define TIMER0_CTC_INT_STATE	INT_DISABLE

/* TIMER0 PWM mode
 *
 * Options:
 * 1- PWM_NON_INVERTING
 * 2- PWM_INVERTING
 * Note:
 * PWM_NON_INVERTING means the Duty cycle is directly proportional to OCR
 * PWM_INVERTING means the Duty cycle is inversely proportional to OCR
 * */
#define TIMER0_PWM_MODE PWM_NON_INVERTING

/* Default PWM value
 *
 * Options:
 * 1- TIMER_DUTY_CYCLE_25
 * 2- TIMER_DUTY_CYCLE_50
 * 3- TIMER_DUTY_CYCLE_75
 * 4- TIMER_DUTY_CYCLE_100
 * */
#define TIMER0_DUTY_CYCLE TIMER_DUTY_CYCLE_25

/* TIMER0 FCPU frequency
 *
 *	Options:
 *	user specify the frequency
 * */
#define TIMER0_InputFreq 8000000UL

/* OC0 Pin Configuration */
#define OC0_PORT PORTB_ID
#define OC0_PIN	 PIN3_ID





/**************   TIMER1_config   **************/


/* WaveForm generation Mode
 *
 * Options:
 * 1- TIMER1_WGM_NORMAL_MODE
 * 2- TIMER1_WGM_PWM_PHASE_CORRECT_8BIT_MODE
 * 3- TIMER1_WGM_PWM_PHASE_CORRECT_9BIT_MODE
 * 4- TIMER1_WGM_PWM_PHASE_CORRECT_10BIT_MODE
 * 5- TIMER1_WGM_CTC_MODE
 * 6- TIMER1_WGM_FAST_PWM_8BIT_MODE
 * 7- TIMER1_WGM_FAST_PWM_9BIT_MODE
 * 8- TIMER1_WGM_FAST_PWM_10BIT_MODE
 * 9- TIMER1_WGM_PWM_PHASE_CORRECT_TOP_ICR1
 * 10-TIMER1_WGM_PWM_PHASE_CORRECT_TOP_OCR1A
 * 11-TIMER1_WGM_CTC_TOP_ICR1
 * 12-TIMER1_WGM_FAST_PWM_TOP_ICR1
 * 13-TIMER1_WGM_FAST_PWM_TOP_OCR1A
 * */
#define TIMER1_WGM_MODE TIMER1_WGM_FAST_PWM_TOP_ICR1



/* Compare Match Output Mode (OC1x Pin)	CTC
 *
 * Options:
 * 1- TIMER1_OC1x_DISCONNECT
 * 2- TIMER1_TOG_OC1x
 * 3- TIMER1_CLR_OC1x
 * 4- TIMER1_SET_OC1x
 * */
#define TIMER1_OC1A_MODE TIMER1_OC1x_DISCONNECT
#define TIMER1_OC1B_MODE TIMER1_OC1x_DISCONNECT



/* Clock select
 *
 * Options:
 * 1- TIMER1_PRESCALER_NO_CLK
 * 2- TIMER1_PRESCALER_NO_PRESCALE
 * 3- TIMER1_PRESCALER_8
 * 4- TIMER1_PRESCALER_32
 * 5- TIMER1_PRESCALER_64
 * 6- TIMER1_PRESCALER_128
 * 7- TIMER1_PRESCALER_256
 * 8- TIMER1_PRESCALER_1024
 * */
#define TIMER1_CLK_SELECT TIMER1_PRESCALER_8


/* Timers state
 *
 * Options:
 * 1- TIMER_ENABLE
 * 2- TIMER_DISABLE
 * */
#define TIMER1_STATE TIMER_DISABLE



/* interrupt state
 *
 * Options:
 * 1- INT_ENABLE
 * 2- INT_DISABLE
 * */
#define TIMER1_OVF_INT_STATE	INT_DISABLE
#define TIMER1_OCF1A_INT_STATE	INT_DISABLE
#define TIMER1_OCF1B_INT_STATE	INT_DISABLE
#define TIMER1_ICF1_INT_STATE	INT_DISABLE


/* TIMER1 PWM mode
 *
 * Options:
 * 1- PWM_NON_INVERTING
 * 2- PWM_INVERTING
 * 3- PWM_OFF
 * Note:
 * PWM_NON_INVERTING means the Duty cycle is directly proportional to OCR1x
 * PWM_INVERTING means the Duty cycle is inversely proportional to OCR1x
 * */
#define TIMER1_OC1A_PWM_MODE PWM_NON_INVERTING
#define TIMER1_OC1B_PWM_MODE PWM_NON_INVERTING


/* TIMER1 FCPU frequency
 *
 *	Options:
 *	user specify the frequency
 * */
#define TIMER1_InputFreq 8000000UL


/* OC1x Pin Configuration */
#define OC1A_PORT PORTD_ID
#define OC1A_PIN  PIN5_ID
#define OC1B_PORT PORTD_ID
#define OC1B_PIN  PIN4_ID






/**************   TIMER2_config   **************/


/* WaveForm generation Mode
 *
 * Options:
 * 1- TIMER2_WGM_NORMAL_MODE
 * 2- TIMER2_WGM_PWM_PHASE_CORRECT_MODE
 * 3- TIMER2_WGM_CTC_MODE
 * 4- TIMER2_WGM_FAST_PWM_MODE
 * */
#define TIMER2_WGM_MODE TIMER2_WGM_PWM_PHASE_CORRECT_MODE

/* Compare Match Output Mode (OC2 Pin)	CTC
 *
 * Options:
 * 1- TIMER2_OC2_DISCONNECT
 * 2- TIMER2_TOG_OC2
 * 3- TIMER2_CLR_OC2
 * 4- TIMER2_SET_OC2
 * */
#define TIMER2_OC0_MODE TIMER2_TOG_OC2

/* Clock select
 *
 * Options:
 * 1- TIMER2_PRESCALER_NO_CLK
 * 2- TIMER2_PRESCALER_NO_PRESCALE
 * 3- TIMER2_PRESCALER_8
 * 4- TIMER2_PRESCALER_32
 * 5- TIMER2_PRESCALER_64
 * 6- TIMER2_PRESCALER_128
 * 7- TIMER2_PRESCALER_256
 * 8- TIMER2_PRESCALER_1024
 * */
#define TIMER2_CLK_SELECT TIMER2_PRESCALER_8



/* Timers state
 *
 * Options:
 * 1- TIMER_ENABLE
 * 2- TIMER_DISABLE
 * */
#define TIMER2_STATE TIMER_DISABLE

/* interrupt state
 *
 * Options:
 * 1- INT_ENABLE
 * 2- INT_DISABLE
 * */
#define TIMER2_OVF_INT_STATE	INT_DISABLE
#define TIMER2_CTC_INT_STATE	INT_DISABLE

/* TIMER2 PWM mode
 *
 * Options:
 * 1- PWM_NON_INVERTING
 * 2- PWM_INVERTING
 * Note:
 * PWM_NON_INVERTING means the Duty cycle is directly proportional to OCR
 * PWM_INVERTING means the Duty cycle is inversely proportional to OCR
 * */
#define TIMER2_PWM_MODE PWM_NON_INVERTING

/* Default PWM value
 *
 * Options:
 * 1- TIMER_DUTY_CYCLE_25
 * 2- TIMER_DUTY_CYCLE_50
 * 3- TIMER_DUTY_CYCLE_75
 * 4- TIMER_DUTY_CYCLE_100
 * */
#define TIMER2_DUTY_CYCLE TIMER_DUTY_CYCLE_75

/* TIMER2 FCPU frequency
 *
 *	Options:
 *	user specify the frequency
 * */
#define TIMER2_InputFreq 8000000UL

/* OC2 Pin Configuration */
#define OC2_PORT PORTD_ID
#define OC2_PIN	 PIN7_ID


#endif /* MCAL_TIMER_TIMER_CFG_H_ */
