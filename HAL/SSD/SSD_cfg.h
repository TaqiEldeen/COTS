/*
 * SSD_cfg.h
 *
 *  Created on: 19 Aug 2022
 *      Author: 20109
 */

#ifndef HAL_SSD_SSD_CFG_H_
#define HAL_SSD_SSD_CFG_H_

/*the right 7seg*/
#define SSDR_DATA_PORT PORTA_ID
#define SSDR_EN_PORT   PORTD_ID
#define SSDR_EN_PIN    PIN0_ID

/*the left 7seg*/
#define SSDL_DATA_PORT PORTA_ID
#define SSDL_EN_PORT   PORTD_ID
#define SSDL_EN_PIN    PIN1_ID


/*
 * you can choose from COM_Anode or COM_CATHODE
 * */
#define SSD_COM COM_CATHODE
#endif /* HAL_SSD_SSD_CFG_H_ */
