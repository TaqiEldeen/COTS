/*********************************************************/
/***********		Author: TaqiEldeen	 	**************/
/***********		Layer: MCAL			 	**************/
/***********		Component: UART			**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 21 Sep 2022	 	**************/
/*********************************************************/

#ifndef MCAL_UART_UART_INT_H_
#define MCAL_UART_UART_INT_H_


/*Available baud rates*/
#define UART_BAUD_RATE_9600		51



/**********************************************************************************************************
 * Description : Interface Function to setup the UART based on the configuration
 * Outputs     : void
 * Inputs      : BaudRate
 ***********************************************************************************************************/
void UART_vInit(u16 A_u16BaudRate);


/**********************************************************************************************************
 * Description : Interface Function to send the data
 * Outputs     : void
 * Inputs      : Data
 ***********************************************************************************************************/
void UART_vSendCharSync(u16 A_u16Data);


/**********************************************************************************************************
 * Description : Interface Function to send the data
 * Outputs     : void
 * Inputs      : string data
 ***********************************************************************************************************/
void UART_vSendStringSync(u8 *A_u8Str);


/**********************************************************************************************************
 * Description : Interface Function to send the data
 * Outputs     : the data received
 * Inputs      : void
 ***********************************************************************************************************/
u16 UART_u16ReceiveDataSync();


#endif /* MCAL_UART_UART_INT_H_ */
