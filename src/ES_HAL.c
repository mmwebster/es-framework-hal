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

#define NUM_INTERFACES 7
#define INTERFACE_MAX_NAME_LEN 8
#define SYSTEM_STR "SYSTEM "
#define TIMERS_STR "TIMERS "
#define INTERFACE_STR SYSTEM_STR \
                      TIMERS_STR \
                      SERIAL_STR \
                      KEYINPUT_STR \
                      ADC_STR \
                      PWM_STR \
                      SERVO_STR

///////////////////////////////////////////////////////////////////////////
// Public function implementations
///////////////////////////////////////////////////////////////////////////
void ES_HAL_Init(void) {

  char *enabled_interfaces_str[NUM_INTERFACES] = { 0 };

  // Initialize all enabled interfaces
#if USE_ES_HAL_SERIAL == YES
  Serial_Init();
#define SERIAL_STR "SERIAL "
#else
#define SERIAL_STR ""
#endif

#if USE_ES_HAL_KEYINPUT == YES
  KeyInput_Init();
#define KEYINPUT_STR "KEYINPUT "
#else
#define KEYINPUT_STR ""
#endif

// This enables the ADC module
#if USE_ES_HAL_ADC == YES
  ADC_Init();
#define ADC_STR "ADC "
#else
#define ADC_STR ""
#endif

// This enables the PWM module
#if USE_ES_HAL_PWM == YES
  PWM_Init();
#define PWM_STR "PWM "
#else
#define PWM_STR ""
#endif

// This enables the Servo module
#if USE_ES_HAL_SERVO == YES
  Servo_Init();
#define SERVO_STR "SERVO "
#else
#define SERVO_STR ""
#endif

  // Initialize required libraries
  Timers_Init();
  System_Init();

  // print initialization message
#if USE_ES_HAL_DEBUG_MODE == YES
  printf("ES_HAL ==> Initialized with interfaces: %s\n", INTERFACE_STR);
#endif
}


#endif /* USE_ES_HAL */

// TODO: start writing all .c file implementations (abstractly) then bring in everything from the PIC32 legacy files. Then write a makefile
