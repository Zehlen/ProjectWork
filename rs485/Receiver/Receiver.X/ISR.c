#include "ISR.h"

void __interrupt() ISR()
{
    if(INTCONbits.T0IE && INTCONbits.T0IF)
    {
        INTCONbits.T0IF = 0;
        TMR0 = 0x05;
    }
    
    if (PIE1bits.RCIE && PIR1bits.RCIF)
    {
        UartStrk.UartVars.G_RxBuffr_Ui8Ptr[UartStrk.UartVars.G_RxBytCntr_Ui8] = RCREG;
        UartStrk.UartVars.G_RxBytCntr_Ui8++;
    }
}
