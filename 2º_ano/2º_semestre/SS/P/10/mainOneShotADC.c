#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_adc/adc_oneshot.h"
#include "esp_log.h"    // Acesso à lib de logging. Permite usar ESP_LOGI com funcionalidades mais avançadas que o printf, como definir
                        //níveis de "severidade", timestamps, tags, e filtragem por nível de "severidade", etc.
                        // https://docs.espressif.com/projects/esp-idf/en/latest/esp32c6/api-reference/system/log.html

#define ADC_INPUT ADC_CHANNEL_3

// Etiqueta para os logs no terminal
static const char *TAG = "ADC_EXEMPLO";

void app_main(void) {

    ESP_LOGI(TAG, "Starting adc one-shot mode demo...");

    // I) Instanciar e configurar módulo ADC
    adc_oneshot_unit_handle_t adc1_handle;
    adc_oneshot_unit_init_cfg_t init_config = {
        .unit_id = ADC_UNIT_1,                  // Usar o módulo ADC 1
        .clk_src = ADC_DIGI_CLK_SRC_DEFAULT,    // Usar o default clock
        .ulp_mode = ADC_ULP_MODE_DISABLE,       // Desactivar modo de ultra-baixo consumo
    };
    ESP_ERROR_CHECK(adc_oneshot_new_unit(&init_config, &adc1_handle));

    // II) Configurar o canal da ADC
    adc_oneshot_chan_cfg_t channel_config = {
        .bitwidth = ADC_BITWIDTH_12,    // Resolução padrão de 12 bits (níveis de 0 a 4095)
        .atten = ADC_ATTEN_DB_12,       // Atenuação máxima (12dB) para conseguir ler tensões até ~3.9V
    };
    
    ESP_ERROR_CHECK(adc_oneshot_config_channel(adc1_handle, ADC_INPUT, &channel_config));

    int raw_value = 0;
    float value_in_volts = 0.0;
    ESP_LOGI(TAG, "A iniciar leituras a cada 0.5 segundos...");

    while (1) {
        // III) Efetua a leitura do canal e guarda em 'valor_lido_raw'
        esp_err_t erro = adc_oneshot_read(adc1_handle, ADC_INPUT, &raw_value);
        
        if (erro == ESP_OK) {
            // Converte o valor digital bruto (0-4095) para Volts (0.0 - 3.9)
            // Nota: O cast (float) é crucial para evitar que o C faça uma divisão inteira e corte os decimais!
            value_in_volts = ((float)raw_value / 4095.0) * 3.9;

            // Imprime o valor bruto e o valor convertido (com 2 casas decimais)
            ESP_LOGI(TAG, "Amostra: %d -> Tensao: %.2f V\n", raw_value, value_in_volts);
        } else {
            ESP_LOGE(TAG, "Falha ao ler a ADC!");
        }

        // Pausa exata de 0.5 segundos (fs = 2 Hz)
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}
