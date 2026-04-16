/*
 * File:   main.c
 * Author: 91865
 *
 * Created on February 2, 2025, 8:03 AM
 */


#include "main.h"

void main(void) {
    DsplySttng.DsplyVar.G_DelyaCnt_Ui16 = 40;
    G_PowerOn_Mth();
    OE_ERC3= 1;
    SHCP_RC0= 0;
    STCP_RC2= 0;
    KeyPadVars.KeyPadVars.DbnceCnt_Ui8 = 9;
    //DsplySttng.DsplyVar.G_DsplyData_Ui8 = 0x60;
    KeyPad_Un.Key_val = 7;
    while(1)
    {
        /*if(DsplySttng.DsplyFlag.OneSecFlag)
        {
            DsplySttng.DsplyFlag.OneSecFlag = false;
            G_SetData_Mth(DsplySttng.DsplyVar.G_DsplyData_Ui8);
            OE_ERC3 = 0;
        }*/
        G_SwtchDsply();
    }
}