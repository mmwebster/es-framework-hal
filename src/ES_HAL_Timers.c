/**
 * @file    ES_HAL_Timers.c
 * @brief   Source file for the Timers module's interface
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
#include "ES_HAL_Timers.h"

// This interface is required as the ES Framework cannot function without
// the timing provided by this interface.

///////////////////////////////////////////////////////////////////////////
// HAL interface API function implementations
///////////////////////////////////////////////////////////////////////////
void Timers_Init(void) {
  Timers_DriverInit();
}

void Timers_Start(void) {
  Timers_DriverStart();
}

void Timers_Stop(void) {
  Timers_DriverStop();
}

void Timers_Read(void) {
  Timers_DriverRead();
}
