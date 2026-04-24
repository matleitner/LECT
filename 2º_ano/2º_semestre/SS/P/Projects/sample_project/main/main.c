#include <stdio.h>
#include "driver/gpio.h"
#include "freertos/task.h"
void app_main(void)

{
    gpio_reset_pin(GPIO_NUM_11);
    gpio_set_direction(GPIO_NUM_11, GPIO_MODE_OUTPUT);
    int level = 0;
    while(1){
        
        gpio_set_level(GPIO_NUM_11, level);
        vTaskDelay(50);
        level = !level;
    }

}    

