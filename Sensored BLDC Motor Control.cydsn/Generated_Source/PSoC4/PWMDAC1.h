/*******************************************************************************
* File Name: PWMDAC1.h  
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

#if !defined(CY_PINS_PWMDAC1_H) /* Pins PWMDAC1_H */
#define CY_PINS_PWMDAC1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "PWMDAC1_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    PWMDAC1_Write(uint8 value) ;
void    PWMDAC1_SetDriveMode(uint8 mode) ;
uint8   PWMDAC1_ReadDataReg(void) ;
uint8   PWMDAC1_Read(void) ;
uint8   PWMDAC1_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define PWMDAC1_DRIVE_MODE_BITS        (3)
#define PWMDAC1_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - PWMDAC1_DRIVE_MODE_BITS))

#define PWMDAC1_DM_ALG_HIZ         (0x00u)
#define PWMDAC1_DM_DIG_HIZ         (0x01u)
#define PWMDAC1_DM_RES_UP          (0x02u)
#define PWMDAC1_DM_RES_DWN         (0x03u)
#define PWMDAC1_DM_OD_LO           (0x04u)
#define PWMDAC1_DM_OD_HI           (0x05u)
#define PWMDAC1_DM_STRONG          (0x06u)
#define PWMDAC1_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define PWMDAC1_MASK               PWMDAC1__MASK
#define PWMDAC1_SHIFT              PWMDAC1__SHIFT
#define PWMDAC1_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define PWMDAC1_PS                     (* (reg32 *) PWMDAC1__PS)
/* Port Configuration */
#define PWMDAC1_PC                     (* (reg32 *) PWMDAC1__PC)
/* Data Register */
#define PWMDAC1_DR                     (* (reg32 *) PWMDAC1__DR)
/* Input Buffer Disable Override */
#define PWMDAC1_INP_DIS                (* (reg32 *) PWMDAC1__PC2)


#if defined(PWMDAC1__INTSTAT)  /* Interrupt Registers */

    #define PWMDAC1_INTSTAT                (* (reg32 *) PWMDAC1__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define PWMDAC1_DRIVE_MODE_SHIFT       (0x00u)
#define PWMDAC1_DRIVE_MODE_MASK        (0x07u << PWMDAC1_DRIVE_MODE_SHIFT)


#endif /* End Pins PWMDAC1_H */


/* [] END OF FILE */
