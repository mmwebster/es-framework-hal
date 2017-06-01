/**
 * @file    PIC32/Servo.h
 * @brief   Header file for the PIC32 Servo module driver
 */


///////////////////////////////////////////////////////////////////////////
// Default Libraries
///////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "ES_HALConf.h"
#include "ES_HAL.h"

// Module usage guard before standard header guard b/c all drivers for the same
// interface have the same file name
#if ES_HAL_SYS == PIC32 && defined(USE_ES_HAL_SERVO)

#ifndef SERVO_H
#define SERVO_H


///////////////////////////////////////////////////////////////////////////
// HAL driver function prototypes
///////////////////////////////////////////////////////////////////////////
#define MINPULSE 1000
#define MAXPULSE 2000

#define RC_PORTX03 0x001
#define RC_PORTX04 0x002
#define RC_PORTY06 0x004
#define RC_PORTY07 0x008
#define RC_PORTZ08 0x010
#define RC_PORTZ09 0x020
#define RC_PORTV03 0x040
#define RC_PORTV04 0x080
#define RC_PORTW07 0x100
#define RC_PORTW08 0x200


///////////////////////////////////////////////////////////////////////////
// HAL driver function prototypes
///////////////////////////////////////////////////////////////////////////
void Servo_DriverInit(void);
void Servo_DriverStart(void);
void Servo_DriverStop(void);
void Servo_DriverWrite(void);

/**
 * @Function RC_Init(void)
 * @param none
 * @return SUCCESS or ERROR
 * @brief Initialize the RC module for use. Uses TIMER4 hardware and initializes
 *        the interrupt to occur every 50msec (20Hz)
 * @author Gabriel Hugh Elkaim, 2011.12.15 16:42 */
char RC_Init(void);

/**
 * @Function RC_AddPins(unsigned short int RCpins)
 * @param RCpins, use #defined RC_PORTxxx OR'd together for each RC servo pin
 * @return SUCCESS or ERROR
 * @brief Enables pins in argument and initializes all enabled RC servo pins to
 *        1.5mSec pulse width (0 degree deflection). Re-enabling a previously
 *        enabled pin returns ERROR. Pin will actually enable at the end of the
 *        50msec cycle.
 * @author Gabriel Hugh Elkaim, 2013.07.24 12:25 */
char RC_AddPins(unsigned short int RCpins);

/**
 * @Function RC_RemovePins(unsigned short int RCpins)
 * @param RCpins - use #defined RC_PORTxxx OR'd together for each RC servo pin
 * @return SUCCESS or ERROR
 * @brief Shuts down each designated pin and turns it into an INPUT. Returns ERROR
 *        if the pin is not currently enabled.
 * @author Gabriel Hugh Elkaim, 2013.07.24 12:25 */
char RC_RemovePins(unsigned short int RCpins);

/**
 * @Function RC_ListPins(void)
 * @param none
 * @return RCpins - the mask of the pins that are currently active
 * @brief Returns a short with a 1 in each bit for each of the RC_PORTxxx that
 *        is enabled. Returns 0x0000 if no pins are enabled.
 * @note To verify RC_PORTxxx is enabled, test (RC_PORTxxx && RcListPins()), if
 *       the result is FALSE, then the pin is currently disabled.
 * @author Gabriel Hugh Elkaim, 2013.07.25 16:05 */
unsigned short int RC_ListPins(void);

/**
 * @Function RcSetPulseTime(unsigned short int RCpin, unsigned short int pulseTime)
 * @param RCpin - use #defined RC_PORTxxx (only one)
 * @param pulseTime - pulse width in uSeconds from [1000 to 2000]
 * @return SUCCESS or ERROR
 * @brief Sets servo pulse to desired value from 1mSec to 2mSec in 1uSec increments.
 * @author Gabriel Hugh Elkaim, 2011.12.15 16:42 */
char RC_SetPulseTime(unsigned short int RCpin, unsigned short int pulseTime);

/**
 * @Function RcGetPulseTime(unsigned short int RCpin)
 * @param RCpin - use #defined RC_PORTxxx (only one)
 * @return pulseTime - Pulse width in uSeconds
 * @brief Gets the servo pulse width, provided for symmetry.
 * @author Gabriel Hugh Elkaim, 2011.12.15 16:42 */
short int RC_GetPulseTime(unsigned short int RCpin);

/**
 * @Function RC_ChangePending(void)
 * @param none
 * @return TRUE or FALSE
 * @brief returns TRUE if change in RC pins pending
 * @author Gabriel Hugh Elkaim, 2013.08.18 21:56 */
char RC_ChangePending(void);

/**
 * @Function RcEnd(void)
 * @param none
 * @return SUCCESS or ERROR
 * @brief Shuts down the RC servo module. Releases TIMER4 and shuts down all
 *        servo outputs.
 * @author Gabriel Hugh Elkaim, 2011.12.15 16:42 */
char RC_End(void);


#endif /* SERVO_H */

#endif /* ES_HAL_SYS == PIC32 && defined(ES_HAL_USE_SERVO) */
