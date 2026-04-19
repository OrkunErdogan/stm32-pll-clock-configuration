/*
 * it.c
 *
 *  Created on: Feb 15, 2026
 *      Author: Orkun Erdoğan
 */

#include "main.h"


void SysTick_Handler(void){

	HAL_IncTick();
	HAL_SYSTICK_IRQHandler();


}

