/**
 * @file    PIC32/PWM.h
 * @brief   Header file for the PIC32 PWM module driver
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

#ifndef PWM_H
#define PWM_H


///////////////////////////////////////////////////////////////////////////
// HAL driver function prototypes
///////////////////////////////////////////////////////////////////////////
void PWM_DriverInit(void);
void PWM_DriverStart(void);
void PWM_DriverStop(void);
void PWM_DriverWrite(void);


#endif /* PWM_H */

#endif /* ES_HAL_SYS == PIC32 */
