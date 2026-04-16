/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef DIPLY_H
#define	DIPLY_H

#include "system.h"

void G_SetData_Mth(uint8_t L_Data_Ui8);
void G_SwtchDsply(void);
void L_SwtchDsply(void);


#define ZERO   0xFC
#define ONE    0x60
#define TWO    0xDA
#define THREE  0xF2
#define FOUR   0x66
#define FIVE   0xB6
#define SIX    0xBE
#define SEVEN  0xE0
#define EIGHT  0xFE
#define NINE   0xF6

uint8_t DsplyVal_ArrUi8[] = {ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE};

uint8_t Dsply_ArrUi8[] = {0xFC,0x60,0xDA,0xF2,0x66,0xB6,0xBE,0xE0,0xFE,0xF6};
#endif	/* XC_HEADER_TEMPLATE_H */

