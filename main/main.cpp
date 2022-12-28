/**
 * @author [Rubén Garrido]
 * @email [rgarrido.rbn@mail.com]
 * @create date 2021-11-21 13:14:41
 * @modify date 2021-12-22 22:58:07
 */
#include "bluetooth/BLEMidiESP32.h"
#include "button/ButtonManager.h"
#include "esp_log.h"
#include "esp_system.h"
#include "freertos/FreeRTOS.h"
#include "freertos/event_groups.h"
#include "freertos/task.h"
#include "gpio/gpioESP32.h"
#include "led/Led.h"
#include <iostream>
#include <string.h>

extern "C"
{
#include "gpio/gpioDefinition.h"
    void app_main(void);
}

void app_main(void)
{
    ESP_LOGI("INIT PROGRAM", "**** App Init ****");

    createGpioInterruptQueue();

    auto buttonPresetUpPin
        = std::make_shared<gpioESP32>(BUTTON_PRESET_UP_PIN, PAL_GPIO_INTR_POSEDGE, PAL_GPIO_MODE_INPUT, PULLDOWN_MODE);
    auto buttonPresetDownPin = std::make_shared<gpioESP32>(BUTTON_PRESET_DOWN_PIN, PAL_GPIO_INTR_POSEDGE,
                                                           PAL_GPIO_MODE_INPUT, PULLDOWN_MODE);
    ESP_LOGI("INIT PROGRAM", "PRESET BUTTONS SUCCESFULLY INIT");

    auto button1Pin
        = std::make_shared<gpioESP32>(BUTTON_1_PIN, PAL_GPIO_INTR_POSEDGE, PAL_GPIO_MODE_INPUT, PULLDOWN_MODE);
    auto button2Pin
        = std::make_shared<gpioESP32>(BUTTON_2_PIN, PAL_GPIO_INTR_POSEDGE, PAL_GPIO_MODE_INPUT, PULLDOWN_MODE);
    auto button3Pin
        = std::make_shared<gpioESP32>(BUTTON_3_PIN, PAL_GPIO_INTR_POSEDGE, PAL_GPIO_MODE_INPUT, PULLDOWN_MODE);
    auto button4Pin
        = std::make_shared<gpioESP32>(BUTTON_4_PIN, PAL_GPIO_INTR_POSEDGE, PAL_GPIO_MODE_INPUT, PULLDOWN_MODE);
    auto button5Pin
        = std::make_shared<gpioESP32>(BUTTON_5_PIN, PAL_GPIO_INTR_POSEDGE, PAL_GPIO_MODE_INPUT, PULLDOWN_MODE);
    auto button6Pin
        = std::make_shared<gpioESP32>(BUTTON_6_PIN, PAL_GPIO_INTR_POSEDGE, PAL_GPIO_MODE_INPUT, PULLDOWN_MODE);
    ESP_LOGI("INIT PROGRAM", "PEDAL BUTTONS SUCCESFULLY INIT");

    auto led1Pin = std::make_shared<gpioESP32>(LED_1_PIN, PAL_GPIO_INTR_DISABLE, PAL_GPIO_MODE_OUTPUT, PULLDOWN_MODE);
    auto led2Pin = std::make_shared<gpioESP32>(LED_2_PIN, PAL_GPIO_INTR_DISABLE, PAL_GPIO_MODE_OUTPUT, PULLDOWN_MODE);
    auto led3Pin = std::make_shared<gpioESP32>(LED_3_PIN, PAL_GPIO_INTR_DISABLE, PAL_GPIO_MODE_OUTPUT, PULLDOWN_MODE);
    auto led4Pin = std::make_shared<gpioESP32>(LED_4_PIN, PAL_GPIO_INTR_DISABLE, PAL_GPIO_MODE_OUTPUT, PULLDOWN_MODE);
    auto led5Pin = std::make_shared<gpioESP32>(LED_5_PIN, PAL_GPIO_INTR_DISABLE, PAL_GPIO_MODE_OUTPUT, PULLDOWN_MODE);
    auto led6Pin = std::make_shared<gpioESP32>(LED_6_PIN, PAL_GPIO_INTR_DISABLE, PAL_GPIO_MODE_OUTPUT, PULLDOWN_MODE);
    ESP_LOGI("INIT PROGRAM", "LED FOR BUTTONS SUCCESFULLY INIT");

    auto buttonPresetUp = std::make_shared<Button>(buttonPresetUpPin, PRESET_MODE);
    auto buttonPresetDown = std::make_shared<Button>(buttonPresetDownPin, PRESET_MODE);

    auto led1 = std::make_shared<Led>(led1Pin);
    auto led2 = std::make_shared<Led>(led2Pin);
    auto led3 = std::make_shared<Led>(led3Pin);
    auto led4 = std::make_shared<Led>(led4Pin);
    auto led5 = std::make_shared<Led>(led5Pin);
    auto led6 = std::make_shared<Led>(led6Pin);

    auto button1 = std::make_shared<Button>(button1Pin, led1, PEDAL_MODE);
    auto button2 = std::make_shared<Button>(button2Pin, led2, PEDAL_MODE);
    auto button3 = std::make_shared<Button>(button3Pin, led3, PEDAL_MODE);
    auto button4 = std::make_shared<Button>(button4Pin, led4, PEDAL_MODE);
    auto button5 = std::make_shared<Button>(button5Pin, led5, PEDAL_MODE);
    auto button6 = std::make_shared<Button>(button6Pin, led6, PEDAL_MODE);

    auto midiBLEInstance = std::make_shared<BLEMidiESP32>();
    int status = midiBLEInstance->init();
    std::list<buttonPtr> buttonVector
        = {buttonPresetUp, buttonPresetDown, button1, button2, button3, button4, button5, button6};

    /* TODO: entity which manages midi, usb... */

    // auto pedalboardButtonManager = std::make_shared<ButtonManager>(buttonVector, midiBLEInstance, midiUartInstance);
    auto pedalboardButtonManager = std::make_shared<ButtonManager>(buttonVector);

    /********* DEMO MESSAGE ***********/
    uint8_t message[3];
    message[0] = 0x90;
    message[1] = 0x3c;
    message[2] = 0x7f;

    while(1)
    {
        if(status == 0)
        { // means ble midi interface successfully init
            midiBLEInstance->sendMessage(message);
            vTaskDelay(1000 / portTICK_RATE_MS);
        }
    }
}
