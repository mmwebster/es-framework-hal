/**
 * @file    PIC32/Timers.h
 * @brief   Header file for the PIC32 Timers module driver
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

#ifndef TIMERS_H
#define TIMERS_H


///////////////////////////////////////////////////////////////////////////
// Public #DEFINES
///////////////////////////////////////////////////////////////////////////
#define TIMER_ACTIVE 1
#define TIMER_EXPIRED 1

#define TIMER_NOT_ACTIVE 0
#define TIMER_NOT_EXPIRED 0


///////////////////////////////////////////////////////////////////////////
// HAL driver function prototypes
///////////////////////////////////////////////////////////////////////////
void Timers_DriverInit(void);
void Timers_DriverStart(void);
void Timers_DriverStop(void);
void Timers_DriverRead(void);

/**
 * @Function TIMERS_Init(void)
 * @param none
 * @return None.
 * @brief  Initializes the timer module
 * @author Max Dunne, 2011.11.15 */
void TIMERS_Init(void);

/**
 * @Function TIMERS_StartTimer(unsigned char Num, unsigned int NewTime)
 * @param Num - the number of the timer to set.
 * @param NewTime -  the number of milliseconds to be counted
 * @return ERROR or SUCCESS
 * @brief  sets the time for a timer, but does not make it active.
 * @author Max Dunne  2011.11.15 */
char TIMERS_StartTimer(unsigned char Num);

/**
 * @Function TIMERS_SetTimer(unsigned char Num)
 * @param Num - the number of the timer to start
 * @return ERROR or SUCCESS
 * @brief  simply sets the active flag in TMR_ActiveFlags to resart a stopped timer.
 * @author Max Dunne, 2011.11.15 */
char TIMERS_SetTimer(unsigned char Num, unsigned int NewTime);

/**
 * @Function TIMERS_StopTimer(unsigned char Num)
 * @param Num - the number of the timer to stop.
 * @return ERROR or SUCCESS
 * @brief  simply clears the bit in TimerActiveFlags associated with this timer. This
 * will cause it to stop counting.
 * @author Max Dunne 2011.11.15 */
char TIMERS_StopTimer(unsigned char Num);

/**
 * @Function TIMERS_InitTimer(unsigned char Num, unsigned int NewTime)
 * @param Num -  the number of the timer to start
 * @param NewTime - the number of tick to be counted
 * @return ERROR or SUCCESS
 * @brief  sets the NewTime into the chosen timer and clears any previous event flag
 * and sets the timer actice to begin counting.
 * @author Max Dunne 2011.11.15 */
char TIMERS_InitTimer(unsigned char Num, unsigned int NewTime);

/**
 * @Function TIMERS_IsTimerActive(unsigned char Num)
 * @param Num - the number of the timer to check
 * @return ERROR or TIMER_NOT_ACTIVE or TIMER_ACTIVE
 * @brief  used to determine if a timer is currently counting.
 * @author Max Dunne   2011.11.15 */
char TIMERS_IsTimerActive(unsigned char Num);

/**
 * @Function TIMERS_IsTimerExpired(unsigned char Num)
 * @param Num - the number of the timer to check
 * @return ERROR or TIMER_NOT_EXPIRED or TIMER_EXPIRED
 * @brief  used to determine if a timer is currently expired.
 * @author Max Dunne   2011.11.15 */
char TIMERS_IsTimerExpired(unsigned char Num);

/**
 * @Function TIMERS_ClearTimerExpired(unsigned char Num)
 * @param Num - the timer whose event flag should be cleared.
 * @return ERROR or SUCCESS
 * @brief  simply clears the appropriate bit in Event Flags to show that the event
 * has been serviced.
 * @author Max Dunne  211.11.15 */
char TIMERS_ClearTimerExpired(unsigned char Num);


/**
 * Function: TIMERS_GetTime
 * @param None
 * @return FreeRunningTimer, the current value of the module variable FreeRunningTimer
 * @remark Provides the ability to grab a snapshot time as an alternative to using
 * the library timers. Can be used to determine how long between 2 events.
 * @author Max Dunne
 * @date 2011.11.15  */
unsigned int TIMERS_GetTime(void);


#endif /* TIMERS_H */

#endif /* ES_HAL_SYS == PIC32 */
