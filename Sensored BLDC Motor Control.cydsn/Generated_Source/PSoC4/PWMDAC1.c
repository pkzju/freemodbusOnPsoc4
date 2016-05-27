/*******************************************************************************
* File Name: PWMDAC1.c  
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
#include "PWMDAC1.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        PWMDAC1_PC =   (PWMDAC1_PC & \
                                (uint32)(~(uint32)(PWMDAC1_DRIVE_MODE_IND_MASK << (PWMDAC1_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (PWMDAC1_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: PWMDAC1_Write
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
void PWMDAC1_Write(uint8 value) 
{
    uint8 drVal = (uint8)(PWMDAC1_DR & (uint8)(~PWMDAC1_MASK));
    drVal = (drVal | ((uint8)(value << PWMDAC1_SHIFT) & PWMDAC1_MASK));
    PWMDAC1_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: PWMDAC1_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  PWMDAC1_DM_STRONG     Strong Drive 
*  PWMDAC1_DM_OD_HI      Open Drain, Drives High 
*  PWMDAC1_DM_OD_LO      Open Drain, Drives Low 
*  PWMDAC1_DM_RES_UP     Resistive Pull Up 
*  PWMDAC1_DM_RES_DWN    Resistive Pull Down 
*  PWMDAC1_DM_RES_UPDWN  Resistive Pull Up/Down 
*  PWMDAC1_DM_DIG_HIZ    High Impedance Digital 
*  PWMDAC1_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void PWMDAC1_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(PWMDAC1__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: PWMDAC1_Read
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
*  Macro PWMDAC1_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 PWMDAC1_Read(void) 
{
    return (uint8)((PWMDAC1_PS & PWMDAC1_MASK) >> PWMDAC1_SHIFT);
}


/*******************************************************************************
* Function Name: PWMDAC1_ReadDataReg
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
uint8 PWMDAC1_ReadDataReg(void) 
{
    return (uint8)((PWMDAC1_DR & PWMDAC1_MASK) >> PWMDAC1_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(PWMDAC1_INTSTAT) 

    /*******************************************************************************
    * Function Name: PWMDAC1_ClearInterrupt
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
    uint8 PWMDAC1_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(PWMDAC1_INTSTAT & PWMDAC1_MASK);
		PWMDAC1_INTSTAT = maskedStatus;
        return maskedStatus >> PWMDAC1_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
