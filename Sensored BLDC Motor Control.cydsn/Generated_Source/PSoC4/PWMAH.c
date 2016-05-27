/*******************************************************************************
* File Name: PWMAH.c  
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
#include "PWMAH.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        PWMAH_PC =   (PWMAH_PC & \
                                (uint32)(~(uint32)(PWMAH_DRIVE_MODE_IND_MASK << (PWMAH_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (PWMAH_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: PWMAH_Write
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
void PWMAH_Write(uint8 value) 
{
    uint8 drVal = (uint8)(PWMAH_DR & (uint8)(~PWMAH_MASK));
    drVal = (drVal | ((uint8)(value << PWMAH_SHIFT) & PWMAH_MASK));
    PWMAH_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: PWMAH_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  PWMAH_DM_STRONG     Strong Drive 
*  PWMAH_DM_OD_HI      Open Drain, Drives High 
*  PWMAH_DM_OD_LO      Open Drain, Drives Low 
*  PWMAH_DM_RES_UP     Resistive Pull Up 
*  PWMAH_DM_RES_DWN    Resistive Pull Down 
*  PWMAH_DM_RES_UPDWN  Resistive Pull Up/Down 
*  PWMAH_DM_DIG_HIZ    High Impedance Digital 
*  PWMAH_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void PWMAH_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(PWMAH__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: PWMAH_Read
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
*  Macro PWMAH_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 PWMAH_Read(void) 
{
    return (uint8)((PWMAH_PS & PWMAH_MASK) >> PWMAH_SHIFT);
}


/*******************************************************************************
* Function Name: PWMAH_ReadDataReg
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
uint8 PWMAH_ReadDataReg(void) 
{
    return (uint8)((PWMAH_DR & PWMAH_MASK) >> PWMAH_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(PWMAH_INTSTAT) 

    /*******************************************************************************
    * Function Name: PWMAH_ClearInterrupt
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
    uint8 PWMAH_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(PWMAH_INTSTAT & PWMAH_MASK);
		PWMAH_INTSTAT = maskedStatus;
        return maskedStatus >> PWMAH_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
