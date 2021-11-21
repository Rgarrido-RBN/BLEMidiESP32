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

const int BUTTON_PRESET_PIN = 11;

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