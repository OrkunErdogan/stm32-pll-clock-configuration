/*
 * msp.c
 *
 *  Created on: Feb 15, 2026
 *      Author: Orkun Erdoğan
 */

#include "main.h"

void HAL_MspInit(void)
{
 //Here will do low level processor specific initilations
	//1. Set up the priority grouping of the arm cortex mx processor
	HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);

	//2. Enable the required system exceptions of the arm cortex mx processor
	SCB->SHCSR |= 0X7 << 16; // USG FAULT, MEMORYFAULT, BUS FAULT system exceptions

	//3. Configure the priority for the system exceptions
	HAL_NVIC_SetPriority(MemoryManagement_IRQn,0,0);
	HAL_NVIC_SetPriority(BusFault_IRQn,0,0);
	HAL_NVIC_SetPriority(UsageFault_IRQn,0,0);
}

void HAL_UART_MspInit(UART_HandleTypeDef *huart)
{
	GPIO_InitTypeDef GPIO_UART;
	//here going to do low level inits of the USART2 peripheral

	//1.Enable the clock for the USART2 peripheral and GPIOA peripheral
	__HAL_RCC_USART2_CLK_ENABLE();
	__HAL_RCC_GPIOA_CLK_ENABLE();

	//2.Do the pin muxing configurations
	GPIO_UART.Pin = GPIO_PIN_2;
	GPIO_UART.Mode= GPIO_MODE_AF_PP;
	GPIO_UART.Pull= GPIO_PULLUP;
	GPIO_UART.Speed= GPIO_SPEED_FREQ_LOW;
	GPIO_UART.Alternate= GPIO_AF7_USART2; //UART2_TX
	HAL_GPIO_Init(GPIOA, &GPIO_UART);

	GPIO_UART.Pin = GPIO_PIN_3; // UART2_RX
	HAL_GPIO_Init(GPIOA, &GPIO_UART);


	//3.Enable the IRQ and set up the priority
	HAL_NVIC_EnableIRQ(USART2_IRQn);
	HAL_NVIC_SetPriority(USART2_IRQn,15, 0);


}
