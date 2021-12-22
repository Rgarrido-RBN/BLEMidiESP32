/*
 * gpioESP32.cpp
 *
 *  Created on: Nov 12, 2021
 *      Author: rbn
 */

#include "button/ButtonManager.h"
#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"
#include "freertos/task.h"

const int LED_ON = 1;
const int LED_OFF = 1;

extern xQueueHandle gpioInterruptQueue;

ButtonManager::ButtonManager(buttonPtr button1, buttonPtr button2, 
		buttonPtr button3, buttonPtr button4, buttonPtr button5,
		buttonPtr button6, buttonPtr button7, buttonPtr button8):
	mButton1(button1), mButton2(button2), mButton3(button3), mButton4(button4),
	mButton5(button5), mButton6(button6), mButton7(button7), mButton8(button8)
{
	createManageButtonsTask();
	insertButtonInMap();
}

void ButtonManager::manageButtonEventsTask(void* args)
{
	uint32_t buttonPressed;
	ButtonManager* buttonManagerArgs =  (ButtonManager*)args;
	
	while(1)
	{
		if(xQueueReceive(gpioInterruptQueue, &buttonPressed, portMAX_DELAY))
		{
		    for (auto it = buttonManagerArgs->mButtonMap.find(buttonPressed); it != buttonManagerArgs->mButtonMap.end(); it++) 
			{
                it->second->buttonPressed();
            }
		}
		vTaskDelay(1000 / portTICK_RATE_MS);
	}
}

void ButtonManager::createManageButtonsTask()
{
	xTaskCreate(manageButtonEventsTask, "ButtonEventsTask", 2048, this, 10, NULL);
}

void ButtonManager::insertButtonInMap()
{
	mButtonMap.insert(make_pair(mButton1->getPin(), mButton1));
	mButtonMap.insert(make_pair(mButton2->getPin(), mButton2));
	mButtonMap.insert(make_pair(mButton3->getPin(), mButton3));
	mButtonMap.insert(make_pair(mButton4->getPin(), mButton4));
	mButtonMap.insert(make_pair(mButton5->getPin(), mButton5));
	mButtonMap.insert(make_pair(mButton6->getPin(), mButton6));
	mButtonMap.insert(make_pair(mButton7->getPin(), mButton7));
	mButtonMap.insert(make_pair(mButton8->getPin(), mButton8));
}