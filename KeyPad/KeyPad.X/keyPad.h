/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef KEY_PAD_H
#define	KEY_PAD_H

#include "System_Struck.h"

#define DEFAULT_KEY   0x07

#define KEY_PORT  PORTB

uint8_t Key_Indx[] = {0x76,0x75,0x6F,0x6D,0x6B,0x5F,0x5D,0x5B,0x3E,0x3D,0x3B};
uint8_t KeyScan_Indx[] = {0x70,0x68,0x58,0x38};

#endif	/* XC_HEADER_TEMPLATE_H */

