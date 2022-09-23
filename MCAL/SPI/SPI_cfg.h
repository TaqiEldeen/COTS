/*********************************************************/
/***********		Author: TaqiEldeen	 	**************/
/***********		Layer: MCAL			 	**************/
/***********		Component: SPI			**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 23 Sep 2022	 	**************/
/*********************************************************/

#ifndef MCAL_SPI_SPI_CFG_H_
#define MCAL_SPI_SPI_CFG_H_

/* SPI interrupt status
 *
 * Options:
 * 1- INT_ENABLE
 * 2- INT_DISABLE
 * */
#define SPI_INTERRUPT_STATUS	INT_DISABLE

/* SPI Data order
 *
 * Options:
 * 1- LSB_FIRST
 * 2- MSB_FIRST
 * */
#define SPI_DATA_ORDER		MSB_FIRST

/* Master/Slave Select
 *
 * Options:
 * 1- SPI_MASTER
 * 2- SPI_SLAVE
 * */
#define SPI_MODE_SELECT		SPI_MASTER

/* Clock Polarity
 *
 * Options:
 * 1- IDLE_SCK_RISING
 * 2- IDLE_SCK_FALLING
 * */
#define SPI_CLK_POL		IDLE_SCK_FALLING

/* Clock Phase
 *
 * Options:
 * 1- SETUP_TRAILING
 * 2- SETUP_LEADING
 * */
#define SPI_CPHA	SETUP_LEADING

/* SPI clock rate select
 *
 * Options:
 * 1- PRESCALE_4
 * 2- PRESCALE_16
 * 3- PRESCALE_64
 * 4- PRESCALE_128
 * 5- PRESCALE_2
 * 6- PRESCALE_8
 * 7- PRESCALE_32
 * 8- PRESCALE_64
 * */
#define SPI_CLK_SELECT		PRESCALE_4

#endif /* MCAL_SPI_SPI_CFG_H_ */
