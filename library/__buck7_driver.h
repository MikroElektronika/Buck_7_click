/*
    __buck7_driver.h

-----------------------------------------------------------------------------

  This file is part of mikroSDK.
  
  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

/**
@file   __buck7_driver.h
@brief    BUCK7 Driver
@mainpage BUCK7 Click
@{

@image html libstock_fb_view.jpg

@}

@defgroup   BUCK7
@brief      BUCK7 Click Driver
@{

| Global Library Prefix | **BUCK7** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **jun 2018.**      |
| Developer             | **Katarina Perendic**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"

#ifndef _BUCK7_H_
#define _BUCK7_H_

/** 
 * @macro T_BUCK7_P
 * @brief Driver Abstract type 
 */
#define T_BUCK7_P    const uint8_t*

/** @defgroup BUCK7_COMPILE Compilation Config */              /** @{ */

   #define   __BUCK7_DRV_SPI__                            /**<     @macro __BUCK7_DRV_SPI__  @brief SPI driver selector */
//  #define   __BUCK7_DRV_I2C__                            /**<     @macro __BUCK7_DRV_I2C__  @brief I2C driver selector */                                          
// #define   __BUCK7_DRV_UART__                           /**<     @macro __BUCK7_DRV_UART__ @brief UART driver selector */ 

                                                                       /** @} */
/** @defgroup BUCK7_VAR Variables */                           /** @{ */

/* MODE */
extern const uint8_t _BUCK7_MODE_DCM;
extern const uint8_t _BUCK7_MODE_PWM;

/* Output voltage */
extern const uint16_t _BUCK7_OUT_VOLTAGE_3_3V;
extern const uint16_t _BUCK7_OUT_VOLTAGE_5V;
extern const uint16_t _BUCK7_OUT_VOLTAGE_6V;
extern const uint16_t _BUCK7_OUT_VOLTAGE_7V;
extern const uint16_t _BUCK7_OUT_VOLTAGE_8V;
extern const uint16_t _BUCK7_OUT_VOLTAGE_9V;
extern const uint16_t _BUCK7_OUT_VOLTAGE_10V;
extern const uint16_t _BUCK7_OUT_VOLTAGE_11V;
extern const uint16_t _BUCK7_OUT_VOLTAGE_12V;
extern const uint16_t _BUCK7_OUT_VOLTAGE_13V;
extern const uint16_t _BUCK7_OUT_VOLTAGE_14V;
extern const uint16_t _BUCK7_OUT_VOLTAGE_15V;
extern const uint16_t _BUCK7_OUT_VOLTAGE_16V;
extern const uint16_t _BUCK7_OUT_VOLTAGE_17V;
extern const uint16_t _BUCK7_OUT_VOLTAGE_18V;
extern const uint16_t _BUCK7_OUT_VOLTAGE_19V;
extern const uint16_t _BUCK7_OUT_VOLTAGE_20V;
extern const uint16_t _BUCK7_OUT_VOLTAGE_21V;
extern const uint16_t _BUCK7_OUT_VOLTAGE_22V;
extern const uint16_t _BUCK7_OUT_VOLTAGE_23V;
extern const uint16_t _BUCK7_OUT_VOLTAGE_24V;
extern const uint16_t _BUCK7_OUT_VOLTAGE_25V;
extern const uint16_t _BUCK7_OUT_VOLTAGE_26V;
extern const uint16_t _BUCK7_OUT_VOLTAGE_27V;
extern const uint16_t _BUCK7_OUT_VOLTAGE_28V;
extern const uint16_t _BUCK7_OUT_VOLTAGE_29V;
extern const uint16_t _BUCK7_OUT_VOLTAGE_30V;

                                                                       /** @} */
#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup BUCK7_INIT Driver Initialization */              /** @{ */

#ifdef   __BUCK7_DRV_SPI__
void buck7_spiDriverInit(T_BUCK7_P gpioObj, T_BUCK7_P spiObj);
#endif
#ifdef   __BUCK7_DRV_I2C__
void buck7_i2cDriverInit(T_BUCK7_P gpioObj, T_BUCK7_P i2cObj, uint8_t slave);
#endif
#ifdef   __BUCK7_DRV_UART__
void buck7_uartDriverInit(T_BUCK7_P gpioObj, T_BUCK7_P uartObj);
#endif

// GPIO Only Drivers - remove in other cases
void buck7_gpioDriverInit(T_BUCK7_P gpioObj);
                                                                       /** @} */
/** @defgroup BUCK7_FUNC Driver Functions */                   /** @{ */

/**
 * @brief Function for settings output voltage
 *
 * @param[in] voltage     voltage which be set
 *
 * Minimum sets output voltage is 2.7V (0x0FFF) and 
   Maximum sets output voltage is 30V (0x0000)
   In order to set the output voltage, the input voltage must be 2.7V + VOUT
 *
 */
void buck7_setOutputVoltage(uint16_t voltage);

/**
 * @brief Function for read RES state
 */
uint8_t buck7_getResState();

/**
 * @brief Function for enable chip
 */
void buck7_enable();

/**
 * @brief Function for settings chip mode
 *
 * @param[in] mode     mode of work chip
 *
 *  Mode options:
       PWM mode - set MDO pin as GND,
       DCM mode - set MDO pin as VCC,
       PFM mode - set MDO pin as OPEN(set INPUT),
 *
 */
void buck7_setMode(uint8_t mode);

                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_BUCK7_STM.c
    @example Click_BUCK7_TIVA.c
    @example Click_BUCK7_CEC.c
    @example Click_BUCK7_KINETIS.c
    @example Click_BUCK7_MSP.c
    @example Click_BUCK7_PIC.c
    @example Click_BUCK7_PIC32.c
    @example Click_BUCK7_DSPIC.c
    @example Click_BUCK7_AVR.c
    @example Click_BUCK7_FT90x.c
    @example Click_BUCK7_STM.mbas
    @example Click_BUCK7_TIVA.mbas
    @example Click_BUCK7_CEC.mbas
    @example Click_BUCK7_KINETIS.mbas
    @example Click_BUCK7_MSP.mbas
    @example Click_BUCK7_PIC.mbas
    @example Click_BUCK7_PIC32.mbas
    @example Click_BUCK7_DSPIC.mbas
    @example Click_BUCK7_AVR.mbas
    @example Click_BUCK7_FT90x.mbas
    @example Click_BUCK7_STM.mpas
    @example Click_BUCK7_TIVA.mpas
    @example Click_BUCK7_CEC.mpas
    @example Click_BUCK7_KINETIS.mpas
    @example Click_BUCK7_MSP.mpas
    @example Click_BUCK7_PIC.mpas
    @example Click_BUCK7_PIC32.mpas
    @example Click_BUCK7_DSPIC.mpas
    @example Click_BUCK7_AVR.mpas
    @example Click_BUCK7_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __buck7_driver.h

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the MikroElektonika.

4. Neither the name of the MikroElektonika nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY MIKROELEKTRONIKA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MIKROELEKTRONIKA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------- */