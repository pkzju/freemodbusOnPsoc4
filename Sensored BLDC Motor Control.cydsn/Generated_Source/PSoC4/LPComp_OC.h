/*******************************************************************************
* File Name: LPComp_OC.h
* Version 2.0
*
* Description:
*  This file contains the function prototypes and constants used in
*  the Low Power Comparator component.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2013-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_COMPARATOR_LPComp_OC_H)
#define CY_COMPARATOR_LPComp_OC_H

#include "cytypes.h"
#include "cyfitter.h"


extern uint8  LPComp_OC_initVar;


/***************************************
*  Conditional Compilation Parameters
****************************************/

#define LPComp_OC_CY_LPCOMP_V0 (CYIPBLOCK_m0s8lpcomp_VERSION == 0u) 
#define LPComp_OC_CY_LPCOMP_V2 (CYIPBLOCK_m0s8lpcomp_VERSION >= 2u) 


/**************************************
*        Function Prototypes
**************************************/

void    LPComp_OC_Start(void);
void    LPComp_OC_Init(void);
void    LPComp_OC_Enable(void);
void    LPComp_OC_Stop(void);
void    LPComp_OC_SetSpeed(uint32 speed);
void    LPComp_OC_SetInterruptMode(uint32 mode);
uint32  LPComp_OC_GetInterruptSource(void);
void    LPComp_OC_ClearInterrupt(uint32 interruptMask);
void    LPComp_OC_SetInterrupt(uint32 interruptMask);
void    LPComp_OC_SetHysteresis(uint32 hysteresis);
uint32  LPComp_OC_GetCompare(void);
uint32  LPComp_OC_ZeroCal(void);
void    LPComp_OC_LoadTrim(uint32 trimVal);
void    LPComp_OC_Sleep(void);
void    LPComp_OC_Wakeup(void);
void    LPComp_OC_SaveConfig(void);
void    LPComp_OC_RestoreConfig(void);
#if(LPComp_OC_CY_LPCOMP_V2)
    void    LPComp_OC_SetOutputMode(uint32 mode);
    void    LPComp_OC_SetInterruptMask(uint32 interruptMask);
    uint32  LPComp_OC_GetInterruptMask(void);
    uint32  LPComp_OC_GetInterruptSourceMasked(void);
#endif /* (LPComp_OC_CY_LPCOMP_V2) */


/**************************************
*           API Constants
**************************************/

#if(LPComp_OC_CY_LPCOMP_V2)
    /* Constants for LPComp_OC_SetOutputMode(), mode parameter */
    #define LPComp_OC_OUT_PULSE      (0x00u)
    #define LPComp_OC_OUT_SYNC       (0x01u)
    #define LPComp_OC_OUT_DIRECT     (0x02u)
#endif /* (LPComp_OC_CY_LPCOMP_V2) */

#define LPComp_OC_INTR_PARAM_MASK    (0x03u)
#define LPComp_OC_SPEED_PARAM_MASK   (0x03u)

/* Constants for LPComp_OC_SetSpeed(), speed parameter */
#define LPComp_OC_MED_SPEED          (0x00u)
#define LPComp_OC_HIGH_SPEED         (0x01u)
#define LPComp_OC_LOW_SPEED          (0x02u)

/* Constants for LPComp_OC_SetInterruptMode(), mode parameter */
#define LPComp_OC_INTR_DISABLE       (0x00u)
#define LPComp_OC_INTR_RISING        (0x01u)
#define LPComp_OC_INTR_FALLING       (0x02u)
#define LPComp_OC_INTR_BOTH          (0x03u)

/* Constants for LPComp_OC_SetHysteresis(), hysteresis parameter */
#define LPComp_OC_HYST_ENABLE        (0x00u)
#define LPComp_OC_HYST_DISABLE       (0x01u)

/* Constants for LPComp_OC_ZeroCal() */
#define LPComp_OC_TRIMA_MASK         (0x1Fu)
#define LPComp_OC_TRIMA_SIGNBIT      (4u)
#define LPComp_OC_TRIMA_MAX_VALUE    (15u)
#define LPComp_OC_TRIMB_MASK         (0x1Fu)
#define LPComp_OC_TRIMB_SHIFT        (8u)
#define LPComp_OC_TRIMB_SIGNBIT      (4u)
#define LPComp_OC_TRIMB_MAX_VALUE    (15u)

/* Constants for LPComp_OC_GetInterruptSource() and 
* LPComp_OC_ClearInterrupt(), interruptMask parameter 
*/
#define LPComp_OC_INTR_SHIFT         (LPComp_OC_cy_psoc4_lpcomp_1__LPCOMP_INTR_SHIFT)
#define LPComp_OC_INTR               ((uint32)0x01u << LPComp_OC_INTR_SHIFT)

/* Constants for LPComp_OC_SetInterrupt(), interruptMask parameter */
#define LPComp_OC_INTR_SET_SHIFT     (LPComp_OC_cy_psoc4_lpcomp_1__LPCOMP_INTR_SET_SHIFT)
#define LPComp_OC_INTR_SET           ((uint32)0x01u << LPComp_OC_INTR_SHIFT)

#if(LPComp_OC_CY_LPCOMP_V2)
    /* Constants for LPComp_OC_GetInterruptMask() and 
    * LPComp_OC_SetInterruptMask(), interruptMask parameter 
    */
    #define LPComp_OC_INTR_MASK_SHIFT    (LPComp_OC_cy_psoc4_lpcomp_1__LPCOMP_INTR_MASK_SHIFT)
    #define LPComp_OC_INTR_MASK          ((uint32)0x01u << LPComp_OC_INTR_MASK_SHIFT)

    /* Constants for LPComp_OC_GetInterruptSourceMasked() */ 
    #define LPComp_OC_INTR_MASKED_SHIFT  (LPComp_OC_cy_psoc4_lpcomp_1__LPCOMP_INTR_MASKED_SHIFT)
    #define LPComp_OC_INTR_MASKED        ((uint32)0x01u << LPComp_OC_INTR_MASKED_SHIFT)
#endif /* (LPComp_OC_CY_LPCOMP_V2) */


/***************************************
* Enumerated Types and Parameters 
***************************************/

/* Enumerated Types LPCompSpeedType, Used in parameter Speed */
#define LPComp_OC__LPC_LOW_SPEED 2
#define LPComp_OC__LPC_MED_SPEED 0
#define LPComp_OC__LPC_HIGH_SPEED 1


/* Enumerated Types LPCompInterruptType, Used in parameter Interrupt */
#define LPComp_OC__LPC_INT_DISABLE 0
#define LPComp_OC__LPC_INT_RISING 1
#define LPComp_OC__LPC_INT_FALLING 2
#define LPComp_OC__LPC_INT_BOTH 3


/* Enumerated Types LPCompHysteresisType, Used in parameter Hysteresis */
#define LPComp_OC__LPC_DISABLE_HYST 1
#define LPComp_OC__LPC_ENABLE_HYST 0


/* Enumerated Types OutputModeType, Used in parameter OutputMode */
#define LPComp_OC__OUT_MODE_SYNC 1
#define LPComp_OC__OUT_MODE_DIRECT 2
#define LPComp_OC__OUT_MODE_PULSE 0



/***************************************
*   Initial Parameter Constants
****************************************/

#define LPComp_OC_INTERRUPT    (1u)
#define LPComp_OC_SPEED        (0u)
#define LPComp_OC_HYSTERESIS   (0u)
#if (LPComp_OC_CY_LPCOMP_V2)
    #define LPComp_OC_OUT_MODE       (0u)
    #define LPComp_OC_INTERRUPT_EN   (0u)
#endif /* (LPComp_OC_CY_LPCOMP_V2) */


/**************************************
*             Registers
**************************************/

#define LPComp_OC_CONFIG_REG     (*(reg32 *)LPComp_OC_cy_psoc4_lpcomp_1__LPCOMP_CONFIG)
#define LPComp_OC_CONFIG_PTR     ( (reg32 *)LPComp_OC_cy_psoc4_lpcomp_1__LPCOMP_CONFIG)

#define LPComp_OC_DFT_REG        (*(reg32 *)CYREG_LPCOMP_DFT)
#define LPComp_OC_DFT_PTR        ( (reg32 *)CYREG_LPCOMP_DFT)

#define LPComp_OC_INTR_REG       (*(reg32 *)LPComp_OC_cy_psoc4_lpcomp_1__LPCOMP_INTR)
#define LPComp_OC_INTR_PTR       ( (reg32 *)LPComp_OC_cy_psoc4_lpcomp_1__LPCOMP_INTR)

#define LPComp_OC_INTR_SET_REG   (*(reg32 *)LPComp_OC_cy_psoc4_lpcomp_1__LPCOMP_INTR_SET)
#define LPComp_OC_INTR_SET_PTR   ( (reg32 *)LPComp_OC_cy_psoc4_lpcomp_1__LPCOMP_INTR_SET)

#define LPComp_OC_TRIMA_REG      (*(reg32 *)LPComp_OC_cy_psoc4_lpcomp_1__TRIM_A)
#define LPComp_OC_TRIMA_PTR      ( (reg32 *)LPComp_OC_cy_psoc4_lpcomp_1__TRIM_A)

#define LPComp_OC_TRIMB_REG      (*(reg32 *)LPComp_OC_cy_psoc4_lpcomp_1__TRIM_B)
#define LPComp_OC_TRIMB_PTR      ( (reg32 *)LPComp_OC_cy_psoc4_lpcomp_1__TRIM_B)

#if(LPComp_OC_CY_LPCOMP_V2)
    #define LPComp_OC_INTR_MASK_REG    (*(reg32 *)LPComp_OC_cy_psoc4_lpcomp_1__LPCOMP_INTR_MASK) 
    #define LPComp_OC_INTR_MASK_PTR    ( (reg32 *)LPComp_OC_cy_psoc4_lpcomp_1__LPCOMP_INTR_MASK) 

    #define LPComp_OC_INTR_MASKED_REG  (*(reg32 *)LPComp_OC_cy_psoc4_lpcomp_1__LPCOMP_INTR_MASKED) 
    #define LPComp_OC_INTR_MASKED_PTR  ( (reg32 *)LPComp_OC_cy_psoc4_lpcomp_1__LPCOMP_INTR_MASKED) 
#endif /* (LPComp_OC_CY_LPCOMP_V2) */


/***************************************
*        Registers Constants
***************************************/

#define LPComp_OC_CONFIG_REG_SHIFT           (LPComp_OC_cy_psoc4_lpcomp_1__LPCOMP_CONFIG_SHIFT)

/* LPComp_OCLPComp_OC_CONFIG_REG */
#define LPComp_OC_CONFIG_SPEED_MODE_SHIFT    (0u)    /* [1:0]    Operating mode for the comparator      */
#define LPComp_OC_CONFIG_HYST_SHIFT          (2u)    /* [2]      Add 10mV hysteresis to the comparator: 0-enable, 1-disable */
#define LPComp_OC_CONFIG_INTR_SHIFT          (4u)    /* [5:4]    Sets Pulse/Interrupt mode              */
#define LPComp_OC_CONFIG_OUT_SHIFT           (6u)    /* [6]      Current output value of the comparator    */
#define LPComp_OC_CONFIG_EN_SHIFT            (7u)    /* [7]      Enable comparator */
#if(LPComp_OC_CY_LPCOMP_V2)
    #define LPComp_OC_CONFIG_DSI_BYPASS_SHIFT    (16u)   /* [16]   Bypass comparator output synchronization for DSI output  */
    #define LPComp_OC_CONFIG_DSI_LEVEL_SHIFT     (17u)   /* [17]   Comparator DSI (trigger) out level: 0-pulse, 1-level  */
#endif /* (LPComp_OC_CY_LPCOMP_V2) */

#define LPComp_OC_CONFIG_SPEED_MODE_MASK     (((uint32) 0x03u << LPComp_OC_CONFIG_SPEED_MODE_SHIFT) << \
                                                    LPComp_OC_CONFIG_REG_SHIFT)

#define LPComp_OC_CONFIG_HYST                (((uint32) 0x01u << LPComp_OC_CONFIG_HYST_SHIFT) << \
                                                    LPComp_OC_CONFIG_REG_SHIFT)

#define LPComp_OC_CONFIG_INTR_MASK           (((uint32) 0x03u << LPComp_OC_CONFIG_INTR_SHIFT) << \
                                                    LPComp_OC_CONFIG_REG_SHIFT)

#define LPComp_OC_CONFIG_OUT                 (((uint32) 0x01u << LPComp_OC_CONFIG_OUT_SHIFT) << \
                                                    LPComp_OC_CONFIG_REG_SHIFT)

#define LPComp_OC_CONFIG_EN                  (((uint32) 0x01u << LPComp_OC_CONFIG_EN_SHIFT) << \
                                                    LPComp_OC_CONFIG_REG_SHIFT)
#if(LPComp_OC_CY_LPCOMP_V2)
    #define LPComp_OC_CONFIG_DSI_BYPASS          (((uint32) 0x01u << LPComp_OC_CONFIG_DSI_BYPASS_SHIFT) << \
                                                        (LPComp_OC_CONFIG_REG_SHIFT/2))

    #define LPComp_OC_CONFIG_DSI_LEVEL           (((uint32) 0x01u << LPComp_OC_CONFIG_DSI_LEVEL_SHIFT) << \
                                                        (LPComp_OC_CONFIG_REG_SHIFT/2))
#endif /* (LPComp_OC_CY_LPCOMP_V2) */


/* LPComp_OCLPComp_OC_DFT_REG */
#define LPComp_OC_DFT_CAL_EN_SHIFT    (0u)    /* [0] Calibration enable */

#define LPComp_OC_DFT_CAL_EN          ((uint32) 0x01u << LPComp_OC_DFT_CAL_EN_SHIFT)


/***************************************
*       Init Macros Definitions
***************************************/

#define LPComp_OC_GET_CONFIG_SPEED_MODE(mode)    ((uint32) ((((uint32) (mode) << LPComp_OC_CONFIG_SPEED_MODE_SHIFT) << \
                                                            LPComp_OC_CONFIG_REG_SHIFT) & \
                                                            LPComp_OC_CONFIG_SPEED_MODE_MASK))

#define LPComp_OC_GET_CONFIG_HYST(hysteresis)    ((0u != (hysteresis)) ? (LPComp_OC_CONFIG_HYST) : (0u))

#define LPComp_OC_GET_CONFIG_INTR(intType)   ((uint32) ((((uint32)(intType) << LPComp_OC_CONFIG_INTR_SHIFT) << \
                                                    LPComp_OC_CONFIG_REG_SHIFT) & \
                                                    LPComp_OC_CONFIG_INTR_MASK))
#if(LPComp_OC_CY_LPCOMP_V2)
    #define LPComp_OC_GET_CONFIG_DSI_BYPASS(bypass)  ((0u != ((bypass) & LPComp_OC_OUT_DIRECT)) ? \
                                                                    (LPComp_OC_CONFIG_DSI_BYPASS) : (0u))
   
    #define LPComp_OC_GET_CONFIG_DSI_LEVEL(level)    ((0u != ((level) & LPComp_OC_OUT_SYNC)) ? \
                                                                    (LPComp_OC_CONFIG_DSI_LEVEL) : (0u))
    
    #define LPComp_OC_GET_INTR_MASK(mask)            ((0u != (mask)) ? (LPComp_OC_INTR_MASK) : (0u))
#endif /* (LPComp_OC_CY_LPCOMP_V2) */

#if(LPComp_OC_CY_LPCOMP_V0)
    #define LPComp_OC_CONFIG_REG_DEFAULT (LPComp_OC_GET_CONFIG_SPEED_MODE(LPComp_OC_SPEED) |\
                                                 LPComp_OC_GET_CONFIG_INTR(LPComp_OC_INTERRUPT)   |\
                                                 LPComp_OC_GET_CONFIG_HYST(LPComp_OC_HYSTERESIS))
#else
    #define LPComp_OC_CONFIG_REG_DEFAULT (LPComp_OC_GET_CONFIG_SPEED_MODE(LPComp_OC_SPEED) |\
                                                 LPComp_OC_GET_CONFIG_INTR(LPComp_OC_INTERRUPT)   |\
                                                 LPComp_OC_GET_CONFIG_HYST(LPComp_OC_HYSTERESIS)  |\
                                                 LPComp_OC_GET_CONFIG_DSI_BYPASS(LPComp_OC_OUT_MODE) |\
                                                 LPComp_OC_GET_CONFIG_DSI_LEVEL(LPComp_OC_OUT_MODE))
#endif /* (LPComp_OC_CY_LPCOMP_V0) */

#if(LPComp_OC_CY_LPCOMP_V2)
    #define LPComp_OC_INTR_MASK_REG_DEFAULT  (LPComp_OC_GET_INTR_MASK(LPComp_OC_INTERRUPT_EN))
#endif /* (LPComp_OC_CY_LPCOMP_V2) */


/***************************************
* The following code is DEPRECATED and 
* should not be used in new projects.
***************************************/

#define LPComp_OC_CONFIG_FILT_SHIFT          (3u)    
#define LPComp_OC_CONFIG_FILT                ((uint32)((uint32)((uint32)0x01u << \
                                                    LPComp_OC_CONFIG_FILT_SHIFT) << LPComp_OC_CONFIG_REG_SHIFT))

#define LPComp_OC_DIGITAL_FILTER             (0u)

/* LPComp_OC_SetFilter() parameters */
#define LPComp_OC_FILT_DISABLE               (0x00u)
#define LPComp_OC_FILT_ENABLE                (0x01u)

/* LPComp_OC_SetSpeed() parameters */
#define LPComp_OC_MEDSPEED                   (LPComp_OC_MED_SPEED)
#define LPComp_OC_HIGHSPEED                  (LPComp_OC_HIGH_SPEED)
#define LPComp_OC_LOWSPEED                   (LPComp_OC_LOW_SPEED)

void    LPComp_OC_SetFilter(uint32 filter);

#endif    /* CY_COMPARATOR_LPComp_OC_H */


/* [] END OF FILE */
