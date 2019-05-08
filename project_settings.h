/*
 * project_settings.h
 *
 *  Created on: Apr 29, 2019
 *      Author: nikol
 */

#ifndef PROJECT_SETTINGS_H_
#define PROJECT_SETTINGS_H_

#define FCPU 24000000

#define USE_SPI_A0
#define SPI_MAX_SIZE 33
#define THIEF_SPI SPI_A0
#define THIEF_BRAINFRAME_NETWORK

#define USE_UART1
#define SUBSYS_UART UART1


// include the library header
#include "library.h"
// let the system know which lower level modules are in use
// this way higher modules can selectively utilize their resources
#define USE_MODULE_TASK
#define USE_MODULE_SUBSYSTEM
#define USE_MODULE_BUFFER_PRINTF

#define SUBSYSTEM_UART 1  // UART1 is the application UART

#define UART0_TX_BUFFER_LENGTH 512

#define USE_UART0

#define TASK_MAX_LENGTH 50

#endif /* PROJECT_SETTINGS_H_ */
