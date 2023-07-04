back to [Wiki](https://github.com/gicking/STM8_templates/wiki)


General Examples
=================

This folder contains board independent examples for the STM8 template library. 
The functionality is (loosely) sorted by rising complexity.

Minimal-C: 
----------
  simple C-project without Arduino-like initialization and setup()/loop(). 
  No assumption is made, no interrupts used. Can be used as starting point 
  for projects with extreme memory limitations.
  Functionality:
  - init FCPU to 16MHz
  - configure pin as output
  - toggle pin every 500ms with delay (->blocking)


Minimal-C_with_ISR
----------
  simple C-project without Arduino-like initialization and setup()/loop(), 
  but with interrupt.
  Functionality:
  - init FCPU to 16MHz
  - configure pin as output
  - init 1ms TIM4 interrupt (for measuring times)
  - toggle pin every 500ms based on SW clock (->non-blocking)
  Note:
    - define "USE_TIM4_UPD_ISR" in "config.h" for 1ms interrupt (TIM4_UPD)
    - include "stm8_interrupt_vector.h" here, because SDCC needs ISR declaration in file containing main()


Pin_Read_Write:
----------
  Arduino-like project with setup() & loop(). Mirror switch 
  input state to LED (i.e. pin read and write)
  Functionality:
  - configure pin as input with pull-up
  - configure other pin as output
  - mirror input to output 


Basic_Project: 
----------
  Arduino-like project with setup() & loop(). Only 1ms interrupts
  are used, but no other optional features. Can be used as a 
  starting point for simple Arduino-like STM8 projects.
  Functionality:
  - configure pin as output
  - poll SW clock and toggle pin every 500ms -> non-blocking


Timeout_Scheduler:
----------
  Arduino-like project with setup() & loop(). Use several 
  timeouts to execute periodic tasks in loop(). 
  Functionality:
  - configure 2 (LED-)pins as output
  - configure timeouts for periodic tasks
  - toggle 2 pins at different intervals


TIM3_PWM_generate:
----------
  Arduino-like project with setup() & loop(). Use
  16-bit timer 3 to generate PWM with variable
  frequency and duty cycle. 
  Functionality:
  - ramp LED brightness using TIM3 PWM
  - use timeout periodically update brightness


Attach_1ms_Interrupt: 
----------
  Arduino-like project with setup() & loop(). Dynamically attach 
  user functions to 1ms interrupt (-> #define USE_MILLI_ISR) to 
  automatically call function every 1ms. 
  Functionality:
  - configure 2 pins as output high
  - attach pin toggle function to 1ms interrupt -> background operation
  - use timeouts to periodically perform tasks in ISR
  - after N cycles swap user function
  - after M cycles detach user function


Measure_PWM: 
----------
  Arduino-like project with setup() & loop(). 
  Measure a PWM and print frequency and duty cycle 
  via UART to PC terminal. 
  Functionality:
  - configure UART1
  - configure putchar() for PC output via UART1
  - measure PWM frequency and duty cylce (blocking)
  - print via UART


Pin_Interrupt: 
----------
  Arduino-like project with setup() & loop(). 
  Use TLI interrupt @ pin PD7 (=automode on muBoard)
  (-> #define USE_TLI_ISR) to call function on falling edge. 
  Functionality:
  - configure TLI pins as input pull-up w/ interrupt
  - configure 2 pins as output high
  - attach ISR to TLI interrupt -> background operation
  - after N ISR calls disable ISR
  - poll TLI pin and mirror to LED


Port_Interrupt: 
----------
  Arduino-like project with setup() & loop(). 
  Use EXINT port interrupt @ pin PE5 (=io_1 on muBoard)
  (-> #define USE_PORT*_ISR) to call function on falling edge. 
  Functionality:
  - configure 1 pins as input pull-up & 2 pins as output high
  - attach ISR to port interrupt -> background operation
  - after N ISR calls disable ISR
  - poll button and mirror to LED


Printf_UART:
----------
  Arduino-like project with setup() & loop(). Print output
  via UART to PC terminal. Optionally in integer (small)
  or floating (large) number format. 
  For float output #define USE_FTOA in config.h)
  Functionality:
  - configure UART1
  - configure putchar() for PC output via UART1
  - every 500ms send current time via printf()


Gets_Printf_UART:
----------
  Arduino-like project with setup() & loop(). Read number
  as string via UART from PC terminal and echo value back.
  Functionality:
  - configure UART1 for PC in-/output
  - use UART1 send for putchar() output
  - use UART1 receive for gets() input
  - read string from PC, convert to number and send value to PC


echo_UART:
----------
  Arduino-like project with setup() & loop(). 
  Echo bytes received via UART1 with polling.
  Functionality:
  - configure UART1 for PC in-/output
  - poll if byte was received via UART1
  - echo bytes+1 back to PC


echo_UART_with_ISR:
----------
  Arduino-like project with setup() & loop(). 
  Echo bytes received via UART1 with interrupts.
  Functionality:
  - configure UART1 for PC in-/output
  - attach send and receive ISRs to UART1 interrupts
  - in receive ISR echo received byte+1 to PC
  - in send ISR toggle LED for each sent byte


Dhrystone: 
----------
  STM8 port of Dhrystone benchmark test without Arduino-like 
  initialization and setup()/loop(), but with interrupts and
  UART output.
  Functionality (see "portme.c"):
  - init FCPU to 16MHz
  - init 1ms TIM4 interrupt (for measuring times)
  - configure UART1 for output via UART1
  - run benchmark test and print result
  Note:
  - SDCC requires ISRs declared in source containing main(), here "dhry_1.c"
  - template based on: http://www.colecovision.eu/stm8/dhrystone-stm8af5288-usart3-sdcc-3.6.0.tar.gz


Bootloader_Activation
----------
  Arduino-like project with setup() & loop(). 
  Activate/Deactivate STM8 ROM bootloader depending on
  state of pin PD7 (=switch "automode" on muBoard)
  Functionality:
  - configure pin as input pull-up
  - wait a bit and read pin state
  - activate(state=1) or deactivate(state=0) BL via option byte


EEPROM_Datalogger:
----------
  Arduino-like project with setup() & loop(). Write data 
  to EEPROM and read back.
  Functionality:
  - configure UART1
  - configure putchar() for PC output via UART1
  - save data to EEPROM
  - read from EEPROM and print to terminal 


P-Flash_Datalogger:
----------
  Arduino-like project with setup() & loop(). 
  Write data to P-flash and read back.
  Functionality:
  - configure UART1
  - configure putchar() for PC output via UART1
  - save data to P-flash (take care not to overwrite application)
  - read from P-flash and print to terminal 


ADC_Measure:
----------
  Arduino-like project with setup() & loop().
  Periodically measure via ADC and switch LED on/off
  depending on analog threshold
  Functionality:
  - configure pin for LED
  - initialize ADC for single measurement
  - measure ADC and switch LED depending on value 


ADC_Continuous_with_ISR:
----------
  Arduino-like project with setup() & loop().
  Continuously measure ADC channels 0..7 in background
  via ADC interrupt. That way, recent ADC results are
  always available.
  Functionality:
  - initialize ADC for continuous mode
  - attach ISR to ADC_EOC interrupt
  - in ADC ISR sweep through ADC channels
  - send out ADC results via UART on user request


I2C_write
----------
  Arduino-like project with setup() & loop().
  Periodically ramp potentiometer resistance attached to I2C (muBoard).
  Used 20kR potentiometer: Analog Devices AD5280BRUZ20 (Farnell 1438441).
  Connected via I2C pins PE1/SCL and PE2/SDA
  Functionality:
  - initialize I2C bus
  - periodically ramp resistance
  - print current value via UART1  


I2C_read
----------
  Arduino-like project with setup() & loop().
  Periodically request data from an Arduino configured as I2C slave.
  Arduino slave from example "Wire/slave sender".
  Connected via I2C pins PE1/SCL and PE2/SDA
  Functionality:
  - initialize I2C bus
  - periodically read data from Arduino ("hello ")
  - print data via UART1  
  Note: **Not yet functional!!!**


Beeper:
----------
  Arduino-like project with setup() & loop(). 
  Demonstrate tone output via beeper module.
  Beeper requires option byte AFR7=1 for alternate usage of BEEP pin 
  Functionality:
  - assert option byte setting for beeper output 
  - play tones with different pitch
  Note: the beeper module is VERY basic. For flexible tones use timer instead 


Trap_Interrupt:
----------
  Arduino-like project with setup() & loop(). 
  Trigger TRAP interrupt by software. 
  Functionality:
  - configure pin as input pull-up
  - on pin=low, trigger TRAP_ISR


Power_Saving_Modes:
----------
  Arduino-like project with setup() & loop(). 
  Enter power-saving modes with auto-wake via 
    - any interrupt (lowPower_Wait)
    - external interrupt or auto-wake (lowPower_HaltAWU)  
    - external interrupt (lowPower_Halt)
  Use EXINT port interrupt @ pin PE5 (=io_1 on muBoard)
  (-> #define USE_PORTE_ISR) and AWU (-> #define USE_AWU_ISR)
  Functionality:
  - configure wake pin as input pull-up with interrupt on falling edge
  - configure LED output pin
  - enter power-down mode


back to [Wiki](https://github.com/gicking/STM8_templates/wiki)

