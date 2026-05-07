#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gptimer.h"
#include "esp_check.h" // Disponibilizar a macro ESP_ERROR_CHECK. Esta permite verificar o sucesso e error codes da execução de funções, 
                       // terminando o programa e imprimindo informação para debug em caso de erros.

// Variável global para permitir o seu acesso pela ISR e pelo programa principal.
// 'volatile' é necessária para avisar o compilador que esta pode mudar a qualquer momento (pela ISR)
// e impedir que este a optimize incorrectamente (p. ex. faça caching do seu valor).
volatile uint32_t my_counter = 0;

// Função de callback do alarme (ISR - Interrupt Service Routine).
// Esta é a assinatura comum para a callback, com parâmetros que permitem receber informação de contexto.
static bool timer_isr_callback(gptimer_handle_t timer, const gptimer_alarm_event_data_t *edata, void *user_data) {
    
    my_counter++;
    
    // Valor lógico retornado serve para controlar alguns aspectos de gestão de tarefas do FreeRTOS.
    // Não vamos entrar nesses detalhes nesta altura; vamos retornar sempre "false". 
    return false; 
}

void app_main(void) {

    printf("Starting timer demo...\n");

    // I) Instanciar e configurar o temporizador (1 MHz de resolução).
    gptimer_handle_t my_timer = NULL;
    gptimer_config_t timer_config = {
        .clk_src = GPTIMER_CLK_SRC_DEFAULT, // Seleciona uso do clock "default".
        .direction = GPTIMER_COUNT_UP, // Configura contagem crescente.
        .resolution_hz = 1000000, // Configura 1 MHz resolução. 1 unidade contagem (tick) = 1 microssegundo.
    };
    ESP_ERROR_CHECK(gptimer_new_timer(&timer_config, &my_timer));

    // II) Configurar a ISR
    gptimer_event_callbacks_t cbs = {
        .on_alarm = timer_isr_callback, // Função "timer_isr_callback" deve ser invocada quando ocorrer um evento alarme.
    };
    ESP_ERROR_CHECK(gptimer_register_event_callbacks(my_timer, &cbs, NULL)); // Registo da ISR especificada anteriormente no nosso timer.

    // III) Configurar o alarme
    gptimer_alarm_config_t alarm_config = {
        .alarm_count = 1000000, // O alarme dispara aos 1.000.000 tiques (1 segundo exato).
        .reload_count = 0,      // Contagem recomeça no tique 0.
        .flags.auto_reload_on_alarm = true, // Recomeça contagem automaticamente após alarme.
    };
    ESP_ERROR_CHECK(gptimer_set_alarm_action(my_timer, &alarm_config));

    // IV) Ativar e iniciar o timer
    ESP_ERROR_CHECK(gptimer_enable(my_timer)); // Ativar periférico timer.
    ESP_ERROR_CHECK(gptimer_start(my_timer));  // Iniciar contagem.

    while (1) {
        printf("Value of my counter: %lu\n", my_counter);
        // Pausa de aproximadamente 1 segundo para não "inundar" o terminal com mensagens.
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
