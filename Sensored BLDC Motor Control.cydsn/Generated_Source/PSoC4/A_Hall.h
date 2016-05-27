/*******************************************************************************
* File Name: A_Hall.h  
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

#if !defined(CY_PINS_A_Hall_H) /* Pins A_Hall_H */
#define CY_PINS_A_Hall_H

#include "cytypes.h"
#include "cyfitter.h"
#include "A_Hall_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    A_Hall_Write(uint8 value) ;
void    A_Hall_SetDriveMode(uint8 mode) ;
uint8   A_Hall_ReadDataReg(void) ;
uint8   A_Hall_Read(void) ;
uint8   A_Hall_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define A_Hall_DRIVE_MODE_BITS        (3)
#define A_Hall_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - A_Hall_DRIVE_MODE_BITS))

#define A_Hall_DM_ALG_HIZ         (0x00u)
#define A_Hall_DM_DIG_HIZ         (0x01u)
#define A_Hall_DM_RES_UP          (0x02u)
#define A_Hall_DM_RES_DWN         (0x03u)
#define A_Hall_DM_OD_LO           (0x04u)
#define A_Hall_DM_OD_HI           (0x05u)
#define A_Hall_DM_STRONG          (0x06u)
#define A_Hall_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define A_Hall_MASK               A_Hall__MASK
#define A_Hall_SHIFT              A_Hall__SHIFT
#define A_Hall_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define A_Hall_PS                     (* (reg32 *) A_Hall__PS)
/* Port Configuration */
#define A_Hall_PC                     (* (reg32 *) A_Hall__PC)
/* Data Register */
#define A_Hall_DR                     (* (reg32 *) A_Hall__DR)
/* Input Buffer Disable Override */
#define A_Hall_INP_DIS                (* (reg32 *) A_Hall__PC2)


#if defined(A_Hall__INTSTAT)  /* Interrupt Registers */

    #define A_Hall_INTSTAT                (* (reg32 *) A_Hall__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define A_Hall_DRIVE_MODE_SHIFT       (0x00u)
#define A_Hall_DRIVE_MODE_MASK        (0x07u << A_Hall_DRIVE_MODE_SHIFT)


#endif /* End Pins A_Hall_H */


/* [] END OF FILE */
