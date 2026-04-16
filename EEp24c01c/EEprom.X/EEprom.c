#include "EEprom.h"

void L_WriteEEprom_Mth(void)
{
    switch(I2cVars.I2cData.G_I2cEvnt_Ui8)
    {
        case _STRT_EV:
            if(I2cVars.I2cFlags.I2cBusy_F)
            {
                I2cVars.I2cFlags.I2cBusy_F = false;
                __START_ENBL();
                I2cVars.I2cData.G_I2cEvnt_Ui8 = _WRTE_OPRTN_EV;
            }
        break;
        case _WRTE_OPRTN_EV:
            if(I2cVars.I2cFlags.I2cBusy_F)
            {
                I2cVars.I2cFlags.I2cBusy_F = false;
                DATA_REG = __WRIT_OPRTN();
                I2cVars.I2cData.G_I2cEvnt_Ui8 = _SEND_ADDRS_EV;
            }
        break;
        case _READ_OPRTN_EV:
            if(I2cVars.I2cFlags.I2cBusy_F)
            {
                I2cVars.I2cFlags.I2cBusy_F = false;
                DATA_REG = __READ_OPRTN();
                I2cVars.I2cData.G_I2cEvnt_Ui8 = _RECV_ENBL_EV;
            }
        break;
        case _RECV_ENBL_EV:
            if(I2cVars.I2cFlags.I2cBusy_F)
            {
                I2cVars.I2cFlags.I2cBusy_F = false;
                __RECV_ENBL();
                I2cVars.I2cData.G_I2cEvnt_Ui8 = _DATA_RD_EV;
            }
        break;
        case _SEND_ADDRS_EV:
            if(I2cVars.I2cFlags.I2cBusy_F)
            {
                I2cVars.I2cFlags.I2cBusy_F = false;
                DATA_REG = (uint8_t)I2cVars.I2cData.G_CrrntAddrs_Ui16;
                I2cVars.I2cData.G_I2cEvnt_Ui8 = _DATA_WRT_EV;
                if(I2cVars.I2cFlags.ScltEEpOprtn == RdSclt)
                {
                    I2cVars.I2cData.G_I2cEvnt_Ui8 = _REPT_EV;
                }
            }
        break;
        case _DATA_WRT_EV:
            if(!I2cVars.I2cFlags.PageCmplt_F)
            {
                if(I2cVars.I2cFlags.I2cBusy_F)
                {
                    I2cVars.I2cFlags.I2cBusy_F = false;
                    L_WrtEEpData_Mth();
                }
            }
            if(I2cVars.I2cFlags.PageCmplt_F)
            {
                I2cVars.I2cFlags.PageCmplt_F = false;
                if(I2cVars.I2cData.G_PageWrttn <= I2cVars.I2cData.G_TotalPageToWrt)
                {
                    I2cVars.I2cData.G_I2cEvnt_Ui8 = _STOP_EV;
                }
            }
        break;
        case _DATA_RD_EV:
            if(__BUFFRFULL_STAT())
            {
                L_RwdEEpData_Mth();
                if(!I2cVars.I2cFlags.PageCmplt_F)
                {
                    __RECV_ENBL();
                }
            }
            if(I2cVars.I2cFlags.PageCmplt_F)
            {
                I2cVars.I2cFlags.PageCmplt_F = false;
                if(I2cVars.I2cData.G_PageWrttn <= I2cVars.I2cData.G_TotalPageToWrt)
                {
                    I2cVars.I2cData.G_I2cEvnt_Ui8 = _STOP_EV;
                    I2cVars.I2cFlags.I2cBusy_F = true;
                }
            }
        break;
        case _REPT_EV:
            if(I2cVars.I2cFlags.I2cBusy_F)
            {
                I2cVars.I2cFlags.I2cBusy_F = false;
                __REPT_ENBL();
                I2cVars.I2cData.G_I2cEvnt_Ui8 = _READ_OPRTN_EV;
            }
        break;
        case _STOP_EV:
            if(I2cVars.I2cFlags.I2cBusy_F)
            {
                I2cVars.I2cFlags.I2cBusy_F = false;
                __STOP_ENBL();
                I2cVars.I2cData.G_I2cEvnt_Ui8 = _STRT_EV;
                if(I2cVars.I2cFlags.ScltEEpOprtn == WrtScl)
                {
                    if(I2cVars.I2cData.G_DataCntr_Ui16 == I2cVars.I2cData.TotalBytsToWrt_Ui16)
                    {
                        I2cVars.I2cData.G_CrrntAddrs_Ui16 = 0;
                        I2cVars.I2cData.G_StrtAddrs_Ui16 = 0;
                        I2cVars.I2cData.G_PageWrttn = 0;
                        I2cVars.I2cData.G_DataCntr_Ui16 = 0;
                        I2cVars.I2cFlags.WrtCmplt_F = true;
                        L_SetUsDly(10);
                    }
                    else
                    {
                        L_SetUsDly(10);
                    }
                }
                if(I2cVars.I2cFlags.ScltEEpOprtn == RdSclt)
                {
                    if(I2cVars.I2cData.G_DataCntr_Ui16 == I2cVars.I2cData.TotalBytsToRd_Ui16)
                    {
                        I2cVars.I2cData.G_CrrntAddrs_Ui16 = 0;
                        I2cVars.I2cData.G_StrtAddrs_Ui16 = 0;
                        I2cVars.I2cData.G_PageWrttn = 0;
                        I2cVars.I2cData.G_DataCntr_Ui16 = 0;
                        I2cVars.I2cFlags.RdCmplt_F = true;
                        L_SetUsDly(5);
                    }
                    else
                    {
                        L_SetUsDly(5);
                    }
                }
            }
        break;
    }
}

void G_WrtDataEep_Mth(void)
{
    I2cVars.I2cData.G_StrtAddrs_Ui16 = 5;
    I2cVars.I2cData.TotalBytsToWrt_Ui16 = L_CalcLenOFData_Mth();
    I2cVars.I2cData.G_EndAddrs_Ui16 = I2cVars.I2cData.G_StrtAddrs_Ui16 + I2cVars.I2cData.TotalBytsToWrt_Ui16;
    I2cVars.I2cData.G_TotalPageToWrt = (uint8_t)(I2cVars.I2cData.G_StrtAddrs_Ui16 + I2cVars.I2cData.G_EndAddrs_Ui16)/PAGE_LIMIT;
    I2cVars.I2cData.G_CrrntAddrs_Ui16 = I2cVars.I2cData.G_StrtAddrs_Ui16;
    I2cVars.I2cFlags.ScltEEpOprtn = WrtScl;
}

void G_RwdDataEep_Mth(void)
{
    I2cVars.I2cData.G_StrtAddrs_Ui16 = 5;
    I2cVars.I2cData.TotalBytsToRd_Ui16 = I2cVars.I2cData.TotalBytsToWrt_Ui16;
    I2cVars.I2cData.G_EndAddrs_Ui16 = I2cVars.I2cData.G_StrtAddrs_Ui16 + I2cVars.I2cData.TotalBytsToRd_Ui16;
    I2cVars.I2cData.G_TotalPageToWrt = (uint8_t)(I2cVars.I2cData.G_StrtAddrs_Ui16 + I2cVars.I2cData.G_EndAddrs_Ui16)/PAGE_LIMIT;
    I2cVars.I2cData.G_CrrntAddrs_Ui16 = I2cVars.I2cData.G_StrtAddrs_Ui16;
    I2cVars.I2cFlags.ScltEEpOprtn = RdSclt;
}

void L_WrtEEpData_Mth(void)
{
    uint16_t L_PageLmt = 0;
    DATA_REG = I2cVars.I2cData.G_I2cBuffr_Ui8[I2cVars.I2cData.G_DataCntr_Ui16];
    I2cVars.I2cData.G_DataCntr_Ui16++;
    I2cVars.I2cData.G_CrrntAddrs_Ui16++;
    L_PageLmt = (I2cVars.I2cData.G_StrtAddrs_Ui16 + I2cVars.I2cData.G_DataCntr_Ui16) % PAGE_LIMIT;
    if(L_PageLmt == 0)
    {
        I2cVars.I2cFlags.PageCmplt_F = true;
        I2cVars.I2cData.G_PageWrttn++;
        
//        I2cVars.I2cData.G_StrtAddrs_Ui16 = 0;
    }
    if(I2cVars.I2cData.G_DataCntr_Ui16 == I2cVars.I2cData.TotalBytsToWrt_Ui16)
    {
        I2cVars.I2cFlags.PageCmplt_F = true;
    }
}

void L_RwdEEpData_Mth(void)
{
    uint16_t L_PageLmt = 0;
    I2cVars.I2cData.G_I2cBuffr_Ui8[I2cVars.I2cData.G_DataCntr_Ui16] = DATA_REG;
    I2cVars.I2cData.G_DataCntr_Ui16++;
    I2cVars.I2cData.G_CrrntAddrs_Ui16++;
    L_PageLmt = (I2cVars.I2cData.G_StrtAddrs_Ui16 + I2cVars.I2cData.G_DataCntr_Ui16) % PAGE_LIMIT;
    if(L_PageLmt == 0)
    {
        I2cVars.I2cFlags.PageCmplt_F = true;
        I2cVars.I2cData.G_PageWrttn++;
        asm("NOP");
        asm("NOP");
        __NACK_ENBL();
//        I2cVars.I2cData.G_StrtAddrs_Ui16 = 0;
    }
    if(I2cVars.I2cData.G_DataCntr_Ui16 == I2cVars.I2cData.TotalBytsToRd_Ui16)
    {
        I2cVars.I2cFlags.PageCmplt_F = true;
        __NACK_ENBL();
        asm("NOP");
        asm("NOP");
    }
    __ACK_ENBL();
}

uint16_t L_CalcLenOFData_Mth(void)
{
    uint16_t L_DataCntr_Ui16 = 0;
    uint8_t My_Data[] = {"Everthing works out in the end."};
    for(;My_Data[L_DataCntr_Ui16] != '\0';L_DataCntr_Ui16++)
    {
        I2cVars.I2cData.G_I2cBuffr_Ui8[L_DataCntr_Ui16] = My_Data[L_DataCntr_Ui16];
    }
    return L_DataCntr_Ui16;
}

void G_ClrBuffr_Mth(void)
{
    uint16_t L_DataCntr_Ui16 = 0;
    for(;I2cVars.I2cData.G_I2cBuffr_Ui8[L_DataCntr_Ui16] != '\0';L_DataCntr_Ui16++)
    {
        I2cVars.I2cData.G_I2cBuffr_Ui8[L_DataCntr_Ui16] = 0;
    }
}
