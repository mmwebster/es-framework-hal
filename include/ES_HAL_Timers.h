/**
 * @file    ES_HAL_Timers.h
 * @brief   Header file for the Timers module's interface
 * @details This file contains all HALL API functions specific to the Timers
 *          interface. These functions tap into the hardware-specific
 *          drivers, abstracting hardware-specific implementation from
 *          the user.
 *
 * @note    This module has no usage header guard because it cannot be disabled
 *          and requires that a driver be defined for every supported system.
 */


#ifndef ES_HAL_TIMERS_H
#define ES_HAL_TIMERS_H

///////////////////////////////////////////////////////////////////////////
// Default Libraries
///////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "ES_HALConf.h"

///////////////////////////////////////////////////////////////////////////
// Driver constants, macros, enums, etc.
///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////
// HAL interface API (public) function prototypes
///////////////////////////////////////////////////////////////////////////
void Timers_Init(void);
void Timers_Start(void);
void Timers_Stop(void);
void Timers_Read(void);


///////////////////////////////////////////////////////////////////////////
// HAL interface drivers
///////////////////////////////////////////////////////////////////////////
#include "PIC32_Timers.h"
#include "x86_NIX_Timers.h"


#endif /* ES_HAL_TIMERS_H */
