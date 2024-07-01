/* 
 * File:   keypad.h
 * Author: lenovo
 *
 * Created on July 1, 2024, 2:12 PM
 */

#ifndef KEYPAD_H
#define	KEYPAD_H

/****************** Section : Includes ***************/
#include "ecu_keypad_cfg.h"
#include "../../MCAL_layer/GPIO/hal_gpio.h"


/* Section : Macro Declarations*/
#define ECU_KEYPAD_ROW 4
#define ECU_KEYPAD_COL 4





/* Section : Data Type Declarations */
typedef struct {
    pin_config_t keypad_row_pins[ECU_KEYPAD_ROW];
    pin_config_t keypad_col_pins[ECU_KEYPAD_COL];
} keypad_t;

/* Section : Function Declarations */
Std_ReturnType Keypad_initialize (const keypad_t * _keypad_obj);
Std_ReturnType Keypad_get_value (const keypad_t * _keypad_obj,uint8 * value);

#endif	/* KEYPAD_H */

