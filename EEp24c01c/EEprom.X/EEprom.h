/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H

#include "System.h"
#include "Display.h"
#include "EEpromDefs.h"

typedef struct __I2C{
    volatile uint16_t G_StrtAddrs_Ui16;
    volatile uint16_t G_CrrntAddrs_Ui16;
    volatile uint16_t G_EndAddrs_Ui16;
    volatile uint16_t TotalBytsToWrt_Ui16;
    volatile uint16_t TotalBytsToRd_Ui16;
    volatile uint16_t G_DataCntr_Ui16;
    
    volatile uint8_t G_I2cBuffr_Ui8[50];
    volatile uint8_t G_I2cEvnt_Ui8;
    volatile uint8_t G_PageWrttn;
    volatile uint8_t G_TotalPageToWrt;
} _I2C; 

typedef struct __I2CFlags{
    unsigned I2cBusy_F          :1;
    unsigned StrtCmplt_F        :1;
	unsigned StopCmplt_F        :1;
    unsigned ReptCmplt_F        :1;
    unsigned AckStat_F          :1;
    unsigned ScltEEpOprtn       :1;
    unsigned WrtCmplt_F         :1;
    unsigned RdCmplt_F          :1;
    unsigned PageCmplt_F        :1;
    unsigned EvntSclt_F         :3;
} _I2CFlag;

typedef struct __I2CVars{
    _I2C  I2cData;
    _I2CFlag I2cFlags;
} _I2CVars;

_I2CVars  I2cVars;

void L_WriteEEprom_Mth(void);
void G_WrtDataEep_Mth(void);
void L_WrtEEpData_Mth(void);
void L_RwdEEpData_Mth(void);
void G_RwdDataEep_Mth(void);
void G_ClrBuffr_Mth(void);
uint16_t L_CalcLenOFData_Mth(void);

#define __START_ENBL()  (SSPCON2   = _SSPCON2_SEN_MASK)
#define __STOP_ENBL()   (SSPCON2   = _SSPCON2_PEN_MASK)
#define __REPT_ENBL()   (SSPCON2   = _SSPCON2_RSEN_MASK)
#define __RECV_ENBL()   (SSPCON2   = _SSPCON2_RCEN_MASK)
#define __ACK_ENBL()    (SSPCON2  |= _SSPCON2_ACKEN_MASK)
#define __NACK_ENBL()   (SSPCON2   = _SSPCON2_ACKDT_MASK)

#define __STRT_CMPLT()      (!SSPCON2bits.SEN)
#define __STOP_CMPLT()      (!SSPCON2bits.PEN)
#define __REPT_CMPLT()      (!SSPCON2bits.RSEN)
#define __ACKSTAT_BIT()     (!SSPCON2bits.ACKSTAT)
#define __BUFFRFULL_STAT()  (SSPSTATbits.BF)
#define __BUS_STATS()       (PORTCbits.RC3 & PORTCbits.RC4)

#define DATA_REG          SSPBUF
#define __READ_OPRTN()    (0b10100001)
#define __WRIT_OPRTN()    (0b10100000)

#define _STRT_EV           0x00
#define _WRTE_OPRTN_EV     0x01
#define _READ_OPRTN_EV     0x02
#define _DATA_WRT_EV       0x03
#define _DATA_RD_EV        0x04
#define _ACK_EV            0x05
#define _STOP_EV           0x06
#define _REPT_EV           0x07
#define _SEND_ADDRS_EV     0x08
#define _RECV_ENBL_EV      0x09

enum{WrtScl,RdSclt};
enum{unsngd,StrtEvnt,AckEvnt,StopEvnt,ReptEvnt};
#endif	/* XC_HEADER_TEMPLATE_H */

