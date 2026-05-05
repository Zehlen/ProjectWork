/* 
 * File:   systmstrk.h
 * Author: Malcolm.X
 *
 * Created on 3 May, 2026, 8:36 AM
 */

#ifndef SYSTMSTRK_H
#define	SYSTMSTRK_H

typedef struct __UartVars
{
    volatile uint8_t G_RxBytCntr_Ui8;
    volatile uint8_t G_RxBytCnt_Ui8;
    volatile uint8_t G_RxBuffr_Ui8Ptr[50];
} _UartVars;

typedef struct __UartFlags
{
    volatile unsigned G_RxCmplt_F      :1;
    volatile unsigned G_RxStrt_F       :1;
} _UartFlags;

typedef struct __UartStrk
{
    _UartVars  UartVars;
    _UartFlags UartFlags;
} _UartStrk;

_UartStrk UartStrk;

enum{
    False,
    True
};

#endif	/* SYSTMSTRK_H */

