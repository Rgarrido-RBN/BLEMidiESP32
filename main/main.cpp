/**
 * @author [Rubén Garrido]
 * @email [rgarrido.rbn@mail.com]
 * @create date 2021-11-21 13:14:41
 * @modify date 2021-12-22 22:58:07
 */
#include <iostream>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
extern "C"
{
  #include "esp_system.h"
  #include "esp_log.h"
  #include "blemidi.h"
  #include "gpio/gpioDefinition.h"
}
#include "gpio/gpioESP32.h"
#include "button/Button.h"
#include "button/ButtonManager.h"
#include "led/Led.h"

extern "C"
{
  void app_main(void);
}

void app_main(void)
{
    ESP_LOGI("INIT PROGRAM", "**** App Init ****");

    std::shared_ptr<gpioAbs> buttonPresetUpPin = std::make_shared<gpioESP32>(BUTTON_PRESET_UP_PIN, PAL_GPIO_INTR_POSEDGE, PAL_GPIO_MODE_INPUT, PULLDOWN_MODE);
    std::shared_ptr<gpioAbs> buttonPresetDownPin = std::make_shared<gpioESP32>(BUTTON_PRESET_DOWN_PIN, PAL_GPIO_INTR_POSEDGE, PAL_GPIO_MODE_INPUT, PULLDOWN_MODE);
    
    std::shared_ptr<gpioAbs> button1Pin = std::make_shared<gpioESP32>(BUTTON_1_PIN, PAL_GPIO_INTR_POSEDGE, PAL_GPIO_MODE_INPUT, PULLDOWN_MODE);
    std::shared_ptr<gpioAbs> button2Pin = std::make_shared<gpioESP32>(BUTTON_2_PIN, PAL_GPIO_INTR_POSEDGE, PAL_GPIO_MODE_INPUT, PULLDOWN_MODE);
    std::shared_ptr<gpioAbs> button3Pin = std::make_shared<gpioESP32>(BUTTON_3_PIN, PAL_GPIO_INTR_POSEDGE, PAL_GPIO_MODE_INPUT, PULLDOWN_MODE);
    std::shared_ptr<gpioAbs> button4Pin = std::make_shared<gpioESP32>(BUTTON_4_PIN, PAL_GPIO_INTR_POSEDGE, PAL_GPIO_MODE_INPUT, PULLDOWN_MODE);
    std::shared_ptr<gpioAbs> button5Pin = std::make_shared<gpioESP32>(BUTTON_5_PIN, PAL_GPIO_INTR_POSEDGE, PAL_GPIO_MODE_INPUT, PULLDOWN_MODE);
    std::shared_ptr<gpioAbs> button6Pin = std::make_shared<gpioESP32>(BUTTON_6_PIN, PAL_GPIO_INTR_POSEDGE, PAL_GPIO_MODE_INPUT, PULLDOWN_MODE);

    std::shared_ptr<gpioAbs> led1Pin = std::make_shared<gpioESP32>(LED_1_PIN, PAL_GPIO_INTR_DISABLE, PAL_GPIO_MODE_OUTPUT, PULLDOWN_MODE);
    std::shared_ptr<gpioAbs> led2Pin = std::make_shared<gpioESP32>(LED_2_PIN, PAL_GPIO_INTR_DISABLE, PAL_GPIO_MODE_OUTPUT, PULLDOWN_MODE);
    std::shared_ptr<gpioAbs> led3Pin = std::make_shared<gpioESP32>(LED_3_PIN, PAL_GPIO_INTR_DISABLE, PAL_GPIO_MODE_OUTPUT, PULLDOWN_MODE);
    std::shared_ptr<gpioAbs> led4Pin = std::make_shared<gpioESP32>(LED_4_PIN, PAL_GPIO_INTR_DISABLE, PAL_GPIO_MODE_OUTPUT, PULLDOWN_MODE);
    std::shared_ptr<gpioAbs> led5Pin = std::make_shared<gpioESP32>(LED_5_PIN, PAL_GPIO_INTR_DISABLE, PAL_GPIO_MODE_OUTPUT, PULLDOWN_MODE);
    std::shared_ptr<gpioAbs> led6Pin = std::make_shared<gpioESP32>(LED_6_PIN, PAL_GPIO_INTR_DISABLE, PAL_GPIO_MODE_OUTPUT, PULLDOWN_MODE);

    std::shared_ptr<Button> buttonPresetUp = std::make_shared<Button>(buttonPresetUpPin);
    std::shared_ptr<Button> buttonPresetDown = std::make_shared<Button>(buttonPresetDownPin);
    buttonPresetUp->convertToBankButton();
    buttonPresetDown->convertToBankButton();

    std::shared_ptr<Led> led1 = std::make_shared<Led>(led1Pin);
    std::shared_ptr<Led> led2 = std::make_shared<Led>(led2Pin);
    std::shared_ptr<Led> led3 = std::make_shared<Led>(led3Pin);
    std::shared_ptr<Led> led4 = std::make_shared<Led>(led4Pin);
    std::shared_ptr<Led> led5 = std::make_shared<Led>(led5Pin);
    std::shared_ptr<Led> led6 = std::make_shared<Led>(led6Pin);  

    std::shared_ptr<Button> button1 = std::make_shared<Button>(button1Pin, led1);
    std::shared_ptr<Button> button2 = std::make_shared<Button>(button2Pin, led2);
    std::shared_ptr<Button> button3 = std::make_shared<Button>(button3Pin, led3);
    std::shared_ptr<Button> button4 = std::make_shared<Button>(button4Pin, led4);
    std::shared_ptr<Button> button5 = std::make_shared<Button>(button5Pin, led5);
    std::shared_ptr<Button> button6 = std::make_shared<Button>(button6Pin, led6);
  
    std::shared_ptr<ButtonManager> pedalboardButtonManager = std::make_shared<ButtonManager>(buttonPresetUp, buttonPresetDown, 
      button1, button2, button3, button4, button5, button6);
  
    while(1)
    {
        vTaskDelay(1000 / portTICK_RATE_MS);
    }
}
