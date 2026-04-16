#include "ISR.h"

void __interrupt() ISR()
{
    if(INTCONbits.INTE && INTCONbits.INTE)
    {
       INTCONbits.INTF = 0;
    }
    if(INTCONbits.TMR0IE && INTCONbits.TMR0IF)
    {  
        INTCONbits.T0IF = 0;
        TMR0 = 0X05;
        if(graphics.StartDelayCount)
        {
            graphics.Delay_counter_Ui16 ++;
            if(graphics.Delay_counter_Ui16 > graphics.Delay_count_Ui16)
            {
                graphics.Delay_counter_Ui16=0;
                graphics.DelayTimeout = true;
                graphics.StartDelayCount = false;
            }
        }
    }
}
