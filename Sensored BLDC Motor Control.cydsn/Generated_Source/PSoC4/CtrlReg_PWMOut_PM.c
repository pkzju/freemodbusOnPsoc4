/*******************************************************************************
* File Name: CtrlReg_PWMOut_PM.c
* Version 1.80
*
* Description:
*  This file contains the setup, control, and status commands to support 
*  the component operation in the low power mode. 
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "CtrlReg_PWMOut.h"

/* Check for removal by optimization */
#if !defined(CtrlReg_PWMOut_Sync_ctrl_reg__REMOVED)

static CtrlReg_PWMOut_BACKUP_STRUCT  CtrlReg_PWMOut_backup = {0u};

    
/*******************************************************************************
* Function Name: CtrlReg_PWMOut_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void CtrlReg_PWMOut_SaveConfig(void) 
{
    CtrlReg_PWMOut_backup.controlState = CtrlReg_PWMOut_Control;
}


/*******************************************************************************
* Function Name: CtrlReg_PWMOut_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*
*******************************************************************************/
void CtrlReg_PWMOut_RestoreConfig(void) 
{
     CtrlReg_PWMOut_Control = CtrlReg_PWMOut_backup.controlState;
}


/*******************************************************************************
* Function Name: CtrlReg_PWMOut_Sleep
********************************************************************************
*
* Summary:
*  Prepares the component for entering the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void CtrlReg_PWMOut_Sleep(void) 
{
    CtrlReg_PWMOut_SaveConfig();
}


/*******************************************************************************
* Function Name: CtrlReg_PWMOut_Wakeup
********************************************************************************
*
* Summary:
*  Restores the component after waking up from the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void CtrlReg_PWMOut_Wakeup(void)  
{
    CtrlReg_PWMOut_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
