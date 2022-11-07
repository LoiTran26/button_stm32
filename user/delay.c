#include "delay.h"
#include "stm32f10x_tim.h"

void timer_Init(void){
	TIM_TimeBaseInitTypeDef timer;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	timer.TIM_CounterMode = TIM_CounterMode_Up;
	timer.TIM_Period = 65535;
	timer.TIM_Prescaler = 2-1;
	timer.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM2, &timer);
}

void delay_1ms(void){
	timer_Init();
	TIM_Cmd(TIM2, ENABLE);
	TIM_SetCounter(TIM2, 0);
	while(TIM_GetCounter(TIM2) < 36000){}
	TIM_Cmd(TIM2, DISABLE);
}

void delay_ms(unsigned int time){
	while(time--){
		delay_1ms();
	}
}

