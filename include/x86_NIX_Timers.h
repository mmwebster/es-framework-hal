/**
 * @file    x86_NIX/Timers.h
 * @brief   Header file for the x86_NIX Timers module driver
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
#if ES_HAL_SYS == x86_NIX

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

#endif /* ES_HAL_SYS == x86_NIX */
