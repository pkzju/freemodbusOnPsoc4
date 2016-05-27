/*******************************************************************************
* File Name: OP_I_b_Vout_Filt.h  
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

#if !defined(CY_PINS_OP_I_b_Vout_Filt_H) /* Pins OP_I_b_Vout_Filt_H */
#define CY_PINS_OP_I_b_Vout_Filt_H

#include "cytypes.h"
#include "cyfitter.h"
#include "OP_I_b_Vout_Filt_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    OP_I_b_Vout_Filt_Write(uint8 value) ;
void    OP_I_b_Vout_Filt_SetDriveMode(uint8 mode) ;
uint8   OP_I_b_Vout_Filt_ReadDataReg(void) ;
uint8   OP_I_b_Vout_Filt_Read(void) ;
uint8   OP_I_b_Vout_Filt_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define OP_I_b_Vout_Filt_DRIVE_MODE_BITS        (3)
#define OP_I_b_Vout_Filt_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - OP_I_b_Vout_Filt_DRIVE_MODE_BITS))

#define OP_I_b_Vout_Filt_DM_ALG_HIZ         (0x00u)
#define OP_I_b_Vout_Filt_DM_DIG_HIZ         (0x01u)
#define OP_I_b_Vout_Filt_DM_RES_UP          (0x02u)
#define OP_I_b_Vout_Filt_DM_RES_DWN         (0x03u)
#define OP_I_b_Vout_Filt_DM_OD_LO           (0x04u)
#define OP_I_b_Vout_Filt_DM_OD_HI           (0x05u)
#define OP_I_b_Vout_Filt_DM_STRONG          (0x06u)
#define OP_I_b_Vout_Filt_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define OP_I_b_Vout_Filt_MASK               OP_I_b_Vout_Filt__MASK
#define OP_I_b_Vout_Filt_SHIFT              OP_I_b_Vout_Filt__SHIFT
#define OP_I_b_Vout_Filt_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define OP_I_b_Vout_Filt_PS                     (* (reg32 *) OP_I_b_Vout_Filt__PS)
/* Port Configuration */
#define OP_I_b_Vout_Filt_PC                     (* (reg32 *) OP_I_b_Vout_Filt__PC)
/* Data Register */
#define OP_I_b_Vout_Filt_DR                     (* (reg32 *) OP_I_b_Vout_Filt__DR)
/* Input Buffer Disable Override */
#define OP_I_b_Vout_Filt_INP_DIS                (* (reg32 *) OP_I_b_Vout_Filt__PC2)


#if defined(OP_I_b_Vout_Filt__INTSTAT)  /* Interrupt Registers */

    #define OP_I_b_Vout_Filt_INTSTAT                (* (reg32 *) OP_I_b_Vout_Filt__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define OP_I_b_Vout_Filt_DRIVE_MODE_SHIFT       (0x00u)
#define OP_I_b_Vout_Filt_DRIVE_MODE_MASK        (0x07u << OP_I_b_Vout_Filt_DRIVE_MODE_SHIFT)


#endif /* End Pins OP_I_b_Vout_Filt_H */


/* [] END OF FILE */
