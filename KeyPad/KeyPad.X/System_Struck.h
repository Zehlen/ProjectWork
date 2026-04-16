/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

#ifndef SYSTEM_STRUCK_H
#define	SYSTEM_STRUCK_H

#include <stdint.h>
#include "Config.h"

typedef struct __KeyPad{
    volatile uint8_t DbuncCntr_Ui8;
    volatile uint8_t DbuncCnt_Ui8;
    volatile uint8_t KeyRlseCntr_Ui8;
    volatile uint8_t KeyRlseCnt_Ui8;
    volatile uint8_t KeyRlseFcntr;
    volatile uint8_t KeyVal_Ui8;
    volatile uint8_t CnfrmKeyVal_Ui8;
    volatile uint8_t CrrntKeyVal_Ui8;
    volatile uint8_t KeyScanIndx_Ui8;
} _KeyPad;

typedef struct __KeyFlags{
    volatile unsigned KeyDetctd_F      :1;
    volatile unsigned KeyPressd_F      :1;
    volatile unsigned KeyRelse_F       :1;
    volatile unsigned DbuncCmplt_F     :1;
} _KeyFlags;

typedef struct __KeyPadVars{
    _KeyPad   KeyPad;
    _KeyFlags KeyFlags;
} _KeyPadVars;

typedef struct __Uart{
    volatile uint8_t Bytes2Send_ui8;
    volatile uint8_t BytesSend_ui8;
    volatile uint8_t UartData_Ui8;
    volatile uint8_t TxBuffr_Ui8[4];
} _Uart;

typedef struct __UartFlags{
    volatile unsigned TxStrt_F   :1;
    volatile unsigned TxCmplt_F  :1;
} _UartFlags;

typedef struct __UartVars{
    _Uart      Uart;
    _UartFlags UartFlags;
} _UartVars;

_KeyPadVars KeyPadVars;
_UartVars UartVars;

enum{false,true};

#endif	/* XC_HEADER_TEMPLATE_H */