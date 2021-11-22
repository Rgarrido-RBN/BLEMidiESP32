/**
 * @author [Rubén Garrido]
 * @email [rgarrido.rbn@mail.com]
 * @create date 2021-11-21 13:14:41
 * @modify date 2021-11-21 13:14:41
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
  
  std::shared_ptr<Button> buttonPresetUp = std::make_shared<Button>(buttonPresetUpPin);
  std::shared_ptr<Button> buttonPresetDown = std::make_shared<Button>(buttonPresetDownPin);
  std::shared_ptr<Button> button1 = std::make_shared<Button>(button1Pin);
  std::shared_ptr<Button> button2 = std::make_shared<Button>(button2Pin);
  std::shared_ptr<Button> button3 = std::make_shared<Button>(button3Pin);
  std::shared_ptr<Button> button4 = std::make_shared<Button>(button4Pin);
  std::shared_ptr<Button> button5 = std::make_shared<Button>(button5Pin);
  std::shared_ptr<Button> button6 = std::make_shared<Button>(button6Pin);

  std::shared_ptr<ButtonManager> pedalboardButtonManager = std::make_shared<ButtonManager>(buttonPresetUp, buttonPresetDown, 
    button1, button2, button3, button4, button5, button6);
  
  while(1)
  {
    

  }
}
