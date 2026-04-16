#include "ISR.h"
#include "EEprom.h"

void __interrupt() ISR()
{
    if(INTCONbits.INTE && INTCONbits.INTF)
    {
        INTCONbits.INTF = 0;
    }
    if(INTCONbits.T0IE && INTCONbits.T0IF)
    {
        TMR0 = 0x05;
        INTCONbits.T0IF = 0;
        if(LcdCnfig.LcdFlags.G_DelayStrt_F)
        {
            LcdCnfig.LcdVars.G_DelayCntr_Ui8++;
            if(LcdCnfig.LcdVars.G_DelayCntr_Ui8 > LcdCnfig.LcdVars.G_DelayCnt_Ui8)
            {
                LcdCnfig.LcdFlags.G_DelayStrt_F = false;
                LcdCnfig.LcdFlags.G_TimeOut_F   = true;
            }
        }
    }
    if(PIE1bits.SSPIE && PIR1bits.SSPIF)
    {
        PIR1bits.SSPIF = false;
        I2cVars.I2cFlags.I2cBusy_F = true;
    }
}
