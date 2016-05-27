/*******************************************************************************
* File Name: Ia_ADC.c  
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
#include "Ia_ADC.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        Ia_ADC_PC =   (Ia_ADC_PC & \
                                (uint32)(~(uint32)(Ia_ADC_DRIVE_MODE_IND_MASK << (Ia_ADC_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (Ia_ADC_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: Ia_ADC_Write
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
void Ia_ADC_Write(uint8 value) 
{
    uint8 drVal = (uint8)(Ia_ADC_DR & (uint8)(~Ia_ADC_MASK));
    drVal = (drVal | ((uint8)(value << Ia_ADC_SHIFT) & Ia_ADC_MASK));
    Ia_ADC_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: Ia_ADC_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  Ia_ADC_DM_STRONG     Strong Drive 
*  Ia_ADC_DM_OD_HI      Open Drain, Drives High 
*  Ia_ADC_DM_OD_LO      Open Drain, Drives Low 
*  Ia_ADC_DM_RES_UP     Resistive Pull Up 
*  Ia_ADC_DM_RES_DWN    Resistive Pull Down 
*  Ia_ADC_DM_RES_UPDWN  Resistive Pull Up/Down 
*  Ia_ADC_DM_DIG_HIZ    High Impedance Digital 
*  Ia_ADC_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void Ia_ADC_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(Ia_ADC__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: Ia_ADC_Read
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
*  Macro Ia_ADC_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Ia_ADC_Read(void) 
{
    return (uint8)((Ia_ADC_PS & Ia_ADC_MASK) >> Ia_ADC_SHIFT);
}


/*******************************************************************************
* Function Name: Ia_ADC_ReadDataReg
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
uint8 Ia_ADC_ReadDataReg(void) 
{
    return (uint8)((Ia_ADC_DR & Ia_ADC_MASK) >> Ia_ADC_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Ia_ADC_INTSTAT) 

    /*******************************************************************************
    * Function Name: Ia_ADC_ClearInterrupt
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
    uint8 Ia_ADC_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(Ia_ADC_INTSTAT & Ia_ADC_MASK);
		Ia_ADC_INTSTAT = maskedStatus;
        return maskedStatus >> Ia_ADC_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
