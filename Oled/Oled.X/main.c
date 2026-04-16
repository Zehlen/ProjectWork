/*
 * File:   main.c
 * Author: Malcolm.x
 *
 * Created on 29 August, 2025, 9:18 AM
 */


#include "main.h"

void main(void) {
    
    G_PowerOn_Mth();
//  OledStrct.OledFlags.G_OledInit_F = true;
    while(1)
    {
        if(!OledStrct.OledFlags.G_OledInit_F)
        {
            G_OledInitCmd_Mth();
            OledStrct.OledVars.G_OledEvnt_Ui8 = DSPLY_NAME;
        }
        else
        {
            switch(OledStrct.OledVars.G_OledEvnt_Ui8)
            {
                case DSPLY_SYMBL:
                    if(!I2cStrct.I2cFlags.G_StpCmplt_F)
                    {
                        I2cStrct.I2cFlags.G_ScltDataOrCmd_F = DataSclt;
                        L_I2c_Mstr_Wrt(SSD1306_I2C_ADDR,AnonymousImg,1024);
                    }
                    else
                    {
                        if(!OledStrct.OledFlags.G_DlyTimOut_F)
                        {
                            OledStrct.OledFlags.G_DlyStrt_F  = true;
                            OledStrct.OledVars.G_DlyCnt_Ui16 = 999;
                        }
                        else
                        {
                            OledStrct.OledFlags.G_DlyStrt_F = false;
                            G_ClrDsply_Mth(SSD1306_I2C_ADDR,8192);
                            if(I2cStrct.I2cFlags.G_WrtCmplt_F)
                            {
                                I2cStrct.I2cFlags.G_WrtCmplt_F    = false;
                                OledStrct.OledVars.G_OledEvnt_Ui8 = DSPLY_NAME;
                            }
                        }
                    }
                break;
                case STRT_SCROLLNG:
                break;
                case DSPLY_NAME:
                    G_WrtMssg_Mth(1,10);
                    if(I2cStrct.I2cFlags.G_WrtCmplt_F)
                    {
                        OledStrct.OledVars.G_OledEvnt_Ui8 = STRT_SCROLLNG;
                    }
                break;
            }
            /*if(!I2cStrct.I2cFlags.G_StpCmplt_F)
            {
//              G_DsplyFill_Mth();
                I2cStrct.I2cFlags.G_ScltDataOrCmd_F = DataSclt;
                L_I2c_Mstr_Wrt(SSD1306_I2C_ADDR,AnonymousImg,1024);
            }*/
            /*if(!I2cStrct.I2cFlags.G_StpCmplt_F)
            {
               // G_WrtMssg_Mth(1);
                G_ClrDsply_Mth(SSD1306_I2C_ADDR,1024);
            }*/
        }
    }
    return;
}
