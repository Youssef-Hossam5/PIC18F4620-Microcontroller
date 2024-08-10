/* 
 * File:   application.c
 * Author: Ahmed.Elghafar
 * https://www.linkedin.com/in/ahmedabdelghafarmohammed/
 */

#include "application.h"
#include "MCAL_Layer/usart/hal_usart.h"
#include "MCAL_layer/I2C/hal_i2c.h"

mssp_i2c_t i2c_obj;

int main() {
    i2c_obj.i2c_clock = 100000;
    i2c_obj.i2c_cfg.i2c_mode = I2C_MSSP_MASTER_MODE;
    i2c_obj.i2c_cfg.i2c_mode_cfg = I2C_MASTER_MODE_DEFINED_CLOCK;
    i2c_obj.i2c_cfg.i2c_SMBus_control = I2C_SMBus_DISABLE;
    i2c_obj.i2c_cfg.i2c_slew_rate = I2C_SLEW_RATE_DISABLE;

    Std_ReturnType ret = E_NOT_OK;
    ret = MSSP_I2C_Init(&i2c_obj);
    ret=MSSP_I2C_Master_Send_Start(&i2c_obj);
    ret=MSSP_I2C_Master_Send_Stop(&i2c_obj);
    
    while(1){
        
    }
    return (EXIT_SUCCESS);
}

void application_intialize(void){
    Std_ReturnType ret = E_NOT_OK;
    ecu_layer_intialize();
}


