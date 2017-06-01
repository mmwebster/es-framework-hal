/**
 * @file    x86_NIX/Servo.h
 * @brief   Header file for the x86_NIX Servo module driver
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
#if ES_HAL_SYS == x86_NIX && defined(USE_ES_HAL_SERVO)

#ifndef SERVO_H
#define SERVO_H


///////////////////////////////////////////////////////////////////////////
// HAL driver function prototypes
///////////////////////////////////////////////////////////////////////////
void Servo_DriverInit(void);
void Servo_DriverStart(void);
void Servo_DriverStop(void);
void Servo_DriverWrite(void);


#endif /* SERVO_H */

#endif /* ES_HAL_SYS == x86_NIX && defined(ES_HAL_USE_SERVO) */
