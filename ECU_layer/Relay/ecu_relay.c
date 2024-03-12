/* 
 * File:   ecu_realy.c
 * Author: lenovo
 *
 * Created on March 4, 2024, 3:05 PM
 */

#include "ecu_relay.h"



Std_ReturnType relay_initialize(const relay_t * _relay){
      Std_ReturnType ret = E_OK;
 if(NULL == _relay) {
        ret = E_NOT_OK;
    }
 
 else {
 pin_config_t pin_0bj={.port = _relay->relay_port, 
      .pin = _relay->relay_pin, 
      .direction= GPIO_DIRECTION_OUTPUT,
      .logic = _relay->relay_status
      };
        gpio_pin_initialize(&pin_0bj);
    }    
      return ret;
}



Std_ReturnType relay_on(const relay_t * _relay){
     Std_ReturnType ret = E_OK;
 if(NULL == _relay) {
        ret = E_NOT_OK;
    }
  else {
     pin_config_t pin_0bj={.port = _relay->relay_port, 
      .pin = _relay->relay_pin, 
      .direction= GPIO_DIRECTION_OUTPUT,
      .logic = _relay->relay_status
      };
        gpio_pin_write_logic(&pin_0bj,GPIO_HIGH);
  }
      return ret;
}
Std_ReturnType relay_off(const relay_t * _relay){
      Std_ReturnType ret = E_OK;
 if(NULL == _relay) {
        ret = E_NOT_OK;
    }
      
   else {
  pin_config_t pin_0bj={.port = _relay->relay_port, 
      .pin = _relay->relay_pin, 
      .direction= GPIO_DIRECTION_OUTPUT,
      .logic = _relay->relay_status
      };
         gpio_pin_write_logic(&pin_0bj,GPIO_LOW);
 }          
      return ret;
}
