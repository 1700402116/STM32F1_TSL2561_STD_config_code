#ifndef __TSL2561_H
#define __TSL2561_H
#include "sys.h"
#include "iic.h"
#include "math.h"

#define TSL2561_ADDR0 0x29 // address with '0' shorted on board
#define TSL2561_ADDR  0x39 // default address
#define TSL2561_ADDR1 0x49 // address with '1' shorted on board

#define RD	0x01
#define WR	0x00
#define CTR_POWERUP 	0x03
#define CTR_POWEROFF	0x00

// TSL2561 registers: 				1000 000x
#define TSL2561_CTR           0x80
#define TSL2561_TIMING        0x81
#define	TSL2561_REG_ID        0x8A
#define	TSL2561_DATA0_LOW     0x8C
#define TSL2561_DATA0_HIGH    0x8D
#define	TSL2561_DATA1_LOW     0x8E
#define TSL2561_DATA1_HIGH    0x8F


//Timing Register Value.Set integration time
                                      //最后两位设置积分时间
#define  TIMING_13MS         0x00     //积分时间13.7毫秒
#define  TIMING_101MS        0x01     //积分时间101毫秒
#define  TIMING_402MS        0x02     //积分时间402毫秒
#define  TIMING_GAIN_1X      0x10     //增益倍数与积分时间进行或运算
#define  TIMING_GAIN_16X     0x00 

#define IIC_SCL_Pin  GPIO_Pin_9
#define IIC_SDA_Pin  GPIO_Pin_8
#define GPIO_IIC     GPIOB
#define RCC_APB2Periph_GPIOIIC RCC_APB2Periph_GPIOB                                             
 
#define IIC_SDA_OUT()  {GPIOB->CRH&=0XFFFFFFF0;GPIOB->CRH|=0x00000003;} 
#define IIC_SDA_IN()   {GPIOB->CRH&=0XFFFFFFF0;GPIOB->CRH|=0x00000008;}        
 
#define SDA_PIN_OUT       PBout(8)
#define SCL_PIN_OUT       PBout(9)
#define SDA_PIN_IN        PBin(8)

int TSL2561_Init();
float get_lux();
float Lux_Calc(float CH0, float CH1);
#endif