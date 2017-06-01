/**
 * @file    PIC32/KeyInput.h
 * @brief   Header file for the PIC32 KeyInput module driver
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
#if ES_HAL_SYS == PIC32 && defined(USE_ES_HAL_KEYINPUT)

#ifndef KEYINPUT_H
#define KEYINPUT_H


///////////////////////////////////////////////////////////////////////////
// HAL driver function prototypes
///////////////////////////////////////////////////////////////////////////
void KeyInput_DriverInit(void);
void KeyInput_DriverStart(void);
void KeyInput_DriverStop(void);
void KeyInput_DriverRead(void);

/**
 * @Function InitKeyboardInput(uint8_t Priority)
 * @param Priority - internal variable to track which event queue to use
 * @return TRUE or FALSE
 * @brief this initializes the keyboard input system which
 *        Returns TRUE if successful, FALSE otherwise
 * @author Max Dunne , 2013.09.26 */
uint8_t InitKeyboardInput(uint8_t Priority);


/**
 * @Function PostKeyboardInput(ES_Event ThisEvent)
 * @param ThisEvent - the event (type and param) to be posted to queue
 * @return TRUE or FALSE
 * @brief Used to post events to keyboard input
 *        Returns TRUE if successful, FALSE otherwise
* @author Max Dunne , 2013.09.26 */
uint8_t PostKeyboardInput(ES_Event ThisEvent);


/**
 * @Function RunKeyboardInput(ES_Event ThisEvent)
 * @param ThisEvent - the event (type and param) to be responded.
 * @return ES_NO_EVENT
 * @brief Keyboard input only accepts the ES_KEYINPUT event and will always return
 * ES_NO_EVENT. it parses strings of the form EVENTNUM->EVENTPARAMHEX or
 * EVENTNUM and passes them to the state machine defined by
 * POSTFUNCTION_FOR_KEYBOARD_INPUT.
 * @note WARNING: you must have created the EventNames Array to use this module
* @author Max Dunne , 2013.09.26 */
ES_Event RunKeyboardInput(ES_Event ThisEvent);


/**
 * @Function KeyboardInput_PrintEvents(void)
 * @param None
 * @return None
 * @brief  Lists out all Events in the EventNames array.
 * @author Max Dunne, 2013.09.26 */
void KeyboardInput_PrintEvents(void);


#endif /* KEYINPUT_H */

#endif /* ES_HAL_SYS == PIC32 && defined(ES_HAL_USE_KEYINPUT) */
