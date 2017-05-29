/**
 * @file    PIC32/Servo.h
 * @brief   Header file for the PIC32 Servo module driver
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

#endif /* ES_HAL_SYS == PIC32 */
