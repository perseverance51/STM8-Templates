/**
  \file uart1.c
   
  \author G. Icking-Konert
  \date 2013-11-22
  \version 0.1
   
  \brief implementation of UART1 / USART functions & macros
   
  implementation of UART1 / USART functions and macros for send & receive.
  Optional functionality via #define:
    - USE_UART1_TXE_ISR:  use TXE interrupt (default is w/o ISR)
    - USE_UART1_RXF_ISR:  use RXF interrupt (default is w/o ISR)
*/

/*-----------------------------------------------------------------------------
    INCLUDE FILES
-----------------------------------------------------------------------------*/
#include "uart1.h"


/*----------------------------------------------------------
    FUNCTIONS
----------------------------------------------------------*/
volatile void UART1_write(uint8_t data) {

  // wait until TX buffer is available
  while (!(UART1.SR.reg.TXE));
    
  // send byte
  UART1.DR.byte = data;
  
} // UART1_write

void UART1_end(void) {

  // disable sender & receiver
  UART1.CR2.reg.TEN = 0;
  UART1.CR2.reg.REN = 0;
  
} // UART1_end

uint8_t UART1_available(void) {

  // return if data in Rx buffer
  return(UART1.SR.reg.RXNE);
  
} // UART1_available

uint8_t UART1_read(void) {

  // wait until byte received
  while (!(UART1.SR.reg.RXNE));

  // return Rx buffer
  return(UART1.DR.byte);

} // UART1_read

/**
  \fn void UART1_begin(uint32_t BR)
   
  \brief initialize UART1 for blocking/polling communication 
  
  \param[in]  BR    baudrate [Baud]

  initialize UART1 for communication with specified baudrate.
  Use 1 start, 8 data and 1 stop bit; no parity or flow control.
*/
void UART1_begin(uint32_t BR) {

  volatile uint16_t  val16;
  
  // set UART1 behaviour
  UART1.CR1.byte = UART1_CR1_RESET_VALUE;  // enable UART1, 8 data bits, no parity control
  UART1.CR2.byte = UART1_CR2_RESET_VALUE;  // no interrupts, disable sender/receiver 
  UART1.CR3.byte = UART1_CR3_RESET_VALUE;  // no LIN support, 1 stop bit, no clock output(?)

  // set baudrate (note: BRR2 must be written before BRR1!)
  val16 = (uint16_t) (((uint32_t) 16000000L)/BR);//HSI:16MHz
//	val16 = (uint16_t) (((uint32_t) 24000000L)/BR);//HSE:24Mhz
  UART1.BRR2.byte = (uint8_t) (((val16 & 0xF000) >> 8) | (val16 & 0x000F));
  UART1.BRR1.byte = (uint8_t) ((val16 & 0x0FF0) >> 4);
  
  // enable transmission
  UART1.CR2.reg.REN = 1; // enable receiver
  UART1.CR2.reg.TEN = 1; // enable sender

} // UART1_begin

 
/**
  \fn void  UART1_writeBytes(uint16_t num, uint8_t *data)
   
  \brief send arry of bytes via UART1
  
  \param[in]  num    buf size in bytes
  \param[in]  data   bytes to send

  send array of bytes via UART1 directly
*/
void  UART1_writeBytes(uint16_t num, uint8_t *data) {

  uint16_t i;

  // send bytes
  for (i=0; i<num; i++) {
    UART1_write(data[i]);
  }      

} // UART1_writeBytes

/*-----------------------------------------------------------------------------
    END OF MODULE
-----------------------------------------------------------------------------*/
