/*******************************************************************************
* File Name: Tx_1.h  
* Version 2.10
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Tx_1_H) /* Pins Tx_1_H */
#define CY_PINS_Tx_1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Tx_1_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Tx_1_Write(uint8 value) ;
void    Tx_1_SetDriveMode(uint8 mode) ;
uint8   Tx_1_ReadDataReg(void) ;
uint8   Tx_1_Read(void) ;
uint8   Tx_1_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Tx_1_DRIVE_MODE_BITS        (3)
#define Tx_1_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Tx_1_DRIVE_MODE_BITS))

#define Tx_1_DM_ALG_HIZ         (0x00u)
#define Tx_1_DM_DIG_HIZ         (0x01u)
#define Tx_1_DM_RES_UP          (0x02u)
#define Tx_1_DM_RES_DWN         (0x03u)
#define Tx_1_DM_OD_LO           (0x04u)
#define Tx_1_DM_OD_HI           (0x05u)
#define Tx_1_DM_STRONG          (0x06u)
#define Tx_1_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define Tx_1_MASK               Tx_1__MASK
#define Tx_1_SHIFT              Tx_1__SHIFT
#define Tx_1_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Tx_1_PS                     (* (reg32 *) Tx_1__PS)
/* Port Configuration */
#define Tx_1_PC                     (* (reg32 *) Tx_1__PC)
/* Data Register */
#define Tx_1_DR                     (* (reg32 *) Tx_1__DR)
/* Input Buffer Disable Override */
#define Tx_1_INP_DIS                (* (reg32 *) Tx_1__PC2)


#if defined(Tx_1__INTSTAT)  /* Interrupt Registers */

    #define Tx_1_INTSTAT                (* (reg32 *) Tx_1__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define Tx_1_DRIVE_MODE_SHIFT       (0x00u)
#define Tx_1_DRIVE_MODE_MASK        (0x07u << Tx_1_DRIVE_MODE_SHIFT)


#endif /* End Pins Tx_1_H */


/* [] END OF FILE */
