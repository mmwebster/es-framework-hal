/**
 * @file    x86_NIX/PWM.c
 * @brief   Source file for the x86_NIX PWM module driver
 */


///////////////////////////////////////////////////////////////////////////
// Default Libraries
///////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "ES_HALConf.h"
#include "ES_HAL.h"
#include "x86_NIX_PWM.h"


// Ensure code only compiles for x86_NIX and when the interface is enabled
#if ES_HAL_SYS == x86_NIX && defined(USE_ES_HAL_PWM)


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


#endif /* ES_HAL_SYS == x86_NIX && defined(ES_HAL_USE_PWM) */
