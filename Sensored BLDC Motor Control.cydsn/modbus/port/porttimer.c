/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
/* ----------------------- Platform includes --------------------------------*/
#include "port.h"
#include <timer_1_isr.h>
#include <Timer_1.h>
#include <timer_clock.h>
#include <B_LED.h>
#include <G_LED.h>
#include <R_LED.h>
/* ----------------------- Modbus includes ----------------------------------*/
#include "modbus/include/mb.h"
#include "modbus/include/mbport.h"

static USHORT s_Tim1Timerout50us = 40;

CY_ISR(timer_1_isr)
{
    timer_1_isr_ClearPending();
    pxMBPortCBTimerExpired(  );

   
}

BOOL
xMBPortTimersInit( USHORT usTim1Timerout50us )
{
    #if(!Timer_1_UsingFixedFunction)
            /* Interrupt State Backup for Critical Region*/
            uint8 Timer_1_interruptState;
    #endif /* Interrupt state back up for Fixed Function only */ 

   s_Tim1Timerout50us = usTim1Timerout50us;
    Timer_1_WritePeriod(s_Tim1Timerout50us);
    Timer_1_WriteCounter(s_Tim1Timerout50us);

    #if (Timer_1_UsingHWCaptureCounter)/* Capture counter is enabled */
        Timer_1_CAPTURE_COUNT_CTRL |= Timer_1_CNTR_ENABLE;
        Timer_1_SetCaptureCount(Timer_1_INIT_CAPTURE_COUNT);
    #endif /* Configure capture counter value */

    #if (!Timer_1_UsingFixedFunction)
        #if (Timer_1_SoftwareCaptureMode)
            Timer_1_SetCaptureMode(Timer_1_INIT_CAPTURE_MODE);
        #endif /* Set Capture Mode for UDB implementation if capture mode is software controlled */

        #if (Timer_1_SoftwareTriggerMode)
            #if (!Timer_1_UDB_CONTROL_REG_REMOVED)
                if (0u == (Timer_1_CONTROL & Timer_1__B_TIMER__TM_SOFTWARE))
                {
                    Timer_1_SetTriggerMode(Timer_1_INIT_TRIGGER_MODE);
                }
            #endif /* (!Timer_1_UDB_CONTROL_REG_REMOVED) */
        #endif /* Set trigger mode for UDB Implementation if trigger mode is software controlled */

        /* CyEnterCriticalRegion and CyExitCriticalRegion are used to mark following region critical*/
        /* Enter Critical Region*/
        Timer_1_interruptState = CyEnterCriticalSection();

        /* Use the interrupt output of the status register for IRQ output */
        Timer_1_STATUS_AUX_CTRL |= Timer_1_STATUS_ACTL_INT_EN_MASK;

        /* Exit Critical Region*/
        CyExitCriticalSection(Timer_1_interruptState);

        #if (Timer_1_EnableTriggerMode)
            Timer_1_EnableTrigger();
        #endif /* Set Trigger enable bit for UDB implementation in the control register*/
		
		
        #if (Timer_1_InterruptOnCaptureCount && !Timer_1_UDB_CONTROL_REG_REMOVED)
            Timer_1_SetInterruptCount(Timer_1_INIT_INT_CAPTURE_COUNT);
        #endif /* Set interrupt count in UDB implementation if interrupt count feature is checked.*/

        Timer_1_ClearFIFO();
    #endif /* Configure additional features of UDB implementation */

    Timer_1_SetInterruptMode(Timer_1_INIT_INTERRUPT_MODE);

    timer_1_isr_SetVector(timer_1_isr);

    timer_1_isr_SetPriority((uint8)timer_1_isr_INTC_PRIOR_NUMBER);
    
    return TRUE;
}

INLINE void
vMBPortTimersEnable(  )
{
    Timer_1_WritePeriod(s_Tim1Timerout50us);//there is bug ,i have to *2,otherwise modbus can not work
    Timer_1_WriteCounter(s_Tim1Timerout50us);
    timer_clock_Start();
    Timer_1_Enable();
    timer_1_isr_Enable();

    
}

INLINE void
vMBPortTimersDisable(  )
{
    timer_clock_Stop();
    timer_1_isr_Disable();
    Timer_1_Stop();
}

/* [] END OF FILE */
