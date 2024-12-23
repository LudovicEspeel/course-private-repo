#include "thread.h"
#include "main.h"
#include "usart1.h"	   //now you can use printf
#include "Board_LED.h" // ::Board Support:LED
#include "rl_net.h"	   // Keil.MDK-Pro::Network:CORE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "settings.h"
#ifdef ETHERNET
#include "tcpClient.h"
#endif
#ifdef WIFI
#include "circularBuffer.h"
#include "esp32c3.h"
#include "usart6.h"
#endif

extern TIM_HandleTypeDef htim6;		 // declared in main.c
extern uint8_t timerPeriodIsElapsed; // declared in main.c
extern void Init_GUIThread(void);

#ifdef WIFI
extern UART_HandleTypeDef huart1;								   // declared in main.c
extern UART_HandleTypeDef huart6;								   // declared in main.c
extern volatile CircularBuffer circularBuffer;					   // declared in circularBuffer.h
extern enum CircularBufferActionResult circularBufferActionResult; // declared in circularBuffer.h
enum UsartState usart6State = idle;
uint8_t receivedUsart1Data = 0;
uint8_t numberOfReceivedBytes = 0;
char receivedText[CHAR_ARRAY_BUFFER_LENGTH];
#endif

#ifdef ETHERNET
char buffer[1024];
#endif

uint8_t updateData;

// Main stack size must be multiple of 8 Bytes
#define APP_MAIN_STK_SZ (4096)
uint64_t app_main_stk[APP_MAIN_STK_SZ / 8];
const osThreadAttr_t app_main_attr = {
	.stack_mem = &app_main_stk[0],
	.stack_size = sizeof(app_main_stk)};
/*----------------------------------------------------------------------------
 * Application main thread
 *---------------------------------------------------------------------------*/
__NO_RETURN void app_main(void *argument)
{

	(void)argument;

	LED_Initialize();

	Init_GUIThread();

	printf("Hello USART1!\r\n");

#ifdef TIMER6
	HAL_TIM_Base_Start_IT(&htim6); // start timer6, interrupt is in main.c (HAL_TIM_PeriodElapsedCallback)
#endif

#ifdef ETHERNET
	netInitialize(); // initialize ethernet interface
	OpenTCPConnection();
#endif

#ifdef WIFI
	InitWifi();
#endif

	while (1)
	{
		// TIMER6
		if (timerPeriodIsElapsed == 1)
		{
			// SendTCPWifiMessage("Hello Wifi!", 11); //this works...

			printf("Timer elapse 5 seconds\r\n");
			timerPeriodIsElapsed = 0;
		}

		// Preferably place as much of your code here as possible, instead of in GUI_SingleThread.
		// The latter is more intended for configuring graphical settings.

#ifdef ETHERNET
		int32_t bytesReceived = ReceiveTCPMessage(buffer, 1024);
		if (bytesReceived > 0)
		{
			updateData = 1;
			printf("Received: %s\r\n", buffer);
		}
#endif

#ifdef WIFI
		while (circularBuffer.numberOfStringsInBuffer > 0)
		{

			// Retrieve one string from the buffer.
			circularBufferActionResult = PopStringFromCircularBuffer(&circularBuffer, receivedText);
			if (circularBufferActionResult == READ_STRING_SUCCEEDED)
			{
				// Check for reception. Look for "+IPD," as it indicates the start of the received TCP data.
				if (strncmp("+IPD,", receivedText, 5) == 0)
				{
					// Determine the number of bytes received (optional).
					numberOfReceivedBytes = (uint16_t)atoi(&receivedText[5]);

					// At the end of the HTTP headers, there is an empty line. Find it and skip all HTTP headers.
					// After that, the requested information from the server will be present.
					// while(!LookForString1(&circularBuffer, "\r\n"));

					// Wait briefly for the next line of data to arrive.
					// while(circularBuffer.numberOfStringsInBuffer == 0);

					// Read the next line, which contains the data received from the network.
					// circularBufferActionResult = PopStringFromCircularBuffer(&circularBuffer, receivedText);

					// Print the received text for debugging purposes.
					printf("Received: %s\r\n", receivedText);
					updateData = 1;
				}
			}
		}
#endif
		// osThreadExit();
	}
}

#ifdef WIFI
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *UartHandle)
{
	if (UartHandle->Instance == USART6)
	{
		// Send a byte on USART2 (USB) so that you can also follow along on the computer.
		// This is not mandatory but facilitates debugging.
		// Note: Ensure a timeout of 0, otherwise the code execution here might be too slow and cause issues on UART1.
		HAL_UART_Transmit(&huart1, (uint8_t *)&receivedUsart1Data, 1, 0);

		// Store received data in a circular buffer.
		// The circular buffer ensures that no bytes are lost. You can then process all received data
		// "at your own pace" in the main loop...
		if (usart6State == busyReceiving)
		{
			// Is there still space in the buffer?
			if (!IsCircularBufferFull(&circularBuffer))
			{
				// Store the character.
				PushCharToCircularBuffer(&circularBuffer, receivedUsart1Data);

				// A new line has been received. Indicate that you are ready for the next line...
				if (receivedUsart1Data == '\n')
					usart6State = idle;
			}
		}
		else
		{
			// Start of the reception/line.
			if (usart6State == idle)
			{
				// Is there still space in the buffer?
				if (!IsCircularBufferFull(&circularBuffer))
				{
					// Buffer is not full. Start storing in the circular buffer.
					usart6State = busyReceiving;

					// Store the character.
					PushCharToCircularBuffer(&circularBuffer, receivedUsart1Data);

					// A new line has been received. Indicate that you are ready for the next line...
					if (receivedUsart1Data == '\n')
						usart6State = idle;
					else
					{
						// After sending the 'AT+CIPSEND' or an 'MQTTPUBRAW' command, it is necessary to wait for the '>' character.
						// Detect the reception of that character here. Automatically append a "\r\n" to forcibly create a new line
						// in the circular buffer. This makes processing the data from the buffer easier.
						if (receivedUsart1Data == '>')
						{
							// Forcefully store an extra line with ">\r\n".
							PushCharToCircularBuffer(&circularBuffer, '\r');
							PushCharToCircularBuffer(&circularBuffer, '\n');

							usart6State = idle;
						}
					}
				}
			}
		}

		// Restart reception via interrupts, because RXNEIE is automatically disabled.
		HAL_UART_Receive_IT(&huart6, (uint8_t *)&receivedUsart1Data, 1);
	}
}
#endif