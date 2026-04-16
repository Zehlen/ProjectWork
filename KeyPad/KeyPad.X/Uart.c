#include "Uart.h"

void CrtTxData(void)
{
    uint8_t L_LwrNibbl_Ui8  = 0;
    uint8_t L_UpprNibbl_Ui8 = 0;
    UartVars.Uart.TxBuffr_Ui8[0] = 0x30;
    UartVars.Uart.TxBuffr_Ui8[1] = 'x';
    L_LwrNibbl_Ui8  = (UartVars.Uart.UartData_Ui8 & 0x0f);
    L_UpprNibbl_Ui8 = (UartVars.Uart.UartData_Ui8 & 0xf0) >> 0x04;
    if(L_LwrNibbl_Ui8 >= 0x00 && L_LwrNibbl_Ui8 <= 0x09)
    {
        L_LwrNibbl_Ui8 |= 0x30;
    }
    else
    {
        L_LwrNibbl_Ui8 -= 9; 
        L_LwrNibbl_Ui8 |= 0x40;
    }
    if(L_UpprNibbl_Ui8 >= 0x00 && L_UpprNibbl_Ui8 <= 0x09)
    {
        L_UpprNibbl_Ui8 |= 0x30;
    }
    else
    {
        L_UpprNibbl_Ui8 -= 9;
        L_UpprNibbl_Ui8 |= 0x40;
    }
    UartVars.Uart.TxBuffr_Ui8[2] = L_UpprNibbl_Ui8;
    UartVars.Uart.TxBuffr_Ui8[3] = L_LwrNibbl_Ui8;
    UartVars.Uart.Bytes2Send_ui8 = 4;
}

void ClrTxBuffr(void)
{
    uint8_t L_BuffCntr = 0;
    for(;UartVars.Uart.TxBuffr_Ui8[L_BuffCntr] != '\0'; L_BuffCntr++)
    {
        UartVars.Uart.TxBuffr_Ui8[L_BuffCntr] = 0;
    }
}
