/**
 * @file    PIC32/System.c
 * @brief   Source file for the PIC32 System module driver
 */


// Ensure code only compiles for PIC32 and when the interface is enabled
#if ES_HAL_SYS == PIC32 && defined(ES_HAL_USE_SYSTEM)

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
void System_DriverInit(void) {
}

void System_DriverStart(void) {
}

void System_DriverStop(void) {
}


#endif /* ES_HAL_SYS == PIC32 && defined(ES_HAL_USE_SYSTEM) */
