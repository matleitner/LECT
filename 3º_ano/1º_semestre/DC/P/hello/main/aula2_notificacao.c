#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
static TaskHandle_t receiverHandler = NULL;
void sender(void * params)
{
    while (true)
    {   
        for(int i=0; i<4; i++) {
            xTaskNotifyGive(receiverHandler);
        }
        vTaskDelay(pdMS_TO_TICKS(5000));
    }
}

void receiver(void * params)
{
    while (true)
    {

        uint32_t count = ulTaskNotifyTake(pdTRUE, portMAX_DELAY);
        //printf("portMAX_DELAY: %lu\n", portMAX_DELAY);
        printf("received notification %ld times\n", count );
    }
}

void app_main(void)
{
    xTaskCreate(&receiver, "receiver", 2048, NULL, 2, &receiverHandler);
    xTaskCreate(&sender, "sender", 2048, NULL, 2, NULL);
}