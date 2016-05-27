/*******************************************************************************
* File Name: IPM_FO.c  
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
#include "IPM_FO.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        IPM_FO_PC =   (IPM_FO_PC & \
                                (uint32)(~(uint32)(IPM_FO_DRIVE_MODE_IND_MASK << (IPM_FO_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (IPM_FO_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: IPM_FO_Write
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
void IPM_FO_Write(uint8 value) 
{
    uint8 drVal = (uint8)(IPM_FO_DR & (uint8)(~IPM_FO_MASK));
    drVal = (drVal | ((uint8)(value << IPM_FO_SHIFT) & IPM_FO_MASK));
    IPM_FO_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: IPM_FO_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  IPM_FO_DM_STRONG     Strong Drive 
*  IPM_FO_DM_OD_HI      Open Drain, Drives High 
*  IPM_FO_DM_OD_LO      Open Drain, Drives Low 
*  IPM_FO_DM_RES_UP     Resistive Pull Up 
*  IPM_FO_DM_RES_DWN    Resistive Pull Down 
*  IPM_FO_DM_RES_UPDWN  Resistive Pull Up/Down 
*  IPM_FO_DM_DIG_HIZ    High Impedance Digital 
*  IPM_FO_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void IPM_FO_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(IPM_FO__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: IPM_FO_Read
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
*  Macro IPM_FO_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 IPM_FO_Read(void) 
{
    return (uint8)((IPM_FO_PS & IPM_FO_MASK) >> IPM_FO_SHIFT);
}


/*******************************************************************************
* Function Name: IPM_FO_ReadDataReg
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
uint8 IPM_FO_ReadDataReg(void) 
{
    return (uint8)((IPM_FO_DR & IPM_FO_MASK) >> IPM_FO_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(IPM_FO_INTSTAT) 

    /*******************************************************************************
    * Function Name: IPM_FO_ClearInterrupt
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
    uint8 IPM_FO_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(IPM_FO_INTSTAT & IPM_FO_MASK);
		IPM_FO_INTSTAT = maskedStatus;
        return maskedStatus >> IPM_FO_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
