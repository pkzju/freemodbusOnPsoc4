/*******************************************************************************
* File Name: RE.h  
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

#if !defined(CY_PINS_RE_H) /* Pins RE_H */
#define CY_PINS_RE_H

#include "cytypes.h"
#include "cyfitter.h"
#include "RE_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    RE_Write(uint8 value) ;
void    RE_SetDriveMode(uint8 mode) ;
uint8   RE_ReadDataReg(void) ;
uint8   RE_Read(void) ;
uint8   RE_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define RE_DRIVE_MODE_BITS        (3)
#define RE_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - RE_DRIVE_MODE_BITS))

#define RE_DM_ALG_HIZ         (0x00u)
#define RE_DM_DIG_HIZ         (0x01u)
#define RE_DM_RES_UP          (0x02u)
#define RE_DM_RES_DWN         (0x03u)
#define RE_DM_OD_LO           (0x04u)
#define RE_DM_OD_HI           (0x05u)
#define RE_DM_STRONG          (0x06u)
#define RE_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define RE_MASK               RE__MASK
#define RE_SHIFT              RE__SHIFT
#define RE_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define RE_PS                     (* (reg32 *) RE__PS)
/* Port Configuration */
#define RE_PC                     (* (reg32 *) RE__PC)
/* Data Register */
#define RE_DR                     (* (reg32 *) RE__DR)
/* Input Buffer Disable Override */
#define RE_INP_DIS                (* (reg32 *) RE__PC2)


#if defined(RE__INTSTAT)  /* Interrupt Registers */

    #define RE_INTSTAT                (* (reg32 *) RE__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define RE_DRIVE_MODE_SHIFT       (0x00u)
#define RE_DRIVE_MODE_MASK        (0x07u << RE_DRIVE_MODE_SHIFT)


#endif /* End Pins RE_H */


/* [] END OF FILE */
