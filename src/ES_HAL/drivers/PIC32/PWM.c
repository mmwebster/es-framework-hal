/**
 * @file    PIC32/PWM.c
 * @brief   Source file for the PIC32 PWM module driver
 */


// Ensure code only compiles for PIC32 and when the interface is enabled
#if ES_HAL_SYS == PIC32 && defined(ES_HAL_USE_PWM)

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
void PWM_DriverInit(void) {
}

void PWM_DriverStart(void) {
}

void PWM_DriverStop(void) {
}

void PWM_DriverWrite(void) {
}


#endif /* ES_HAL_SYS == PIC32 && defined(ES_HAL_USE_PWM) */
