/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef DISPLAY_H
#define DISPLAY_H	

#include "System_Struck.h"

_LcdCnfig LcdCnfig;
void G_DsplyInt_Mth(void);
void L_LcdWrite_Mth(uint8_t L_Data_Ui8, uint8_t L_SclInst);
void L_SetUsDly(uint16_t L_CntVal);
void G_WrtData_Mth(void);

#define INIT_DELAY  0x00
#define FUNCTN_SET  0x02   //for interal reset
#define MODE_4BIT   0x28
#define CLR_DSPLY   0x01
#define CURSR_ON    0x0C
#define ENTRY_MODE  0x06

#define INST_MODE  0
#define DATA_MODE  1

#define WRT_EVNT        0
#define RWD_EVNT        1
#define EEP_EVNT        2
#define DSPLYDATA_EVNT  3

#define DATA_PORTD PORTD
#define RS_RE0    PORTEbits.RE0
#define EN_RE1    PORTEbits.RE1

#define LINE_LIMIT  16
#define DSPLY_LIMIT 32
#endif	/* XC_HEADER_TEMPLATE_H */