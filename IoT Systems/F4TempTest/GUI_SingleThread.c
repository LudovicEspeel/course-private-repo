
#include "cmsis_os2.h"
#include "GUI.h"
#include "dialog.h"
#include "TemperatureSensor.h"
#include <stdio.h>

/*----------------------------------------------------------------------------
 *      GUIThread: GUI Thread for Single-Task Execution Model
 *---------------------------------------------------------------------------*/
#define GUI_THREAD_STK_SZ    (2048U)

static void         GUIThread (void *argument);         /* thread function */
static osThreadId_t GUIThread_tid;                      /* thread id */
static uint64_t     GUIThread_stk[GUI_THREAD_STK_SZ/8]; /* thread stack */
extern WM_HWIN CreateLogViewer(void);

static const osThreadAttr_t GUIThread_attr = {
  .stack_mem  = &GUIThread_stk[0],
  .stack_size = sizeof(GUIThread_stk),
  .priority   = osPriorityIdle 
};

int Init_GUIThread (void) {

  GUIThread_tid = osThreadNew(GUIThread, NULL, &GUIThread_attr);
  if (GUIThread_tid == NULL) {
    return(-1);
  }

  return(0);
}

__NO_RETURN static void GUIThread (void *argument) {
  (void)argument;

  GUI_Init();           /* Initialize the Graphics Component */

  /* Add GUI setup code here */
	GUI_DispString("Hello world");
	
	CreateLogViewer();

	uint8_t temp = 0;

  while (1) {
		char buf[4];
		int32_t a = Temp_Read(&temp);
		sprintf(buf, "%02d", temp);
    printf("%s\r\n", buf);
		
    /* All GUI related activities might only be called from here */

    GUI_Exec();         /* Execute all GUI jobs ... Return 0 if nothing was done. */
    GUI_X_ExecIdle();   /* Nothing left to do for the moment ... Idle processing */
		GUI_TOUCH_Exec();
  }
}
