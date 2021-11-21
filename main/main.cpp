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

  std::shared_ptr<gpioAbs> buttonPreset = std::make_shared<gpioESP32>(BUTTON_PRESET_PIN, PAL_GPIO_INTR_POSEDGE , PAL_GPIO_MODE_INPUT, PULLDOWN_MODE);

  while(1)
  {

  }
}
