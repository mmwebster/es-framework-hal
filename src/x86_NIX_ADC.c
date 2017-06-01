/**
 * @file    x86_NIX/ADC.c
 * @brief   Source file for the x86_NIX ADC module driver
 */


///////////////////////////////////////////////////////////////////////////
// Default Libraries
///////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "ES_HALConf.h"
#include "ES_HAL.h"
#include "x86_NIX_ADC.h"


// Ensure code only compiles for x86_NIX and when the interface is enabled
#if ES_HAL_SYS == x86_NIX && defined(USE_ES_HAL_ADC)


///////////////////////////////////////////////////////////////////////////
// HAL driver function prototypes
///////////////////////////////////////////////////////////////////////////
void ADC_DriverInit(void) {
}

void ADC_DriverStart(void) {
}

void ADC_DriverStop(void) {
}

void ADC_DriverRead(void) {
}


#endif /* ES_HAL_SYS == x86_NIX && defined(ES_HAL_USE_ADC) */
