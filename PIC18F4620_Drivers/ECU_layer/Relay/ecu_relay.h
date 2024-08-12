/* 
 * File:   ecu_realy.h
 * Author: lenovo
 *
 * Created on March 4, 2024, 3:05 PM
 */

#ifndef ECU_REALY_H
#define	ECU_REALY_H

/* Section : Includes */
#include "ecu_relay_cfg.h"
#include "../../MCAL_layer/GPIO/hal_gpio.h"


/*************** Section : Macro Declarations     ****************/
#define RELAY_ON_STATUS  0x01U
#define RELAY_OFF_STATUS  0x00U

/*************** Section : Data Type Declarations *****************/
typedef struct {
    uint8 relay_port    :4;
    uint8 relay_pin     :3;
    uint8 relay_status  :1;    
} relay_t;                  //relay type 



/*************** Section : Function Declarations *****************/
Std_ReturnType relay_initialize(const relay_t * _relay);
Std_ReturnType relay_on(const relay_t * _relay);
Std_ReturnType relay_off(const relay_t * _relay);



#endif	/* ECU_REALY_H */

