#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

#define LED_GREEN 13
#define LED_YELLOW 12
#define LED_RED 11

// Estados do semáforo
typedef enum {
    VERMELHO,
    AMARELO,
    VERDE
} estado_semaforo_t;

estado_semaforo_t estado_atual = VERMELHO;

// Callback do temporizador
bool repeating_timer_callback(struct repeating_timer *t) {
    switch (estado_atual) {
        case VERMELHO:
            gpio_put(LED_RED, 0);
            gpio_put(LED_YELLOW, 1);
            estado_atual = AMARELO;
            break;
        case AMARELO:
            gpio_put(LED_YELLOW, 0);
            gpio_put(LED_GREEN, 1);
            estado_atual = VERDE;
            break;
        case VERDE:
            gpio_put(LED_GREEN, 0);
            gpio_put(LED_RED, 1);
            estado_atual = VERMELHO;
            break;
    }
    return true; 
}

int main() {
    stdio_init_all();    
    
    gpio_init(LED_RED);
    gpio_init(LED_YELLOW);
    gpio_init(LED_GREEN);
    gpio_set_dir(LED_RED, GPIO_OUT);
    gpio_set_dir(LED_YELLOW, GPIO_OUT);
    gpio_set_dir(LED_GREEN, GPIO_OUT);
    
    // Inicializa o semáforo no vermelho
    gpio_put(LED_RED, 1);
    gpio_put(LED_YELLOW, 0);
    gpio_put(LED_GREEN, 0);
    
    // Configuração do temporizador periódico
    struct repeating_timer timer;
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);
    
    // Loop principal com impressão na porta serial a cada 1 segundo
    while (true) {
        printf("Semáforo: estado %d\n", estado_atual);
        sleep_ms(1000);
    }
}
