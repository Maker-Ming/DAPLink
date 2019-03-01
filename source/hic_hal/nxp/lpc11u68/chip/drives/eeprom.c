/*
 * @brief Common EEPROM support functions
 *
 * @note
 * Copyright(C) NXP Semiconductors, 2013
 * All rights reserved.
 */

#include "chip.h"
#include "eeprom.h"

/*****************************************************************************
 * Private types/enumerations/variables
 ****************************************************************************/

/*****************************************************************************
 * Public types/enumerations/variables
 ****************************************************************************/

/*****************************************************************************
 * Private functions
 ****************************************************************************/

/*****************************************************************************
 * Public functions
 ****************************************************************************/

/* Write data to EEPROM */
uint8_t Chip_EEPROM_Write(uint32_t dstAdd, uint8_t *ptr, uint32_t byteswrt)
{
	uint32_t command[5], result[4];

	command[0] = IAP_EEPROM_WRITE;
	command[1] = dstAdd;
	command[2] = (uint32_t) ptr;
	command[3] = byteswrt;
	command[4] = SystemCoreClock / 1000;
	iap_entry(command, result);

	return result[0];
}

/* Read data from EEPROM */
uint8_t Chip_EEPROM_Read(uint32_t srcAdd, uint8_t *ptr, uint32_t bytesrd)
{
	uint32_t command[5], result[4];

	command[0] = IAP_EEPROM_READ;
	command[1] = srcAdd;
	command[2] = (uint32_t) ptr;
	command[3] = bytesrd;
	command[4] = SystemCoreClock / 1000;
	iap_entry(command, result);

	return result[0];
}
