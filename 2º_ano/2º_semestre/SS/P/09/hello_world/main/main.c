#include <stdio.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/ledc.h"

#define GPIO_11 11
#define GPIO_9 9

volatile int state;

void app_main(void)
{   
    // 3- Tutorial Inicial
    printf("Hello world de ESP32 !!\n");
    
    // 4Desenvolva um programa que faça o LED externo,
    // ligado ao GPIO 11, piscar continuamente
    // a uma frequência exata de 1Hz e um duty-cycle de 50%
    state = 0;
    gpio_reset_pin(GPIO_11);

    gpio_set_direction(GPIO_11, GPIO_MODE_OUTPUT);

    // 4.2 - Entradas digitais – polling de estado de um botão
    gpio_set_direction(GPIO_9, GPIO_MODE_INPUT);
    int prev_state = gpio_get_level(GPIO_9);
    int gpio9_state;
    //while (1)
    //{
        /* 4.1
        gpio_set_level(GPIO_11, state);
        state = !state;
        
        vTaskDelay(500 / portTICK_PERIOD_MS);
        */
            /* 4.2
            gpio9_state = gpio_get_level(GPIO_9);       // pressionado dá 0, solto dá 1 
            if (gpio9_state != prev_state){
                if(gpio9_state){
                    printf("[EVENTO] Botão largado!\n");
                }else{
                    printf("[EVENTO] Botão pressionado!\n");
                }
                prev_state = gpio9_state;
            }
            
            vTaskDelay(pdMS_TO_TICKS(10));
            */
    //}
    
    // 5 
    // Para frequências de 1Hz, 5Hz e 10Hz:
    // 1Hz -> Período 1000ms -> Delay de 500ms
    // 5Hz -> Período 200ms  -> Delay de 100ms
    // 10Hz -> Período 100ms -> Delay de 50ms
    int freqs[3] ={500, 100,50};
    int counter = 0;
    while(1){
        for (int dutyCycle = 0; dutyCycle <= 255; dutyCycle++) {
            ledc_set_pin(GPIO_11, dutyCycle);
            vTaskDelay(pdMS_TO_TICKS(10));
        }
        for (int dutyCycle = 255; dutyCycle >= 0; dutyCycle--) {
            ledcWrite(ledcChannel, dutyCycle);
            vTaskDelay(pdMS_TO_TICKS(10));

        }

        gpio9_state = gpio_get_level(GPIO_9);
        if(!gpio9_state && (prev_state != gpio9_state) ){
            counter = (counter+1)%3;
            printf("delay: %d\n", freqs[counter]);
        }
        state = !state;
        prev_state = gpio9_state;
        vTaskDelay(pdMS_TO_TICKS(freqs[counter]));

    }
    

}