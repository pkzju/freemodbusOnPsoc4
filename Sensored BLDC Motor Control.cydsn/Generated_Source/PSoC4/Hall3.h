/*******************************************************************************
* File Name: Hall3.h  
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

#if !defined(CY_PINS_Hall3_H) /* Pins Hall3_H */
#define CY_PINS_Hall3_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Hall3_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Hall3_Write(uint8 value) ;
void    Hall3_SetDriveMode(uint8 mode) ;
uint8   Hall3_ReadDataReg(void) ;
uint8   Hall3_Read(void) ;
uint8   Hall3_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Hall3_DRIVE_MODE_BITS        (3)
#define Hall3_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Hall3_DRIVE_MODE_BITS))

#define Hall3_DM_ALG_HIZ         (0x00u)
#define Hall3_DM_DIG_HIZ         (0x01u)
#define Hall3_DM_RES_UP          (0x02u)
#define Hall3_DM_RES_DWN         (0x03u)
#define Hall3_DM_OD_LO           (0x04u)
#define Hall3_DM_OD_HI           (0x05u)
#define Hall3_DM_STRONG          (0x06u)
#define Hall3_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define Hall3_MASK               Hall3__MASK
#define Hall3_SHIFT              Hall3__SHIFT
#define Hall3_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Hall3_PS                     (* (reg32 *) Hall3__PS)
/* Port Configuration */
#define Hall3_PC                     (* (reg32 *) Hall3__PC)
/* Data Register */
#define Hall3_DR                     (* (reg32 *) Hall3__DR)
/* Input Buffer Disable Override */
#define Hall3_INP_DIS                (* (reg32 *) Hall3__PC2)


#if defined(Hall3__INTSTAT)  /* Interrupt Registers */

    #define Hall3_INTSTAT                (* (reg32 *) Hall3__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define Hall3_DRIVE_MODE_SHIFT       (0x00u)
#define Hall3_DRIVE_MODE_MASK        (0x07u << Hall3_DRIVE_MODE_SHIFT)


#endif /* End Pins Hall3_H */


/* [] END OF FILE */
