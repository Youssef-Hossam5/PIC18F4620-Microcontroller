/* 
 * File:   application.c
 * Author: lenovo
 *
 * Created on February 12, 2024, 12:02 PM
 */
#include "application.h"

uint8 keypad_value= ZERO_INIT;
void application_intialize (void) {
    Std_ReturnType ret = E_NOT_OK;       
    ecu_layer_intialize();
    return ;
}
uint8 number=45;
int main() {
     Std_ReturnType ret = E_NOT_OK;
     application_intialize();
    while (1) {
        ret=Keypad_get_value(&keypad1,&keypad_value);
    }
     return (EXIT_SUCCESS);
}
    