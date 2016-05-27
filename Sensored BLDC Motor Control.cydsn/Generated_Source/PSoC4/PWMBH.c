/*******************************************************************************
* File Name: PWMBH.c  
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
#include "PWMBH.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        PWMBH_PC =   (PWMBH_PC & \
                                (uint32)(~(uint32)(PWMBH_DRIVE_MODE_IND_MASK << (PWMBH_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (PWMBH_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: PWMBH_Write
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
void PWMBH_Write(uint8 value) 
{
    uint8 drVal = (uint8)(PWMBH_DR & (uint8)(~PWMBH_MASK));
    drVal = (drVal | ((uint8)(value << PWMBH_SHIFT) & PWMBH_MASK));
    PWMBH_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: PWMBH_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  PWMBH_DM_STRONG     Strong Drive 
*  PWMBH_DM_OD_HI      Open Drain, Drives High 
*  PWMBH_DM_OD_LO      Open Drain, Drives Low 
*  PWMBH_DM_RES_UP     Resistive Pull Up 
*  PWMBH_DM_RES_DWN    Resistive Pull Down 
*  PWMBH_DM_RES_UPDWN  Resistive Pull Up/Down 
*  PWMBH_DM_DIG_HIZ    High Impedance Digital 
*  PWMBH_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void PWMBH_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(PWMBH__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: PWMBH_Read
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
*  Macro PWMBH_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 PWMBH_Read(void) 
{
    return (uint8)((PWMBH_PS & PWMBH_MASK) >> PWMBH_SHIFT);
}


/*******************************************************************************
* Function Name: PWMBH_ReadDataReg
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
uint8 PWMBH_ReadDataReg(void) 
{
    return (uint8)((PWMBH_DR & PWMBH_MASK) >> PWMBH_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(PWMBH_INTSTAT) 

    /*******************************************************************************
    * Function Name: PWMBH_ClearInterrupt
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
    uint8 PWMBH_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(PWMBH_INTSTAT & PWMBH_MASK);
		PWMBH_INTSTAT = maskedStatus;
        return maskedStatus >> PWMBH_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
