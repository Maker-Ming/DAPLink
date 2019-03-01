/****************************************************************
* 说明: LPC11u6x芯片的锁相环pll初始化以及system clock设定
*       注意main clock不得超过100M,system clock不得超过50M
* 搬运: 1209实验室@ujn
* 修改: 2018-11-28
*****************************************************************/
#ifndef __E3V_SYSINIT_11U6X_H_
#define __E3V_SYSINIT_11U6X_H_
#include "chip.h"

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

/****************************************************************
* 说明: 外部可调用的API
* 修改: 2018-11-30
*****************************************************************/
void E3V_irc_pll_init(MAIN_CLOCK_e mainclock);
void E3V_xtal_pll_init(MAIN_CLOCK_e mainclock);
void E3V_set_systemclock(uint8_t Div);

#endif