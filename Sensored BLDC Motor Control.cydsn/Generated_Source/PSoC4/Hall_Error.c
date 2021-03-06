/*******************************************************************************
* File Name: Hall_Error.c  
* Version 1.90
*
* Description:
*  This file contains API to enable firmware to read the value of a Status 
*  Register.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "Hall_Error.h"

#if !defined(Hall_Error_sts_sts_reg__REMOVED) /* Check for removal by optimization */


/*******************************************************************************
* Function Name: Hall_Error_Read
********************************************************************************
*
* Summary:
*  Reads the current value assigned to the Status Register.
*
* Parameters:
*  None.
*
* Return:
*  The current value in the Status Register.
*
*******************************************************************************/
uint8 Hall_Error_Read(void) 
{ 
    return Hall_Error_Status;
}


/*******************************************************************************
* Function Name: Hall_Error_InterruptEnable
********************************************************************************
*
* Summary:
*  Enables the Status Register interrupt.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void Hall_Error_InterruptEnable(void) 
{
    uint8 interruptState;
    interruptState = CyEnterCriticalSection();
    Hall_Error_Status_Aux_Ctrl |= Hall_Error_STATUS_INTR_ENBL;
    CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: Hall_Error_InterruptDisable
********************************************************************************
*
* Summary:
*  Disables the Status Register interrupt.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void Hall_Error_InterruptDisable(void) 
{
    uint8 interruptState;
    interruptState = CyEnterCriticalSection();
    Hall_Error_Status_Aux_Ctrl &= (uint8)(~Hall_Error_STATUS_INTR_ENBL);
    CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: Hall_Error_WriteMask
********************************************************************************
*
* Summary:
*  Writes the current mask value assigned to the Status Register.
*
* Parameters:
*  mask:  Value to write into the mask register.
*
* Return:
*  None.
*
*******************************************************************************/
void Hall_Error_WriteMask(uint8 mask) 
{
    #if(Hall_Error_INPUTS < 8u)
    	mask &= ((uint8)(1u << Hall_Error_INPUTS) - 1u);
	#endif /* End Hall_Error_INPUTS < 8u */
    Hall_Error_Status_Mask = mask;
}


/*******************************************************************************
* Function Name: Hall_Error_ReadMask
********************************************************************************
*
* Summary:
*  Reads the current interrupt mask assigned to the Status Register.
*
* Parameters:
*  None.
*
* Return:
*  The value of the interrupt mask of the Status Register.
*
*******************************************************************************/
uint8 Hall_Error_ReadMask(void) 
{
    return Hall_Error_Status_Mask;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
