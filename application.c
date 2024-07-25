/* 
 * File:   application.c
 * Author: lenovo
 *
 * Created on February 12, 2024, 12:02 PM
 */
#include "application.h"

#include "application.h"
#include "ECU_layer/LED/ecu_led.h"
#include "MCAL_layer/Timer0/hal_timer0.h"
volatile uint8 timer0_1000ms = 0;
void Timer0_DefaultInterruptHandler(void){
    timer0_1000ms = 1;
}
led_t led1 = {.port_name = PORTC_INDEX, .pin = GPIO_PIN0, .led_status = GPIO_LOW};
timer0_t timer0 ={
.TMR0_InterruptHandler=Timer0_DefaultInterruptHandler ,
.timer0_mode =TIMER0_TIMER_MODE ,
.timer0_register_size=TIMER0_16BIT_REGISTER_MODE,
.prescaler_enable =TIMER0_PRESCALER_ENABLE_CFG ,
.prescaler_value = TIMER0_PRESCALER_DIV_BY_16,
.timer0_preload_value=3036,
};


int main() { 
    Std_ReturnType ret = E_NOT_OK;
    //ret=application_intialize();
    ret=led_initialize(&led1);
    ret=led_turn_on(&led1);
    ret=Timer0_Init(&timer0);
    while(1){
          if(timer0_1000ms == 1){
            timer0_1000ms = 0;
            led_turn_toggle(&led1);
             }
           else {/* Nothing */}

    }
    return (EXIT_SUCCESS);
}

void application_intialize(void){
    Std_ReturnType ret = E_NOT_OK;
    ecu_layer_intialize();
}
