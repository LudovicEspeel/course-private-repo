#include "usart1.h"
#include <stdio.h>

FILE __stdout;
FILE __stdin;

// Redirect printf() to USART1.
int fputc(int ch, FILE *f)
{
	extern UART_HandleTypeDef huart1; // declared in main.c

	HAL_UART_Transmit(&huart1, (uint8_t *)&ch, 1, HAL_MAX_DELAY);
	return ch;
}

// Redirect scanf() to USART1.
int fgetc(FILE *f)
{
	extern UART_HandleTypeDef huart1; // declared in main.c

	int ch = 0;
	HAL_UART_Receive(&huart1, (uint8_t *)&ch, 1, HAL_MAX_DELAY);
	return ch;
}
