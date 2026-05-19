#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gptimer.h"
#include "driver/gpio.h"
#include "esp_check.h"

#define GPIO_SQUARE_WAVE 11
volatile uint8_t state = 0;
volatile uint32_t my_counter = 0;

static bool timer_isr_callback(gptimer_handle_t timer, const gptimer_alarm_event_data_t *edata, void *user_data) {
    
    state= !state;
    my_counter++;
    return false;
}

void app_main(void) {
    printf("Starting square wave generator...\n");

    // Configura GPIO 11
    gpio_reset_pin(GPIO_SQUARE_WAVE);
    gpio_set_direction(GPIO_SQUARE_WAVE, GPIO_MODE_OUTPUT);
    
    
    // I) Instanciar e configurar o temporizador (1 MHz de resolução).
    // Configuração do timer
    gptimer_handle_t my_timer = NULL;
    gptimer_config_t timer_config = {
        .clk_src = GPTIMER_CLK_SRC_DEFAULT,
        .direction = GPTIMER_COUNT_UP,
        .resolution_hz = 1000000, // 1 MHz
    };
    ESP_ERROR_CHECK(gptimer_new_timer(&timer_config, &my_timer));

    // II) Configurar a ISR
    gptimer_event_callbacks_t cbs = {
        .on_alarm = timer_isr_callback,
    };
    ESP_ERROR_CHECK(gptimer_register_event_callbacks(my_timer, &cbs, NULL));

    //  // III) Configurar o alarme 
    gptimer_alarm_config_t alarm_config = {
        .alarm_count = 10000,       // 500_000 para 0.5s ligado ou seja 1Hz 10_000 para 50Hz
        .reload_count = 0,
        .flags.auto_reload_on_alarm = true,
    };
    ESP_ERROR_CHECK(gptimer_set_alarm_action(my_timer, &alarm_config));

    //IV) Ativar e iniciar timer
    ESP_ERROR_CHECK(gptimer_enable(my_timer));
    ESP_ERROR_CHECK(gptimer_start(my_timer));

    // Loop principal opcional
    while (1) {
        printf("Square wave toggles: %lu\n", my_counter);
        gpio_set_level(GPIO_SQUARE_WAVE, state);
        vTaskDelay(10 / portTICK_PERIOD_MS);
    }
}

