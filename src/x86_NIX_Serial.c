/**
 * @file    x86_NIX/Serial.c
 * @brief   Source file for the x86_NIX Serial module driver
 */

///////////////////////////////////////////////////////////////////////////
// Default Libraries
///////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "ES_HALConf.h"
#include "ES_HAL.h"
#include "x86_NIX_Serial.h"


// Ensure code only compiles for x86_NIX and when the interface is enabled
#if ES_HAL_SYS == x86_NIX && defined(USE_ES_HAL_SERIAL)


///////////////////////////////////////////////////////////////////////////
// HAL driver function prototypes
///////////////////////////////////////////////////////////////////////////
void Serial_DriverInit(void) {
}

void Serial_DriverStart(void) {
}

void Serial_DriverStop(void) {
}

void Serial_DriverRead(void) {
}

void Serial_DriverWrite(void) {
}

#endif /* ES_HAL_SYS == x86_NIX && defined(ES_HAL_USE_SERIAL) */
