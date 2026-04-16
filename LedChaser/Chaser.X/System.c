#include "System.h"

void G_PwrOn_Mth(void)
{
    L_PrtCnfg();
    L_TmrCnfg();
    L_IntrrptCnfg();
}

void L_TmrCnfg(void)
{
    OPTION_REG  = 0x00;
    OPTION_REG |= _OPTION_REG_nRBPU_MASK | _OPTION_REG_PS0_MASK;
    TMR0        = 0x05;
}

void L_PrtCnfg(void)
{
    PORTB  = 0x00;
    PORTC  = 0x00;
    TRISB  = 0x01;
    TRISC  = 0x00;
    ANSELH = 0x00;
}

void L_IntrrptCnfg(void)
{
    INTCON  = 0x00;
    INTCON |= _INTCON_GIE_MASK | _INTCON_PEIE_POSN | _INTCON_T0IE_MASK ;
}