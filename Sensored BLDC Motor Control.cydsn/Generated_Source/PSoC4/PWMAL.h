/*******************************************************************************
* File Name: PWMAL.h  
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

#if !defined(CY_PINS_PWMAL_H) /* Pins PWMAL_H */
#define CY_PINS_PWMAL_H

#include "cytypes.h"
#include "cyfitter.h"
#include "PWMAL_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    PWMAL_Write(uint8 value) ;
void    PWMAL_SetDriveMode(uint8 mode) ;
uint8   PWMAL_ReadDataReg(void) ;
uint8   PWMAL_Read(void) ;
uint8   PWMAL_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define PWMAL_DRIVE_MODE_BITS        (3)
#define PWMAL_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - PWMAL_DRIVE_MODE_BITS))

#define PWMAL_DM_ALG_HIZ         (0x00u)
#define PWMAL_DM_DIG_HIZ         (0x01u)
#define PWMAL_DM_RES_UP          (0x02u)
#define PWMAL_DM_RES_DWN         (0x03u)
#define PWMAL_DM_OD_LO           (0x04u)
#define PWMAL_DM_OD_HI           (0x05u)
#define PWMAL_DM_STRONG          (0x06u)
#define PWMAL_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define PWMAL_MASK               PWMAL__MASK
#define PWMAL_SHIFT              PWMAL__SHIFT
#define PWMAL_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define PWMAL_PS                     (* (reg32 *) PWMAL__PS)
/* Port Configuration */
#define PWMAL_PC                     (* (reg32 *) PWMAL__PC)
/* Data Register */
#define PWMAL_DR                     (* (reg32 *) PWMAL__DR)
/* Input Buffer Disable Override */
#define PWMAL_INP_DIS                (* (reg32 *) PWMAL__PC2)


#if defined(PWMAL__INTSTAT)  /* Interrupt Registers */

    #define PWMAL_INTSTAT                (* (reg32 *) PWMAL__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define PWMAL_DRIVE_MODE_SHIFT       (0x00u)
#define PWMAL_DRIVE_MODE_MASK        (0x07u << PWMAL_DRIVE_MODE_SHIFT)


#endif /* End Pins PWMAL_H */


/* [] END OF FILE */
