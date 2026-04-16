/* 
 * File:   Oled.h
 * Author: abdul
 *
 * Created on 29 August, 2025, 2:42 PM
 */

#ifndef OLED_H
#define	OLED_H

#include "SystemStruck.h"
#include "defines.h"
#include "Fonts.h"

void G_OledInit_Mth(void);
void G_OledInitCmd_Mth(void);
void G_DsplyFill_Mth(void);
void L_ClrBuffr_Mth(void);
void G_WrtMssg_Mth(uint8_t L_MssgNum_Ui8,uint8_t L_XPostn_Ui8);
void G_ClrDsply_Mth(uint8_t L_DevAddress_Ui8,uint16_t L_Size_Ui8);
void L_I2c_Mstr_Wrt(uint8_t L_DevAddress_Ui8,const uint8_t *L_PtrDataBuffr_Ui8,uint16_t L_Size_Ui8);

uint16_t L_CrtDataArry_Fun(const uint8_t *PDataArry_Ui8,uint16_t L_CntrOffset_Ui8,uint16_t L_DataCnt);
uint8_t  L_GetMssgLn_Fun(uint8_t L_MssgNum_Ui8);

#define DSPLY_STRT_DLY      0x00
#define IS_DSPLY_RDY        0x01
#define MUX_CMD             0xA8
#define MUX_RATIO    		0x3F  // how many rows are scanned.
#define SET_DSPLY_OFFSET    0xD3  // Dsply start address.
#define DSPLY_STRT_LINE     0x40  //
#define SET_SEGMENT         0xA0
#define COM_SCN_DRCTN       0xC0
#define COM_PIN_CNFG        0xDA
#define SET_CONTRAST        0xCF
#define DSPLY_RAM_ON	    0xA4
#define SET_NRML_DSPLY      0xA6
#define SET_FRNCY    	 	0xD5
#define ENBL_RGULTOR		0xD9
#define DSPLY_ON            0xAF
#define DSPLY_OFF           0xAE
#define ADDRSNG_MODE        0x10
#define PAGE_STRT_ADDRS     0xB0
#define SET_LWCLMN_ADDRS    0x02
#define SET_HIGHCLMN_ADDRS  0x11
#define DUMPY_DATA          0x04

#define SSD1306_I2C_ADDR    0x78 //OLED address for i2c
#define I2CBUFFR_LMT        0x32 //I2c Buffer limit
/*---Definition of Wrtie message funciton---*/
#define CLRBUFFR       0x00
#define MSSGLEN        0x01
#define SET_MSSG_ADDRS 0x02
#define FLLI2CBUFFR    0x03
#define WRTI2CBUFFR    0x04
/*-----------------------------------------*/

/*---Definition of Displaying image and Text---*/
#define DSPLY_SYMBL    0x00
#define STRT_SCROLLNG  0x01
#define DSPLY_NAME     0x02
/*--------------------------------------------*/

#endif	/* OLED_H */

