/*******************************************************************************
* File Name: Opamp_B.h
* Version 1.10
*
* Description:
*  This file contains the function prototypes and constants used in
*  the Opamp (Analog Buffer) Component.
*
*
********************************************************************************
* Copyright 2013-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/


#if !defined(CY_OPAMP_Opamp_B_H)
#define CY_OPAMP_Opamp_B_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*       Type Definitions
***************************************/

/* Structure to save state before go to sleep */
typedef struct
{
    uint8  enableState;
} Opamp_B_BACKUP_STRUCT;


/**************************************
*        Function Prototypes
**************************************/
void Opamp_B_Init(void);
void Opamp_B_Enable(void);
void Opamp_B_Start(void);
void Opamp_B_Stop(void);
void Opamp_B_SetPower(uint32 power);
void Opamp_B_PumpControl(uint32 onOff);
void Opamp_B_Sleep(void);
void Opamp_B_Wakeup(void);
void Opamp_B_SaveConfig(void);
void Opamp_B_RestoreConfig(void);


/**************************************
*           API Constants
**************************************/

/* Parameters for SetPower() function */
#define Opamp_B_LOW_POWER      (1u)
#define Opamp_B_MED_POWER      (2u)
#define Opamp_B_HIGH_POWER     (3u)


/* Parameters for PumpControl() function */
#define Opamp_B_PUMP_ON        (1u)
#define Opamp_B_PUMP_OFF       (0u)


/***************************************
*   Initial Parameter Constants
****************************************/

#define Opamp_B_OUTPUT_CURRENT         (1u)
#define Opamp_B_POWER                  (2u)
#define Opamp_B_MODE                   (0u)
#define Opamp_B_OA_COMP_TRIM_VALUE     (1u)
#define Opamp_B_DEEPSLEEP_SUPPORT      (0u)


/***************************************
*    Variables with External Linkage
***************************************/

extern uint8  Opamp_B_initVar;


/**************************************
*             Registers
**************************************/
#define Opamp_B_CTB_CTRL_REG       (*(reg32 *) Opamp_B_cy_psoc4_abuf__CTBM_CTB_CTRL)
#define Opamp_B_CTB_CTRL_PTR       ( (reg32 *) Opamp_B_cy_psoc4_abuf__CTBM_CTB_CTRL)
#define Opamp_B_OA_RES_CTRL_REG    (*(reg32 *) Opamp_B_cy_psoc4_abuf__OA_RES_CTRL)
#define Opamp_B_OA_RES_CTRL_PTR    ( (reg32 *) Opamp_B_cy_psoc4_abuf__OA_RES_CTRL)
#define Opamp_B_OA_COMP_TRIM_REG   (*(reg32 *) Opamp_B_cy_psoc4_abuf__OA_COMP_TRIM)
#define Opamp_B_OA_COMP_TRIM_PTR   ( (reg32 *) Opamp_B_cy_psoc4_abuf__OA_COMP_TRIM)


/***************************************
*        Registers Constants
***************************************/

/* Opamp_B_CTB_CTRL_REG */
#define Opamp_B_CTB_CTRL_DEEPSLEEP_ON_SHIFT    (30u)   /* [30] Selects behavior CTB IP in the DeepSleep power mode */
#define Opamp_B_CTB_CTRL_ENABLED_SHIFT         (31u)   /* [31] Enable of the CTB IP */


#define Opamp_B_CTB_CTRL_DEEPSLEEP_ON          ((uint32) 0x01u << Opamp_B_CTB_CTRL_DEEPSLEEP_ON_SHIFT)
#define Opamp_B_CTB_CTRL_ENABLED               ((uint32) 0x01u << Opamp_B_CTB_CTRL_ENABLED_SHIFT)


/* Opamp_B_OA_RES_CTRL_REG */
#define Opamp_B_OA_PWR_MODE_SHIFT          (0u)    /* [1:0]    Power level */
#define Opamp_B_OA_DRIVE_STR_SEL_SHIFT     (2u)    /* [2]      Opamp output strenght select: 0 - 1x, 1 - 10x */
#define Opamp_B_OA_COMP_EN_SHIFT           (4u)    /* [4]      CTB IP mode: 0 - Opamp, 1 - Comparator  */
#define Opamp_B_OA_PUMP_EN_SHIFT           (11u)   /* [11]     Pump enable */


#define Opamp_B_OA_PWR_MODE                ((uint32) 0x02u << Opamp_B_OA_PWR_MODE_SHIFT)
#define Opamp_B_OA_PWR_MODE_MASK           ((uint32) 0x03u << Opamp_B_OA_PWR_MODE_SHIFT)
#define Opamp_B_OA_DRIVE_STR_SEL_1X        ((uint32) 0x00u << Opamp_B_OA_DRIVE_STR_SEL_SHIFT)
#define Opamp_B_OA_DRIVE_STR_SEL_10X       ((uint32) 0x01u << Opamp_B_OA_DRIVE_STR_SEL_SHIFT)
#define Opamp_B_OA_DRIVE_STR_SEL_MASK      ((uint32) 0x01u << Opamp_B_OA_DRIVE_STR_SEL_SHIFT)
#define Opamp_B_OA_COMP_EN                 ((uint32) 0x00u << Opamp_B_OA_COMP_EN_SHIFT)
#define Opamp_B_OA_PUMP_EN                 ((uint32) 0x01u << Opamp_B_OA_PUMP_EN_SHIFT)


/***************************************
*       Init Macros Definitions
***************************************/

#define Opamp_B_GET_DEEPSLEEP_ON(deepSleep)    ((0u != (deepSleep)) ? (Opamp_B_CTB_CTRL_DEEPSLEEP_ON) : (0u))
#define Opamp_B_GET_OA_DRIVE_STR(current)      ((0u != (current)) ? (Opamp_B_OA_DRIVE_STR_SEL_10X) : \
                                                                             (Opamp_B_OA_DRIVE_STR_SEL_1X))
#define Opamp_B_GET_OA_PWR_MODE(mode)          ((mode) & Opamp_B_OA_PWR_MODE_MASK)
#define Opamp_B_CHECK_PWR_MODE_OFF             (0u != (Opamp_B_OA_RES_CTRL_REG & \
                                                                Opamp_B_OA_PWR_MODE_MASK))

/* Returns true if component available in Deep Sleep power mode*/ 
#define Opamp_B_CHECK_DEEPSLEEP_SUPPORT        (0u != Opamp_B_DEEPSLEEP_SUPPORT) 

#define Opamp_B_DEFAULT_CTB_CTRL (Opamp_B_GET_DEEPSLEEP_ON(Opamp_B_DEEPSLEEP_SUPPORT) | \
                                           Opamp_B_CTB_CTRL_ENABLED)

#define Opamp_B_DEFAULT_OA_RES_CTRL (Opamp_B_OA_COMP_EN | \
                                              Opamp_B_GET_OA_DRIVE_STR(Opamp_B_OUTPUT_CURRENT))

#define Opamp_B_DEFAULT_OA_COMP_TRIM_REG (Opamp_B_OA_COMP_TRIM_VALUE)


/***************************************
* The following code is DEPRECATED and 
* should not be used in new projects.
***************************************/

#define Opamp_B_LOWPOWER                   (Opamp_B_LOW_POWER)
#define Opamp_B_MEDPOWER                   (Opamp_B_MED_POWER)
#define Opamp_B_HIGHPOWER                  (Opamp_B_HIGH_POWER)

/* PUMP ON/OFF defines */
#define Opamp_B_PUMPON                     (Opamp_B_PUMP_ON)
#define Opamp_B_PUMPOFF                    (Opamp_B_PUMP_OFF)

#define Opamp_B_OA_CTRL                    (Opamp_B_CTB_CTRL_REG)
#define Opamp_B_OA_RES_CTRL                (Opamp_B_OA_RES_CTRL_REG)

/* Bit Field  OA_CTRL */
#define Opamp_B_OA_CTB_EN_SHIFT            (Opamp_B_CTB_CTRL_ENABLED_SHIFT)
#define Opamp_B_OA_PUMP_CTRL_SHIFT         (Opamp_B_OA_PUMP_EN_SHIFT)
#define Opamp_B_OA_PUMP_EN_MASK            (0x800u)
#define Opamp_B_PUMP_PROTECT_MASK          (1u)


#endif    /* CY_OPAMP_Opamp_B_H */


/* [] END OF FILE */
