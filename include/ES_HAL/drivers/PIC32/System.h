/**
 * @file    PIC32/System.h
 * @brief   Header file for the PIC32 System module driver
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

#ifndef SYSTEM_H
#define SYSTEM_H


///////////////////////////////////////////////////////////////////////////
// HAL driver function prototypes
///////////////////////////////////////////////////////////////////////////
void System_DriverInit(void);
void System_DriverStart(void);
void System_DriverStop(void);


#endif /* SYSTEM_H */

#endif /* ES_HAL_SYS == PIC32 */

