/*******************************************************************************
* File Name: Ia_VN.c  
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
#include "Ia_VN.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        Ia_VN_PC =   (Ia_VN_PC & \
                                (uint32)(~(uint32)(Ia_VN_DRIVE_MODE_IND_MASK << (Ia_VN_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (Ia_VN_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: Ia_VN_Write
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
void Ia_VN_Write(uint8 value) 
{
    uint8 drVal = (uint8)(Ia_VN_DR & (uint8)(~Ia_VN_MASK));
    drVal = (drVal | ((uint8)(value << Ia_VN_SHIFT) & Ia_VN_MASK));
    Ia_VN_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: Ia_VN_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  Ia_VN_DM_STRONG     Strong Drive 
*  Ia_VN_DM_OD_HI      Open Drain, Drives High 
*  Ia_VN_DM_OD_LO      Open Drain, Drives Low 
*  Ia_VN_DM_RES_UP     Resistive Pull Up 
*  Ia_VN_DM_RES_DWN    Resistive Pull Down 
*  Ia_VN_DM_RES_UPDWN  Resistive Pull Up/Down 
*  Ia_VN_DM_DIG_HIZ    High Impedance Digital 
*  Ia_VN_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void Ia_VN_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(Ia_VN__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: Ia_VN_Read
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
*  Macro Ia_VN_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Ia_VN_Read(void) 
{
    return (uint8)((Ia_VN_PS & Ia_VN_MASK) >> Ia_VN_SHIFT);
}


/*******************************************************************************
* Function Name: Ia_VN_ReadDataReg
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
uint8 Ia_VN_ReadDataReg(void) 
{
    return (uint8)((Ia_VN_DR & Ia_VN_MASK) >> Ia_VN_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Ia_VN_INTSTAT) 

    /*******************************************************************************
    * Function Name: Ia_VN_ClearInterrupt
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
    uint8 Ia_VN_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(Ia_VN_INTSTAT & Ia_VN_MASK);
		Ia_VN_INTSTAT = maskedStatus;
        return maskedStatus >> Ia_VN_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
