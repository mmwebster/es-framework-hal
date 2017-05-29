/**
 * @file    ES_HAL_PWM.h
 * @brief   Header file for the PWM module's interface
 * @details This file contains all HALL API functions specific to the PWM
 *          interface. These functions tap into the hardware-specific
 *          drivers, abstracting hardware-specific implementation from
 *          the user.
 */


#ifndef ES_HAL_PWM_H
#define ES_HAL_PWM_H

///////////////////////////////////////////////////////////////////////////
// Default Libraries
///////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "ES_HALConf.h"

#ifdef USE_ES_HAL_PWM

///////////////////////////////////////////////////////////////////////////
// Driver constants, macros, enums, etc.
///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////
// HAL interface API (public) function prototypes
///////////////////////////////////////////////////////////////////////////
void PWM_Init(void);
void PWM_Start(void);
void PWM_Stop(void);
void PWM_Write(void);


///////////////////////////////////////////////////////////////////////////
// HAL interface drivers
///////////////////////////////////////////////////////////////////////////
#include "PIC32/PWM.h"
#include "x86_NIX/PWM.h"


#endif /* USE_ES_HAL_PWM */

#endif /* ES_HAL_PWM_H */