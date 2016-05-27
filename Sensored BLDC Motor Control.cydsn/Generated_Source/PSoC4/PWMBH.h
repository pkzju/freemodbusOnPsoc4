/*******************************************************************************
* File Name: PWMBH.h  
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

#if !defined(CY_PINS_PWMBH_H) /* Pins PWMBH_H */
#define CY_PINS_PWMBH_H

#include "cytypes.h"
#include "cyfitter.h"
#include "PWMBH_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    PWMBH_Write(uint8 value) ;
void    PWMBH_SetDriveMode(uint8 mode) ;
uint8   PWMBH_ReadDataReg(void) ;
uint8   PWMBH_Read(void) ;
uint8   PWMBH_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define PWMBH_DRIVE_MODE_BITS        (3)
#define PWMBH_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - PWMBH_DRIVE_MODE_BITS))

#define PWMBH_DM_ALG_HIZ         (0x00u)
#define PWMBH_DM_DIG_HIZ         (0x01u)
#define PWMBH_DM_RES_UP          (0x02u)
#define PWMBH_DM_RES_DWN         (0x03u)
#define PWMBH_DM_OD_LO           (0x04u)
#define PWMBH_DM_OD_HI           (0x05u)
#define PWMBH_DM_STRONG          (0x06u)
#define PWMBH_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define PWMBH_MASK               PWMBH__MASK
#define PWMBH_SHIFT              PWMBH__SHIFT
#define PWMBH_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define PWMBH_PS                     (* (reg32 *) PWMBH__PS)
/* Port Configuration */
#define PWMBH_PC                     (* (reg32 *) PWMBH__PC)
/* Data Register */
#define PWMBH_DR                     (* (reg32 *) PWMBH__DR)
/* Input Buffer Disable Override */
#define PWMBH_INP_DIS                (* (reg32 *) PWMBH__PC2)


#if defined(PWMBH__INTSTAT)  /* Interrupt Registers */

    #define PWMBH_INTSTAT                (* (reg32 *) PWMBH__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define PWMBH_DRIVE_MODE_SHIFT       (0x00u)
#define PWMBH_DRIVE_MODE_MASK        (0x07u << PWMBH_DRIVE_MODE_SHIFT)


#endif /* End Pins PWMBH_H */


/* [] END OF FILE */
