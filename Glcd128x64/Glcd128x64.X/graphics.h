/*
 * graphics.h
 *
 *  Created on: Jul 17, 2024
 *      Author: Shruti
 */

#ifndef SRC_GRAPHICS_H_
#define SRC_GRAPHICS_H_



#include "extern_gui.h"
#include "struck_system.h"
#include "extern_gui.h"
#include "font_calibri.h"
#include "app_msg.h"
#include "system.h"
#include "define.h"

struct __graphics graphics;
union __ValOfKey_Un KeyVal_Un;
struct __KeyPadvars KeyPadVars;
void GLCD_Command(uint8_t LCD_data);
void G_SetXY_Mth(uint8_t L_row_Ui8, uint8_t L_Col_Ui8);
void G_SetRow_Mth(uint8_t L_Row_Ui16);
void G_SetColumn_Mth(uint8_t L_Column_Ui8);
void G_GLCDWrit1eStr_Mth(unsigned char str[], unsigned char count,uint8_t L_Xpos_Ui8,uint8_t L_Ypos_Ui8);
uint8_t G_DrawChar_Mth(uint8_t L_CharData_Ui8);
void G_DrawLine_Mth(uint8_t L_XCord_Ui8,uint8_t L_YCord_Ui8,uint8_t L_Len_Ui8, uint8_t L_LineDir_Ui8);
void G_DrawImage_Mth(void);
void G_DrawRectangle_Mth(unsigned char L_RectType_Uch, uint8_t L_X1Cord_Ui8, uint8_t L_Y1Cord_Ui8,uint8_t L_X2Cord_Ui8, uint8_t L_Y2Cord_Ui8);
void G_GLCDInit_Mth(void);
void G_GlcdWrite_Mth(uint8_t Rs_Status,uint8_t L_Data_Uch);
void G_SetXY_Mth(uint8_t L_row_Ui8, uint8_t L_Col_Ui8);
void G_GLCDWriteStr_Mth(unsigned char str[], unsigned char count,uint8_t L_Xpos_Ui8);
void G_ClrGLCDLine_Mth(uint8_t L_Offset,uint8_t L_Xlen_Ui8, uint8_t L_YCord_ui8);
void G_GLCDFill_Mth(uint16_t data);
void G_GLCDWriteChar_Mth(unsigned char data);
void G_GLCDClearDisplay_Mth();
void G_WriteBufferData_Mth(void);
uint16_t G_Set_CharYPos_Mth(uint8_t L_Y_Pos_Ui8, uint8_t L_Data_Ui8);
uint16_t G_ReadPortVal_Fun (uint16_t L_WriteData_Ui16);
void G_ClearLine_Mth(uint8_t L_XCord_Ui8,uint8_t L_YCord_Ui8,uint8_t L_Len_Ui8);
volatile uint8_t G_GLCDData64_Ui8Arr[4][20];
void G_ClearGLCEDataBuffer_Mth(void);
void G_ClearGLCDCharBuffer_Mth(void);
void G_WriteMsg_Mth(uint8_t M_Msg_Ui8, uint8_t M_X_Val_Ui8, uint8_t M_Y_Val_Ui8);
//#define INC_FONT_CALIBRI_H_
void putpixel(int x, int y, int color);
void G_DelayUs_Mth (uint16_t L_DelayCount_Ui8);
void SetDelayUs_Mth(uint8_t CountVal);
uint8_t AppMessageLen(uint8_t Message_Ui8);
void TestData(void);
//void lcd_command();

#endif /* SRC_GRAPHICS_H_ */