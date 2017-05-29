/**
 * @file    ES_HAL_Servo.c
 * @brief   Source file for the Servo module's interface
 * @todo    The interface functions here currently only serve as wrappers to
 *          the driver functions. Their final role will be to include all
 *          behavior that can be abstracted from the hardware. Wrappers was
 *          the quickest temporary solution.
 */


///////////////////////////////////////////////////////////////////////////
// Default Libraries
///////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "ES_HALConf.h"
#include "ES_HAL.h"

#ifdef USE_ES_HAL_SERVO

///////////////////////////////////////////////////////////////////////////
// HAL interface API function implementations
///////////////////////////////////////////////////////////////////////////
void Servo_Init(void) {
  Servo_DriverInit();
}

void Servo_Start(void) {
  Servo_DriverStart();
}

void Servo_Stop(void) {
  Servo_DriverStop();
}

void Servo_Write(void) {
  Servo_DriverWrite();
}


#endif /* USE_ES_HAL_SERVO */
