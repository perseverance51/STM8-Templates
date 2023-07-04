/**********************
  Arduino-like project with setup() & loop(). Only 1ms interrupts
  are used, but no other optional features. Can be used as a 
  starting point for simple Arduino-like STM8 projects.
  Functionality:
  - configure pin as output
  - poll SW clock and toggle pin every 500ms -> non-blocking
**********************/

/*----------------------------------------------------------
    INCLUDE FILES
----------------------------------------------------------*/
#include "main_general.h"   // board-independent main


/*----------------------------------------------------------
    MACROS
----------------------------------------------------------*/

// define board LED pin
#if defined(STM8S_DISCOVERY)
  #define LED   pinOutputReg(&PORT_C, pin6)   // STM8S Discovery Board
#elif defined(MUBOARD)
  #define LED   pinOutputReg(&PORT_C, pin7)   // muBoard LED
#else
  #error select supported device/board!
#endif


/*----------------------------------------------------------
    FUNCTIONS
----------------------------------------------------------*/

//////////
// user setup, called once after reset
//////////
void setup() {
  
  // configure LED pin as output
  #if defined(STM8S_DISCOVERY)
    pinMode(&PORT_C, 6, OUTPUT);    // STM8S Discovery Board
  #else
    pinMode(&PORT_C, 7, OUTPUT);    // muBoard LED
  #endif

} // setup



//////////
// user loop, called continuously
//////////
void loop() {

  // poll 1ms flag
  if (flagMilli()) {
    clearFlagMilli();    // reset 1ms flag

    // every 500ms toggle LED
    if (!(millis() % 500))
      LED ^= 1;

  } // if flagMilli
  
} // loop

