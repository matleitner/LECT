#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
SemaphoreHandle_t xMutex;

void writeToBus(char *message)
{
    xSemaphoreTake(xMutex, portMAX_DELAY);
    
        printf("%s\n", message);
    
    xSemaphoreGive( xMutex );
}

void task1(void *params)
{
    while (true)
        {
        printf("reading temperature \n");
        writeToBus("temperature is 25c\n");
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

void task2(void *params)
{
    while (true)
    {
        printf("reading humidity\n");
        writeToBus("humidity is 50 \n");
        vTaskDelay(pdMS_TO_TICKS(2000));
    }
}

void app_main(void)
{
    xMutex = xSemaphoreCreateMutex();
    if( xMutex != NULL ){

        xTaskCreate(&task1, "temperature reading", 2048, NULL, 2, NULL);
        xTaskCreate(&task2, "humidity reading", 2048, NULL, 2, NULL);
    }
}