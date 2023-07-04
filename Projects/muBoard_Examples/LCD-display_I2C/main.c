/**********************
  Arduino-like project with setup() & loop().
  Periodically print text to 2x16 char LCD attached to I2C (muBoard)
  Used display: Batron BTHQ21605V-COG-FSRE-I2C 2X16 (Farnell 1220409)
  connected via I2C pins PE1/SCL, PE2/SDA, and GPIO PE3 for LCD reset (see i2c_lcd.c)
  Functionality:
  - initialize I2C bus
  - initialize and reset LCD display
  - periodically print time to LCD  
**********************/

/*----------------------------------------------------------
    INCLUDE FILES
----------------------------------------------------------*/
#include "main_muBoard.h"    // board-independent main


/*----------------------------------------------------------
    FUNCTIONS
----------------------------------------------------------*/

//////////
// user setup, called once after reset
//////////
void setup() {

  // print to LCD
  lcd_print(1, 1, "hello user...");
  delay(1000);
    
} // setup



//////////
// user loop, called continuously
//////////
void loop() {
  
  char  str[20];    // string buffer for LCD output

  // print to LCD
  sprintf(str, "time = %d s", (int) (millis()/1000L));
  lcd_print(2, 1, str);
      
  // wait 1s
  sw_delay(1000);

} // loop

/*-----------------------------------------------------------------------------
    END OF MODULE
-----------------------------------------------------------------------------*/
