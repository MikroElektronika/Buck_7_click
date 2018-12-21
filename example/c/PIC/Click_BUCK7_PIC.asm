
_systemInit:

;Click_BUCK7_PIC.c,30 :: 		void systemInit()
;Click_BUCK7_PIC.c,32 :: 		mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_AN_PIN, _GPIO_OUTPUT );
	CLRF        FARG_mikrobus_gpioInit_bus+0 
	CLRF        FARG_mikrobus_gpioInit_pin+0 
	CLRF        FARG_mikrobus_gpioInit_direction+0 
	CALL        _mikrobus_gpioInit+0, 0
;Click_BUCK7_PIC.c,33 :: 		mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_RST_PIN, _GPIO_OUTPUT );
	CLRF        FARG_mikrobus_gpioInit_bus+0 
	MOVLW       1
	MOVWF       FARG_mikrobus_gpioInit_pin+0 
	CLRF        FARG_mikrobus_gpioInit_direction+0 
	CALL        _mikrobus_gpioInit+0, 0
;Click_BUCK7_PIC.c,34 :: 		mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_CS_PIN, _GPIO_OUTPUT );
	CLRF        FARG_mikrobus_gpioInit_bus+0 
	MOVLW       2
	MOVWF       FARG_mikrobus_gpioInit_pin+0 
	CLRF        FARG_mikrobus_gpioInit_direction+0 
	CALL        _mikrobus_gpioInit+0, 0
;Click_BUCK7_PIC.c,35 :: 		mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_PWM_PIN, _GPIO_OUTPUT );
	CLRF        FARG_mikrobus_gpioInit_bus+0 
	MOVLW       6
	MOVWF       FARG_mikrobus_gpioInit_pin+0 
	CLRF        FARG_mikrobus_gpioInit_direction+0 
	CALL        _mikrobus_gpioInit+0, 0
;Click_BUCK7_PIC.c,37 :: 		mikrobus_spiInit( _MIKROBUS1, &_BUCK7_SPI_CFG[0] );
	CLRF        FARG_mikrobus_spiInit_bus+0 
	MOVLW       __BUCK7_SPI_CFG+0
	MOVWF       FARG_mikrobus_spiInit_cfg+0 
	MOVLW       hi_addr(__BUCK7_SPI_CFG+0)
	MOVWF       FARG_mikrobus_spiInit_cfg+1 
	MOVLW       higher_addr(__BUCK7_SPI_CFG+0)
	MOVWF       FARG_mikrobus_spiInit_cfg+2 
	CALL        _mikrobus_spiInit+0, 0
;Click_BUCK7_PIC.c,38 :: 		Delay_ms( 100 );
	MOVLW       9
	MOVWF       R11, 0
	MOVLW       30
	MOVWF       R12, 0
	MOVLW       228
	MOVWF       R13, 0
L_systemInit0:
	DECFSZ      R13, 1, 1
	BRA         L_systemInit0
	DECFSZ      R12, 1, 1
	BRA         L_systemInit0
	DECFSZ      R11, 1, 1
	BRA         L_systemInit0
	NOP
;Click_BUCK7_PIC.c,39 :: 		}
L_end_systemInit:
	RETURN      0
; end of _systemInit

_applicationInit:

;Click_BUCK7_PIC.c,41 :: 		void applicationInit()
;Click_BUCK7_PIC.c,43 :: 		buck7_spiDriverInit( (T_BUCK7_P)&_MIKROBUS1_GPIO, (T_BUCK7_P)&_MIKROBUS1_SPI );
	MOVLW       __MIKROBUS1_GPIO+0
	MOVWF       FARG_buck7_spiDriverInit_gpioObj+0 
	MOVLW       hi_addr(__MIKROBUS1_GPIO+0)
	MOVWF       FARG_buck7_spiDriverInit_gpioObj+1 
	MOVLW       higher_addr(__MIKROBUS1_GPIO+0)
	MOVWF       FARG_buck7_spiDriverInit_gpioObj+2 
	MOVLW       __MIKROBUS1_SPI+0
	MOVWF       FARG_buck7_spiDriverInit_spiObj+0 
	MOVLW       hi_addr(__MIKROBUS1_SPI+0)
	MOVWF       FARG_buck7_spiDriverInit_spiObj+1 
	MOVLW       higher_addr(__MIKROBUS1_SPI+0)
	MOVWF       FARG_buck7_spiDriverInit_spiObj+2 
	CALL        _buck7_spiDriverInit+0, 0
;Click_BUCK7_PIC.c,44 :: 		buck7_reset();
	CALL        _buck7_reset+0, 0
;Click_BUCK7_PIC.c,45 :: 		buck7_enable();
	CALL        _buck7_enable+0, 0
;Click_BUCK7_PIC.c,46 :: 		buck7_setMode( _BUCK7_MODE_PWM );
	MOVLW       __BUCK7_MODE_PWM
	MOVWF       FARG_buck7_setMode_mode+0 
	CALL        _buck7_setMode+0, 0
;Click_BUCK7_PIC.c,47 :: 		}
L_end_applicationInit:
	RETURN      0
; end of _applicationInit

_applicationTask:

;Click_BUCK7_PIC.c,49 :: 		void applicationTask()
;Click_BUCK7_PIC.c,51 :: 		buck7_setOutputVoltage( _BUCK7_OUT_VOLTAGE_5V );
	MOVLW       __BUCK7_OUT_VOLTAGE_5V
	MOVWF       FARG_buck7_setOutputVoltage_voltage+0 
	MOVLW       __BUCK7_OUT_VOLTAGE_5V+1
	MOVWF       FARG_buck7_setOutputVoltage_voltage+1 
	CALL        _buck7_setOutputVoltage+0, 0
;Click_BUCK7_PIC.c,52 :: 		Delay_ms( 3000 );
	MOVLW       244
	MOVWF       R11, 0
	MOVLW       130
	MOVWF       R12, 0
	MOVLW       5
	MOVWF       R13, 0
L_applicationTask1:
	DECFSZ      R13, 1, 1
	BRA         L_applicationTask1
	DECFSZ      R12, 1, 1
	BRA         L_applicationTask1
	DECFSZ      R11, 1, 1
	BRA         L_applicationTask1
;Click_BUCK7_PIC.c,53 :: 		buck7_setOutputVoltage( _BUCK7_OUT_VOLTAGE_10V );
	MOVLW       __BUCK7_OUT_VOLTAGE_10V
	MOVWF       FARG_buck7_setOutputVoltage_voltage+0 
	MOVLW       __BUCK7_OUT_VOLTAGE_10V+1
	MOVWF       FARG_buck7_setOutputVoltage_voltage+1 
	CALL        _buck7_setOutputVoltage+0, 0
;Click_BUCK7_PIC.c,54 :: 		Delay_ms( 3000 );
	MOVLW       244
	MOVWF       R11, 0
	MOVLW       130
	MOVWF       R12, 0
	MOVLW       5
	MOVWF       R13, 0
L_applicationTask2:
	DECFSZ      R13, 1, 1
	BRA         L_applicationTask2
	DECFSZ      R12, 1, 1
	BRA         L_applicationTask2
	DECFSZ      R11, 1, 1
	BRA         L_applicationTask2
;Click_BUCK7_PIC.c,55 :: 		buck7_setOutputVoltage( _BUCK7_OUT_VOLTAGE_15V );
	MOVLW       __BUCK7_OUT_VOLTAGE_15V
	MOVWF       FARG_buck7_setOutputVoltage_voltage+0 
	MOVLW       __BUCK7_OUT_VOLTAGE_15V+1
	MOVWF       FARG_buck7_setOutputVoltage_voltage+1 
	CALL        _buck7_setOutputVoltage+0, 0
;Click_BUCK7_PIC.c,56 :: 		Delay_ms( 3000 );
	MOVLW       244
	MOVWF       R11, 0
	MOVLW       130
	MOVWF       R12, 0
	MOVLW       5
	MOVWF       R13, 0
L_applicationTask3:
	DECFSZ      R13, 1, 1
	BRA         L_applicationTask3
	DECFSZ      R12, 1, 1
	BRA         L_applicationTask3
	DECFSZ      R11, 1, 1
	BRA         L_applicationTask3
;Click_BUCK7_PIC.c,57 :: 		buck7_setOutputVoltage( _BUCK7_OUT_VOLTAGE_20V );
	MOVLW       __BUCK7_OUT_VOLTAGE_20V
	MOVWF       FARG_buck7_setOutputVoltage_voltage+0 
	MOVLW       __BUCK7_OUT_VOLTAGE_20V+1
	MOVWF       FARG_buck7_setOutputVoltage_voltage+1 
	CALL        _buck7_setOutputVoltage+0, 0
;Click_BUCK7_PIC.c,58 :: 		Delay_ms( 3000 );
	MOVLW       244
	MOVWF       R11, 0
	MOVLW       130
	MOVWF       R12, 0
	MOVLW       5
	MOVWF       R13, 0
L_applicationTask4:
	DECFSZ      R13, 1, 1
	BRA         L_applicationTask4
	DECFSZ      R12, 1, 1
	BRA         L_applicationTask4
	DECFSZ      R11, 1, 1
	BRA         L_applicationTask4
;Click_BUCK7_PIC.c,59 :: 		buck7_setOutputVoltage( _BUCK7_OUT_VOLTAGE_25V );
	MOVLW       __BUCK7_OUT_VOLTAGE_25V
	MOVWF       FARG_buck7_setOutputVoltage_voltage+0 
	MOVLW       __BUCK7_OUT_VOLTAGE_25V+1
	MOVWF       FARG_buck7_setOutputVoltage_voltage+1 
	CALL        _buck7_setOutputVoltage+0, 0
;Click_BUCK7_PIC.c,60 :: 		Delay_ms( 3000 );
	MOVLW       244
	MOVWF       R11, 0
	MOVLW       130
	MOVWF       R12, 0
	MOVLW       5
	MOVWF       R13, 0
L_applicationTask5:
	DECFSZ      R13, 1, 1
	BRA         L_applicationTask5
	DECFSZ      R12, 1, 1
	BRA         L_applicationTask5
	DECFSZ      R11, 1, 1
	BRA         L_applicationTask5
;Click_BUCK7_PIC.c,61 :: 		buck7_setOutputVoltage( _BUCK7_OUT_VOLTAGE_20V );
	MOVLW       __BUCK7_OUT_VOLTAGE_20V
	MOVWF       FARG_buck7_setOutputVoltage_voltage+0 
	MOVLW       __BUCK7_OUT_VOLTAGE_20V+1
	MOVWF       FARG_buck7_setOutputVoltage_voltage+1 
	CALL        _buck7_setOutputVoltage+0, 0
;Click_BUCK7_PIC.c,62 :: 		Delay_ms( 3000 );
	MOVLW       244
	MOVWF       R11, 0
	MOVLW       130
	MOVWF       R12, 0
	MOVLW       5
	MOVWF       R13, 0
L_applicationTask6:
	DECFSZ      R13, 1, 1
	BRA         L_applicationTask6
	DECFSZ      R12, 1, 1
	BRA         L_applicationTask6
	DECFSZ      R11, 1, 1
	BRA         L_applicationTask6
;Click_BUCK7_PIC.c,63 :: 		buck7_setOutputVoltage( _BUCK7_OUT_VOLTAGE_15V );
	MOVLW       __BUCK7_OUT_VOLTAGE_15V
	MOVWF       FARG_buck7_setOutputVoltage_voltage+0 
	MOVLW       __BUCK7_OUT_VOLTAGE_15V+1
	MOVWF       FARG_buck7_setOutputVoltage_voltage+1 
	CALL        _buck7_setOutputVoltage+0, 0
;Click_BUCK7_PIC.c,64 :: 		Delay_ms( 3000 );
	MOVLW       244
	MOVWF       R11, 0
	MOVLW       130
	MOVWF       R12, 0
	MOVLW       5
	MOVWF       R13, 0
L_applicationTask7:
	DECFSZ      R13, 1, 1
	BRA         L_applicationTask7
	DECFSZ      R12, 1, 1
	BRA         L_applicationTask7
	DECFSZ      R11, 1, 1
	BRA         L_applicationTask7
;Click_BUCK7_PIC.c,65 :: 		buck7_setOutputVoltage( 0x0BB8 ); /* 10 V */
	MOVLW       184
	MOVWF       FARG_buck7_setOutputVoltage_voltage+0 
	MOVLW       11
	MOVWF       FARG_buck7_setOutputVoltage_voltage+1 
	CALL        _buck7_setOutputVoltage+0, 0
;Click_BUCK7_PIC.c,66 :: 		Delay_ms( 3000 );
	MOVLW       244
	MOVWF       R11, 0
	MOVLW       130
	MOVWF       R12, 0
	MOVLW       5
	MOVWF       R13, 0
L_applicationTask8:
	DECFSZ      R13, 1, 1
	BRA         L_applicationTask8
	DECFSZ      R12, 1, 1
	BRA         L_applicationTask8
	DECFSZ      R11, 1, 1
	BRA         L_applicationTask8
;Click_BUCK7_PIC.c,67 :: 		}
L_end_applicationTask:
	RETURN      0
; end of _applicationTask

_main:

;Click_BUCK7_PIC.c,69 :: 		void main()
;Click_BUCK7_PIC.c,71 :: 		systemInit();
	CALL        _systemInit+0, 0
;Click_BUCK7_PIC.c,72 :: 		applicationInit();
	CALL        _applicationInit+0, 0
;Click_BUCK7_PIC.c,74 :: 		while (1)
L_main9:
;Click_BUCK7_PIC.c,76 :: 		applicationTask();
	CALL        _applicationTask+0, 0
;Click_BUCK7_PIC.c,77 :: 		}
	GOTO        L_main9
;Click_BUCK7_PIC.c,78 :: 		}
L_end_main:
	GOTO        $+0
; end of _main
