/*********************************************************/
/***********		Author: TaqiEldeen	 	**************/
/***********		Layer: MCAL			 	**************/
/***********		Component: UART			**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 21 Sep 2022	 	**************/
/*********************************************************/

#ifndef MCAL_UART_UART_PRI_H_
#define MCAL_UART_UART_PRI_H_

/****************	Interrupt Options	****************/
#define INT_ENABLE 		1
#define INT_DISABLE		0



/****************	Receiver & transmitter Options	****************/
#define ENABLE 		1
#define DISABLE		0



/****************	USART MODE Options	****************/
#define ASYNC_MODE		0
#define SYNC_MODE		1




/****************	Parity MODE Options	****************/
#define PARITY_DISABLE		0
#define PARITY_EVEN			2
#define PARITY_ODD			3



/****************	Stop bits MODE Options	****************/
#define ONE_STOP_BIT		0
#define TWO_STOP_BITS		1


/****************	Stop bits MODE Options	****************/
#define BIT_5_DATA 			0
#define BIT_6_DATA 			1
#define BIT_7_DATA 			2
#define BIT_8_DATA 			3
#define BIT_9_DATA 			4


/****************	Polarity MODE Options	****************/
#define RISING_XCK_EDGE		0
#define FALLING_XCK_EDGE	1



#endif /* MCAL_UART_UART_PRI_H_ */
