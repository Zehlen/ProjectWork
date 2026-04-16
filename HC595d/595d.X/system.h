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

#include "Config.h" 
#include "system_struck.h"

_DsplySettng DsplySttng;
_KeyPad_Un KeyPad_Un;
_KeyPad KeyPadVars;
#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    void G_PowerOn_Mth(void);
    void L_PortCnfg_Mth(void);
    void L_TmrCnfg(void);
    void L_IntrrptCnf(void);

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */

