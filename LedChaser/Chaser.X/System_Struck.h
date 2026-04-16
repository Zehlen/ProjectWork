/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_SYSTEM_STRUCK_H
#define	XC_SYSTEM_STRUCK_H

#include <stdint.h>

typedef struct __PLvars
{
    volatile uint8_t G_BitCntr_Ui8;
    volatile uint8_t G_CrrntVal_Ui8;
    volatile uint8_t G_PrivsVal_Ui8;
    volatile uint8_t G_SystmDlyCntr_Ui8;
    volatile uint8_t G_SystmDlyCnt_Ui8;
} _PLvars;

typedef struct __PlFlags
{
    volatile unsigned G_DataSet_F    :1;
    volatile unsigned G_SystmDly_F   :1;
    volatile unsigned G_ShftRgrBsy_F :1;
} _PlFlags;

typedef struct __PLStrct
{
    _PLvars  PLVars;
    _PlFlags PLFlags;
} _PLStrct;

_PLStrct PLStrct;

enum {false,true};
enum {False,True};
#endif	/* XC_HEADER_TEMPLATE_H */

