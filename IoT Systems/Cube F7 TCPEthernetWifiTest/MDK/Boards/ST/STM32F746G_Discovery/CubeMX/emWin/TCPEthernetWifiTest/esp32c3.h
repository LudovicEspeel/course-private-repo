#include "circularBuffer.h"

#ifndef ESP8266_DEFINED
#define ESP8266_DEFINED

void InitWifi();
void ConnectToWiFiNetwork();
void SendTCPWifiMessage(char *message, uint32_t size);
#endif
