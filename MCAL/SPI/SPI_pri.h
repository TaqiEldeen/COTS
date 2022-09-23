/*********************************************************/
/***********		Author: TaqiEldeen	 	**************/
/***********		Layer: MCAL			 	**************/
/***********		Component: SPI			**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 23 Sep 2022	 	**************/
/*********************************************************/

#ifndef MCAL_SPI_SPI_PRI_H_
#define MCAL_SPI_SPI_PRI_H_


/************** 	INT status	  **************/
#define INT_ENABLE		1
#define INT_DISABLE		0


/************** 	Data order	  **************/
#define LSB_FIRST	1
#define MSB_FIRST	0


/************** 	Master/Slave Select	  **************/
#define SPI_MASTER		1
#define SPI_SLAVE		0


/************** 	Clock Polarity	  **************/
#define IDLE_SCK_RISING		1
#define IDLE_SCK_FALLING	0


/************** 	Clock Phase	  **************/
#define SETUP_TRAILING		0
#define SETUP_LEADING		1


/************** 	clock rate select	  **************/
#define PRESCALE_4		0
#define PRESCALE_16		1
#define PRESCALE_64		2
#define PRESCALE_128	3
#define PRESCALE_2		4
#define PRESCALE_8		5
#define PRESCALE_32		6


/************** 	SPI DOUBLE SPEED	  **************/
#define SPI2x_ENABLE 	0
#define SPI2x_DISABLE	1

#endif /* MCAL_SPI_SPI_PRI_H_ */
