/*******************************************************************************
* File Name: VSP.h  
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

#if !defined(CY_PINS_VSP_H) /* Pins VSP_H */
#define CY_PINS_VSP_H

#include "cytypes.h"
#include "cyfitter.h"
#include "VSP_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    VSP_Write(uint8 value) ;
void    VSP_SetDriveMode(uint8 mode) ;
uint8   VSP_ReadDataReg(void) ;
uint8   VSP_Read(void) ;
uint8   VSP_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define VSP_DRIVE_MODE_BITS        (3)
#define VSP_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - VSP_DRIVE_MODE_BITS))

#define VSP_DM_ALG_HIZ         (0x00u)
#define VSP_DM_DIG_HIZ         (0x01u)
#define VSP_DM_RES_UP          (0x02u)
#define VSP_DM_RES_DWN         (0x03u)
#define VSP_DM_OD_LO           (0x04u)
#define VSP_DM_OD_HI           (0x05u)
#define VSP_DM_STRONG          (0x06u)
#define VSP_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define VSP_MASK               VSP__MASK
#define VSP_SHIFT              VSP__SHIFT
#define VSP_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define VSP_PS                     (* (reg32 *) VSP__PS)
/* Port Configuration */
#define VSP_PC                     (* (reg32 *) VSP__PC)
/* Data Register */
#define VSP_DR                     (* (reg32 *) VSP__DR)
/* Input Buffer Disable Override */
#define VSP_INP_DIS                (* (reg32 *) VSP__PC2)


#if defined(VSP__INTSTAT)  /* Interrupt Registers */

    #define VSP_INTSTAT                (* (reg32 *) VSP__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define VSP_DRIVE_MODE_SHIFT       (0x00u)
#define VSP_DRIVE_MODE_MASK        (0x07u << VSP_DRIVE_MODE_SHIFT)


#endif /* End Pins VSP_H */


/* [] END OF FILE */
