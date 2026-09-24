#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#define INPUT_GPIO GPIO_NUM_9 // choose an available GPIO on your board
#define BLINK_GPIO GPIO_NUM_10 // GPIO10 on ESP32-C6

void app_main(void) {
    // Configure the GPIO as input with pull-up enabled
    gpio_config_t io_config_button = {
        .pin_bit_mask = 1ULL << INPUT_GPIO, // bit mask for selected GPIO
        .mode = GPIO_MODE_INPUT,
        .pull_up_en = GPIO_PULLUP_ENABLE, // enable internal pull-up
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .intr_type = GPIO_INTR_DISABLE
    };
    gpio_config(&io_config_button);

    gpio_config_t io_config_led = {
        .pin_bit_mask = 1ULL << BLINK_GPIO, // bit mask for GPIO10
        .mode = GPIO_MODE_OUTPUT,
        .pull_up_en = GPIO_PULLUP_DISABLE,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .intr_type = GPIO_INTR_DISABLE
    };
    gpio_config(&io_config_led);

    while (1) {
        int level = gpio_get_level(INPUT_GPIO); // read the pin state (0 or 1)
        // INCLUA AQUI O CODIGO PARA IMPRIMIR O ESTADO DO BOTAO
        gpio_set_level(BLINK_GPIO, !level);

        printf("Estado do botão %d\n", !level);

        vTaskDelay(pdMS_TO_TICKS(1000)); // check every 1s
    }
}