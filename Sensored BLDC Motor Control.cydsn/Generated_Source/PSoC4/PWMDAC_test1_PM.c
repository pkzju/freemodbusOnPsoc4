/*******************************************************************************
* File Name: PWMDAC_test1_PM.c
* Version 3.30
*
* Description:
*  This file provides the power management source code to API for the
*  PWM.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "PWMDAC_test1.h"

static PWMDAC_test1_backupStruct PWMDAC_test1_backup;


/*******************************************************************************
* Function Name: PWMDAC_test1_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the current user configuration of the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWMDAC_test1_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void PWMDAC_test1_SaveConfig(void) 
{

    #if(!PWMDAC_test1_UsingFixedFunction)
        #if(!PWMDAC_test1_PWMModeIsCenterAligned)
            PWMDAC_test1_backup.PWMPeriod = PWMDAC_test1_ReadPeriod();
        #endif /* (!PWMDAC_test1_PWMModeIsCenterAligned) */
        PWMDAC_test1_backup.PWMUdb = PWMDAC_test1_ReadCounter();
        #if (PWMDAC_test1_UseStatus)
            PWMDAC_test1_backup.InterruptMaskValue = PWMDAC_test1_STATUS_MASK;
        #endif /* (PWMDAC_test1_UseStatus) */

        #if(PWMDAC_test1_DeadBandMode == PWMDAC_test1__B_PWM__DBM_256_CLOCKS || \
            PWMDAC_test1_DeadBandMode == PWMDAC_test1__B_PWM__DBM_2_4_CLOCKS)
            PWMDAC_test1_backup.PWMdeadBandValue = PWMDAC_test1_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(PWMDAC_test1_KillModeMinTime)
             PWMDAC_test1_backup.PWMKillCounterPeriod = PWMDAC_test1_ReadKillTime();
        #endif /* (PWMDAC_test1_KillModeMinTime) */

        #if(PWMDAC_test1_UseControl)
            PWMDAC_test1_backup.PWMControlRegister = PWMDAC_test1_ReadControlRegister();
        #endif /* (PWMDAC_test1_UseControl) */
    #endif  /* (!PWMDAC_test1_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: PWMDAC_test1_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration of the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWMDAC_test1_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void PWMDAC_test1_RestoreConfig(void) 
{
        #if(!PWMDAC_test1_UsingFixedFunction)
            #if(!PWMDAC_test1_PWMModeIsCenterAligned)
                PWMDAC_test1_WritePeriod(PWMDAC_test1_backup.PWMPeriod);
            #endif /* (!PWMDAC_test1_PWMModeIsCenterAligned) */

            PWMDAC_test1_WriteCounter(PWMDAC_test1_backup.PWMUdb);

            #if (PWMDAC_test1_UseStatus)
                PWMDAC_test1_STATUS_MASK = PWMDAC_test1_backup.InterruptMaskValue;
            #endif /* (PWMDAC_test1_UseStatus) */

            #if(PWMDAC_test1_DeadBandMode == PWMDAC_test1__B_PWM__DBM_256_CLOCKS || \
                PWMDAC_test1_DeadBandMode == PWMDAC_test1__B_PWM__DBM_2_4_CLOCKS)
                PWMDAC_test1_WriteDeadTime(PWMDAC_test1_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(PWMDAC_test1_KillModeMinTime)
                PWMDAC_test1_WriteKillTime(PWMDAC_test1_backup.PWMKillCounterPeriod);
            #endif /* (PWMDAC_test1_KillModeMinTime) */

            #if(PWMDAC_test1_UseControl)
                PWMDAC_test1_WriteControlRegister(PWMDAC_test1_backup.PWMControlRegister);
            #endif /* (PWMDAC_test1_UseControl) */
        #endif  /* (!PWMDAC_test1_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: PWMDAC_test1_Sleep
********************************************************************************
*
* Summary:
*  Disables block's operation and saves the user configuration. Should be called
*  just prior to entering sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWMDAC_test1_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void PWMDAC_test1_Sleep(void) 
{
    #if(PWMDAC_test1_UseControl)
        if(PWMDAC_test1_CTRL_ENABLE == (PWMDAC_test1_CONTROL & PWMDAC_test1_CTRL_ENABLE))
        {
            /*Component is enabled */
            PWMDAC_test1_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            PWMDAC_test1_backup.PWMEnableState = 0u;
        }
    #endif /* (PWMDAC_test1_UseControl) */

    /* Stop component */
    PWMDAC_test1_Stop();

    /* Save registers configuration */
    PWMDAC_test1_SaveConfig();
}


/*******************************************************************************
* Function Name: PWMDAC_test1_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration. Should be called just after
*  awaking from sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWMDAC_test1_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void PWMDAC_test1_Wakeup(void) 
{
     /* Restore registers values */
    PWMDAC_test1_RestoreConfig();

    if(PWMDAC_test1_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        PWMDAC_test1_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
