/**
 * @file    x86_NIX/KeyInput.c
 * @brief   Source file for the x86_NIX KeyInput module driver
 * @TODO    Abstract the keyboard input from the ES_KeyboardInput module in
 *          order to make the actual keyinput interface that used by the
 *          ES_KeyboardInput module.
 */


///////////////////////////////////////////////////////////////////////////
// Default Libraries
///////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "ES_HALConf.h"
#include "ES_HAL.h"
#include "x86_NIX_KeyInput.h"


// Ensure code only compiles for x86_NIX and when the interface is enabled
#if ES_HAL_SYS == x86_NIX && defined(USE_ES_HAL_KEYINPUT)


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


#endif /* ES_HAL_SYS == x86_NIX && defined(ES_HAL_USE_KEYINPUT) */
