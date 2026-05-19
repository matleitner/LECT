#include <stdio.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "esp_adc/adc_continuous.h"
#include "esp_log.h"

static const char *TAG = "ADC_DMA";

#define SAMPLING_FREQUENCY_HZ 20000     // fs = 20 kHz. Existem valores mínimos e máximos suportados pela ADC, definidos
                                        // pelas macro SOC_ADC_SAMPLE_FREQ_THRES_LOW e SOC_ADC_SAMPLE_FREQ_THRES_HIGH respetivamente. Macros definidas em "soc/soc_caps.h").
#define SAMPLING_OBSERVATION_TIME_SECONDS 1 // X: Tempo de observação para garantir resolução de 1 Hz.
#define SAMPLES_NUMBER_GOAL (SAMPLING_FREQUENCY_HZ * SAMPLING_OBSERVATION_TIME_SECONDS) // Número exato de amostras necessárias (N = fs * X).

// Vamos definir conversion frames com 64 amostras que resulta em cerca de 64 * 4 = 256 Bytes (SOC_ADC_DIGI_RESULT_BYTES no nosso caso é 4 Bytes).
// Temos assim um equilíbrio entre recursos necessários e número de vezes que o CPU é interrompido para a operação de leitura da frame (p. ex., caso usemos ISR).
#define CONVERSION_FRAME_LENGTH (64 * SOC_ADC_DIGI_RESULT_BYTES)

// !! A stack FreeRTOS para app_main é reduzida (4 a 8 KB). A declaração de variáveis "gigantes", como o array seguinte, deve ser feita aqui para ser alocada em RAM,
// caso contrário, vamos ter stack overflow e o programa "morre".
float processed_samples[SAMPLES_NUMBER_GOAL];  // Para guardar as nossas amostras processadas (p. ex., para depois usarmos no Octave).
uint32_t number_proccesed_samples = 0;          // Contador com o número de amostras processadas e guardadas no nosso buffer principal.

void app_main(void) {
    ESP_LOGI(TAG, "Starting adc continuous mode demo...");

    // I) Instanciar e configurar driver.
    adc_continuous_handle_t adc_handle = NULL;
    adc_continuous_handle_cfg_t adc_handle_config = {
        .max_store_buf_size = 4 * CONVERSION_FRAME_LENGTH,  // Tamanho do buffer interno do driver para guardar amostras. // Deverá ser no mínimo o dobro de CONVERSION_FRAME_LENGTH.                     
        .conv_frame_size = CONVERSION_FRAME_LENGTH,         // Tamanho de cada conversion frame.
    };
    ESP_ERROR_CHECK(adc_continuous_new_handle(&adc_handle_config, &adc_handle));

    // II) Configurar canal e módulo ADC.
    adc_digi_pattern_config_t channel_config = {
        .channel = ADC_CHANNEL_3,       // Vamos amostrar o Canal 3 (GPIO 3 no ESP32-C6).
        .atten = ADC_ATTEN_DB_12,       // Atenuação máxima (12dB) para conseguir ler tensões até ~3.9V.
        .unit = ADC_UNIT_1,             // Usar o módulo ADC 1.
        .bit_width = ADC_BITWIDTH_12,   // Resolução padrão de 12 bits (níveis de 0 a 4095). !! Nota para evitar confusão: pode reparar que este campo neste driver é ".bit_width"
                                        // e não ".bitwidth" como no driver one-shot. O porquê desta inconsistência...não sabemos. 
    };
    adc_continuous_config_t adc_config = {
        .pattern_num = 1,                           // Apenas um canal vai ser usado.
        .adc_pattern = &channel_config,             // Lista com a configuração para cada um dos canais usados.
        .sample_freq_hz = SAMPLING_FREQUENCY_HZ,    // Frequência de amostragem esperada.
        .conv_mode = ADC_CONV_SINGLE_UNIT_1,        // Apenas usar o módulo ADC 1 para conversão.
        .format = ADC_DIGI_OUTPUT_FORMAT_TYPE2,     // Existem dois formatos de estruturas de dados para armazenar o valor de cada
                                                    // amostra e metadata associada: ADC_DIGI_OUTPUT_FORMAT_TYPE1 e ADC_DIGI_OUTPUT_FORMAT_TYPE2.
                                                    // O formato padrão para o ESP32-C6 (e outros recentes) é ADC_DIGI_OUTPUT_FORMAT_TYPE2.
    };
    ESP_ERROR_CHECK(adc_continuous_config(adc_handle, &adc_config));

    uint8_t dma_buffer[CONVERSION_FRAME_LENGTH];    // Buffer para a transferência de uma conversion frame da ADC para o nosso programa via DMA.
    uint32_t number_read_bytes = 0;                 // Variável que irá indicar quantos bytes foram transferidos via DMA.

    // III) Iniciar a amostragem.
    ESP_ERROR_CHECK(adc_continuous_start(adc_handle));

    // IV) Transferir e processar conversion frames
    while (1) {
        // Pedir uma conversion frame completa via DMA. A função bloqueia até os dados estarem prontos.
        esp_err_t erro = adc_continuous_read(adc_handle, dma_buffer, CONVERSION_FRAME_LENGTH, &number_read_bytes, portMAX_DELAY);
        
        if (erro == ESP_OK) {
            // Pode acontecer por vezes o número de amostras na frame ser inferior ao pedido (frame "incompleta"). 
            // É boa prática calcular sempre quantas amostras efetivamente estão presentes na frame obtida.
            uint32_t frame_samples_number = number_read_bytes / SOC_ADC_DIGI_RESULT_BYTES;

            // Extrair, converter e guardar cada amostra obtida no nosso buffer principal.
            for (int sample_index = 0; sample_index < frame_samples_number; sample_index++) {
                
                // Se já atingimos a nossa meta de tempo (X segundos), paramos de guardar
                if (number_proccesed_samples >= SAMPLES_NUMBER_GOAL) {
                    break; 
                }

                // Extrair a amostra usando a estrutura oficial da Espressif.
                adc_digi_output_data_t *dados = (adc_digi_output_data_t*)&dma_buffer[sample_index * SOC_ADC_DIGI_RESULT_BYTES];
                uint32_t raw_sample = dados->type2.data; 

                // Converter para Volts e guardar no nosso buffer principal.
                processed_samples[number_proccesed_samples] = ((float)raw_sample / 4095.0) * 3.9;
                
                number_proccesed_samples++;
            }

            if (number_proccesed_samples >= SAMPLES_NUMBER_GOAL) {
                ESP_LOGI(TAG, "Desired number of samples achieved! Stopping sampling. First 10 collected samples:\n");
                ESP_ERROR_CHECK(adc_continuous_stop(adc_handle));
                for(int sample_index = 0; sample_index < 10; sample_index++) {
                    ESP_LOGI(TAG, "Sample %d: %.2f V\n", sample_index, processed_samples[sample_index]);
                }
                break;
            }
        }
    }
}

