/**
 * @file    x86_NIX/KeyInput.h
 * @brief   Header file for the x86_NIX KeyInput module driver
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
#if ES_HAL_SYS == x86_NIX && defined(USE_ES_HAL_KEYINPUT)

#ifndef KEYINPUT_H
#define KEYINPUT_H


///////////////////////////////////////////////////////////////////////////
// HAL driver function prototypes
///////////////////////////////////////////////////////////////////////////
void KeyInput_DriverInit(void);
void KeyInput_DriverStart(void);
void KeyInput_DriverStop(void);
void KeyInput_DriverRead(void);


#endif /* KEYINPUT_H */

#endif /* ES_HAL_SYS == x86_NIX && defined(ES_HAL_USE_KEYINPUT) */
