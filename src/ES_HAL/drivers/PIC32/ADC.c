/**
 * @file    PIC32/ADC.c
 * @brief   Source file for the PIC32 ADC module driver
 */


// Ensure code only compiles for PIC32 and when the interface is enabled
#if ES_HAL_SYS == PIC32 && defined(ES_HAL_USE_ADC)

///////////////////////////////////////////////////////////////////////////
// Default Libraries
///////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "ES_HALConf.h"
#include "ES_HAL.h"
#include "PIC32/ADC.h"

#include <xc.h>
#include <BOARD.h>
#include <peripheral/adc10.h>
#include <peripheral/ports.h>
#include <peripheral/power.h>


///////////////////////////////////////////////////////////////////////////
// Private #DEFINES
///////////////////////////////////////////////////////////////////////////
#define NUM_AD_PINS 14
#define NUM_AD_PINS_UNO 16

#ifdef IM_A_ROACH
#define BAT_VOLTAGE_MONITOR AD_PORTV3
#error //note from MaxL:  This is deprecated.  Please do not use the IM_A_ROACH flag.
#else
#define BAT_VOLTAGE_MONITOR BAT_VOLTAGE
#endif

#define BAT_VOLTAGE_LOCKOUT 263
#define BAT_VOLTAGE_NO_BAT 169

//#define AD_DEBUG_VERBOSE
#ifdef AD_DEBUG_VERBOSE
#include "serial.h"
#define dbprintf(...) while(!IsTransmitEmpty()); printf(__VA_ARGS__)
#else
#define dbprintf(...)
#endif


//battery filter definitions
#define FILTER_POWER (11)
#define KEEP_PERCENTAGE ((float).9)
#define ADD_PERCENTAGE (1-KEEP_PERCENTAGE)

#define KEEP_FILT ((int)((2<<(FILTER_POWER-1))*KEEP_PERCENTAGE))
#define ADD_FILT ((int)((2<<(FILTER_POWER-1))*ADD_PERCENTAGE))
#define SHIFT_FILT (FILTER_POWER)
#define ALLADPINS (AD_PORTV3|AD_PORTV4|AD_PORTV5|AD_PORTV6|AD_PORTV7|AD_PORTV8|AD_PORTW3|AD_PORTW4|AD_PORTW5|AD_PORTW6|AD_PORTW7|AD_PORTW8|BAT_VOLTAGE|ROACH_LIGHT_SENSOR)
#define BATFILT_HISTORY_LENGTH 2
#define POINTS_PER_SECOND_PER_PIN 9345
#define FREQUENCY_TO_SAMPLE 1


///////////////////////////////////////////////////////////////////////////
// Private variables
///////////////////////////////////////////////////////////////////////////
static unsigned int AD1PCFG_MASKS[NUM_AD_PINS] = {ENABLE_AN2_ANA, ENABLE_AN3_ANA,
    ENABLE_AN4_ANA, ENABLE_AN5_ANA, ENABLE_AN8_ANA, ENABLE_AN9_ANA,
    ENABLE_AN11_ANA, ENABLE_AN10_ANA, ENABLE_AN13_ANA, ENABLE_AN12_ANA,
    ENABLE_AN15_ANA, ENABLE_AN14_ANA, ENABLE_AN1_ANA,ENABLE_AN0_ANA};

static unsigned int AD1CSSL_MASKS[NUM_AD_PINS] = {SKIP_SCAN_AN2, SKIP_SCAN_AN3,
    SKIP_SCAN_AN4, SKIP_SCAN_AN5, SKIP_SCAN_AN8, SKIP_SCAN_AN9,
    SKIP_SCAN_AN11, SKIP_SCAN_AN10, SKIP_SCAN_AN13, SKIP_SCAN_AN12,
    SKIP_SCAN_AN15, SKIP_SCAN_AN14, SKIP_SCAN_AN1,SKIP_SCAN_AN0};

static unsigned int AD1PCFG_POS[NUM_AD_PINS] = {_AD1PCFG_PCFG2_POSITION, _AD1PCFG_PCFG3_POSITION,
    _AD1PCFG_PCFG4_POSITION, _AD1PCFG_PCFG5_POSITION, _AD1PCFG_PCFG8_POSITION, _AD1PCFG_PCFG9_POSITION,
    _AD1PCFG_PCFG11_POSITION, _AD1PCFG_PCFG10_POSITION, _AD1PCFG_PCFG13_POSITION, _AD1PCFG_PCFG12_POSITION,
    _AD1PCFG_PCFG15_POSITION, _AD1PCFG_PCFG14_POSITION, _AD1PCFG_PCFG1_POSITION,_AD1PCFG_PCFG0_POSITION};


static unsigned int ActivePins;
static unsigned int PinsToAdd;
static unsigned int PinsToRemove;
static unsigned int PinCount;
static unsigned int ADValues[NUM_AD_PINS];
static int PortMapping[NUM_AD_PINS];

static char ADActive;
static char ADNewData = FALSE;


static int Filt_BatVoltage = 1023;
static int CurFilt_BatVoltage = 0;
static int PrevFilt_BatVoltage = 0;
//static uint16_t BatFiltHistory[BATFILT_HISTORY_LENGTH] = {0};
//static uint8_t BatFiltHistoryCurPoint = -1;
static uint32_t PointsPerBatSamples = 0;
static uint32_t SampleCount = 0;


///////////////////////////////////////////////////////////////////////////
// Private function prototypes
///////////////////////////////////////////////////////////////////////////
char AD_SetPins(void);


///////////////////////////////////////////////////////////////////////////
// HAL driver function prototypes
///////////////////////////////////////////////////////////////////////////
void ADC_DriverInit(void) {
}

void ADC_DriverStart(void) {
}

void ADC_DriverStop(void) {
}

void ADC_DriverRead(void) {
}


/**
 * @Function AD_Init
 * @param None
 * @return SUCCESS or ERROR
 * @brief  Initializes the A/D subsystem and enable battery voltage monitoring.
 * @author Max Dunne, 2013.08.10 */
char AD_Init(void)
{

    if (ADActive) {
        return ERROR;
    }
    int pin = 0;
    //ensure that the battery monitor is active
    ActivePins = BAT_VOLTAGE_MONITOR;
    ADActive = TRUE;
    AD_SetPins();
    for (pin = 0; pin < NUM_AD_PINS; pin++) {
        ADValues[pin] = -1;
    }
    INTEnable(INT_AD1, INT_DISABLED);
    INTClearFlag(INT_AD1);
    INTSetVectorPriority(INT_ADC_VECTOR, 1);
    INTSetVectorSubPriority(INT_ADC_VECTOR, 3);
    INTEnable(INT_AD1, INT_ENABLED);
    EnableADC10();
    ADNewData = FALSE;
    //wait for first reading to ensure  battery monitor starts in the right spot
    while (!AD_IsNewDataReady()) {
#ifdef AD_DEBUG_VERBOSE
        PutChar('.');
#endif
    }
    //set the first values for the battery monitor filter
    Filt_BatVoltage = AD_ReadADPin(BAT_VOLTAGE_MONITOR);
    CurFilt_BatVoltage = Filt_BatVoltage;
    PrevFilt_BatVoltage = Filt_BatVoltage;

    return SUCCESS;
}

/**
 * @Function AD_AddPins(unsigned int AddPins)
 * @param RemovePins - use #defined AD_PORTxxx OR'd together for each A/D Pin you wish to remove
 * @return SUCCESS OR ERROR
 * @brief  Remove pins from the A/D system.  If any pin is not active it returns an 
 * error
 * @note  None.
 * @author Max Dunne, 2013.08.15 */
char AD_AddPins(unsigned int AddPins)
{
    if (!ADActive) {
        dbprintf("%s called before enable\r\n", __FUNCTION__);
        return ERROR;
    }
    if ((AddPins == 0) || (AddPins > ALLADPINS)) {
        dbprintf("%s returning ERROR with pins outside range: %X\r\n", __FUNCTION__, AddPins);
        return ERROR;
    }
    if (ActivePins & AddPins) {
        dbprintf("%s Returning ERROR for pins already in state: %X \r\n", __FUNCTION__, AddPins);
        return ERROR;
    }
    //setting the pins to be added during the next interrupt cycle
    PinsToAdd = AddPins;
    return SUCCESS;
}

/**
 * @Function AD_RemovePins(unsigned int RemovePins)
 * @param RemovePins - use #defined AD_PORTxxx OR'd together for each A/D Pin you wish to remove
 * @return SUCCESS OR ERROR
 * @brief  Remove pins from the A/D system.  If any pin is not active it returns an 
 * error
 * @note  None.
 * @author Max Dunne, 2013.08.15 */
char AD_RemovePins(unsigned int RemovePins)
{
    if (!ADActive) {
        dbprintf("%s called before enable\r\n", __FUNCTION__);
        return ERROR;
    }
    if ((RemovePins == 0) || (RemovePins > ALLADPINS)) {
        dbprintf("%s returning ERROR with pins outside range: %X\r\n", __FUNCTION__, RemovePins);
        return ERROR;
    }
    if (!(ActivePins & RemovePins)) {
        dbprintf("%s Returning ERROR for pins already in state: %X \r\n", __FUNCTION__, RemovePins);
        return ERROR;
    }
    if (RemovePins & BAT_VOLTAGE_MONITOR) {
        dbprintf("%s returning error attempting to remove the battery monitor", __FUNCTION__);
        return ERROR;
    }

    //setting the pins to be added during the next interrupt cycle
    PinsToRemove |= RemovePins;
    return SUCCESS;
}

/**
 * @Function AD_ActivePins(void)
 * @param None
 * @return Listing of all A/D pins that are active.
 * @brief  Returns a variable of all active A/D pins. An individual pin can be determined 
 * if active by "anding" with the AD_PORTXX Macros
 * @note  This will not reflect changes made with add or remove pins until the next 
 * A/D interrupt cycle
 * @author Max Dunne, 2013.08.15 */
unsigned int AD_ActivePins(void)
{
    return ActivePins;
}

/**
 * @Function AD_IsNewDataReady(void)
 * @param None
 * @return TRUE or FALSE
 * @brief  This function returns a flag indicating that the A/D has new values since the last read of any value
 * @author Max Dunne, 2013.08.15 */
char AD_IsNewDataReady(void)
{
    if (ADNewData) {
        ADNewData = FALSE;
        return TRUE;
    }
    return FALSE;
}

/**
 * @Function AD_ReadADPin(unsigned int Pin)
 * @param Pin, used #defined AD_PORTxxx to select pin
 * @return 10-bit AD Value or ERROR
 * @brief  Reads current value from buffer for given pin
 * @author Max Dunne, 2011.12.10 */
unsigned int AD_ReadADPin(unsigned int Pin)
{
    if (!ADActive) {
        dbprintf("%s returning ERROR before enable\r\n", __FUNCTION__);
        return ERROR;
    }
    if (!(ActivePins & Pin)) {
        dbprintf("%s returning error with unactivated pin: %X %X\r\n", __FUNCTION__, Pin);
        return ERROR;
    }
    unsigned char TranslatedPin = 0;
    while (Pin > 1) {

        Pin >>= 1;
        TranslatedPin++;
    }
    return ADValues[PortMapping[TranslatedPin]];
}

/**
 * @Function AD_End(void)
 * @param None
 * @return None
 * @brief  disables the A/D subsystem and release the pins used
 * @author Max Dunne, 2013.09.20 */
void AD_End(void)
{
    int pin;
    if (!ADActive) {
        return;
    }
    INTEnable(INT_AD1, INT_DISABLED);
    AD1CON1CLR = _AD1CON1_ON_MASK;
    PinsToRemove = ALLADPINS;
    AD_SetPins();
    for (pin = 0; pin < NUM_AD_PINS; pin++) {
        ADValues[pin] = -1;
    }
    ActivePins = 0;
    PinCount = 0;
    //CloseADC10();    
    AD1PCFG = 0xFF;
}

///////////////////////////////////////////////////////////////////////////
// Private functions
///////////////////////////////////////////////////////////////////////////

/**
 * @Function AD_SetPins
 * @param None
 * @return SUCCESS OR ERROR
 * @brief  Connects pins in PinstoAdd to the A/D system and removes the pins in PinsToRemove
 * @note  Private Function. DO NOT USE.
 * @author Max Dunne, 2013.08.15 */
char AD_SetPins(void)
{
    if (!ADActive) {
        return ERROR;
    }
    unsigned int cssl = 0;
    unsigned int pcfg = 0;
    unsigned int rempcfg = 0;
    unsigned char CurPin = 0;
    unsigned int CurPinOrder = 0x00;
    int ADMapping[NUM_AD_PINS_UNO];
    AD1CON1CLR = _AD1CON1_ON_MASK; //disable A/D system and interrupt
    INTEnable(INT_AD1, INT_DISABLED);
    PinCount = 0;

    //determine the new set of active pins
    ActivePins |= PinsToAdd;
    ActivePins &= ~PinsToRemove;
    //initialize the mapping array to -1
    for (CurPin = 0; CurPin < NUM_AD_PINS_UNO; CurPin++) {
        ADMapping[CurPin] = -1;
    }
    // memset(ADMapping,-1,NUM_AD_PINS_UNO);
    for (CurPin = 0; CurPin < NUM_AD_PINS; CurPin++) {
        PortMapping[CurPin] = -1; //reset all ports to unmapped
        if ((ActivePins & (1 << CurPin)) != 0) { //if one of the pins is active
            //build masks and remap pins
            cssl |= AD1CSSL_MASKS[CurPin];
            pcfg |= AD1PCFG_MASKS[CurPin];
            ADMapping[AD1PCFG_POS[CurPin]] = CurPin;
            PinCount++;
        }
        if ((PinsToRemove & (1 << CurPin)) != 0) {//generate removal masks
            rempcfg |= AD1PCFG_MASKS[CurPin];
        }
    }
    for (CurPin = 0; CurPin < NUM_AD_PINS_UNO; CurPin++) {//translate AD Mapping to Port Mapping
        if (ADMapping[CurPin] != -1) {
            PortMapping[ADMapping[CurPin]] = CurPinOrder;
            CurPinOrder++;
        }
    }
    cssl = ~cssl;
    OpenADC10(ADC_MODULE_ON | ADC_FORMAT_INTG | ADC_CLK_AUTO | ADC_AUTO_SAMPLING_ON,
            ADC_VREF_AVDD_AVSS | ADC_SCAN_ON | ((PinCount - 1) << _AD1CON2_SMPI_POSITION) | ADC_BUF_16,
            ADC_SAMPLE_TIME_29 | ADC_CONV_CLK_51Tcy2 | ADC_CONV_CLK_PB, pcfg, cssl);
    AD1PCFGSET = rempcfg;
    //recalculate interval between battery samples
    PointsPerBatSamples = (POINTS_PER_SECOND_PER_PIN / PinCount) / (float) FREQUENCY_TO_SAMPLE;
    PinsToAdd = 0;
    PinsToRemove = 0;
    INTEnable(INT_AD1, INT_ENABLED);
    return SUCCESS;
}

/**
 * @Function ADCIntHandler
 * @param None
 * @return None
 * @brief  Interrupt Handler for A/D. Reads all used pins into buffer.
 * @note  This function is not to be called by the user
 * @author Max Dunne, 2013.08.25 */
void __ISR(_ADC_VECTOR, ipl1auto) ADCIntHandler(void)
{
    unsigned char CurPin = 0;
    INTClearFlag(INT_AD1);
    for (CurPin = 0; CurPin <= PinCount; CurPin++) {
        ADValues[CurPin] = ReadADC10(CurPin); //read in new set of values
    }
    //calculate new filtered battery voltage
    Filt_BatVoltage = (Filt_BatVoltage * KEEP_FILT + AD_ReadADPin(BAT_VOLTAGE_MONITOR) * ADD_FILT) >> SHIFT_FILT;

    SampleCount++;
    if (SampleCount > PointsPerBatSamples) {//if sample time has passed
        PrevFilt_BatVoltage = CurFilt_BatVoltage;
        CurFilt_BatVoltage = Filt_BatVoltage;
        SampleCount = 0;
        //check for battery undervoltage check
        if ((CurFilt_BatVoltage <= BAT_VOLTAGE_LOCKOUT) && (PrevFilt_BatVoltage <= BAT_VOLTAGE_LOCKOUT) && (AD_ReadADPin(BAT_VOLTAGE_MONITOR) > BAT_VOLTAGE_NO_BAT)) {
            BOARD_End();
            while (1) {
                printf("Battery is undervoltage with reading %d, Going to sleep\r\n", AD_ReadADPin(BAT_VOLTAGE_MONITOR));
                while (!IsTransmitEmpty());
//EXPERIMENTAL UVLO !  10/8/2014
                while(1) {
                    PowerSaveSleep(); // Enter Sleep
                }
                //END EXPERIMENT
            }
        }
    }
    //if pins are changed add pins
    if (PinsToAdd | PinsToRemove) {
        AD_SetPins();
    }
    ADNewData = TRUE;
}

#endif /* ES_HAL_SYS == PIC32 && defined(ES_HAL_USE_ADC) */
