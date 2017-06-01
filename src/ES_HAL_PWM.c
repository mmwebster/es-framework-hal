/**
 * @file    ES_HAL_PWM.c
 * @brief   Source file for the PWM module's interface
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
#include "ES_HAL_PWM.h"

#ifdef USE_ES_HAL_PWM

///////////////////////////////////////////////////////////////////////////
// HAL interface API function implementations
///////////////////////////////////////////////////////////////////////////
void PWM_Init(void) {
  PWM_DriverInit();
}

void PWM_Start(void) {
  PWM_DriverStart();
}

void PWM_Stop(void) {
  PWM_DriverStop();
}

void PWM_Write(void) {
  PWM_DriverWrite();
}


#endif /* USE_ES_HAL_PWM */
