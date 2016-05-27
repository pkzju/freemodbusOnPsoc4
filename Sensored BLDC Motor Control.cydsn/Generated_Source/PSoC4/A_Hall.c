/*******************************************************************************
* File Name: A_Hall.c  
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
#include "A_Hall.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        A_Hall_PC =   (A_Hall_PC & \
                                (uint32)(~(uint32)(A_Hall_DRIVE_MODE_IND_MASK << (A_Hall_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (A_Hall_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: A_Hall_Write
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
void A_Hall_Write(uint8 value) 
{
    uint8 drVal = (uint8)(A_Hall_DR & (uint8)(~A_Hall_MASK));
    drVal = (drVal | ((uint8)(value << A_Hall_SHIFT) & A_Hall_MASK));
    A_Hall_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: A_Hall_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  A_Hall_DM_STRONG     Strong Drive 
*  A_Hall_DM_OD_HI      Open Drain, Drives High 
*  A_Hall_DM_OD_LO      Open Drain, Drives Low 
*  A_Hall_DM_RES_UP     Resistive Pull Up 
*  A_Hall_DM_RES_DWN    Resistive Pull Down 
*  A_Hall_DM_RES_UPDWN  Resistive Pull Up/Down 
*  A_Hall_DM_DIG_HIZ    High Impedance Digital 
*  A_Hall_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void A_Hall_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(A_Hall__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: A_Hall_Read
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
*  Macro A_Hall_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 A_Hall_Read(void) 
{
    return (uint8)((A_Hall_PS & A_Hall_MASK) >> A_Hall_SHIFT);
}


/*******************************************************************************
* Function Name: A_Hall_ReadDataReg
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
uint8 A_Hall_ReadDataReg(void) 
{
    return (uint8)((A_Hall_DR & A_Hall_MASK) >> A_Hall_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(A_Hall_INTSTAT) 

    /*******************************************************************************
    * Function Name: A_Hall_ClearInterrupt
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
    uint8 A_Hall_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(A_Hall_INTSTAT & A_Hall_MASK);
		A_Hall_INTSTAT = maskedStatus;
        return maskedStatus >> A_Hall_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
