/*******************************************************************************
* File Name: PWM_test1_PM.c
* Version 2.0
*
* Description:
*  This file contains the setup, control, and status commands to support
*  the component operations in the low power mode.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2013-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "PWM_test1.h"

static PWM_test1_BACKUP_STRUCT PWM_test1_backup;


/*******************************************************************************
* Function Name: PWM_test1_SaveConfig
********************************************************************************
*
* Summary:
*  All configuration registers are retention. Nothing to save here.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void PWM_test1_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: PWM_test1_Sleep
********************************************************************************
*
* Summary:
*  Stops the component operation and saves the user configuration.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void PWM_test1_Sleep(void)
{
    if(0u != (PWM_test1_BLOCK_CONTROL_REG & PWM_test1_MASK))
    {
        PWM_test1_backup.enableState = 1u;
    }
    else
    {
        PWM_test1_backup.enableState = 0u;
    }

    PWM_test1_Stop();
    PWM_test1_SaveConfig();
}


/*******************************************************************************
* Function Name: PWM_test1_RestoreConfig
********************************************************************************
*
* Summary:
*  All configuration registers are retention. Nothing to restore here.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void PWM_test1_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: PWM_test1_Wakeup
********************************************************************************
*
* Summary:
*  Restores the user configuration and restores the enable state.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void PWM_test1_Wakeup(void)
{
    PWM_test1_RestoreConfig();

    if(0u != PWM_test1_backup.enableState)
    {
        PWM_test1_Enable();
    }
}


/* [] END OF FILE */
