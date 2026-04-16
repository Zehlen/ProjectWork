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
        if(!PLStrct.PLFlags.G_SystmDly_F)
        {
            PLStrct.PLVars.G_SystmDlyCntr_Ui8++;
            if(PLStrct.PLVars.G_SystmDlyCntr_Ui8 > PLStrct.PLVars.G_SystmDlyCnt_Ui8)
            {
                PLStrct.PLVars.G_SystmDlyCntr_Ui8 = 0;
                PLStrct.PLFlags.G_SystmDly_F      = true;
                CLCK_EN_RB2 = 0;
            }
        }
        if(PLStrct.PLFlags.G_SystmDly_F && !PLStrct.PLFlags.G_ShftRgrBsy_F)
        {
            PLStrct.PLFlags.G_DataSet_F = true;
            /*CLCK_IN_RB3 = 1;
            asm("NOP");
            asm("NOP");
            asm("NOP");
            PLStrct.PLVars.G_CrrntVal_Ui8 |= DS_OUT_PB0 << (--PLStrct.PLVars.G_BitCntr_Ui8);
            asm("NOP");
            asm("NOP");
            asm("NOP");
            CLCK_IN_RB3 = 0;
            if(PLStrct.PLVars.G_BitCntr_Ui8 <= 0)
            {
                PLStrct.PLVars.G_BitCntr_Ui8 = 8;
                if(PLStrct.PLVars.G_PrivsVal_Ui8 != PLStrct.PLVars.G_CrrntVal_Ui8)
                {
                    PORTD = PLStrct.PLVars.G_CrrntVal_Ui8;
                    //PORTEbits.RE0 = ~PORTEbits.RE0;
                    PLStrct.PLVars.G_PrivsVal_Ui8 = PLStrct.PLVars.G_CrrntVal_Ui8;
                }
                PLStrct.PLVars.G_CrrntVal_Ui8 = 0;
            }*/
        }
    }
}
