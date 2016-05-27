/*******************************************************************************
* File Name: VR_In.h  
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

#if !defined(CY_PINS_VR_In_H) /* Pins VR_In_H */
#define CY_PINS_VR_In_H

#include "cytypes.h"
#include "cyfitter.h"
#include "VR_In_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    VR_In_Write(uint8 value) ;
void    VR_In_SetDriveMode(uint8 mode) ;
uint8   VR_In_ReadDataReg(void) ;
uint8   VR_In_Read(void) ;
uint8   VR_In_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define VR_In_DRIVE_MODE_BITS        (3)
#define VR_In_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - VR_In_DRIVE_MODE_BITS))

#define VR_In_DM_ALG_HIZ         (0x00u)
#define VR_In_DM_DIG_HIZ         (0x01u)
#define VR_In_DM_RES_UP          (0x02u)
#define VR_In_DM_RES_DWN         (0x03u)
#define VR_In_DM_OD_LO           (0x04u)
#define VR_In_DM_OD_HI           (0x05u)
#define VR_In_DM_STRONG          (0x06u)
#define VR_In_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define VR_In_MASK               VR_In__MASK
#define VR_In_SHIFT              VR_In__SHIFT
#define VR_In_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define VR_In_PS                     (* (reg32 *) VR_In__PS)
/* Port Configuration */
#define VR_In_PC                     (* (reg32 *) VR_In__PC)
/* Data Register */
#define VR_In_DR                     (* (reg32 *) VR_In__DR)
/* Input Buffer Disable Override */
#define VR_In_INP_DIS                (* (reg32 *) VR_In__PC2)


#if defined(VR_In__INTSTAT)  /* Interrupt Registers */

    #define VR_In_INTSTAT                (* (reg32 *) VR_In__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define VR_In_DRIVE_MODE_SHIFT       (0x00u)
#define VR_In_DRIVE_MODE_MASK        (0x07u << VR_In_DRIVE_MODE_SHIFT)


#endif /* End Pins VR_In_H */


/* [] END OF FILE */
