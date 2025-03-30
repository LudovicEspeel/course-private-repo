#include "stm32f091xc.h"
#include "timer6.h"

// Timer 6 instellen
// 1 cm (moet dubbel afgelegd worden) = 0.02m/340m/s = ~59 µs
// Gemeten met een klok van 48 MHz is dit 59 µs/20,8ns = ~2832 stappen
void InitTimer6(void)
{
	RCC->APB1ENR |= RCC_APB1ENR_TIM6EN; // Timer6 clock aanzetten
  TIM6->PSC = 48 - 1; // Prescaler: Deel door 48000 (1 tick = 1 ms)
  TIM6->ARR = 0xFFFF; // Auto-reload: 1000 ticks = 1 seconde
  //TIM6->CR1 |= TIM_CR1_URS; // Enkel overflow genereert update event
  //TIM6->EGR |= TIM_EGR_UG; // Update event forceren om registers te laden
	//TIM6->DIER |= TIM_DIER_UIE;	// Interrupt enable voor timer 6	
}

void Timer6On(void)
{
	TIM6->CNT = 0;
	TIM6->CR1 |= TIM_CR1_CEN;		// Counter enable
}

void Timer6Off(void)
{
	TIM6->CR1 &= ~TIM_CR1_CEN;	// Counter disable
}