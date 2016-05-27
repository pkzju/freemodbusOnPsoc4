/*******************************************************************************
* File Name: Hall1.h  
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

#if !defined(CY_PINS_Hall1_H) /* Pins Hall1_H */
#define CY_PINS_Hall1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Hall1_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Hall1_Write(uint8 value) ;
void    Hall1_SetDriveMode(uint8 mode) ;
uint8   Hall1_ReadDataReg(void) ;
uint8   Hall1_Read(void) ;
uint8   Hall1_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Hall1_DRIVE_MODE_BITS        (3)
#define Hall1_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Hall1_DRIVE_MODE_BITS))

#define Hall1_DM_ALG_HIZ         (0x00u)
#define Hall1_DM_DIG_HIZ         (0x01u)
#define Hall1_DM_RES_UP          (0x02u)
#define Hall1_DM_RES_DWN         (0x03u)
#define Hall1_DM_OD_LO           (0x04u)
#define Hall1_DM_OD_HI           (0x05u)
#define Hall1_DM_STRONG          (0x06u)
#define Hall1_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define Hall1_MASK               Hall1__MASK
#define Hall1_SHIFT              Hall1__SHIFT
#define Hall1_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Hall1_PS                     (* (reg32 *) Hall1__PS)
/* Port Configuration */
#define Hall1_PC                     (* (reg32 *) Hall1__PC)
/* Data Register */
#define Hall1_DR                     (* (reg32 *) Hall1__DR)
/* Input Buffer Disable Override */
#define Hall1_INP_DIS                (* (reg32 *) Hall1__PC2)


#if defined(Hall1__INTSTAT)  /* Interrupt Registers */

    #define Hall1_INTSTAT                (* (reg32 *) Hall1__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define Hall1_DRIVE_MODE_SHIFT       (0x00u)
#define Hall1_DRIVE_MODE_MASK        (0x07u << Hall1_DRIVE_MODE_SHIFT)


#endif /* End Pins Hall1_H */


/* [] END OF FILE */
