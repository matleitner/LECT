#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <stdio.h>

#define BLINK_GPIO GPIO_NUM_10 // GPIO10 on ESP32-C6
void app_main(void) {
  // Configure GPIO10 as output
  gpio_config_t io_conf = {.pin_bit_mask = 1ULL << BLINK_GPIO, // bit mask for GPIO10
    .mode = GPIO_MODE_OUTPUT,
    .pull_up_en = GPIO_PULLUP_DISABLE,
    .pull_down_en = GPIO_PULLDOWN_DISABLE,
    .intr_type = GPIO_INTR_DISABLE
  };
  
  gpio_config(&io_conf);
  bool level = false;
  
  while (1) {
    gpio_set_level(BLINK_GPIO, level);
    level = !level;                  // invert for next toggle
    vTaskDelay(pdMS_TO_TICKS(1000)); // delay 1 second
    printf("GPIO level set to %d\n", level);
  }
}
