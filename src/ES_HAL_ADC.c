/**
 * @file    ES_HAL_ACD.c
 * @brief   Source file for the ADC module's interface
 * @todo    The interface functions here currently only serve as wrappers to
 *          the driver functions. Their final role will be to include all
 *          behavior that can be abstracted from the hardware. Wrappers was
 *          the quickest temporary solution.
 */


///////////////////////////////////////////////////////////////////////////
// Default Libraries
///////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "ES_HALConf.h"
#include "ES_HAL.h"
#include "ES_HAL_ADC.h"

#ifdef USE_ES_HAL_ADC

///////////////////////////////////////////////////////////////////////////
// HAL interface API function implementations
///////////////////////////////////////////////////////////////////////////
void ADC_Init(void) {
  ADC_DriverInit();
}

void ADC_Start(void) {
  ADC_DriverStart();
}

void ADC_Stop(void) {
  ADC_DriverStop();
}

void ADC_Read(void) {
  ADC_DriverRead();
}


#endif /* USE_ES_HAL_ADC */
