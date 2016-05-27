/*******************************************************************************
* File Name: PWMBL.h  
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

#if !defined(CY_PINS_PWMBL_H) /* Pins PWMBL_H */
#define CY_PINS_PWMBL_H

#include "cytypes.h"
#include "cyfitter.h"
#include "PWMBL_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    PWMBL_Write(uint8 value) ;
void    PWMBL_SetDriveMode(uint8 mode) ;
uint8   PWMBL_ReadDataReg(void) ;
uint8   PWMBL_Read(void) ;
uint8   PWMBL_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define PWMBL_DRIVE_MODE_BITS        (3)
#define PWMBL_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - PWMBL_DRIVE_MODE_BITS))

#define PWMBL_DM_ALG_HIZ         (0x00u)
#define PWMBL_DM_DIG_HIZ         (0x01u)
#define PWMBL_DM_RES_UP          (0x02u)
#define PWMBL_DM_RES_DWN         (0x03u)
#define PWMBL_DM_OD_LO           (0x04u)
#define PWMBL_DM_OD_HI           (0x05u)
#define PWMBL_DM_STRONG          (0x06u)
#define PWMBL_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define PWMBL_MASK               PWMBL__MASK
#define PWMBL_SHIFT              PWMBL__SHIFT
#define PWMBL_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define PWMBL_PS                     (* (reg32 *) PWMBL__PS)
/* Port Configuration */
#define PWMBL_PC                     (* (reg32 *) PWMBL__PC)
/* Data Register */
#define PWMBL_DR                     (* (reg32 *) PWMBL__DR)
/* Input Buffer Disable Override */
#define PWMBL_INP_DIS                (* (reg32 *) PWMBL__PC2)


#if defined(PWMBL__INTSTAT)  /* Interrupt Registers */

    #define PWMBL_INTSTAT                (* (reg32 *) PWMBL__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define PWMBL_DRIVE_MODE_SHIFT       (0x00u)
#define PWMBL_DRIVE_MODE_MASK        (0x07u << PWMBL_DRIVE_MODE_SHIFT)


#endif /* End Pins PWMBL_H */


/* [] END OF FILE */
