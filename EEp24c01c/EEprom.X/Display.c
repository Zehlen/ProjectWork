#include "Display.h"
#include "EEprom.h"

void G_DsplyInt_Mth(void)
{
    if(LcdCnfig.LcdFlags.G_TimeOut_F)
    {
        LcdCnfig.LcdFlags.G_TimeOut_F = false;
        switch(LcdCnfig.LcdVars.G_InitEvnt_Ui8)
        {
            case INIT_DELAY:
                LcdCnfig.LcdVars.G_DelayCnt_Ui8  = 19;
                LcdCnfig.LcdVars.G_DelayCntr_Ui8 = 0;
                LcdCnfig.LcdFlags.G_DelayStrt_F  = true;
                LcdCnfig.LcdVars.G_InitEvnt_Ui8  = FUNCTN_SET;
            break;
            case FUNCTN_SET:
                L_LcdWrite_Mth(FUNCTN_SET,INST_MODE);
                LcdCnfig.LcdVars.G_DelayCnt_Ui8  = 5;
                LcdCnfig.LcdVars.G_DelayCntr_Ui8 = 0;
                LcdCnfig.LcdFlags.G_DelayStrt_F  = true;
                LcdCnfig.LcdVars.G_InitEvnt_Ui8  = MODE_4BIT;
            break;
            case MODE_4BIT:
                L_LcdWrite_Mth(MODE_4BIT,INST_MODE);
                LcdCnfig.LcdVars.G_DelayCnt_Ui8  = 5;
                LcdCnfig.LcdVars.G_DelayCntr_Ui8 = 0;
                LcdCnfig.LcdFlags.G_DelayStrt_F  = true;
                LcdCnfig.LcdVars.G_InitEvnt_Ui8  = CLR_DSPLY;
            break;
            case CLR_DSPLY:
                L_LcdWrite_Mth(CLR_DSPLY,INST_MODE);
                LcdCnfig.LcdVars.G_DelayCnt_Ui8  = 5;
                LcdCnfig.LcdVars.G_DelayCntr_Ui8 = 0;
                LcdCnfig.LcdFlags.G_DelayStrt_F  = true;
                LcdCnfig.LcdVars.G_InitEvnt_Ui8  = CURSR_ON;
            break;
            case CURSR_ON:
                L_LcdWrite_Mth(CURSR_ON,INST_MODE);
                LcdCnfig.LcdVars.G_DelayCnt_Ui8  = 5;
                LcdCnfig.LcdVars.G_DelayCntr_Ui8 = 0;
                LcdCnfig.LcdFlags.G_DelayStrt_F  = true;
                LcdCnfig.LcdVars.G_InitEvnt_Ui8  = ENTRY_MODE;
            break;
            case ENTRY_MODE:
                L_LcdWrite_Mth(ENTRY_MODE,INST_MODE);
                LcdCnfig.LcdVars.G_DelayCnt_Ui8  = 5;
                LcdCnfig.LcdVars.G_DelayCntr_Ui8 = 0;
                LcdCnfig.LcdFlags.G_DelayStrt_F  = true;
                LcdCnfig.LcdFlags.G_InitLcd_F = true;
                //LcdCnfig.LcdVars.G_InitEvnt_Ui8 = 5;
            break;
            case 5:
                L_LcdWrite_Mth('H',DATA_MODE);
                LcdCnfig.LcdVars.G_DelayCnt_Ui8  = 5;
                LcdCnfig.LcdVars.G_DelayCntr_Ui8 = 0;
                LcdCnfig.LcdFlags.G_DelayStrt_F  = true;
                LcdCnfig.LcdFlags.G_InitLcd_F = true;
            break;
        }
    }
}

void G_WrtData_Mth(void)
{
    uint8_t L_DataCntr = 0;
    for(; I2cVars.I2cData.G_I2cBuffr_Ui8[L_DataCntr] != '\0'; L_DataCntr++)
    {
        LcdCnfig.LcdVars.G_LcdDataBuff_Ui8[L_DataCntr] = (uint8_t)I2cVars.I2cData.G_I2cBuffr_Ui8[L_DataCntr];
        if(L_DataCntr == LINE_LIMIT)
        {
            L_LcdWrite_Mth(0xC0 ,INST_MODE);
            L_SetUsDly(2);
        }
        L_LcdWrite_Mth(LcdCnfig.LcdVars.G_LcdDataBuff_Ui8[L_DataCntr],DATA_MODE);
        L_SetUsDly(5);
    }
    LcdCnfig.LcdFlags.G_WritCmplt_F = true;
}

void L_LcdWrite_Mth(uint8_t L_Data_Ui8, uint8_t L_SclInst)
{
    if(L_SclInst)
        RS_RE0 = 1;
    else
        RS_RE0 = 0;
    
    DATA_PORTD = (L_Data_Ui8 & 0xF0) >> 0x04;
    EN_RE1 = 1;
    L_SetUsDly(1);
    EN_RE1 = 0;
    
    DATA_PORTD = (L_Data_Ui8 & 0x0F);
    EN_RE1 = 1;
    L_SetUsDly(1);
    EN_RE1 = 0;
}

void L_SetUsDly(uint16_t L_CntVal)
{
    for(uint16_t L_Cntr = 0; L_Cntr < L_CntVal; L_Cntr++)
    {
        asm("NOP");
    }
}
