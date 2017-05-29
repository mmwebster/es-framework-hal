/**
 * @file    PIC32/Timers.h
 * @brief   Header file for the PIC32 Timers module driver
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

#ifndef TIMERS_H
#define TIMERS_H


///////////////////////////////////////////////////////////////////////////
// HAL driver function prototypes
///////////////////////////////////////////////////////////////////////////
void Timers_DriverInit(void);
void Timers_DriverStart(void);
void Timers_DriverStop(void);
void Timers_DriverRead(void);


#endif /* TIMERS_H */

#endif /* ES_HAL_SYS == PIC32 */
