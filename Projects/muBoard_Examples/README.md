back to [Wiki](https://github.com/gicking/STM8_templates/wiki)


muBoard Examples
=================

This folder contains some [muBoard](https://frosch.piandmore.de//de/pam9/call/public-media/event_media/160611_Vortrag_Interpreter.pdf) specific example projects for
the STM8 template library. The functionality (loosely sorted by 
rising complexity) is as follows:

LCD-display_I2C: 
----------
  Arduino-like project with setup() & loop().
  Periodically print text to 2x16 char LCD attached to I2C (muBoard)
  Used display: Batron BTHQ21605V-COG-FSRE-I2C 2X16 (Farnell 1220409)
  connected via I2C pins PE1/SCL, PE2/SDA, and GPIO PE3 for LCD reset (see i2c_lcd.c)
  Functionality:
  - initialize I2C bus
  - initialize and reset LCD display
  - periodically print time to LCD  


digital-poti_I2C:
----------
  Arduino-like project with setup() & loop().
  Periodically ramp potentiometer resistance attached to I2C (muBoard).
  Used 20kR potentiometer: Analog Devices AD5280BRUZ20 (Farnell 1438441).
  Connected via I2C pins PE1/SCL and PE2/SDA
  Functionality:
  - initialize I2C bus
  - periodically ramp resistance
  - print current value via UART1  


back to [Wiki](https://github.com/gicking/STM8_templates/wiki)

