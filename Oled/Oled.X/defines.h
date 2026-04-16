/* 
 * File:   defines.h
 * Author: abdul
 *
 * Created on 29 August, 2025, 2:42 PM
 */

#ifndef DEFINES_H
#define	DEFINES_H

#include "System.h"

#define __START_ENBL()  (SSPCON2   = _SSPCON2_SEN_MASK)
#define __STOP_ENBL()   (SSPCON2   = _SSPCON2_PEN_MASK)
#define __REPT_ENBL()   (SSPCON2   = _SSPCON2_RSEN_MASK)
#define __RECV_ENBL()   (SSPCON2   = _SSPCON2_RCEN_MASK)
#define __ACK_ENBL()    (SSPCON2  |= _SSPCON2_ACKEN_MASK)
#define __NACK_ENBL()   (SSPCON2   = _SSPCON2_ACKDT_MASK)

#define DATA_REG          SSPBUF
#define __READ_OPRTN()    (0b01111001)
#define __WRIT_OPRTN()    (0b01111000)
#define __WRT_DATA()      (0b01000000) //CO D?C 000000  D/C = 1 Data.0x40 
#define __WRT_CMD()       (0b00000000) //CO D?C 000000  D/C = 0 Cmd. 0x00

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
#define _CNTRL_BYTE        0x0A

#define _ARRYTRMENTR       0x2E

enum {Prsvr,WrtSclt,RdSclt,StpRdWrt};
enum {DataSclt,CmdSclt};
enum {CntsBytSclt,SnglBytSclt};
enum {False, True};
enum {false,true};

#endif	/* DEFINES_H */

