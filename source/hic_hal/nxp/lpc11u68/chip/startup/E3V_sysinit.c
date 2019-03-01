/****************************************************************
* 说明: 系统时钟初始化
* 搬运: 1209实验室@ujn
* 修改: 2018-11-28
*****************************************************************/
 #include "board.h"
 #include "E3V_user_cfg.h"
 #include "E3V_sysinit_11u6x.h"


/****************************************************************
* 功能:初始化PLL得到main_clock,并将其分频得到system_clock
* 参数:无
* 修改:2018-11-28
*****************************************************************/
void E3V_sysclock_init(void)
{
#if   defined(E3V_PLL_USE_IRC)
    E3V_irc_pll_init(E3V_MAIN_CLOCK_MHZ);
      
#elif   defined(E3V_PLL_USE_XTAL_12M)
    E3V_xtal_pll_init(E3V_MAIN_CLOCK_MHZ);

#else  
    E3V_irc_pll_init(E3V_MAIN_CLOCK_MHZ);
    
#endif    
    E3V_set_systemclock(E3V_SYSClK_DIV);
}

/****************************************************************
* 功能:启动代码会调用这个函数，进行时钟初始化
* 参数:无
* 修改:2018-11-28
*****************************************************************/
void SystemInit(void)
{
    
    E3V_sysclock_init();
    
}

