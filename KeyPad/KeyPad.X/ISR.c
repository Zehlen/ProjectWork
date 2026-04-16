#include "ISR.h"

void __interrupt() ISR()
{
    if(INTCONbits.INTE && INTCONbits.INTF)
    {
        INTCONbits.INTF = 0;
    }
    if(INTCONbits.T0IE && INTCONbits.T0IF)
    {
        INTCONbits.T0IF = 0;
        TMR0 = 0x05;
        if(!KeyPadVars.KeyFlags.KeyPressd_F)
        {
            if(!KeyPadVars.KeyFlags.KeyDetctd_F)
            {
                KeyPadVars.KeyPad.KeyVal_Ui8 = KEY_PORT & DEFAULT_KEY;
                if(KeyPadVars.KeyPad.KeyVal_Ui8 != DEFAULT_KEY)
                {
                    KeyPadVars.KeyFlags.KeyDetctd_F = true;
                }
            }
            else
            {
                KeyPadVars.KeyPad.DbuncCntr_Ui8++;
                if(KeyPadVars.KeyPad.DbuncCntr_Ui8 > KeyPadVars.KeyPad.DbuncCnt_Ui8)
                {
                    KeyPadVars.KeyPad.DbuncCntr_Ui8 = 0;
                    KeyPadVars.KeyPad.CnfrmKeyVal_Ui8 = KEY_PORT & DEFAULT_KEY;
                    if(KeyPadVars.KeyPad.CnfrmKeyVal_Ui8 == KeyPadVars.KeyPad.KeyVal_Ui8)
                    {
                        KeyPadVars.KeyPad.CnfrmKeyVal_Ui8 = KEY_PORT;
                        KeyPadVars.KeyFlags.KeyPressd_F = true;
                    }
                    KeyPadVars.KeyPad.KeyVal_Ui8 = 0;
                    KeyPadVars.KeyFlags.KeyDetctd_F = false;
                }
            }
        }
        if(KeyPadVars.KeyFlags.KeyPressd_F)
        {
            KeyPadVars.KeyPad.KeyRlseCntr_Ui8++;
            if(KeyPadVars.KeyPad.KeyRlseCntr_Ui8 > KeyPadVars.KeyPad.KeyRlseCnt_Ui8)
            {
                KeyPadVars.KeyPad.KeyRlseCntr_Ui8 = 0;
                KeyPadVars.KeyFlags.KeyPressd_F = false;
                KeyPadVars.KeyFlags.KeyDetctd_F = false;
                KeyPadVars.KeyPad.KeyVal_Ui8 = KEY_PORT & DEFAULT_KEY;
                if(KeyPadVars.KeyPad.KeyVal_Ui8 == DEFAULT_KEY)
                {
                    KeyPadVars.KeyFlags.KeyRelse_F  = true;
                    KeyPadVars.KeyPad.CrrntKeyVal_Ui8 = KeyPadVars.KeyPad.CnfrmKeyVal_Ui8;
                }
            }
        }
        if(!KeyPadVars.KeyFlags.KeyDetctd_F)
        {
            KEY_PORT = KeyScan_Indx[KeyPadVars.KeyPad.KeyScanIndx_Ui8];
            KeyPadVars.KeyPad.KeyScanIndx_Ui8++;
            if(KeyPadVars.KeyPad.KeyScanIndx_Ui8 > 3)
            {
                KeyPadVars.KeyPad.KeyScanIndx_Ui8 = 0;
            }
        }
    }
    if(PIE1bits.TXIE && PIR1bits.TXIF)
    {
        //PIR1bits.TXIF = 0;
        if(TXSTAbits.TRMT)
        {  
            if(UartVars.Uart.BytesSend_ui8 < UartVars.Uart.Bytes2Send_ui8)
            {
                TXREG = UartVars.Uart.TxBuffr_Ui8[UartVars.Uart.BytesSend_ui8];
                UartVars.Uart.BytesSend_ui8++;
            }
            else
            {
                TXSTAbits.TXEN = 0;
                //UartVars.Uart.BytesSend_ui8 = 0;
                UartVars.UartFlags.TxCmplt_F = true;
            }
        }
    }
}

