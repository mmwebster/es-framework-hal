/**
 * @file    ES_HAL.h
 * @brief   Main header file for the ES Framework Hardware Abstraction Layer (HAL)
 * @details This file contains all HAL API functions. All API functions are
 *          designed to sit on top of ES Framework s.t. a project previously no
 *          integrated with the HAL will immediately work after integration with
 *          HAL. To enable the HAL 
 */


#ifndef ES_HAL_H
#define ES_HAL_H

///////////////////////////////////////////////////////////////////////////
// Default Libraries
///////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "ES_HALConf.h"

#ifdef USE_ES_HAL

///////////////////////////////////////////////////////////////////////////
// HALConf error checking
///////////////////////////////////////////////////////////////////////////
#ifndef ES_HAL_USE_SERIAL
#error "ES_HAL_USE_SERIAL not defined in ES_HALConf.h"
#endif

#ifndef ES_HAL_USE_KEYINPUT
#error "ES_HAL_USE_KEYINPUT not defined in ES_HALConf.h"
#endif

#ifndef ES_HAL_USE_ADC
#error "ES_HAL_USE_ADC not defined in ES_HALConf.h"
#endif

#ifndef ES_HAL_USE_PWM
#error "ES_HAL_USE_PWM not defined in ES_HALConf.h"
#endif

#ifndef ES_HAL_USE_SERVO
#error "ES_HAL_USE_SERVO not defined in ES_HALConf.h"
#endif

#ifndef ES_HAL_USE_STEPPER
#error "ES_HAL_USE_STEPPER not defined in ES_HALConf.h"
#endif


///////////////////////////////////////////////////////////////////////////
// HAL Interfaces
///////////////////////////////////////////////////////////////////////////
#include "interfaces/ES_HAL_Serial.h"
#include "interfaces/ES_HAL_KeyInput.h"
#include "interfaces/ES_HAL_ADC.h"
#include "interfaces/ES_HAL_PWM.h"
#include "interfaces/ES_HAL_Servo.h"
#include "interfaces/ES_HAL_Stepper.h"
#include "interfaces/ES_HAL_Timers.h"
#include "interfaces/ES_HAL_System.h"


///////////////////////////////////////////////////////////////////////////
// Public function prototypes
///////////////////////////////////////////////////////////////////////////
void ES_HAL_Init(void);


#endif /* USE_ES_HAL */

#endif /* ES_HAL_H */
