#ifndef LED_MATRIX_H_
#define LED_MATRIX_H_

/**
 * @defgroup led LED Matrix Module
 * @file LED_matrix.h
 * @addtogroup led LED Matrix Module
 *
 *  Created on: May 3, 2019
 *  @author: Nikola Kosaric
 *
 * @brief The LED matrix module implements control for a 5x5 RGB LED matrix
 * 
 * Normal usage is:
 * - LED_Matrix_Init to initialize a the LED matrix.
 * - Slect the LED to illuminate
 * -- Select_LED to select the row, column, and color of the LED to illuminate
 * - Clear all LEDs
 * -- Clears all the LEDs that are illuminated in order to allow for the next LED to be illuminated
 * @{
 */

#include <stdint.h>

/** 
 * Allows for the user to easily select red rather than remembering what integer to use
 */
#define red 1
/** 
 * Allows for the user to easily select green rather than remembering what integer to use
 */
#define green 2
/** 
 * Allows for the user to easily select blue rather than remembering what integer to use
 */
#define blue 3

/** @brief Initialized the LED matrix module
 *
 * This module intiializes the LED matrix by setting the direction all the pins utilized for the RGB LED matrix. All pins utilized are set to the output direction so they can be utilized for general. The Clear_LED function is then called to ensure that all LEDs are initially shut off.
 * This module is specific to the MSP430F5529 as there are no easy ways to have a hardware abstraction layer. 
 */
void LED_Matrix_Init(void);

/** @brief Selects the LED to be illuminated based on the row, column, and color selected.
 *
 * @param row - Selets the row of the LED matrix that will be illuminated
 * @param column - Selects the column of the LED matrix that will be illuminated
 * @param color - Selects the color of the LED that will be illuminated, the red, green, and blue defines can be utilized
 */
void Select_LED(uint8_t row, uint8_t column, uint8_t color);

/** @brief Shuts off all the LEDs on the LED matrix so that the next LED can be selected
 *
 * Sets all the anodes of the LEDs high and all the cathodes of the LEDs low. This ensures that every LED on the matrix is off so that the next selected LED will not be affected by any previously illuminated LED.
 */
void Clear_LED(void);

/** @}*/
#endif /* LED_MATRIX_H_ */
