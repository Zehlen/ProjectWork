#include "Oled.h"
#include "Message.h"

void G_OledInitCmd_Mth(void)
{
    if(!OledStrct.OledFlags.G_DsplyBusy_F)
    {
        I2cStrct.I2cVars.G_I2cBuffr_Ui8[0]  = 0xAE; // Display OFF
        I2cStrct.I2cVars.G_I2cBuffr_Ui8[1]  = 0xD5; // Set display clock/oscillator frequency
        I2cStrct.I2cVars.G_I2cBuffr_Ui8[2]  = 0x80; // Parameter
        I2cStrct.I2cVars.G_I2cBuffr_Ui8[3]  = 0xA8; // Set multiplex ratio
        I2cStrct.I2cVars.G_I2cBuffr_Ui8[4]  = 0x3F; // Parameter: 0x3F = 63 -> 64MUX (for 128x64)
        I2cStrct.I2cVars.G_I2cBuffr_Ui8[5]  = 0xD3; // Set display offset
        I2cStrct.I2cVars.G_I2cBuffr_Ui8[6]  = 0x00; // Parameter
        I2cStrct.I2cVars.G_I2cBuffr_Ui8[7]  = 0x40; // Set display start line = 0
        I2cStrct.I2cVars.G_I2cBuffr_Ui8[8]  = 0x8D; // Charge pump
        I2cStrct.I2cVars.G_I2cBuffr_Ui8[9]  = 0x14; // Enable
        I2cStrct.I2cVars.G_I2cBuffr_Ui8[10] = 0x20; // Memory addressing mode
        I2cStrct.I2cVars.G_I2cBuffr_Ui8[11] = 0x00; // parameter : Select horizontal addressing mode
        I2cStrct.I2cVars.G_I2cBuffr_Ui8[12] = 0xA0; // Segment remap (0xA0/0xA1)
        I2cStrct.I2cVars.G_I2cBuffr_Ui8[13] = 0xC0; // COM output scan direction (0xC0/0xC8)
        I2cStrct.I2cVars.G_I2cBuffr_Ui8[14] = 0xDA; // Set COM pins hardware configuration
        I2cStrct.I2cVars.G_I2cBuffr_Ui8[15] = 0x12; // Parameter for 128x64
        I2cStrct.I2cVars.G_I2cBuffr_Ui8[16] = 0x81; // Set contrast
        I2cStrct.I2cVars.G_I2cBuffr_Ui8[17] = 0xCF; // Parameter
        I2cStrct.I2cVars.G_I2cBuffr_Ui8[18] = 0xD9; // Set pre-charge period
        I2cStrct.I2cVars.G_I2cBuffr_Ui8[19] = 0xF1; // Parameter
        I2cStrct.I2cVars.G_I2cBuffr_Ui8[20] = 0xDB; // Set VCOMH deselect level
        I2cStrct.I2cVars.G_I2cBuffr_Ui8[21] = 0x40; // Parameter
        I2cStrct.I2cVars.G_I2cBuffr_Ui8[22] = 0xA4; // Entire display ON (resume from RAM)
        I2cStrct.I2cVars.G_I2cBuffr_Ui8[23] = 0xA6; // Normal display (not inverted)
        I2cStrct.I2cVars.G_I2cBuffr_Ui8[24] = 0xAF; // Display ON
        I2cStrct.I2cVars.G_I2cBuffr_Ui8[25] = _ARRYTRMENTR; // End of array
        I2cStrct.I2cFlags.G_TrsnmsonSclt_F  = CntsBytSclt;
        I2cStrct.I2cFlags.G_ScltDataOrCmd_F = CmdSclt;
    }
    L_I2c_Mstr_Wrt(SSD1306_I2C_ADDR,I2cStrct.I2cVars.G_I2cBuffr_Ui8,25);
    if(I2cStrct.I2cFlags.G_StpCmplt_F)
    {
        I2cStrct.I2cFlags.G_StpCmplt_F    = false;
        OledStrct.OledFlags.G_OledInit_F  = true;
        OledStrct.OledFlags.G_DsplyBusy_F = false;
    }
}

void G_WrtDsplyCmd_Mth(uint8_t L_DsplyCmd_ui8)
{
    I2cStrct.I2cVars.G_I2cBuffr_Ui8[0]  = L_DsplyCmd_ui8;
    I2cStrct.I2cFlags.G_ScltDataOrCmd_F = CmdSclt;
    L_I2c_Mstr_Wrt(SSD1306_I2C_ADDR,I2cStrct.I2cVars.G_I2cBuffr_Ui8,1);
    if(I2cStrct.I2cFlags.G_StpCmplt_F)
    {
        I2cStrct.I2cFlags.G_StpCmplt_F = false;
        I2cStrct.I2cFlags.G_WrtCmplt_F = true;
    }
}

void G_ClrDsply_Mth(uint8_t L_DevAddress_Ui8,uint16_t L_Size_Ui8)
{
    I2cStrct.I2cVars.G_TotalBytsToWrt_Ui16 = L_Size_Ui8;
    if(!I2cStrct.I2cFlags.G_I2cBusy_F)
    {
        I2cStrct.I2cFlags.G_I2cBusy_F = true;
        switch(I2cStrct.I2cVars.G_I2cEvnt_Ui8)
        {
            case _STRT_EV:
                __START_ENBL();
                I2cStrct.I2cFlags.G_StrtCmplt_F   = true;
                I2cStrct.I2cVars.G_I2cEvnt_Ui8    = _SEND_ADDRS_EV;
                OledStrct.OledFlags.G_DsplyBusy_F = true;
            break;
            case _SEND_ADDRS_EV:
                DATA_REG = L_DevAddress_Ui8;
                I2cStrct.I2cVars.G_I2cEvnt_Ui8 = _WRTE_OPRTN_EV;
            break;
            case _WRTE_OPRTN_EV:
                DATA_REG = __WRT_DATA();
                I2cStrct.I2cVars.G_I2cEvnt_Ui8 = _DATA_WRT_EV;
            break;
            case _DATA_WRT_EV:
                DATA_REG = 0xFF;
//                PIR1bits.SSPIF = 1;
                I2cStrct.I2cVars.G_DataCntr_Ui16++;
                if(I2cStrct.I2cVars.G_DataCntr_Ui16 >= I2cStrct.I2cVars.G_TotalBytsToWrt_Ui16)
                {
                    I2cStrct.I2cVars.G_DataCntr_Ui16 = 0;
                    I2cStrct.I2cFlags.G_RedWrtSclt_F = StpRdWrt;
                    I2cStrct.I2cVars.G_I2cEvnt_Ui8   = _STOP_EV;
                }
            break;
            case _STOP_EV:
                __STOP_ENBL();
                I2cStrct.I2cVars.G_I2cEvnt_Ui8    = _STRT_EV;
                I2cStrct.I2cFlags.G_StpCmplt_F    = true;
                OledStrct.OledFlags.G_DsplyBusy_F = false;
                I2cStrct.I2cFlags.G_WrtCmplt_F    = true;
            break;
        }
    }
}
void G_WrtMssg_Mth(uint8_t L_MssgNum_Ui8,uint8_t L_XPostn_Ui8)
{
    uint8_t TmpData         = 0;
    uint8_t L_FontIndex_Ui8 = 0;
    uint8_t L_FontSize_Ui8  = 0;
    uint8_t L_ClmCntr_Ui8   = 0;
    uint8_t L_I2cBffrCntr   = 0;
    uint8_t L_FontData_Ui8  = 0;
    switch(OledStrct.OledVars.G_WrtMssgEv_Ui8)
    {
        case CLRBUFFR:
            L_ClrBuffr_Mth();
            OledStrct.OledVars.G_WrtMssgEv_Ui8 = MSSGLEN;
        break;
        case MSSGLEN:
            OledStrct.OledVars.G_MssgLenght_Ui8 = L_GetMssgLn_Fun(L_MssgNum_Ui8);
            OledStrct.OledVars.G_WrtMssgEv_Ui8  = SET_MSSG_ADDRS;
        break;
        case SET_MSSG_ADDRS:
            I2cStrct.I2cVars.G_I2cBuffr_Ui8[0] = L_XPostn_Ui8;
            L_I2c_Mstr_Wrt(SSD1306_I2C_ADDR,I2cStrct.I2cVars.G_I2cBuffr_Ui8,1);
            if(I2cStrct.I2cFlags.G_StpCmplt_F)
            {
                I2cStrct.I2cFlags.G_StpCmplt_F     = false;
                OledStrct.OledVars.G_WrtMssgEv_Ui8 = FLLI2CBUFFR;
            }
        break;
        case FLLI2CBUFFR:
            TmpData         = AppMessages[L_MssgNum_Ui8][OledStrct.OledVars.G_WrdCntr_Ui8++];
            L_FontIndex_Ui8 = TmpData - ' ';
            L_FontSize_Ui8  = CalibriFontSize[L_FontIndex_Ui8];
            L_ClmCntr_Ui8   = 0;
            L_FontData_Ui8  = 0;
            L_I2cBffrCntr   = OledStrct.OledVars.G_MssgOffst_Ui8;
            for(;L_ClmCntr_Ui8 < L_FontSize_Ui8; L_ClmCntr_Ui8++)
            {
                L_FontData_Ui8 = Font7x10[L_FontIndex_Ui8][L_ClmCntr_Ui8];
                I2cStrct.I2cVars.G_I2cBuffr_Ui8[L_I2cBffrCntr++] = L_FontData_Ui8;
                if(L_I2cBffrCntr >= I2CBUFFR_LMT)
                {
                    break;
                }
            }
            OledStrct.OledVars.G_MssgOffst_Ui8   = L_I2cBffrCntr;
            if(OledStrct.OledVars.G_WrdCntr_Ui8 >= OledStrct.OledVars.G_MssgLenght_Ui8)
            {
                OledStrct.OledVars.G_WrtMssgEv_Ui8  = WRTI2CBUFFR; 
            }
        break;
        case WRTI2CBUFFR:
//            I2cStrct.I2cFlags.G_RedWrtSclt_F    = WrtSclt;
            I2cStrct.I2cFlags.G_ScltDataOrCmd_F = DataSclt;
            I2cStrct.I2cFlags.G_TrsnmsonSclt_F  = CntsBytSclt;
            L_I2c_Mstr_Wrt(SSD1306_I2C_ADDR,I2cStrct.I2cVars.G_I2cBuffr_Ui8,OledStrct.OledVars.G_MssgOffst_Ui8);
            if(I2cStrct.I2cFlags.G_StpCmplt_F)
            {
                OledStrct.OledVars.G_MssgOffst_Ui8  = 0;
                OledStrct.OledVars.G_DataOffset_Ui8 = 0;
                I2cStrct.I2cFlags.G_WrtCmplt_F      = true;
                I2cStrct.I2cFlags.G_StpCmplt_F      = false;
            }
            
        break;
    }
}


void L_I2c_Mstr_Wrt(uint8_t L_DevAddress_Ui8,const uint8_t *L_TempPtr_Ui8,uint16_t L_Size_Ui8)
{
    I2cStrct.I2cVars.G_TotalBytsToWrt_Ui16 = L_Size_Ui8;
    if(!I2cStrct.I2cFlags.G_I2cBusy_F)
    {
        I2cStrct.I2cFlags.G_I2cBusy_F = true;
        switch(I2cStrct.I2cVars.G_I2cEvnt_Ui8)
        {
            case _STRT_EV:
                __START_ENBL();
                I2cStrct.I2cFlags.G_StrtCmplt_F   = true;
                I2cStrct.I2cVars.G_I2cEvnt_Ui8    = _SEND_ADDRS_EV;
                OledStrct.OledFlags.G_DsplyBusy_F = true;
            break;
            case _SEND_ADDRS_EV:
                DATA_REG = L_DevAddress_Ui8;
                I2cStrct.I2cVars.G_I2cEvnt_Ui8 = _WRTE_OPRTN_EV;
            break;
            case _WRTE_OPRTN_EV:
                L_PtrDataBuffr_Ui8               = L_TempPtr_Ui8;
                I2cStrct.I2cFlags.G_RedWrtSclt_F = WrtSclt;
                if(I2cStrct.I2cFlags.G_ScltDataOrCmd_F == DataSclt)
                {
                    DATA_REG = __WRT_DATA();
                }
                if(I2cStrct.I2cFlags.G_ScltDataOrCmd_F == CmdSclt)
                {
                    DATA_REG = __WRT_CMD();
                }
                I2cStrct.I2cVars.G_I2cEvnt_Ui8 = _DATA_WRT_EV;
            break;
            case _DATA_WRT_EV:
//                PIR1bits.SSPIF = 1;
                if(I2cStrct.I2cVars.G_DataCntr_Ui16 >= I2cStrct.I2cVars.G_TotalBytsToWrt_Ui16)
                {
                    I2cStrct.I2cVars.G_DataCntr_Ui16 = 0;
                    I2cStrct.I2cFlags.G_RedWrtSclt_F = StpRdWrt;
                    I2cStrct.I2cVars.G_I2cEvnt_Ui8   = _STOP_EV;
                }
                if(I2cStrct.I2cVars.G_DataCntr_Ui16 == 0)
                {
                    
                }
            break;
            case _STOP_EV:
                __STOP_ENBL();
                I2cStrct.I2cVars.G_I2cEvnt_Ui8    = _STRT_EV;
                I2cStrct.I2cFlags.G_StpCmplt_F    = true;
                OledStrct.OledFlags.G_DsplyBusy_F = false;
            break;
        }
    }
}

uint8_t L_GetMssgLn_Fun(uint8_t L_MssgNum_Ui8)
{
    uint8_t L_DataCntr = 0;
    uint8_t L_ClmnCntr = 0;
    uint8_t L_RwCntr   = L_MssgNum_Ui8;
    for(;AppMessages[L_RwCntr][L_ClmnCntr] != '\0'; L_ClmnCntr++)
    {
        L_DataCntr++;
    }
    return L_DataCntr;
}

void L_ClrBuffr_Mth(void)
{
    uint8_t L_Cntr_Ui8 = 0;
    for(;I2cStrct.I2cVars.G_I2cBuffr_Ui8[L_Cntr_Ui8] != _ARRYTRMENTR;L_Cntr_Ui8++)
    {
        I2cStrct.I2cVars.G_I2cBuffr_Ui8[L_Cntr_Ui8]   = 0x00;
    }
}