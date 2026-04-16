/* 
 * File:   lcd.h
 * Author: Malcolm.x
 *
 * Created on 27 December, 2025, 11:19 AM
 */

#ifndef LCD_H
#define	LCD_H

#include "Sysstruck.h"
#include "I2cdefin.h"

void G_LcdInit_Mth(void);
void G_LcdInit1_Mth(void);
void L_RdWrtI2c_Mth(uint8_t L_DevAddrs_Ui8,uint8_t L_ScltCmdorData ,uint16_t L_TotlByts_Ui16);
void G_LcdDataWrt_Mth(uint8_t L_MssgNum_ui8);

#define INIT_DELAY  0x00
#define LCD_STTING  0x07
#define FUNCTN_SET  0x02   //for interal reset
#define MODE_4BIT   0x28
#define CLR_DSPLY   0x01
#define CURSR_ON    0x0E
#define ENTRY_MODE  0x06

#define INST_MODE  0
#define DATA_MODE  1

#endif	/* LCD_H */