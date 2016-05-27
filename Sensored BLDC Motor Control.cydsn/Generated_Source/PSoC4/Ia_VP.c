/*******************************************************************************
* File Name: Ia_VP.c  
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
#include "Ia_VP.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        Ia_VP_PC =   (Ia_VP_PC & \
                                (uint32)(~(uint32)(Ia_VP_DRIVE_MODE_IND_MASK << (Ia_VP_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (Ia_VP_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: Ia_VP_Write
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
void Ia_VP_Write(uint8 value) 
{
    uint8 drVal = (uint8)(Ia_VP_DR & (uint8)(~Ia_VP_MASK));
    drVal = (drVal | ((uint8)(value << Ia_VP_SHIFT) & Ia_VP_MASK));
    Ia_VP_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: Ia_VP_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  Ia_VP_DM_STRONG     Strong Drive 
*  Ia_VP_DM_OD_HI      Open Drain, Drives High 
*  Ia_VP_DM_OD_LO      Open Drain, Drives Low 
*  Ia_VP_DM_RES_UP     Resistive Pull Up 
*  Ia_VP_DM_RES_DWN    Resistive Pull Down 
*  Ia_VP_DM_RES_UPDWN  Resistive Pull Up/Down 
*  Ia_VP_DM_DIG_HIZ    High Impedance Digital 
*  Ia_VP_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void Ia_VP_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(Ia_VP__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: Ia_VP_Read
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
*  Macro Ia_VP_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Ia_VP_Read(void) 
{
    return (uint8)((Ia_VP_PS & Ia_VP_MASK) >> Ia_VP_SHIFT);
}


/*******************************************************************************
* Function Name: Ia_VP_ReadDataReg
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
uint8 Ia_VP_ReadDataReg(void) 
{
    return (uint8)((Ia_VP_DR & Ia_VP_MASK) >> Ia_VP_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Ia_VP_INTSTAT) 

    /*******************************************************************************
    * Function Name: Ia_VP_ClearInterrupt
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
    uint8 Ia_VP_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(Ia_VP_INTSTAT & Ia_VP_MASK);
		Ia_VP_INTSTAT = maskedStatus;
        return maskedStatus >> Ia_VP_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
