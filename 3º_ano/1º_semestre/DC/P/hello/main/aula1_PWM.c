#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "driver/gpio.h"
#include "freertos/task.h"
#include "driver/ledc.h"
#define LED_GPIO GPIO_NUM_10
#define LEDC_CHANNEL LEDC_CHANNEL_0
#define LEDC_TIMER LEDC_TIMER_0
#define LEDC_MODE LEDC_LOW_SPEED_MODE
#define LEDC_DUTY_RES LEDC_TIMER_13_BIT // 13-bit resolution
#define LEDC_FREQUENCY 5000
// 5 kHz PWM
void app_main(void)
{
    // 1. Configure timer
    ledc_timer_config_t ledc_timer = {
    .speed_mode = LEDC_MODE,
    .timer_num = LEDC_TIMER,
    .duty_resolution = LEDC_DUTY_RES,
    .freq_hz = LEDC_FREQUENCY,
    .clk_cfg = LEDC_AUTO_CLK
    };

    ledc_timer_config(&ledc_timer);
    // 2. Configure channel
    ledc_channel_config_t ledc_channel = {
        .gpio_num = LED_GPIO,
        .speed_mode= LEDC_MODE,
        .channel = LEDC_CHANNEL,
        .intr_type = LEDC_INTR_DISABLE,
        .timer_sel = LEDC_TIMER, 
        .duty = 0, 
        .hpoint = 0
    };

    ledc_channel_config(&ledc_channel);
    uint32_t max_duty = (1 << LEDC_DUTY_RES) - 1;
    int32_t duty_increment = 0;  // max * 1 / 100
    int32_t step = max_duty/100;

    int8_t toggle_sum_sub = 1;  
    while (1) {
        ledc_set_duty(LEDC_MODE, LEDC_CHANNEL, (uint32_t)duty_increment);
        ledc_update_duty(LEDC_MODE, LEDC_CHANNEL);
        vTaskDelay(pdMS_TO_TICKS(20));

        duty_increment += step * toggle_sum_sub;

        if(duty_increment >= (int32_t) max_duty) {
            toggle_sum_sub = -1;
            duty_increment = max_duty;
        }else if (duty_increment <= 0) {
            duty_increment = 0;
            toggle_sum_sub = 1;
        }
    }
}