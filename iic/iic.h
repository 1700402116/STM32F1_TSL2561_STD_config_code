#ifndef __IIC_H
#define __IIC_H

//SDA接GPIO_Pin_11
//SCL接GPIO_Pin_10

#include "stm32f10x.h"
#define SDA_PORT	GPIO_Pin_11
#define SCL_PORT	GPIO_Pin_10
#define IIC_PORT	GPIOB

#define SDA_DATA(a)	if (a)	\
							GPIO_SetBits(IIC_PORT,SDA_PORT);\
							else		\
							GPIO_ResetBits(IIC_PORT,SDA_PORT)
							
#define SCL_OUT(a)	if (a)	\
							GPIO_SetBits(IIC_PORT,SCL_PORT);\
							else		\
							GPIO_ResetBits(IIC_PORT,SCL_PORT)														
							
#define SDA_IO_IN      GPIO_ReadInputDataBit(IIC_PORT,SDA_PORT)


//IIC所有操作函数
void IIC_Init(void);                //初始化IIC的IO口	
void SDA_OUT(void);
void SDA_IN(void);			 
void IIC_Start(void);				//发送IIC开始信号
void IIC_Stop(void);	  			//发送IIC停止信号
void IIC_Send_Byte(u8 txd);			//IIC发送一个字节
u16 IIC_Read_Byte(unsigned char ack);//IIC读取一个字节
u8 IIC_Wait_Ack(void); 				//IIC等待ACK信号
void IIC_Ack(void);					//IIC发送ACK信号
void IIC_NAck(void);				//IIC不发送ACK信号
void IIC_Write_One_Byte(u8 daddr,u8 addr,u8 data);
u8 IIC_Read_One_Byte(u8 daddr,u8 addr);	 

 
#endif

