/**
 * @file    PIC32/Serial.c
 * @brief   Source file for the PIC32 Serial module driver
 */


// Ensure code only compiles for PIC32 and when the interface is enabled
#if ES_HAL_SYS == PIC32 && defined(ES_HAL_USE_SERIAL)

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

#endif /* ES_HAL_SYS == PIC32 && defined(ES_HAL_USE_SERIAL) */
