#include "system.h"
void G_PowrOn_Mth(void)
{
    PortConfig_Mth();
    TmrConfig_Mth();
    IntrptConfig_Mth();
}
void PortConfig_Mth(void)
{
    TRISD = 0x00;
    TRISB = 0xf8;
    TRISE = 0xf8;
    TRISC = 0xf8;
    PORTD = 0X00;
    PORTB = 0X00;
    PORTE = 0X00;
    PORTC = 0X00;
    ANSEL = 0x00;
}
void TmrConfig_Mth(void)
{
     OPTION_REG  = 0x81;
     TMR0 = 0x05;
}
void IntrptConfig_Mth(void)
{
   INTCON = 0;
   INTCON = _INTCON_T0IE_MASK | _INTCON_PEIE_MASK | _INTCON_GIE_MASK;
}

