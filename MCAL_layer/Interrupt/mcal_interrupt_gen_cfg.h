/* 
 * File:   mcal_interrupt_gen_cfg.h
 * Author: lenovo
 *
 * Created on July 15, 2024, 8:01 PM
 */

/* 
 * 
 * This is supposed to be a generated  pre-config file from a tool 
 */


#ifndef MCAL_INTERRUPT_GEN_CFG_H
#define	MCAL_INTERRUPT_GEN_CFG_H

#define INTERRUPT_FEATURE_ENABLE 1U
//#define INTERRUPT_PRIORITY_LEVELS_ENABLE            INTERRUPT_FEATURE_ENABLE

#define EXTERNAL_INTERRUPT_INTx_FEATURE_ENABLE      INTERRUPT_FEATURE_ENABLE
#define EXTERNAL_INTERRUPT_OnChange_FEATURE_ENABLE  INTERRUPT_FEATURE_ENABLE

#define ADC_INTERRUPT_FEATURE_ENABLE    INTERRUPT_FEATURE_ENABLE  /*  precompile condition if ADC will use interrupt, instead of polling  */



#endif	/* MCAL_INTERRUPT_GEN_CFG_H */

