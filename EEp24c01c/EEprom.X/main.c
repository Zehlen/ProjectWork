/*
 * File:   main.c
 * Author: 91865
 *
 * Created on March 19, 2025, 3:36 PM
 */


#include "main.h"

void main(void) {
    
    G_PowerOn_Mth();
    LcdCnfig.LcdFlags.G_DelayStrt_F = true;
    I2cVars.I2cFlags.I2cBusy_F = true;
    while(1)
    {
        if(!LcdCnfig.LcdFlags.G_InitLcd_F)
            G_DsplyInt_Mth();
        else
        {
            switch(LcdCnfig.LcdVars.G_SystmEvnt_Ui8)
            {
                case WRT_EVNT:
                    G_WrtDataEep_Mth();
                    LcdCnfig.LcdVars.G_SystmEvnt_Ui8 = EEP_EVNT;
                break;
                case RWD_EVNT:
                    G_RwdDataEep_Mth();
                    LcdCnfig.LcdVars.G_SystmEvnt_Ui8 = EEP_EVNT;
                break;
                case EEP_EVNT:
                    L_WriteEEprom_Mth();
                    if(I2cVars.I2cFlags.WrtCmplt_F)
                    {
                        I2cVars.I2cFlags.WrtCmplt_F = false;
                        LcdCnfig.LcdVars.G_SystmEvnt_Ui8 = RWD_EVNT;
                        G_ClrBuffr_Mth();
                    }
                    if(I2cVars.I2cFlags.RdCmplt_F)
                    {
                        I2cVars.I2cFlags.RdCmplt_F = false;
                        LcdCnfig.LcdVars.G_SystmEvnt_Ui8 = DSPLYDATA_EVNT;
                    }
                break;
                case DSPLYDATA_EVNT:
                    G_WrtData_Mth();
                    LcdCnfig.LcdVars.G_SystmEvnt_Ui8 = 4;
                break;
            }
        }
    }
    return;
}