#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gptimer.h"
#include "driver/gpio.h"
#include "esp_adc/adc_continuous.h"
#include "esp_check.h"

#define GPIO_SQUARE_WAVE 11

static const char *TAG = "ADC_DMA";
volatile uint8_t state = 0;
volatile uint32_t my_counter = 0;

// função isr
static bool timer_isr_callback(gptimer_handle_t timer, const gptimer_alarm_event_data_t *edata, void *user_data) {
    
    state= !state;
    gpio_set_level(GPIO_SQUARE_WAVE, 1);
    my_counter++;
    return false;
}


// ######################## 4.1 ######################## 
void timer_cfg(){
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
}
// ########################     ######################## 


// ######################## 4.2 ########################
// MACROS para ADC
#define TIMES              1
#define BUFFER_SIZE        4096    // N calculado
#define READ_LEN           256
#define SAMPLING_FREQUENCY_HZ 20000     // fs = 20 kHz. Existem valores mínimos e máximos suportados pela ADC, definidos
                                        // pelas macro SOC_ADC_SAMPLE_FREQ_THRES_LOW e SOC_ADC_SAMPLE_FREQ_THRES_HIGH respetivamente. Macros definidas em "soc/soc_caps.h").
#define SAMPLING_OBSERVATION_TIME_SECONDS 1 // X: Tempo de observação para garantir resolução de 1 Hz.


// Vamos definir conversion frames com 64 amostras que resulta em cerca de 64 * 4 = 256 Bytes (SOC_ADC_DIGI_RESULT_BYTES no nosso caso é 4 Bytes).
// Temos assim um equilíbrio entre recursos necessários e número de vezes que o CPU é interrompido para a operação de leitura da frame (p. ex., caso usemos ISR).
#define CONVERSION_FRAME_LENGTH (64 * SOC_ADC_DIGI_RESULT_BYTES)

float processed_samples[BUFFER_SIZE];           // Para guardar as nossas amostras processadas (p. ex., para depois usarmos no Octave).
uint32_t number_proccesed_samples = 0;          // Contador com o número de amostras processadas e guardadas no nosso buffer principal.

void app_main(void) {
    printf("Starting square wave generator...\n");
    // Configura GPIO 11

    gpio_reset_pin(GPIO_SQUARE_WAVE);
    gpio_set_direction(GPIO_SQUARE_WAVE, GPIO_MODE_OUTPUT);
    
    
    
    timer_cfg();
    // I) Instanciar e configurar driver.
    adc_continuous_handle_t adc_handle = NULL;
    adc_continuous_handle_cfg_t adc_handle_config = {
        .max_store_buf_size = 4 * BUFFER_SIZE * 2,                     
        .conv_frame_size = READ_LEN,                    // Tamanho de cada conversion frame.
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
    // ########################     ########################
    
    
    
    
    // Loop principal opcional
    while (1) {
        printf("Square wave toggles: %lu\n", my_counter);
        
        // Pedir uma conversion frame completa via DMA. A função bloqueia até os dados estarem prontos.
        esp_err_t erro = adc_continuous_read(adc_handle, dma_buffer, CONVERSION_FRAME_LENGTH, &number_read_bytes, portMAX_DELAY);
        
        if (erro == ESP_OK) {
            // Pode acontecer por vezes o número de amostras na frame ser inferior ao pedido (frame "incompleta"). 
            // É boa prática calcular sempre quantas amostras efetivamente estão presentes na frame obtida.
            uint32_t frame_samples_number = number_read_bytes / SOC_ADC_DIGI_RESULT_BYTES;

            // Extrair, converter e guardar cada amostra obtida no nosso buffer principal.
            for (int sample_index = 0; sample_index < frame_samples_number; sample_index++) {
                
                // Se já atingimos a nossa meta de tempo (X segundos), paramos de guardar
                if (number_proccesed_samples >= BUFFER_SIZE) {
                    break; 
                }

                // Extrair a amostra usando a estrutura oficial da Espressif.
                adc_digi_output_data_t *dados = (adc_digi_output_data_t*)&dma_buffer[sample_index * SOC_ADC_DIGI_RESULT_BYTES];
                uint32_t raw_sample = dados->type2.data; 

                // Converter para Volts e guardar no nosso buffer principal.
                processed_samples[number_proccesed_samples] = (float)raw_sample;
                
                number_proccesed_samples++;
            }

            if (number_proccesed_samples >= BUFFER_SIZE) {
                ESP_LOGI(TAG, "Desired number of samples achieved! Stopping sampling. First 25 collected samples:\n");
                ESP_ERROR_CHECK(adc_continuous_stop(adc_handle));
                for(int sample_index = 0; sample_index < 25; sample_index++) {
                    ESP_LOGI(TAG, "Sample %d: %.2f V\n", sample_index, processed_samples[sample_index]);
                }
                break;
            }
        }

        // O timer vai gerar uma interrupção a cada final
        // de contagem,  que ativa a função de interrupção 
        // altera o estado do led 
        // vTaskDelay(pdMS_TO_TICKS(10));       // mudar 500 para 10 respetivamente

    }

}

