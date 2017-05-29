/**
 * @file    PIC32/KeyInput.c
 * @brief   Source file for the PIC32 KeyInput module driver
 */


// Ensure code only compiles for PIC32 and when the interface is enabled
#if ES_HAL_SYS == PIC32 && defined(ES_HAL_USE_KEYINPUT)

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
void KeyInput_DriverInit(void) {
}

void KeyInput_DriverStart(void) {
}

void KeyInput_DriverStop(void) {
}

void KeyInput_DriverRead(void) {
}


#endif /* ES_HAL_SYS == PIC32 && defined(ES_HAL_USE_KEYINPUT) */
