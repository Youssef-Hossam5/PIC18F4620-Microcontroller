/* 
 * File:   ecu_layer_init.c
 * Author: lenovo
 *
 * Created on July 1, 2024, 2:53 PM
 */


#include "ecu_layer_init.h"


keypad_t keypad1 = {
   .keypad_row_pins[0].port            = PORTC_INDEX,
   .keypad_row_pins[0].pin             = GPIO_PIN0, 
   .keypad_row_pins[0].direction       = GPIO_DIRECTION_OUTPUT,
   .keypad_row_pins[0].logic           = GPIO_LOW ,
   
   .keypad_row_pins[1].port            = PORTC_INDEX,
   .keypad_row_pins[1].pin             = GPIO_PIN1, 
   .keypad_row_pins[1].direction       = GPIO_DIRECTION_OUTPUT,
   .keypad_row_pins[1].logic           = GPIO_LOW ,
   
   .keypad_row_pins[2].port            = PORTC_INDEX,
   .keypad_row_pins[2].pin             = GPIO_PIN2, 
   .keypad_row_pins[2].direction       = GPIO_DIRECTION_OUTPUT,
   .keypad_row_pins[2].logic           = GPIO_LOW ,
   
   .keypad_row_pins[3].port            = PORTC_INDEX,
   .keypad_row_pins[3].pin             = GPIO_PIN3, 
   .keypad_row_pins[3].direction       = GPIO_DIRECTION_OUTPUT,
   .keypad_row_pins[3].logic           = GPIO_LOW ,
   
   
   
   .keypad_col_pins[0].port            = PORTC_INDEX,
   .keypad_col_pins[0].pin             = GPIO_PIN4, 
   .keypad_col_pins[0].direction       = GPIO_DIRECTION_INPUT,
   .keypad_col_pins[0].logic           = GPIO_LOW ,
   
   .keypad_col_pins[1].port            = PORTC_INDEX,
   .keypad_col_pins[1].pin             = GPIO_PIN5, 
   .keypad_col_pins[1].direction       = GPIO_DIRECTION_INPUT,
   .keypad_col_pins[1].logic           = GPIO_LOW ,
   
   .keypad_col_pins[2].port            = PORTC_INDEX,
   .keypad_col_pins[2].pin             = GPIO_PIN6, 
   .keypad_col_pins[2].direction       = GPIO_DIRECTION_INPUT,
   .keypad_col_pins[2].logic           = GPIO_LOW ,
   
   .keypad_col_pins[3].port            = PORTC_INDEX,
   .keypad_col_pins[3].pin             = GPIO_PIN7, 
   .keypad_col_pins[3].direction       = GPIO_DIRECTION_INPUT,
   .keypad_col_pins[3].logic           = GPIO_LOW ,
   
};




 void ecu_layer_intialize(void) {
      Std_ReturnType ret = E_NOT_OK;
      ret = Keypad_initialize(&keypad1);

 
 }
