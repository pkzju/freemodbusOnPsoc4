/*******************************************************************************
* File Name: A_Hall_ref.h  
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

#if !defined(CY_PINS_A_Hall_ref_H) /* Pins A_Hall_ref_H */
#define CY_PINS_A_Hall_ref_H

#include "cytypes.h"
#include "cyfitter.h"
#include "A_Hall_ref_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    A_Hall_ref_Write(uint8 value) ;
void    A_Hall_ref_SetDriveMode(uint8 mode) ;
uint8   A_Hall_ref_ReadDataReg(void) ;
uint8   A_Hall_ref_Read(void) ;
uint8   A_Hall_ref_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define A_Hall_ref_DRIVE_MODE_BITS        (3)
#define A_Hall_ref_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - A_Hall_ref_DRIVE_MODE_BITS))

#define A_Hall_ref_DM_ALG_HIZ         (0x00u)
#define A_Hall_ref_DM_DIG_HIZ         (0x01u)
#define A_Hall_ref_DM_RES_UP          (0x02u)
#define A_Hall_ref_DM_RES_DWN         (0x03u)
#define A_Hall_ref_DM_OD_LO           (0x04u)
#define A_Hall_ref_DM_OD_HI           (0x05u)
#define A_Hall_ref_DM_STRONG          (0x06u)
#define A_Hall_ref_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define A_Hall_ref_MASK               A_Hall_ref__MASK
#define A_Hall_ref_SHIFT              A_Hall_ref__SHIFT
#define A_Hall_ref_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define A_Hall_ref_PS                     (* (reg32 *) A_Hall_ref__PS)
/* Port Configuration */
#define A_Hall_ref_PC                     (* (reg32 *) A_Hall_ref__PC)
/* Data Register */
#define A_Hall_ref_DR                     (* (reg32 *) A_Hall_ref__DR)
/* Input Buffer Disable Override */
#define A_Hall_ref_INP_DIS                (* (reg32 *) A_Hall_ref__PC2)


#if defined(A_Hall_ref__INTSTAT)  /* Interrupt Registers */

    #define A_Hall_ref_INTSTAT                (* (reg32 *) A_Hall_ref__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define A_Hall_ref_DRIVE_MODE_SHIFT       (0x00u)
#define A_Hall_ref_DRIVE_MODE_MASK        (0x07u << A_Hall_ref_DRIVE_MODE_SHIFT)


#endif /* End Pins A_Hall_ref_H */


/* [] END OF FILE */
