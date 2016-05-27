/*******************************************************************************
* File Name: Hall_ref.c  
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
#include "Hall_ref.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        Hall_ref_PC =   (Hall_ref_PC & \
                                (uint32)(~(uint32)(Hall_ref_DRIVE_MODE_IND_MASK << (Hall_ref_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (Hall_ref_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: Hall_ref_Write
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
void Hall_ref_Write(uint8 value) 
{
    uint8 drVal = (uint8)(Hall_ref_DR & (uint8)(~Hall_ref_MASK));
    drVal = (drVal | ((uint8)(value << Hall_ref_SHIFT) & Hall_ref_MASK));
    Hall_ref_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: Hall_ref_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  Hall_ref_DM_STRONG     Strong Drive 
*  Hall_ref_DM_OD_HI      Open Drain, Drives High 
*  Hall_ref_DM_OD_LO      Open Drain, Drives Low 
*  Hall_ref_DM_RES_UP     Resistive Pull Up 
*  Hall_ref_DM_RES_DWN    Resistive Pull Down 
*  Hall_ref_DM_RES_UPDWN  Resistive Pull Up/Down 
*  Hall_ref_DM_DIG_HIZ    High Impedance Digital 
*  Hall_ref_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void Hall_ref_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(Hall_ref__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: Hall_ref_Read
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
*  Macro Hall_ref_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Hall_ref_Read(void) 
{
    return (uint8)((Hall_ref_PS & Hall_ref_MASK) >> Hall_ref_SHIFT);
}


/*******************************************************************************
* Function Name: Hall_ref_ReadDataReg
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
uint8 Hall_ref_ReadDataReg(void) 
{
    return (uint8)((Hall_ref_DR & Hall_ref_MASK) >> Hall_ref_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Hall_ref_INTSTAT) 

    /*******************************************************************************
    * Function Name: Hall_ref_ClearInterrupt
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
    uint8 Hall_ref_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(Hall_ref_INTSTAT & Hall_ref_MASK);
		Hall_ref_INTSTAT = maskedStatus;
        return maskedStatus >> Hall_ref_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
