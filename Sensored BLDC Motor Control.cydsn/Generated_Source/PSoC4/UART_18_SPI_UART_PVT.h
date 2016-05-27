/*******************************************************************************
* File Name: UART_18_SPI_UART_PVT.h
* Version 3.0
*
* Description:
*  This private file provides constants and parameter values for the
*  SCB Component in SPI and UART modes.
*  Please do not use this file or its content in your project.
*
* Note:
*
********************************************************************************
* Copyright 2013-2015, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SCB_SPI_UART_PVT_UART_18_H)
#define CY_SCB_SPI_UART_PVT_UART_18_H

#include "UART_18_SPI_UART.h"


/***************************************
*     Internal Global Vars
***************************************/

#if (UART_18_INTERNAL_RX_SW_BUFFER_CONST)
    extern volatile uint32  UART_18_rxBufferHead;
    extern volatile uint32  UART_18_rxBufferTail;
    extern volatile uint8   UART_18_rxBufferOverflow;
#endif /* (UART_18_INTERNAL_RX_SW_BUFFER_CONST) */

#if (UART_18_INTERNAL_TX_SW_BUFFER_CONST)
    extern volatile uint32  UART_18_txBufferHead;
    extern volatile uint32  UART_18_txBufferTail;
#endif /* (UART_18_INTERNAL_TX_SW_BUFFER_CONST) */

#if (UART_18_INTERNAL_RX_SW_BUFFER)
    extern volatile uint8 UART_18_rxBufferInternal[UART_18_INTERNAL_RX_BUFFER_SIZE];
#endif /* (UART_18_INTERNAL_RX_SW_BUFFER) */

#if (UART_18_INTERNAL_TX_SW_BUFFER)
    extern volatile uint8 UART_18_txBufferInternal[UART_18_TX_BUFFER_SIZE];
#endif /* (UART_18_INTERNAL_TX_SW_BUFFER) */


/***************************************
*     Private Function Prototypes
***************************************/

void UART_18_SpiPostEnable(void);
void UART_18_SpiStop(void);

#if (UART_18_SCB_MODE_SPI_CONST_CFG)
    void UART_18_SpiInit(void);
#endif /* (UART_18_SCB_MODE_SPI_CONST_CFG) */

#if (UART_18_SPI_WAKE_ENABLE_CONST)
    void UART_18_SpiSaveConfig(void);
    void UART_18_SpiRestoreConfig(void);
#endif /* (UART_18_SPI_WAKE_ENABLE_CONST) */

void UART_18_UartPostEnable(void);
void UART_18_UartStop(void);

#if (UART_18_SCB_MODE_UART_CONST_CFG)
    void UART_18_UartInit(void);
#endif /* (UART_18_SCB_MODE_UART_CONST_CFG) */

#if (UART_18_UART_WAKE_ENABLE_CONST)
    void UART_18_UartSaveConfig(void);
    void UART_18_UartRestoreConfig(void);
#endif /* (UART_18_UART_WAKE_ENABLE_CONST) */


/***************************************
*         UART API Constants
***************************************/

/* UART RX and TX position to be used in UART_18_SetPins() */
#define UART_18_UART_RX_PIN_ENABLE    (UART_18_UART_RX)
#define UART_18_UART_TX_PIN_ENABLE    (UART_18_UART_TX)

/* UART RTS and CTS position to be used in  UART_18_SetPins() */
#define UART_18_UART_RTS_PIN_ENABLE    (0x10u)
#define UART_18_UART_CTS_PIN_ENABLE    (0x20u)


/***************************************
* The following code is DEPRECATED and
* must not be used.
***************************************/

/* Interrupt processing */
#define UART_18_SpiUartEnableIntRx(intSourceMask)  UART_18_SetRxInterruptMode(intSourceMask)
#define UART_18_SpiUartEnableIntTx(intSourceMask)  UART_18_SetTxInterruptMode(intSourceMask)
uint32  UART_18_SpiUartDisableIntRx(void);
uint32  UART_18_SpiUartDisableIntTx(void);


#endif /* (CY_SCB_SPI_UART_PVT_UART_18_H) */


/* [] END OF FILE */
