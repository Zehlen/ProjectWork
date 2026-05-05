#include "ISR.h"

void __interrupt() ISR()
{
    if(INTCONbits.T0IE && INTCONbits.T0IF)
    {
        INTCONbits.T0IF = 0;
        TMR0 = 0x05;
        if (UartStrk.UartFlags.G_DlyStrt_F) 
        {
            UartStrk.UartVars.G_DlayCntr_Ui8++;
            if(UartStrk.UartVars.G_DlayCntr_Ui8 >  20)
            {
                UartStrk.UartFlags.G_DlyStrt_F    = False;
                UartStrk.UartFlags.G_DlyTimOut_F  = True;
                UartStrk.UartVars.G_DlayCntr_Ui8  = 0;
            }
        }

    }
    
    if (PIE1bits.TXIE && PIR1bits.TXIF)
    {
       if (TXSTAbits.TRMT)
       {
            if (UartStrk.UartVars.G_TxBytCnt_Ui8 >= UartStrk.UartVars.G_TxBytCntr_Ui8) 
            {
                TXREG = UartStrk.UartVars.G_Buffr_Ui8[UartStrk.UartVars.G_TxBytCntr_Ui8];
                UartStrk.UartVars.G_TxBytCntr_Ui8++;
            }
            else
            {
                TXSTAbits.TXEN = 0;
                UartStrk.UartFlags.G_TxCmplt_F = True;
            }
       }
    }
    if (PIE1bits.RCIE && PIR1bits.RCIF) 
    {
        UartStrk.UartVars.G_Buffr_Ui8[UartStrk.UartVars.G_RxBytCntr_Ui8] = RCREG;
        UartStrk.UartVars.G_RxBytCntr_Ui8++;
        if ((RCREG == '\n') || (RCREG == '\r'))
        {
            UartStrk.UartVars.G_Buffr_Ui8[UartStrk.UartVars.G_RxBytCntr_Ui8] = '\n';
            UartStrk.UartVars.G_RxBytCntr_Ui8++;
            UartStrk.UartVars.G_Buffr_Ui8[UartStrk.UartVars.G_RxBytCntr_Ui8] = '\0';
            UartStrk.UartFlags.G_RxCmplt_F = True;
        }

    }

}
