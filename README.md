# stm32-pll-clock-configuration

This project demonstrates configuration of the system clock (SYSCLK) using PLL on an STM32 microcontroller, with focus on understanding the clock tree and register-level behavior.
Used board: STM32F446RE Nucleo

Objective:

Configure SYSCLK to different frequency values using PLL and observe system behavior at higher clock speeds.

Tested Configurations
50 MHz
84 MHz
120 MHz
180 MHz (maximum supported frequency)

PLL Configuration:

PLL was configured using the standard formula:

VCO = (CLK_IN / PLLM) * PLLN  
SYSCLK = VCO / PLLP

Both clock sources were tested:

HSI (internal oscillator)
HSE (external oscillator)

Implemented via:

SystemClock_Config_HSI()
SystemClock_Config_HSE()

HAL RCC functions were used during configuration.

Verification

Due to lack of external measurement equipment, verification was performed using indirect methods:
-Observing registers:
RCC_PLLCFGR:PLL parameter setup
RCC_CFGR:system clock selection and prescalers
RCC_CR:clock enable and ready flags

-UART output observed via Tera Term, Baudrate selected as 115200. You can test the other with other macros defined in main.h



