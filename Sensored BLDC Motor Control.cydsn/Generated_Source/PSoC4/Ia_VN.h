/*******************************************************************************
* File Name: Ia_VN.h  
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

#if !defined(CY_PINS_Ia_VN_H) /* Pins Ia_VN_H */
#define CY_PINS_Ia_VN_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Ia_VN_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Ia_VN_Write(uint8 value) ;
void    Ia_VN_SetDriveMode(uint8 mode) ;
uint8   Ia_VN_ReadDataReg(void) ;
uint8   Ia_VN_Read(void) ;
uint8   Ia_VN_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Ia_VN_DRIVE_MODE_BITS        (3)
#define Ia_VN_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Ia_VN_DRIVE_MODE_BITS))

#define Ia_VN_DM_ALG_HIZ         (0x00u)
#define Ia_VN_DM_DIG_HIZ         (0x01u)
#define Ia_VN_DM_RES_UP          (0x02u)
#define Ia_VN_DM_RES_DWN         (0x03u)
#define Ia_VN_DM_OD_LO           (0x04u)
#define Ia_VN_DM_OD_HI           (0x05u)
#define Ia_VN_DM_STRONG          (0x06u)
#define Ia_VN_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define Ia_VN_MASK               Ia_VN__MASK
#define Ia_VN_SHIFT              Ia_VN__SHIFT
#define Ia_VN_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Ia_VN_PS                     (* (reg32 *) Ia_VN__PS)
/* Port Configuration */
#define Ia_VN_PC                     (* (reg32 *) Ia_VN__PC)
/* Data Register */
#define Ia_VN_DR                     (* (reg32 *) Ia_VN__DR)
/* Input Buffer Disable Override */
#define Ia_VN_INP_DIS                (* (reg32 *) Ia_VN__PC2)


#if defined(Ia_VN__INTSTAT)  /* Interrupt Registers */

    #define Ia_VN_INTSTAT                (* (reg32 *) Ia_VN__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define Ia_VN_DRIVE_MODE_SHIFT       (0x00u)
#define Ia_VN_DRIVE_MODE_MASK        (0x07u << Ia_VN_DRIVE_MODE_SHIFT)


#endif /* End Pins Ia_VN_H */


/* [] END OF FILE */
