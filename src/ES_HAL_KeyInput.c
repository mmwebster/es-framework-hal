/**
 * @file    ES_HAL_KeyInput.c
 * @brief   Source file for the KeyInput module's interface
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
#include "ES_HAL_KeyInput.h"

#ifdef USE_ES_HAL_KEYINPUT

///////////////////////////////////////////////////////////////////////////
// HAL interface API function implementations
///////////////////////////////////////////////////////////////////////////
void KeyInput_Init(void) {
  KeyInput_DriverInit();
}

void KeyInput_Start(void) {
  KeyInput_DriverStart();
}

void KeyInput_Stop(void) {
  KeyInput_DriverStop();
}

void KeyInput_Read(void) {
  KeyInput_DriverRead();
}


#endif /* USE_ES_HAL_KEYINPUT */
