/*******************************************************************************
* File Name: OP_I_B_VNeg.c  
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
#include "OP_I_B_VNeg.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        OP_I_B_VNeg_PC =   (OP_I_B_VNeg_PC & \
                                (uint32)(~(uint32)(OP_I_B_VNeg_DRIVE_MODE_IND_MASK << (OP_I_B_VNeg_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (OP_I_B_VNeg_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: OP_I_B_VNeg_Write
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
void OP_I_B_VNeg_Write(uint8 value) 
{
    uint8 drVal = (uint8)(OP_I_B_VNeg_DR & (uint8)(~OP_I_B_VNeg_MASK));
    drVal = (drVal | ((uint8)(value << OP_I_B_VNeg_SHIFT) & OP_I_B_VNeg_MASK));
    OP_I_B_VNeg_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: OP_I_B_VNeg_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  OP_I_B_VNeg_DM_STRONG     Strong Drive 
*  OP_I_B_VNeg_DM_OD_HI      Open Drain, Drives High 
*  OP_I_B_VNeg_DM_OD_LO      Open Drain, Drives Low 
*  OP_I_B_VNeg_DM_RES_UP     Resistive Pull Up 
*  OP_I_B_VNeg_DM_RES_DWN    Resistive Pull Down 
*  OP_I_B_VNeg_DM_RES_UPDWN  Resistive Pull Up/Down 
*  OP_I_B_VNeg_DM_DIG_HIZ    High Impedance Digital 
*  OP_I_B_VNeg_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void OP_I_B_VNeg_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(OP_I_B_VNeg__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: OP_I_B_VNeg_Read
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
*  Macro OP_I_B_VNeg_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 OP_I_B_VNeg_Read(void) 
{
    return (uint8)((OP_I_B_VNeg_PS & OP_I_B_VNeg_MASK) >> OP_I_B_VNeg_SHIFT);
}


/*******************************************************************************
* Function Name: OP_I_B_VNeg_ReadDataReg
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
uint8 OP_I_B_VNeg_ReadDataReg(void) 
{
    return (uint8)((OP_I_B_VNeg_DR & OP_I_B_VNeg_MASK) >> OP_I_B_VNeg_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(OP_I_B_VNeg_INTSTAT) 

    /*******************************************************************************
    * Function Name: OP_I_B_VNeg_ClearInterrupt
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
    uint8 OP_I_B_VNeg_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(OP_I_B_VNeg_INTSTAT & OP_I_B_VNeg_MASK);
		OP_I_B_VNeg_INTSTAT = maskedStatus;
        return maskedStatus >> OP_I_B_VNeg_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
