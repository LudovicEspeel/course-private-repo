#include "stm32f091xc.h"
#include "inputoutput.h"

void InitIo2(void)
{
	// Clock voor GPIOC inschakelen.
	RCC->AHBENR = RCC->AHBENR | RCC_AHBENR_GPIOCEN;
	
	// PC0 (LED1) op output zetten
	GPIOC->MODER = (GPIOC->MODER & ~GPIO_MODER_MODER0) | GPIO_MODER_MODER0_0;
	
	
	// Clock voor GPIOA inschakelen.
	RCC->AHBENR = RCC->AHBENR | RCC_AHBENR_GPIOAEN;
	
	// PA1 (SW1) op input zetten (optioneel).
	GPIOA->MODER = GPIOA->MODER & ~GPIO_MODER_MODER1;
}