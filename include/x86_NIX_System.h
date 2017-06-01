/**
 * @file    x86_NIX/System.h
 * @brief   Header file for the x86_NIX System module driver
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

#ifndef SYSTEM_H
#define SYSTEM_H


///////////////////////////////////////////////////////////////////////////
// HAL driver function prototypes
///////////////////////////////////////////////////////////////////////////
void System_DriverInit(void);
void System_DriverStart(void);
void System_DriverStop(void);


#endif /* SYSTEM_H */

#endif /* ES_HAL_SYS == x86_NIX */

