![MikroE](http://www.mikroe.com/img/designs/beta/logo_small.png)

---

# BUCK7 Click

- **CIC Prefix**  : BUCK7
- **Author**      : Katarina Perendic
- **Verison**     : 1.0.0
- **Date**        : jun 2018.

---

### Software Support

We provide a library for the BUCK7 Click on our [LibStock](https://libstock.mikroe.com/projects/view/2440/buck-7-click) 
page, as well as a demo application (example), developed using MikroElektronika 
[compilers](http://shop.mikroe.com/compilers). The demo can run on all the main 
MikroElektronika [development boards](http://shop.mikroe.com/development-boards).

**Library Description**

The library initializes and defines the SPI bus driver.
The library includes function for sets output voltage, functions for enable chip.
The user also has the function for sets work mode.


Key functions :

- ``` void buck7_setOutputVoltage(uint16_t voltage) ``` - Function for set output voltage
- ``` void buck7_enable() ``` - Function for enable chip
- ``` void buck7_setMode(uint8_t mode) ``` - Function for set chip mode 

**Examples Description**

The application is composed of three sections :

- System Initialization - Initializes SPI module and set AN,RST,CS and PWM pin as OUTPUT
- Application Initialization - Initializes Driver init, enable chip and set mode
- Application Task - (code snippet) - Sets output voltage to 5V, 10V, 15V, 20V, 25V every 3 seconds.
                                      It is necessary to set the input voltage on 2.7V + maximum output voltage.


```.c
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
    buck7_setOutputVoltage( 0x0BB8 ); /* 10 V */
    Delay_ms( 3000 );
}
```

The full application code, and ready to use projects can be found on our 
[LibStock](https://libstock.mikroe.com/projects/view/2440/buck-7-click) page.

Other mikroE Libraries used in the example:

- SPI

**Additional notes and informations**

Depending on the development board you are using, you may need 
[USB UART click](http://shop.mikroe.com/usb-uart-click), 
[USB UART 2 Click](http://shop.mikroe.com/usb-uart-2-click) or 
[RS232 Click](http://shop.mikroe.com/rs232-click) to connect to your PC, for 
development systems with no UART to USB interface available on the board. The 
terminal available in all Mikroelektronika 
[compilers](http://shop.mikroe.com/compilers), or any other terminal application 
of your choice, can be used to read the message.

---
---
