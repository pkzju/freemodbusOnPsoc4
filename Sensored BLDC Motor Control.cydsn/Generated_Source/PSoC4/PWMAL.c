/*******************************************************************************
* File Name: PWMAL.c  
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
#include "PWMAL.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        PWMAL_PC =   (PWMAL_PC & \
                                (uint32)(~(uint32)(PWMAL_DRIVE_MODE_IND_MASK << (PWMAL_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (PWMAL_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: PWMAL_Write
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
void PWMAL_Write(uint8 value) 
{
    uint8 drVal = (uint8)(PWMAL_DR & (uint8)(~PWMAL_MASK));
    drVal = (drVal | ((uint8)(value << PWMAL_SHIFT) & PWMAL_MASK));
    PWMAL_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: PWMAL_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  PWMAL_DM_STRONG     Strong Drive 
*  PWMAL_DM_OD_HI      Open Drain, Drives High 
*  PWMAL_DM_OD_LO      Open Drain, Drives Low 
*  PWMAL_DM_RES_UP     Resistive Pull Up 
*  PWMAL_DM_RES_DWN    Resistive Pull Down 
*  PWMAL_DM_RES_UPDWN  Resistive Pull Up/Down 
*  PWMAL_DM_DIG_HIZ    High Impedance Digital 
*  PWMAL_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void PWMAL_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(PWMAL__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: PWMAL_Read
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
*  Macro PWMAL_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 PWMAL_Read(void) 
{
    return (uint8)((PWMAL_PS & PWMAL_MASK) >> PWMAL_SHIFT);
}


/*******************************************************************************
* Function Name: PWMAL_ReadDataReg
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
uint8 PWMAL_ReadDataReg(void) 
{
    return (uint8)((PWMAL_DR & PWMAL_MASK) >> PWMAL_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(PWMAL_INTSTAT) 

    /*******************************************************************************
    * Function Name: PWMAL_ClearInterrupt
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
    uint8 PWMAL_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(PWMAL_INTSTAT & PWMAL_MASK);
		PWMAL_INTSTAT = maskedStatus;
        return maskedStatus >> PWMAL_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
