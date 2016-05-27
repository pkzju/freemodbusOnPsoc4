/*******************************************************************************
* File Name: IDAC_Iref.c
* Version 1.10
*
* Description:
*  This file provides the source code of APIs for the IDAC_P4 component.
*
*******************************************************************************
* Copyright 2013-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "IDAC_Iref.h"

uint32 IDAC_Iref_initVar = 0u;


/*******************************************************************************
* Function Name: IDAC_Iref_Init
********************************************************************************
*
* Summary:
*  Initializes IDAC registers with initial values provided from customizer.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  None
*
*******************************************************************************/
void IDAC_Iref_Init(void)
{
    uint32 regVal;
    uint8 enableInterrupts;

    /* Set initial configuration */
    enableInterrupts = CyEnterCriticalSection();
    
    #if(IDAC_Iref_MODE_SOURCE == IDAC_Iref_IDAC_POLARITY)
        regVal  = IDAC_Iref_CSD_TRIM1_REG & ~(IDAC_Iref_CSD_IDAC_TRIM1_MASK);
        regVal |=  (IDAC_Iref_SFLASH_TRIM1_REG & IDAC_Iref_CSD_IDAC_TRIM1_MASK);
        IDAC_Iref_CSD_TRIM1_REG = regVal;
    #else
        regVal  = IDAC_Iref_CSD_TRIM2_REG & ~(IDAC_Iref_CSD_IDAC_TRIM2_MASK);
        regVal |=  (IDAC_Iref_SFLASH_TRIM2_REG & IDAC_Iref_CSD_IDAC_TRIM2_MASK);
        IDAC_Iref_CSD_TRIM2_REG = regVal;
    #endif /* (IDAC_Iref_MODE_SOURCE == IDAC_Iref_IDAC_POLARITY) */

    /* clear previous values */
    IDAC_Iref_IDAC_CONTROL_REG &= ((uint32)~((uint32)IDAC_Iref_IDAC_VALUE_MASK <<
        IDAC_Iref_IDAC_VALUE_POSITION)) | ((uint32)~((uint32)IDAC_Iref_IDAC_MODE_MASK <<
        IDAC_Iref_IDAC_MODE_POSITION))  | ((uint32)~((uint32)IDAC_Iref_IDAC_RANGE_MASK  <<
        IDAC_Iref_IDAC_RANGE_POSITION));

    IDAC_Iref_IDAC_POLARITY_CONTROL_REG &= (~(uint32)((uint32)IDAC_Iref_IDAC_POLARITY_MASK <<
        IDAC_Iref_IDAC_POLARITY_POSITION));

    /* set new configuration */
    IDAC_Iref_IDAC_CONTROL_REG |= (((uint32)IDAC_Iref_IDAC_INIT_VALUE <<
        IDAC_Iref_IDAC_VALUE_POSITION) | ((uint32)IDAC_Iref_IDAC_RANGE <<
        IDAC_Iref_IDAC_RANGE_POSITION));

    IDAC_Iref_IDAC_POLARITY_CONTROL_REG |= ((uint32)IDAC_Iref_IDAC_POLARITY <<
                                                           IDAC_Iref_IDAC_POLARITY_POSITION);

    CyExitCriticalSection(enableInterrupts);

}


/*******************************************************************************
* Function Name: IDAC_Iref_Enable
********************************************************************************
*
* Summary:
*  Enables IDAC operations.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  None
*
*******************************************************************************/
void IDAC_Iref_Enable(void)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    /* Enable the IDAC */
    IDAC_Iref_IDAC_CONTROL_REG |= ((uint32)IDAC_Iref_IDAC_EN_MODE <<
                                                  IDAC_Iref_IDAC_MODE_POSITION);
    IDAC_Iref_IDAC_POLARITY_CONTROL_REG |= ((uint32)IDAC_Iref_IDAC_CSD_EN <<
                                                           IDAC_Iref_IDAC_CSD_EN_POSITION);
    CyExitCriticalSection(enableInterrupts);

}


/*******************************************************************************
* Function Name: IDAC_Iref_Start
********************************************************************************
*
* Summary:
*  Starts the IDAC hardware.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  IDAC_Iref_initVar
*
*******************************************************************************/
void IDAC_Iref_Start(void)
{
    if(0u == IDAC_Iref_initVar)
    {
        IDAC_Iref_Init();
        IDAC_Iref_initVar = 1u;
    }

    IDAC_Iref_Enable();

}


/*******************************************************************************
* Function Name: IDAC_Iref_Stop
********************************************************************************
*
* Summary:
*  Stops the IDAC hardware.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  None
*
*******************************************************************************/
void IDAC_Iref_Stop(void)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    /* Disable the IDAC */
    IDAC_Iref_IDAC_CONTROL_REG &= ((uint32)~((uint32)IDAC_Iref_IDAC_MODE_MASK <<
        IDAC_Iref_IDAC_MODE_POSITION));
    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: IDAC_Iref_SetValue
********************************************************************************
*
* Summary:
*  Sets the IDAC value.
*
* Parameters:
*  uint32 value
*
* Return:
*  None
*
* Global variables:
*  None
*
*******************************************************************************/
void IDAC_Iref_SetValue(uint32 value)
{
    uint8 enableInterrupts;
    uint32 newRegisterValue;

    enableInterrupts = CyEnterCriticalSection();

    #if(IDAC_Iref_IDAC_VALUE_POSITION != 0u)
        newRegisterValue = ((IDAC_Iref_IDAC_CONTROL_REG & (~(uint32)((uint32)IDAC_Iref_IDAC_VALUE_MASK <<
        IDAC_Iref_IDAC_VALUE_POSITION))) | (value << IDAC_Iref_IDAC_VALUE_POSITION));
    #else
        newRegisterValue = ((IDAC_Iref_IDAC_CONTROL_REG & (~(uint32)IDAC_Iref_IDAC_VALUE_MASK)) | value);
    #endif /* IDAC_Iref_IDAC_VALUE_POSITION != 0u */

    IDAC_Iref_IDAC_CONTROL_REG = newRegisterValue;

    CyExitCriticalSection(enableInterrupts);
}

/* [] END OF FILE */
