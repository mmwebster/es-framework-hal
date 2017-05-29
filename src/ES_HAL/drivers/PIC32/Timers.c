/**
 * @file    PIC32/Timers.c
 * @brief   Source file for the PIC32 Timers module driver
 */


// Ensure code only compiles for PIC32 and when the interface is enabled
// No check for ES_HAL_USE_TIMERS b/c it's a required interface
#if ES_HAL_SYS == PIC32

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
void Timers_DriverInit(void) {
}

void Timers_DriverStart(void) {
}

void Timers_DriverStop(void) {
}

void Timers_DriverRead(void) {
}


#endif /* ES_HAL_SYS == PIC32 && defined(ES_HAL_USE_TIMERS) */
