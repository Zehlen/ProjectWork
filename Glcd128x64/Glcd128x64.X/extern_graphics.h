/*
 * extern_graphics.h
 *
 *  Created on: Jul 17, 2024
 *      Author: Shruti
 */

#ifndef INC_EXTERN_GRAPHICS_H_
#define INC_EXTERN_GRAPHICS_H_



#include <stdint.h>

extern struct __graphics graphics;
extern union __ValOfKey_Un KeyVal_Un;
extern struct __KeyPadvars KeyPadVars;
extern volatile uint8_t G_GLCDData64_Ui8Arr[4][20];
extern void G_DrawLine_Mth(uint8_t L_XCord_Ui8,uint8_t L_YCord_Ui8,uint8_t L_Len_Ui8, uint8_t L_LineDir_Ui8);
extern void G_DrawImage_Mth(void);
extern void G_DrawRectangle_Mth(unsigned char L_RectType_Uch, uint8_t L_X1Cord_Ui8, uint8_t L_Y1Cord_Ui8,uint8_t L_X2Cord_Ui8, uint8_t L_Y2Cord_Ui8);
extern void G_LCDInit_Mth(void);
extern void G_GlcdWrite_Mth(uint8_t Rs_Status,uint8_t L_Data_Uch);
extern void G_SetXY_Mth(uint8_t L_row_Ui8, uint8_t L_Col_Ui8);
extern void G_SetRow_Mth(uint8_t L_Row_Ui8);
extern void G_SetColumn_Mth(uint8_t L_Column_Ui8);
extern void G_GLCDWriteStr_Mth(unsigned char str[],unsigned char count,uint8_t L_Xpos_Ui8);
extern void G_WriteMsg_Mth(uint8_t M_Msg_Ui8, uint8_t M_X_Val_Ui8, uint8_t M_Y_Val_Ui8);
extern void G_ClrGLCDLine_Mth(uint8_t L_Offset,uint8_t L_Xlen_Ui8, uint8_t L_YCord_ui8);
extern void G_GLCDFill_Mth(uint16_t data);
extern void G_GLCDWriteChar_Mth(unsigned char data);
extern void G_GLCDClearDisplay_Mth(void);
extern void G_WriteBufferData_Mth(void);
extern uint16_t G_Set_CharYPos_Mth(uint8_t L_Y_Pos_Ui8, uint8_t L_Data_Ui8);
extern void G_ClearLine_Mth(uint8_t L_XCord_Ui8,uint8_t L_YCord_Ui8,uint8_t L_Len_Ui8);
extern void G_ClearGLCEDataBuffer_Mth(void);
extern void putpixel(int x, int y, int color);
extern void Control_fun_Mth(void);
uint16_t G_ReadPortVal_Fun (uint16_t L_WriteData_Ui16);
uint8_t G_DrawChar_Mth(uint8_t L_CharData_Ui8);
//extern void lcd_setCursor(uint8_t x, uint8_t y);
//extern void lcd_data(uint8_t data);


#endif /* INC_EXTERN_GRAPHICS_H_ */
