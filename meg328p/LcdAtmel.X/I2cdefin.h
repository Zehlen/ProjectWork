/* 
 * File:   I2cdefin.h
 * Author: Malcolm.x
 *
 * Created on 27 December, 2025, 10:51 AM
 */

#ifndef I2CDEFIN_H
#define	I2CDEFIN_H

#include "System.h"

/*-----------------------------------------*/

#define __STRT_I2C()  (TWCR  = (1 << TWSTA) | (1 << TWINT) | (1 << TWIE) | (1 << TWEN))
#define __STP_I2C()   (TWCR  = (1 << TWSTO) | (1 << TWINT) | (1 << TWEN))
#define __DATA_REG    TWDR

/*------------------------------------------*/

/*-----------------------------------------*/
#define _STRT_EV               0x00
#define _SCLT_DATAORCMD_EV     0x01
#define _DATA_WRT_EV           0x02
#define _DATA_RD_EV            0x03
#define _ACK_EV                0x04
#define _STOP_EV               0x05
#define _REPT_EV               0x06
#define _SEND_ADDRS_EV         0x07
#define _RECV_ENBL_EV          0x08
#define _CNTRL_BYTE            0x09
#define _ADDRS_WRT             0x4E // address with write operation LSD = 0 
#define _ADDRS_RED             0x8F // address with read operation LSD = 1

/*---------------------------------------*/

/*---------------------------------*/

#define _SET_CMD     0x00
#define _SET_DATA    0x01
#define _RS_POSTN    0x00
#define _EN_POSTN    0x02

/*--------------------------------*/

enum{False, True};
enum{false, true};
enum{RedSclt, WrtSclt};
enum{CmdSclt, DataSclt};

#endif	/* I2CDEFIN_H */

