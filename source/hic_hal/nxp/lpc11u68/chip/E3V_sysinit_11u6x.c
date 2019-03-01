/****************************************************************
* 说明: LPC11u6x芯片的锁相环pll初始化以及system clock设定
*       main clock不得超过100M,system clock不得超过50M
* 搬运: 1209实验室@ujn
* 修改: 2018-11-28
*****************************************************************/
#include "E3V_sysinit_11u6x.h"
#include "E3V_iocon_11u6x.h"

/****************************************************************
* 功能:PLL对内部振荡器IRC倍频，得到预设的main_clock
* 参数:IN - mainclock - 用户需求的main_clock大小
* 修改:2018-11-28
*****************************************************************/
void E3V_irc_pll_init(MAIN_CLOCK_e mainclock)
{
    /* 启用IRC*/
    Chip_SYSCTL_PowerUp(SYSCTL_POWERDOWN_IRC_PD);

    /* 选择IRC作为PLL的输入 */
    Chip_Clock_SetSystemPLLSource(SYSCTL_PLLCLKSRC_IRC);

    /* 选择访问flash的时钟 */
    Chip_FMC_SetFLASHAccess(FLASHTIM_3CLK_CPU);

    /* 先关闭PLL,再设置PLL分频比 */
    Chip_SYSCTL_PowerDown(SYSCTL_POWERDOWN_SYSPLL_PD);

    /* M = msel + 1
     * P = 2^psel = 1,2,4,8 (pesl = 0,1,2,3)
     * FCLKOUT = FCLKIN * M = 12MHz * M
     * FCCO = FCLKOUT * 2 * P (FCCO range in 156 to 320 MHz)        
     */
    switch (mainclock)
    {
    case MAIN_CLOCK_24M:
        Chip_Clock_SetupSystemPLL(1, 2);    //M = 2, P = 4
        break;
    case MAIN_CLOCK_36M:
        Chip_Clock_SetupSystemPLL(2, 2);    //M = 3, P = 4
        break;
    case MAIN_CLOCK_48M:
        Chip_Clock_SetupSystemPLL(3, 1);    //M = 4, P = 2
        break;
    case MAIN_CLOCK_60M:
        Chip_Clock_SetupSystemPLL(4, 2);    //M = 5, P = 4
        break;
    case MAIN_CLOCK_72M:
        Chip_Clock_SetupSystemPLL(5, 1);    //M = 6, P = 2
        break;
    case MAIN_CLOCK_84M:
        Chip_Clock_SetupSystemPLL(6, 0);    //M = 7, P = 1
        break;        
    default:
        break;
    }

    /* 启用PLL */
    Chip_SYSCTL_PowerUp(SYSCTL_POWERDOWN_SYSPLL_PD);

    /* Wait for PLL to lock */
    while (!Chip_Clock_IsSystemPLLLocked()){}

 }


/****************************************************************
* 功能:PLL对外部晶振倍频，得到预设的main_clock
* 参数:IN - mainclock - 用户需求的main_clock大小
* 修改:2018-11-28
*****************************************************************/
void E3V_xtal_pll_init(MAIN_CLOCK_e mainclock)
{
	volatile int i;

    /* 初始化外部晶振管脚: 
     * PIO2_0 -> XTALIN 
     * PIO2_1 -> XTALOUT 
     */
    Chip_Clock_EnablePeriphClock(SYSCTL_CLOCK_IOCON);
    E3V_pin_init(PORT2, PIN_0, PIN_FUNC1);
    E3V_pin_init(PORT2, PIN_1, PIN_FUNC1 | PIN_MODE_INACT);

	/* Powerup main oscillator */
	Chip_SYSCTL_PowerUp(SYSCTL_POWERDOWN_SYSOSC_PD);

	/* 延时等待至少580us来让osc稳定 ，参考RM的<4.4.48 Power configuration register>章节 */
	for (i = 0; i < 2500; i++) {}

	/* Set system PLL input to main oscillator */
	Chip_Clock_SetSystemPLLSource(SYSCTL_PLLCLKSRC_MAINOSC);

	/* 选择访问flash的时钟 */
	Chip_FMC_SetFLASHAccess(FLASHTIM_3CLK_CPU);

	/* 先关闭PLL,再设置PLL分频比 */
	Chip_SYSCTL_PowerDown(SYSCTL_POWERDOWN_SYSPLL_PD);

    /* M = msel + 1
     * P = 2^psel = 1,2,4,8 (pesl = 0,1,2,3)
     * FCLKOUT = FCLKIN * M = 12MHz * M
     * FCCO = FCLKOUT * 2 * P (FCCO range in 156 to 320 MHz)        
     */
    switch (mainclock)
    {
    case MAIN_CLOCK_24M:
        Chip_Clock_SetupSystemPLL(1, 2);    //M = 2, P = 4
        break;
    case MAIN_CLOCK_36M:
        Chip_Clock_SetupSystemPLL(2, 2);    //M = 3, P = 4
        break;
    case MAIN_CLOCK_48M:
        Chip_Clock_SetupSystemPLL(3, 1);    //M = 4, P = 2
        break;
    case MAIN_CLOCK_60M:
        Chip_Clock_SetupSystemPLL(4, 2);    //M = 5, P = 4
        break;
    case MAIN_CLOCK_72M:
        Chip_Clock_SetupSystemPLL(5, 1);    //M = 6, P = 2
        break;
    case MAIN_CLOCK_84M:
        Chip_Clock_SetupSystemPLL(6, 0);    //M = 7, P = 1
        break;        
    default:
        break;
    }

	/* 启用PLL */
	Chip_SYSCTL_PowerUp(SYSCTL_POWERDOWN_SYSPLL_PD);

	/* Wait for PLL to lock */
	while (!Chip_Clock_IsSystemPLLLocked()) {}

}


/****************************************************************
* 功能: 通过对main_clock分频得到system_clock(不得超过50MHz)
* 参数: IN - Div - 分频系数，取值1~255
* 修改: 2018-11-28
*****************************************************************/
void E3V_set_systemclock(uint8_t Div)
{
	/* 系数为1~255, system_clock = main_clock/Div */
	Chip_Clock_SetSysClockDiv(Div);

	/* 选择PLL作为main clock源 */
	Chip_Clock_SetMainClockSource(SYSCTL_MAINCLKSRC_PLLOUT);
}