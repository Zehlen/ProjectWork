/* 
 * File:   SystemStruck.h
 * Author: abdul
 *
 * Created on 29 August, 2025, 2:42 PM
 */

#ifndef SYSTEMSTRUCK_H
#define	SYSTEMSTRUCK_H

#include <stdint.h>

typedef struct __OledVar{
    volatile uint8_t G_WrtMssgEv_Ui8;
    volatile uint8_t G_MssgLenght_Ui8;
    volatile uint8_t G_MssgOffst_Ui8;
    volatile uint8_t G_WrdCntr_Ui8;
    volatile uint8_t G_OledEvnt_Ui8;
    
    volatile uint16_t G_BytsWrtCntr_Ui8;
    volatile uint16_t G_DataOffset_Ui8;
    volatile uint16_t G_NBytsToWrt_Ui16;
    volatile uint16_t G_DlyCntr_Ui16;
    volatile uint16_t G_DlyCnt_Ui16;
    
} _OledVar;

typedef struct __OledFlags
{
    volatile unsigned G_OledInit_F      :1;
    volatile unsigned G_DlyStrt_F       :1;
    volatile unsigned G_DlyTimOut_F     :1;
    volatile unsigned G_DsplyBusy_F     :1;
} _OledFlags;

typedef struct __OledStrct
{
    _OledVar   OledVars;
    _OledFlags OledFlags;
} _OledStrct;

typedef struct __I2cVars
{
    volatile uint16_t G_TotalBytsToWrt_Ui16;
    volatile uint16_t G_TotalBytsToRd_Ui16;
    volatile uint16_t G_DataCntr_Ui16;
    
    uint8_t G_I2cBuffr_Ui8[50];
    volatile uint8_t G_I2cEvnt_Ui8;
    volatile uint8_t L_I2cBuffrCntr_Ui8;
    
} _I2cVars;

typedef struct __I2cFlags
{
   volatile unsigned G_I2cBusy_F               :1;
   volatile unsigned G_StrtCmplt_F             :1;
   volatile unsigned G_StpCmplt_F              :1;
   volatile unsigned G_TrsnmsonSclt_F          :1;
   volatile unsigned G_ReptCmplt_F             :1;
   volatile unsigned G_WrtCmplt_F              :1;
   volatile unsigned G_RdCmplt_F               :1;
   volatile unsigned G_RedWrtSclt_F            :2;
   volatile unsigned G_ScltDataOrCmd_F         :2;
} _I2cFlags;

typedef struct __I2cStrct
{
    _I2cVars  I2cVars;
    _I2cFlags I2cFlags;
} _I2cStrct;

const uint8_t *L_PtrDataBuffr_Ui8;

_I2cStrct I2cStrct;
_OledStrct OledStrct;

#endif	/* SYSTEMSTRUCK_H */

