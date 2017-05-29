/**
 * @file    ES_HAL_KeyInput.h
 * @brief   Header file for the KeyInput module's interface
 * @details This file contains all HALL API functions specific to the KeyInput
 *          interface. These functions tap into the hardware-specific
 *          drivers, abstracting hardware-specific implementation from
 *          the user.
 */


#ifndef ES_HAL_KEYINPUT_H
#define ES_HAL_KEYINPUT_H

///////////////////////////////////////////////////////////////////////////
// Default Libraries
///////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "ES_HALConf.h"

#ifdef USE_ES_HAL_KEYINPUT

///////////////////////////////////////////////////////////////////////////
// Driver constants, macros, enums, etc.
///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////
// HAL interface API (public) function prototypes
///////////////////////////////////////////////////////////////////////////
void KeyInput_Init(void);
void KeyInput_Start(void);
void KeyInput_Stop(void);
void KeyInput_Read(void);


///////////////////////////////////////////////////////////////////////////
// HAL interface drivers
///////////////////////////////////////////////////////////////////////////
#include "PIC32/KeyInput.h"
#include "x86_NIX/KeyInput.h"


#endif /* USE_ES_HAL_KEYINPUT */

#endif /* ES_HAL_KEYINPUT_H */
