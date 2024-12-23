#include "stm32f7xx_hal.h"

#if !defined(USART6_DEFINED)
#define USART6_DEFINED

enum UsartState
{
	idle,
	busyReceiving,
	newStringArrived,
	receptionTimeOut,
	overflowOccured
};

void StringToUsart6(char *string);
#endif