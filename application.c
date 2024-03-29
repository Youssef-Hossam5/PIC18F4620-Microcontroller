/* 
 * File:   application.c
 * Author: lenovo
 *
 * Created on February 12, 2024, 12:02 PM
 */
#include "application.h"

pin_config_t seg_1_enable = {
    .direction =GPIO_DIRECTION_OUTPUT,
    .port=PORTD_INDEX,
    .logic =GPIO_LOW ,
    .pin=GPIO_PIN0
};
pin_config_t seg_2_enable = {
    .direction =GPIO_DIRECTION_OUTPUT,
    .port=PORTD_INDEX,
    .logic=GPIO_LOW,
    .pin=GPIO_PIN1
};
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




segment_t seg1 ={
        /*******     first pin *********/
        .segment_pins[0].port=PORTC_INDEX,
        .segment_pins[0].pin=GPIO_PIN0 , 
        .segment_pins[0].logic=GPIO_LOW ,      //display zero at start
        .segment_pins[0].direction=GPIO_DIRECTION_OUTPUT ,
        /*******     second pin *********/
        .segment_pins[1].port=PORTC_INDEX,
        .segment_pins[1].pin=GPIO_PIN1 , 
        .segment_pins[1].logic=GPIO_LOW ,
        .segment_pins[1].direction=GPIO_DIRECTION_OUTPUT ,
         /*******     third pin *********/
        .segment_pins[2].port=PORTC_INDEX,
        .segment_pins[2].pin=GPIO_PIN2 , 
        .segment_pins[2].logic=GPIO_LOW ,
        .segment_pins[2].direction=GPIO_DIRECTION_OUTPUT ,
         /*******     fourth pin *********/
        .segment_pins[3].port=PORTC_INDEX,
        .segment_pins[3].pin=GPIO_PIN3 , 
        .segment_pins[3].logic=GPIO_LOW ,
        .segment_pins[3].direction=GPIO_DIRECTION_OUTPUT ,
        .segment_type=SEGMENT_COMMON_ANODE      
} ;
void application_intialize (void) {
    Std_ReturnType ret = E_NOT_OK;
     ret= dc_motor_initialize(&dc_motor_1);
    ret= seven_segment_initialize(&seg1); // initialize port to be output
    ret=gpio_pin_initialize(&seg_1_enable);
    ret=gpio_pin_initialize(&seg_2_enable);       
    return ;
}
uint8 number=45;
int main() {
     Std_ReturnType ret = E_NOT_OK;
     application_intialize();
    while (1) {
      
           ret=seven_segment_write_number(&seg1, (uint8)(number%10) );
          ret=gpio_pin_write_logic(&seg_2_enable,GPIO_HIGH);
        __delay_ms(5);
          ret=gpio_pin_write_logic(&seg_2_enable,GPIO_LOW);
          
          ret=seven_segment_write_number(&seg1, (uint8)(number/10) );
          ret=gpio_pin_write_logic(&seg_1_enable,GPIO_HIGH);
        __delay_ms(5);
          ret=gpio_pin_write_logic(&seg_1_enable,GPIO_LOW);
        
        

    }
     return (EXIT_SUCCESS);
}
    