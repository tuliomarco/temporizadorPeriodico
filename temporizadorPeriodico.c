#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

/* Desenvolvedor: Marco Túlio Macêdo Oliveira dos Santos */

// Identificação das GPIOs correspondentes aos LEDs
#define LED_R_PIN 11 // 13
#define LED_G_PIN 13 // 12
#define LED_Y_PIN 12 // 11 Obs.: Para um funcionamento mais próximo ao da simulação na ferramenta educacional BitDogLab

/*
* Inicialização das GPIOs
*/
void init() {
    gpio_init(LED_R_PIN);
    gpio_init(LED_G_PIN);
    gpio_init(LED_Y_PIN);

    gpio_set_dir(LED_R_PIN, GPIO_OUT);
    gpio_set_dir(LED_G_PIN, GPIO_OUT);
    gpio_set_dir(LED_Y_PIN, GPIO_OUT);
}

// Possíveis estados do semáforo (1 ligado | 0 desligado)
uint8_t traffic_light_control[3] = {
    0b100, 0b010, 0b001
};

// Variável para controle dos estados
volatile uint state = 0;

/*
* Função de repetição
*/
bool repeating_timer_callback(struct repeating_timer *t) {
    state = (state + 1) % 3; // Alteração do estado (0-2)
    // Modificação do semáforo
    gpio_put(LED_R_PIN, traffic_light_control[state] & 0x4); // (Hex. 0x4 | Bin. 0b100)
    gpio_put(LED_Y_PIN, traffic_light_control[state] & 0x2); // (Hex. 0x2 | Bin. 0b010)
    gpio_put(LED_G_PIN, traffic_light_control[state] & 0x1); // (Hex. 0x1 | Bin. 0b001)
    
    return true;
}

int main() {
    stdio_init_all();
    init();

    struct repeating_timer timer; // Estrutura para o temporizador periódico

    gpio_put(LED_R_PIN, true); // Inicia com a cor vermelha
    
    // Adiciona um temporizador para chamar a função de callback a cada 3000 ms (3 segundos)
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    // Array com mensagens de status do semáforo
    char signal[3][17] = {
        "VERMELHO, PAROU!",
        "AMARELO, ATENTO!",
        "VERDE, SIGA!"
    };

    uint inc = 0; // Contador para controlar a sequência de mensagens

    while (true) {
        sleep_ms(1000);
        inc++;

        switch (inc) {
        case 1:
            printf(state != 0 ? "Dirigindo meu carro." : "Esperando o sinal abrir.");
            break;
        case 2:
            printf("Atenção, o sinal irá mudar.");
            break;
        case 3:
            printf("Sinal mudou! %s\n", signal[state]); // Exibe a mensagem do semáforo com base no estado atual
            inc = 0; // Reinicia o contador de mensagens
            break;
        }
        printf("\n"); // Nova linha para melhorar a legibilidade
    }
}