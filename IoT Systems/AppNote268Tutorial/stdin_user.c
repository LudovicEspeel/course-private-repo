/*-----------------------------------------------------------------------------
 * Name:    stdin_user.c
 * Purpose: STDIN User Template
 * Rev.:    1.0.0
 *-----------------------------------------------------------------------------*/

/*
 * Copyright (C) 2023 ARM Limited or its affiliates. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "retarget_stdin.h"
#include "Driver_USART.h" // CMSIS Driver:USART
extern ARM_DRIVER_USART Driver_USART1;
static ARM_DRIVER_USART * USARTdrv = &Driver_USART1;

/**
  Get a character from stdin

  \return     The next character from the input, or -1 on read error.
*/
int stdin_getchar (void) {
  // ...
  uint8_t ch;
	if(USARTdrv->Receive(&ch,1))
		return (-1);
	while(USARTdrv->GetStatus().rx_busy);
	return ch;
}
