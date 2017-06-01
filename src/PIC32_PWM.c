/**
 * @file    PIC32/PWM.c
 * @brief   Source file for the PIC32 PWM module driver
 */


// Ensure code only compiles for PIC32 and when the interface is enabled
#if ES_HAL_SYS == PIC32 && defined(ES_HAL_USE_PWM)

///////////////////////////////////////////////////////////////////////////
// Default Libraries
///////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "ES_HALConf.h"
#include "ES_HAL.h"
#include "PIC32_PWM.h"


#include <xc.h>
#include <peripheral/outcompare.h>
#include <peripheral/timer.h>


///////////////////////////////////////////////////////////////////////////
// Private #DEFINES
///////////////////////////////////////////////////////////////////////////
#define F_PB (BOARD_GetPBClock())

//#define PWM_DEBUG_VERBOSE
#ifdef PWM_DEBUG_VERBOSE
#include "serial.h"
#define dbprintf(...) while(!IsTransmitEmpty()); printf(__VA_ARGS__)
#else
#define dbprintf(...)
#endif

#define ALLPWMPINS (PWM_PORTZ06|PWM_PORTY12|PWM_PORTY10|PWM_PORTY04|PWM_PORTX11)
#define NUM_PWM_CHANNELS 5


///////////////////////////////////////////////////////////////////////////
// Private variables
///////////////////////////////////////////////////////////////////////////
static unsigned char PWMActive = FALSE;
//static unsigned int usedChannels;
static volatile unsigned int * const Duty_Registers[] = {&OC1RS, &OC2RS, &OC3RS, &OC4RS, &OC5RS};
static volatile unsigned int * const Reset_Registers[] = {&OC1R, &OC2R, &OC3R, &OC4R, &OC5R};
static volatile unsigned int * const Config_Registers[] = {&OC1CON, &OC2CON, &OC3CON, &OC4CON, &OC5CON};
static unsigned int PWMActivePins;
static unsigned int PWMFrequency;


///////////////////////////////////////////////////////////////////////////
// HAL driver function prototypes
///////////////////////////////////////////////////////////////////////////
void PWM_DriverInit(void) {
}

void PWM_DriverStart(void) {
}

void PWM_DriverStop(void) {
}

void PWM_DriverWrite(void) {
}


/**
 * @Function PWM_Init(void)
 * @param None
 * @return SUCCESS or ERROR
 * @brief  Initializes the timer for the PWM system and set is to the default frequency
 * @note  None.
 * @author Max Dunne, 2011.11.12 */
char PWM_Init(void)
{
    if (PWMActive) {
        dbprintf("%s tried to init when already initialized", __FUNCTION__);
        return ERROR;
    }
    PWMActive = TRUE;
    PWM_SetFrequency(PWM_DEFAULT_FREQUENCY);
    PWMActivePins = 0;
    return SUCCESS;
}

/**
 * @Function PWM_SetFrequency(unsigned int NewFrequency)
 * @param NewFrequency - new frequency to set. best to use #defined from header
 * @return SUCCESS OR ERROR
 * @brief  Changes the frequency of the PWM system.
 * @note  Behavior of PWM channels during Frequency change is undocumented
 * @author Max Dunne, 2013.08.19 */
char PWM_SetFrequency(unsigned int NewFrequency)
{
    if (!PWMActive) {
        dbprintf("%s called before enable\r\n", __FUNCTION__);
        return ERROR;
    }
    if ((NewFrequency < MIN_PWM_FREQ) | (MAX_PWM_FREQ < NewFrequency)) {
        dbprintf("%s called with frequency outside bounds: %d", __FUNCTION__, NewFrequency);
        return ERROR;
    }
    if (NewFrequency != 0) {
        //turn off the timer in preperation to restarting it with the new fequency
        T2CON = 0;
    }
    if (NewFrequency <= 1000) {
        OpenTimer2(T2_ON | T2_PS_1_32, F_PB / 32 / NewFrequency);
        dbprintf("Period less than 1KHz, setting prescaler to 32\r\n");
    } else {
        OpenTimer2(T2_ON | T2_PS_1_1, F_PB / NewFrequency);
        dbprintf("Period greater than 1KHz, setting prescaler to 1\r\n");
    }
    PWMFrequency=NewFrequency;
    return SUCCESS;
}

/**
 * @Function PWM_GetFrequency(void)
 * @return Frequency of system in Hertz
 * @brief  gets the frequency of the PWM system.
 * @author Max Dunne, 2013.08.19 */
unsigned int PWM_GetFrequency(void)
{
    if (!PWMActive) {
        dbprintf("%s called before enable\r\n", __FUNCTION__);
        return ERROR;
    }
    return (PWMFrequency);
}

/**
 * @Function PWM_AddPins(unsigned short int AddPins)
 * @param AddPins - use #defined PWM_PORTxxx OR'd together for each A/D Pin you wish to add
 * @return SUCCESS OR ERROR
 * @brief  Adds new pins to the PWM system.  If any pin is already active it errors 
 * out
 * @author Max Dunne, 2013.08.15 */
char PWM_AddPins(unsigned short int AddPins)
{
    if (!PWMActive) {
        dbprintf("%s returning ERROR before enable\r\n", __FUNCTION__);
        return ERROR;
    }
    if ((AddPins == 0) || (AddPins > ALLPWMPINS)) {
        dbprintf("%s returning ERROR with pins outside range: %X\r\n", __FUNCTION__, AddPins);
        return ERROR;
    }

    if (PWMActivePins & AddPins) {
        dbprintf("%s Returning ERROR for pins already in state: %X \r\n", __FUNCTION__, AddPins);
        return ERROR;
    }
    int PinCount = 0;
    //sets new pwm pins in the on state while setting their duty cycles to zero
    for (PinCount = 0; PinCount < ALLPWMPINS; PinCount++) {
        if (AddPins & (1 << PinCount)) {
            *Duty_Registers[PinCount] = 0;
            *Reset_Registers[PinCount] = 0;
            *Config_Registers[PinCount] = (OC_ON | OC_TIMER2_SRC | OC_PWM_FAULT_PIN_DISABLE);
            dbprintf("PWM pin #%d has been added to the system\r\n", PinCount);
        }
    }

    PWMActivePins |= AddPins;
    return SUCCESS;
}

/**
 * @Function PWM_RemovePins(unsigned int PWMPins)
 * @param RemovePins - use #defined AD_PORTxxx OR'd together for each A/D Pin you wish to remove
 * @return SUCCESS OR ERROR
 * @brief  Remove pins from the PWM system.  If any pin is not active it errors out
 * @author Max Dunne, 2013.08.15 */
char PWM_RemovePins(unsigned int PWMPins)
{
    if (!PWMActive) {
        dbprintf("%s returning ERROR before enable\r\n", __FUNCTION__);
        return ERROR;
    }
    if ((PWMPins == 0) || (PWMPins > ALLPWMPINS)) {
        dbprintf("%s returning ERROR with pins outside range: %X\r\n", __FUNCTION__, PWMPins);
        return ERROR;
    }
    if (!(PWMActivePins & PWMPins)) {
        dbprintf("%s Returning ERROR for pins already in state: %X \r\n", __FUNCTION__, PWMPins);
        return ERROR;
    }
    int PinCount = 0;
    for (PinCount = 0; PinCount < ALLPWMPINS; PinCount++) {
        if (PWMPins & (1 << PinCount)) {
            *Duty_Registers[PinCount] = 0;
            *Reset_Registers[PinCount] = 0;
            *Config_Registers[PinCount] &= (~_OC1CON_ON_MASK);
        }
    }
    PWMActivePins &= (~PWMPins);
    return SUCCESS;
}

/**
 * @Function PWM_ListPins(void)
 * @param None
 * @return Listing of all PWM pins that are active.
 * @brief  Returns a variable of all active pwm pins. An individual pin can be determined 
 * if active by "anding" with the pwm_PORTXX Macros
 * @author Max Dunne, 2013.08.19 */
unsigned int PWM_ListPins(void)
{
    return PWMActivePins;
}

/**
 * Function  PWM_SetDutyCycle
 * @param Channels, use #defined PWM_PORTxxx
 * @param Duty, duty cycle for the channel (0-1000)
 * @return SUCCESS or ERROR
 * @remark Sets the Duty Cycle for a Single Channel and returns error if that channel is not enabled
 * @author Max Dunne
 * @date 2011.11.12  */
char PWM_SetDutyCycle(unsigned char Channel, unsigned int Duty)
{
    if (!PWMActive) {
        dbprintf("%s returning ERROR before enable\r\n", __FUNCTION__);
        return ERROR;
    }
    if ((Channel == 0 || Channel > ALLPWMPINS)) {
        dbprintf("%s returning error with pin out of bounds: %X\r\n", __FUNCTION__, Channel);
        return ERROR;
    }
    if (!(Channel & PWMActivePins)) {
        dbprintf("%s returning error with unactivated pin: %X %X\r\n", __FUNCTION__, Channel, PWMActivePins);
        return ERROR;
    }
    if (Duty < 0 || Duty > 1000) {
        dbprintf("%s returning error with duty cycle out of bounds: %d\r\n", __FUNCTION__, Duty);
        return ERROR;
    }

    unsigned int ScaledDuty = 0;
    unsigned int TranslatedChannel = 0;
    ScaledDuty = ((PR2 + 1) * Duty) / MAX_PWM;
    while (Channel > 1) {
        Channel >>= 1;
        TranslatedChannel++;
    }
    dbprintf("Translated Channel is %d and Scaled Duty is %d\r\n", TranslatedChannel, ScaledDuty);
    *Duty_Registers[TranslatedChannel] = ScaledDuty;
    return SUCCESS;

}

/**
 * Function  PWM_GetDutyCycle
 * @param Channels, use #defined PWM_PORTxxx
 *
 * @return Duty cycle
 * @remark Gets the Duty Cycle for a Single Channel and returns error if that channel is not enabled
 * @author Max Dunne
 * @date 2011.11.12  */
unsigned int PWM_GetDutyCycle(char Channel)
{
    if (!PWMActive) {
        dbprintf("%s returning ERROR before enable\r\n", __FUNCTION__);
        return ERROR;
    }
    if ((Channel == 0 || Channel > ALLPWMPINS)) {
        dbprintf("%s returning error with pin out of bounds: %X\r\n", __FUNCTION__, Channel);
        return ERROR;
    }
    if (!(Channel & PWMActivePins)) {
        dbprintf("%s returning error with unactivated pin: %X %X\r\n", __FUNCTION__, Channel, PWMActivePins);
        return ERROR;
    }

    unsigned int ScaledDuty = 0;
    unsigned int Duty = 0;
    unsigned int TranslatedChannel = 0;

    while (Channel > 1) {
        Channel >>= 1;
        TranslatedChannel++;
    }
    ScaledDuty = *Duty_Registers[TranslatedChannel];
    Duty = (ScaledDuty * MAX_PWM) / (PR2 + 1) + 1;
    if (Duty > MAX_PWM) {
        //one off error due to integer division
        Duty = MAX_PWM;
    }
    dbprintf("Translated Channel is %d and unScaled Duty is %d\r\n", TranslatedChannel, Duty);

    return Duty;

}

/**
 * Function: PWM_End
 * @param None
 * @return SUCCESS or ERROR
 * @remark Disables the PWM sub-system and releases all pins.
 * @author Max Dunne
 * @date 2011.11.12  */
char PWM_End(void)
{
    int Curpin;
    if (!PWMActive) {
        return ERROR;
    }
    for (Curpin = 0; Curpin < NUM_PWM_CHANNELS; Curpin++) {
        *Duty_Registers[Curpin] = 0;
        *Reset_Registers[Curpin] = 0;
    }
    INTEnable(INT_T2, INT_DISABLED);
    INTEnable(INT_OC1, INT_DISABLED);
    INTEnable(INT_OC2, INT_DISABLED);
    INTEnable(INT_OC3, INT_DISABLED);
    INTEnable(INT_OC4, INT_DISABLED);
    INTEnable(INT_OC5, INT_DISABLED);
    OC1CONCLR = _OC1CON_ON_MASK;
    OC2CONCLR = _OC2CON_ON_MASK;
    OC3CONCLR = _OC3CON_ON_MASK;
    OC4CONCLR = _OC4CON_ON_MASK;
    OC5CONCLR = _OC5CON_ON_MASK;

    PWMActive = FALSE;
    PWMFrequency = 0;
    return SUCCESS;
}


#endif /* ES_HAL_SYS == PIC32 && defined(ES_HAL_USE_PWM) */
