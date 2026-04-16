/*
 */

#include "main.h"

int main(void)
{
    G_PwrOn_Mth();
    LcdStrk.LcdFlgas.TimOut_F = true;
    while(1)
    {
        if(!LcdStrk.LcdFlgas.LcdInit_F)
        {
            G_LcdInit1_Mth();
        }
        else
        {
            if(!I2cStrk.I2cFlags.WrtCmplt_F)
            {
                G_LcdDataWrt_Mth(1);
            }
        }
    }
    return 0;
}
