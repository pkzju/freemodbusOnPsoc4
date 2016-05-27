/*******************************************************************************
* File Name: LED0.h  
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

#if !defined(CY_PINS_LED0_H) /* Pins LED0_H */
#define CY_PINS_LED0_H

#include "cytypes.h"
#include "cyfitter.h"
#include "LED0_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    LED0_Write(uint8 value) ;
void    LED0_SetDriveMode(uint8 mode) ;
uint8   LED0_ReadDataReg(void) ;
uint8   LED0_Read(void) ;
uint8   LED0_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define LED0_DRIVE_MODE_BITS        (3)
#define LED0_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - LED0_DRIVE_MODE_BITS))

#define LED0_DM_ALG_HIZ         (0x00u)
#define LED0_DM_DIG_HIZ         (0x01u)
#define LED0_DM_RES_UP          (0x02u)
#define LED0_DM_RES_DWN         (0x03u)
#define LED0_DM_OD_LO           (0x04u)
#define LED0_DM_OD_HI           (0x05u)
#define LED0_DM_STRONG          (0x06u)
#define LED0_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define LED0_MASK               LED0__MASK
#define LED0_SHIFT              LED0__SHIFT
#define LED0_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define LED0_PS                     (* (reg32 *) LED0__PS)
/* Port Configuration */
#define LED0_PC                     (* (reg32 *) LED0__PC)
/* Data Register */
#define LED0_DR                     (* (reg32 *) LED0__DR)
/* Input Buffer Disable Override */
#define LED0_INP_DIS                (* (reg32 *) LED0__PC2)


#if defined(LED0__INTSTAT)  /* Interrupt Registers */

    #define LED0_INTSTAT                (* (reg32 *) LED0__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define LED0_DRIVE_MODE_SHIFT       (0x00u)
#define LED0_DRIVE_MODE_MASK        (0x07u << LED0_DRIVE_MODE_SHIFT)


#endif /* End Pins LED0_H */


/* [] END OF FILE */
