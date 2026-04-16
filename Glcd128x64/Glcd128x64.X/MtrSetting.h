/*
 * MtrSetting.h
 *
 *  Created on: Nov 9, 2024
 *      Author: 91865
 */

#ifndef INC_MTRSETTING_H_
#define INC_MTRSETTING_H_

#include "struck_system.h"
#include "extern_graphics.h"
#include "system.h"

_ValOfKey_Un KeyVal_Un;
_KeyPadvars KeyPadVars;

void G_SetDutyCycle(void);
void G_CaltErrInPress_Mth(void);
void G_GetKeyVal_Mth(void);
#endif /* INC_MTRSETTING_H_ */