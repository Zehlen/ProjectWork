/* 
 * File:   Sysstruck.h
 * Author: Malcolm.x
 *
 * Created on 27 December, 2025, 11:21 AM
 */

#ifndef SYSSTRUCK_H
#define	SYSSTRUCK_H

#include <stdint.h>

typedef struct _LcdVar
{
    volatile uint16_t DlyCnt_Ui16;
    volatile uint16_t DlyCntr_Ui16;
    
    volatile uint8_t LcdInitEvnt_Ui8;
    volatile uint8_t LcdEnvt_ui8;
    volatile uint8_t DataByte_Ui8;
    volatile uint8_t DataBffr_Ui8[50];
} __LcdVar;

typedef struct _LcdFlags
{
    volatile unsigned DlyStrt_F    :1;
    volatile unsigned TimOut_F     :1;
    volatile unsigned LcdInit_F    :1;
} __LcdFlags;

typedef struct _LcdStrk 
{
    __LcdVar LcdVars;
    __LcdFlags LcdFlgas;
} __LcdStrk;

typedef struct _I2cVars
{
    volatile uint8_t I2cEvnt_Ui8;
    volatile uint8_t DevAddrs_Ui8;
    volatile uint8_t LwrNibbl_Ui8;
    volatile uint8_t UpprNibbl_Ui8;
    
    volatile uint16_t TotlByts2wrt_Ui16;
    volatile uint16_t TotlByts2Red_Ui16;
    volatile uint16_t BytsCntr_Ui16;
} __I2cVars;

typedef struct _I2cFlags
{
    volatile unsigned I2cBusy_F      :1;
    volatile unsigned StrtCmplt_F    :1;
    volatile unsigned StpCmplt_F     :1;
    volatile unsigned WrtCmplt_F     :1;
    volatile unsigned DataCmdSclt_F  :1;
} __I2cFlags;

typedef struct _I2cStrk
{
    __I2cVars I2cVars;
    __I2cFlags I2cFlags;
} __I2cStrk;

extern volatile __LcdStrk LcdStrk;
extern volatile __I2cStrk I2cStrk;

#endif	/* SYSSTRUCK_H */

