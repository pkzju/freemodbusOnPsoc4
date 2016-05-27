/*******************************************************************************
* File Name: Opamp_B.c
* Version 1.10
*
* Description:
*  This file provides the source code to the API for the Opamp (Analog Buffer)
*  Component.
*
*
********************************************************************************
* Copyright 2013-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "Opamp_B.h"

uint8 Opamp_B_initVar = 0u; /* Defines if component was initialized */
static uint32 Opamp_B_internalPower = 0u; /* Defines component Power value */


/*******************************************************************************
* Function Name: Opamp_B_Init
********************************************************************************
*
* Summary:
*  Initializes or restores the component according to the customizer Configure 
*  dialog settings. It is not necessary to call Init() because the Start() API 
*  calls this function and is the preferred method to begin the component operation.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Opamp_B_Init(void)
{
    Opamp_B_internalPower = Opamp_B_POWER;
    Opamp_B_CTB_CTRL_REG = Opamp_B_DEFAULT_CTB_CTRL;
    Opamp_B_OA_RES_CTRL_REG = Opamp_B_DEFAULT_OA_RES_CTRL;
    Opamp_B_OA_COMP_TRIM_REG = Opamp_B_DEFAULT_OA_COMP_TRIM_REG;
}


/*******************************************************************************
* Function Name: Opamp_B_Enable
********************************************************************************
*
* Summary:
*  Activates the hardware and begins the component operation. It is not necessary to 
*  call Enable() because the Start() API calls this function, which is the 
*  preferred method to begin the component operation.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Opamp_B_Enable(void)
{
    Opamp_B_OA_RES_CTRL_REG |= Opamp_B_internalPower | \
                                        Opamp_B_OA_PUMP_EN;
}


/*******************************************************************************
* Function Name: Opamp_B_Start
********************************************************************************
*
* Summary:
*  Performs all of the required initialization for the component and enables power 
*  to the block. The first time the routine is executed, the Power level, Mode, 
*  and Output mode are set. When called to restart the Opamp following a Stop() call, 
*  the current component parameter settings are retained.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  Opamp_B_initVar: Used to check the initial configuration, modified
*  when this function is called for the first time.
*
*******************************************************************************/
void Opamp_B_Start(void)
{
    if( 0u == Opamp_B_initVar)
    {
        Opamp_B_Init();
        Opamp_B_initVar = 1u;
    }
    Opamp_B_Enable();
}


/*******************************************************************************
* Function Name: Opamp_B_Stop
********************************************************************************
*
* Summary:
*  Turn off the Opamp block.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Opamp_B_Stop(void)
{
    Opamp_B_OA_RES_CTRL_REG &= ((uint32)~(Opamp_B_OA_PWR_MODE_MASK | \
                                                   Opamp_B_OA_PUMP_EN));
}


/*******************************************************************************
* Function Name: Opamp_B_SetPower
********************************************************************************
*
* Summary:
*  Sets the Opamp to one of the three power levels.
*
* Parameters:
*  power: power levels.
*   Opamp_B_LOW_POWER - Lowest active power
*   Opamp_B_MED_POWER - Medium power
*   Opamp_B_HIGH_POWER - Highest active power
*
* Return:
*  None
*
**********************************************************************************/
void Opamp_B_SetPower(uint32 power)
{
    uint32 tmp;
    
    Opamp_B_internalPower = Opamp_B_GET_OA_PWR_MODE(power);
    tmp = Opamp_B_OA_RES_CTRL_REG & \
           (uint32)~Opamp_B_OA_PWR_MODE_MASK;
    Opamp_B_OA_RES_CTRL_REG = tmp | Opamp_B_internalPower;
}


/*******************************************************************************
* Function Name: Opamp_B_PumpControl
********************************************************************************
*
* Summary:
*  Allows the user to turn the Opamp's boost pump on or off. By Default the Start() 
*  function turns on the pump. Use this API to turn it off. The boost must be 
*  turned on when the supply is less than 2.7 volts and off if the supply is more 
*  than 4 volts.
*
* Parameters:
*  onOff: Control the pump.
*   Opamp_B_PUMP_OFF - Turn off the pump
*   Opamp_B_PUMP_ON - Turn on the pump
*
* Return:
*  None
*
**********************************************************************************/
void Opamp_B_PumpControl(uint32 onOff)
{
    
    if(0u != onOff)
    {
        Opamp_B_OA_RES_CTRL |= Opamp_B_OA_PUMP_EN;    
    }
    else
    {
        Opamp_B_OA_RES_CTRL &= (uint32)~Opamp_B_OA_PUMP_EN;
    }
}


/* [] END OF FILE */
