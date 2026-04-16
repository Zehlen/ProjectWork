/*
 * defines.h
 *
 *  Created on: Jul 31, 2024
 *      Author: 91865
 */

#ifndef INC_DEFINES_H_
#define INC_DEFINES_H_

#define INSMODE  0
#define DATAMODE 1

#define STATUS_IDLE		0
#define DISPLAY_OFF		1
#define SET_YADDRESS	2
#define SET_XADDRESS	3
#define SET_ZADDRESS	4
#define DISPLAY_ON		5
#define CHIP_SELECT		6
#define INIT_COMPLETE	7
#define REVERS_DSPLY    8


#define FOUR_MIN_EVENT		0X04
#define SIX_MIN_EVENT		0X06
#define EIGHT_MIN_EVENT		0X08
#define TEN_MIN_EVENT		0X0A


#define FIFT_SEV_EVENT		0X00
#define HUN_TWFI_EVENT		0X01
#define ONEF_ONES_EVENT		0X02
#define TWOH_TWOF_EVENT		0X03

#define DRAWRECTANGLE   	0x00
#define WRITEAPPMSSG_1		0x01
#define WRITEAPPMSSG_2		0x02
#define WRITEAPPMSSG_3		0x03
#define WRITEAPPMSSG_4		0x04
#define WRITEAPPMSSG_5		0x05
#define WRITEAPPMSSG_6		0x06
#define WRITEAPPMSSG_7		0x07
#define DRAWBATTERY			0x08

#define DISPLAY_SPLASH	0
#define MTRSTATR		1
#define SCAN_MENU		2
#define SETTINGS_MENU	3

enum{EmtyRectgl,SldRectgl};
enum{Vrtclne,Hrzntlne};

#endif /* INC_DEFINES_H_ */