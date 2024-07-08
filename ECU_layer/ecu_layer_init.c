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

chr_lcd_4bit_t lcd_1 = {
   .lcd_rs.port = PORTC_INDEX,
   .lcd_rs.pin  = GPIO_PIN0,
   .lcd_rs.direction = GPIO_DIRECTION_OUTPUT,
   .lcd_rs.logic = GPIO_LOW,
   
   .lcd_en.port = PORTC_INDEX,
   .lcd_en.pin  = GPIO_PIN1,
   .lcd_en.direction = GPIO_DIRECTION_OUTPUT,
   .lcd_en.logic = GPIO_LOW,
   
   .lcd_data[0].port = PORTC_INDEX,
   .lcd_data[0].pin  = GPIO_PIN2,
   .lcd_data[0].direction = GPIO_DIRECTION_OUTPUT,
   .lcd_data[0].logic = GPIO_LOW,
   
   
   .lcd_data[1].port = PORTC_INDEX,
   .lcd_data[1].pin  = GPIO_PIN3,
   .lcd_data[1].direction = GPIO_DIRECTION_OUTPUT,
   .lcd_data[1].logic = GPIO_LOW,
   
   
   .lcd_data[2].port = PORTC_INDEX,
   .lcd_data[2].pin  = GPIO_PIN4,
   .lcd_data[2].direction = GPIO_DIRECTION_OUTPUT,
   .lcd_data[2].logic = GPIO_LOW,
   
   .lcd_data[3].port = PORTC_INDEX,
   .lcd_data[3].pin  = GPIO_PIN5,
   .lcd_data[3].direction = GPIO_DIRECTION_OUTPUT,
   .lcd_data[3].logic = GPIO_LOW
};





 void ecu_layer_intialize(void) {
      Std_ReturnType ret = E_NOT_OK; 
 }
