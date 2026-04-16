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

#include "config.h"

#define CS1_RC0 PORTCbits.RC0
#define CS2_RC1 PORTCbits.RC1
#define RST_PC2 PORTCbits.RC2
#define DATA_PORT PORTD

#define EN_RE0 PORTEbits.RE0
#define RW_RE1 PORTEbits.RE1
#define RS_RE2 PORTEbits.RE2

void G_PowrOn_Mth(void);
void PortConfig_Mth(void);
void TmrConfig_Mth(void);
void IntrptConfig_Mth(void);

// TODO Insert appropriate #include <>

// TODO Insert C++ class definitions if appropriate

// TODO Insert declarations

// Comment a function and leverage automatic documentation with slash star star
/**
    <p><b>Function prototype:</b></p>
  
    <p><b>Summary:</b></p>

    <p><b>Description:</b></p>

    <p><b>Precondition:</b></p>

    <p><b>Parameters:</b></p>

    <p><b>Returns:</b></p>

    <p><b>Example:</b></p>
    <code>
 
    </code>

    <p><b>Remarks:</b></p>
 */
// TODO Insert declarations or function prototypes (right here) to leverage 
// live documentation

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */

