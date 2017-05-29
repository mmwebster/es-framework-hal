/**
 * @file    PIC32/ADC.c
 * @brief   Source file for the PIC32 ADC module driver
 */


// Ensure code only compiles for PIC32 and when the interface is enabled
#if ES_HAL_SYS == PIC32 && defined(ES_HAL_USE_ADC)

///////////////////////////////////////////////////////////////////////////
// Default Libraries
///////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "ES_HALConf.h"
#include "ES_HAL.h"


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


#endif /* ES_HAL_SYS == PIC32 && defined(ES_HAL_USE_ADC) */
