/*******************************************************************************
* File Name: PWMCL.h  
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

#if !defined(CY_PINS_PWMCL_H) /* Pins PWMCL_H */
#define CY_PINS_PWMCL_H

#include "cytypes.h"
#include "cyfitter.h"
#include "PWMCL_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    PWMCL_Write(uint8 value) ;
void    PWMCL_SetDriveMode(uint8 mode) ;
uint8   PWMCL_ReadDataReg(void) ;
uint8   PWMCL_Read(void) ;
uint8   PWMCL_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define PWMCL_DRIVE_MODE_BITS        (3)
#define PWMCL_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - PWMCL_DRIVE_MODE_BITS))

#define PWMCL_DM_ALG_HIZ         (0x00u)
#define PWMCL_DM_DIG_HIZ         (0x01u)
#define PWMCL_DM_RES_UP          (0x02u)
#define PWMCL_DM_RES_DWN         (0x03u)
#define PWMCL_DM_OD_LO           (0x04u)
#define PWMCL_DM_OD_HI           (0x05u)
#define PWMCL_DM_STRONG          (0x06u)
#define PWMCL_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define PWMCL_MASK               PWMCL__MASK
#define PWMCL_SHIFT              PWMCL__SHIFT
#define PWMCL_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define PWMCL_PS                     (* (reg32 *) PWMCL__PS)
/* Port Configuration */
#define PWMCL_PC                     (* (reg32 *) PWMCL__PC)
/* Data Register */
#define PWMCL_DR                     (* (reg32 *) PWMCL__DR)
/* Input Buffer Disable Override */
#define PWMCL_INP_DIS                (* (reg32 *) PWMCL__PC2)


#if defined(PWMCL__INTSTAT)  /* Interrupt Registers */

    #define PWMCL_INTSTAT                (* (reg32 *) PWMCL__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define PWMCL_DRIVE_MODE_SHIFT       (0x00u)
#define PWMCL_DRIVE_MODE_MASK        (0x07u << PWMCL_DRIVE_MODE_SHIFT)


#endif /* End Pins PWMCL_H */


/* [] END OF FILE */
