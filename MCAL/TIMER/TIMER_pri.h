/*********************************************************/
/***********		Author: TaqiEldeen	 	**************/
/***********		Layer: MCAL			 	**************/
/***********		Component: TIMER		**************/
/***********		Version: 1.02		 	**************/
/***********		Date: 13 Sep 2022	 	**************/
/***********		Updated: 17 Sep 2022	**************/
/*********************************************************/

#ifndef MCAL_TIMER_TIMER_PRI_H_
#define MCAL_TIMER_TIMER_PRI_H_



/**************   TIMER0_private   **************/


/* Available WaveForm Generation modes for timer0 */
#define TIMER0_WGM_NORMAL_MODE 		   		0b00000000
#define TIMER0_WGM_PWM_PHASE_CORRECT_MODE 	0b01000000
#define TIMER0_WGM_CTC_MODE			   		0b00001000
#define TIMER0_WGM_FAST_PWM_MODE          	0b01001000
/*Mask for the  waveForm Generation modes*/
#define TIMER0_WGM_MASK        				0b10110111

/*Available Compare output modes for timer0*/
#define TIMER0_OC0_DISCONNECT	0b00000000
#define TIMER0_TOG_OC0     		0b00010000
#define TIMER0_CLR_OC0     		0b00100000
#define TIMER0_SET_OC0 	 		0b00110000
/*Mask for the Compare output mode*/
#define TIMER0_COM_MASK			0b11001111

/*Available Clock sources/prescaling for timer0*/
#define TIMER0_PRESCALER_NO_CLK 		0b00000000
#define TIMER0_PRESCALER_NO_PRESCALE    0b00000001
#define TIMER0_PRESCALER_8				0b00000010
#define TIMER0_PRESCALER_64				0b00000011
#define TIMER0_PRESCALER_256			0b00000100
#define TIMER0_PRESCALER_1024			0b00000101
#define TIMER0_EXT_CLK_FALLING_EDGE		0b00000110
#define TIMER0_EXT_CLK_RISING_EDGE      0b00000111
/*Mask for Clock source*/
#define TIMER0_CLK_SELECT_MASK			0b11111000





/**************   TIMER1_private   **************/


/* Available WaveForm Generation modes for timer1 */

#define TIMER1_WGM_NORMAL_MODE						0
#define TIMER1_WGM_PWM_PHASE_CORRECT_8BIT_MODE		1
#define TIMER1_WGM_PWM_PHASE_CORRECT_9BIT_MODE		2
#define TIMER1_WGM_PWM_PHASE_CORRECT_10BIT_MODE		3
#define TIMER1_WGM_CTC_MODE							4
#define TIMER1_WGM_FAST_PWM_8BIT_MODE				5
#define TIMER1_WGM_FAST_PWM_9BIT_MODE				6
#define TIMER1_WGM_FAST_PWM_10BIT_MODE				7
#define TIMER1_WGM_PWM_PHASE_CORRECT_TOP_ICR1		8
#define TIMER1_WGM_PWM_PHASE_CORRECT_TOP_OCR1A		9
/*
#define TIMER1_WGM_PWM_PHASE_CORRECT_TOP_ICR1		10
#define TIMER1_WGM_PWM_PHASE_CORRECT_TOP_OCR1A		11
*/
#define TIMER1_WGM_CTC_TOP_ICR1						12
#define TIMER1_WGM_FAST_PWM_TOP_ICR1				13
#define TIMER1_WGM_FAST_PWM_TOP_OCR1A				14


/*Available Compare output modes for timer1*/
#define TIMER1_OC1x_DISCONNECT		0
#define TIMER1_TOG_OC1x     		1
#define TIMER1_CLR_OC1x     		2
#define TIMER1_SET_OC1x 	 		3
#define TIMER1_COM1xx_MASK			0b00001111


/*Available Clock sources/prescaling for timer1*/
#define TIMER1_PRESCALER_NO_CLK 		0b00000000
#define TIMER1_PRESCALER_NO_PRESCALE    0b00000001
#define TIMER1_PRESCALER_8				0b00000010
#define TIMER1_PRESCALER_64				0b00000011
#define TIMER1_PRESCALER_256			0b00000100
#define TIMER1_PRESCALER_1024			0b00000101
#define TIMER1_EXT_CLK_FALLING_EDGE		0b00000110
#define TIMER1_EXT_CLK_RISING_EDGE      0b00000111
/*Mask for Clock source*/
#define TIMER1_CLK_SELECT_MASK			0b11111000


/*input capture unit setting for timer1*/





/**************   TIMER2_private   **************/


/* Available WaveForm Generation modes for timer2 */
#define TIMER2_WGM_NORMAL_MODE 		   		0b00000000
#define TIMER2_WGM_PWM_PHASE_CORRECT_MODE 	0b01000000
#define TIMER2_WGM_CTC_MODE			   		0b00001000
#define TIMER2_WGM_FAST_PWM_MODE          	0b01001000
/*Mask for the  waveForm Generation modes*/
#define TIMER2_WGM_MASK        				0b10110111

/*Available Compare output modes for timer2*/
#define TIMER2_OC2_DISCONNECT	0b00000000
#define TIMER2_TOG_OC2     		0b00010000
#define TIMER2_CLR_OC2     		0b00100000
#define TIMER2_SET_OC2 	 		0b00110000
/*Mask for the Compare output mode*/
#define TIMER2_COM_MASK			0b11001111

/*Available Clock sources/prescaling for timer2*/
#define TIMER2_PRESCALER_NO_CLK 		0b00000000
#define TIMER2_PRESCALER_NO_PRESCALE    0b00000001
#define TIMER2_PRESCALER_8				0b00000010
#define TIMER2_PRESCALER_32				0b00000011
#define TIMER2_PRESCALER_64				0b00000100
#define TIMER2_PRESCALER_128			0b00000101
#define TIMER2_PRESCALER_256			0b00000110
#define TIMER2_PRESCALER_1024	        0b00000111
/*Mask for Clock source*/
#define TIMER2_CLK_SELECT_MASK			0b11111000




/*##############   General private   ##############*/


/**************   TIMERn MAX COUNT   **************/
#define TIMER0_MAX_COUNT (u8)  255
#define TIMER1_MAX_COUNT (u16) 65535
#define TIMER2_MAX_COUNT (u8)  255

/**************   TIMER STATES   **************/
#define TIMER_ENABLE 	0
#define TIMER_DISABLE	1


/**************   TIMER PWM   **************/
#define PWM_NON_INVERTING	0
#define PWM_INVERTING		1
#define PWM_OFF				2

/**************   TIMER INT state   **************/
#define INT_ENABLE 	0
#define INT_DISABLE 1



/**************   TIMER ISRs  **************/
void __vector_4(void)__attribute__((signal));  /*TIMER2 COMP*/
void __vector_5(void)__attribute__((signal));  /*TIMER2 OVF*/
void __vector_6(void)__attribute__((signal));  /*TIMER1 CAPT*/
void __vector_7(void)__attribute__((signal));  /*TIMER1 COMPA*/
void __vector_8(void)__attribute__((signal));  /*TIMER1 COMPB*/
void __vector_9(void)__attribute__((signal));  /*TIMER1 OVF*/
void __vector_10(void)__attribute__((signal)); /*TIMER0 COMP*/
void __vector_11(void)__attribute__((signal)); /*TIMER0 OVF*/



/**************   TIMERn POINTER TO FUNCTION  **************/
void (*G_PTRF_TIM0_OVF)(void) = ADDRESS_NULL;
void (*G_PTRF_TIM0_CTC)(void) = ADDRESS_NULL;

void (*G_PTRF_TIM1_OVF)(void) = ADDRESS_NULL;
void (*G_PTRF_TIM1_OC1AF)(void) = ADDRESS_NULL;
void (*G_PTRF_TIM1_OC1BF)(void) = ADDRESS_NULL;
void (*G_PTRF_TIM1_ICF1)(void) = ADDRESS_NULL;


void (*G_PTRF_TIM2_OVF)(void) = ADDRESS_NULL;
void (*G_PTRF_TIM2_CTC)(void) = ADDRESS_NULL;



/**************   TIMERn GLOBAL VARIABLES  **************/
static void TIMER_vTimer0_SetupCTC		();
static void TIMER_vTimer0_SetupFastPWM	();
static void TIMER_vTimer0_SetupPhaseCorrectPWM	();

static void TIMER_vTimer1_setupWGM();

static void TIMER_vTimer2_SetupCTC		();
static void TIMER_vTimer2_SetupFastPWM	();
static void TIMER_vTimer2_SetupPhaseCorrectPWM	();





/**************   TIMERn GLOBAL VARIABLES  **************/
u16 G_u16Timer0_Cov = 0;
u8 G_u8Timer0_Preload_Val = 0;
u8 G_u8Timer0_OcrVal = 0;

u16 G_u16Timer1_Cov = 0;
u16 G_u16Timer1_Preload_Val = 0;
u16 G_u16Timer1_OcrVal = 0;

u16 G_u16Timer2_Cov = 0;
u8 G_u8Timer2_Preload_Val = 0;
u8 G_u8Timer2_OcrVal = 0;

#endif /* MCAL_TIMER_TIMER_PRI_H_ */
