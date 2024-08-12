/* 
 * File:   EEPROM_24C02C.h
 * Author: lenovo
 *
 * Created on August 12, 2024, 9:58 PM
 */

#ifndef EEPROM_24C02C_H
#define	EEPROM_24C02C_H

#include "../../mcc_generated_files/examples/i2c_master_example.h"

void EEPROM_24C02C_Write_Byte(i2c_address_t EEPROM_Address, i2c_address_t Byte_Address, uint8_t Data);
uint8_t EEPROM_24C02C_Read_Byte(i2c_address_t EEPROM_Address, i2c_address_t Byte_Address);

#endif	/* EEPROM_24C02C_H */

