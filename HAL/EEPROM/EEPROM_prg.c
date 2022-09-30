/*
 * EEPROM_prg.c
 *
 *  Created on: 28 Sep 2022
 *      Author: 20109
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/TWI/TWI_int.h"
#include "EEPROM_pri.h"
#include "EEPROM_int.h"


/**********************************************************************************************************
 * Description : Interface Function to Init the EEPROM
 * Outputs     : void
 * Inputs      : void
 ***********************************************************************************************************/
void EEPROM_vInit(void){
	/*Init the TWI*/
	TWI_vMasterInit();
}


/**********************************************************************************************************
 * Description : Interface Function to write data in a specific address
 * Outputs     : Error state
 * Inputs      : The required address. the data
 ***********************************************************************************************************/
u8 EEPROM_u8WriteData(u16 A_u16Addr, u8 A_u8Data){
	u8 L_u8BlockNo;
	u8 L_u8AddressLocation;
	u8 L_u8SlaveAddress;

	/*Get the block number by masking the address and shifting to second bit*/
	L_u8BlockNo = ( (A_u16Addr & BLOCK_MASK) >> 8 );

	/*Get the address in the block*/
	L_u8AddressLocation = (u8) A_u16Addr;

	/*Get the slave address*/
	L_u8SlaveAddress = ( (FIXED_ADDRESS >> 1) | L_u8BlockNo );

	/*Starting the condition*/
	TWI_vSendStartCondition();

	/*Check for the ACK*/
	if(TWI_u8MasterGetStatus() == TWI_STATUS_START){
		TWI_vMasterWriteSlaveAdd(L_u8SlaveAddress, TWI_SLAVE_WR);
	} else {
		return EEPROM_ERR_START_CONDITION;
	}

	/*Check for the ACK*/
	if(TWI_u8MasterGetStatus() == TWI_STATUS_MT_SLA_W_ACK) {
		/*Send the address location*/
		TWI_vMasterWriteDataByte(L_u8AddressLocation);
	} else {
		return EEPROM_ERR_SLAVE_ADR;
	}

	/*Check for the ACK*/
	if(TWI_u8MasterGetStatus() == TWI_STATUS_MT_DATA_ACK) {
		/*Send the data byte*/
		TWI_vMasterWriteDataByte(A_u8Data);
	} else {
		return EEPROM_ERR_DATA;
	}

	/*Check for the ACK*/
	if(TWI_u8MasterGetStatus() == TWI_STATUS_MT_DATA_ACK) {
		TWI_vSendStopCondition();
		return EEPROM_NO_ERR;
	} else {
		return EEPROM_ERR_DATA;
	}
}


/**********************************************************************************************************
 * Description : Interface Function to write data in a specific address
 * Outputs     : Error state
 * Inputs      : The required address. the data to be modified
 ***********************************************************************************************************/
u8 EEPROM_u8ReadData(u16 A_u8Addr, u8 * A_u8Data){
	u8 L_u8BlockNo;
	u8 L_u8AddressLocation;
	u8 L_u8SlaveAddress;


	/*Get the block number by masking the address and shifting to second bit*/
	L_u8BlockNo = ( (A_u8Addr & BLOCK_MASK) >> 8 );

	/*Get the address in the block*/
	L_u8AddressLocation = (u8) A_u8Addr;

	/*Get the slave address: it must be 7 bits starting from bit 0*/
	L_u8SlaveAddress = ( (FIXED_ADDRESS >> 1) | L_u8BlockNo );


	/*Start condition*/
	TWI_vSendStartCondition();

	/*Check for the ACK*/
	if(TWI_u8MasterGetStatus() == TWI_STATUS_START){
		/*Device select & block select*/
		TWI_vMasterWriteSlaveAdd(L_u8SlaveAddress, TWI_SLAVE_WR);
	} else {
		return EEPROM_ERR_START_CONDITION;
	}

	/*Check for the ACK*/
	if(TWI_u8MasterGetStatus() == TWI_STATUS_MT_SLA_W_ACK) {
		/*Send the address location required to read from it*/
		TWI_vMasterWriteDataByte(L_u8AddressLocation);
	} else {
		return EEPROM_ERR_SLAVE_ADR;
	}

	/*Check for the ACK*/
	if(TWI_u8MasterGetStatus() == TWI_STATUS_MT_DATA_ACK) {
		/*repeated start to change the direction*/
		TWI_vSendStartCondition();
	} else {
		return EEPROM_ERR_DATA;
	}

	/*Check for the ACK*/
	if(TWI_u8MasterGetStatus() == TWI_STATUS_REP_START){
		TWI_vMasterWriteSlaveAdd(L_u8SlaveAddress, TWI_SLAVE_RD);
	} else {
		return EEPROM_ERR_START_CONDITION;
	}

	/*Check for the ACK*/
	if(TWI_u8MasterGetStatus() == TWI_STATUS_MT_SLA_R_ACK) {
		*A_u8Data = TWI_u8MasterReadDataByteWith_NACK();
		TWI_vSendStopCondition();
		return EEPROM_NO_ERR;
	} else {
		return EEPROM_ERR_SLAVE_ADR;
	}

}
