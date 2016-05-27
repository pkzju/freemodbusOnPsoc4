/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include <project.h>
#include "port.h"
#include "UART_2.h"

//#include <B_LED.h>
//#include <G_LED.h>
//#include <R_LED.h>

/* ----------------------- Modbus includes ----------------------------------*/
#include "modbus/include/mb.h"
#include "modbus/include/mbport.h"

/* ----------------------- Start implementation -----------------------------*/

void
vMBPortSerialEnable( BOOL xRxEnable, BOOL xTxEnable )
{
    
    if(xRxEnable){
        UART_2_ENABLE_INTR_RX(UART_2_INTR_RX_NOT_EMPTY);
        UART_2_RX_CTRL_REG |= UART_2_RX_CTRL_ENABLED;
    }
    else{
        UART_2_DISABLE_INTR_RX(UART_2_INTR_RX_NOT_EMPTY);
        UART_2_RX_CTRL_REG &= ~UART_2_RX_CTRL_ENABLED;
    }
    
    if(xTxEnable){
        RE_Write(1);
        UART_2_ENABLE_INTR_TX(UART_2_INTR_TX_EMPTY);
        UART_2_TX_CTRL_REG |= UART_2_TX_CTRL_ENABLED;
    }
    else{
        RE_Write(0);
        UART_2_DISABLE_INTR_TX(UART_2_INTR_TX_EMPTY);
        UART_2_TX_CTRL_REG &= ~UART_2_TX_CTRL_ENABLED;
    }
    
}

CY_ISR(SCB_IRQ)
{
   
    
    if(UART_2_GetRxInterruptSourceMasked() == UART_2_INTR_RX_NOT_EMPTY)
    {
        pxMBFrameCBByteReceived(  );

        UART_2_ClearRxInterruptSource(UART_2_INTR_RX_NOT_EMPTY);
    }

    if(UART_2_GetTxInterruptSourceMasked() == (UART_2_INTR_TX_EMPTY))
    {
       
        pxMBFrameCBTransmitterEmpty(  );
        UART_2_ClearTxInterruptSource(UART_2_INTR_TX_EMPTY);
    }
}
BOOL
xMBPortSerialInit( UCHAR ucPORT, ULONG ulBaudRate, UCHAR ucDataBits, eMBParity eParity )
{
    
    UART_2_Start();
    UART_2_ClearRxInterruptSource(UART_2_INTR_RX_NOT_EMPTY);
    UART_2_ClearTxInterruptSource(UART_2_INTR_TX_EMPTY);
    UART_2_SCB_IRQ_StartEx(SCB_IRQ);
    return TRUE;
}

BOOL
xMBPortSerialPutByte( CHAR ucByte )
{
    /* Put a byte in the UARTs transmit buffer. This function is called
     * by the protocol stack if pxMBFrameCBTransmitterEmpty( ) has been
     * called. */
    
    UART_2_SpiUartWriteTxData(ucByte);

    return TRUE;
}

BOOL
xMBPortSerialGetByte( CHAR * pucByte )
{
    /* Return the byte in the UARTs receive buffer. This function is called
     * by the protocol stack after pxMBFrameCBByteReceived( ) has been called.
     */

    *pucByte = UART_2_SpiUartReadRxData();

    return TRUE;            // return TRUE if Parity Error Flag was not set
}


/* [] END OF FILE */
