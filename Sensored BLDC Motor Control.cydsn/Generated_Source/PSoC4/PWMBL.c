/*******************************************************************************
* File Name: PWMBL.c  
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
#include "PWMBL.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        PWMBL_PC =   (PWMBL_PC & \
                                (uint32)(~(uint32)(PWMBL_DRIVE_MODE_IND_MASK << (PWMBL_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (PWMBL_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: PWMBL_Write
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
void PWMBL_Write(uint8 value) 
{
    uint8 drVal = (uint8)(PWMBL_DR & (uint8)(~PWMBL_MASK));
    drVal = (drVal | ((uint8)(value << PWMBL_SHIFT) & PWMBL_MASK));
    PWMBL_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: PWMBL_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  PWMBL_DM_STRONG     Strong Drive 
*  PWMBL_DM_OD_HI      Open Drain, Drives High 
*  PWMBL_DM_OD_LO      Open Drain, Drives Low 
*  PWMBL_DM_RES_UP     Resistive Pull Up 
*  PWMBL_DM_RES_DWN    Resistive Pull Down 
*  PWMBL_DM_RES_UPDWN  Resistive Pull Up/Down 
*  PWMBL_DM_DIG_HIZ    High Impedance Digital 
*  PWMBL_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void PWMBL_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(PWMBL__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: PWMBL_Read
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
*  Macro PWMBL_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 PWMBL_Read(void) 
{
    return (uint8)((PWMBL_PS & PWMBL_MASK) >> PWMBL_SHIFT);
}


/*******************************************************************************
* Function Name: PWMBL_ReadDataReg
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
uint8 PWMBL_ReadDataReg(void) 
{
    return (uint8)((PWMBL_DR & PWMBL_MASK) >> PWMBL_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(PWMBL_INTSTAT) 

    /*******************************************************************************
    * Function Name: PWMBL_ClearInterrupt
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
    uint8 PWMBL_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(PWMBL_INTSTAT & PWMBL_MASK);
		PWMBL_INTSTAT = maskedStatus;
        return maskedStatus >> PWMBL_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
