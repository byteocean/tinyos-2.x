/******************** (C) COPYRIGHT 2007 STMicroelectronics ********************
* File Name          : stm32f10x_pwr.h
* Author             : MCD Application Team
* Version            : V1.0
* Date               : 10/08/2007
* Description        : This file contains all the functions prototypes for the
*                      PWR firmware library.
********************************************************************************
* THE PRESENT SOFTWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE TIME.
* AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY DIRECT,
* INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE
* CONTENT OF SUCH SOFTWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING
* INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
*******************************************************************************/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM32F10x_PWR_H
#define __STM32F10x_PWR_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x_map.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* PVD detection level */
#define PWR_PVDLevel_2V2          ((uint32_t)0x00000000)
#define PWR_PVDLevel_2V3          ((uint32_t)0x00000020)
#define PWR_PVDLevel_2V4          ((uint32_t)0x00000040)
#define PWR_PVDLevel_2V5          ((uint32_t)0x00000060)
#define PWR_PVDLevel_2V6          ((uint32_t)0x00000080)
#define PWR_PVDLevel_2V7          ((uint32_t)0x000000A0)
#define PWR_PVDLevel_2V8          ((uint32_t)0x000000C0)
#define PWR_PVDLevel_2V9          ((uint32_t)0x000000E0)

#define IS_PWR_PVD_LEVEL(LEVEL) ((LEVEL == PWR_PVDLevel_2V2) || (LEVEL == PWR_PVDLevel_2V3)|| \
                                 (LEVEL == PWR_PVDLevel_2V4) || (LEVEL == PWR_PVDLevel_2V5)|| \
                                 (LEVEL == PWR_PVDLevel_2V6) || (LEVEL == PWR_PVDLevel_2V7)|| \
                                 (LEVEL == PWR_PVDLevel_2V8) || (LEVEL == PWR_PVDLevel_2V9))

/* Regulator state is STOP mode */
#define PWR_Regulator_ON          ((uint32_t)0x00000000)
#define PWR_Regulator_LowPower    ((uint32_t)0x00000001)

#define IS_PWR_REGULATOR(REGULATOR) ((REGULATOR == PWR_Regulator_ON) || \
                                     (REGULATOR == PWR_Regulator_LowPower))

/* STOP mode entry */
#define PWR_STOPEntry_WFI         ((uint8_t)0x01)
#define PWR_STOPEntry_WFE         ((uint8_t)0x02)

#define IS_PWR_STOP_ENTRY(ENTRY) ((ENTRY == PWR_STOPEntry_WFI) || (ENTRY == PWR_STOPEntry_WFE))
 
/* PWR Flag */
#define PWR_FLAG_WU               ((uint32_t)0x00000001)
#define PWR_FLAG_SB               ((uint32_t)0x00000002)
#define PWR_FLAG_PVDO             ((uint32_t)0x00000004)

#define IS_PWR_GET_FLAG(FLAG) ((FLAG == PWR_FLAG_WU) || (FLAG == PWR_FLAG_SB) || \
                               (FLAG == PWR_FLAG_PVDO))
#define IS_PWR_CLEAR_FLAG(FLAG) ((FLAG == PWR_FLAG_WU) || (FLAG == PWR_FLAG_SB))

/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
void PWR_DeInit(void);
void PWR_BackupAccessCmd(FunctionalState NewState);
void PWR_PVDCmd(FunctionalState NewState);
void PWR_PVDLevelConfig(uint32_t PWR_PVDLevel);
void PWR_WakeUpPinCmd(FunctionalState NewState);
void PWR_EnterSTOPMode(uint32_t PWR_Regulator, uint8_t PWR_STOPEntry);
void PWR_EnterSTANDBYMode(void);
FlagStatus PWR_GetFlagStatus(uint32_t PWR_FLAG);
void PWR_ClearFlag(uint32_t PWR_FLAG);

#endif /* __STM32F10x_PWR_H */

/******************* (C) COPYRIGHT 2007 STMicroelectronics *****END OF FILE****/