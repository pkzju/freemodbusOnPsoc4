/*******************************************************************************
* File Name: PWM_Drive_PM.c
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

#include "PWM_Drive.h"

static PWM_Drive_BACKUP_STRUCT PWM_Drive_backup;


/*******************************************************************************
* Function Name: PWM_Drive_SaveConfig
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
void PWM_Drive_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: PWM_Drive_Sleep
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
void PWM_Drive_Sleep(void)
{
    if(0u != (PWM_Drive_BLOCK_CONTROL_REG & PWM_Drive_MASK))
    {
        PWM_Drive_backup.enableState = 1u;
    }
    else
    {
        PWM_Drive_backup.enableState = 0u;
    }

    PWM_Drive_Stop();
    PWM_Drive_SaveConfig();
}


/*******************************************************************************
* Function Name: PWM_Drive_RestoreConfig
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
void PWM_Drive_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: PWM_Drive_Wakeup
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
void PWM_Drive_Wakeup(void)
{
    PWM_Drive_RestoreConfig();

    if(0u != PWM_Drive_backup.enableState)
    {
        PWM_Drive_Enable();
    }
}


/* [] END OF FILE */
