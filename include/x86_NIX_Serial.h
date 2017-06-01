/**
 * @file    x86_NIX/Serial.h
 * @brief   Header file for the x86_NIX Serial module driver
 */


///////////////////////////////////////////////////////////////////////////
// Default Libraries
///////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "ES_HALConf.h"
#include "ES_HAL.h"

// Module usage guard before standard header guard b/c all drivers for the same
// interface have the same file name
#if ES_HAL_SYS == x86_NIX && defined(USE_ES_HAL_SERIAL)

#ifndef SERIAL_H
#define SERIAL_H


///////////////////////////////////////////////////////////////////////////
// HAL driver function prototypes
///////////////////////////////////////////////////////////////////////////
void Serial_DriverInit(void);
void Serial_DriverStart(void);
void Serial_DriverStop(void);
void Serial_DriverRead(void);
void Serial_DriverWrite(void);


#endif /* SERIAL_H */

#endif /* ES_HAL_SYS == x86_NIX && defined(ES_HAL_USE_SERIAL) */
