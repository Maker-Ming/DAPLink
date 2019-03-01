/*
 * @brief Common EEPROM support functions
 *
 * @note
 * Copyright(C) NXP Semiconductors, 2013
 * All rights reserved.
 */

#ifndef __EEPROM_H_
#define __EEPROM_H_

#ifdef __cplusplus
extern "C" {
#endif

/** @defgroup COMMON_EEPROM CHIP: Common Chip EEPROM commands
 * @ingroup CHIP_Common
 * @{
 */

/**
 * @brief	Write data to EEPROM
 * @param	dstAdd		: EEPROM address to be written to
 * @param	ptr			: Pointer to buffer to write from
 * @param	byteswrt	: Number of bytes to write to EEPROM
 * @return	An IAP response definition from iap.h
 */
uint8_t Chip_EEPROM_Write(uint32_t dstAdd, uint8_t *ptr, uint32_t byteswrt);

/**
 * @brief	Read data from EEPROM
 * @param	srcAdd	: EEPROM address to be read from
 * @param	ptr		: Pointer to buffer to read to
 * @param	bytesrd	: Number of bytes to read from EEPROM
 * @return	An IAP response definition from iap.h
 */
uint8_t Chip_EEPROM_Read(uint32_t srcAdd, uint8_t *ptr, uint32_t bytesrd);

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif /* __EEPROM_H_ */
