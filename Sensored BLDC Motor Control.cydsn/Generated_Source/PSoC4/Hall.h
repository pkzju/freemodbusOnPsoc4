/*******************************************************************************
* File Name: Hall.h  
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

#if !defined(CY_PINS_Hall_H) /* Pins Hall_H */
#define CY_PINS_Hall_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Hall_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Hall_Write(uint8 value) ;
void    Hall_SetDriveMode(uint8 mode) ;
uint8   Hall_ReadDataReg(void) ;
uint8   Hall_Read(void) ;
uint8   Hall_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Hall_DRIVE_MODE_BITS        (3)
#define Hall_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Hall_DRIVE_MODE_BITS))

#define Hall_DM_ALG_HIZ         (0x00u)
#define Hall_DM_DIG_HIZ         (0x01u)
#define Hall_DM_RES_UP          (0x02u)
#define Hall_DM_RES_DWN         (0x03u)
#define Hall_DM_OD_LO           (0x04u)
#define Hall_DM_OD_HI           (0x05u)
#define Hall_DM_STRONG          (0x06u)
#define Hall_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define Hall_MASK               Hall__MASK
#define Hall_SHIFT              Hall__SHIFT
#define Hall_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Hall_PS                     (* (reg32 *) Hall__PS)
/* Port Configuration */
#define Hall_PC                     (* (reg32 *) Hall__PC)
/* Data Register */
#define Hall_DR                     (* (reg32 *) Hall__DR)
/* Input Buffer Disable Override */
#define Hall_INP_DIS                (* (reg32 *) Hall__PC2)


#if defined(Hall__INTSTAT)  /* Interrupt Registers */

    #define Hall_INTSTAT                (* (reg32 *) Hall__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define Hall_DRIVE_MODE_SHIFT       (0x00u)
#define Hall_DRIVE_MODE_MASK        (0x07u << Hall_DRIVE_MODE_SHIFT)


#endif /* End Pins Hall_H */


/* [] END OF FILE */
