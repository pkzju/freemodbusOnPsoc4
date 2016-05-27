/*******************************************************************************
* File Name: PWMCH.h  
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

#if !defined(CY_PINS_PWMCH_H) /* Pins PWMCH_H */
#define CY_PINS_PWMCH_H

#include "cytypes.h"
#include "cyfitter.h"
#include "PWMCH_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    PWMCH_Write(uint8 value) ;
void    PWMCH_SetDriveMode(uint8 mode) ;
uint8   PWMCH_ReadDataReg(void) ;
uint8   PWMCH_Read(void) ;
uint8   PWMCH_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define PWMCH_DRIVE_MODE_BITS        (3)
#define PWMCH_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - PWMCH_DRIVE_MODE_BITS))

#define PWMCH_DM_ALG_HIZ         (0x00u)
#define PWMCH_DM_DIG_HIZ         (0x01u)
#define PWMCH_DM_RES_UP          (0x02u)
#define PWMCH_DM_RES_DWN         (0x03u)
#define PWMCH_DM_OD_LO           (0x04u)
#define PWMCH_DM_OD_HI           (0x05u)
#define PWMCH_DM_STRONG          (0x06u)
#define PWMCH_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define PWMCH_MASK               PWMCH__MASK
#define PWMCH_SHIFT              PWMCH__SHIFT
#define PWMCH_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define PWMCH_PS                     (* (reg32 *) PWMCH__PS)
/* Port Configuration */
#define PWMCH_PC                     (* (reg32 *) PWMCH__PC)
/* Data Register */
#define PWMCH_DR                     (* (reg32 *) PWMCH__DR)
/* Input Buffer Disable Override */
#define PWMCH_INP_DIS                (* (reg32 *) PWMCH__PC2)


#if defined(PWMCH__INTSTAT)  /* Interrupt Registers */

    #define PWMCH_INTSTAT                (* (reg32 *) PWMCH__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define PWMCH_DRIVE_MODE_SHIFT       (0x00u)
#define PWMCH_DRIVE_MODE_MASK        (0x07u << PWMCH_DRIVE_MODE_SHIFT)


#endif /* End Pins PWMCH_H */


/* [] END OF FILE */
