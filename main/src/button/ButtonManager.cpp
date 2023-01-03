/*
 * gpioESP32.cpp
 *
 *  Created on: Nov 12, 2021
 *      Author: rbn
 */

#include "button/ButtonManager.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"
#include "freertos/task.h"

const int LED_ON = 1;
const int LED_OFF = 1;
static const char* TAG= "ButtonManager";

extern xQueueHandle gpioInterruptQueue;

// TODO: Send a list of buttons instead of all buttons
ButtonManager::ButtonManager(std::list<buttonPtr> buttonList, std::shared_ptr<MidiInterface> midiIface)
    : mButtonList(buttonList)
    , mMidiIface(midiIface)
{
    ESP_LOGI(TAG, "Button Manager Initialise");
    mMidiIface->openMidiBLE();
    mMidiIface->openMidiUART();

    createManageButtonsTask();
}

/* When a button is pressed we look for on a map for the button
 pressed and using a getter we know his message to send it to
  MIDI instance */

void ButtonManager::manageButtonEventsTask(void *args)
{
    uint32_t buttonPressed;
    ButtonManager *_this = (ButtonManager *)args;
    while(1)
    {
        if(gpioInterruptQueue != NULL)
        {
            if(xQueueReceive(gpioInterruptQueue, &buttonPressed, portMAX_DELAY))
            {
                for(auto &it : _this->mButtonList)
                {
                    if(it->getPin() == buttonPressed)
                    {
                        _this->mMidiIface->sendMidiMessage(it->getMidiMessage());
                    }
                }
            }
            vTaskDelay(1000 / portTICK_RATE_MS);
        }
    }
}

void ButtonManager::createManageButtonsTask()
{
    xTaskCreate(manageButtonEventsTask, "ButtonEventsTask", 2048, this, 10, NULL);
}

