/**
 * @file    PIC32/Servo.c
 * @brief   Source file for the PIC32 Servo module driver
 */


// Ensure code only compiles for PIC32 and when the interface is enabled
#if ES_HAL_SYS == PIC32 && defined(ES_HAL_USE_SERVO)

///////////////////////////////////////////////////////////////////////////
// Default Libraries
///////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "ES_HALConf.h"
#include "ES_HAL.h"


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


#endif /* ES_HAL_SYS == PIC32 && defined(ES_HAL_USE_SERVO) */
