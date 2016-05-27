/*******************************************************************************
* File Name: PWM_DAC1_PM.c
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

#include "PWM_DAC1.h"

static PWM_DAC1_BACKUP_STRUCT PWM_DAC1_backup;


/*******************************************************************************
* Function Name: PWM_DAC1_SaveConfig
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
void PWM_DAC1_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: PWM_DAC1_Sleep
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
void PWM_DAC1_Sleep(void)
{
    if(0u != (PWM_DAC1_BLOCK_CONTROL_REG & PWM_DAC1_MASK))
    {
        PWM_DAC1_backup.enableState = 1u;
    }
    else
    {
        PWM_DAC1_backup.enableState = 0u;
    }

    PWM_DAC1_Stop();
    PWM_DAC1_SaveConfig();
}


/*******************************************************************************
* Function Name: PWM_DAC1_RestoreConfig
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
void PWM_DAC1_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: PWM_DAC1_Wakeup
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
void PWM_DAC1_Wakeup(void)
{
    PWM_DAC1_RestoreConfig();

    if(0u != PWM_DAC1_backup.enableState)
    {
        PWM_DAC1_Enable();
    }
}


/* [] END OF FILE */
