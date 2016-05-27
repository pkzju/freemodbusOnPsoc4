/*******************************************************************************
* File Name: Relay.c  
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
#include "Relay.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        Relay_PC =   (Relay_PC & \
                                (uint32)(~(uint32)(Relay_DRIVE_MODE_IND_MASK << (Relay_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (Relay_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: Relay_Write
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
void Relay_Write(uint8 value) 
{
    uint8 drVal = (uint8)(Relay_DR & (uint8)(~Relay_MASK));
    drVal = (drVal | ((uint8)(value << Relay_SHIFT) & Relay_MASK));
    Relay_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: Relay_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  Relay_DM_STRONG     Strong Drive 
*  Relay_DM_OD_HI      Open Drain, Drives High 
*  Relay_DM_OD_LO      Open Drain, Drives Low 
*  Relay_DM_RES_UP     Resistive Pull Up 
*  Relay_DM_RES_DWN    Resistive Pull Down 
*  Relay_DM_RES_UPDWN  Resistive Pull Up/Down 
*  Relay_DM_DIG_HIZ    High Impedance Digital 
*  Relay_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void Relay_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(Relay__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: Relay_Read
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
*  Macro Relay_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Relay_Read(void) 
{
    return (uint8)((Relay_PS & Relay_MASK) >> Relay_SHIFT);
}


/*******************************************************************************
* Function Name: Relay_ReadDataReg
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
uint8 Relay_ReadDataReg(void) 
{
    return (uint8)((Relay_DR & Relay_MASK) >> Relay_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Relay_INTSTAT) 

    /*******************************************************************************
    * Function Name: Relay_ClearInterrupt
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
    uint8 Relay_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(Relay_INTSTAT & Relay_MASK);
		Relay_INTSTAT = maskedStatus;
        return maskedStatus >> Relay_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
