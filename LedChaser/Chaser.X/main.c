/*
 * File:   main.c
 * Author: Malcolm.X
 *
 * Created on June 24, 2025, 3:44 PM
 */


#include "main.h"

void main(void) {
    PLStrct.PLVars.G_SystmDlyCnt_Ui8 = 9;
    G_PwrOn_Mth();
    CLCK_EN_RB2 = 1;
    PL_EN_RB1   = 1;
    while (1) 
    {
        G_ReadData_Mth(); 
    }
    return;
}
