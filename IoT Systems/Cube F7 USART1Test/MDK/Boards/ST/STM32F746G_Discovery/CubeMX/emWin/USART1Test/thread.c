#include "thread.h"
#include "main.h"
#include "usart1.h"	   //now you can use printf
#include "Board_LED.h" // ::Board Support:LED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern void Init_GUIThread(void);
extern UART_HandleTypeDef huart1; // declared in main.c
uint8_t sendData = 0;
uint8_t dataReceived = 0;
char buffer[1024];

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

	while (1)
	{

		// Preferably place as much of your code here as possible, instead of in GUI_SingleThread.
		// The latter is more intended for configuring graphical settings.
		if(sendData)
		{
			printf("Hello USART1!\r\n");
			sendData = 0;
		}
		
		//scanf can't be used here because it blocks the execution
		//...
		
		HAL_StatusTypeDef status = HAL_UART_Receive(&huart1, (uint8_t*)buffer, 1, 100); //polling for 1 byte of data
		if (status == HAL_OK) {
        dataReceived = 1;
    }
		//better: use interrupts, enable this in Cube, use HAL_UART_Receive_IT and create callback HAL_UART_RxCpltCallback in main.c 
		
		// osThreadExit();
	}
}