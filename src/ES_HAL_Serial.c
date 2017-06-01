/**
 * @file    ES_HAL_Serial.c
 * @brief   Source file for the Serial module's interface
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
#include "ES_HAL_Serial.h"

#ifdef USE_ES_HAL_SERIAL

///////////////////////////////////////////////////////////////////////////
// HAL interface API function implementations
///////////////////////////////////////////////////////////////////////////
void Serial_Init(void) {
  Serial_DriverInit();
}

void Serial_Start(void) {
  Serial_DriverStart();
}

void Serial_Stop(void) {
  Serial_DriverStop();
}

void Serial_Read(void) {
  Serial_DriverRead();
}

void Serial_Write(void) {
  Serial_DriverWrite();
}

#endif /* USE_ES_HAL_SERIAL */
