#include "System.h"


void G_PowerOn_Mth(void)
{
    L_PortCnfig_Mth();
    L_TmrCnfig_Mth();
    L_UartCnfig_Mth();
    L_IntrrptCnf();
}

void L_PortCnfig_Mth(void)
{
    TRISB  = 0x00;
    PORTB  = 0x00;
    TRISD  = 0x00;
    PORTD  = 0x00;
    ANSELH = 0x00;
    WPUB   = 0x00;
    TRISB |= _TRISB_TRISB0_MASK | _TRISB_TRISB1_MASK | _TRISB_TRISB2_MASK;
    WPUB  |= _WPUB_WPUB0_MASK | _WPUB_WPUB1_MASK | _WPUB_WPUB2_MASK;
}

void L_TmrCnfig_Mth(void)
{
    OPTION_REG  = 0x01;
    TMR0        = 0x05;
}

void L_UartCnfig_Mth(void)
{
    RCSTA  = 0x00;
    TXSTA  = 0x04;
    RCSTA  = _RCSTA_SPEN_MASK;
    SPBRG  = 0x19;
}

void L_IntrrptCnf(void)
{
    INTCON  = 0x00;
    PIE1    = 0x00;
    PIE1    = _PIE1_TXIE_MASK;
    INTCON |= _INTCON_GIE_MASK | _INTCON_PEIE_MASK | _INTCON_T0IE_MASK;
}
