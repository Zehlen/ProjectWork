#include "system.h"

void G_PowerOn_Mth(void)
{
    L_PortCnfg_Mth();
    L_TmrCnfg();
    L_IntrrptCnf();
}

void L_PortCnfg_Mth(void)
{
    TRISC  = 0x00;
    TRISD  = 0x00;
    PORTD  = 0X00;
    PORTD  = 0x00;
    TRISB  = 0x07;
    PORTB  = 0x00;
    ANSELH = 0x00;
    WPUB   = 0x00;
    WPUB  |= _WPUB_WPUB0_MASK | _WPUB_WPUB1_MASK | _WPUB_WPUB2_MASK;
}

void L_TmrCnfg(void)
{
    //OSCCON     |=  _OSCCON_IRCF_MASK;
    OPTION_REG  = 0x01;
    TMR0        = 0x05;
}

void L_IntrrptCnf(void)
{
    INTCON  = 0x00;
    INTCON |= _INTCON_GIE_MASK | _INTCON_PEIE_POSN | _INTCON_T0IE_MASK ;
   //IOCB   |= _IOCB_IOCB0_MASK | _IOCB_IOCB1_MASK  | _IOCB_IOCB2_MASK;
    //PIE2   |= _PIE2_ULPWUIE_MASK;
}