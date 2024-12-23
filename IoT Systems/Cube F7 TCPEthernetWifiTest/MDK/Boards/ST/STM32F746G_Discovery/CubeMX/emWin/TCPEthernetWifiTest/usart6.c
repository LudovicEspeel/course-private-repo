#include "settings.h"
#ifdef WIFI
#include "usart6.h"
#include "string.h"

void StringToUsart6(char *string)
{
	extern UART_HandleTypeDef huart6;

	HAL_UART_Transmit(&huart6, (uint8_t *)string, strlen(string), HAL_MAX_DELAY);
}
#endif