/*********************************************************/
/***********		Author: TaqiEldeen	 	**************/
/***********		Layer: MCAL			 	**************/
/***********		Component: UART			**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 21 Sep 2022	 	**************/
/*********************************************************/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "../../MCAL/UART/UART_pri.h"
#include "../../MCAL/UART/UART_cfg.h"
#include "../../MCAL/UART/UART_reg.h"
#include "../../MCAL/UART/UART_int.h"
#include "../../MCAL/WDT/WDT_int.h"



/**********************************************************************************************************
 * Description : Interface Function to setup the UART based on the configuration
 * Outputs     : void
 * Inputs      : BaudRate
 ***********************************************************************************************************/
void UART_vInit(u16 A_u16BaudRate){
	/*Applying the configured modes in Register UCSRB*/
	UCSRB = 0x00;
	UCSRB |= (RX_COMPLETE_INTERRUPT << RXCIE)
			|(TX_COMPLETE_INTERRUPT << TXCIE)
			|(UDR_EMPTY_INTERRUPT   << UDRIE)
			|(RECEIVER_STATUS 		<< RXEN)
			|(TRANSMITTER_STATUS 	<< TXEN);


	/*Applying the configured modes in Register UCSRA*/

	/*The URSEL must be one when writing the UCSRC.*/
	UCSRC |= (1 << URSEL)
			|(USART_MODE 		<< UMSEL)
			|(PARITY_MODE 		<< UPM0)
			|(STOP_BIT_SELECT 	<< USBS);


	/*Choosing the character size*/
	#if CHARACTER_SIZE == BIT_9_DATA
		SET_BIT(UCSRB, UCSZ2);
		UCSRC |= (1<<UCSZ1) | (1<<UCSZ2);
	#else
		UCSRC |= (1<<URSEL)|(CHARACTER_SIZE << UCSZ0);
	#endif


	/*Choosing CLK polarity if in SYNC mode*/
	#if USART_MODE == SYNC_MODE
		UCSRC |= (CLK_POLARITY	<< UCPOL);
	#endif

	/*BAUD rate configuration*/
	UBRRH =  ( (0<<URSEL) | (A_u16BaudRate >> 8) );
	UBRRL = (u8)A_u16BaudRate;

	/*Enable the WDT*/
	WDT_vEnable();

	/*Setup the TX & RX pins*/
	DIO_vSetPinDir(TX_PORT, TX_PIN, DIR_OUTPUT);
	DIO_vSetPinDir(RX_PORT, RX_PIN, DIR_INPUT);
}


/**********************************************************************************************************
 * Description : Interface Function to send the data
 * Outputs     : void
 * Inputs      : Data
 ***********************************************************************************************************/
void UART_vSendCharSync(u16 A_u16Data){


	/*Wait till UDR is empty*/
	WDT_vSetSleep(WDT_SLEEP_16_3_MS);
	while( !(UCSRA & (1<<UDRE)) );
	WDT_vDisable();

	/*Handle 9-bits character mode*/
	#if CHARACTER_SIZE == BIT_9_DATA
		if(A_u16Data & (1<<8)) {
			SET_BIT(UCSRB, TXB8);
		} else {
			CLR_BIT(UCSRB, TXB8);
		}
	#endif

	/*Sending the lower byte*/
	UDR = (u8)A_u16Data;


	/*
	 * WE can also use the Transmit complete flag

	while(!(UCSRA & (1<<TXC)));
	CRL_BIT(UCSRA, TXC);

	*/

	return;
}


/**********************************************************************************************************
 * Description : Interface Function to send the data
 * Outputs     : void
 * Inputs      : string data
 ***********************************************************************************************************/
void UART_vSendStringSync(u8 *A_u8Str){
	u8 L_u8Iterator = 0;
	while(A_u8Str[L_u8Iterator] != '\0') {
		UART_vSendCharSync(A_u8Str[L_u8Iterator]);
		L_u8Iterator++;
	}
	return;
}


/**********************************************************************************************************
 * Description : Interface Function to send the data
 * Outputs     : the data received
 * Inputs      : void
 ***********************************************************************************************************/
u16 UART_u16ReceiveDataSync(){
	u16 L_u16Data = 0;

	/*Wait till Receiving the Data*/
	while( !(UCSRA & (1<<RXC)) );

	/*Handle 9-bits character mode*/
	#if CHARACTER_SIZE == BIT_9_DATA
		L_u16Data = (RXB8<<8);
	#endif

	L_u16Data = UDR;

	return L_u16Data;
}
