/**
 * @file    ES_HAL.c
 * @brief   Main source file for the ES Framework Hardware Abstraction Layer (HAL)
 * @details This file contains all HAL API functions. All API functions are
 *          designed to sit on top of ES Framework s.t. a project previously no
 *          integrated with the HAL will immediately work after integration with
 *          HAL. To enable the HAL 
 */


#ifndef ES_HAL_H
#define ES_HAL_H

// System libraries
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#ifdef USE_ES_HAL

///////////////////////////////////////////////////////////////////////////
// ...
///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////
// Private function prototypes
///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////
// Public function implementations
///////////////////////////////////////////////////////////////////////////
void ES_HAL_Init(void) {
  // print initialization message
  printf("ES Framework's Hardware Abstraction Layer Initialized.");
}


#endif /* USE_ES_HAL */

#endif /* ES_HAL_H */

// TODO: start writing all .c file implementations (abstractly) then bring in everything from the PIC32 legacy files. Then write a makefile
