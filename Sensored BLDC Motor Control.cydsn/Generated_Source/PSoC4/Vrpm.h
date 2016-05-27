/*******************************************************************************
* File Name: Vrpm.h  
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

#if !defined(CY_PINS_Vrpm_H) /* Pins Vrpm_H */
#define CY_PINS_Vrpm_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Vrpm_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Vrpm_Write(uint8 value) ;
void    Vrpm_SetDriveMode(uint8 mode) ;
uint8   Vrpm_ReadDataReg(void) ;
uint8   Vrpm_Read(void) ;
uint8   Vrpm_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Vrpm_DRIVE_MODE_BITS        (3)
#define Vrpm_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Vrpm_DRIVE_MODE_BITS))

#define Vrpm_DM_ALG_HIZ         (0x00u)
#define Vrpm_DM_DIG_HIZ         (0x01u)
#define Vrpm_DM_RES_UP          (0x02u)
#define Vrpm_DM_RES_DWN         (0x03u)
#define Vrpm_DM_OD_LO           (0x04u)
#define Vrpm_DM_OD_HI           (0x05u)
#define Vrpm_DM_STRONG          (0x06u)
#define Vrpm_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define Vrpm_MASK               Vrpm__MASK
#define Vrpm_SHIFT              Vrpm__SHIFT
#define Vrpm_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Vrpm_PS                     (* (reg32 *) Vrpm__PS)
/* Port Configuration */
#define Vrpm_PC                     (* (reg32 *) Vrpm__PC)
/* Data Register */
#define Vrpm_DR                     (* (reg32 *) Vrpm__DR)
/* Input Buffer Disable Override */
#define Vrpm_INP_DIS                (* (reg32 *) Vrpm__PC2)


#if defined(Vrpm__INTSTAT)  /* Interrupt Registers */

    #define Vrpm_INTSTAT                (* (reg32 *) Vrpm__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define Vrpm_DRIVE_MODE_SHIFT       (0x00u)
#define Vrpm_DRIVE_MODE_MASK        (0x07u << Vrpm_DRIVE_MODE_SHIFT)


#endif /* End Pins Vrpm_H */


/* [] END OF FILE */
