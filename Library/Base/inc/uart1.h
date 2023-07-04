/**
  \file uart1.h
   
  \author G. Icking-Konert
  \date 2013-11-22
  \version 0.1
   
  \brief declaration of UART1 / USART functions & macros
   
  declaration of UART1 / USART functions and macros for send & receive.
  Optional functionality via #define:
    - USE_UART1_TXE_ISR:  use TXE interrupt (default is w/o ISR)
    - USE_UART1_RXF_ISR:  use RXF interrupt (default is w/o ISR)
*/

/*-----------------------------------------------------------------------------
    MODULE DEFINITION FOR MULTIPLE INCLUSION
-----------------------------------------------------------------------------*/
#ifndef _UART1_H_
#define _UART1_H_


/*-----------------------------------------------------------------------------
    INCLUDE FILES
-----------------------------------------------------------------------------*/
#include "stm8as.h"
#include "config.h"


/*-----------------------------------------------------------------------------
    DECLARATION OF GLOBAL MACROS
-----------------------------------------------------------------------------*/

// only if UART1_TXE interrupts are used
#if defined(USE_UART1_TXE_ISR)

  /// enable UART1_TXE interrupt
  #define UART1_enable_send_interrupt()  UART1.CR2.reg.TIEN = 1

  /// disable UART1_TXE interrupt
  #define UART1_disable_send_interrupt() UART1.CR2.reg.TIEN = 0

#endif

// only if UART1_RXF interrupts are used
#if defined(USE_UART1_RXF_ISR)

  /// enable UART1_RXF interrupt
  #define UART1_enable_receive_interrupt()  UART1.CR2.reg.RIEN = 1

  /// disable UART1_RXF interrupt
  #define UART1_disable_receive_interrupt() UART1.CR2.reg.RIEN = 0

#endif



/*-----------------------------------------------------------------------------
    DECLARATION OF GLOBAL FUNCTIONS
-----------------------------------------------------------------------------*/
/**
  \fn void  UART1_write(uint8_t data)
   
  \brief send byte via UART1
  
  \param[in]  data   byte to send

  send byte via UART1 as soon as possible
*/

volatile void UART1_write(uint8_t data);

/// init UART1 for communication
void UART1_begin(uint32_t BR);

/// send arry of bytes via UART1
void UART1_writeBytes(uint16_t num, uint8_t *buf);


/*-----------------------------------------------------------------------------
    DECLARATION OF GLOBAL INLINE FUNCTIONS
-----------------------------------------------------------------------------*/

/**
  \fn void UART1_end(void)
   
  \brief UART1 disable sender & receiver

  UART1 disable sender & receiver. Retain previous settings
*/
void UART1_end(void);// UART1_end



/**
  \fn uint8_t UART1_available(void)
   
  \brief UART1 check if data available
  
  \return  1=data waiting, 0=receive buffer empty

  UART1 check if data is available
*/
uint8_t UART1_available(void);

uint8_t UART1_read(void);





/**
  \fn uint8_t UART1_read(void)
   
  \brief UART1 byte receive function. Blocking
  
  \return received byte
  
  wait until byte received via UART1 and return content of Rx register
*/




/*-----------------------------------------------------------------------------
    END OF MODULE DEFINITION FOR MULTIPLE INLUSION
-----------------------------------------------------------------------------*/
#endif  // _UART1_H_
