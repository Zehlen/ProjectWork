#include "ISR.h"

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
        if(OledStrct.OledFlags.G_DlyStrt_F)
        {
            OledStrct.OledVars.G_DlyCntr_Ui16++;
            if(OledStrct.OledVars.G_DlyCntr_Ui16 > OledStrct.OledVars.G_DlyCnt_Ui16)
            {
                OledStrct.OledFlags.G_DlyStrt_F   = false;
                OledStrct.OledFlags.G_DlyTimOut_F = true;
                OledStrct.OledVars.G_DlyCntr_Ui16 = 0;
            }
        }
    }
    if(PIE1bits.SSPIE && PIR1bits.SSPIF)
    {
        PIR1bits.SSPIF = false;
        I2cStrct.I2cFlags.G_I2cBusy_F = false;
        if(I2cStrct.I2cFlags.G_RedWrtSclt_F == WrtSclt)
        {
            DATA_REG = *(L_PtrDataBuffr_Ui8)++;
            I2cStrct.I2cVars.G_DataCntr_Ui16++;
        }
    }
}