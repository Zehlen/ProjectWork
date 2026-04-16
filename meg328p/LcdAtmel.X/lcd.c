#include "lcd.h"

volatile __LcdStrk LcdStrk;
volatile __I2cStrk I2cStrk;

const uint8_t MessgArr_Ui8[][43] = {
    {"A"},
    {"Every computer is broken"},
    {"All this happen when you forget who you are"}
};

void G_LcdInit1_Mth(void)
{
    if(LcdStrk.LcdFlgas.TimOut_F)
    {
        LcdStrk.LcdFlgas.TimOut_F = false;
        switch(LcdStrk.LcdVars.LcdInitEvnt_Ui8)
        {
            case INIT_DELAY:
                LcdStrk.LcdVars.DlyCnt_Ui16      = 16;
                LcdStrk.LcdVars.DlyCntr_Ui16     = 0;
                LcdStrk.LcdFlgas.DlyStrt_F      = true;
                LcdStrk.LcdVars.LcdInitEvnt_Ui8 = LCD_STTING;
            break;
            case LCD_STTING:
                LcdStrk.LcdVars.DlyCnt_Ui16     = 5;
                LcdStrk.LcdVars.DlyCntr_Ui16    = 0;
                LcdStrk.LcdFlgas.DlyStrt_F      = true;
                LcdStrk.LcdVars.DataBffr_Ui8[0] = FUNCTN_SET;
                LcdStrk.LcdVars.DataBffr_Ui8[1] = MODE_4BIT;
                LcdStrk.LcdVars.DataBffr_Ui8[2] = CLR_DSPLY;
                LcdStrk.LcdVars.DataBffr_Ui8[3] = CURSR_ON;
                LcdStrk.LcdVars.DataBffr_Ui8[4] = ENTRY_MODE;
                L_RdWrtI2c_Mth(_ADDRS_WRT,_SET_CMD,4);
                if(I2cStrk.I2cFlags.StpCmplt_F)
                {
                    LcdStrk.LcdFlgas.LcdInit_F  = true;
                    I2cStrk.I2cFlags.StpCmplt_F = false;
                    LcdStrk.LcdFlgas.TimOut_F   = true;
                }
            break;
        }
    }
}

void L_RdWrtI2c_Mth(uint8_t L_DevAddrs_Ui8,uint8_t L_ScltCmdorData ,uint16_t L_TotlByts_Ui16)
{
    I2cStrk.I2cVars.DevAddrs_Ui8      = L_DevAddrs_Ui8;
    I2cStrk.I2cFlags.DataCmdSclt_F    = L_ScltCmdorData;
    I2cStrk.I2cVars.TotlByts2wrt_Ui16 = L_TotlByts_Ui16;
    if(!I2cStrk.I2cFlags.StpCmplt_F)
    {
        __STRT_I2C();
    }
}

void G_LcdDataWrt_Mth(uint8_t L_MssgNum_ui8)
{
    uint8_t L_BytCntr  = 0 , L_BuffrCntr = 0, L_Limit = 16;
    if((!I2cStrk.I2cFlags.StrtCmplt_F) && (!I2cStrk.I2cFlags.StpCmplt_F))
    {
        for(; MessgArr_Ui8[L_MssgNum_ui8][L_BytCntr] != '\0'; L_BytCntr++)
        {
            LcdStrk.LcdVars.DataBffr_Ui8[L_BuffrCntr] = 0;
            LcdStrk.LcdVars.DataBffr_Ui8[L_BuffrCntr++] = MessgArr_Ui8[L_MssgNum_ui8][L_BytCntr];
            if(L_BuffrCntr == L_Limit)
            {
                if(L_BuffrCntr == 16)
                {
                    LcdStrk.LcdVars.DataBffr_Ui8[L_BuffrCntr] = 0xC0;
                    L_Limit = L_Limit * 2;
                }
                if(L_BuffrCntr == 32)
                {
                    LcdStrk.LcdVars.DataBffr_Ui8[L_BuffrCntr] = 0x80;
                    L_Limit = 16;
                }
                L_BuffrCntr++;
            }
        }
        I2cStrk.I2cVars.TotlByts2wrt_Ui16 = L_BytCntr;
    }
    if(LcdStrk.LcdFlgas.TimOut_F)
    {
        LcdStrk.LcdFlgas.TimOut_F    = false;
        LcdStrk.LcdVars.DlyCnt_Ui16  = 5;
        LcdStrk.LcdVars.DlyCntr_Ui16 = 0;
        LcdStrk.LcdFlgas.DlyStrt_F   = true;
        if(I2cStrk.I2cVars.BytsCntr_Ui16 != 16 && I2cStrk.I2cVars.BytsCntr_Ui16 != 32)
        {
            L_RdWrtI2c_Mth(_ADDRS_WRT,_SET_DATA,I2cStrk.I2cVars.TotlByts2wrt_Ui16);
        }
        else
        {
            if(I2cStrk.I2cVars.BytsCntr_Ui16 == 32)
            {
                LcdStrk.LcdVars.DlyCnt_Ui16 = 999;
            }
            L_RdWrtI2c_Mth(_ADDRS_WRT,_SET_CMD,I2cStrk.I2cVars.TotlByts2wrt_Ui16);
        }
        if(I2cStrk.I2cFlags.StpCmplt_F)
        {
            I2cStrk.I2cFlags.StpCmplt_F = false;
            I2cStrk.I2cFlags.WrtCmplt_F = true;
        }
    }
}