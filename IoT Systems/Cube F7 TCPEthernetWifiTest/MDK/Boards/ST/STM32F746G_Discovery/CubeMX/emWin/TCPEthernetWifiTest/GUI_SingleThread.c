#include "cmsis_os2.h"
#include "thread.h"
#include "Dialog.h"
#include "usart1.h"
#include <stdio.h>
#include "settings.h"
#ifdef ETHERNET
#include "TCPClient.h"
#endif
#ifdef WIFI
#include "circularBuffer.h"
#include <string.h>
#endif

extern WM_HWIN CreateMyDialog(void);        // declared in MyDialogDLG.c
extern int GUI_VNC_X_StartServer(int, int); // declared in MyDialogDLG.c
extern uint8_t updateData;                  // declared in thread.c

#ifdef ETHERNET
extern char buffer[1024]; // declared in thread.c
#endif

#ifdef WIFI
extern char receivedText[CHAR_ARRAY_BUFFER_LENGTH]; // declared in thread.c
void removeBeforeColon(char *str);
#endif

#define ID_TEXT_0 (GUI_ID_USER + 0x04)

#ifdef _RTE_
#include "RTE_Components.h" // Component selection
#endif

/*----------------------------------------------------------------------------
 *      GUIThread: GUI Thread for Single-Task Execution Model
 *---------------------------------------------------------------------------*/
#define GUI_THREAD_STK_SZ (4096U)

static void GUIThread(void *argument);                /* thread function */
static osThreadId_t GUIThread_tid;                    /* thread id */
static uint64_t GUIThread_stk[GUI_THREAD_STK_SZ / 8]; /* thread stack */

static const osThreadAttr_t GUIThread_attr = {
    .stack_mem = &GUIThread_stk[0],
    .stack_size = sizeof(GUIThread_stk),
    .priority = osPriorityNormal};

int Init_GUIThread(void)
{

  GUIThread_tid = osThreadNew(GUIThread, NULL, &GUIThread_attr);
  if (GUIThread_tid == NULL)
  {
    return (-1);
  }

  return (0);
}

__NO_RETURN static void GUIThread(void *argument)
{
  (void)argument;

  GUI_Init(); /* Initialize the Graphics Component */

  // GUI_VNC_X_StartServer(0,0);

  WM_HWIN hItemWindow = CreateMyDialog();
  WM_HWIN hItem = WM_GetDialogItem(hItemWindow, ID_TEXT_0);

  while (1)
  {

    /* All GUI related activities might only be called from here */

#ifdef ETHERNET
    if (updateData == 1)
    {
      TEXT_SetText(hItem, buffer);
      updateData = 0;
    }
#endif

#ifdef WIFI
    if (updateData == 1)
    {
      // removeBeforeColon(receivedText); // remove +IPD,nr
      TEXT_SetText(hItem, &receivedText[8]);
      updateData = 0;
    }
#endif

#ifdef RTE_Graphics_Touchscreen /* Graphics Input Device Touchscreen enabled */
    GUI_TOUCH_Exec();           /* Execute Touchscreen support */
#endif
    GUI_Exec();       /* Execute all GUI jobs ... Return 0 if nothing was done. */
    GUI_X_ExecIdle(); /* Nothing left to do for the moment ... Idle processing */
    osDelay(100);
  }
}

#ifdef WIFI
void removeBeforeColon(char *str)
{
  // Find the first occurrence of ':' in the string
  char *colonPos = strchr(str, ':');

  if (colonPos != NULL)
  {
    // Move the pointer to the first character after the ':'
    colonPos++;

    // Shift the rest of the string to the beginning
    memmove(str, colonPos, strlen(colonPos) + 1); // +1 to include the null terminator
  }
}
#endif
