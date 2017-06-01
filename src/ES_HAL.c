/**
 * @file    ES_HAL.c
 * @brief   Main source file for the ES Framework Hardware Abstraction Layer (HAL)
 * @details This file contains all HAL API functions. All API functions are
 *          designed to sit on top of ES Framework s.t. a project previously no
 *          integrated with the HAL will immediately work after integration with
 *          HAL. To enable the HAL 
 */


// System libraries
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "ES_HALConf.h"
#include "ES_HAL.h"

#ifdef USE_ES_HAL

///////////////////////////////////////////////////////////////////////////
// Public function implementations
///////////////////////////////////////////////////////////////////////////
void ES_HAL_Init(void) {
  // print initialization message
  printf("ES Framework's Hardware Abstraction Layer Initialized.\n");

  // Initialize all enabled interfaces
#if USE_ES_HAL_SERIAL == TRUE
  Serial_Init();
#endif

#if USE_ES_HAL_KEYINPUT == TRUE
  KeyInput_Init();
#endif

// This enables the ADC module
#if USE_ES_HAL_ADC == TRUE
  ADC_Init();
#endif

// This enables the PWM module
#if USE_ES_HAL_PWM == TRUE
  PWM_Init();
#endif

// This enables the Servo module
#if USE_ES_HAL_SERVO == TRUE
  Servo_Init();
#endif

  // Initialize required libraries
  Timers_Init();
  System_Init();
}


#endif /* USE_ES_HAL */

// TODO: start writing all .c file implementations (abstractly) then bring in everything from the PIC32 legacy files. Then write a makefile
