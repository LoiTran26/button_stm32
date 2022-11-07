#include "stm32f10x.h"
#include "button.h"
#include "delay.h"
#include "led.h"
#include "quetled.h"


uint16_t led7[11] = {0xC0, 0xF9, 0xA4, 0xB0, 
					 0x99, 0x92, 0x82, 0xF8, 
					 0x80, 0x90, 0xFF};	
uint16_t counttime=0;
unsigned int dem=0; 
unsigned int checkButton(void){
	uint16_t sttNew = GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_7);
	if(sttNew == 1){
		if(counttime <= 30){
			counttime++;
			if(counttime == 4){
				if(dem <= 9999){
					dem ++;
				}
				else{
					dem = 0;
				}
			}
		}
		else{
			counttime = 0;
		}
	}
	return dem;
}

void buttoneffect(void){
	if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_7)==1){
		checkButton();
		delay_ms(130);
		if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_7)==0){
			delay_ms(130);
			if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_7)==0){
				reset();
				GPIO_SetBits(GPIOA, GPIO_Pin_12);
			}
			else{
				if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_7)==1){
					reset();
					GPIO_SetBits(GPIOB, GPIO_Pin_5);
				}
			}
		}
		else{
			if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_7)==1){
				delay_ms(400);
				reset();
				GPIO_SetBits(GPIOB, GPIO_Pin_8);
			}
		}
		delay_ms(200);
	}
}

void button_Init(void){
	GPIO_InitTypeDef button;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	button.GPIO_Mode = GPIO_Mode_IPU;
	button.GPIO_Pin = GPIO_Pin_7;
	button.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &button);
}
