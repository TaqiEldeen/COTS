/*
 * SSD_int.h
 *
 *  Created on: 19 Aug 2022
 *      Author: 20109
 */

#ifndef HAL_SSD_SSD_INT_H_
#define HAL_SSD_SSD_INT_H_

typedef enum {
	SSD_A_ID,
	SSD_B_ID,
	SSD_C_ID,
	SSD_D_ID,
	SSD_E_ID,
	SSD_F_ID,
	SSD_G_ID,
	SSD_DOT_ID
};

#define SSDR_ID 0
#define SSDL_ID 1

void SSD_vInit      (u8 A_u8SsdId);
void SSD_vDispNum   (u8 A_u8SsdId, u8 A_u8Val);
void SSD_vTurnOff   (u8 A_u8SsdId);
void SSD_vTurnOn    (u8 A_u8SsdId);
void SSD_vClearDisp (u8 A_u8SsdId);
void SSD_vSegmentOn (u8 A_u8SsdId, u8 A_u8SegmentId);

#endif /* HAL_SSD_SSD_INT_H_ */
