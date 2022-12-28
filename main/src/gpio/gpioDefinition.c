/*
 * gpioDefinition.cpp
 *
 *  Created on: Nov 20, 2021
 *      Author: rbn
 */

#include "gpio/gpioDefinition.h"
#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"
#include "driver/gpio.h"

const int ENABLE = 1;
const int DISABLE = 0;

xQueueHandle gpioInterruptQueue = NULL;

int gpioInterruptModesLookUpTable[] = {

    GPIO_PIN_INTR_DISABLE,
    GPIO_PIN_INTR_POSEDGE,
    GPIO_PIN_INTR_NEGEDGE,
    GPIO_PIN_INTR_ANYEDGE,
    GPIO_PIN_INTR_LOLEVEL,
    GPIO_PIN_INTR_HILEVEL
};

int gpioModesLookUpTable[] = {

    GPIO_MODE_DISABLE,
    GPIO_MODE_INPUT,
    GPIO_MODE_OUTPUT,
    GPIO_MODE_OUTPUT_OD,
    GPIO_MODE_INPUT_OUTPUT_OD,
    GPIO_MODE_INPUT_OUTPUT,
};

void gpioInitPin(int pinName, int interruptMode, int pinMode, int pullMode)
{
    int gpioPullMode = 0;
    gpio_config_t io_conf;
    io_conf.intr_type = gpioInterruptModesLookUpTable[interruptMode];
    io_conf.mode = gpioModesLookUpTable[pinMode];
    io_conf.pin_bit_mask = (1ULL << pinName);

    if(NOPULL_MODE == pullMode)
    {
        io_conf.pull_down_en = DISABLE;
        io_conf.pull_up_en = DISABLE;
    }
    else if(PULLDOWN_MODE == pullMode)
    {
        io_conf.pull_down_en = ENABLE;
        io_conf.pull_up_en = DISABLE;
    }
    else if(PULLUP_MODE == pullMode)
    {
        io_conf.pull_down_en = DISABLE;
        io_conf.pull_up_en = ENABLE;
    }
    gpio_config(&io_conf);
}

static void IRAM_ATTR buttonInterruptCallbackHandler(void* arg)
{
    int gpioID = (int) arg;
    xQueueSendFromISR(gpioInterruptQueue, &gpioID, NULL);
}
void setButtonInterruptCallback(int pinName)
{
    int gpioID = (int) pinName;
    gpio_isr_handler_add(pinName, buttonInterruptCallbackHandler, (void*) pinName);
}

void createGpioInterruptQueue()
{
    gpioInterruptQueue = xQueueCreate(10, sizeof(uint32_t));
}

