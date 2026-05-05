#include "main.h"

int main(void)
{
    G_PwrOn_Mth();
    UartStrk.UartFlags.G_DlyStrt_F = True;
    while(1)
    {
        if (UartStrk.UartFlags.G_DlyTimOut_F) 
        {
            PORTEbits.RE0 = 1;
            if (UartStrk.UartFlags.G_RxCmplt_F) 
            {
                UartStrk.UartFlags.G_RxCmplt_F    = False;
                UartStrk.UartVars.G_TxBytCnt_Ui8  = UartStrk.UartVars.G_RxBytCntr_Ui8;
                UartStrk.UartVars.G_TxBytCntr_Ui8 = 0;
                TXSTAbits.TXEN = 1;
            }
            if (UartStrk.UartFlags.G_TxCmplt_F) 
            {
                UartStrk.UartFlags.G_TxCmplt_F    = False;
                UartStrk.UartVars.G_RxBytCntr_Ui8 = 0;
                G_ClrBuffr_Mth();
            }
        }
    }
    return 0;
}

void G_ClrBuffr_Mth(void)
{
    RCSTAbits.CREN = 0;
    uint8_t L_BytCntr_Ui8 = 0;
    for(; UartStrk.UartVars.G_Buffr_Ui8[L_BytCntr_Ui8] != '\0'; L_BytCntr_Ui8++)
    {
        UartStrk.UartVars.G_Buffr_Ui8[L_BytCntr_Ui8] = 0;
    }
    RCSTAbits.CREN = 1;
}