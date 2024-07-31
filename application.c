

#include "application.h"
#include "MCAL_layer/Timer3/hal_timer3.h"
#include "MCAL_layer/CCP/hal_ccp.h"

volatile uint32 CCP1_Interrupt_Flag =0;
timer3_t timer3_obj;


ccp_t ccp_obj;


void CCP1_DefaultInterruptHandler (void) {
    CCP1_Interrupt_Flag++ ;
}

int main() {
Std_ReturnType ret = E_NOT_OK;

ccp_obj.CCP1_InterruptHandler = CCP1_DefaultInterruptHandler;
ccp_obj.ccp_inst = CCP1_INST;
ccp_obj.ccp_mode = CCP_CAPTURE_MODE_SELECTED;
ccp_obj.ccp_mode_variant = CCP_CAPTURE_MODE_1_RISING_EDGE;
ccp_obj.ccp_pin.port = PORTC_INDEX;
ccp_obj.ccp_pin.pin = GPIO_PIN2;
ccp_obj.ccp_pin.direction = GPIO_DIRECTION_INPUT;
ret = CCP_Init(&ccp_obj);

while(1){

}
return (EXIT_SUCCESS);
}
