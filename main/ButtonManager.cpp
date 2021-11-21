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

extern xQueueHandle gpioInterruptQueue;

ButtonManager::ButtonManager(buttonPtr button1, buttonPtr button2, 
		buttonPtr button3, buttonPtr button4, buttonPtr button5,
		buttonPtr button6, buttonPtr button7, buttonPtr button8):
	mButton1(button1), mButton2(button2), mButton3(button3), mButton4(button4),
	mButton5(button5), mButton6(button6), mButton7(button7), mButton8(button8)
{
	createManageButtonsTask();
}

void ButtonManager::manageButtonEventsTask(void* args)
{
	uint32_t buttonPressed;
	while(1)
	{
		if(xQueueReceive(gpioInterruptQueue, &buttonPressed, portMAX_DELAY))
		{
			//TODO: Implement logic for button pressed
		}
		vTaskDelay(1000 / portTICK_RATE_MS);
	}
}

void ButtonManager::createManageButtonsTask()
{
	xTaskCreate(manageButtonEventsTask, "ButtonEventsTask", 2048, this, 10, NULL);
} 