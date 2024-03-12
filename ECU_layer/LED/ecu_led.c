/* 
 * File:   ecu_led.c
 * Author: lenovo
 *
 * Created on February 12, 2024, 12:02 PM
 */
#include "ecu_led.h"


/**
 * 
 * @param led
 * @return 
 */
Std_ReturnType led_initialize(const led_t *led){
      Std_ReturnType ret = E_OK;
      pin_config_t pin_0bj={.port = led->port_name, 
      .pin = led->pin, 
      .direction= GPIO_DIRECTION_OUTPUT,
      .logic = led->led_status
      };
    if(NULL == led) {
        ret = E_NOT_OK;
    }
    else{
        gpio_pin_initialize(&pin_0bj);
    }
      return ret;
}


/**
 * 
 * @param led
 * @return 
 */
Std_ReturnType led_turn_on(const led_t *led){
       Std_ReturnType ret = E_OK;
    if(NULL == led) {
        ret = E_NOT_OK;
    }
    else{       
       pin_config_t pin_0bj={.port = led->port_name, 
      .pin = led->pin, 
      .direction= GPIO_DIRECTION_OUTPUT,
      .logic = led->led_status
      };
        gpio_pin_write_logic(&pin_0bj,GPIO_HIGH);
    }
        return ret;
}


/**
 *  
 * @param led
 * @return 
 */
Std_ReturnType led_turn_off(const led_t *led){
       Std_ReturnType ret = E_OK;
    if(NULL == led) {
        ret = E_NOT_OK;
    }
    else{
      pin_config_t pin_0bj={.port = led->port_name, 
      .pin = led->pin, 
      .direction= GPIO_DIRECTION_OUTPUT,
      .logic = led->led_status
      };        
      gpio_pin_write_logic(&pin_0bj,GPIO_LOW);
    }
        return ret;
}


/**
 * 
 * @param led
 * @return 
 */
Std_ReturnType led_turn_toggle(const led_t *led){
       Std_ReturnType ret = E_OK;
    if(NULL == led) {
        ret = E_NOT_OK;
    }
    else{
      pin_config_t pin_0bj={.port = led->port_name, 
      .pin = led->pin, 
      .direction= GPIO_DIRECTION_OUTPUT,
      .logic = led->led_status
      };        
      gpio_pin_toggle_logic(&pin_0bj);
    }
        return ret;
}