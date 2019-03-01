/****************************************************************
* 说明: 芯片的管脚复用功能设置，以及设置管脚的上下拉功能
*       管脚复用查询User manual中的<IOCON function assignments>表格
* 搬运: 1209实验室@ujn
* 修改: 2018-11-30
*****************************************************************/
#ifndef __E3V_IOCON_11U6X_H_
#define __E3V_IOCON_11U6X_H_
#include "chip.h"

/**
 * @brief LPC11u6x IO Configuration Unit register block structure
 */
typedef struct {			/*!< LPC11U6X IOCON Structure */
	__IO uint32_t  PIO0[24];
	__IO uint32_t  PIO1[32];
	__I  uint32_t  reserved[4];
	__IO uint32_t  PIO2A[2];/* PIO2_0/1 only */
	__I  uint32_t  reserved1[1];
	__IO uint32_t  PIO2B[22];	/* PIO2_2 to PIO_2_23 */
} LPC_IOCON_T;

/** 
 * @brief Array of IOCON pin definitions passed to Chip_IOCON_SetPinMuxing() must be in this format 
 */ 
typedef struct {
	uint32_t port : 8;			/* Pin port */
	uint32_t pin : 8;			/* Pin number */
	uint32_t modefunc : 16;		/* Function and mode */
} PINMUX_GRP_T;

/******************************************************************************/
/*! 管脚复用功能选择,具体功能需要查询User manual中的<IOCON function assignments>表格 */
#define  PIN_FUNC0             0x0 
#define  PIN_FUNC1             0x1              
#define  PIN_FUNC2             0x2             
#define  PIN_FUNC3             0x3             
#define  PIN_FUNC4             0x4             
#define  PIN_FUNC5             0x5  
         /*! 可选择的管脚模式 */
#define  PIN_MODE_INACT        (0x0 << 3)         /*!< 无附加引脚功能 */
#define  PIN_MODE_PULLDOWN     (0x1 << 3)         /*!< 选择下拉功能 */
#define  PIN_MODE_PULLUP       (0x2 << 3)         /*!< 选择上拉功能 */
#define  PIN_MODE_REPEATER     (0x3 << 3)         /*!< 选择中继器模式 */
#define  PIN_HYS_EN            (0x1 << 5)         /*!< 使能迟滞 */
#define  PIN_INV_EN            (0x1 << 6)         /*!< 使能反转输入 */
#define  PIN_ADMODE_EN         (0x0 << 7)         /*!< 使能模拟输入功能(只支持模拟引脚) */
#define  PIN_DIGMODE_EN        (0x1 << 7)         /*!< 使能数字功能(只支持模拟引脚) */
#define  PIN_SFI2C_EN          (0x0 << 8)         /*!< I2C standard mode/fast-mode */
#define  PIN_STDI2C_EN         (0x1 << 8)         /*!< I2C标准I/O功能 */
#define  PIN_FASTI2C_EN        (0x2 << 8)         /*!< I2C快速模式 Plus */
#define  PIN_FILT_DIS          (0x1 << 8)         /*!< Disables noise pulses filtering (10nS glitch filter) */
#define  PIN_OPENDRAIN_EN      (0x1 << 10)        /*!< 使能开漏 */
         /*! 数字滤波器采样模式 */
#define  PIN_S_MODE_0CLK       (0x0 << 11)        /*!< 旁路输入滤波器 */
#define  PIN_S_MODE_1CLK       (0x1 << 11)        /*!< 1个时钟周期。拒绝短于1个滤波器时钟的输入脉冲 */
#define  PIN_S_MODE_2CLK       (0x2 << 11)        /*!< 2个时钟周期。拒绝短于2个滤波器时钟的输入脉冲 */
#define  PIN_S_MODE_3CLK       (0x3 << 11)        /*!< 3个时钟周期。拒绝短于3个滤波器时钟的输入脉冲 */
         /*! 选择外设时钟分频器用于输入滤波器采样时钟*/
#define  PIN_CLKDIV_0          (0x0 << 13)        /*!< Select clock divider 0 */
#define  PIN_CLKDIV_1          (0x1 << 13)        /*!< Select clock divider 1 */
#define  PIN_CLKDIV_2          (0x2 << 13)        /*!< Select clock divider 2 */
#define  PIN_CLKDIV_3          (0x3 << 13)        /*!< Select clock divider 3 */
#define  PIN_CLKDIV_4          (0x4 << 13)        /*!< Select clock divider 4 */
#define  PIN_CLKDIV_5          (0x5 << 13)        /*!< Select clock divider 5 */
#define  PIN_CLKDIV_6          (0x6 << 13)        /*!< Select clock divider 6 */

/******************************************************************************/

/*! 枚举端口编号 */
typedef enum
{
    PORT0 = 0,
    PORT1 = 1,
    PORT2 = 2,

} PORTn_e;

/*! 枚举管脚编号 */
typedef enum
{
    /*  管脚编号0~23  */
   PIN_0,  PIN_1,  PIN_2,  PIN_3,  PIN_4,  PIN_5,  PIN_6,  PIN_7,  
   PIN_8,  PIN_9,  PIN_10, PIN_11, PIN_12, PIN_13, PIN_14, PIN_15, 
   PIN_16, PIN_17, PIN_18, PIN_19, PIN_20, PIN_21, PIN_22, PIN_23,

} PINn_e;


/****************************************************************
* 说明:外部可调用的API
* 修改:2018-11-30
*****************************************************************/
void E3V_pin_init(PORTn_e port, PINn_e pin, uint32_t func_mode);
void E3V_pin_group_init(const PINMUX_GRP_T* pinArray, uint32_t arrayLength);
uint32_t E3V_get_pinmux(PORTn_e port, PINn_e pin);


#endif
