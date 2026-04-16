#include "System.h"

void G_PwrOn_Mth(void)
{
    L_Tmr0Confg_Mth();
    L_I2cConfg_Mth();
    L_IntrptConfg_Mth();
}

void L_Tmr0Confg_Mth(void)
{
    TCCR0A = 0x00;
    TCCR0B = (1 << CS00) | (1 << CS01);
    TCNT0  = 0xC3;
}

void L_I2cConfg_Mth(void)
{
    TWCR = 0x00;
    TWSR = 0x00;
    TWCR = (1 << TWEN) | (1 << TWINT);
    TWBR = 0x32;
    
}

void L_IntrptConfg_Mth(void)
{
    TIMSK0 = 0x00;
    TIMSK0 = (1 << TOIE0);
    TWCR  |= (1 << TWIE);
    sei();
}