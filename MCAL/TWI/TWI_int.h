
/*********************************************************/
/***********		Author: TaqiEldeen	 	**************/
/***********		Layer: MCAL			 	**************/
/***********		Component: I2C			**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 26 Sep 2022	 	**************/
/*********************************************************/

#ifndef MCAL_TWI_TWI_INT_H_
#define MCAL_TWI_TWI_INT_H_


/*****************		Status Codes for Master Transmitter Mode		*****************/
#define START_ACK				0x08
#define REP_START_ACK			0x10
#define SLAVE_ADD_AND_WR_ACK	0x38
#define SLAVE_ADD_AND_RD_ACK	0x40
#define MSTR_WR_BYTE_ACK		0x48
#define MSTR_RD_BYTE_ACK		0x50
#define MSTR_RD_BYTE_NACK		0x58

/*****************		the states of addressing a slave (reading/writing)		*****************/
#define TWI_SLAVE_RD	1
#define TWI_SLAVE_WR	0


/**********************************************************************************************************
 * Description : Interface Function to Init in master mode
 * Outputs     : void
 * Inputs      : void
 ***********************************************************************************************************/
void TWI_vMasterInit(void);

/**********************************************************************************************************
 * Description : Interface Function to send the start condition
 * Outputs     : void
 * Inputs      : void
 ***********************************************************************************************************/
void TWI_vSendStartCondition(void);

/**********************************************************************************************************
 * Description : Interface Function to send the stop condition
 * Outputs     : void
 * Inputs      : void
 ***********************************************************************************************************/
void TWI_vSendStopCondition(void);

/**********************************************************************************************************
 * Description : Interface Function to write data
 * Outputs     : void
 * Inputs      : the data
 ***********************************************************************************************************/
void TWI_vMasterWriteDataByte(u8 A_u8Data);

/**********************************************************************************************************
 * Description : Interface Function to write the required slave address
 * Outputs     : void
 * Inputs      : the data
 * NOTES	   : use the macros of reading/writing
 ***********************************************************************************************************/
void TWI_vMasterWriteSlaveAdd(u8 A_u8Data, u8 A_u8RW);

/**********************************************************************************************************
 * Description : Interface Function to Read data with acknowledge
 * Outputs     : void
 * Inputs      : void
 ***********************************************************************************************************/
u8 TWI_vMasterReadDataByteWith_ACK(void);

/**********************************************************************************************************
 * Description : Interface Function to read data without acknowledge
 * Outputs     : void
 * Inputs      : void
 ***********************************************************************************************************/
u8 TWI_vMasterReadDataByteWith_NACK(void);

/**********************************************************************************************************
 * Description : Interface Function to get status of the bus
 * Outputs     : void
 * Inputs      : void
 ***********************************************************************************************************/
u8 TWI_vMasterGetStatus(void);


#endif /* MCAL_TWI_TWI_INT_H_ */
