/**
 * @file    x86_NIX/System.c
 * @brief   Source file for the x86_NIX System module driver
 */


///////////////////////////////////////////////////////////////////////////
// Default Libraries
///////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "ES_HALConf.h"
#include "x86_NIX_System.h"


// Ensure code only compiles for x86_NIX and when the interface is enabled
#if ES_HAL_SYS == x86_NIX


///////////////////////////////////////////////////////////////////////////
// HAL driver function prototypes
///////////////////////////////////////////////////////////////////////////
void System_DriverInit(void) {
}

void System_DriverStart(void) {
}

void System_DriverStop(void) {
}




#endif /* ES_HAL_SYS == x86_NIX && defined(ES_HAL_USE_SYSTEM) */
