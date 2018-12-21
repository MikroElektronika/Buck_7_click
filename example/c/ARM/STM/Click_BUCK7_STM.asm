_systemInit:
;Click_BUCK7_STM.c,31 :: 		void systemInit()
SUB	SP, SP, #4
STR	LR, [SP, #0]
;Click_BUCK7_STM.c,33 :: 		mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_AN_PIN, _GPIO_OUTPUT );
MOVS	R2, #0
MOVS	R1, #0
MOVS	R0, #0
BL	_mikrobus_gpioInit+0
;Click_BUCK7_STM.c,34 :: 		mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_RST_PIN, _GPIO_OUTPUT );
MOVS	R2, #0
MOVS	R1, #1
MOVS	R0, #0
BL	_mikrobus_gpioInit+0
;Click_BUCK7_STM.c,35 :: 		mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_CS_PIN, _GPIO_OUTPUT );
MOVS	R2, #0
MOVS	R1, #2
MOVS	R0, #0
BL	_mikrobus_gpioInit+0
;Click_BUCK7_STM.c,36 :: 		mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_PWM_PIN, _GPIO_OUTPUT );
MOVS	R2, #0
MOVS	R1, #6
MOVS	R0, #0
BL	_mikrobus_gpioInit+0
;Click_BUCK7_STM.c,38 :: 		mikrobus_spiInit( _MIKROBUS1, &_BUCK7_SPI_CFG[0] );
MOVW	R0, #lo_addr(__BUCK7_SPI_CFG+0)
MOVT	R0, #hi_addr(__BUCK7_SPI_CFG+0)
MOV	R1, R0
MOVS	R0, #0
BL	_mikrobus_spiInit+0
;Click_BUCK7_STM.c,39 :: 		Delay_ms( 100 );
MOVW	R7, #20351
MOVT	R7, #18
NOP
NOP
L_systemInit0:
SUBS	R7, R7, #1
BNE	L_systemInit0
NOP
NOP
NOP
;Click_BUCK7_STM.c,40 :: 		}
L_end_systemInit:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _systemInit
_applicationInit:
;Click_BUCK7_STM.c,42 :: 		void applicationInit()
SUB	SP, SP, #4
STR	LR, [SP, #0]
;Click_BUCK7_STM.c,44 :: 		buck7_spiDriverInit( (T_BUCK7_P)&_MIKROBUS1_GPIO, (T_BUCK7_P)&_MIKROBUS1_SPI );
MOVW	R1, #lo_addr(__MIKROBUS1_SPI+0)
MOVT	R1, #hi_addr(__MIKROBUS1_SPI+0)
MOVW	R0, #lo_addr(__MIKROBUS1_GPIO+0)
MOVT	R0, #hi_addr(__MIKROBUS1_GPIO+0)
BL	_buck7_spiDriverInit+0
;Click_BUCK7_STM.c,45 :: 		buck7_enable();
BL	_buck7_enable+0
;Click_BUCK7_STM.c,46 :: 		buck7_setMode( _BUCK7_MODE_PWM );
MOVS	R0, __BUCK7_MODE_PWM
BL	_buck7_setMode+0
;Click_BUCK7_STM.c,47 :: 		}
L_end_applicationInit:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _applicationInit
_applicationTask:
;Click_BUCK7_STM.c,49 :: 		void applicationTask()
SUB	SP, SP, #4
STR	LR, [SP, #0]
;Click_BUCK7_STM.c,51 :: 		buck7_setOutputVoltage( _BUCK7_OUT_VOLTAGE_5V );
MOVW	R0, __BUCK7_OUT_VOLTAGE_5V
BL	_buck7_setOutputVoltage+0
;Click_BUCK7_STM.c,52 :: 		Delay_ms( 3000 );
MOVW	R7, #20735
MOVT	R7, #549
NOP
NOP
L_applicationTask2:
SUBS	R7, R7, #1
BNE	L_applicationTask2
NOP
NOP
NOP
;Click_BUCK7_STM.c,53 :: 		buck7_setOutputVoltage( _BUCK7_OUT_VOLTAGE_10V );
MOVW	R0, __BUCK7_OUT_VOLTAGE_10V
BL	_buck7_setOutputVoltage+0
;Click_BUCK7_STM.c,54 :: 		Delay_ms( 3000 );
MOVW	R7, #20735
MOVT	R7, #549
NOP
NOP
L_applicationTask4:
SUBS	R7, R7, #1
BNE	L_applicationTask4
NOP
NOP
NOP
;Click_BUCK7_STM.c,55 :: 		buck7_setOutputVoltage( _BUCK7_OUT_VOLTAGE_15V );
MOVW	R0, __BUCK7_OUT_VOLTAGE_15V
BL	_buck7_setOutputVoltage+0
;Click_BUCK7_STM.c,56 :: 		Delay_ms( 3000 );
MOVW	R7, #20735
MOVT	R7, #549
NOP
NOP
L_applicationTask6:
SUBS	R7, R7, #1
BNE	L_applicationTask6
NOP
NOP
NOP
;Click_BUCK7_STM.c,57 :: 		buck7_setOutputVoltage( _BUCK7_OUT_VOLTAGE_20V );
MOVW	R0, __BUCK7_OUT_VOLTAGE_20V
BL	_buck7_setOutputVoltage+0
;Click_BUCK7_STM.c,58 :: 		Delay_ms( 3000 );
MOVW	R7, #20735
MOVT	R7, #549
NOP
NOP
L_applicationTask8:
SUBS	R7, R7, #1
BNE	L_applicationTask8
NOP
NOP
NOP
;Click_BUCK7_STM.c,59 :: 		buck7_setOutputVoltage( _BUCK7_OUT_VOLTAGE_25V );
MOVW	R0, __BUCK7_OUT_VOLTAGE_25V
BL	_buck7_setOutputVoltage+0
;Click_BUCK7_STM.c,60 :: 		Delay_ms( 3000 );
MOVW	R7, #20735
MOVT	R7, #549
NOP
NOP
L_applicationTask10:
SUBS	R7, R7, #1
BNE	L_applicationTask10
NOP
NOP
NOP
;Click_BUCK7_STM.c,61 :: 		buck7_setOutputVoltage( _BUCK7_OUT_VOLTAGE_20V );
MOVW	R0, __BUCK7_OUT_VOLTAGE_20V
BL	_buck7_setOutputVoltage+0
;Click_BUCK7_STM.c,62 :: 		Delay_ms( 3000 );
MOVW	R7, #20735
MOVT	R7, #549
NOP
NOP
L_applicationTask12:
SUBS	R7, R7, #1
BNE	L_applicationTask12
NOP
NOP
NOP
;Click_BUCK7_STM.c,63 :: 		buck7_setOutputVoltage( _BUCK7_OUT_VOLTAGE_15V );
MOVW	R0, __BUCK7_OUT_VOLTAGE_15V
BL	_buck7_setOutputVoltage+0
;Click_BUCK7_STM.c,64 :: 		Delay_ms( 3000 );
MOVW	R7, #20735
MOVT	R7, #549
NOP
NOP
L_applicationTask14:
SUBS	R7, R7, #1
BNE	L_applicationTask14
NOP
NOP
NOP
;Click_BUCK7_STM.c,65 :: 		buck7_setOutputVoltage( 0x0BB8 ); /* 10 V */
MOVW	R0, #3000
BL	_buck7_setOutputVoltage+0
;Click_BUCK7_STM.c,66 :: 		Delay_ms( 3000 );
MOVW	R7, #20735
MOVT	R7, #549
NOP
NOP
L_applicationTask16:
SUBS	R7, R7, #1
BNE	L_applicationTask16
NOP
NOP
NOP
;Click_BUCK7_STM.c,67 :: 		}
L_end_applicationTask:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _applicationTask
_main:
;Click_BUCK7_STM.c,69 :: 		void main()
;Click_BUCK7_STM.c,71 :: 		systemInit();
BL	_systemInit+0
;Click_BUCK7_STM.c,72 :: 		applicationInit();
BL	_applicationInit+0
;Click_BUCK7_STM.c,74 :: 		while (1)
L_main18:
;Click_BUCK7_STM.c,76 :: 		applicationTask();
BL	_applicationTask+0
;Click_BUCK7_STM.c,77 :: 		}
IT	AL
BAL	L_main18
;Click_BUCK7_STM.c,78 :: 		}
L_end_main:
L__main_end_loop:
B	L__main_end_loop
; end of _main
