/*
 * File:   main.c
 * Author: Malcolm.X
 *
 * Created on March 19, 2025, 3:36 PM
 */


#include "main.h"

void main(void) {
    
    G_PowerOn_Mth();
    KeyPadVars.KeyPad.DbuncCnt_Ui8 = 9;
    KeyPadVars.KeyPad.KeyRlseCnt_Ui8 = 20;
    while(1)
    {
        if(KeyPadVars.KeyFlags.KeyRelse_F)
        {
            KeyPadVars.KeyFlags.KeyRelse_F = false;
            PORTDbits.RD0 = ~PORTDbits.RD0;
            UartVars.Uart.UartData_Ui8 = KeyPadVars.KeyPad.CrrntKeyVal_Ui8;
            CrtTxData();
            TXSTAbits.TXEN = 1;
        }
        if(UartVars.UartFlags.TxCmplt_F)
        {
            UartVars.UartFlags.TxCmplt_F = false;
            UartVars.Uart.BytesSend_ui8 = 0;
            ClrTxBuffr();
        }
    }
}
