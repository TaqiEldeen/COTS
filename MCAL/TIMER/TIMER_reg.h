/*********************************************************/
/***********		Author: TaqiEldeen	 	**************/
/***********		Layer: MCAL			 	**************/
/***********		Component: TIMER		**************/
/***********		Version: 1.02		 	**************/
/***********		Date: 13 Sep 2022	 	**************/
/***********		Updated: 17 Sep 2022	**************/
/*********************************************************/

#ifndef MCAL_TIMER_TIMER_REG_H_
#define MCAL_TIMER_TIMER_REG_H_



/**************   Timer0 Registers   **************/

/*Register TCCR0*/
#define TCCR0	 *((volatile u8*) 0x53)
/*Pins*/
#define CS00  0 /*Clock select*/
#define CS01  1 /*Clock select*/
#define CS02  2 /*Clock select*/
#define WGM01 3 /*Waveform gen mode*/
#define COM00 4 /*OC0 pin MODES*/
#define COM01 5 /*OC0 pin MODES*/
#define WGM00 6 /*Waveform gen mode*/
#define FOC0  7 /*Force output compare*/

/*register TCNT0 timer counter*/
#define TCNT0	 *((volatile u8*) 0x52)

/*Register OCR0*/
#define OCR0  *((volatile u8*) 0x5C)






/**************   Timer1 Registers   **************/

/*Register TCCR1A*/
#define TCCR1A	 *((volatile u8*) 0x4F)
/*Pins*/
#define WGM10	0
#define WGM11	1
#define FOC1B	2
#define FOC1A	3
#define COM1B0	4
#define COM1B1	5
#define COM1A0	6
#define COM1A1	7


/*Register TCCR1B*/
#define TCCR1B	 *((volatile u8*) 0x4E)
/*Pins,, pin 5 is reserved*/
#define CS10	0
#define CS11	1
#define CS12	2
#define WGM12	3
#define WGM13	4
#define ICES1	6
#define ICNC1	7


/*Register TCNT1H*/
#define TCNT1H	 *((volatile u8*) 0x4D)

/*Register TCNT1L*/
#define TCNT1L	 *((volatile u8*) 0x4C)

/* Register TCNT1W
 *--> Used to get the whole counting of the Timer1
 * */
#define TCNT1	*((volatile u16*) 0x4C)


/*Register OCR1AH*/
#define OCR1AH *((volatile u8*) 0x4B)

/*Register OCR1AL*/
#define OCR1AL *((volatile u8*) 0x4A)

/*Register OCR1AW
 * --> Used to get the whole counting of the Timer1 OCR1
 */
#define OCR1A *((volatile u16*) 0x4A)


/*Register OCR1BH*/
#define OCR1BH *((volatile u8*) 0x49)

/*Register OCR1BL*/
#define OCR1BL *((volatile u8*) 0x48)

/*Register OCR1BW
 * --> Used to get the whole counting of the Timer1 OCR1
 */
#define OCR1B *((volatile u16*) 0x48)


/*Register ICR1H*/
#define ICR1H	*((volatile u8*) 0x47)

/*Register ICR1L*/
#define ICR1L	*((volatile u8*) 0x46)

/*Register ICR1
 * --> Used to get the whole counting of the Timer1 input capture
 */
#define ICR1	*((volatile u16*) 0x46)






/**************   Timer2 Registers   **************/

/*Register TCCR2*/
#define TCCR2	 *((volatile u8*) 0x45)
/*Pins*/
#define CS20	0
#define CS21	1
#define CS22	2
#define WGM21	3
#define COM20	4
#define COM21	5
#define WGM20	6
#define FOC2	7


/*Register TCNT2*/
#define TCNT2	 *((volatile u8*) 0x44)


/*Register OCR2*/
#define OCR2  	 *((volatile u8*) 0x43)







/**************   Timer Interrupt states Registers   **************/


/*Register TIMSK*/
#define TIMSK	*((volatile u8*) 0x59)

/*Pins*/
#define TOIE0  0
#define OCIE0  1
#define TOIE1  2
#define OCIE1B 3
#define OCIE1A 4
#define TICIE1 5
#define TOIE2  6
#define OCIE2  7

/*Register TIFR*/
#define TIFR  *((volatile u8*) 0x58)

/*Pins*/
#define TOV0  0
#define OCF0  1
#define TOV1  2
#define OCF1B 3
#define OCF1A 4
#define ICF1  5
#define TOV2  6
#define OCF2  7

#endif /* MCAL_TIMER_TIMER_REG_H_ */
