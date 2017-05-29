/**
 * @file    PIC32/KeyInput.h
 * @brief   Header file for the PIC32 KeyInput module driver
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

#endif /* ES_HAL_SYS == PIC32 */
