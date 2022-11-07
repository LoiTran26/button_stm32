#include "led.h"
#include "stm32f10x.h"

void ledA_Init(void){
	GPIO_InitTypeDef led;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	led.GPIO_Mode = GPIO_Mode_Out_PP;
	led.GPIO_Pin = GPIO_Pin_12;
	led.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &led);
}

void ledB_Init(void){
	GPIO_InitTypeDef led;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	led.GPIO_Mode = GPIO_Mode_Out_PP;
	led.GPIO_Pin = GPIO_Pin_5 | GPIO_Pin_8;
	led.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &led);
}

void led_7_thanh_Init(void){
	GPIO_InitTypeDef led_7_thanh;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	led_7_thanh.GPIO_Mode = GPIO_Mode_Out_PP;
	led_7_thanh.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | 
						   GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_8 | 
						   GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11 ;
	led_7_thanh.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &led_7_thanh);
}

void reset(void){
	GPIO_ResetBits(GPIOA, GPIO_Pin_12);
	GPIO_ResetBits(GPIOB, GPIO_Pin_5);
	GPIO_ResetBits(GPIOB, GPIO_Pin_8);
}

void reset7(void){
	GPIO_ResetBits(GPIOA, GPIO_Pin_8);
	GPIO_ResetBits(GPIOA, GPIO_Pin_9);
	GPIO_ResetBits(GPIOA, GPIO_Pin_10);
	GPIO_ResetBits(GPIOA, GPIO_Pin_11);
}
