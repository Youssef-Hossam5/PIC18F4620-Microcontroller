/* 
 * File:   ecu_seven_segment.h
 * Author: lenovo
 *
 * Created on March 12, 2024, 5:35 PM
 */

#ifndef ECU_SEVEN_SEGMENT_H
#define	ECU_SEVEN_SEGMENT_H

/************************ Section : Includes *******************/
#include "../../MCAL_layer/GPIO/hal_gpio.h"
#include "ecu_seven_segment_cfg.h"

/************************ Section : Macro Declarations **************/
#define SEGMENT_PIN0 0
#define SEGMENT_PIN1 1
#define SEGMENT_PIN2 2
#define SEGMENT_PIN3 3

/**********************  Section : Data Type Declarations *****************/
typedef enum {
    SEGMENT_COMMON_ANODE,
    SEGMENT_COMMON_CATHODE
} segment_type_t;

typedef struct {
    pin_config_t segment_pins[4];         // each segment is represented by 4 pins, different ports for generality
    segment_type_t segment_type;         // common anode or common cathode
} segment_t;

/************************** Section : Function Declarations *******************/
Std_ReturnType seven_segment_initialize(const segment_t * seg );
Std_ReturnType seven_segment_write_number(const segment_t * seg, uint8 number );



#endif	/* ECU_SEVEN_SEGMENT_H */

