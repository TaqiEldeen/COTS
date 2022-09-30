/*
 * EEPROM_int.h
 *
 *  Created on: 28 Sep 2022
 *      Author: 20109
 */

#ifndef HAL_EEPROM_EEPROM_INT_H_
#define HAL_EEPROM_EEPROM_INT_H_

#define EEPROM_ERR_START_CONDITION		1
#define EEPROM_ERR_SLAVE_ADR			2
#define EEPROM_ERR_LOC_ADR				3
#define EEPROM_NO_ERR					4
#define EEPROM_ERR_DATA					5

/**********************************************************************************************************
 * Description : Interface Function to write data in a specific address
 * Outputs     : Error state
 * Inputs      : The required address. the data
 ***********************************************************************************************************/
void EEPROM_vInit(void);

/**********************************************************************************************************
 * Description : Interface Function to write data in a specific address
 * Outputs     : Error state
 * Inputs      : The required address. the data
 ***********************************************************************************************************/
u8 EEPROM_u8ReadData(u16 A_u8Addr, u8 * A_u8Data);

/**********************************************************************************************************
 * Description : Interface Function to write data in a specific address
 * Outputs     : Error state
 * Inputs      : The required address. the data to be modified
 ***********************************************************************************************************/
u8 EEPROM_u8WriteData(u16 A_u16Addr, u8 A_u8Data);




#endif /* HAL_EEPROM_EEPROM_INT_H_ */
