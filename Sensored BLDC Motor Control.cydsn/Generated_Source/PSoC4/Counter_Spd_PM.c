/*******************************************************************************
* File Name: Counter_Spd_PM.c
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

#include "Counter_Spd.h"

static Counter_Spd_BACKUP_STRUCT Counter_Spd_backup;


/*******************************************************************************
* Function Name: Counter_Spd_SaveConfig
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
void Counter_Spd_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: Counter_Spd_Sleep
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
void Counter_Spd_Sleep(void)
{
    if(0u != (Counter_Spd_BLOCK_CONTROL_REG & Counter_Spd_MASK))
    {
        Counter_Spd_backup.enableState = 1u;
    }
    else
    {
        Counter_Spd_backup.enableState = 0u;
    }

    Counter_Spd_Stop();
    Counter_Spd_SaveConfig();
}


/*******************************************************************************
* Function Name: Counter_Spd_RestoreConfig
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
void Counter_Spd_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: Counter_Spd_Wakeup
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
void Counter_Spd_Wakeup(void)
{
    Counter_Spd_RestoreConfig();

    if(0u != Counter_Spd_backup.enableState)
    {
        Counter_Spd_Enable();
    }
}


/* [] END OF FILE */
