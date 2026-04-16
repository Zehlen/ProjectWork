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
        if(DsplySttng.DsplyFlag.StrtDsplyDlyF)
        {
            DsplySttng.DsplyVar.G_DelayCntr_Ui16++;
            if(DsplySttng.DsplyVar.G_DelayCntr_Ui16 > DsplySttng.DsplyVar.G_DelyaCnt_Ui16)
            {
                DsplySttng.DsplyVar.G_DelayCntr_Ui16   = 0;
                DsplySttng.DsplyFlag.TimOutF = true;
                DsplySttng.DsplyFlag.StrtDsplyDlyF = false;
            }
        }
        if(!KeyPadVars.KeyPadFlag.KeyDtctedF)
        {
            KeyPadVars.KeyPadVars.RdPortVal_Ui8 = (PORTB & 0x0f);
            if(KeyPadVars.KeyPadVars.RdPortVal_Ui8 != 0x07)
            {
                KeyPadVars.KeyPadFlag.KeyDtctedF = true;
            }
        }
        else
        {
            KeyPadVars.KeyPadVars.DbnceCntr_Ui8++;
            if(KeyPadVars.KeyPadVars.DbnceCntr_Ui8 > KeyPadVars.KeyPadVars.DbnceCnt_Ui8)
            {
                KeyPadVars.KeyPadVars.DbnceCntr_Ui8 = 0;
                KeyPadVars.KeyPadVars.G_CnfrmkeyVal_Ui8  = (PORTB & 0x0f);
                if(KeyPadVars.KeyPadVars.G_CnfrmkeyVal_Ui8 == KeyPadVars.KeyPadVars.RdPortVal_Ui8)
                {
                    KeyPadVars.KeyPadFlag.KeyPrssF      = true;
                    KeyPadVars.KeyPadVars.RdPortVal_Ui8 = 0;
                }
                else
                {
                    KeyPadVars.KeyPadFlag.KeyDtctedF = false;
                    KeyPadVars.KeyPadVars.G_CnfrmkeyVal_Ui8 = 0;
                }
            }
        }
        if(KeyPadVars.KeyPadFlag.KeyPrssF)
        {
            KeyPadVars.KeyPadVars.RdPortVal_Ui8 = (PORTB & 0x0f);
            if(KeyPadVars.KeyPadVars.RdPortVal_Ui8 == 0x07)
            {
                KeyPad_Un.Key_val = (KeyPadVars.KeyPadVars.G_CnfrmkeyVal_Ui8 & 0x0f);
                KeyPadVars.KeyPadFlag.KeyRelsF   = true;
                KeyPadVars.KeyPadFlag.KeyDtctedF = false;
                KeyPadVars.KeyPadFlag.KeyPrssF   = false;
                KeyPadVars.KeyPadVars.G_CnfrmkeyVal_Ui8 = 0;
            }
        }
    }
}
