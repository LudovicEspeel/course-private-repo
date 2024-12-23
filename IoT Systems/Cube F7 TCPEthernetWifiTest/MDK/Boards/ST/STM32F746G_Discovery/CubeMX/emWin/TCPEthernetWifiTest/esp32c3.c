#include "settings.h"
#ifdef WIFI
#include "esp32c3.h"
#include "circularBuffer.h"
#include "usart1.h"
#include "usart6.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Board_LED.h" // ::Board Support:LED
#include "main.h"

// AT-commands reference: https://docs.espressif.com/projects/esp-at/en/release-v3.1.0.0/esp32c3/AT_Command_Set/Basic_AT_Commands.html.

extern volatile CircularBuffer circularBuffer;
extern UART_HandleTypeDef huart6;
uint8_t receivedUsart6Data = 0;

void InitWifi()
{
	// Initialize the circular buffer.
	if (InitCircularBuffer(&circularBuffer) != INIT_SUCCEEDED)
		printf("Initialization of CircularBuffer failed!\r\n");

	// Give the WiFi module time to start up.
	HAL_Delay(1000);

	// Start receiving one byte via interrupts (for the ESP32 module).
	HAL_UART_Receive_IT(&huart6, (uint8_t *)&receivedUsart6Data, 1);

	// Set the WiFi module to AT mode.
	StringToUsart6("AT\r\n");
	while (!LookForString1(&circularBuffer, "OK\r\n"))
		;

	// Reset the WiFi module.
	StringToUsart6("AT+RST\r\n");
	while (!LookForString1(&circularBuffer, "ready\r\n"))
		;

	// Request the current AT firmware version (optional).
	// StringToUsart6("AT+GMR\r\n");
	// while(!LookForString1(&circularBuffer, "OK\r\n"));

	// Request the MAC address (optional).
	// StringToUsart6("AT+CIPSTAMAC?\r\n");
	// while(!LookForString1(&circularBuffer, "OK\r\n"));

	ConnectToWiFiNetwork();
}

void ConnectToWiFiNetwork()
{
	char text[CHAR_ARRAY_BUFFER_LENGTH];

	// Visually indicate that there is no connection. TODO: use GUI component?
	LED_Off(0);

	// Clear the circular buffer.
	InitCircularBuffer(&circularBuffer);

	// Do not save settings to flash.
	StringToUsart6("AT+SYSSTORE=0\r\n");
	while (!LookForString1(&circularBuffer, "OK\r\n"))
		;

	// Do not automatically connect on power up.
	StringToUsart6("AT+CWAUTOCONN=0\r\n");
	while (!LookForString1(&circularBuffer, "OK\r\n"))
		;

	// Set to station mode and disable automatic connection to the access point.
	StringToUsart6("AT+CWMODE=1,0\r\n");
	while (!LookForString1(&circularBuffer, "OK\r\n"))
		;

	// Set reconnect: retry every 10 seconds, up to a maximum of 100 attempts.
	StringToUsart6("AT+CWRECONNCFG=10,100\r\n");
	while (!LookForString1(&circularBuffer, "OK\r\n"))
		;

	// Set to station mode and receive IP via DHCP.
	StringToUsart6("AT+CWDHCP=1,1\r\n");
	while (!LookForString1(&circularBuffer, "OK\r\n"))
		;

	// Disable multiple connections.
	StringToUsart6("AT+CIPMUX=0\r\n");
	while (!LookForString1(&circularBuffer, "OK\r\n"))
		;

	// List available access points.
	// StringToUsart6("AT+CWLAP\r\n");
	// while(!LookForString1(&circularBuffer, "OK\r\n"));

	// Connect to the WiFi network. Wait for: "WIFI GOT IP\r\n\r\nOK\r\n" or "OK\r\n".
	sprintf(text, "AT+CWJAP=\"%s\",\"%s\"\r\n", "YOUR_SSID", "YOUR_PASSWORD"); // TODO: add these settings in separate file
	StringToUsart6(text);
	while (!LookForString1(&circularBuffer, "OK\r\n"))
		;

	// Request MAC address.
	// StringToUsart6("AT+CIPSTAMAC?\r\n");
	// while(!LookForString1(&circularBuffer, "OK\r\n"));

	// Request IP address.
	StringToUsart6("AT+CIPSTA?\r\n");
	while (!LookForString1(&circularBuffer, "OK\r\n"))
		;

	// Check if connected to the access point AND if an IPv4 address is assigned.
	StringToUsart6("AT+CWSTATE?\r\n");
	sprintf(text, "+CWSTATE:2,\"%s\"\r\n", "YOUR_SSID"); // TODO: add these settings in separate file
	while (!LookForString1(&circularBuffer, text))
		;
	while (!LookForString1(&circularBuffer, "OK\r\n"))
		;

	// Visually indicate that there is a connection.
	LED_On(0);
}

void SendTCPWifiMessage(char *message, uint32_t size)
{
	static char tcptext[CHAR_ARRAY_BUFFER_LENGTH]; // Static, so the content can be used as a return value.
	char text[CHAR_ARRAY_BUFFER_LENGTH];
	uint8_t foundString = 0;
	bool waitingForData = true;
	uint16_t numberOfReceivedBytes = 0;
	uint8_t contentLength = 0;
	enum CircularBufferActionResult circularBufferActionResult;

	// Query the current status of the TCP connection.
	StringToUsart6("AT+CIPSTATE?\r\n");
	while (PopStringFromCircularBuffer(&circularBuffer, text) != READ_STRING_SUCCEEDED) // The code blocks here sometimes?!
		;																				// Discard echo of "AT+CPISTART".
	while (PopStringFromCircularBuffer(&circularBuffer, text) != READ_STRING_SUCCEEDED) // The code blocks here sometimes?!
		;																				// Retrieve response of "AT+CIPSTART".
	// If the response is not of the form "+CIPSTATE:0,"SSL","34.107.226.223",443,63455,0", restart.
	if (text[0] != '+')
	{
		// Look for OK.
		while (!LookForString1(&circularBuffer, "OK\r\n"))
			;

		// Start a (new) TCP connection with the server.
		sprintf(tcptext, "AT+CIPSTART=\"TCP\",\"%s\",%d\r\n", "192.168.1.11", 3100);
		StringToUsart6(tcptext);
		// TODO: Also handle ERROR and create a new connection?
		while (!LookForString1(&circularBuffer, "OK\r\n"))
			;
	}

	// Raw TCP-IP message.
	sprintf(tcptext, "%s", message);

	// Send packet over TCP.
	sprintf(text, "AT+CIPSEND=%d\r\n", strlen(tcptext));
	StringToUsart6(text);
	// TODO: Add a timeout here as well.
	// Wait for '>' character.
	while (!LookForString1(&circularBuffer, ">\r\n"))
		;
	StringToUsart6(tcptext);
	while (!LookForString1(&circularBuffer, "SEND OK\r\n"))
		;

	// Display what was sent for information (optional).
	sprintf(text, "TCP-data sent: %s\r\n", tcptext);
	printf("%s", text);
}

// TODO: add functions for HTTP, HTTPS, MQTT
//...
#endif