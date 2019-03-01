/**************************************************************************//**
 * @file     system_LPC11Uxx.h
 * @brief    CMSIS Cortex-M0 Device Peripheral Access Layer Header File
 *           for the NXP LPC11Uxx Device Series
 * @version  V1.10
 * @date     24. November 2010
 *
 * @note
 * Copyright (C) 2009-2010 ARM Limited. All rights reserved.
 *
 * @par
 * ARM Limited (ARM) is supplying this software for use with Cortex-M 
 * processor based microcontrollers.  This file can be freely distributed 
 * within development tools that are supporting such ARM based processors. 
 *
 * @par
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * ARM SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR
 * CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 ******************************************************************************/


#ifndef __E3V_SYSINIT_11U6X_H_
#define __E3V_SYSINIT_11U6X_H_

#ifdef __cplusplus
extern "C" {
#endif

/*用户可选的main_clock*/
typedef enum
{
    MAIN_CLOCK_24M = 24,
    MAIN_CLOCK_36M = 36,
    MAIN_CLOCK_48M = 48,
    MAIN_CLOCK_60M = 60,
    MAIN_CLOCK_72M = 72,
    MAIN_CLOCK_84M = 84,

} MAIN_CLOCK_e;

extern uint32_t SystemCoreClock;     /*!< System Clock Frequency (Core Clock)  */

/****************************************************************
* 功能:启动代码会调用这个函数，进行时钟初始化
       初始化PLL得到main_clock,并将其分频得到system_clock
* 参数:无
* 修改:2018-11-28
*****************************************************************/
extern void SystemInit (void);


extern void SystemCoreClockUpdate (void);


#ifdef __cplusplus
}
#endif

#endif /* __E3V_SYSINIT_11U6X_H_ */
