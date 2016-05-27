/*******************************************************************************
* File Name: Relay.h  
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

#if !defined(CY_PINS_Relay_H) /* Pins Relay_H */
#define CY_PINS_Relay_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Relay_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Relay_Write(uint8 value) ;
void    Relay_SetDriveMode(uint8 mode) ;
uint8   Relay_ReadDataReg(void) ;
uint8   Relay_Read(void) ;
uint8   Relay_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Relay_DRIVE_MODE_BITS        (3)
#define Relay_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Relay_DRIVE_MODE_BITS))

#define Relay_DM_ALG_HIZ         (0x00u)
#define Relay_DM_DIG_HIZ         (0x01u)
#define Relay_DM_RES_UP          (0x02u)
#define Relay_DM_RES_DWN         (0x03u)
#define Relay_DM_OD_LO           (0x04u)
#define Relay_DM_OD_HI           (0x05u)
#define Relay_DM_STRONG          (0x06u)
#define Relay_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define Relay_MASK               Relay__MASK
#define Relay_SHIFT              Relay__SHIFT
#define Relay_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Relay_PS                     (* (reg32 *) Relay__PS)
/* Port Configuration */
#define Relay_PC                     (* (reg32 *) Relay__PC)
/* Data Register */
#define Relay_DR                     (* (reg32 *) Relay__DR)
/* Input Buffer Disable Override */
#define Relay_INP_DIS                (* (reg32 *) Relay__PC2)


#if defined(Relay__INTSTAT)  /* Interrupt Registers */

    #define Relay_INTSTAT                (* (reg32 *) Relay__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define Relay_DRIVE_MODE_SHIFT       (0x00u)
#define Relay_DRIVE_MODE_MASK        (0x07u << Relay_DRIVE_MODE_SHIFT)


#endif /* End Pins Relay_H */


/* [] END OF FILE */
