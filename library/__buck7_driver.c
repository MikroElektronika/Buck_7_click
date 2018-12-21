/*
    __buck7_driver.c

-----------------------------------------------------------------------------

  This file is part of mikroSDK.

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

#include "__buck7_driver.h"
#include "__buck7_hal.c"

/* ------------------------------------------------------------------- MACROS */

/* MODE */
const uint8_t _BUCK7_MODE_DCM = 0x01;
const uint8_t _BUCK7_MODE_PWM = 0x00;

/* Output voltage */
const uint16_t _BUCK7_OUT_VOLTAGE_3_3V = 0x0FAF;
const uint16_t _BUCK7_OUT_VOLTAGE_5V   = 0x0EA6;
const uint16_t _BUCK7_OUT_VOLTAGE_6V   = 0x0E10;
const uint16_t _BUCK7_OUT_VOLTAGE_7V   = 0x0D7A;
const uint16_t _BUCK7_OUT_VOLTAGE_8V   = 0x0CE4;
const uint16_t _BUCK7_OUT_VOLTAGE_9V   = 0x0C4E;
const uint16_t _BUCK7_OUT_VOLTAGE_10V  = 0x0BB8;
const uint16_t _BUCK7_OUT_VOLTAGE_11V  = 0x0B22;
const uint16_t _BUCK7_OUT_VOLTAGE_12V  = 0x0A8C;
const uint16_t _BUCK7_OUT_VOLTAGE_13V  = 0x09F6;
const uint16_t _BUCK7_OUT_VOLTAGE_14V  = 0x0960;
const uint16_t _BUCK7_OUT_VOLTAGE_15V  = 0x08CA;
const uint16_t _BUCK7_OUT_VOLTAGE_16V  = 0x0834;
const uint16_t _BUCK7_OUT_VOLTAGE_17V  = 0x079E;
const uint16_t _BUCK7_OUT_VOLTAGE_18V  = 0x0708;
const uint16_t _BUCK7_OUT_VOLTAGE_19V  = 0x0672;
const uint16_t _BUCK7_OUT_VOLTAGE_20V  = 0x059C;
const uint16_t _BUCK7_OUT_VOLTAGE_21V  = 0x0546;
const uint16_t _BUCK7_OUT_VOLTAGE_22V  = 0x04B0;
const uint16_t _BUCK7_OUT_VOLTAGE_23V  = 0x041A;
const uint16_t _BUCK7_OUT_VOLTAGE_24V  = 0x0384;
const uint16_t _BUCK7_OUT_VOLTAGE_25V  = 0x02EE;
const uint16_t _BUCK7_OUT_VOLTAGE_26V  = 0x0244;
const uint16_t _BUCK7_OUT_VOLTAGE_27V  = 0x0190;
const uint16_t _BUCK7_OUT_VOLTAGE_28V  = 0x00FA;
const uint16_t _BUCK7_OUT_VOLTAGE_29V  = 0x0096;
const uint16_t _BUCK7_OUT_VOLTAGE_30V  = 0x0000;

/* ---------------------------------------------------------------- VARIABLES */

#ifdef   __BUCK7_DRV_I2C__
static uint8_t _slaveAddress;
#endif

/* -------------------------------------------- PRIVATE FUNCTION DECLARATIONS */



/* --------------------------------------------- PRIVATE FUNCTION DEFINITIONS */



/* --------------------------------------------------------- PUBLIC FUNCTIONS */

#ifdef   __BUCK7_DRV_SPI__

void buck7_spiDriverInit(T_BUCK7_P gpioObj, T_BUCK7_P spiObj)
{
    hal_spiMap( (T_HAL_P)spiObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    hal_gpio_csSet( 1 );
}

#endif
#ifdef   __BUCK7_DRV_I2C__

void buck7_i2cDriverInit(T_BUCK7_P gpioObj, T_BUCK7_P i2cObj, uint8_t slave)
{
    _slaveAddress = slave;
    hal_i2cMap( (T_HAL_P)i2cObj );
    hal_gpioMap( (T_HAL_P)gpioObj );
}

#endif
#ifdef   __BUCK7_DRV_UART__

void buck7_uartDriverInit(T_BUCK7_P gpioObj, T_BUCK7_P uartObj)
{
    hal_uartMap( (T_HAL_P)uartObj );
    hal_gpioMap( (T_HAL_P)gpioObj );
}

#endif


/* ----------------------------------------------------------- IMPLEMENTATION */

void buck7_setOutputVoltage(uint16_t voltage)
{
    uint8_t writeVolt[ 2 ];
    uint16_t setVolt;
    
    setVolt = 0x7000 | voltage;
    
    writeVolt[ 0 ] = setVolt >> 8;
    writeVolt[ 1 ] = setVolt & 0x00FF;
    
    hal_gpio_csSet( 0 );
    hal_spiWrite(writeVolt, 2);
    hal_gpio_csSet( 1 );
}

void buck7_enable()
{
    hal_gpio_anSet( 1 );
}

void buck7_setMode(uint8_t mode)
{
    hal_gpio_pwmSet( mode );
}


uint8_t buck7_getResState()
{
    return hal_gpio_rstGet();
}

/* -------------------------------------------------------------------------- */
/*
  __buck7_driver.c

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