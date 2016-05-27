/*******************************************************************************
* File Name: IPM_FO.h  
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

#if !defined(CY_PINS_IPM_FO_H) /* Pins IPM_FO_H */
#define CY_PINS_IPM_FO_H

#include "cytypes.h"
#include "cyfitter.h"
#include "IPM_FO_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    IPM_FO_Write(uint8 value) ;
void    IPM_FO_SetDriveMode(uint8 mode) ;
uint8   IPM_FO_ReadDataReg(void) ;
uint8   IPM_FO_Read(void) ;
uint8   IPM_FO_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define IPM_FO_DRIVE_MODE_BITS        (3)
#define IPM_FO_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - IPM_FO_DRIVE_MODE_BITS))

#define IPM_FO_DM_ALG_HIZ         (0x00u)
#define IPM_FO_DM_DIG_HIZ         (0x01u)
#define IPM_FO_DM_RES_UP          (0x02u)
#define IPM_FO_DM_RES_DWN         (0x03u)
#define IPM_FO_DM_OD_LO           (0x04u)
#define IPM_FO_DM_OD_HI           (0x05u)
#define IPM_FO_DM_STRONG          (0x06u)
#define IPM_FO_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define IPM_FO_MASK               IPM_FO__MASK
#define IPM_FO_SHIFT              IPM_FO__SHIFT
#define IPM_FO_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define IPM_FO_PS                     (* (reg32 *) IPM_FO__PS)
/* Port Configuration */
#define IPM_FO_PC                     (* (reg32 *) IPM_FO__PC)
/* Data Register */
#define IPM_FO_DR                     (* (reg32 *) IPM_FO__DR)
/* Input Buffer Disable Override */
#define IPM_FO_INP_DIS                (* (reg32 *) IPM_FO__PC2)


#if defined(IPM_FO__INTSTAT)  /* Interrupt Registers */

    #define IPM_FO_INTSTAT                (* (reg32 *) IPM_FO__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define IPM_FO_DRIVE_MODE_SHIFT       (0x00u)
#define IPM_FO_DRIVE_MODE_MASK        (0x07u << IPM_FO_DRIVE_MODE_SHIFT)


#endif /* End Pins IPM_FO_H */


/* [] END OF FILE */
