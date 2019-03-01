/****************************************************************
* 说明: 芯片的管脚复用功能设置，以及设置管脚的上下拉功能
*       管脚复用查询User manual中的<IOCON function assignments>表格
* 搬运: 1209实验室@ujn
* 修改: 2018-11-30
*****************************************************************/
#include "chip.h"
#include "E3V_iocon_11u6x.h"

/****************************************************************
* 功能: 设置管脚的功能以及模式,使用管脚之前应先调用这个函数
* 参数: 
* IN - port - 端口号,取值参考枚举变量 PORTn_e
* IN - pin  - 管脚号,取值参考枚举变量 PINn_e
* IN - func_mode - 管脚功能和模式的可选项,取值参考枚举变量FUNC_MODE_e
* 修改: 2018-12-05
*****************************************************************/
void E3V_pin_init(PORTn_e port, PINn_e pin, uint32_t func_mode)
{
	switch (port) {
	case PORT0:
		LPC_IOCON->PIO0[pin] = func_mode;
		break;

	case PORT1:
		LPC_IOCON->PIO1[pin] = func_mode;
		break;

	case PORT2:
		if (pin >= 2) {
			LPC_IOCON->PIO2B[pin - 2] = func_mode;
		}
		else {
			LPC_IOCON->PIO2A[pin] = func_mode;
		}
		break;

	default:
		break;
	}
}

/****************************************************************
* 功能: 通过一个参数数组,设置多个管脚的功能以及模式
* 参数: 
* IN - pinArray    - 事先定义的参数数组的首地址
* IN - arrayLength - 参数数组的长度
* 修改: 2018-12-05
*****************************************************************/
void E3V_pin_group_init(const PINMUX_GRP_T* pinArray, uint32_t arrayLength)
{
	uint32_t ix;

	for (ix = 0; ix < arrayLength; ix++ )
	{
		E3V_pin_init((PORTn_e)pinArray[ix].port, (PINn_e)pinArray[ix].pin, (uint32_t)pinArray[ix].modefunc);
	}
}


/****************************************************************
* 功能: 读取指定管脚的配置信息
* 参数: 
* IN - port - 端口号,取值参考枚举变量 PORTn_e
* IN - pin  - 管脚号,取值参考枚举变量 PINn_e
* RETURN - 返回指定管脚的配置信息
* 修改: 2018-12-05
*****************************************************************/
uint32_t E3V_get_pinmux(PORTn_e port, PINn_e pin)
{
	uint32_t iocon_value = 0;
	switch (port) {
	case PORT0:
		iocon_value = LPC_IOCON->PIO0[pin];
		break;

	case PORT1:
		iocon_value = LPC_IOCON->PIO1[pin];
		break;

	case PORT2:
		if (pin >= 2) {
			iocon_value = LPC_IOCON->PIO2B[pin - 2];
		}
		else {
			iocon_value = LPC_IOCON->PIO2A[pin];
		}
		break;

	default:
		break;
	}
	return iocon_value;
}
