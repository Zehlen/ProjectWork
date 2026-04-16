/*
 * gui.c
 *
 *  Created on: Jul 31, 2024
 *      Author: 91865
 */
#include "gui.h"
#include "graphics.h"

void G_CreateHomePage(void)
{
	if(graphics.DelayTimeout)
	{
		graphics.DelayTimeout = false;
		switch(graphics.GLcdStrEvent_Ui8)
		{
			case DRAWRECTANGLE:
				G_GLCDClearDisplay_Mth();
				graphics.GLcdStrEvent_Ui8 = DRAWBATTERY;
				graphics.DebounceCount = 10;
				graphics.DebounceCounter = 0;
				graphics.StartDelayCount = true;
                graphics.GLcdStrEvent_Ui8 = WRITEAPPMSSG_1;
			break;
            case WRITEAPPMSSG_1:
                G_WriteMsg_Mth(WRITEAPPMSSG_1, 3, 20);  //Print VAC Version 1.0
                G_WriteBufferData_Mth();
				graphics.GLcdStrEvent_Ui8 = DRAWBATTERY;
				graphics.DebounceCount = 10;
				graphics.DebounceCounter = 0;
				graphics.StartDelayCount = true;
                graphics.VACEvent_Ui8 = MTRSTATR;
            break;
		}
		G_ClearGLCEDataBuffer_Mth();
	}
}
