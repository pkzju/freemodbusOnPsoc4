/*******************************************************************************
* File Name: PWMCH.c  
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
#include "PWMCH.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        PWMCH_PC =   (PWMCH_PC & \
                                (uint32)(~(uint32)(PWMCH_DRIVE_MODE_IND_MASK << (PWMCH_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (PWMCH_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: PWMCH_Write
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
void PWMCH_Write(uint8 value) 
{
    uint8 drVal = (uint8)(PWMCH_DR & (uint8)(~PWMCH_MASK));
    drVal = (drVal | ((uint8)(value << PWMCH_SHIFT) & PWMCH_MASK));
    PWMCH_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: PWMCH_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  PWMCH_DM_STRONG     Strong Drive 
*  PWMCH_DM_OD_HI      Open Drain, Drives High 
*  PWMCH_DM_OD_LO      Open Drain, Drives Low 
*  PWMCH_DM_RES_UP     Resistive Pull Up 
*  PWMCH_DM_RES_DWN    Resistive Pull Down 
*  PWMCH_DM_RES_UPDWN  Resistive Pull Up/Down 
*  PWMCH_DM_DIG_HIZ    High Impedance Digital 
*  PWMCH_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void PWMCH_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(PWMCH__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: PWMCH_Read
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
*  Macro PWMCH_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 PWMCH_Read(void) 
{
    return (uint8)((PWMCH_PS & PWMCH_MASK) >> PWMCH_SHIFT);
}


/*******************************************************************************
* Function Name: PWMCH_ReadDataReg
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
uint8 PWMCH_ReadDataReg(void) 
{
    return (uint8)((PWMCH_DR & PWMCH_MASK) >> PWMCH_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(PWMCH_INTSTAT) 

    /*******************************************************************************
    * Function Name: PWMCH_ClearInterrupt
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
    uint8 PWMCH_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(PWMCH_INTSTAT & PWMCH_MASK);
		PWMCH_INTSTAT = maskedStatus;
        return maskedStatus >> PWMCH_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
