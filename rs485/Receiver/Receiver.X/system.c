#include "system.h"

void G_PwrOn_Mth(void)
{
    G_PrtCnfg_Mth();
    G_UartCnfg_Mth();
    G_IntrCnfg_Mth();
//    L_TmrCnfig_Mth();
}

void G_PrtCnfg_Mth(void)
{
    TRISE = 0x00;
    PORTE = 0x00;
}

void G_UartCnfg_Mth(void)
{
    TXSTA  = 0x00;
    RCSTA  = 0x00;
    TXSTA  = _TXSTA_BRGH_MASK;
    RCSTA  = _RCSTA_SPEN_MASK | _RCSTA_CREN_MASK;
    SPBRG  = 0x33;
}

void L_TmrCnfig_Mth(void)
{
    OPTION_REG  = 0x01;
    TMR0        = 0x05;
}

void G_IntrCnfg_Mth(void)
{
    INTCON  = 0x00;
    PIE1    = 0x00;
    PIE1    = _PIE1_RCIE_MASK;
    INTCON  = _INTCON_GIE_MASK | _INTCON_PEIE_MASK | _INTCON_T0IE_MASK;
}
