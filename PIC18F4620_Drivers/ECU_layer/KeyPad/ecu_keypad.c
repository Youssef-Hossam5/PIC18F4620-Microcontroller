/* 
 * File:   keypad.c
 * Author: lenovo
 *
 * Created on July 1, 2024, 2:12 PM
 */



#include "ecu_keypad.h"
#define _XTAL_FREQ  4000000  // 4MHz crystal frquency

// const as it wont change during runtime and static as its only avaliable for the keypad file
static const uint8 btn_values[ECU_KEYPAD_ROW][ECU_KEYPAD_COL] = {
                                                                        {'7', '8', '9', '/'},
                                                                        {'4', '5', '6', '*'},
                                                                        {'1', '2', '3', '-'},
                                                                        {'#', '0', '=', '+'}
                                                                     };


/**
 * 
 * @param _keypad_obj
 * @return 
 */
Std_ReturnType Keypad_initialize (const keypad_t * _keypad_obj){
    Std_ReturnType ret = E_OK;
    uint8 rows_counter=ZERO_INIT, cols_counter=ZERO_INIT; 
        if(NULL == _keypad_obj){
        ret = E_NOT_OK;
    }
    else{
            for(rows_counter=ZERO_INIT;rows_counter<ECU_KEYPAD_ROW;rows_counter++){
                ret=gpio_pin_initialize( &(_keypad_obj ->keypad_row_pins[rows_counter]) );
            }
                for( cols_counter=ZERO_INIT;cols_counter<ECU_KEYPAD_COL;cols_counter++){
                    ret=gpio_pin_direction_initialize( &(_keypad_obj ->keypad_col_pins[cols_counter]) );
                }
    }
  return ret;


}

/**
 * @brief Get the value of the button pressed by the user and performing the scanning algorithm
 * @param _keypad_obj pointer to the keypad configurations
 * @param value Value of the button pressed by the user
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action 
 */
Std_ReturnType Keypad_get_value(const keypad_t *_keypad_obj, uint8 *value){
    Std_ReturnType ret = E_OK;
    uint8 l_rows_counter = ZERO_INIT, l_columns_counter = ZERO_INIT, l_counter = ZERO_INIT;
    uint8 column_logic = ZERO_INIT;
    if((NULL == _keypad_obj) || (NULL == value)){
        ret = E_NOT_OK;
    }
    else{    
        for(l_rows_counter=ZERO_INIT; l_rows_counter<ECU_KEYPAD_ROW; l_rows_counter++){
            for(l_counter=ZERO_INIT; l_counter<ECU_KEYPAD_ROW; l_counter++){
                ret = gpio_pin_write_logic(&(_keypad_obj->keypad_row_pins[l_counter]), GPIO_LOW);
            }
            gpio_pin_write_logic(&(_keypad_obj->keypad_row_pins[l_rows_counter]), GPIO_HIGH);
            __delay_ms(10);
            for(l_columns_counter=ZERO_INIT; l_columns_counter<ECU_KEYPAD_COL; l_columns_counter++){
                ret = gpio_pin_read_logic(&(_keypad_obj->keypad_col_pins[l_columns_counter]), &column_logic);
                if(GPIO_HIGH == column_logic){
                    *value = btn_values[l_rows_counter][l_columns_counter];
                }
            }
        }
    }
    return ret;
}