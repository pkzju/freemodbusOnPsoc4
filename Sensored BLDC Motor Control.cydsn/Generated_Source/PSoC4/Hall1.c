/*******************************************************************************
* File Name: Hall1.c  
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
#include "Hall1.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        Hall1_PC =   (Hall1_PC & \
                                (uint32)(~(uint32)(Hall1_DRIVE_MODE_IND_MASK << (Hall1_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (Hall1_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: Hall1_Write
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
void Hall1_Write(uint8 value) 
{
    uint8 drVal = (uint8)(Hall1_DR & (uint8)(~Hall1_MASK));
    drVal = (drVal | ((uint8)(value << Hall1_SHIFT) & Hall1_MASK));
    Hall1_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: Hall1_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  Hall1_DM_STRONG     Strong Drive 
*  Hall1_DM_OD_HI      Open Drain, Drives High 
*  Hall1_DM_OD_LO      Open Drain, Drives Low 
*  Hall1_DM_RES_UP     Resistive Pull Up 
*  Hall1_DM_RES_DWN    Resistive Pull Down 
*  Hall1_DM_RES_UPDWN  Resistive Pull Up/Down 
*  Hall1_DM_DIG_HIZ    High Impedance Digital 
*  Hall1_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void Hall1_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(Hall1__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: Hall1_Read
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
*  Macro Hall1_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Hall1_Read(void) 
{
    return (uint8)((Hall1_PS & Hall1_MASK) >> Hall1_SHIFT);
}


/*******************************************************************************
* Function Name: Hall1_ReadDataReg
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
uint8 Hall1_ReadDataReg(void) 
{
    return (uint8)((Hall1_DR & Hall1_MASK) >> Hall1_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Hall1_INTSTAT) 

    /*******************************************************************************
    * Function Name: Hall1_ClearInterrupt
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
    uint8 Hall1_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(Hall1_INTSTAT & Hall1_MASK);
		Hall1_INTSTAT = maskedStatus;
        return maskedStatus >> Hall1_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
