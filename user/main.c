#include "stm32f10x.h"                  
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"
#include "delay.h"
#include "button.h"
#include "led.h"
#include "quetled.h"

int main(){
	ledA_Init();
	ledB_Init();
	led_7_thanh_Init();
	button_Init();
//	unsigned int dem=0; 
//	uint16_t counttime=0;
//	uint16_t led7[11] = {0xC0, 0xF9, 0xA4, 0xB0, 
//					 0x99, 0x92, 0x82, 0xF8, 
//					 0x80, 0x90, 0xFF};	

	while(1){
//		quet_led(checkButton());
		buttoneffect();
	}
}	
		