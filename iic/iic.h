#ifndef __IIC_H
#define __IIC_H

//SDA��GPIO_Pin_11
//SCL��GPIO_Pin_10

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


//IIC���в�������
void IIC_Init(void);                //��ʼ��IIC��IO��	
void SDA_OUT(void);
void SDA_IN(void);			 
void IIC_Start(void);				//����IIC��ʼ�ź�
void IIC_Stop(void);	  			//����IICֹͣ�ź�
void IIC_Send_Byte(u8 txd);			//IIC����һ���ֽ�
u16 IIC_Read_Byte(unsigned char ack);//IIC��ȡһ���ֽ�
u8 IIC_Wait_Ack(void); 				//IIC�ȴ�ACK�ź�
void IIC_Ack(void);					//IIC����ACK�ź�
void IIC_NAck(void);				//IIC������ACK�ź�
void IIC_Write_One_Byte(u8 daddr,u8 addr,u8 data);
u8 IIC_Read_One_Byte(u8 daddr,u8 addr);	 

 
#endif

