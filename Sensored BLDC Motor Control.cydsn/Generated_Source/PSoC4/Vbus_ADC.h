/*******************************************************************************
* File Name: Vbus_ADC.h  
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

#if !defined(CY_PINS_Vbus_ADC_H) /* Pins Vbus_ADC_H */
#define CY_PINS_Vbus_ADC_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Vbus_ADC_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Vbus_ADC_Write(uint8 value) ;
void    Vbus_ADC_SetDriveMode(uint8 mode) ;
uint8   Vbus_ADC_ReadDataReg(void) ;
uint8   Vbus_ADC_Read(void) ;
uint8   Vbus_ADC_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Vbus_ADC_DRIVE_MODE_BITS        (3)
#define Vbus_ADC_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Vbus_ADC_DRIVE_MODE_BITS))

#define Vbus_ADC_DM_ALG_HIZ         (0x00u)
#define Vbus_ADC_DM_DIG_HIZ         (0x01u)
#define Vbus_ADC_DM_RES_UP          (0x02u)
#define Vbus_ADC_DM_RES_DWN         (0x03u)
#define Vbus_ADC_DM_OD_LO           (0x04u)
#define Vbus_ADC_DM_OD_HI           (0x05u)
#define Vbus_ADC_DM_STRONG          (0x06u)
#define Vbus_ADC_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define Vbus_ADC_MASK               Vbus_ADC__MASK
#define Vbus_ADC_SHIFT              Vbus_ADC__SHIFT
#define Vbus_ADC_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Vbus_ADC_PS                     (* (reg32 *) Vbus_ADC__PS)
/* Port Configuration */
#define Vbus_ADC_PC                     (* (reg32 *) Vbus_ADC__PC)
/* Data Register */
#define Vbus_ADC_DR                     (* (reg32 *) Vbus_ADC__DR)
/* Input Buffer Disable Override */
#define Vbus_ADC_INP_DIS                (* (reg32 *) Vbus_ADC__PC2)


#if defined(Vbus_ADC__INTSTAT)  /* Interrupt Registers */

    #define Vbus_ADC_INTSTAT                (* (reg32 *) Vbus_ADC__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define Vbus_ADC_DRIVE_MODE_SHIFT       (0x00u)
#define Vbus_ADC_DRIVE_MODE_MASK        (0x07u << Vbus_ADC_DRIVE_MODE_SHIFT)


#endif /* End Pins Vbus_ADC_H */


/* [] END OF FILE */
