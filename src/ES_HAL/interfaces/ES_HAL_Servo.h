/**
 * @file    ES_HAL_Servo.h
 * @brief   Header file for the Servo module's interface
 * @details This file contains all HALL API functions specific to the Servo
 *          interface. These functions tap into the hardware-specific
 *          drivers, abstracting hardware-specific implementation from
 *          the user.
 */


#ifndef ES_HAL_SERVO_H
#define ES_HAL_SERVO_H

///////////////////////////////////////////////////////////////////////////
// Default Libraries
///////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "ES_HALConf.h"

#ifdef USE_ES_HAL_SERVO

///////////////////////////////////////////////////////////////////////////
// Driver constants, macros, enums, etc.
///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////
// HAL interface API (public) function prototypes
///////////////////////////////////////////////////////////////////////////
void Servo_Init(void);
void Servo_Start(void);
void Servo_Stop(void);
void Servo_Write(void);


///////////////////////////////////////////////////////////////////////////
// HAL interface drivers
///////////////////////////////////////////////////////////////////////////
#include "PIC32/Servo.h"
#include "x86_NIX/Servo.h"


#endif /* USE_ES_HAL_SERVO */

#endif /* ES_HAL_SERVO_H */
