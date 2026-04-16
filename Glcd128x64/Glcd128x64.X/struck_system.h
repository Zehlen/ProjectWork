/*
 * struck_system.h
 *
 *  Created on: Jul 18, 2024
 *      Author: Shruti
 */

#ifndef INC_STRUCK_SYSTEM_H_
#define INC_STRUCK_SYSTEM_H_

#include <stdint.h>
typedef struct __graphics
{
	volatile unsigned InitGraphics :		 1;
	volatile unsigned StartDelayCount : 	 1;
	volatile unsigned StartFrameDelayCount : 1;
	volatile unsigned DelayTimeout :		 1;
	volatile unsigned FrameDelayTimeout :	 1;
	volatile unsigned FontsInverted :		 1;
	volatile unsigned Debounceperiod :		 1;
	volatile unsigned KeyPressed :			 1;
	volatile unsigned KeyReleased :			 1;
	volatile unsigned KeyValue : 			 4;
	volatile unsigned PreKeyValue :			 4;
	volatile unsigned Updatedisplay : 		 1;
	volatile unsigned G_SelModeFlag :  		 1;
	volatile unsigned EPROM_WriteFlag :		 1;
	volatile unsigned BuzzerStartFlag :		 1;

	volatile uint8_t VACEvent_Ui8;
	volatile uint8_t G_SelCnt_Ui8;
	volatile uint8_t DebounceCount;
	volatile uint8_t DebounceCounter;
	volatile uint8_t Arrow_X;
	volatile uint8_t Arrow_Y;
	volatile uint8_t G_ErrorPer_Ui8;
	volatile uint8_t G_DefTimeData_Ui8;
	volatile uint8_t BuzzerOnOffConunt_Ui8;
	volatile uint8_t G_GLCD_InitStatus_Ui8;
	volatile uint8_t RowStrtAddr_Ui8;
	volatile uint8_t ColStrtAddr_Ui8;
	volatile uint8_t RowEndAddr_Ui8;
	volatile uint8_t ColEndAddr_Ui8;
	volatile uint8_t TotalColWrite_Ui8;
	volatile uint8_t TotalRowWrite_Ui8;
	volatile uint8_t GLcdStrEvent_Ui8;

	volatile uint16_t LcdUpadetCounter_Ui16;
	volatile uint16_t LcdUpadetCount_Ui16;
	volatile uint16_t Delay_count_Ui16;
	volatile uint16_t Delay_counter_Ui16;
	volatile uint16_t FrameDelayCount_Ui16;
	volatile uint16_t FrameDelayCounter_Ui16;
	volatile uint16_t G_MotorTime_Ui16;
	volatile uint16_t G_HalfMotorTime_Ui16;
	volatile uint16_t BuzzerCount_Ui16;
	volatile uint16_t GPIO_ReadValue_Ui16;
	volatile uint16_t GPIO_WriteValue_Ui16;
	volatile uint16_t TotalColWrite_Ui16;
	volatile long G_BatADC_Ln;

} _graphics;

typedef struct __KeyPad{

	uint8_t G_DebncCntr_ui8;
	uint8_t G_DebncCnt_ui8;
	uint8_t G_PrsedKeyVal_Ui8;
	uint8_t G_CnfrmkeyVal_Ui8;

	uint16_t G_GetKeyVal_Ui16;
} _KeyPad;

typedef struct __KeyPadFalg{
	volatile unsigned Key1_Flag			: 1;
	volatile unsigned Key2_Flag			: 1;
	volatile unsigned Key3_Flag			: 1;
	volatile unsigned Key4_Flag			: 1;
	volatile unsigned KeyPressedFlag 	: 1;
	volatile unsigned KeyReleasedFlag   : 1;
	volatile unsigned KeyDectedFlag 	: 1;
} _KeyPadFalgs;

typedef struct __KeyPadvars{
	_KeyPad KeyPad;
	_KeyPadFalgs KeyPadFlags;
} _KeyPadvars;

typedef union __ValOfKey_Un
{
	volatile unsigned  KeyVal 			: 4;
	_KeyPadFalgs       KeyPadFlag_Un;
} _ValOfKey_Un;
enum
{
    false,true 
};

enum {False,True};


#endif /* INC_STRUCK_SYSTEM_H_ */
