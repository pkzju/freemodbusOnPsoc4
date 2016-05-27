/*******************************************************************************
* File Name: Hall_ref.h  
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

#if !defined(CY_PINS_Hall_ref_H) /* Pins Hall_ref_H */
#define CY_PINS_Hall_ref_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Hall_ref_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Hall_ref_Write(uint8 value) ;
void    Hall_ref_SetDriveMode(uint8 mode) ;
uint8   Hall_ref_ReadDataReg(void) ;
uint8   Hall_ref_Read(void) ;
uint8   Hall_ref_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Hall_ref_DRIVE_MODE_BITS        (3)
#define Hall_ref_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Hall_ref_DRIVE_MODE_BITS))

#define Hall_ref_DM_ALG_HIZ         (0x00u)
#define Hall_ref_DM_DIG_HIZ         (0x01u)
#define Hall_ref_DM_RES_UP          (0x02u)
#define Hall_ref_DM_RES_DWN         (0x03u)
#define Hall_ref_DM_OD_LO           (0x04u)
#define Hall_ref_DM_OD_HI           (0x05u)
#define Hall_ref_DM_STRONG          (0x06u)
#define Hall_ref_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define Hall_ref_MASK               Hall_ref__MASK
#define Hall_ref_SHIFT              Hall_ref__SHIFT
#define Hall_ref_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Hall_ref_PS                     (* (reg32 *) Hall_ref__PS)
/* Port Configuration */
#define Hall_ref_PC                     (* (reg32 *) Hall_ref__PC)
/* Data Register */
#define Hall_ref_DR                     (* (reg32 *) Hall_ref__DR)
/* Input Buffer Disable Override */
#define Hall_ref_INP_DIS                (* (reg32 *) Hall_ref__PC2)


#if defined(Hall_ref__INTSTAT)  /* Interrupt Registers */

    #define Hall_ref_INTSTAT                (* (reg32 *) Hall_ref__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define Hall_ref_DRIVE_MODE_SHIFT       (0x00u)
#define Hall_ref_DRIVE_MODE_MASK        (0x07u << Hall_ref_DRIVE_MODE_SHIFT)


#endif /* End Pins Hall_ref_H */


/* [] END OF FILE */
