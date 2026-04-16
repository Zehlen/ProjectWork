/*
 * system_flow.c
 *
 *  Created on: Aug 5, 2024
 *      Author: 91865
 */
#include "system_flow.h"
void G_initgraphicsVriables_Mth(void)
{
	graphics.StartDelayCount = true;
	graphics.Updatedisplay   = true;
	//graphics.FontsInverted   = true;
	graphics.LcdUpadetCount_Ui16 = 67;
	graphics.Delay_count_Ui16 = 67;
	graphics.Delay_counter_Ui16 = 0;
	KeyPadVars.KeyPad.G_DebncCnt_ui8 = 10;
    RW_RE1 = 0;
    RST_PC2 = 1;
	//HAL_GPIO_WritePin(GPIOD, PD0_RW_Pin , RESET);
}

void M_SystemFlow_Mth(void)
{
	if (!graphics.InitGraphics)
	{
		G_LCDInit_Mth();
	}
	else
	{
		if(KeyPadVars.KeyPadFlags.KeyReleasedFlag)
		{
			KeyPadVars.KeyPadFlags.KeyReleasedFlag = false;
		}
		switch(graphics.VACEvent_Ui8)
		{
			case DISPLAY_SPLASH:
				G_CreateHomePage();
			break;
			case MTRSTATR:
				graphics.VACEvent_Ui8 = 3;
			break;
		}
	}

}


