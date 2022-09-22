/*
 * SSD_prg.c
 *
 *  Created on: 19 Aug 2022
 *      Author: 20109
 */

#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "SSD_pri.h"
#include "SSD_cfg.h"
#include "SSD_int.h"

/*Initialise the SSD and turn it off*/
void SSD_vInit (u8 A_u8SsdId){
	switch(A_u8SsdId){
		case SSDL_ID: {
			DIO_vSetPortDir(SSDL_DATA_PORT, DIR_OUTPUT); /*set the port o/p*/
			DIO_vSetPinDir(SSDL_EN_PORT, SSDL_EN_PIN, DIR_OUTPUT);
			#if (SSD_COM == COM_CATHODE)
				DIO_vSetPinVal(SSDL_EN_PORT, SSDL_EN_PIN, VAL_HIGH); /*SSD OFF*/
			#else
				DIO_vSetPinVal(SSDL_EN_PORT, SSDL_EN_PIN, VAL_LOW);
			#endif
			break;
		}
		case SSDR_ID: {
			DIO_vSetPortDir(SSDR_DATA_PORT, DIR_OUTPUT); /*set the port o/p*/
			DIO_vSetPinDir(SSDR_EN_PORT, SSDR_EN_PIN, DIR_OUTPUT);
			#if (SSD_COM == COM_CATHODE)
				DIO_vSetPinVal(SSDR_EN_PORT, SSDR_EN_PIN, VAL_HIGH); /*SSD OFF*/
			#else
				DIO_vSetPinVal(SSDR_EN_PORT, SSDR_EN_PIN, VAL_LOW);
			#endif
			break;
		}
	}
}

/*Display a number on the 7seg*/
void SSD_vDispNum   (u8 A_u8SsdId, u8 A_u8Val){
	/*will be put in .data section and one time initlialise and be put in flash memory*/
	static const u8 L_u8SegCathode[] = { 0b00111111, 0b00000110, 0b01011011, 0b01001111, 0b01100110,
			 	 	 	   	   	         0b01101101, 0b01111101, 0b00000111, 0b01111111, 0b01100111 };//7seg display
	switch(A_u8SsdId){
		case SSDL_ID: {
			#if (SSD_COM == COM_CATHODE)
				DIO_vSetPortVal(SSDL_DATA_PORT, L_u8SegCathode[A_u8Val]); /*display the number*/
			#else
				DIO_vSetPortVal(SSDL_DATA_PORT, ~L_u8SegCathode[A_u8Val]);/*invert for the common anode*/
			#endif
			break;
		}
		case SSDR_ID: {
			#if (SSD_COM == COM_CATHODE)
				DIO_vSetPortVal(SSDR_DATA_PORT, L_u8SegCathode[A_u8Val]); /*display the number*/
			#else
				DIO_vSetPortVal(SSDR_DATA_PORT, ~L_u8SegCathode[A_u8Val]);/*invert for the common anode*/
			#endif

			break;
		}
	}
}

/*Turn off the 7seg*/
void SSD_vTurnOff   (u8 A_u8SsdId){
	switch(A_u8SsdId){
		case SSDL_ID: {
			#if (SSD_COM == COM_CATHODE)
				DIO_vSetPinVal(SSDL_EN_PORT, SSDL_EN_PIN, VAL_HIGH); /*SSD OFF*/
			#else
				DIO_vSetPinVal(SSDL_EN_PORT, SSDL_EN_PIN, VAL_LOW);
			#endif
			break;
		}
		case SSDR_ID: {
			#if (SSD_COM == COM_CATHODE)
				DIO_vSetPinVal(SSDR_EN_PORT, SSDR_EN_PIN, VAL_HIGH); /*SSD OFF*/
			#else
				DIO_vSetPinVal(SSDR_EN_PORT, SSDR_EN_PIN, VAL_LOW);
			#endif
			break;
		}
	}
}

/*Turn on the 7seg*/
void SSD_vTurnOn    (u8 A_u8SsdId){
	switch(A_u8SsdId){
		case SSDL_ID: {
			#if (SSD_COM == COM_CATHODE)
				DIO_vSetPinVal(SSDL_EN_PORT, SSDL_EN_PIN, VAL_LOW); /*SSD ON*/
			#else
				DIO_vSetPinVal(SSDL_EN_PORT, SSDL_EN_PIN, VAL_HIGH);
			#endif
			break;
		}
		case SSDR_ID: {
			#if (SSD_COM == COM_CATHODE)
				DIO_vSetPinVal(SSDR_EN_PORT, SSDR_EN_PIN, VAL_LOW); /*SSD ON*/
			#else
				DIO_vSetPinVal(SSDR_EN_PORT, SSDR_EN_PIN, VAL_HIGH);
			#endif
			break;
		}
	}
}

/*Clear the 7seg*/
void SSD_vClearDisp (u8 A_u8SsdId){
	switch(A_u8SsdId){
		case SSDL_ID: DIO_vSetPortVal(SSDL_DATA_PORT, 0x00); break;
		case SSDR_ID: DIO_vSetPortVal(SSDR_DATA_PORT, 0x00); break;
	}
}

/*Turn on a segment on the 7seg*/
void SSD_vSegmentOn (u8 A_u8SsdId, u8 A_u8SegmentId){
	static const u8 L_u8Seg[]= {
			0b00000001,
			0b00000010,
			0b00000100,
			0b00001000,
			0b00010000,
			0b00100000,
			0b01000000,
			0b10000000
	};
	switch(A_u8SsdId){
		case SSDL_ID:
		{
			#if (SSD_COM == COM_CATHODE)
				DIO_vSetPortVal(SSDL_DATA_PORT, L_u8Seg[A_u8SegmentId]);
			#else
				DIO_vSetPortVal(SSDL_DATA_PORT, ~L_u8Seg[A_u8SegmentId]);
			#endif
			break;
		}
		case SSDR_ID:
		{
			#if (SSD_COM == COM_CATHODE)
				DIO_vSetPortVal(SSDR_DATA_PORT, L_u8Seg[A_u8SegmentId]);
			#else
				DIO_vSetPortVal(SSDR_DATA_PORT, ~L_u8Seg[A_u8SegmentId]);
			#endif
			break;
		}
	}
}
