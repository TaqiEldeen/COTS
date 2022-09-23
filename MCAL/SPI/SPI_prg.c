/*********************************************************/
/***********		Author: TaqiEldeen	 	**************/
/***********		Layer: MCAL			 	**************/
/***********		Component: SPI			**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 23 Sep 2022	 	**************/
/*********************************************************/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../DIO/DIO_int.h"
#include "SPI_pri.h"
#include "SPI_cfg.h"
#include "SPI_int.h"
#include "SPI_reg.h"


/**********************************************************************************************************
 * Description : Interface Function to setup the SPI
 * Outputs     : void
 * Inputs      : void
 * NOTE		   : based on configuration the SPI is initialised in MASTER or SLAVE
 ***********************************************************************************************************/
void SPI_vInit(){
	/*setup the SPI*/
	SPCR = 0x00;
	SPCR |= (SPI_INTERRUPT_STATUS << SPIE)
			|(1	<< SPE)
			|(SPI_DATA_ORDER  << DORD)
			|(SPI_MODE_SELECT << MSTR)
			|(SPI_CLK_POL 	  << CPOL)
			|(SPI_CPHA 		  << CPHA)
			|(SPI_CLK_SELECT  <<  SPR0);

	/*Handling speed mode*/
	#if SPI_DOUBLE_SPEED == SPI2x_ENABLE
		SET_BIT(SPSR, SPI2X);
	#else
		CLR_BIT(SPSR, SPI2X);
	#endif

	/*setup pins*/
	#if SPI_MODE_SELECT == SPI_MASTER
		DIO_vSetPinDir(SPI_PORT, SPI_MOSI_PIN, DIR_OUTPUT);
		DIO_vSetPinDir(SPI_PORT, SPI_SCK_PIN, DIR_OUTPUT);
		DIO_vSetPinDir(SPI_PORT, SPI_MISO_PIN, DIR_INPUT);
	#else SPI_MODE_SELECT == SPI_SLAVE
		DIO_vSetPinDir(SPI_PORT, SPI_MOSI_PIN, DIR_INPUT);
		DIO_vSetPinDir(SPI_PORT, SPI_SCK_PIN, DIR_INPUT);
		DIO_vSetPinDir(SPI_PORT, SPI_MISO_PIN, DIR_OUTPUT);
	#endif
}

/**********************************************************************************************************
 * Description : Interface Function to Disable the SPI
 * Outputs     : void
 * Inputs      : void
 ***********************************************************************************************************/
void SPI_vDisable(){
	CLR_BIT(SPCR, SPE);
}

/**********************************************************************************************************
 * Description : Interface Function to Enable the SPI
 * Outputs     : void
 * Inputs      : void
 ***********************************************************************************************************/
void SPI_vEnable(){
	SET_BIT(SPCR, SPE);
}

/**********************************************************************************************************
 * Description : Interface Function to transmit/receive
 * Outputs     : received data
 * Inputs      : transmit data
 ***********************************************************************************************************/
u8 SPI_u8Tranceiver(u8 A_u8Data){

	/*Send data*/
	SPDR = A_u8Data;

	/*Wait till transmitting is completed */
	while(!(GET_BIT(SPSR, SPIF)));

	/*read the received data*/
	return SPDR;
}
