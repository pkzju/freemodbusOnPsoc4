/*******************************************************************************
* File Name: Hall_Comp_PM.c
* Version 1.10
*
* Description:
*  This file provides the power management source code APIs for the
*  Comparator.
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

#include "Hall_Comp.h"

#if(!Hall_Comp_CHECK_DEEPSLEEP_SUPPORT)
    static Hall_Comp_BACKUP_STRUCT Hall_Comp_backup =
    {
        0u, /* enableState */
    };
#endif /* (Hall_Comp_CHECK_DEEPSLEEP_SUPPORT) */


/*******************************************************************************
* Function Name: Hall_Comp_SaveConfig
********************************************************************************
*
* Summary:
*  Empty function. Included for consistency with other components.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Hall_Comp_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: Hall_Comp_RestoreConfig
********************************************************************************
*
* Summary:
*  Empty function. Included for consistency with other components.
*
* Parameters:
*  None
*
* Return:
*  None
*
********************************************************************************/
void Hall_Comp_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: Hall_Comp_Sleep
********************************************************************************
*
* Summary:
*  This is the preferred API to prepare the component for sleep. The Sleep() API 
*  saves the current component state. Call the Comp_Sleep() function before 
*  calling the CySysPmDeepSleep() or the CySysPmHibernate() functions.
*  The "Deep sleep operation" option has an influence on this function
*  implementation.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Hall_Comp_Sleep(void)
{
#if(!Hall_Comp_CHECK_DEEPSLEEP_SUPPORT)
    if(Hall_Comp_CHECK_PWR_MODE_OFF)
    {
        Hall_Comp_backup.enableState = 1u;
        Hall_Comp_Stop();
    }
    else /* Component is disabled */
    {
        Hall_Comp_backup.enableState = 0u;
    }
#endif /* (Hall_Comp_CHECK_DEEPSLEEP_SUPPORT) */
}


/*******************************************************************************
* Function Name: Hall_Comp_Wakeup
********************************************************************************
*
* Summary:
*  This is the preferred API to restore the component to the state when Sleep() 
*  was called. The Wakeup() function will also re-enable the component. 
*  The "Deep sleep operation" option has an influence on this function
*  implementation.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Hall_Comp_Wakeup(void)
{
#if(!Hall_Comp_CHECK_DEEPSLEEP_SUPPORT)
    if(0u != Hall_Comp_backup.enableState)
    {
        /* Enable Comp's operation */
        Hall_Comp_Enable();
    } /* Do nothing if Comp was disabled before */
#endif /* (Hall_Comp_CHECK_DEEPSLEEP_SUPPORT) */
}


/* [] END OF FILE */

