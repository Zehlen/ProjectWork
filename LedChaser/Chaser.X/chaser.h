/* 
 * File:   
 * Author: Malcolm.x
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_CHASER_H
#define	XC_CHASER_H

#include "System.h"
#include "System_Struck.h"

void G_ReadData_Mth(void);
void G_SetData_Mth(uint8_t L_Data_Ui8);
void L_SetUsDly(uint8_t L_DlyCnt_Ui8);

#define DS_OUT_PB0  PORTBbits.RB0
#define PL_EN_RB1   PORTBbits.RB1
#define CLCK_EN_RB2 PORTBbits.RB2
#define CLCK_IN_RB3 PORTBbits.RB3

#define SHCP_RC0    PORTCbits.RC0
#define DS_RC1      PORTCbits.RC1
#define STCP_RC2    PORTCbits.RC2
#define OE_ERC3     PORTCbits.RC3

#endif	/* XC_HEADER_TEMPLATE_H */

