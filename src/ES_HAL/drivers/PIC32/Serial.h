/**
 * @file    PIC32/Serial.h
 * @brief   Header file for the PIC32 Serial module driver
 */


// Module usage guard before standard header guard b/c all drivers for the same
// interface have the same file name
#if ES_HAL_SYS == PIC32

///////////////////////////////////////////////////////////////////////////
// Default Libraries
///////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "ES_HALConf.h"

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

#endif /* ES_HAL_SYS == PIC32 */
