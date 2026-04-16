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

typedef struct __DsplyVar {
    volatile uint8_t G_ScltDigit_Ui8;
    volatile uint8_t G_DsplyEvnt_Ui8;
    volatile uint8_t G_DsplyData_Ui8;
    volatile uint8_t G_UintCntr_Ui8;
    volatile uint8_t G_TenCntr_Ui8;
    volatile uint8_t G_HndrdCntr_Ui8;
    
    volatile uint16_t G_DelyaCnt_Ui16;
    volatile uint16_t G_DelayCntr_Ui16;
} _DsplyVar;

typedef struct __DsplyFlag {
    volatile unsigned TimOutF        :1;
    volatile unsigned StrtDsplyDlyF  :1;
} _DsplyFlag;


typedef struct __DsplySettng {
    _DsplyVar  DsplyVar;
    _DsplyFlag DsplyFlag;
} _DsplySettng;

typedef struct __KeyPadVars{
    volatile uint8_t RdPortVal_Ui8;
    volatile uint8_t KeyCntr_Ui8;
    volatile uint8_t DbnceCntr_Ui8;
    volatile uint8_t DbnceCnt_Ui8;
    volatile uint8_t G_CnfrmkeyVal_Ui8;
    
    volatile uint16_t KeyValCntr_ui16;
} _KeyPadVars;

typedef struct __KeyPadFlags{
    volatile unsigned IncKeyF       :1;
    volatile unsigned DncKeyF       :1;
    volatile unsigned RstKeyF       :1;
    volatile unsigned KeyDtctedF    :1;
    volatile unsigned KeyPrssF      :1;
    volatile unsigned KeyRelsF      :1;
} _KeyPadFlags;

typedef struct __KeyPad{
    _KeyPadVars KeyPadVars;
    _KeyPadFlags KeyPadFlag;
} _KeyPad;

typedef union __KeyPad_Un{
    volatile unsigned Key_val    :3;
    _KeyPadFlags KeyPadFalg;
}_KeyPad_Un;

#define UINT_PD0     PORTDbits.RD0
#define TEN_PD1      PORTDbits.RD1
#define HUNDRD_PD2   PORTDbits.RD2


#define SHCP_RC0    PORTCbits.RC0
#define DS_RC1      PORTCbits.RC1
#define STCP_RC2    PORTCbits.RC2
#define OE_ERC3     PORTCbits.RC3

#define RST_EVENT   0
#define DETEC_KEY   1
#define SWTCH_SGMNT 2
#define EXCPTN      3

#define DIGIT_CNT   10
#define UNIT_CNT    10
#define TEN_CNT     100
#define HUNDRD_CNT  1000

#define DIGIT_1     0
#define DIGIT_2     1
#define DIGIT_3     2

enum {false,true};
enum {False,True};
#endif	/* XC_HEADER_TEMPLATE_H */

