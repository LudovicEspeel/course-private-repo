#include "stm32f091xc.h"

// versie waarbij we alles in 1 bestand plaatsen, de main-functie bevindt zich onderaan

void SystemClock_Config(void)
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

void InitIo(void)
{
	// Clock voor GPIOA inschakelen.
	RCC->AHBENR = RCC->AHBENR | RCC_AHBENR_GPIOAEN;
	
	// PA1 (SW1) op input zetten (optioneel).
	GPIOA->MODER = GPIOA->MODER & ~GPIO_MODER_MODER1;
	
	
	// Clock voor GPIOC inschakelen.
	RCC->AHBENR = RCC->AHBENR | RCC_AHBENR_GPIOCEN;
	
	// PC0 (LED1) op output zetten
	GPIOC->MODER = (GPIOC->MODER & ~GPIO_MODER_MODER0) | GPIO_MODER_MODER0_0;
}

int main(void)
{
	SystemClock_Config();
	
	InitIo();
	
	while(1)
	{
		// SW1 actief?
		if((GPIOA->IDR & GPIO_IDR_1) != GPIO_IDR_1)
			GPIOC->ODR = GPIOC->ODR | GPIO_ODR_0;
		else
			GPIOC->ODR = GPIOC->ODR & ~GPIO_ODR_0;
	}
}