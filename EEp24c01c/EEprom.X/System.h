/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef SYSTEM_H
#define	SYSTEM_H

#include "System_Struck.h"

void G_PowerOn_Mth(void);
void L_I2cConfig_Mth(void);
void L_PortConfig_Mth(void);
void L_TmrConfig_Mth(void);
void L_IntrrptCnf(void);

#endif	/* XC_HEADER_TEMPLATE_H */