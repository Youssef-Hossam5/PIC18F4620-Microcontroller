/* 
 * File:   application.c
 * Author: lenovo
 *
 * Created on February 12, 2024, 12:02 PM
 */
#include "application.h"

dc_motor_t dc_motor_1 = {
.dc_motor_pin[0].pin = GPIO_PIN0 ,
.dc_motor_pin[0].port= PORTC_INDEX ,
.dc_motor_pin[0].direction=GPIO_DIRECTION_OUTPUT ,  
.dc_motor_pin[0].logic=DC_MOTOR_OFF_STATUS ,  
.dc_motor_pin[1].pin = GPIO_PIN1 ,
.dc_motor_pin[1].port= PORTC_INDEX ,
.dc_motor_pin[1].direction=GPIO_DIRECTION_OUTPUT ,  
.dc_motor_pin[1].logic=DC_MOTOR_OFF_STATUS ,         
};


dc_motor_t dc_motor_2 = {
.dc_motor_pin[0].pin = GPIO_PIN2 ,
.dc_motor_pin[0].port= PORTC_INDEX ,
.dc_motor_pin[0].direction=GPIO_DIRECTION_OUTPUT ,  
.dc_motor_pin[0].logic=DC_MOTOR_OFF_STATUS ,  
.dc_motor_pin[1].pin = GPIO_PIN3 ,
.dc_motor_pin[1].port= PORTC_INDEX ,
.dc_motor_pin[1].direction=GPIO_DIRECTION_OUTPUT ,  
.dc_motor_pin[1].logic=DC_MOTOR_OFF_STATUS ,         
};


void application_intialize (void) {
    Std_ReturnType ret = E_NOT_OK;
     ret= dc_motor_initialize(&dc_motor_1);
    ret= gpio_port_direction_initialize(PORTC_INDEX,0x80); // initialize port to be output
    return ;
}


int main() {
     Std_ReturnType ret = E_NOT_OK;
     application_intialize();
    while (1) {
        ret=gpio_port_write_logic(PORTC_INDEX,0xc0);
        

    }
     return (EXIT_SUCCESS);
}
    