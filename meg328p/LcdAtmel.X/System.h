/* 
 * File:   System.h
 * Author: Malcolm.x
 *
 * Created on 21 December, 2025, 7:45 AM
 */

#ifndef SYSTEM_H
#define	SYSTEM_H

#include "config.h"
#include "avr/interrupt.h"

void G_PwrOn_Mth(void);
void L_Tmr0Confg_Mth(void);
void L_IntrptConfg_Mth(void);
void L_I2cConfg_Mth(void);

#endif	/* SYSTEM_H */

