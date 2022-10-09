/*********************************************************/
/***********		Author: TaqiEldeen	 	**************/
/***********		Layer: MCAL			 	**************/
/***********		Component: TIMER		**************/
/***********		Version: 1.02		 	**************/
/***********		Date: 13 Sep 2022	 	**************/
/*********************************************************/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../DIO/DIO_int.h"
#include <math.h>

#include "../TIMER/TIMER_pri.h"
#include "../TIMER/TIMER_cfg.h"
#include "../TIMER/TIMER_int.h"
#include "../TIMER/TIMER_reg.h"

/**********************************************************************************************************
 * Description : Interface Function to 1-prescaler select, 2-Timer0 mode select, 3-Set OC0 Pin state
 * Outputs     : void
 * Inputs      : void
 * Notes	   : timer is initially off
 ***********************************************************************************************************/
void TIMER_vInitTimer0 (){
#if TIMER0_STATE == TIMER_ENABLE
	/*Step 1: Choose timer mode*/
	#if TIMER0_WGM_MODE == TIMER0_WGM_NORMAL_MODE
		TCCR0 &= TIMER0_WGM_MASK;
		TCCR0 |= TIMER0_WGM_MODE;

		/*Set the interrupt*/
		#if TIMER0_OVF_INT_STATE == INT_ENABLE
			SET_BIT(TIMSK, TOIE0);
		#endif

		/*Setup the OC0 Pin*/
		TCCR0 &= TIMER0_COM_MASK;
		TCCR0 |= TIMER0_OC0_MODE;

	#elif TIMER0_WGM_MODE == TIMER0_WGM_CTC_MODE
		TIMER_vTimer0_SetupCTC();
	#elif TIMER0_WGM_MODE == TIMER0_WGM_FAST_PWM_MODE
		TIMER_vTimer0_SetupFastPWM();
	#elif TIMER0_WGM_MODE == TIMER0_WGM_PWM_PHASE_CORRECT_MODE
		TIMER_vTimer0_SetupPhaseCorrectPWM();
	#endif

	/*Disable force output compare by default*/
	CLR_BIT(TCCR0, FOC0);

#else

#endif
}

/**********************************************************************************************************
 * Description : Interface Function to 1-prescaler select, 2-Timer1 mode select, 3-Set OC0 Pin state
 * Outputs     : void
 * Inputs      : void
 * Notes	   : timer is initially off
 ***********************************************************************************************************/
void TIMER_vInitTimer1 (){
#if TIMER1_STATE == TIMER_ENABLE

	/*Setup the mode*/
	TIMER_vTimer1_setupWGM();

	CLR_BIT(TCCR1A, FOC1B);
	CLR_BIT(TCCR1A, FOC1A);

#else

#endif
}

/**********************************************************************************************************
 * Description : Interface Function to 1-prescaler select, 2-Timer2 mode select, 3-Set OC0 Pin state
 * Outputs     : void
 * Inputs      : void
 * Notes	   : timer is initially off
 ***********************************************************************************************************/
void TIMER_vInitTimer2 (){
#if TIMER2_STATE == TIMER_ENABLE
	/*Step 1: Choose timer mode*/
	#if TIMER2_WGM_MODE == TIMER2_WGM_NORMAL_MODE
		TCCR2 &= TIMER2_WGM_MASK;
		TCCR2 |= TIMER2_WGM_MODE;

		/*Set the interrupt*/
		#if TIMER2_OVF_INT_STATE == INT_ENABLE
			SET_BIT(TIMSK, TOIE2);
		#endif

	#elif TIMER2_WGM_MODE == TIMER2_WGM_CTC_MODE
		TIMER_vTimer2_SetupCTC();
	#elif TIMER2_WGM_MODE == TIMER2_WGM_FAST_PWM_MODE
		TIMER_vTimer2_SetupFastPWM();
	#elif TIMER2_WGM_MODE == TIMER2_WGM_PWM_PHASE_CORRECT_MODE
		TIMER_vTimer2_SetupPhaseCorrectPWM();
	#endif

	/*Disable force output compare by default*/
	CLR_BIT(TCCR2, FOC2);
#else

#endif
}

/**********************************************************************************************************
 * Description : Interface Function to Turn on timer
 * Outputs     : void
 * Inputs      : Timer ID
 ***********************************************************************************************************/
void TIMER_vTurnOn (u8 A_u8TimerId){
	switch(A_u8TimerId){
		case TIMER0_ID:
			TCCR0 &= TIMER0_CLK_SELECT_MASK;
			TCCR0 |= TIMER0_CLK_SELECT;
			break;
		case TIMER1_ID:
			TCCR1B &= TIMER1_CLK_SELECT_MASK;
			TCCR1B |= TIMER1_CLK_SELECT;
			break;
		case TIMER2_ID:
			TCCR2 &= TIMER2_CLK_SELECT_MASK;
			TCCR2 |= TIMER2_CLK_SELECT;
			break;
	}
	return;
}

/**********************************************************************************************************
 * Description : Interface Function to Turn off timer
 * Outputs     : void
 * Inputs      : Timer ID
 ***********************************************************************************************************/
void TIMER_vTurnOff	(u8 A_u8TimerId){
	switch(A_u8TimerId){
		case TIMER0_ID:
			TCCR0 &= TIMER0_CLK_SELECT_MASK;
			TCCR0 |= TIMER0_PRESCALER_NO_CLK;
			break;
		case TIMER1_ID:
			TCCR1B &= TIMER1_CLK_SELECT_MASK;
			TCCR1B |= TIMER1_PRESCALER_NO_CLK;
			break;
		case TIMER2_ID:
			TCCR2 &= TIMER2_CLK_SELECT_MASK;
			TCCR2 |= TIMER2_PRESCALER_NO_CLK;
			break;
	}

	return;
}

/**********************************************************************************************************
 * Description : Interface Function to set ICR1 register
 * Outputs     : ICR
 * Inputs      : void
 ***********************************************************************************************************/
u16 TIMER_vGetIcr1Val (){
	return ICR1;
}

/**********************************************************************************************************
 * Description : Interface Function to set TIMER1 in ICU mode: enabling interrupt OVF & InputCapture
 * 				 Normal mode and setting the ICP input, rising edge triggering, PreScale 8
 * Outputs     : void
 * Inputs      : void
 ***********************************************************************************************************/
void TIMER_vInitICU (){
	/*WGM of normal mode*/
	TCCR1A &= ~( (1<<WGM10) | (1<<WGM11) );
	TCCR1B &= ~( (1<<WGM12) | (1<<WGM13) );

	/*Enable Capture interrupt and overflow*/
	TIMSK |= (1<< TICIE1) | (1<<TOIE1);

	/*IC pin as input*/
	DIO_vSetPinDir(PORTD_ID, PIN6_ID, DIR_INPUT);

	/*Edge select of the ICU: Rising edge*/
	SET_BIT(TCCR1B, ICES1);

	/*PreScaling of 8*/
	TCCR1B |= (1<<CS11) ;
	TCCR1B &= ~( (1<<CS10) | (1<<CS12) );
}


/**********************************************************************************************************
 * Description : Interface Function to turn off interrupt of iCR
 * Outputs     : void
 * Inputs      : void
 ***********************************************************************************************************/
void TIMER_vDisableICU (){
	/*Disable Capture interrupt*/
	CLR_BIT(TIMSK, TICIE1);
}


/**********************************************************************************************************
 * Description : Interface Function to set preload to start counting from this value
 * Outputs     : void
 * Inputs      : Preload value
 ***********************************************************************************************************/
void TIMER_vSetPreload (u8 A_u8TimerId, u16 A_u16PreloadVal){
	switch(A_u8TimerId){
		case TIMER0_ID:
			TCNT0 = A_u16PreloadVal;
			G_u8Timer0_Preload_Val = (u8)A_u16PreloadVal;
			break;
		case TIMER1_ID:
			TCNT1 = A_u16PreloadVal;
			G_u16Timer1_Preload_Val = A_u16PreloadVal;
			break;
		case TIMER2_ID:
			TCNT2 = A_u16PreloadVal;
			G_u8Timer2_Preload_Val = (u8)A_u16PreloadVal;
			break;
	}
	return;
}


/**********************************************************************************************************
 * Description : Interface Function to set preload to start counting from this value
 * Outputs     : Preload value
 * Inputs      : timer ID
 ***********************************************************************************************************/
u16 TIMER_vGetPreload (u8 A_u8TimerId){
	switch(A_u8TimerId){
		case TIMER0_ID:
			return TCNT0;
		case TIMER1_ID:
			return TCNT1;
		case TIMER2_ID:
			return TCNT2;
	}
}


/**********************************************************************************************************
 * Description : Interface Function to set OCR0 register
 * Outputs     : void
 * Inputs      : OCR value
 ***********************************************************************************************************/
void TIMER_vSetOcr0Val (u8 A_u8OcrVal){
	OCR0 = A_u8OcrVal;
	return;
}

/**********************************************************************************************************
 * Description : Interface Function to set OCR1A register
 * Outputs     : void
 * Inputs      : OCR value
 ***********************************************************************************************************/
void TIMER_vSetOcr1aVal (u16 A_u16OcrVal){
	OCR1A = A_u16OcrVal;
	return;
}

/**********************************************************************************************************
 * Description : Interface Function to set OCR1B register
 * Outputs     : void
 * Inputs      : OCR value
 ***********************************************************************************************************/
void TIMER_vSetOcr1bVal (u16 A_u16OcrVal){
	OCR1B = A_u16OcrVal;
	return;
}

/**********************************************************************************************************
 * Description : Interface Function to set OCR2 register
 * Outputs     : void
 * Inputs      : OCR value
 ***********************************************************************************************************/
void TIMER_vSetOcr2Val (u8 A_u8OcrVal){
	OCR2 = A_u8OcrVal;
	return;
}

/**********************************************************************************************************
 * Description : Interface Function to set ICR1 register
 * Outputs     : void
 * Inputs      : ICR value
 ***********************************************************************************************************/
void TIMER_vSetIcr1Val (u16 A_u16IcrVal){
	ICR1 = A_u16IcrVal;
	return;
}


/**********************************************************************************************************
 * Description : Interface Function to set the Triggering edge for the ICU
 * Outputs     : void
 * Inputs      : Trigger mode
 ***********************************************************************************************************/
void TIMER_vSetTriggering (u8 A_u8Trigger){
	switch(A_u8Trigger) {
		case ICR_FALLING_EDGE: TCCR1B &= ~(1<<ICES1); break;
		case ICR_RISING_EDGE: TCCR1B |= (1<<ICES1); break;
	}
	return;
}


/**********************************************************************************************************
 * Description : Interface Function to set the call back function that will be executed during overflow
 * Outputs     : void
 * Inputs      : Timer ID, pointer to function
 ***********************************************************************************************************/
void TIMER_vCallBack_OVF (ptr_func_t ptr, u8 A_u8TimerId){
	switch(A_u8TimerId){
		case TIMER0_ID: G_PTRF_TIM0_OVF = ptr; break;
		case TIMER1_ID: G_PTRF_TIM1_OVF = ptr; break;
		case TIMER2_ID: G_PTRF_TIM2_OVF = ptr; break;
	}
	return;
}

/**********************************************************************************************************
 * Description : Interface Function to set the call back function that will be executed during OCF0
 * Outputs     : void
 * Inputs      : pointer to function
 ***********************************************************************************************************/
void TIMER_vCallBack_OCF0 (ptr_func_t ptr){
	G_PTRF_TIM0_CTC = ptr;
	return;
}


/**********************************************************************************************************
 * Description : Interface Function to set the call back function that will be executed during OCF1A
 * Outputs     : void
 * Inputs      : pointer to function
 ***********************************************************************************************************/
void TIMER_vCallBack_OCF1A (ptr_func_t ptr){
	G_PTRF_TIM1_OC1AF = ptr;
	return;
}

/**********************************************************************************************************
 * Description : Interface Function to set the call back function that will be executed during OCF1B
 * Outputs     : void
 * Inputs      : pointer to function
 ***********************************************************************************************************/
void TIMER_vCallBack_OCF1B (ptr_func_t ptr){
	G_PTRF_TIM1_OC1BF = ptr;
	return;
}

/**********************************************************************************************************
 * Description : Interface Function to set the call back function that will be executed during OCF2
 * Outputs     : void
 * Inputs      : pointer to function
 ***********************************************************************************************************/
void TIMER_vCallBack_OCF2 (ptr_func_t ptr){
	G_PTRF_TIM2_CTC = ptr;
	return;
}


/**********************************************************************************************************
 * Description : Interface Function to set the call back function that will be executed during OCF2
 * Outputs     : void
 * Inputs      : pointer to function
 ***********************************************************************************************************/
void TIMER_vCallBack_ICF1 (ptr_func_t ptr){
	G_PTRF_TIM1_ICF1 = ptr;
	return;
}





/**********************************************************************************************************
 * Description : Interface Function to set a delay for a specific timer
 * Outputs     : void
 * Inputs      : Timer ID, required delay in milliseconds, the function to be executed
 * NOTES	   : still need some work!
 ***********************************************************************************************************/
void  TIMER_vDelayMilli (u16 A_u16DelayMs, u8 A_u8TimerId, ptr_func_t ptr){
	u16 L_u16PrescaleVal = 1;
	f32 L_f32TimeOverFlow;
	f32 L_f32TickTime;
	u16 L_u16OverFlowCounts = 0;
	u16 L_u8PreloadVal = 0;

	switch(TIMER0_CLK_SELECT){
		case TIMER0_PRESCALER_8:    L_u16PrescaleVal = 8; 	break;
		case TIMER0_PRESCALER_64:   L_u16PrescaleVal = 16; 	break;
		case TIMER0_PRESCALER_256:  L_u16PrescaleVal = 256; break;
		case TIMER0_PRESCALER_1024: L_u16PrescaleVal = 1024;break;
	}

	/*Tick time Calculation*/
	L_f32TickTime = (f32)L_u16PrescaleVal / TIMER0_InputFreq;

	/*Time required for complete 1 over flow*/
	L_f32TimeOverFlow = (TIMER0_MAX_COUNT + 1) * (L_f32TickTime * ((u16)1000));

	/*Over flow needed by this delay*/
	L_u16OverFlowCounts = (u16)ceil(( ((f32)A_u16DelayMs /L_f32TimeOverFlow) ));

	/*Calculating OverFlow counts & preload value*/
	L_u8PreloadVal = (f32)L_u16OverFlowCounts - ((f32)A_u16DelayMs /L_f32TimeOverFlow);
	G_u16Timer0_Cov = L_u16OverFlowCounts;


#if  TIMER0_WGM_MODE == TIMER0_WGM_CTC_MODE
		TIMER_vSetOcr0Val((TIMER0_MAX_COUNT - L_u8PreloadVal));
		G_PTRF_TIM0_CTC = ptr;
#elif TIMER0_WGM_MODE == TIMER0_WGM_NORMAL_MODE
		G_PTRF_TIM0_OVF = ptr;
#endif

}




/**************   TIMER0 mode functions   **************/

static void TIMER_vTimer0_SetupCTC(){
	/*Setup the mode*/
	TCCR0 &= TIMER0_WGM_MASK;
	TCCR0 |= TIMER0_WGM_MODE;

	/*Setup the OC0 Pin*/
	TCCR0 &= TIMER0_COM_MASK;
	TCCR0 |= TIMER0_OC0_MODE;

	#if TIMER0_OC0_MODE == TIMER0_OC0_DISCONNECT
	#else
	/*Must set the OC0 pin output if in CTC, fast PWM or phase correct PWM modes*/
	DIO_vSetPinDir(OC0_PORT, OC0_PIN, DIR_OUTPUT);
	#endif

	#if TIMER0_CTC_INT_STATE == INT_ENABLE
		SET_BIT(TIMSK, OCIE0);
	#endif

	return;
}

static void TIMER_vTimer0_SetupFastPWM	(){
	TCCR0 &= TIMER0_WGM_MASK;
	TCCR0 |= TIMER0_WGM_MODE;

	/*Step 2: Setup the OC0 Pin*/
	#if TIMER0_PWM_MODE == PWM_INVERTING
		SET_BIT(TCCR0, COM00);
		SET_BIT(TCCR0, COM01);
	#elif TIMER0_PWM_MODE == PWM_NON_INVERTING
		CLR_BIT(TCCR0, COM00);
		SET_BIT(TCCR0, COM01);
	#else

	#endif

	/*Calculate the dutyCycle*/
	TIMER_vSetDutyCycleOC0(TIMER0_DUTY_CYCLE);

	/*Must set the OC0 pin output if in CTC, fast PWM or phase correct PWM modes*/
	DIO_vSetPinDir(OC0_PORT, OC0_PIN, DIR_OUTPUT);

	return;
}

static void TIMER_vTimer0_SetupPhaseCorrectPWM	(){
	TCCR0 &= TIMER0_WGM_MASK;
	TCCR0 |= TIMER0_WGM_MODE;

	/*Step 2: Setup the OC0 Pin*/
	#if TIMER0_PWM_MODE == PWM_INVERTING
		SET_BIT(TCCR0, COM00);
		SET_BIT(TCCR0, COM01);
	#elif TIMER0_PWM_MODE == PWM_NON_INVERTING
		CLR_BIT(TCCR0, COM00);
		SET_BIT(TCCR0, COM01);
	#else

	#endif

	/*Must set the OC0 pin output if in CTC, fast PWM or phase correct PWM modes*/
	DIO_vSetPinDir(OC0_PORT, OC0_PIN, DIR_OUTPUT);

	return;
}




/**************   TIMER2 mode functions   **************/

static void TIMER_vTimer2_SetupCTC(){
	/*Setup the mode*/
	TCCR2 &= TIMER2_WGM_MASK;
	TCCR2 |= TIMER2_WGM_MODE;

	/*Setup the OC0 Pin*/
	TCCR2 &= TIMER2_COM_MASK;
	TCCR2 |= TIMER2_OC2_MODE;

	#if TIMER2_OC2_MODE == TIMER2_OC2_DISCONNECT

	#else
		/*Must set the OC2 pin output if in CTC, fast PWM or phase correct PWM modes*/
		DIO_vSetPinDir(OC2_PORT, OC2_PIN, DIR_OUTPUT);
	#endif

	#if TIMER2_CTC_INT_STATE == INT_ENABLE
		SET_BIT(TIMSK, OCIE2);
	#endif

	return;
}

static void TIMER_vTimer2_SetupFastPWM	(){
	TCCR2 &= TIMER2_WGM_MASK;
	TCCR2 |= TIMER2_WGM_MODE;

	/*Step 2: Setup the OC2 Pin*/
	#if TIMER2_PWM_MODE == PWM_INVERTING
		SET_BIT(TCCR2, COM20);
		SET_BIT(TCCR2, COM21);
	#elif TIMER2_PWM_MODE == PWM_NON_INVERTING
		CLR_BIT(TCCR2, COM20);
		SET_BIT(TCCR2, COM21);
	#else

	#endif

	/*Calculate the dutyCycle*/
	TIMER_vSetDutyCycleOC2( TIMER2_DUTY_CYCLE);
	/*Must set the OC2 pin output if in CTC, fast PWM or phase correct PWM modes*/
	DIO_vSetPinDir(OC2_PORT, OC2_PIN, DIR_OUTPUT);

	return;
}

static void TIMER_vTimer2_SetupPhaseCorrectPWM	(){
	TCCR2 &= TIMER2_WGM_MASK;
	TCCR2 |= TIMER2_WGM_MODE;

	/*Step 2: Setup the OC2 Pin*/
	#if TIMER2_PWM_MODE == PWM_INVERTING
		SET_BIT(TCCR2, COM00);
		SET_BIT(TCCR2, COM01);
	#elif TIMER2_PWM_MODE == PWM_NON_INVERTING
		CLR_BIT(TCCR2, COM20);
		SET_BIT(TCCR2, COM21);
	#else

	#endif

	/*Calculate the dutyCycle*/
	TIMER_vSetDutyCycleOC2( TIMER2_DUTY_CYCLE);
	/*Must set the OC2 pin output if in CTC, fast PWM or phase correct PWM modes*/
	DIO_vSetPinDir(OC2_PORT, OC2_PIN, DIR_OUTPUT);

	return;
}


/**************   DutyCycle functions   **************/



/**********************************************************************************************************
 * Description : interface Function to setup the OC0 pin duty cycle if in PWM mode
 * Outputs     : void
 * Inputs      : void
 * Notes	   : this function is used for calculating DutyCycle only if the TOP is MAX counts
 ***********************************************************************************************************/

void TIMER_vSetDutyCycleOC0 (u8 A_u8DutyCycle){
	#if TIMER0_PWM_MODE == PWM_NON_INVERTING
		TIMER_vSetOcr0Val( ( (TIMER0_MAX_COUNT + 1) * A_u8DutyCycle ) / 100);
	#elif TIMER0_PWM_MODE == PWM_INVERTING
		TIMER_vSetOcr0Val( ( -( (A_u8DutyCycle/100) - 1) ) * (TIMER0_MAX_COUNT + 1);
	#endif
	return;
}

/**********************************************************************************************************
 * Description : interface Function to setup the OC1a pin duty cycle if in PWM mode
 * Outputs     : void
 * Inputs      : void
 * Notes	   : this function is used for calculating DutyCycle only if the TOP is MAX counts
 ***********************************************************************************************************/

void TIMER_vSetDutyCycleOC1A (u8 A_u8DutyCycle){
	#if TIMER1_OC1A_PWM_MODE == PWM_NON_INVERTING
		TIMER_vSetOcr1aVal( ( (TIMER1_MAX_COUNT + 1) * A_u8DutyCycle ) /100);
	#elif TIMER1_PWM_MODE == PWM_INVERTING
		TIMER_vSetOcr1aVal( ( -( (A_u8DutyCycle/100) - 1) ) * (TIMER1_MAX_COUNT + 1);
	#endif

	return;
}

/**********************************************************************************************************
 * Description : interface Function to setup the OC1b pin duty cycle if in PWM mode
 * Outputs     : void
 * Inputs      : void
 * Notes	   : this function is used for calculating DutyCycle only if the TOP is MAX counts
 ***********************************************************************************************************/
void TIMER_vSetDutyCycleOC1B (u8 A_u8DutyCycle){

	#if TIMER1_OC1B_PWM_MODE == PWM_NON_INVERTING
		TIMER_vSetOcr1bVal( ( (TIMER1_MAX_COUNT + 1) * A_u8DutyCycle ) /100);
	#elif TIMER1_PWM_MODE == PWM_INVERTING
		TIMER_vSetOcr1bVal( ( -( (A_u8DutyCycle/100) - 1) ) * (TIMER1_MAX_COUNT + 1);
	#endif

	return;
}

/**********************************************************************************************************
 * Description : interface Function to setup the OC2 pin duty cycle if in PWM mode
 * Outputs     : void
 * Inputs      : void
 * Notes	   : this function is used for calculating DutyCycle only if the TOP is MAX counts
 ***********************************************************************************************************/
void TIMER_vSetDutyCycleOC2 (u8 A_u8DutyCycle){
	#if TIMER2_PWM_MODE == PWM_NON_INVERTING
		TIMER_vSetOcr2Val( ( (TIMER2_MAX_COUNT + 1) * A_u8DutyCycle ) /100);
	#elif TIMER2_PWM_MODE == PWM_INVERTING
		TIMER_vSetOcr1aVal( ( -( (A_u8DutyCycle/100) - 1) ) * (TIMER2_MAX_COUNT + 1);
	#endif

	return;
}





/**********************************************************************************************************
 * Description : private Function to setup the Timer1 based on configuration
 * Outputs     : void
 * Inputs      : void
 ***********************************************************************************************************/

void TIMER_vTimer1_setupWGM() {

	#if TIMER1_WGM_MODE == TIMER1_WGM_NORMAL_MODE
		TCCR1A &= ~( (1<<WGM10) | (1<<WGM11) );
		TCCR1B &= ~( (1<<WGM12) | (1<<WGM13) );

		/*Setup the OC1x pin mode*/
		TCCR1A &= TIMER1_COM1xx_MASK;
		TCCR1A |= (TIMER1_OC1A_MODE << COM1A0);
		TCCR1A |= (TIMER1_OC1B_MODE << COM1B0);

	#if TIMER1_OVF_INT_STATE == INT_ENABLE
		TIMSK |= (1<<TOIE1);
	#endif

		/*Set the pin direction*/
		#if TIMER1_OC1A_MODE != TIMER1_OC1x_DISCONNECT
			DIO_vSetPinDir(OC1A_PORT, OC1A_PIN, DIR_OUTPUT);
		#endif

		#if TIMER1_OC1B_MODE != TIMER1_OC1x_DISCONNECT
			DIO_vSetPinDir(OC1B_PORT, OC1B_PIN, DIR_OUTPUT);
		#endif

	#elif TIMER1_WGM_MODE == TIMER1_WGM_PWM_PHASE_CORRECT_8BIT_MODE
		TCCR1A |= (1<<WGM10);
		TCCR1A &= ~(1<<WGM11);
		TCCR1B &= ~( (1<<WGM12) | (1<<WGM13) );

		/*Setup the PWM state of OC1A*/
		#if TIMER1_OC1A_PWM_MODE == PWM_NON_INVERTING
			TCCR1A |= (1<<COM1A1);
			TCCR1A &= ~(1<<COM1A0);
			DIO_vSetPinVal(OC1A_PORT, OC1A_PIN, DIR_OUTPUT);
		#elif TIMER1_OC1A_PWM_MODE == PWM_INVERTING
			TCCR1A |= (1<<WGM1A1) | (1<<WGM1A0);
			DIO_vSetPinVal(OC1A_PORT, OC1A_PIN, DIR_OUTPUT);
		#elif TIMER1_OC1A_PWM_MODE == PWM_OFF
			TCCR1A &= ~( (1<<WGM1A0) | (1<<WGM1A1) );
		#endif

		/*Setup the PWM state of OC1B*/
		#if TIMER1_OC1B_PWM_MODE == PWM_NON_INVERTING
			TCCR1A |= (1<<COM1B1);
			TCCR1A &= ~(1<<COM1B0);
			DIO_vSetPinVal(OC1B_PORT, OC1B_PIN, DIR_OUTPUT);
		#elif TIMER1_OC1A_PWM_MODE == PWM_INVERTING
			TCCR1A |= (1<<WGM1B1) | (1<<WGM1B0);
			DIO_vSetPinVal(OC1B_PORT, OC1B_PIN, DIR_OUTPUT);
		#elif TIMER1_OC1A_PWM_MODE == PWM_OFF
			TCCR1A &= ~( (1<<WGM1B0) | (1<<WGM1B1) );
		#endif

	#elif TIMER1_WGM_MODE == TIMER1_WGM_PWM_PHASE_CORRECT_9BIT_MODE
		TCCR1A |= (1<<WGM11);
		TCCR1A &= ~(1<<WGM10);
		TCCR1B &= ~( (1<<WGM12) | (1<<WGM13) );

		/*Setup the PWM state of OC1A*/
		#if TIMER1_OC1A_PWM_MODE == PWM_NON_INVERTING
			TCCR1A |= (1<<COM1A1);
			TCCR1A &= ~(1<<COM1A0);
			DIO_vSetPinVal(OC1A_PORT, OC1A_PIN, DIR_OUTPUT);
		#elif TIMER1_OC1A_PWM_MODE == PWM_INVERTING
			TCCR1A |= (1<<WGM1A1) | (1<<WGM1A0);
			DIO_vSetPinVal(OC1A_PORT, OC1A_PIN, DIR_OUTPUT);
		#elif TIMER1_OC1A_PWM_MODE == PWM_OFF
			TCCR1A &= ~( (1<<WGM1A0) | (1<<WGM1A1) );
		#endif

		/*Setup the PWM state of OC1B*/
		#if TIMER1_OC1B_PWM_MODE == PWM_NON_INVERTING
			TCCR1A |= (1<<COM1B1);
			TCCR1A &= ~(1<<COM1B0);
			DIO_vSetPinVal(OC1B_PORT, OC1B_PIN, DIR_OUTPUT);
		#elif TIMER1_OC1A_PWM_MODE == PWM_INVERTING
			TCCR1A |= (1<<WGM1B1) | (1<<WGM1B0);
			DIO_vSetPinVal(OC1B_PORT, OC1B_PIN, DIR_OUTPUT);
		#elif TIMER1_OC1A_PWM_MODE == PWM_OFF
			TCCR1A &= ~( (1<<WGM1B0) | (1<<WGM1B1) );
		#endif

	#elif TIMER1_WGM_MODE == TIMER1_WGM_PWM_PHASE_CORRECT_10BIT_MODE
		TCCR1A |= (1<<WGM11) | (1<<WGM10);
		TCCR1B &= ~( (1<<WGM12) | (1<<WGM13) );

		/*Setup the PWM state of OC1A*/
		#if TIMER1_OC1A_PWM_MODE == PWM_NON_INVERTING
			TCCR1A |= (1<<COM1A1);
			TCCR1A &= ~(1<<COM1A0);
			DIO_vSetPinVal(OC1A_PORT, OC1A_PIN, DIR_OUTPUT);
		#elif TIMER1_OC1A_PWM_MODE == PWM_INVERTING
			TCCR1A |= (1<<WGM1A1) | (1<<WGM1A0);
			DIO_vSetPinVal(OC1A_PORT, OC1A_PIN, DIR_OUTPUT);
		#elif TIMER1_OC1A_PWM_MODE == PWM_OFF
			TCCR1A &= ~( (1<<WGM1A0) | (1<<WGM1A1) );
		#endif

		/*Setup the PWM state of OC1B*/
		#if TIMER1_OC1B_PWM_MODE == PWM_NON_INVERTING
			TCCR1A |= (1<<COM1B1);
			TCCR1A &= ~(1<<COM1B0);
			DIO_vSetPinVal(OC1B_PORT, OC1B_PIN, DIR_OUTPUT);
		#elif TIMER1_OC1A_PWM_MODE == PWM_INVERTING
			TCCR1A |= (1<<WGM1B1) | (1<<WGM1B0);
			DIO_vSetPinVal(OC1B_PORT, OC1B_PIN, DIR_OUTPUT);
		#elif TIMER1_OC1A_PWM_MODE == PWM_OFF
			TCCR1A &= ~( (1<<WGM1B0) | (1<<WGM1B1) );
		#endif

	#elif TIMER1_WGM_MDOE == TIMER1_WGM_CTC_MODE
		TCCR1A &= ~( (1<<WGM10) | (1<<WGM11) );
		TCCR1B |= (1<<WGM12);
		TCCR1B &= ~(1<<WGM13);

		/*Setup the OC1x pin mode*/
		TCCR1A &= TIMER1_COM1xx_MASK;
		TCCR1A |= (TIMER1_OC1A_MODE << COM1A0);
		TCCR1A |= (TIMER1_OC1B_MOE << COM1B0);

		/*Set the pin direction*/
		#if TIMER1_OC1A_MODE != TIMER1_OC1x_DISCONNECT
			DIO_vSetPinDir(OC1A_PORT, OC1A_PIN, DIR_OUTPUT);
		#endif

		#if TIMER1_OC1B_MODE != TIMER1_OC1x_DISCONNECT
			DIO_vSetPinDir(OC1B_PORT, OC1B_PIN, DIR_OUTPUT);
		#endif

	#elif TIMER1_WGM_MODE == TIMER1_WGM_FAST_PWM_8BIT_MODE
		TCCR1A |= (1<<WGM10);
		TCCR1A &= ~(1<<WGM11);
		TCCR1B |= (1<<WGM12);
		TCCR1B &= ~(1<<WGM13);

		/*Setup the PWM state of OC1A*/
		#if TIMER1_OC1A_PWM_MODE == PWM_NON_INVERTING
			TCCR1A |= (1<<COM1A1);
			TCCR1A &= ~(1<<COM1A0);
			DIO_vSetPinVal(OC1A_PORT, OC1A_PIN, DIR_OUTPUT);
		#elif TIMER1_OC1A_PWM_MODE == PWM_INVERTING
			TCCR1A |= (1<<WGM1A1) | (1<<WGM1A0);
			DIO_vSetPinVal(OC1A_PORT, OC1A_PIN, DIR_OUTPUT);
		#elif TIMER1_OC1A_PWM_MODE == PWM_OFF
			TCCR1A &= ~( (1<<WGM1A0) | (1<<WGM1A1) );
		#endif

		/*Setup the PWM state of OC1B*/
		#if TIMER1_OC1B_PWM_MODE == PWM_NON_INVERTING
			TCCR1A |= (1<<COM1B1);
			TCCR1A &= ~(1<<COM1B0);
			DIO_vSetPinVal(OC1B_PORT, OC1B_PIN, DIR_OUTPUT);
		#elif TIMER1_OC1A_PWM_MODE == PWM_INVERTING
			TCCR1A |= (1<<WGM1B1) | (1<<WGM1B0);
			DIO_vSetPinVal(OC1B_PORT, OC1B_PIN, DIR_OUTPUT);
		#elif TIMER1_OC1A_PWM_MODE == PWM_OFF
			TCCR1A &= ~( (1<<WGM1B0) | (1<<WGM1B1) );
		#endif

	#elif TIMER1_WGM_MODE == TIMER1_WGM_FAST_PWM_9BIT_MODE
		TCCR1A &= ~(1<<WGM10);
		TCCR1A |= (1<<WGM11);
		TCCR1B |= (1<<WGM12);
		TCCR1B &= ~(1<<WGM13);

		/*Setup the PWM state of OC1A*/
		#if TIMER1_OC1A_PWM_MODE == PWM_NON_INVERTING
			TCCR1A |= (1<<COM1A1);
			TCCR1A &= ~(1<<COM1A0);
			DIO_vSetPinVal(OC1A_PORT, OC1A_PIN, DIR_OUTPUT);
		#elif TIMER1_OC1A_PWM_MODE == PWM_INVERTING
			TCCR1A |= (1<<WGM1A1) | (1<<WGM1A0);
			DIO_vSetPinVal(OC1A_PORT, OC1A_PIN, DIR_OUTPUT);
		#elif TIMER1_OC1A_PWM_MODE == PWM_OFF
			TCCR1A &= ~( (1<<WGM1A0) | (1<<WGM1A1) );
		#endif

		/*Setup the PWM state of OC1B*/
		#if TIMER1_OC1B_PWM_MODE == PWM_NON_INVERTING
			TCCR1A |= (1<<COM1B1);
			TCCR1A &= ~(1<<COM1B0);
			DIO_vSetPinVal(OC1B_PORT, OC1B_PIN, DIR_OUTPUT);
		#elif TIMER1_OC1A_PWM_MODE == PWM_INVERTING
			TCCR1A |= (1<<WGM1B1) | (1<<WGM1B0);
			DIO_vSetPinVal(OC1B_PORT, OC1B_PIN, DIR_OUTPUT);
		#elif TIMER1_OC1A_PWM_MODE == PWM_OFF
			TCCR1A &= ~( (1<<WGM1B0) | (1<<WGM1B1) );
		#endif

	#elif TIMER1_WGM_MODE == TIMER1_WGM_FAST_PWM_10BIT_MODE
		TCCR1A |= (1<<WGM10) | (1<<WGM11);
		TCCR1B |= (1<<WGM12);
		TCCR1B &= ~(1<<WGM13);

		/*Setup the PWM state of OC1A*/
		#if TIMER1_OC1A_PWM_MODE == PWM_NON_INVERTING
			TCCR1A |= (1<<COM1A1);
			TCCR1A &= ~(1<<COM1A0);
			DIO_vSetPinVal(OC1A_PORT, OC1A_PIN, DIR_OUTPUT);
		#elif TIMER1_OC1A_PWM_MODE == PWM_INVERTING
			TCCR1A |= (1<<WGM1A1) | (1<<WGM1A0);
			DIO_vSetPinVal(OC1A_PORT, OC1A_PIN, DIR_OUTPUT);
		#elif TIMER1_OC1A_PWM_MODE == PWM_OFF
			TCCR1A &= ~( (1<<WGM1A0) | (1<<WGM1A1) );
		#endif

		/*Setup the PWM state of OC1B*/
		#if TIMER1_OC1B_PWM_MODE == PWM_NON_INVERTING
			TCCR1A |= (1<<COM1B1);
			TCCR1A &= ~(1<<COM1B0);
			DIO_vSetPinVal(OC1B_PORT, OC1B_PIN, DIR_OUTPUT);
		#elif TIMER1_OC1A_PWM_MODE == PWM_INVERTING
			TCCR1A |= (1<<WGM1B1) | (1<<WGM1B0);
			DIO_vSetPinVal(OC1B_PORT, OC1B_PIN, DIR_OUTPUT);
		#elif TIMER1_OC1A_PWM_MODE == PWM_OFF
			TCCR1A &= ~( (1<<WGM1B0) | (1<<WGM1B1) );
		#endif
	#elif TIMER1_WGM_MODE == TIMER1_WGM_PWM_PHASE_CORRECT_TOP_ICR1
		TCCR1A &= ~( (1<<WGM10) | (1<<WGM11) );
		TCCR1B &= ~(1<<WGM12);
		TCCR1B |= (1<<WGM13);

		/*Setup the PWM state of OC1A*/
		#if TIMER1_OC1A_PWM_MODE == PWM_NON_INVERTING
			TCCR1A |= (1<<COM1A1);
			TCCR1A &= ~(1<<COM1A0);
			DIO_vSetPinVal(OC1A_PORT, OC1A_PIN, DIR_OUTPUT);
		#elif TIMER1_OC1A_PWM_MODE == PWM_INVERTING
			TCCR1A |= (1<<WGM1A1) | (1<<WGM1A0);
			DIO_vSetPinVal(OC1A_PORT, OC1A_PIN, DIR_OUTPUT);
		#elif TIMER1_OC1A_PWM_MODE == PWM_OFF
			TCCR1A &= ~( (1<<WGM1A0) | (1<<WGM1A1) );
		#endif

		/*Setup the PWM state of OC1B*/
		#if TIMER1_OC1B_PWM_MODE == PWM_NON_INVERTING
			TCCR1A |= (1<<COM1B1);
			TCCR1A &= ~(1<<COM1B0);
			DIO_vSetPinVal(OC1B_PORT, OC1B_PIN, DIR_OUTPUT);
		#elif TIMER1_OC1A_PWM_MODE == PWM_INVERTING
			TCCR1A |= (1<<WGM1B1) | (1<<WGM1B0);
			DIO_vSetPinVal(OC1B_PORT, OC1B_PIN, DIR_OUTPUT);
		#elif TIMER1_OC1A_PWM_MODE == PWM_OFF
			TCCR1A &= ~( (1<<WGM1B0) | (1<<WGM1B1) );
		#endif

	#elif TIMER1_WGM_MODE == TIMER1_WGM_PWM_PHASE_CORRECT_TOP_OCR1A
		TCCR1A |= (1<<WGM10);
		TCCR1A &= ~(1<<WGM11);
		TCCR1B &= ~(1<<WGM12);
		TCCR1B |= (1<<WGM13);

		/*Setup the PWM state of OC1A*/
		#if TIMER1_OC1A_PWM_MODE == PWM_NON_INVERTING
			TCCR1A |= (1<<COM1A1);
			TCCR1A &= ~(1<<COM1A0);
			DIO_vSetPinVal(OC1A_PORT, OC1A_PIN, DIR_OUTPUT);
		#elif TIMER1_OC1A_PWM_MODE == PWM_INVERTING
			TCCR1A |= (1<<WGM1A1) | (1<<WGM1A0);
			DIO_vSetPinVal(OC1A_PORT, OC1A_PIN, DIR_OUTPUT);
		#elif TIMER1_OC1A_PWM_MODE == PWM_OFF
			TCCR1A &= ~( (1<<WGM1A0) | (1<<WGM1A1) );
		#endif

		/*Setup the PWM state of OC1B*/
		#if TIMER1_OC1B_PWM_MODE == PWM_NON_INVERTING
			TCCR1A |= (1<<COM1B1);
			TCCR1A &= ~(1<<COM1B0);
			DIO_vSetPinVal(OC1B_PORT, OC1B_PIN, DIR_OUTPUT);
		#elif TIMER1_OC1A_PWM_MODE == PWM_INVERTING
			TCCR1A |= (1<<WGM1B1) | (1<<WGM1B0);
			DIO_vSetPinVal(OC1B_PORT, OC1B_PIN, DIR_OUTPUT);
		#elif TIMER1_OC1A_PWM_MODE == PWM_OFF
			TCCR1A &= ~( (1<<WGM1B0) | (1<<WGM1B1) );
		#endif
	#elif TIMER1_WGM_MODE == TIMER1_WGM_CTC_TOP_ICR1
		TCCR1A &= ~( (1<<WGM10) | (1<<WGM11) );
		TCCR1B |= ( (1<<WGM12) | (1<<WGM13) );

		/*Setup the OC1x pin mode*/
		TCCR1A &= TIMER1_COM1xx_MASK;
		TCCR1A |= (TIMER1_OC1A_MODE << COM1A0);
		TCCR1A |= (TIMER1_OC1B_MOE << COM1B0);

		/*Set the pin direction*/
		#if TIMER1_OC1A_MODE != TIMER1_OC1x_DISCONNECT
			DIO_vSetPinDir(OC1A_PORT, OC1A_PIN, DIR_OUTPUT);
		#endif

		#if TIMER1_OC1B_MODE != TIMER1_OC1x_DISCONNECT
			DIO_vSetPinDir(OC1B_PORT, OC1B_PIN, DIR_OUTPUT);
		#endif

	#elif TIMER1_WGM_MODE == TIMER1_WGM_FAST_PWM_TOP_ICR1
		TCCR1A &= ~(1<<WGM10);
		TCCR1A |= (1<<WGM11);
		TCCR1B |= ( (1<<WGM12) | (1<<WGM13) );

		/*Setup the PWM state of OC1A*/
		#if TIMER1_OC1A_PWM_MODE == PWM_NON_INVERTING
			TCCR1A |= (1<<COM1A1);
			TCCR1A &= ~(1<<COM1A0);
			DIO_vSetPinDir(OC1A_PORT, OC1A_PIN, DIR_OUTPUT);
		#elif TIMER1_OC1A_PWM_MODE == PWM_INVERTING
			TCCR1A |= (1<<COM1A1) | (1<<COM1A0);
			DIO_vSetPinVal(OC1A_PORT, OC1A_PIN, DIR_OUTPUT);
		#elif TIMER1_OC1A_PWM_MODE == PWM_OFF
			TCCR1A &= ~( (1<<COM1A1) | (1<<COM1A0) );
		#endif

		/*Setup the PWM state of OC1B*/
		#if TIMER1_OC1B_PWM_MODE == PWM_NON_INVERTING
			TCCR1A |= (1<<COM1B1);
			TCCR1A &= ~(1<<COM1B0);
			DIO_vSetPinDir(OC1B_PORT, OC1B_PIN, DIR_OUTPUT);
		#elif TIMER1_OC1B_PWM_MODE == PWM_INVERTING
			TCCR1A |= (1<<COM1B1) | (1<<COM1B0);
			DIO_vSetPinVal(OC1B_PORT, OC1B_PIN, DIR_OUTPUT);
		#elif TIMER1_OC1B_PWM_MODE == PWM_OFF
			TCCR1A &= ~( (1<<COM1B0) | (1<<COM1B1) );
		#endif

	#elif TIMER1_WGM_MODE == TIMER1_WGM_FAST_PWM_TOP_OCR1A
		TCCR1A |= (1<<WGM10) | (1<<WGM11);
		TCCR1B |= (1<<WGM12) | (1<<WGM13);

		/*Setup the PWM state of OC1A*/
		#if TIMER1_OC1A_PWM_MODE == PWM_NON_INVERTING
			TCCR1A |= (1<<COM1A1);
			TCCR1A &= ~(1<<COM1A0);
			DIO_vSetPinVal(OC1A_PORT, OC1A_PIN, DIR_OUTPUT);
		#elif TIMER1_OC1A_PWM_MODE == PWM_INVERTING
			TCCR1A |= (1<<WGM1A1) | (1<<WGM1A0);
			DIO_vSetPinVal(OC1A_PORT, OC1A_PIN, DIR_OUTPUT);
		#elif TIMER1_OC1A_PWM_MODE == PWM_OFF
			TCCR1A &= ~( (1<<WGM1A0) | (1<<WGM1A1) );
		#endif

		/*Setup the PWM state of OC1B*/
		#if TIMER1_OC1B_PWM_MODE == PWM_NON_INVERTING
			TCCR1A |= (1<<COM1B1);
			TCCR1A &= ~(1<<COM1B0);
			DIO_vSetPinVal(OC1B_PORT, OC1B_PIN, DIR_OUTPUT);
		#elif TIMER1_OC1A_PWM_MODE == PWM_INVERTING
			TCCR1A |= (1<<WGM1B1) | (1<<WGM1B0);
			DIO_vSetPinVal(OC1B_PORT, OC1B_PIN, DIR_OUTPUT);
		#elif TIMER1_OC1A_PWM_MODE == PWM_OFF
			TCCR1A &= ~( (1<<WGM1B0) | (1<<WGM1B1) );
		#endif

	#endif
}




/**************   TIMER0 ISR   **************/


/*TIMER0 COMP*/
void __vector_10(void){
	if(G_PTRF_TIM0_CTC != ADDRESS_NULL){
		G_PTRF_TIM0_CTC();
	} else {
		/*Handle callback error*/
	}
}

/*TIMER0 OVF*/
void __vector_11(void){
	static u16 L_u16Counter = 0;
	if(G_PTRF_TIM0_OVF != ADDRESS_NULL){
		if(L_u16Counter == G_u16Timer0_Cov) {
			L_u16Counter = 0;
			TCNT0 = G_u8Timer0_Preload_Val;
			G_PTRF_TIM0_OVF();
		} else {
			L_u16Counter++;
		}
	} else {
		/*Handle callback error*/
	}
	return;
}




/**************   TIMER1 ISR   **************/

/*TIMER1 CAPT*/
void __vector_6(void)  {
	if(G_PTRF_TIM1_ICF1 != ADDRESS_NULL) {
		G_PTRF_TIM1_ICF1();
	} else {

	}
}

/*TIMER1 COMPA*/
void __vector_7(void){
	if(G_PTRF_TIM1_OC1AF != ADDRESS_NULL) {
		G_PTRF_TIM1_OC1AF();
	} else {

	}
}

/*TIMER1 COMPB*/
void __vector_8(void){
	if(G_PTRF_TIM1_OC1BF != ADDRESS_NULL) {
		G_PTRF_TIM1_OC1BF();
	} else {

	}
}

/*TIMER1 OVF*/
void __vector_9(void){
	if(G_PTRF_TIM1_OVF != ADDRESS_NULL) {
		G_PTRF_TIM1_OVF();
	} else {

	}
}





/**************   TIMER2 ISR   **************/

/*TIMER2 COMP*/
void __vector_4(void){
	if(G_PTRF_TIM2_CTC != ADDRESS_NULL){
		G_PTRF_TIM2_CTC();
	} else {
		/*Handle callback error*/
	}
}

/*TIMER2 OVF*/
void __vector_5(void){
	if(G_PTRF_TIM2_OVF != ADDRESS_NULL){
		G_PTRF_TIM2_OVF();
	} else {
		/*Handle callback error*/
	}
}
