#line 1 "D:/Clicks_git/B/Buck_7_Click/SW/example/c/ARM/STM/Click_BUCK7_STM.c"
#line 1 "d:/clicks_git/b/buck_7_click/sw/example/c/arm/stm/click_buck7_types.h"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for arm/include/stdint.h"





typedef signed char int8_t;
typedef signed int int16_t;
typedef signed long int int32_t;
typedef signed long long int64_t;


typedef unsigned char uint8_t;
typedef unsigned int uint16_t;
typedef unsigned long int uint32_t;
typedef unsigned long long uint64_t;


typedef signed char int_least8_t;
typedef signed int int_least16_t;
typedef signed long int int_least32_t;
typedef signed long long int_least64_t;


typedef unsigned char uint_least8_t;
typedef unsigned int uint_least16_t;
typedef unsigned long int uint_least32_t;
typedef unsigned long long uint_least64_t;



typedef signed long int int_fast8_t;
typedef signed long int int_fast16_t;
typedef signed long int int_fast32_t;
typedef signed long long int_fast64_t;


typedef unsigned long int uint_fast8_t;
typedef unsigned long int uint_fast16_t;
typedef unsigned long int uint_fast32_t;
typedef unsigned long long uint_fast64_t;


typedef signed long int intptr_t;
typedef unsigned long int uintptr_t;


typedef signed long long intmax_t;
typedef unsigned long long uintmax_t;
#line 1 "d:/clicks_git/b/buck_7_click/sw/example/c/arm/stm/click_buck7_config.h"
#line 1 "d:/clicks_git/b/buck_7_click/sw/example/c/arm/stm/click_buck7_types.h"
#line 3 "d:/clicks_git/b/buck_7_click/sw/example/c/arm/stm/click_buck7_config.h"
const uint32_t _BUCK7_SPI_CFG[ 2 ] =
{
 _SPI_FPCLK_DIV256,
 _SPI_FIRST_CLK_EDGE_TRANSITION |
 _SPI_CLK_IDLE_LOW |
 _SPI_MASTER |
 _SPI_MSB_FIRST |
 _SPI_8_BIT |
 _SPI_SSM_ENABLE |
 _SPI_SS_DISABLE |
 _SPI_SSI_1
};
#line 1 "d:/clicks_git/b/buck_7_click/sw/library/__buck7_driver.h"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for arm/include/stdint.h"
#line 58 "d:/clicks_git/b/buck_7_click/sw/library/__buck7_driver.h"
extern const uint8_t _BUCK7_MODE_DCM;
extern const uint8_t _BUCK7_MODE_PWM;


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
#line 98 "d:/clicks_git/b/buck_7_click/sw/library/__buck7_driver.h"
void buck7_spiDriverInit( const uint8_t*  gpioObj,  const uint8_t*  spiObj);
#line 108 "d:/clicks_git/b/buck_7_click/sw/library/__buck7_driver.h"
void buck7_gpioDriverInit( const uint8_t*  gpioObj);
#line 122 "d:/clicks_git/b/buck_7_click/sw/library/__buck7_driver.h"
void buck7_setOutputVoltage(uint16_t voltage);
#line 127 "d:/clicks_git/b/buck_7_click/sw/library/__buck7_driver.h"
uint8_t buck7_getResState();
#line 132 "d:/clicks_git/b/buck_7_click/sw/library/__buck7_driver.h"
void buck7_enable();
#line 145 "d:/clicks_git/b/buck_7_click/sw/library/__buck7_driver.h"
void buck7_setMode(uint8_t mode);
#line 31 "D:/Clicks_git/B/Buck_7_Click/SW/example/c/ARM/STM/Click_BUCK7_STM.c"
void systemInit()
{
 mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_AN_PIN, _GPIO_OUTPUT );
 mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_RST_PIN, _GPIO_OUTPUT );
 mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_CS_PIN, _GPIO_OUTPUT );
 mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_PWM_PIN, _GPIO_OUTPUT );

 mikrobus_spiInit( _MIKROBUS1, &_BUCK7_SPI_CFG[0] );
 Delay_ms( 100 );
}

void applicationInit()
{
 buck7_spiDriverInit( ( const uint8_t* )&_MIKROBUS1_GPIO, ( const uint8_t* )&_MIKROBUS1_SPI );
 buck7_enable();
 buck7_setMode( _BUCK7_MODE_PWM );
}

void applicationTask()
{
 buck7_setOutputVoltage( _BUCK7_OUT_VOLTAGE_5V );
 Delay_ms( 3000 );
 buck7_setOutputVoltage( _BUCK7_OUT_VOLTAGE_10V );
 Delay_ms( 3000 );
 buck7_setOutputVoltage( _BUCK7_OUT_VOLTAGE_15V );
 Delay_ms( 3000 );
 buck7_setOutputVoltage( _BUCK7_OUT_VOLTAGE_20V );
 Delay_ms( 3000 );
 buck7_setOutputVoltage( _BUCK7_OUT_VOLTAGE_25V );
 Delay_ms( 3000 );
 buck7_setOutputVoltage( _BUCK7_OUT_VOLTAGE_20V );
 Delay_ms( 3000 );
 buck7_setOutputVoltage( _BUCK7_OUT_VOLTAGE_15V );
 Delay_ms( 3000 );
 buck7_setOutputVoltage( 0x0BB8 );
 Delay_ms( 3000 );
}

void main()
{
 systemInit();
 applicationInit();

 while (1)
 {
 applicationTask();
 }
}
