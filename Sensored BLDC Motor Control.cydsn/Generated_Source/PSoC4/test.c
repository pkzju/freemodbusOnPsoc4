/*******************************************************************************
* File Name: test.c  
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
#include "test.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        test_PC =   (test_PC & \
                                (uint32)(~(uint32)(test_DRIVE_MODE_IND_MASK << (test_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (test_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: test_Write
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
void test_Write(uint8 value) 
{
    uint8 drVal = (uint8)(test_DR & (uint8)(~test_MASK));
    drVal = (drVal | ((uint8)(value << test_SHIFT) & test_MASK));
    test_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: test_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  test_DM_STRONG     Strong Drive 
*  test_DM_OD_HI      Open Drain, Drives High 
*  test_DM_OD_LO      Open Drain, Drives Low 
*  test_DM_RES_UP     Resistive Pull Up 
*  test_DM_RES_DWN    Resistive Pull Down 
*  test_DM_RES_UPDWN  Resistive Pull Up/Down 
*  test_DM_DIG_HIZ    High Impedance Digital 
*  test_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void test_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(test__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: test_Read
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
*  Macro test_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 test_Read(void) 
{
    return (uint8)((test_PS & test_MASK) >> test_SHIFT);
}


/*******************************************************************************
* Function Name: test_ReadDataReg
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
uint8 test_ReadDataReg(void) 
{
    return (uint8)((test_DR & test_MASK) >> test_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(test_INTSTAT) 

    /*******************************************************************************
    * Function Name: test_ClearInterrupt
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
    uint8 test_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(test_INTSTAT & test_MASK);
		test_INTSTAT = maskedStatus;
        return maskedStatus >> test_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
