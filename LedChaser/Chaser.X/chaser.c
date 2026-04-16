#include "chaser.h"

void G_ReadData_Mth(void)
{
    if(PLStrct.PLFlags.G_DataSet_F)
    {
        PLStrct.PLVars.G_BitCntr_Ui8  = 7;
        PLStrct.PLVars.G_CrrntVal_Ui8 = 0;
        PLStrct.PLFlags.G_ShftRgrBsy_F = true;
        PL_EN_RB1 = 1;
        for(;PLStrct.PLVars.G_BitCntr_Ui8 >= 0 ; PLStrct.PLVars.G_BitCntr_Ui8--)
        {
            CLCK_IN_RB3 = 0;
            PLStrct.PLVars.G_CrrntVal_Ui8 |= DS_OUT_PB0 << PLStrct.PLVars.G_BitCntr_Ui8;
            CLCK_IN_RB3 = 1;
            if(PLStrct.PLVars.G_BitCntr_Ui8 == 0)
            {
                break;
            }
        }
        if(PLStrct.PLVars.G_PrivsVal_Ui8 != PLStrct.PLVars.G_CrrntVal_Ui8)
        {
             G_SetData_Mth(PLStrct.PLVars.G_CrrntVal_Ui8);
            PLStrct.PLVars.G_PrivsVal_Ui8 = PLStrct.PLVars.G_CrrntVal_Ui8;
        }
        PLStrct.PLFlags.G_DataSet_F   = false;
        PLStrct.PLFlags.G_ShftRgrBsy_F = false;
        PL_EN_RB1 = 0;
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



void L_SetUsDly(uint8_t L_DlyCnt_Ui8)
{
    uint8_t L_DlyCntr_Ui8 = 0;
    for( ;L_DlyCntr_Ui8 < L_DlyCnt_Ui8; L_DlyCntr_Ui8++)
    {
        asm("NOP");
    }
}