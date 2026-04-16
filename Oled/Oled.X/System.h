/* 
 * File:   System.h
 * Author: abdul
 *
 * Created on 29 August, 2025, 9:20 AM
 */

#ifndef SYSTEM_H
#define	SYSTEM_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "config.h"

void G_PowerOn_Mth(void);
void L_I2cConfig_Mth(void);
void L_PortConfig_Mth(void);
void L_TmrConfig_Mth(void);
void L_IntrrptCnf(void);


#ifdef	__cplusplus
}
#endif

#endif	/* SYSTEM_H */

