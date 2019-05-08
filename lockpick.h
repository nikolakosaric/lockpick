#ifndef LOCKPICK_H_
#define LOCKPICK_H_

/**
 * @defgroup lockpick Lockpick Module
 * @file lockpick.h
 * @addtogroup lockpick Lockpick Module
 *
 *  Created on: May 3, 2019
 *  @author: Nikola Kosaric
 *
 * @brief The lockpick module implements a virtual lockpick by using a slide potentiometer to mimic movement of a tumbler and a 5x5 RGB LED matrx to display the position of the virtual tumbler. 
 *
 *Each column of the matrix represents a tumbler. The user slides the potentiometer, mimicking the position of the tumbler. This position is shown on the RGB matrix as a red LED. The position at which the tumbler unlocks is shown as a blue LED. Once the user moves the tumbler to a position within plus or minus the error, the LED turns green and the tumbler is then incrimeneted. Once all five tumblers have been solved, the lock is disarmed. The error value is set by the difficulty of the trap. 
 *
 * This module relies on the task module, random integer module, and LED matrix module.
 *
 * Doccumentation for the task module can be seen here: <a href="https://muhlbaier.github.io/embedded-software/group__task.html">Task Module</a> 
 *
 * Doccumentation for the random integer module can be seen here: <a href="https://muhlbaier.github.io/embedded-software/group__random__int.html">Random Integer Module</a> 
 *
 * @{
 */

#include <msp430.h>
#include <stdint.h>
#include "random_int.h"
#include "task.h"
#include "project_settings.h"
#include "subsystem.h"
#include "LED_matrix.h"

/**
 * Global variable to allow for each function to keep track of what tumbler the user is currently on
 */
uint8_t tumbler;

/**
 * @brief Function to be called to arm the lockpick
 *
 *@param error - sets the difficulty of the lockpick. The higher the number, the more difficult the lockpick is to crack
 *
 *
 */
uint8_t Lockpick_Arm(uint8_t error);

/**
 * @brief Function that sets the position at which each individual tumbler unlocks to a 16 bit integer value by utilizing the random_int module
 *
 *
 */
void Tumbler_Values(void);

/**
 * @brief Plots the column position of the tumbler based on a unsigned 16 bit integer, and the tumbler that is being moved
 *
 * @param ADC_draw_value - the position of the tumbler based on the 16 bit integer value of the tumbler 
 * @param tumbler - the tumbler that is currently being utilized
 * @param color - the color that the LED should be lit up
 *
 * This module is utilized when drawing the position of the tumbler that is moved and the position that the tumbler needs to be at to unlock. 
 */
void Draw_ADC_Value(uint16_t ADC_draw_value, uint8_t tumbler, uint8_t color);

/**
 * @brief Plots the position of tumbler 1 by calling the Draw_ADC_Value function
 *
 */
void Draw_Tumbler1(void);

/**
 * @brief Plots the position of tumbler 2 by calling the Draw_ADC_Value function and stops plotting the position of tumbler 1
 *
 */
void Draw_Tumbler2(void);

/**
 * @brief Plots the position of tumbler 3 by calling the Draw_ADC_Value function and stops plotting the position of tumbler 2
 *
 */
void Draw_Tumbler3(void);

/**
 * @brief Plots the position of tumbler 4 by calling the Draw_ADC_Value function and stops plotting the position of tumbler 3
 *
 */
void Draw_Tumbler4(void);

/**
 * @brief Plots the position of tumbler 5 by calling the Draw_ADC_Value function and stops plotting the position of tumbler 4
 *
 */
void Draw_Tumbler5(void);

/**
 * @brief Schedules tumbler to be drawn based on what tumbler is currently being utilized
 *
 * @param tumbler - the current tumbler that is being utilized
 */
void Draw_Tumblers(uint8_t tumbler);

/**
 * @brief Returns the position at which the tumbler unlocks
 *
 * @param tumbler - the current tumbler that is being utilized
 */
uint16_t Tumbler_Value(uint8_t tumbler);

/**
 * @brief Checks the position of the tumbler to see if it has reached the position at which the tumbler unlocks
 * 
 * @param ADC_value - the position at which the user has the tumbler
 * @param tumbler_value - the position at which the tumbler unlocks
 * @param tumbler - the current tumbler that is being utilized
 * @param error - the room for error the user has to reach the positions at which the tumbler unlocks
 * The error value is based off of the difficulty.
 * 
 */
uint8_t Check_Tumbler_Position(uint16_t ADC_value, uint16_t tumbler_value, uint8_t tumbler, uint8_t error);

/**
 * @brief Disarms the lockpick
 *
 */
void Picked(void);

/** @}*/
#endif /* LOCKPICK_H_ */
