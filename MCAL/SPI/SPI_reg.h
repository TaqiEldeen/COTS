/*********************************************************/
/***********		Author: TaqiEldeen	 	**************/
/***********		Layer: MCAL			 	**************/
/***********		Component: SPI			**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 23 Sep 2022	 	**************/
/*********************************************************/

#ifndef MCAL_SPI_SPI_REG_H_
#define MCAL_SPI_SPI_REG_H_


/******************		SPI control register	 ******************/
#define SPCR	*((u8*) 0x2D)
/*Bits*/
#define SPR0	0	/*SPI Clock Rate Select*/
#define SPR1	1	/*SPI Clock Rate Select*/
#define CPHA	2	/*Clock Phase*/
#define CPOL	3	/*Clock Polarity*/
#define MSTR	4	/*Master/Slave Select*/
#define DORD	5	/*Data Order*/
#define SPE		6	/*SPI Enable*/
#define SPIE	7	/*SPI Interrupt Enable*/


/******************		SPI Status Register	    ******************/
#define SPSR	*((volatile u8*) 0x2E)
/*Bits: bits 1-5 are reserved by the MCU*/
#define SPI2X	0	/*Double SPI Speed Bit*/
#define WCOL	6	/*Write COLlision Flag*/
#define SPIF	7	/*SPI Interrupt Flag*/


/******************		SPI Data Register	 ******************/
#define SPDR	*((volatile u8*) 0x2F)


#endif /* MCAL_SPI_SPI_REG_H_ */
