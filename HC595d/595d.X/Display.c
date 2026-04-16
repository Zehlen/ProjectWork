#include "Display.h"

void G_SwtchDsply(void)
{
    switch(DsplySttng.DsplyVar.G_DsplyEvnt_Ui8)
    {
        case RST_EVENT:
            DsplySttng.DsplyVar.G_DsplyData_Ui8 = DsplyVal_ArrUi8[0];
            G_SetData_Mth(DsplySttng.DsplyVar.G_DsplyData_Ui8); 
            OE_ERC3 = 0;
            PORTD   = KeyPad_Un.Key_val;
            DS_RC1  = 0;
            DsplySttng.DsplyVar.G_DsplyEvnt_Ui8 = DETEC_KEY;
        break;
        case DETEC_KEY:
            if(!KeyPad_Un.KeyPadFalg.IncKeyF)
            {
                KeyPad_Un.Key_val = 7;
                KeyPadVars.KeyPadVars.KeyValCntr_ui16++;
                DsplySttng.DsplyFlag.StrtDsplyDlyF = true;
                DsplySttng.DsplyVar.G_DsplyEvnt_Ui8 = SWTCH_SGMNT;
            }
            if(!KeyPad_Un.KeyPadFalg.DncKeyF)
            {
                if(KeyPadVars.KeyPadVars.KeyValCntr_ui16 != 0)
                {
                    KeyPad_Un.Key_val = 7;
                    KeyPadVars.KeyPadVars.KeyValCntr_ui16--;
                    DsplySttng.DsplyFlag.StrtDsplyDlyF = true;
                    DsplySttng.DsplyVar.G_DsplyEvnt_Ui8 = SWTCH_SGMNT;
                }
                else
                {
                    KeyPad_Un.Key_val = 7;
                    KeyPadVars.KeyPadVars.KeyValCntr_ui16 = 0;
                    DsplySttng.DsplyVar.G_DsplyEvnt_Ui8 = RST_EVENT;
                }
            }
            if(!KeyPad_Un.KeyPadFalg.RstKeyF)
            {
                KeyPad_Un.Key_val = 7;
                DsplySttng.DsplyVar.G_DsplyEvnt_Ui8 = RST_EVENT;
            }
            if(KeyPadVars.KeyPadVars.KeyValCntr_ui16 != 0)
            {
                if(KeyPadVars.KeyPadVars.KeyValCntr_ui16 <= 999)
                {
                    DsplySttng.DsplyVar.G_UintCntr_Ui8  = KeyPadVars.KeyPadVars.KeyValCntr_ui16 % 10;
                    DsplySttng.DsplyVar.G_TenCntr_Ui8   = (KeyPadVars.KeyPadVars.KeyValCntr_ui16 % 100)/10;
                    DsplySttng.DsplyVar.G_HndrdCntr_Ui8 = (uint8_t)KeyPadVars.KeyPadVars.KeyValCntr_ui16 / 100;
                }
                else
                {
                    KeyPadVars.KeyPadVars.KeyValCntr_ui16 = 0;
                    DsplySttng.DsplyVar.G_DsplyEvnt_Ui8 = RST_EVENT;
                }
            }
            else
            {
                KeyPadVars.KeyPadVars.KeyValCntr_ui16 = 0;
                DsplySttng.DsplyVar.G_DsplyEvnt_Ui8 = RST_EVENT;
            }
            if(KeyPadVars.KeyPadFlag.KeyRelsF)
            {
                KeyPadVars.KeyPadFlag.KeyRelsF = false;
            }
        break;
        case SWTCH_SGMNT:
            if(DsplySttng.DsplyFlag.TimOutF)
            {
                DsplySttng.DsplyFlag.TimOutF = false;
                L_SwtchDsply(); 
                DsplySttng.DsplyFlag.StrtDsplyDlyF = true;
            }
        break;
        case EXCPTN:
            HUNDRD_PD2 = 0;
            TEN_PD1    = 0;
            UINT_PD0   = 0;
            DsplySttng.DsplyVar.G_DsplyEvnt_Ui8 = DETEC_KEY;
        break;
    }
}

void L_SwtchDsply(void)
{
    switch(DsplySttng.DsplyVar.G_ScltDigit_Ui8)
    {
        case DIGIT_1:
            TEN_PD1    = 0;
            HUNDRD_PD2 = 0;
            OE_ERC3 = 1;
            DsplySttng.DsplyVar.G_DsplyData_Ui8 = DsplyVal_ArrUi8[DsplySttng.DsplyVar.G_UintCntr_Ui8];
            G_SetData_Mth(DsplySttng.DsplyVar.G_DsplyData_Ui8);
            OE_ERC3 = 0;
            UINT_PD0   = 1;
            DsplySttng.DsplyVar.G_ScltDigit_Ui8 = DIGIT_2;
        break;
        case DIGIT_2:
            OE_ERC3 = 1;
            DsplySttng.DsplyVar.G_DsplyData_Ui8 = DsplyVal_ArrUi8[DsplySttng.DsplyVar.G_TenCntr_Ui8];
            G_SetData_Mth(DsplySttng.DsplyVar.G_DsplyData_Ui8);
            OE_ERC3    = 0;
            TEN_PD1    = 1;
            UINT_PD0   = 0;
            DsplySttng.DsplyVar.G_ScltDigit_Ui8 = DIGIT_3;
        break;
        case DIGIT_3: 
            OE_ERC3 = 1;
            DsplySttng.DsplyVar.G_DsplyData_Ui8 = DsplyVal_ArrUi8[DsplySttng.DsplyVar.G_HndrdCntr_Ui8];
            G_SetData_Mth(DsplySttng.DsplyVar.G_DsplyData_Ui8);
            OE_ERC3 = 0;
            HUNDRD_PD2 = 1;
            TEN_PD1    = 0;
            UINT_PD0   = 0;
            DsplySttng.DsplyVar.G_ScltDigit_Ui8 = DIGIT_1;
        break;
    }
    if(KeyPadVars.KeyPadFlag.KeyRelsF)
    {
        KeyPadVars.KeyPadFlag.KeyRelsF = false;
        DsplySttng.DsplyVar.G_DsplyEvnt_Ui8 = DETEC_KEY;
    }
}


void G_SetData_Mth(uint8_t L_Data_Ui8)
{
    uint8_t L_BitPstn[] = {1,2,4,8,16,32,64,128};
    for(uint8_t L_BytCntr = 0; L_BytCntr < 1; L_BytCntr++)
    {
        for(uint8_t L_BitCntr = 0; L_BitCntr < 8; L_BitCntr++)
        {
            if((L_BitPstn[L_BitCntr] & L_Data_Ui8) == L_BitPstn[L_BitCntr])
            {
                DS_RC1 = 1;
            }
            else
            {
                DS_RC1= 0;
            }
            asm("NOP");
            asm("NOP");
            SHCP_RC0= 1;
            asm("NOP");
            asm("NOP");
            SHCP_RC0= 0;
        }
    }
    STCP_RC2= 1;
    asm("NOP");
    asm("NOP");
    STCP_RC2= 0;
}
