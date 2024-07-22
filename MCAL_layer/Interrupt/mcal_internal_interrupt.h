/* 
 * File:   mcal_internal_interrupt.h
 * Author: lenovo
 *
 * Created on July 15, 2024, 7:35 PM
 */

#ifndef MCAL_INTERNAL_INTERRUPT_H
#define	MCAL_INTERNAL_INTERRUPT_H

/* ----------------- Includes -----------------*/
#include "mcal_interrupt_config.h"

/* ----------------- Macro Declarations -----------------*/

/* ----------------- Macro Functions Declarations -----------------*/
#if ADC_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
/* This routine clears the interrupt enable for the ADC Module */
#define ADC_InterruptDisable()         (PIE1bits.ADIE = 0)
/* This routine sets the interrupt enable for the ADC Module */
#define ADC_InterruptEnable()          (PIE1bits.ADIE = 1)
/* This routine clears the interrupt flag for the ADC Module */
#define ADC_InterruptFlagClear()       (PIR1bits.ADIF = 0)
#if INTERRUPT_PRIORITY_LEVELS_ENABLE==INTERRUPT_FEATURE_ENABLE 
/* This routine set the ADC Module Interrupt Priority to be High priority */
#define ADC_HighPrioritySet()          (IPR1bits.ADIP = 1)
/* This routine set the ADC Module Interrupt Priority to be Low priority */
#define ADC_LowPrioritySet()           (IPR1bits.ADIP = 0)
#endif
#endif
/*------------------ Software Interfaces -------------------------*/





#endif /* MCAL_INTERNAL_INTERRUPT_H */