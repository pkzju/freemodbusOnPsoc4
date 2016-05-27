/*******************************************************************************
* File Name: VSP.c  
* Version 2.10
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "VSP.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        VSP_PC =   (VSP_PC & \
                                (uint32)(~(uint32)(VSP_DRIVE_MODE_IND_MASK << (VSP_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (VSP_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: VSP_Write
********************************************************************************
*
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  None 
*  
*******************************************************************************/
void VSP_Write(uint8 value) 
{
    uint8 drVal = (uint8)(VSP_DR & (uint8)(~VSP_MASK));
    drVal = (drVal | ((uint8)(value << VSP_SHIFT) & VSP_MASK));
    VSP_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: VSP_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  VSP_DM_STRONG     Strong Drive 
*  VSP_DM_OD_HI      Open Drain, Drives High 
*  VSP_DM_OD_LO      Open Drain, Drives Low 
*  VSP_DM_RES_UP     Resistive Pull Up 
*  VSP_DM_RES_DWN    Resistive Pull Down 
*  VSP_DM_RES_UPDWN  Resistive Pull Up/Down 
*  VSP_DM_DIG_HIZ    High Impedance Digital 
*  VSP_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void VSP_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(VSP__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: VSP_Read
********************************************************************************
*
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro VSP_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 VSP_Read(void) 
{
    return (uint8)((VSP_PS & VSP_MASK) >> VSP_SHIFT);
}


/*******************************************************************************
* Function Name: VSP_ReadDataReg
********************************************************************************
*
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 VSP_ReadDataReg(void) 
{
    return (uint8)((VSP_DR & VSP_MASK) >> VSP_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(VSP_INTSTAT) 

    /*******************************************************************************
    * Function Name: VSP_ClearInterrupt
    ********************************************************************************
    *
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  None 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 VSP_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(VSP_INTSTAT & VSP_MASK);
		VSP_INTSTAT = maskedStatus;
        return maskedStatus >> VSP_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
