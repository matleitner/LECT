#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void vTask1(void *pvParameters)
{
    while (true)
    {
        printf("reading temperature from %s\n",(char*)pvParameters);
        // ficar estado de suspensão durante 1000 ms 
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

void vTask2(void *pvParameters) {
    while (true) {
        printf("reading humidity from %s\n", (char*)pvParameters);
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

void app_main(void) {
    const char* taskID1 = "Task 1";
    const char* taskID2 = "Task 2";
    xTaskCreate(vTask1, "Task 1", 2048, (void*)taskID1, 1, NULL);
    xTaskCreate(vTask2, "Task 2", 2048, (void*)taskID2, 1, NULL);
    //vTaskStartScheduler();
}
