#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_adc/adc_oneshot.h"
#define ADC_CHANNEL ADC_CHANNEL_0 // GPIO0 (check pin mapping for ESP32-C6)
#define ADC_UNIT ADC_UNIT_1 // Use ADC1
#define ADC_ATTEN ADC_ATTEN_DB_12 // 12 dB, ~1.1 V full-scale
void app_main(void)
{
    // ADC Oneshot driver handle
    adc_oneshot_unit_handle_t adc1_handle;
    adc_oneshot_unit_init_cfg_t init_config1 = {
        .unit_id = ADC_UNIT,
    };
    adc_oneshot_new_unit(&init_config1, &adc1_handle);
    // Configure channel
    adc_oneshot_chan_cfg_t config = {
        .atten = ADC_ATTEN,
        .bitwidth = ADC_BITWIDTH_DEFAULT, // default = 12-bit
    };
    adc_oneshot_config_channel(adc1_handle, ADC_CHANNEL, &config);

    while (1) {
        int adc_raw = 0;
        adc_oneshot_read(adc1_handle, ADC_CHANNEL, &adc_raw);
        // Convert raw value to voltage (approximate, no calibration)
        float voltage = (adc_raw / 4095.0f) *  3.3f;// (1.1f/0.25f);
        // INCLUA AQUI O CODIGO PARA IMPRIMIR O VALOR DIGITAL LIDO E O CORREPONDENTE ANALOGICO
        printf("\rRaw: %d, Voltage: %.2f V",adc_raw, voltage);
        vTaskDelay(pdMS_TO_TICKS(10));
    }
}
  