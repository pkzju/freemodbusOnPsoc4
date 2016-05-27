/*******************************************************************************
* File Name: CtrlReg_PWMOut.h  
* Version 1.80
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CONTROL_REG_CtrlReg_PWMOut_H) /* CY_CONTROL_REG_CtrlReg_PWMOut_H */
#define CY_CONTROL_REG_CtrlReg_PWMOut_H

#include "cytypes.h"

    
/***************************************
*     Data Struct Definitions
***************************************/

/* Sleep Mode API Support */
typedef struct
{
    uint8 controlState;

} CtrlReg_PWMOut_BACKUP_STRUCT;


/***************************************
*         Function Prototypes 
***************************************/

void    CtrlReg_PWMOut_Write(uint8 control) ;
uint8   CtrlReg_PWMOut_Read(void) ;

void CtrlReg_PWMOut_SaveConfig(void) ;
void CtrlReg_PWMOut_RestoreConfig(void) ;
void CtrlReg_PWMOut_Sleep(void) ; 
void CtrlReg_PWMOut_Wakeup(void) ;


/***************************************
*            Registers        
***************************************/

/* Control Register */
#define CtrlReg_PWMOut_Control        (* (reg8 *) CtrlReg_PWMOut_Sync_ctrl_reg__CONTROL_REG )
#define CtrlReg_PWMOut_Control_PTR    (  (reg8 *) CtrlReg_PWMOut_Sync_ctrl_reg__CONTROL_REG )

#endif /* End CY_CONTROL_REG_CtrlReg_PWMOut_H */


/* [] END OF FILE */
