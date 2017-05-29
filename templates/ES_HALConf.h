/**
 * @file    ES_HALConf.h
 * @brief   Configuration file for the ES Framework Hardware Abstraction Layer (HAL)
 * @details This configuration file allows enabling and disabling of hardware
 *          drivers and miscelanous HAL features. The HAL is designed such
 */

#ifndef ES_HALCONF_H
#define ES_HALCONF_H

#ifdef USE_ES_HAL

// This sets the system architecture to use. Options include PIC32 and x86_NIX
// TODO: Pick this up with an environment variable to isolate it from the
//       codebase
#if !defined(ES_HAL_SYS)
#define ES_HAL_SYS PIC32 // default of PIC32
#endif

// This enables the Serial module
#if !defined(ES_HAL_USE_SERIAL)
#define ES_HAL_USE_SERIAL            TRUE
#endif

// This enables the Keyboard Input
// module. DO NOT DISABLE THIS.
#if !defined(ES_HAL_USE_KEYINPUT)
#define ES_HAL_USE_KEYINPUT          TRUE
#endif

// This enables the ADC module
#if !defined(ES_HAL_USE_ADC)
#define ES_HAL_USE_ADC               FALSE
#endif

// This enables the PWM module
#if !defined(ES_HAL_USE_PWM)
#define ES_HAL_USE_PWM               FALSE
#endif

// This enables the Servo module
#if !defined(ES_HAL_USE_SERVO)
#define ES_HAL_USE_SERVO             FALSE
#endif

#endif /* USE_ES_HAL */

#endif /* ES_HALCONF_H */
