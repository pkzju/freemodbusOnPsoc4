/*******************************************************************************
* File Name: PWMAH.h  
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

#if !defined(CY_PINS_PWMAH_H) /* Pins PWMAH_H */
#define CY_PINS_PWMAH_H

#include "cytypes.h"
#include "cyfitter.h"
#include "PWMAH_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    PWMAH_Write(uint8 value) ;
void    PWMAH_SetDriveMode(uint8 mode) ;
uint8   PWMAH_ReadDataReg(void) ;
uint8   PWMAH_Read(void) ;
uint8   PWMAH_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define PWMAH_DRIVE_MODE_BITS        (3)
#define PWMAH_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - PWMAH_DRIVE_MODE_BITS))

#define PWMAH_DM_ALG_HIZ         (0x00u)
#define PWMAH_DM_DIG_HIZ         (0x01u)
#define PWMAH_DM_RES_UP          (0x02u)
#define PWMAH_DM_RES_DWN         (0x03u)
#define PWMAH_DM_OD_LO           (0x04u)
#define PWMAH_DM_OD_HI           (0x05u)
#define PWMAH_DM_STRONG          (0x06u)
#define PWMAH_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define PWMAH_MASK               PWMAH__MASK
#define PWMAH_SHIFT              PWMAH__SHIFT
#define PWMAH_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define PWMAH_PS                     (* (reg32 *) PWMAH__PS)
/* Port Configuration */
#define PWMAH_PC                     (* (reg32 *) PWMAH__PC)
/* Data Register */
#define PWMAH_DR                     (* (reg32 *) PWMAH__DR)
/* Input Buffer Disable Override */
#define PWMAH_INP_DIS                (* (reg32 *) PWMAH__PC2)


#if defined(PWMAH__INTSTAT)  /* Interrupt Registers */

    #define PWMAH_INTSTAT                (* (reg32 *) PWMAH__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define PWMAH_DRIVE_MODE_SHIFT       (0x00u)
#define PWMAH_DRIVE_MODE_MASK        (0x07u << PWMAH_DRIVE_MODE_SHIFT)


#endif /* End Pins PWMAH_H */


/* [] END OF FILE */
