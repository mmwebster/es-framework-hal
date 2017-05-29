/**
 * @file    PIC32/ADC.h
 * @brief   Header file for the PIC32 ADC module driver
 */


// Module usage guard before standard header guard b/c all drivers for the same
// interface have the same file name
#if ES_HAL_SYS == PIC32 && defined(ES_HAL_USE_ADC)

///////////////////////////////////////////////////////////////////////////
// Default Libraries
///////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "ES_HALConf.h"

#ifndef ADC_H
#define ADC_H

///////////////////////////////////////////////////////////////////////////
// Public #DEFINES
///////////////////////////////////////////////////////////////////////////
#define AD_PORTV3 (1<<0)
#define AD_PORTV4 (1<<1)
#define AD_PORTV5 (1<<2)
#define AD_PORTV6 (1<<3)
#define AD_PORTV7 (1<<4)
#define AD_PORTV8 (1<<5)
#define AD_PORTW3 (1<<6)
#define AD_PORTW4 (1<<7)
#define AD_PORTW5 (1<<8)
#define AD_PORTW6 (1<<9)
#define AD_PORTW7 (1<<10)
#define AD_PORTW8 (1<<11)
#define BAT_VOLTAGE (1<<12)
#define ROACH_LIGHT_SENSOR (1<<13)


///////////////////////////////////////////////////////////////////////////
// HAL driver function prototypes
///////////////////////////////////////////////////////////////////////////
void ADC_DriverInit(void);
void ADC_DriverStart(void);
void ADC_DriverStop(void);
void ADC_DriverRead(void);

/**
 * @Function AD_Init
 * @param None
 * @return SUCCESS or ERROR
 * @brief  Initializes the A/D subsystem and enable battery voltage monitoring.
 * @author Max Dunne, 2013.08.10 */
char AD_Init(void);

/**
 * @Function AD_AddPins(unsigned int AddPins)
 * @param RemovePins - use #defined AD_PORTxxx OR'd together for each A/D Pin you wish to remove
 * @return SUCCESS OR ERROR
 * @brief  Remove pins from the A/D system.  If any pin is not active it returns an
 * error
 * @note  None.
 * @author Max Dunne, 2013.08.15 */
char AD_AddPins(unsigned int NewPins);

/**
 * @Function AD_RemovePins(unsigned int RemovePins)
 * @param RemovePins - use #defined AD_PORTxxx OR'd together for each A/D Pin you wish to remove
 * @return SUCCESS OR ERROR
 * @brief  Remove pins from the A/D system.  If any pin is not active it returns an
 * error
 * @note  None.
 * @author Max Dunne, 2013.08.15 */
char AD_RemovePins(unsigned int NewPins);

/**
 * @Function AD_ActivePins(void)
 * @param None
 * @return Listing of all A/D pins that are active.
 * @brief  Returns a variable of all active A/D pins. An individual pin can be determined
 * if active by "anding" with the AD_PORTXX Macros
 * @note  This will not reflect changes made with add or remove pins until the next
 * A/D interrupt cycle
 * @author Max Dunne, 2013.08.15 */
unsigned int AD_ActivePins(void);

/**
 * @Function AD_IsNewDataReady(void)
 * @param None
 * @return TRUE or FALSE
 * @brief  This function returns a flag indicating that the A/D has new values since the last read of a value
 * @author Max Dunne, 2013.08.15 */
char AD_IsNewDataReady(void);

/**
 * @Function AD_ReadADPin(unsigned int Pin)
 * @param Pin, used #defined AD_PORTxxx to select pin
 * @return 10-bit AD Value or ERROR
 * @brief  Reads current value from buffer for given pin
 * @author Max Dunne, 2011.12.10 */
unsigned int  AD_ReadADPin(unsigned int NewPins);

/**
 * @Function AD_End(void)
 * @param None
 * @return None
 * @brief  disables the A/D subsystem and release the pins used
 * @author Max Dunne, 2013.09.20 */
void AD_End(void);


#endif /* ADC_H */

#endif /* ES_HAL_SYS == PIC32 && defined(ES_HAL_USE_ADC) */
