/*********************************************************/
/***********		Author: TaqiEldeen	 	**************/
/***********		Layer: MCAL			 	**************/
/***********		Component: TIMER		**************/
/***********		Version: 1.02		 	**************/
/***********		Date: 13 Sep 2022	 	**************/
/*********************************************************/

#ifndef MCAL_TIMER_TIMER_INT_H_
#define MCAL_TIMER_TIMER_INT_H_

typedef enum {
	TIMER0_ID,
	TIMER1_ID,
	TIMER2_ID
};

typedef enum {
	ICR_FALLING_EDGE,
	ICR_RISING_EDGE
};


#define	TIMER_DUTY_CYCLE_25		25
#define	TIMER_DUTY_CYCLE_50		50
#define	TIMER_DUTY_CYCLE_75		75
#define	TIMER_DUTY_CYCLE_100	100

/**********************************************************************************************************
 * Description : Interface Function to 1-prescaler select, 2-Timer0 mode select, 3-Set OC0 Pin state
 * Outputs     : void
 * Inputs      : void
 * Notes	   : timer is initially off
 ***********************************************************************************************************/
void TIMER_vInitTimer0 ();

/**********************************************************************************************************
 * Description : Interface Function to 1-prescaler select, 2-Timer1 mode select, 3-Set OC0 Pin state
 * Outputs     : void
 * Inputs      : void
 * Notes	   : timer is initially off
 ***********************************************************************************************************/
void TIMER_vInitTimer1 ();

/**********************************************************************************************************
 * Description : Interface Function to 1-prescaler select, 2-Timer2 mode select, 3-Set OC0 Pin state
 * Outputs     : void
 * Inputs      : void
 * Notes	   : timer is initially off
 ***********************************************************************************************************/
void TIMER_vInitTimer2 ();

/**********************************************************************************************************
 * Description : Interface Function to Turn on a timer
 * Outputs     : void
 * Inputs      : Timer ID
 ***********************************************************************************************************/
void TIMER_vTurnOn			(u8 A_u8TimerId);

/**********************************************************************************************************
 * Description : Interface Function to set a delay for a specific timer
 * Outputs     : void
 * Inputs      : Timer ID
 ***********************************************************************************************************/
void TIMER_vTurnOff			(u8 A_u8TimerId);

/**********************************************************************************************************
 * Description : Interface Function to set preload to start counting from this value
 * Outputs     : void
 * Inputs      : timer ID, Preload value
 ***********************************************************************************************************/
void TIMER_vSetPreload		(u8 A_u8TimerId, u16 A_u16PreloadVal);

/**********************************************************************************************************
 * Description : Interface Function to set preload to start counting from this value
 * Outputs     : Preload value
 * Inputs      : timer ID
 ***********************************************************************************************************/
u16 TIMER_vGetPreload		(u8 A_u8TimerId);

/**********************************************************************************************************
 * Description : Interface Function to set OCR0 register
 * Outputs     : void
 * Inputs      : OCR value
 ***********************************************************************************************************/
void TIMER_vSetOcr0Val (u8 A_u8OcrVal);

/**********************************************************************************************************
 * Description : Interface Function to set OCR1A register
 * Outputs     : void
 * Inputs      : OCR value
 ***********************************************************************************************************/
void TIMER_vSetOcr1aVal (u16 A_u16OcrVal);

/**********************************************************************************************************
 * Description : Interface Function to set OCR1B register
 * Outputs     : void
 * Inputs      : OCR value
 ***********************************************************************************************************/
void TIMER_vSetOcr1bVal (u16 A_u16OcrVal);

/**********************************************************************************************************
 * Description : Interface Function to set OCR2 register
 * Outputs     : void
 * Inputs      : OCR value
 ***********************************************************************************************************/
void TIMER_vSetOcr2Val (u8 A_u8OcrVal);

/**********************************************************************************************************
 * Description : Interface Function to set OCR0 register
 * Outputs     : OCR0
 * Inputs      : void
 ***********************************************************************************************************/
u8 TIMER_vGetOcr0Val ();

/**********************************************************************************************************
 * Description : Interface Function to GET OCR1A register
 * Outputs     : OCR1A
 * Inputs      : void
 ***********************************************************************************************************/
u16 TIMER_vGetOcr1aVal ();

/**********************************************************************************************************
 * Description : Interface Function to GET OCR1B register
 * Outputs     : OCR1B
 * Inputs      : void
 ***********************************************************************************************************/
u16 TIMER_vGetOcr1bVal ();

/**********************************************************************************************************
 * Description : Interface Function to GET OCR2 register
 * Outputs     : OCR2
 * Inputs      : void
 ***********************************************************************************************************/
u8 TIMER_vGetOcr2Val ();

/**********************************************************************************************************
 * Description : Interface Function to set the call back function that will be executed during overflow
 * Outputs     : void
 * Inputs      : Timer ID, pointer to function
 ***********************************************************************************************************/
void TIMER_vCallBack_OVF	(ptr_func_t ptr, u8 A_u8TimerId);

/**********************************************************************************************************
 * Description : Interface Function to set the call back function that will be executed during OCF0
 * Outputs     : void
 * Inputs      : pointer to function
 ***********************************************************************************************************/
void TIMER_vCallBack_OCF0 (ptr_func_t ptr);

/**********************************************************************************************************
 * Description : Interface Function to set the call back function that will be executed during OCF1A
 * Outputs     : void
 * Inputs      : pointer to function
 ***********************************************************************************************************/
void TIMER_vCallBack_OCF1A (ptr_func_t ptr);

/**********************************************************************************************************
 * Description : Interface Function to set the call back function that will be executed during OCF1B
 * Outputs     : void
 * Inputs      : pointer to function
 ***********************************************************************************************************/
void TIMER_vCallBack_OCF1B (ptr_func_t ptr);

/**********************************************************************************************************
 * Description : Interface Function to set the call back function that will be executed during OCF2
 * Outputs     : void
 * Inputs      : pointer to function
 ***********************************************************************************************************/
void TIMER_vCallBack_OCF2 (ptr_func_t ptr);

/**********************************************************************************************************
 * Description : Interface Function to set the call back function that will be executed during ICR event
 * Outputs     : void
 * Inputs      : pointer to function
 ***********************************************************************************************************/
void TIMER_vCallBack_ICF1 (ptr_func_t ptr);

/**********************************************************************************************************
 * Description : Interface Function to set a delay for a specific timer
 * Outputs     : void
 * Inputs      : Timer ID, required delay in milliseconds, the function to be executed
 * NOTES	   : still need some work! (To work for other timers)
 ***********************************************************************************************************/
void  TIMER_vDelayMilli (u16 A_u8DelayMs, u8 A_u8TimerId, ptr_func_t ptr);

/**********************************************************************************************************
 * Description : interface Function to setup the OC0 pin duty cycle if in PWM mode
 * Outputs     : void
 * Inputs      : void
 ***********************************************************************************************************/

void TIMER_vSetDutyCycleOC0 (u8 A_u8DutyCycle);

/**********************************************************************************************************
 * Description : interface Function to setup the OC1a pin duty cycle if in PWM mode
 * Outputs     : void
 * Inputs      : void
 ***********************************************************************************************************/

void TIMER_vSetDutyCycleOC1A (u8 A_u8DutyCycle);

/**********************************************************************************************************
 * Description : interface Function to setup the OC1b pin duty cycle if in PWM mode
 * Outputs     : void
 * Inputs      : void
 ***********************************************************************************************************/
void TIMER_vSetDutyCycleOC1B (u8 A_u8DutyCycle);

/**********************************************************************************************************
 * Description : interface Function to setup the OC2 pin duty cycle if in PWM mode
 * Outputs     : void
 * Inputs      : void
 ***********************************************************************************************************/
void TIMER_vSetDutyCycleOC2 (u8 A_u8DutyCycle);

/**********************************************************************************************************
 * Description : Interface Function to set ICR1 register
 * Outputs     : void
 * Inputs      : ICR value
 ***********************************************************************************************************/
void TIMER_vSetIcr1Val (u16 A_u16IcrVal);

/**********************************************************************************************************
 * Description : Interface Function to set TIMER1 in ICU mode
 * Outputs     : void
 * Inputs      : void
 ***********************************************************************************************************/
void TIMER_vInitICU ();

/**********************************************************************************************************
 * Description : Interface Function to turn off interrupt of iCR
 * Outputs     : void
 * Inputs      : void
 ***********************************************************************************************************/
void TIMER_vDisableICU ();

/**********************************************************************************************************
 * Description : Interface Function to set the Triggering edge for the ICU
 * Outputs     : void
 * Inputs      : Trigger mode
 ***********************************************************************************************************/
void TIMER_vSetTriggering (u8 A_u8Trigger);

/**********************************************************************************************************
 * Description : Interface Function to set ICR1 register
 * Outputs     : ICR
 * Inputs      : void
 ***********************************************************************************************************/
u16 TIMER_vGetIcr1Val ();

#endif /* MCAL_TIMER_TIMER_INT_H_ */
