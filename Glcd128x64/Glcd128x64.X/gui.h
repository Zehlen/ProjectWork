/*
 * gui.h
 *
 *  Created on: Jul 31, 2024
 *      Author: 91865
 */

#ifndef INC_GUI_H_
#define INC_GUI_H_

#include "extern_graphics.h"
#include "extern_gui.h"
#include "struck_system.h"
#include "extern_gui.h"
#include "define.h"

unsigned char G_CharBuffer_Ui8Arr[16];
void G_CreateHomePage(void);
void G_CreateMenuPage(void);
void G_ProcessPage(void);

void G_WriteCompanyName_Mth(void);
void G_WriteLeakRate_Mth(void);
void G_WriteVersion_Mth(void);
void G_WriteContinuous_Mth(void);
uint8_t G_CopyContinuous_Mth(void);

uint8_t G_CopyVersion_Mth(void);
uint8_t G_CopyLeakRate_Mth(void);
uint8_t G_CopyCompanyName_Mth(void);
void G_WriteStart_Mth(void);
uint8_t G_CopyStart_Mth(void);
void G_WriteSettings_Mth(void);
uint8_t G_CopySettings_Mth(void);
void G_WriteArrow_Mth(void);
uint8_t G_CopyArrow_Mth(void);
//void G_WriteValue_Mth(uint8_t L_Value_Ui8);
uint8_t G_CopyStop_Mth(void);
void G_WriteStop_Mth(void);
void G_WritemmHg_Mth(void);
uint8_t G_CopymmHg_Mth(void);
void G_WriteLongValue_Mth(long L_Value_Ln);

uint8_t G_CopyMsg_Mth(uint8_t M_Msg_Ui8);
void G_SetTimePage_Mth(void);
void G_SelTime_Mth(void);
void G_SetPressurePage_Mth(void);
void G_SelPressure_Mth(void);
void G_WriteValue_Mth(long L_Value_Ln, uint8_t L_Count_Ui8, uint8_t X_Pos_Ui8, uint8_t Y_Pos_Ui8);
void G_ModePage(void);
void G_Battery_Mth(void);
void G_LeakageBar_Mth(uint8_t L_BarVal_Ui8);

#endif /* GUI_H_ */