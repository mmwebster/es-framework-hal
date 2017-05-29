/**
 * @file    ES_HAL_System.c
 * @brief   Source file for the System module's interface
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

// Always include this source when the HAL is enabled
#ifdef USE_ES_HAL

///////////////////////////////////////////////////////////////////////////
// HAL interface API function implementations
///////////////////////////////////////////////////////////////////////////
void System_Init(void) {
  System_DriverInit();
}

void System_Start(void) {
  System_DriverStart();
}

void System_Stop(void) {
  System_DriverStop();
}


#endif /* USE_ES_HAL */
