#include "stm32f7xx_hal.h"

#if !defined(TCPClient_DEFINED)
#define TCPClient_DEFINED
void OpenTCPConnection();
void SendTCPMessage(char *message, uint32_t size);
int32_t ReceiveTCPMessage(char *buffer, uint32_t size);
void CloseTCPConnection();
#endif