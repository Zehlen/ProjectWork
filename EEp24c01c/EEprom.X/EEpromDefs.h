/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef EEPROM_DEFS_H
#define	EEPROM_DEFS_H

#define DEVICE_TYPE		0


/* Uncomment one of the line below to select the EEPROM Configuration */
#define EEPROM24C01
//#define EEPROM24C02
//#define EEPROM24C04
//#define EEPROM24C08
//#define EEPROM24C16
//#define EEPROM24C32
//#define EEPROM24C64
//#define EEPROM24C128
//#define EEPROM24C256
//#define EEPROM24C512

#ifdef EEPROM24C01
	#define EEPROM_ADDRESS 	  0xA0
	#define PAGE_LIMIT		  16
	#define PAGE_UNIT	      8
    #define TOTAL_PAGE        8
	#define PAGE_MASK		  0
#endif

#ifdef EEPROM24C02

	#define EEPROM_ADDRESS 	0xA0
	#define PAGE_LIMIT		32
	#define BYTES_PER_PAGE	8
#endif
#ifdef EEPROM24C04
	#define EEPROM_ADDRESS 	0xA0
	#define PAGE_LIMIT		32
	#define BYTES_PER_PAGE	16
	#define PAGE_MASK		2
#endif
#ifdef EEPROM24C08
	#define EEPROM_ADDRESS 	0xA0
	#define PAGE_LIMIT		64
	#define BYTES_PER_PAGE	16
	#define PAGE_MASK		6
#endif
#ifdef EEPROM24C16
	#define EEPROM_ADDRESS 	0xA0
	#define PAGE_LIMIT		128
	#define BYTES_PER_PAGE	16
	#define PAGE_MASK		14
#endif
#ifdef EEPROM24C32
	#define EEPROM_ADDRESS 	0xA0
	#define PAGE_LIMIT		128
	#define BYTES_PER_PAGE	32
	#define PAGE_MASK		0
#endif
#ifdef EEPROM24C64
	#define EEPROM_ADDRESS 	0xA0
	#define PAGE_LIMIT		256
	#define BYTES_PER_PAGE	32
	#define PAGE_MASK		0
#endif
#ifdef EEPROM24C128
	#define EEPROM_ADDRESS 	0xA0
	#define PAGE_LIMIT		128
	#define BYTES_PER_PAGE	64
	#define PAGE_MASK		0
#endif
#ifdef EEPROM24C256
	#define EEPROM_ADDRESS 	0xA0
	#define PAGE_LIMIT		256
	#define BYTES_PER_PAGE	64
	#define PAGE_MASK		0
#endif
#ifdef EEPROM24C512
	#define EEPROM_ADDRESS 	0xA0
	#define PAGE_LIMIT		512
	#define BYTES_PER_PAGE	128
	#define PAGE_MASK		0
#endif


#endif	/* XC_HEADER_TEMPLATE_H */