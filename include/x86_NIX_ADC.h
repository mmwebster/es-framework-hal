/**
 * @file    x86_NIX/ADC.h
 * @brief   Header file for the x86_NIX ADC module driver
 */


///////////////////////////////////////////////////////////////////////////
// Default Libraries
///////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "ES_HALConf.h"
#include "ES_HAL.h"

// Module usage guard before standard header guard b/c all drivers for the same
// interface have the same file name
#if ES_HAL_SYS == x86_NIX && defined(USE_ES_HAL_ADC)

#ifndef ADC_H
#define ADC_H


///////////////////////////////////////////////////////////////////////////
// HAL driver function prototypes
///////////////////////////////////////////////////////////////////////////
void ADC_DriverInit(void);
void ADC_DriverStart(void);
void ADC_DriverStop(void);
void ADC_DriverRead(void);


#endif /* ADC_H */

#endif /* ES_HAL_SYS == PIC32 && defined(ES_HAL_USE_ADC) */
