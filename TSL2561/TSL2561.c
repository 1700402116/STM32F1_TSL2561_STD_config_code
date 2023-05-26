#include "TSL2561.h"

int TSL2561_Init(){
	unsigned char modified_addr;
	// get access to this chip, current Addr: 0x39
	IIC_Start();
	modified_addr = (TSL2561_ADDR<<1)|WR;
	IIC_Send_Byte(modified_addr);
	IIC_Wait_Ack();
	// write command to control, activate ADC
	IIC_Send_Byte(TSL2561_CTR);
	IIC_Wait_Ack();
	IIC_Send_Byte(CTR_POWERUP);

	return 0;
}

float get_lux(){
	float result;
	unsigned char modified_addr;
	unsigned char CH0L;
	unsigned char CH0H;
	unsigned char CH1L;
	unsigned char CH1H;
	int	CH0;
	int CH1;
	// get access to this chip, current Addr: 0x39
	modified_addr = (TSL2561_ADDR<<1)|WR;
	IIC_Start();
	IIC_Send_Byte(modified_addr);	
	IIC_Wait_Ack();
	// get access to ADC channel 0 LB
	IIC_Send_Byte(TSL2561_DATA0_LOW);	
	IIC_Wait_Ack();
	// start reading ADC channel 0 LB
	modified_addr = (TSL2561_ADDR<<1)|RD;
	IIC_Start();
	IIC_Send_Byte(modified_addr);	
	IIC_Wait_Ack();
	CH0L = IIC_Read_Byte(1);
	IIC_Stop();
	
	modified_addr = (TSL2561_ADDR<<1)|WR;
	IIC_Start();
	IIC_Send_Byte(modified_addr);	
	IIC_Wait_Ack();
	// get access to ADC channel 0 HB
	IIC_Send_Byte(TSL2561_DATA0_HIGH);	
	IIC_Wait_Ack();
	// start reading ADC channel 0 HB
	modified_addr = (TSL2561_ADDR<<1)|RD;
	IIC_Start();
	IIC_Send_Byte(modified_addr);	
	IIC_Wait_Ack();
	CH0H = IIC_Read_Byte(1);
	IIC_Stop();
	
	// get access to this chip, current Addr: 0x39
	modified_addr = (TSL2561_ADDR<<1)|WR;
	IIC_Start();
	IIC_Send_Byte(modified_addr);	
	IIC_Wait_Ack();
	// get access to ADC channel 1 LB
	IIC_Send_Byte(TSL2561_DATA1_LOW);	
	IIC_Wait_Ack();
	// start reading ADC channel 1 LB
	modified_addr = (TSL2561_ADDR<<1)|RD;
	IIC_Start();
	IIC_Send_Byte(modified_addr);	
	IIC_Wait_Ack();
	CH1L = IIC_Read_Byte(1);
	IIC_Stop();

	// get access to this chip, current Addr: 0x39
	modified_addr = (TSL2561_ADDR<<1)|WR;
	IIC_Start();
	IIC_Send_Byte(modified_addr);	
	IIC_Wait_Ack();
	// get access to ADC channel 1 HB
	IIC_Send_Byte(TSL2561_DATA1_HIGH);	
	IIC_Wait_Ack();
	// start reading ADC channel 1 HB
	modified_addr = (TSL2561_ADDR<<1)|RD;
	IIC_Start();
	IIC_Send_Byte(modified_addr);	
	IIC_Wait_Ack();
	CH1H = IIC_Read_Byte(1);
	IIC_Stop();

	CH0 = (CH0H << 8)|CH0L;
	CH1 = (CH1H << 8)|CH1L;
	result = Lux_Calc(CH0,CH1);
	return result;
}

float Lux_Calc(float CH0, float CH1){
	float result;
	float cdc;
	cdc = CH1/CH0;
	if(cdc > 0 && cdc <= 0.50){
		result = 0.0304*CH0 - 0.062*CH0*(pow(cdc,1.4));
		return result;
	}
	else if(cdc > 0.50 && cdc <= 0.61){
		result = 0.0224*CH0 - 0.031*CH1;
		return result;
	}
	else if(cdc > 0.61 && cdc <= 0.8){
		result = 0.0128*CH0 - 0.0153*CH1;
		return result;
	}
	else if(cdc > 0.8 && cdc <= 1.30){
		result = 0.00146*CH0 - 0.00112*CH1;
		return result;
	}
	else{
		return 0;
	}
}
