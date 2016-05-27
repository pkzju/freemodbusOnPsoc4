/*******************************************************************************
* File Name: Hall_Comp.h
* Version 1.10
*
* Description:
*  This file contains the function prototypes and constants used in
*  the Analog Comparator User Module.
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

#if !defined(CY_COMPARATOR_Hall_Comp_H)
#define CY_COMPARATOR_Hall_Comp_H

#include "cytypes.h"
#include "CyLib.h"
#include "cyfitter.h"


/***************************************
*       Type Definitions
***************************************/

/* Structure to save state before go to sleep */
typedef struct
{
    uint8  enableState;
} Hall_Comp_BACKUP_STRUCT;


/**************************************
*        Function Prototypes
**************************************/
void    Hall_Comp_Init(void);
void    Hall_Comp_Enable(void);
void    Hall_Comp_Start(void);
void    Hall_Comp_Stop(void);
void    Hall_Comp_SetSpeed(uint32 speed);
uint32  Hall_Comp_ZeroCal(void);
void    Hall_Comp_LoadTrim(uint32 trimVal);
void    Hall_Comp_Sleep(void);
void    Hall_Comp_Wakeup(void);
void    Hall_Comp_SaveConfig(void);
void    Hall_Comp_RestoreConfig(void);
uint32  Hall_Comp_GetCompare(void);
uint32  Hall_Comp_GetInterruptSource(void);
void    Hall_Comp_ClearInterrupt(uint32 interruptMask);
void    Hall_Comp_SetInterrupt(uint32 interruptMask);
void    Hall_Comp_SetInterruptMask(uint32 interruptMask);
uint32  Hall_Comp_GetInterruptMask(void);
uint32  Hall_Comp_GetInterruptSourceMasked(void);
void    Hall_Comp_SetInterruptMode(uint32 mode);
void    Hall_Comp_DisableInterruptOutput(void);

#define Hall_Comp_EnableInterruptOutput(void)     Hall_Comp_SetInterruptMask(Hall_Comp_GetInterruptMask() | Hall_Comp_INTR_MASK)
#define Hall_Comp_GetInterruptOutputStatus(void)  ((0u == (Hall_Comp_GetInterruptSourceMasked() & Hall_Comp_INTR_MASKED)) ? 0u : 1u)
#define Hall_Comp_ClearInterruptOutput(void)      Hall_Comp_ClearInterrupt(Hall_Comp_INTR)
#define Hall_Comp_SetInterruptOutput(void)        Hall_Comp_SetInterrupt(Hall_Comp_INTR_MASK)

/**************************************
*           API Constants
**************************************/

/* Power constants for SetSpeed() function */
#define Hall_Comp_SLOW_SPEED     (0x01u)
#define Hall_Comp_MED_SPEED      (0x02u)
#define Hall_Comp_HIGH_SPEED     (0x03u)

/* Trim defines for ZeroCal() function */
#define Hall_Comp_COMP_TRIM_SIGN_SHIFT   (5u)
#define Hall_Comp_COMP_TRIM_MAX_VALUE    (32u)
#define Hall_Comp_COMP_CALIBRATION_DELAY (10u)

/* Constants for Hall_Comp_SetInterruptMode(), mode parameter */
#define Hall_Comp_INTR_DISABLE       (0x00u)
#define Hall_Comp_INTR_RISING        (0x01u)
#define Hall_Comp_INTR_FALLING       (0x02u)
#define Hall_Comp_INTR_BOTH          (0x03u)

/* Constants for Hall_Comp_GetInterruptSource() and 
* Hall_Comp_ClearInterrupt(), interruptMask parameter 
*/
#define Hall_Comp_INTR_SHIFT         (Hall_Comp_cy_psoc4_abuf__INTR_SHIFT)
#define Hall_Comp_INTR               ((uint32)0x01u << Hall_Comp_INTR_SHIFT)

/* Constants for Hall_Comp_SetInterrupt(), interruptMask parameter */
#define Hall_Comp_INTR_SET_SHIFT     (Hall_Comp_cy_psoc4_abuf__INTR_SET_SHIFT)
#define Hall_Comp_INTR_SET           ((uint32)0x01u << Hall_Comp_INTR_SHIFT)

/* Constants for Hall_Comp_GetInterruptMask() and 
* Hall_Comp_SetInterruptMask(), interruptMask parameter 
*/
#define Hall_Comp_INTR_MASK_SHIFT    (Hall_Comp_cy_psoc4_abuf__INTR_MASK_SHIFT)
#define Hall_Comp_INTR_MASK          ((uint32)0x01u << Hall_Comp_INTR_MASK_SHIFT)

/* Constants for Hall_Comp_GetInterruptSourceMasked() */ 
#define Hall_Comp_INTR_MASKED_SHIFT  (Hall_Comp_cy_psoc4_abuf__INTR_MASKED_SHIFT)
#define Hall_Comp_INTR_MASKED        ((uint32)0x01u << Hall_Comp_INTR_MASKED_SHIFT)


/***************************************
*   Initial Parameter Constants
****************************************/

#define Hall_Comp_HYSTERESIS         (1u)
#define Hall_Comp_POWER              (3u)
#define Hall_Comp_DEEPSLEEP_SUPPORT  (0u)
#define Hall_Comp_INTERRUPT_EN       (0u)
#define Hall_Comp_INTERRUPT          (0u)


/***************************************
*    Variables with External Linkage
***************************************/

extern uint8  Hall_Comp_initVar;


/**************************************
*             Registers
**************************************/

#define Hall_Comp_CTB_CTRL_REG               (* (reg32 *) Hall_Comp_cy_psoc4_abuf__CTBM_CTB_CTRL)
#define Hall_Comp_CTB_CTRL_PTR               (  (reg32 *) Hall_Comp_cy_psoc4_abuf__CTBM_CTB_CTRL)

#define Hall_Comp_OA_RES_CTRL_REG            (* (reg32 *) Hall_Comp_cy_psoc4_abuf__OA_RES_CTRL)
#define Hall_Comp_OA_RES_CTRL_PTR            (  (reg32 *) Hall_Comp_cy_psoc4_abuf__OA_RES_CTRL)

#define Hall_Comp_OA_COMP_STAT_REG           (* (reg32 *) Hall_Comp_cy_psoc4_abuf__COMP_STAT)
#define Hall_Comp_OA_COMP_STAT_PTR           (  (reg32 *) Hall_Comp_cy_psoc4_abuf__COMP_STAT)

#define Hall_Comp_OA_OFFSET_TRIM_REG         (* (reg32 *) Hall_Comp_cy_psoc4_abuf__OA_OFFSET_TRIM)
#define Hall_Comp_OA_OFFSET_TRIM_PTR         (  (reg32 *) Hall_Comp_cy_psoc4_abuf__OA_OFFSET_TRIM)

#define Hall_Comp_OA_SLOPE_OFFSET_TRIM_REG   (* (reg32 *) Hall_Comp_cy_psoc4_abuf__OA_SLOPE_OFFSET_TRIM)
#define Hall_Comp_OA_SLOPE_OFFSET_TRIM_PTR   (  (reg32 *) Hall_Comp_cy_psoc4_abuf__OA_SLOPE_OFFSET_TRIM)

#define Hall_Comp_OA_COMP_SHIFT              (Hall_Comp_cy_psoc4_abuf__COMP_STAT_SHIFT)

#define Hall_Comp_INTR_REG       (*(reg32 *)Hall_Comp_cy_psoc4_abuf__INTR)
#define Hall_Comp_INTR_PTR       ( (reg32 *)Hall_Comp_cy_psoc4_abuf__INTR)

#define Hall_Comp_INTR_SET_REG   (*(reg32 *)Hall_Comp_cy_psoc4_abuf__INTR_SET)
#define Hall_Comp_INTR_SET_PTR   ( (reg32 *)Hall_Comp_cy_psoc4_abuf__INTR_SET)

#define Hall_Comp_INTR_MASK_REG    (*(reg32 *)Hall_Comp_cy_psoc4_abuf__INTR_MASK) 
#define Hall_Comp_INTR_MASK_PTR    ( (reg32 *)Hall_Comp_cy_psoc4_abuf__INTR_MASK) 

#define Hall_Comp_INTR_MASKED_REG  (*(reg32 *)Hall_Comp_cy_psoc4_abuf__INTR_MASKED) 
#define Hall_Comp_INTR_MASKED_PTR  ( (reg32 *)Hall_Comp_cy_psoc4_abuf__INTR_MASKED)

/***************************************
*        Registers Constants
***************************************/

/* Hall_Comp_CTB_CTRL_REG */
#define Hall_Comp_CTB_CTRL_DEEPSLEEP_ON_SHIFT    (30u)   /* [30] Selects behavior CTB IP in the DeepSleep power mode */
#define Hall_Comp_CTB_CTRL_ENABLED_SHIFT         (31u)   /* [31] Enable of the CTB IP */

#define Hall_Comp_CTB_CTRL_DEEPSLEEP_ON          ((uint32) 0x01u << Hall_Comp_CTB_CTRL_DEEPSLEEP_ON_SHIFT)
#define Hall_Comp_CTB_CTRL_ENABLED               ((uint32) 0x01u << Hall_Comp_CTB_CTRL_ENABLED_SHIFT)

/* Hall_Comp_OA_RES_CTRL_REG */
#define Hall_Comp_OA_PWR_MODE_SHIFT          (0u)    /* [1:0]    Power level */
#define Hall_Comp_OA_COMP_EN_SHIFT           (4u)    /* [4]      Comparator enable */
#define Hall_Comp_OA_HYST_EN_SHIFT           (5u)    /* [5]      Hysteresis enable (10mV) */
#define Hall_Comp_OA_BYPASS_DSI_SYNC_SHIFT   (6u)    /* [6]      Bypass comparator output synchronization for DSI (trigger) output */
#define Hall_Comp_OA_COMPINT_SHIFT           (8u)    /* [9:8]    Sets Interrupt mode */
#define Hall_Comp_OA_PUMP_EN_SHIFT           (11u)   /* [11]     Pump enable */

#define Hall_Comp_OA_PWR_MODE                ((uint32) 0x02u << Hall_Comp_OA_PWR_MODE_SHIFT)
#define Hall_Comp_OA_PWR_MODE_MASK           ((uint32) 0x03u << Hall_Comp_OA_PWR_MODE_SHIFT)
#define Hall_Comp_OA_COMP_EN                 ((uint32) 0x01u << Hall_Comp_OA_COMP_EN_SHIFT)
#define Hall_Comp_OA_HYST_EN                 ((uint32) 0x01u << Hall_Comp_OA_HYST_EN_SHIFT)
#define Hall_Comp_OA_BYPASS_DSI_SYNC         ((uint32) 0x01u << Hall_Comp_OA_BYPASS_DSI_SYNC_SHIFT)
#define Hall_Comp_OA_COMPINT_MASK            ((uint32) 0x03u << Hall_Comp_OA_COMPINT_SHIFT)
#define Hall_Comp_OA_PUMP_EN                 ((uint32) 0x01u << Hall_Comp_OA_PUMP_EN_SHIFT)


/***************************************
*       Init Macros Definitions
***************************************/

#define Hall_Comp_GET_DEEPSLEEP_ON(deepSleep)    ((0u != (deepSleep)) ? (Hall_Comp_CTB_CTRL_DEEPSLEEP_ON) : (0u))
#define Hall_Comp_GET_OA_HYST_EN(hyst)           ((0u != (hyst)) ? (Hall_Comp_OA_HYST_EN) : (0u))
#define Hall_Comp_GET_OA_PWR_MODE(mode)          ((mode) & Hall_Comp_OA_PWR_MODE_MASK)
#define Hall_Comp_CHECK_PWR_MODE_OFF             (0u != (Hall_Comp_OA_RES_CTRL_REG & \
                                                                Hall_Comp_OA_PWR_MODE_MASK))
#define Hall_Comp_GET_OA_COMPINT(intType)        ((uint32) ((((uint32)(intType) << Hall_Comp_OA_COMPINT_SHIFT)) & \
                                                        Hall_Comp_OA_COMPINT_MASK))

#define Hall_Comp_GET_INTR_MASK(mask)            ((0u != (mask)) ? (Hall_Comp_INTR_MASK) : (0u))

/* Returns true if component available in Deep Sleep power mode*/ 
#define Hall_Comp_CHECK_DEEPSLEEP_SUPPORT        (0u != Hall_Comp_DEEPSLEEP_SUPPORT) 

#define Hall_Comp_DEFAULT_CTB_CTRL (Hall_Comp_GET_DEEPSLEEP_ON(Hall_Comp_DEEPSLEEP_SUPPORT) | \
                                           Hall_Comp_CTB_CTRL_ENABLED)

#define Hall_Comp_DEFAULT_OA_RES_CTRL (Hall_Comp_OA_COMP_EN | \
                                              Hall_Comp_GET_OA_HYST_EN(Hall_Comp_HYSTERESIS)  | \
                                              Hall_Comp_GET_OA_COMPINT(Hall_Comp_INTERRUPT) |\
                                              Hall_Comp_OA_BYPASS_DSI_SYNC)

#define Hall_Comp_INTR_MASK_REG_DEFAULT  (Hall_Comp_GET_INTR_MASK(Hall_Comp_INTERRUPT_EN))


/***************************************
* The following code is DEPRECATED and 
* should not be used in new projects.
***************************************/

/* Power constants for SetSpeed() function */
#define Hall_Comp_SLOWSPEED      (Hall_Comp_SLOW_SPEED)
#define Hall_Comp_MEDSPEED       (Hall_Comp_MED_SPEED)
#define Hall_Comp_HIGHSPEED      (Hall_Comp_HIGH_SPEED)

#define Hall_Comp_OA_CTRL_REG        (Hall_Comp_OA_RES_CTRL_REG)
#define Hall_Comp_OA_COMPSTAT_REG    (Hall_Comp_OA_COMP_STAT_REG)
#define Hall_Comp_OA_COMPSHIFT       (Hall_Comp_OA_COMP_SHIFT)

#define Hall_Comp_OA_CTB_EN_SHIFT    (Hall_Comp_CTB_CTRL_ENABLED_SHIFT)
#define Hall_Comp_OA_PWR_MODE_HIGH   (Hall_Comp_HIGH_SPEED) 
#define Hall_Comp_OA_BYPASS_SHIFT    (Hall_Comp_OA_BYPASS_DSI_SYNC_SHIFT)

#endif /*  CY_COMPARATOR_Hall_Comp_H */


/* [] END OF FILE */
