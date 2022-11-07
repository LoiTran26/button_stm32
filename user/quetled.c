#include "stm32f10x.h"
#include "quetled.h"
#include "led.h"
#include "delay.h"
#include "button.h"

uint16_t led[11] = {0xC0, 0xF9, 0xA4, 0xB0, 
					 0x99, 0x92, 0x82, 0xF8, 
					 0x80, 0x90, 0xFF};	


void quet_led(unsigned int so){
	unsigned int i = so;
	reset7();
	GPIO_Write(GPIOA, led[i/1000]);
	GPIO_SetBits(GPIOA, GPIO_Pin_8);
	delay_1ms();
	
	reset7();
	GPIO_Write(GPIOA, led[(i%1000)/100]);
	GPIO_SetBits(GPIOA, GPIO_Pin_9);
	delay_1ms();
	
	reset7();
	GPIO_Write(GPIOA, led[(i%100)/10]);
	GPIO_SetBits(GPIOA, GPIO_Pin_10);
	delay_1ms();
	
	reset7();
	GPIO_Write(GPIOA, led[i%10]);
	GPIO_SetBits(GPIOA, GPIO_Pin_11);
	delay_1ms();
}
