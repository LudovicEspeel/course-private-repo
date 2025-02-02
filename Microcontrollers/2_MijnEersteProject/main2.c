#include "stm32f091xc.h"
#include "inputoutput.h"
#include <stdbool.h>

// versie 2 waarbij we werken met functie prototypes en aparte bestanden, zo bevindt de main-functie zich zo hoog mogelijk

void SystemClock_Config2(void);

int main2(void)
{
	SystemClock_Config2();
	
	InitIo2();
	
	while(true)
	{
		// SW1 actief?
		if((GPIOA->IDR & GPIO_IDR_1) != GPIO_IDR_1)
			GPIOC->ODR = GPIOC->ODR | GPIO_ODR_0;
		else
			GPIOC->ODR = GPIOC->ODR & ~GPIO_ODR_0;
	}
}

void SystemClock_Config2(void)
{ 
  RCC->CR |= RCC_CR_HSITRIM_4;
  RCC->CR |= RCC_CR_HSION;
  while((RCC->CR & RCC_CR_HSIRDY) == 0);
 
  RCC->CFGR &= ~RCC_CFGR_SW;
  while((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_HSI);

  RCC->CR &= ~RCC_CR_PLLON;
  while((RCC->CR & RCC_CR_PLLRDY) != 0);

  RCC->CFGR |= RCC_CFGR_PLLSRC_HSI_PREDIV;
  RCC->CFGR2 |= RCC_CFGR2_PREDIV_DIV2;
  RCC->CFGR |= RCC_CFGR_PLLMUL12;
	
  FLASH->ACR |= FLASH_ACR_LATENCY;
	
  RCC->CR |= RCC_CR_PLLON;
  while((RCC->CR & RCC_CR_PLLRDY) == 0);

  RCC->CFGR |= RCC_CFGR_SW_PLL;
  while((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL);

  RCC->CFGR |= RCC_CFGR_HPRE_DIV1;
  RCC->CFGR |= RCC_CFGR_PPRE_DIV1;
	
  SystemCoreClockUpdate(); 
  //SysTick_Config(48000);
}