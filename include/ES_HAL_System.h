/**
 * @file    ES_HAL_System.h
 * @brief   Header file for the System module's interface
 * @details This file contains all HALL API functions specific to the System
 *          interface. These functions tap into the hardware-specific
 *          drivers, abstracting hardware-specific implementation from
 *          the user.
 * @note    This module has no usage header guard because it cannot be disabled
 *          and requires that a driver be defined for every supported system.
 */


#ifndef ES_HAL_SYSTEM_H
#define ES_HAL_SYSTEM_H

///////////////////////////////////////////////////////////////////////////
// Default Libraries
///////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "ES_HALConf.h"


///////////////////////////////////////////////////////////////////////////
// HAL interface API (public) function prototypes
///////////////////////////////////////////////////////////////////////////
void System_Init(void);
void System_Start(void);
void System_Stop(void);


///////////////////////////////////////////////////////////////////////////
// HAL interface drivers
///////////////////////////////////////////////////////////////////////////
#include "PIC32_System.h"
#include "x86_NIX_System.h"


#endif /* ES_HAL_SYSTEM_H */
