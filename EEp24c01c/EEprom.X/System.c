#include "System.h"


void G_PowerOn_Mth(void)
{
    L_PortConfig_Mth();
    L_TmrConfig_Mth();
    L_I2cConfig_Mth();
    L_IntrrptCnf();
}

void L_I2cConfig_Mth(void)
{
    SSPCON   = 0x00;
    SSPSTAT  = 0x00;
    SSPCON2  = 0x00;
    SSPCON  |= _SSPCON_SSPEN_MASK | _SSPCON_SSPM3_MASK;
    SSPSTAT |= _SSPSTAT_SMP_MASK;
    SSPADD   = 0x09;
}

void L_PortConfig_Mth(void)
{
    TRISD = 0x00;
    PORTD = 0x00;
    ANSEL = 0x00;
    TRISE = 0x00;
    PORTE = 0x00;
    TRISC = 0x18;
    PORTC = 0x00;
}

void L_TmrConfig_Mth(void)
{
    OPTION_REG  = 0x01;
    TMR0        = 0x05;
}

void L_IntrrptCnf(void)
{
    INTCON  = 0x00;
    PIE1    = 0x00;
    INTCON |= _INTCON_GIE_MASK | _INTCON_PEIE_POSN | _INTCON_T0IE_MASK ;
    PIE1   |= _PIE1_SSPIE_MASK;
}
