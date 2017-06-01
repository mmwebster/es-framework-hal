/**
 * @file    x86_NIXg/Timers.c
 * @brief   Source file for the x86_NIXg Timers module driver
 */


///////////////////////////////////////////////////////////////////////////
// Default Libraries
///////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "ES_HALConf.h"
#include "x86_NIX_Timers.h"


// Ensure code only compiles for x86_NIXg and when the interface is enabled
// No check for ES_HAL_USE_TIMERS b/c it's a required interface
#if ES_HAL_SYS == x86_NIX


///////////////////////////////////////////////////////////////////////////
// HAL driver function prototypes
///////////////////////////////////////////////////////////////////////////
void Timers_DriverInit(void) {
}

void Timers_DriverStart(void) {
}

void Timers_DriverStop(void) {
}

void Timers_DriverRead(void) {
}


#endif /* ES_HAL_SYS == x86_NIXg && defined(ES_HAL_USE_TIMERS) */
