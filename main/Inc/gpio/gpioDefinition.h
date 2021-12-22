/*
 * gpioDefinition.h
 *
 *  Created on: Nov 20, 2021
 *      Author: rbn
 */

#ifndef MAIN_INC_GPIO_GPIODEFINITION_H_
#define MAIN_INC_GPIO_GPIODEFINITION_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "driver/gpio.h"

const int BUTTON_PRESET_UP_PIN = 5;
const int BUTTON_PRESET_DOWN_PIN = 6;
const int BUTTON_1_PIN = 7;
const int BUTTON_2_PIN = 8;
const int BUTTON_3_PIN = 9;
const int BUTTON_4_PIN = 10;
const int BUTTON_5_PIN = 11;
const int BUTTON_6_PIN = 12;
const int LED_1_PIN = 13;
const int LED_2_PIN = 14;
const int LED_3_PIN = 15;
const int LED_4_PIN = 16;
const int LED_5_PIN = 17;
const int LED_6_PIN = 18;

typedef enum {
    NOPULL_MODE = 0,
    PULLDOWN_MODE = 1,
    PULLUP_MODE = 2,
} gpioPullModes;

typedef enum {
    PAL_GPIO_INTR_DISABLE = 0,
    PAL_GPIO_INTR_POSEDGE = 1,
    PAL_GPIO_INTR_NEGEDGE = 2,
    PAL_GPIO_INTR_ANYEDGE = 3,
    PAL_GPIO_INTR_LOLEVEL = 4,
    PAL_GPIO_INTR_HILEVEL = 5
} gpioInterruptModes;

typedef enum {
    PAL_GPIO_MODE_DISABLE = 0,
    PAL_GPIO_MODE_INPUT,
    PAL_GPIO_MODE_OUTPUT,
    PAL_GPIO_MODE_OUTPUT_OD,
    PAL_GPIO_MODE_INPUT_OUTPUT_OD,
    PAL_GPIO_MODE_INPUT_OUTPUT,
} gpioModes;

void gpioInitPin(int pinName, int interruptMode, int pinMode, int pullMode);
void setButtonInterruptCallback(int pinName);

#endif /* MAIN_INC_GPIO_GPIODEFINITION_H_ */