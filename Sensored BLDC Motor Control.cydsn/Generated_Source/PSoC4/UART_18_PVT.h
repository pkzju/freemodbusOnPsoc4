/*******************************************************************************
* File Name: .h
* Version 3.0
*
* Description:
*  This private file provides constants and parameter values for the
*  SCB Component.
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

#if !defined(CY_SCB_PVT_UART_18_H)
#define CY_SCB_PVT_UART_18_H

#include "UART_18.h"


/***************************************
*     Private Function Prototypes
***************************************/

/* APIs to service INTR_I2C_EC register */
#define UART_18_SetI2CExtClkInterruptMode(interruptMask) UART_18_WRITE_INTR_I2C_EC_MASK(interruptMask)
#define UART_18_ClearI2CExtClkInterruptSource(interruptMask) UART_18_CLEAR_INTR_I2C_EC(interruptMask)
#define UART_18_GetI2CExtClkInterruptSource()                (UART_18_INTR_I2C_EC_REG)
#define UART_18_GetI2CExtClkInterruptMode()                  (UART_18_INTR_I2C_EC_MASK_REG)
#define UART_18_GetI2CExtClkInterruptSourceMasked()          (UART_18_INTR_I2C_EC_MASKED_REG)

#if (!UART_18_CY_SCBIP_V1)
    /* APIs to service INTR_SPI_EC register */
    #define UART_18_SetSpiExtClkInterruptMode(interruptMask) \
                                                                UART_18_WRITE_INTR_SPI_EC_MASK(interruptMask)
    #define UART_18_ClearSpiExtClkInterruptSource(interruptMask) \
                                                                UART_18_CLEAR_INTR_SPI_EC(interruptMask)
    #define UART_18_GetExtSpiClkInterruptSource()                 (UART_18_INTR_SPI_EC_REG)
    #define UART_18_GetExtSpiClkInterruptMode()                   (UART_18_INTR_SPI_EC_MASK_REG)
    #define UART_18_GetExtSpiClkInterruptSourceMasked()           (UART_18_INTR_SPI_EC_MASKED_REG)
#endif /* (!UART_18_CY_SCBIP_V1) */

#if(UART_18_SCB_MODE_UNCONFIG_CONST_CFG)
    extern void UART_18_SetPins(uint32 mode, uint32 subMode, uint32 uartEnableMask);
#endif /* (UART_18_SCB_MODE_UNCONFIG_CONST_CFG) */


/***************************************
*     Vars with External Linkage
***************************************/

#if (UART_18_SCB_IRQ_INTERNAL)
#if !defined (CY_REMOVE_UART_18_CUSTOM_INTR_HANDLER)
    extern cyisraddress UART_18_customIntrHandler;
#endif /* !defined (CY_REMOVE_UART_18_CUSTOM_INTR_HANDLER) */
#endif /* (UART_18_SCB_IRQ_INTERNAL) */

extern UART_18_BACKUP_STRUCT UART_18_backup;

#if(UART_18_SCB_MODE_UNCONFIG_CONST_CFG)
    /* Common configuration variables */
    extern uint8 UART_18_scbMode;
    extern uint8 UART_18_scbEnableWake;
    extern uint8 UART_18_scbEnableIntr;

    /* I2C configuration variables */
    extern uint8 UART_18_mode;
    extern uint8 UART_18_acceptAddr;

    /* SPI/UART configuration variables */
    extern volatile uint8 * UART_18_rxBuffer;
    extern uint8   UART_18_rxDataBits;
    extern uint32  UART_18_rxBufferSize;

    extern volatile uint8 * UART_18_txBuffer;
    extern uint8   UART_18_txDataBits;
    extern uint32  UART_18_txBufferSize;

    /* EZI2C configuration variables */
    extern uint8 UART_18_numberOfAddr;
    extern uint8 UART_18_subAddrSize;
#endif /* (UART_18_SCB_MODE_UNCONFIG_CONST_CFG) */


/***************************************
*        Conditional Macro
****************************************/

#if(UART_18_SCB_MODE_UNCONFIG_CONST_CFG)
    /* Defines run time operation mode */
    #define UART_18_SCB_MODE_I2C_RUNTM_CFG     (UART_18_SCB_MODE_I2C      == UART_18_scbMode)
    #define UART_18_SCB_MODE_SPI_RUNTM_CFG     (UART_18_SCB_MODE_SPI      == UART_18_scbMode)
    #define UART_18_SCB_MODE_UART_RUNTM_CFG    (UART_18_SCB_MODE_UART     == UART_18_scbMode)
    #define UART_18_SCB_MODE_EZI2C_RUNTM_CFG   (UART_18_SCB_MODE_EZI2C    == UART_18_scbMode)
    #define UART_18_SCB_MODE_UNCONFIG_RUNTM_CFG \
                                                        (UART_18_SCB_MODE_UNCONFIG == UART_18_scbMode)

    /* Defines wakeup enable */
    #define UART_18_SCB_WAKE_ENABLE_CHECK       (0u != UART_18_scbEnableWake)
#endif /* (UART_18_SCB_MODE_UNCONFIG_CONST_CFG) */

/* Defines maximum number of SCB pins */
#if (!UART_18_CY_SCBIP_V1)
    #define UART_18_SCB_PINS_NUMBER    (7u)
#else
    #define UART_18_SCB_PINS_NUMBER    (2u)
#endif /* (!UART_18_CY_SCBIP_V1) */

#endif /* (CY_SCB_PVT_UART_18_H) */


/* [] END OF FILE */
