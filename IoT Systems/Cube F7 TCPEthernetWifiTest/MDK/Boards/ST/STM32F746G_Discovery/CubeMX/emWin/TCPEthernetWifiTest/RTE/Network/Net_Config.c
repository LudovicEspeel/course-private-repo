/*------------------------------------------------------------------------------
 * MDK Middleware - Component ::Network
 * Copyright (c) 2004-2023 Arm Limited (or its affiliates). All rights reserved.
 *------------------------------------------------------------------------------
 * Name:    Net_Config.c
 * Purpose: Network Configuration
 * Rev.:    V7.2.0
 *----------------------------------------------------------------------------*/

//-------- <<< Use Configuration Wizard in Context Menu >>> --------------------

// <h>Network System Settings
// <i>Global Network System definitions
//   <s.15>Local Host Name
//   <i>This is the name under which embedded host can be
//   <i>accessed on a local area network.
//   <i>Default: "my_host"
#define NET_HOST_NAME           "stm32f746g-dk"

//   <o>Memory Pool Size <1536-262144:4>
//   <i>This is the size of a memory pool in bytes. Buffers for
//   <i>network packets are allocated from this memory pool.
//   <i>Default: 12000 bytes
#define NET_MEM_POOL_SIZE       12000

//   <q>Start System Services
//   <i>If enabled, the system will automatically start server services
//   <i>(HTTP, FTP, TFTP server, ...) when initializing the network system.
//   <i>Default: Enabled
#define NET_START_SERVICE       1

//   <h>OS Resource Settings
//   <i>These settings are used to optimize usage of OS resources.
//     <o>Core Thread Stack Size <512-65535:4>
//     <i>Default: 1024 bytes
#define NET_THREAD_STACK_SIZE   1024

//        Core Thread Priority
#define NET_THREAD_PRIORITY     osPriorityNormal

//   </h>
// </h>

//------------- <<< end of configuration section >>> ---------------------------


#include "net_config.h"


/**
\addtogroup net_genFunc
@{
*/
/**
  \fn          void net_sys_error (NET_ERROR error)
  \ingroup     net_cores
  \brief       Network system error handler.
*/
void net_sys_error (NET_ERROR error) {
  /* This function is called when a fatal error is encountered. */
  /* The normal program execution is not possible anymore.      */

  switch (error) {
    case NET_ERROR_MEM_ALLOC:
      /* Out of memory */
      break;

    case NET_ERROR_MEM_FREE:
      /* Trying to release non existing memory block */
      break;

    case NET_ERROR_MEM_CORRUPT:
      /* Memory Link pointer corrupted */
      /* More data written than the size of allocated memory block */
      break;

    case NET_ERROR_CONFIG:
      /* Network configuration error detected */
      break;

    case NET_ERROR_UDP_ALLOC:
      /* Out of UDP Sockets */
      break;

    case NET_ERROR_TCP_ALLOC:
      /* Out of TCP Sockets */
      break;

    case NET_ERROR_TCP_STATE:
      /* TCP State machine in undefined state */
      break;
  }

  /* End-less loop */
  while (1);
}
/**
@}
*/
