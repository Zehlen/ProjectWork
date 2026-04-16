/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef SYSTEM_STRUCK_H
#define	SYSTEM_STRUCK_H

#include <stdint.h>
#include "Config.h"

typedef struct __LCdVar{
    volatile uint8_t G_DelayCnt_Ui8;
    volatile uint8_t G_DelayCntr_Ui8;
    volatile uint8_t G_InitEvnt_Ui8;
    volatile uint8_t G_SystmEvnt_Ui8;
    
    volatile uint8_t G_LcdDataBuff_Ui8[50];
} _LCdVar;

typedef struct __LcdFlags{
    unsigned G_DelayStrt_F      :1;
    unsigned G_TimeOut_F        :1;
    unsigned G_InitLcd_F        :1;
    unsigned G_WritCmplt_F      :1;
} _LcdFlags;

typedef struct __LcdCnfig{
    _LCdVar   LcdVars;
    _LcdFlags LcdFlags;
} _LcdCnfig;

enum{false,true};

#endif	/* XC_HEADER_TEMPLATE_H */