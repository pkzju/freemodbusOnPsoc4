/*******************************************************************************
* File Name: OP_V_bus_Vout_Filt.c  
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
#include "OP_V_bus_Vout_Filt.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        OP_V_bus_Vout_Filt_PC =   (OP_V_bus_Vout_Filt_PC & \
                                (uint32)(~(uint32)(OP_V_bus_Vout_Filt_DRIVE_MODE_IND_MASK << (OP_V_bus_Vout_Filt_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (OP_V_bus_Vout_Filt_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: OP_V_bus_Vout_Filt_Write
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
void OP_V_bus_Vout_Filt_Write(uint8 value) 
{
    uint8 drVal = (uint8)(OP_V_bus_Vout_Filt_DR & (uint8)(~OP_V_bus_Vout_Filt_MASK));
    drVal = (drVal | ((uint8)(value << OP_V_bus_Vout_Filt_SHIFT) & OP_V_bus_Vout_Filt_MASK));
    OP_V_bus_Vout_Filt_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: OP_V_bus_Vout_Filt_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  OP_V_bus_Vout_Filt_DM_STRONG     Strong Drive 
*  OP_V_bus_Vout_Filt_DM_OD_HI      Open Drain, Drives High 
*  OP_V_bus_Vout_Filt_DM_OD_LO      Open Drain, Drives Low 
*  OP_V_bus_Vout_Filt_DM_RES_UP     Resistive Pull Up 
*  OP_V_bus_Vout_Filt_DM_RES_DWN    Resistive Pull Down 
*  OP_V_bus_Vout_Filt_DM_RES_UPDWN  Resistive Pull Up/Down 
*  OP_V_bus_Vout_Filt_DM_DIG_HIZ    High Impedance Digital 
*  OP_V_bus_Vout_Filt_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void OP_V_bus_Vout_Filt_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(OP_V_bus_Vout_Filt__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: OP_V_bus_Vout_Filt_Read
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
*  Macro OP_V_bus_Vout_Filt_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 OP_V_bus_Vout_Filt_Read(void) 
{
    return (uint8)((OP_V_bus_Vout_Filt_PS & OP_V_bus_Vout_Filt_MASK) >> OP_V_bus_Vout_Filt_SHIFT);
}


/*******************************************************************************
* Function Name: OP_V_bus_Vout_Filt_ReadDataReg
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
uint8 OP_V_bus_Vout_Filt_ReadDataReg(void) 
{
    return (uint8)((OP_V_bus_Vout_Filt_DR & OP_V_bus_Vout_Filt_MASK) >> OP_V_bus_Vout_Filt_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(OP_V_bus_Vout_Filt_INTSTAT) 

    /*******************************************************************************
    * Function Name: OP_V_bus_Vout_Filt_ClearInterrupt
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
    uint8 OP_V_bus_Vout_Filt_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(OP_V_bus_Vout_Filt_INTSTAT & OP_V_bus_Vout_Filt_MASK);
		OP_V_bus_Vout_Filt_INTSTAT = maskedStatus;
        return maskedStatus >> OP_V_bus_Vout_Filt_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
