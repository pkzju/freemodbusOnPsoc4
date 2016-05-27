/*******************************************************************************
* File Name: PWMDAC2.h  
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

#if !defined(CY_PINS_PWMDAC2_H) /* Pins PWMDAC2_H */
#define CY_PINS_PWMDAC2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "PWMDAC2_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    PWMDAC2_Write(uint8 value) ;
void    PWMDAC2_SetDriveMode(uint8 mode) ;
uint8   PWMDAC2_ReadDataReg(void) ;
uint8   PWMDAC2_Read(void) ;
uint8   PWMDAC2_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define PWMDAC2_DRIVE_MODE_BITS        (3)
#define PWMDAC2_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - PWMDAC2_DRIVE_MODE_BITS))

#define PWMDAC2_DM_ALG_HIZ         (0x00u)
#define PWMDAC2_DM_DIG_HIZ         (0x01u)
#define PWMDAC2_DM_RES_UP          (0x02u)
#define PWMDAC2_DM_RES_DWN         (0x03u)
#define PWMDAC2_DM_OD_LO           (0x04u)
#define PWMDAC2_DM_OD_HI           (0x05u)
#define PWMDAC2_DM_STRONG          (0x06u)
#define PWMDAC2_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define PWMDAC2_MASK               PWMDAC2__MASK
#define PWMDAC2_SHIFT              PWMDAC2__SHIFT
#define PWMDAC2_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define PWMDAC2_PS                     (* (reg32 *) PWMDAC2__PS)
/* Port Configuration */
#define PWMDAC2_PC                     (* (reg32 *) PWMDAC2__PC)
/* Data Register */
#define PWMDAC2_DR                     (* (reg32 *) PWMDAC2__DR)
/* Input Buffer Disable Override */
#define PWMDAC2_INP_DIS                (* (reg32 *) PWMDAC2__PC2)


#if defined(PWMDAC2__INTSTAT)  /* Interrupt Registers */

    #define PWMDAC2_INTSTAT                (* (reg32 *) PWMDAC2__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define PWMDAC2_DRIVE_MODE_SHIFT       (0x00u)
#define PWMDAC2_DRIVE_MODE_MASK        (0x07u << PWMDAC2_DRIVE_MODE_SHIFT)


#endif /* End Pins PWMDAC2_H */


/* [] END OF FILE */
