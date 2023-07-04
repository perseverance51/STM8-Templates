/**********************
  Arduino-like project with setup() & loop(). Mirror switch 
  input state to LED (i.e. pin read and write)
  Functionality:
  - configure pin as input with pull-up
  - configure other pin as output
  - mirror input to output 
**********************/

/*----------------------------------------------------------
    INCLUDE FILES
----------------------------------------------------------*/
#include "main_general.h"   // board-independent main

// access button(=PE5=io_1) and LED(=PH3) pins. See gpio.h
#define BUTTON  pinInputReg(&PORT_G, pin1)
#define LED     pinOutputReg(&PORT_C, pin7)


/*----------------------------------------------------------
    MACROS
----------------------------------------------------------*/

/*----------------------------------------------------------
    FUNCTIONS
----------------------------------------------------------*/

//////////
// user setup, called once after reset
//////////
void setup() {
  
  // configure PE5 (=io_1 on muBoard) as input with pull-up
  pinMode(&PORT_G, 1, INPUT_PULLUP);
      
  // configure PH3 (=red LED on muBoard) as output
  pinMode(&PORT_C, 7, OUTPUT);

} // setup



//////////
// user loop, called continuously
//////////
void loop() {
  
  // mirror pin PE5 to pin PH3
  pinSet(&PORT_C,7, pinRead(&PORT_G, 1));   // via "normal" functions
  //LED = BUTTON;                             // via direct (bitwise) access

} // loop

