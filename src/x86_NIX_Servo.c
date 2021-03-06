/**
 * @file    x86_NIX/Servo.c
 * @brief   Source file for the x86_NIX Servo module driver
 */


///////////////////////////////////////////////////////////////////////////
// Default Libraries
///////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "ES_HALConf.h"
#include "ES_HAL.h"
#include "x86_NIX_Servo.h"


// Ensure code only compiles for x86_NIX and when the interface is enabled
#if ES_HAL_SYS == x86_NIX && defined(USE_ES_HAL_SERVO)


///////////////////////////////////////////////////////////////////////////
// HAL driver function prototypes
///////////////////////////////////////////////////////////////////////////
void Servo_DriverInit(void) {
}

void Servo_DriverStart(void) {
}

void Servo_DriverStop(void) {
}

void Servo_DriverWrite(void) {
}


#endif /* ES_HAL_SYS == x86_NIX && defined(ES_HAL_USE_SERVO) */
